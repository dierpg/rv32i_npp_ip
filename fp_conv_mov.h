#ifndef __FP_CONV_MOV__
#define __FP_CONV_MOV__

#include "ap_int.h"
#include <ap_fixed.h>
#include "rv32i_npp_ip.h" 

typedef ap_fixed<32,8> fp32_t;


typedef ap_int<32>   xword_t;   // con signo
typedef ap_uint<32>  uxword_t;  // sin signo

// Para copiar bits entre float fijo y entero
union fp32_raw_t {
  fp32_t     f;
  ap_uint<32> u;
};

fp32_t result_f(
  fp32_t                rv1,
  fp32_t                rv2,
  decoded_instruction_t d_i);

  //    float -> entero

xword_t conv_f2i( // FCVT.W.S / FCVT.WU.S
  fp32_t                rv1,
  decoded_instruction_t d_i);

    //  entero -> float (FCVT.S.W / FCVT.S.WU)

fp32_t conv_i2f(     
  xword_t               rv1,
  decoded_instruction_t d_i);

    // (FSGNJ.S / FSGNJN.S / FSGNJX.S)

fp32_t sign_f(    
  fp32_t                rv1,
  fp32_t                rv2,
  decoded_instruction_t d_i);

// Float -> entero (FMV.X.W / FMV.W.X (copia de bits))
xword_t fmv_x_w(     //  
  fp32_t                rv1,
  decoded_instruction_t d_i);

// Entero -> float (FMV.X.W / FMV.W.X (copia de bits))
fp32_t fmv_w_x(      
  xword_t               rv1,
  decoded_instruction_t d_i);

#endif 
