import re
from pathlib import Path
import docx
from docx.shared import Inches, Pt, RGBColor
from docx.enum.text import WD_ALIGN_PARAGRAPH
from docx.enum.table import WD_TABLE_ALIGNMENT
from docx.oxml import OxmlElement
from docx.oxml.ns import qn

def set_cell_background(cell, fill_hex):
    tcPr = cell._tc.get_or_add_tcPr()
    shd = OxmlElement('w:shd')
    shd.set(qn('w:val'), 'clear')
    shd.set(qn('w:color'), 'auto')
    shd.set(qn('w:fill'), fill_hex)
    tcPr.append(shd)

def set_cell_margins(cell, top=100, bottom=100, left=150, right=150):
    tcPr = cell._tc.get_or_add_tcPr()
    tcMar = OxmlElement('w:tcMar')
    for m, val in [('w:top', top), ('w:bottom', bottom), ('w:left', left), ('w:right', right)]:
        node = OxmlElement(m)
        node.set(qn('w:w'), str(val))
        node.set(qn('w:type'), 'dxa')
        tcMar.append(node)
    tcPr.append(tcMar)

def markdown_to_docx(md_path: Path, docx_path: Path):
    doc = docx.Document()
    
    # Page Setup (Standard A4 / Letter, 1 inch margins)
    for section in doc.sections:
        section.top_margin = Inches(1.0)
        section.bottom_margin = Inches(1.0)
        section.left_margin = Inches(1.0)
        section.right_margin = Inches(1.0)

    # Base Normal Style
    normal_style = doc.styles['Normal']
    normal_style.font.name = 'Times New Roman'
    normal_style.font.size = Pt(12)
    normal_style.font.color.rgb = RGBColor(30, 30, 30)
    normal_style.paragraph_format.line_spacing = 1.15
    normal_style.paragraph_format.space_after = Pt(4)

    lines = md_path.read_text(encoding='utf-8').splitlines()
    
    in_code_block = False
    code_lines = []
    in_table = False
    table_lines = []

    def flush_table():
        nonlocal in_table, table_lines
        if not table_lines:
            return
        
        # Parse table rows
        rows_data = []
        for line in table_lines:
            parts = [c.strip() for c in line.strip().strip('|').split('|')]
            # Check if separator row
            if all(re.match(r'^:?-+:?$', p) for p in parts if p):
                continue
            rows_data.append(parts)
            
        if rows_data:
            num_cols = max(len(r) for r in rows_data)
            # Normalize row length
            for r in rows_data:
                while len(r) < num_cols:
                    r.append("")
            
            table = doc.add_table(rows=len(rows_data), cols=num_cols)
            table.alignment = WD_TABLE_ALIGNMENT.CENTER
            table.autofit = True
            
            for i, row in enumerate(rows_data):
                for j, text in enumerate(row):
                    cell = table.cell(i, j)
                    cell.text = text
                    p = cell.paragraphs[0]
                    p.paragraph_format.space_after = Pt(2)
                    p.paragraph_format.space_before = Pt(2)
                    p.paragraph_format.line_spacing = 1.05
                    run = p.runs[0] if p.runs else p.add_run()
                    run.font.name = 'Times New Roman'
                    
                    if i == 0:
                        run.font.bold = True
                        run.font.size = Pt(10.5)
                        set_cell_background(cell, 'EAECEF')
                    else:
                        run.font.size = Pt(10)
                        if i % 2 == 1:
                            set_cell_background(cell, 'F9FBFD')
                    set_cell_margins(cell, top=80, bottom=80, left=120, right=120)
            
            doc.add_paragraph() # Spacing
            
        table_lines = []
        in_table = False

    def flush_code():
        nonlocal in_code_block, code_lines
        if not code_lines:
            return
        code_text = "\n".join(code_lines)
        p = doc.add_paragraph()
        p.paragraph_format.space_before = Pt(4)
        p.paragraph_format.space_after = Pt(6)
        p.paragraph_format.line_spacing = 1.0
        run = p.add_run(code_text)
        run.font.name = 'Consolas'
        run.font.size = Pt(9.5)
        run.font.color.rgb = RGBColor(20, 40, 80)
        code_lines = []
        in_code_block = False

    for line in lines:
        stripped = line.strip()

        # Code block delimiter
        if stripped.startswith("```"):
            if in_code_block:
                flush_code()
            else:
                if in_table:
                    flush_table()
                in_code_block = True
                code_lines = []
            continue

        if in_code_block:
            code_lines.append(line)
            continue

        # Table detection
        if stripped.startswith("|") and stripped.endswith("|"):
            in_table = True
            table_lines.append(stripped)
            continue
        elif in_table:
            flush_table()

        if not stripped:
            continue

        # Horizontal rule
        if re.match(r'^-{3,}$', stripped):
            p = doc.add_paragraph()
            p.paragraph_format.space_before = Pt(6)
            p.paragraph_format.space_after = Pt(6)
            run = p.add_run("_________________________________________________________________________________")
            run.font.color.rgb = RGBColor(180, 180, 180)
            p.alignment = WD_ALIGN_PARAGRAPH.CENTER
            continue

        # Headings
        if stripped.startswith("# "):
            p = doc.add_heading(level=1)
            p.paragraph_format.space_before = Pt(18)
            p.paragraph_format.space_after = Pt(8)
            run = p.add_run(stripped[2:])
            run.font.name = 'Times New Roman'
            run.font.size = Pt(18)
            run.font.bold = True
            run.font.color.rgb = RGBColor(0, 32, 96)
        elif stripped.startswith("## "):
            p = doc.add_heading(level=2)
            p.paragraph_format.space_before = Pt(14)
            p.paragraph_format.space_after = Pt(6)
            run = p.add_run(stripped[3:])
            run.font.name = 'Times New Roman'
            run.font.size = Pt(14)
            run.font.bold = True
            run.font.color.rgb = RGBColor(16, 64, 128)
        elif stripped.startswith("### "):
            p = doc.add_heading(level=3)
            p.paragraph_format.space_before = Pt(10)
            p.paragraph_format.space_after = Pt(4)
            run = p.add_run(stripped[4:])
            run.font.name = 'Times New Roman'
            run.font.size = Pt(12)
            run.font.bold = True
            run.font.color.rgb = RGBColor(40, 80, 140)
        elif stripped.startswith("- ") or stripped.startswith("* "):
            p = doc.add_paragraph(style='List Bullet')
            p.paragraph_format.space_after = Pt(2)
            p.paragraph_format.line_spacing = 1.15
            run = p.add_run(stripped[2:])
            run.font.name = 'Times New Roman'
            run.font.size = Pt(11.5)
        elif re.match(r'^\d+\.\s+', stripped):
            match = re.match(r'^(\d+\.\s+)(.*)', stripped)
            p = doc.add_paragraph(style='List Number')
            p.paragraph_format.space_after = Pt(2)
            p.paragraph_format.line_spacing = 1.15
            run = p.add_run(match.group(2))
            run.font.name = 'Times New Roman'
            run.font.size = Pt(11.5)
        elif stripped.startswith("> "):
            p = doc.add_paragraph()
            p.paragraph_format.left_indent = Inches(0.5)
            p.paragraph_format.space_before = Pt(4)
            p.paragraph_format.space_after = Pt(4)
            run = p.add_run(stripped[2:])
            run.font.name = 'Times New Roman'
            run.font.italic = True
            run.font.size = Pt(11)
            run.font.color.rgb = RGBColor(60, 60, 60)
        else:
            p = doc.add_paragraph()
            p.paragraph_format.space_after = Pt(4)
            p.paragraph_format.line_spacing = 1.15
            run = p.add_run(stripped)
            run.font.name = 'Times New Roman'
            run.font.size = Pt(12)

    if in_table:
        flush_table()
    if in_code_block:
        flush_code()

    doc.save(str(docx_path))
    print(f"[OK] Generated Word document: {docx_path}")

if __name__ == "__main__":
    src_md = Path("Final_Year_Project_Report.md")
    dst_docx = Path("Final_Year_Project_Report.docx")
    markdown_to_docx(src_md, dst_docx)

