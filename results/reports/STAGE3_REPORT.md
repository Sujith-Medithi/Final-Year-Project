# Stage 3 Core Benchmark Scaling Report (1,000 Programs)

**Total Programs**: 1000 (100 programs per family across 10 families)  
**Unique SHA-256 Hashes**: 1000 / 1000 (100% Unique - Zero Duplication)  
**Dataset SHA-256**: `c4fb283e413456711e7539398b31d7d9894cd09c35a3eb575bda24e0a176031e`  
**Ground Truth Source**: Official CBMC Model Checker (`--unwind 5`)

## 1. Feature Variance Verification across 1,000 Programs

| Feature Name | Feature Group | Standard Deviation (σ) | Min | Max |
| :--- | :--- | :--- | :--- | :--- |
| `loc` | Group A (Source) | **2.2282** | 20 | 26 |
| `num_instructions` | Group A (Source) | **1.6287** | 5 | 10 |
| `num_branches` | Group A (Source) | **0.7814** | 0 | 2 |
| `num_loops` | Group A (Source) | **0.4002** | 0 | 1 |
| `num_functions` | Group A (Source) | **0.0** | 2 | 2 |
| `num_variables` | Group A (Source) | **0.9005** | 6 | 9 |
| `num_arrays` | Group A (Source) | **0.4002** | 0 | 1 |
| `num_structure` | Group A (Source) | **0.0** | 0 | 0 |
| `num_union` | Group A (Source) | **0.0** | 0 | 0 |
| `num_high_inputs` | Group B / Ratio | **0.0** | 1 | 1 |
| `num_low_inputs` | Group B / Ratio | **0.0** | 1 | 1 |
| `num_explicit_flows` | Group B / Ratio | **2.192** | 4 | 10 |
| `num_culprit_blocks` | Group B / Ratio | **2.0135** | 0 | 6 |
| `num_implicit_flows` | Group B / Ratio | **5.4442** | 0 | 18 |
| `num_information_leak` | Group B / Ratio | **1.7925** | 4 | 9 |
| `num_secret_dependent_prints` | Group B / Ratio | **0.0** | 0 | 0 |
| `num_assumptions` | Group B / Ratio | **0.0** | 2 | 2 |
| `num_assertions` | Group B / Ratio | **0.6328** | 2 | 4 |
| `num_array_accesses` | Group B / Ratio | **1.4974** | 0 | 5 |
| `taint_ratio` | Group B / Ratio | **0.0863** | 0.16 | 0.45 |
| `secret_branch_ratio` | Group B / Ratio | **0.4502** | 0.0 | 1.0 |
| `secret_memory_ratio` | Group B / Ratio | **0.3002** | 0.0 | 1.0 |

## 2. Program Breakdown by Leakage Family

| Family ID | Programs Count | Mean Assertions | Mean CBMC `#leak` | Leakage Behavior |
| :--- | :--- | :--- | :--- | :--- |
| `arithmetic` | 100 | 2.0 | **2.0** | Leaking (#leak>0) |
| `array_lookup` | 100 | 3.0 | **3.0** | Leaking (#leak>0) |
| `bitwise` | 100 | 3.0 | **3.0** | Leaking (#leak>0) |
| `direct_leakage` | 100 | 3.0 | **3.0** | Leaking (#leak>0) |
| `implicit_flow` | 100 | 3.0 | **3.0** | Leaking (#leak>0) |
| `loop_accumulator` | 100 | 3.0 | **2.2** | Leaking (#leak>0) |
| `mixed_control_data` | 100 | 4.0 | **3.0** | Leaking (#leak>0) |
| `nested_branches` | 100 | 3.0 | **3.0** | Leaking (#leak>0) |
| `partial_leakage` | 100 | 2.0 | **2.0** | Leaking (#leak>0) |
| `zero_leakage` | 100 | 4.0 | **0.0** | Zero Leakage (#leak=0) |
