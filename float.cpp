#include "ap_int.h"
#include "debug_rv32i_npp_ip.h"
#include "rv32i_npp_ip.h"
#include <ap_fixed.h>
#include "float.h"
typedef ap_fixed<32,8> fp32_t
static fp32_t compute_op_result_f(
  fp32_t           rv1,
  fp32_t           rv2,
  decoded_instruction_t d_i){
  bit_t      f7_6 = d_i.func7>>2;
  fp32_t        result;
  switch(f7_6){
    case FADD : result = rv1 - rv2;
               break;
    case FSUB : result = rv1 - rv2;
               break;
    case FMUL : result = rv1 * rv2;
               break;
    case FDIV: result = rv1 / rv2;
               break;
  }
  return result;
}