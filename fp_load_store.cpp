#include "rv32i_npp_ip.h"

l_fp_immediate_t l_float(decode_fp_immediate_t d_float){
return (((l_fp_immediatet_t)d_float.inst_31   <<11) |
        ((l_fp_immediate_t)d_float.ins_30_25 << 5) |
        ((l_fp_immediate_t)d_float.ins_24_21 << 1) |
        ((l_fp_immediate_t)d_float.inst_20       ));
}

s_fp_immediate_t s_float(decode_fp_immediate_t d_float){
return (((s_fp_immediate_t)d_float.inst_31   <<11) |
        ((s_fp_immediate_t)d_float.ins_30_25 << 5) |
        ((s_fp_immediate_t)d_float.ins_24_21 << 1) |
        ((s_fp_immediate_t)d_float.inst_7       ));
}
