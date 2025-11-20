#include "rv32i_npp_ip.h"

r_csr_t r_csr(decoded_csr_t d_imm){
 return ((r_csr_t)d_imm.inst_31_20   <<11) |
         ((r_csr_t)d_imm.inst_19_15<< 5);
}

i_csr_t i_float(decoded_csr_t d_imm){
 return ((i_csr_t)d_imm.inst_31   <<11) |
         ((i_csr_t)d_imm.inst_30_25<< 5);  
}

