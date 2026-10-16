# Stage 1 Verification & Baseline Smoke Test Report

**Total Programs**: 12  
**Families Covered**: 12  
**Ground Truth Source**: Official CBMC Model Checker (`#leak` = failed assertions count)

## 1. Summary of Stage 1 Programs & Inputs

| Program ID | Family | Sensitive Inputs (`high_vars`) | Public Inputs (`low_vars`) | Total Assertions | CBMC `#leak` |
| :--- | :--- | :--- | :--- | :--- | :--- |
| `P000001` | `zero_leakage` | `high_sec` | `pub_val` | 3 | **0** |
| `P000002` | `direct_leakage` | `key_in` | `pub_in` | 3 | **3** |
| `P000003` | `partial_leakage` | `secret_k` | `pub_bias` | 3 | **3** |
| `P000004` | `implicit_flow` | `sec_pw` | `pub_user` | 3 | **3** |
| `P000005` | `arithmetic` | `sec_val` | `pub_scale` | 3 | **3** |
| `P000006` | `bitwise` | `sec_token` | `pub_nonce` | 3 | **3** |
| `P000007` | `nested_branches` | `sec_score` | `pub_flag` | 3 | **3** |
| `P000008` | `loop_accumulator` | `sec_data` | `pub_seed` | 3 | **3** |
| `P000009` | `array_lookup` | `sec_idx` | `pub_base` | 3 | **3** |
| `P000010` | `mixed_control_data` | `sec_param` | `pub_config` | 4 | **3** |
| `P000011` | `multi_secret` | `sec_key1,sec_key2` | `pub_nonce` | 3 | **3** |
| `P000012` | `zero_leakage_cancel` | `sec_pin` | `pub_mode` | 3 | **0** |

## 2. Key Stage 1 Verification Takeaways

1. **Complete Input Transparency**: Every program explicitly defines sensitive secrets and public values in its companion JSON.
2. **Zero-Leakage Correctness**: `P000001` (dead code) and `P000012` (XOR cancellation) correctly verified `#leak = 0`.
3. **Positive Leakage Detection**: Direct, partial, arithmetic, bitwise, and control-flow side channels correctly produce `#leak > 0`.
4. **Feature Integrity**: All Group A, Group B, and Ratio features extracted without missing values or syntax crashes.
