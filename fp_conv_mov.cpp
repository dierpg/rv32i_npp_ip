#include "ap_int.h"
#include "debug_rv32i_npp_ip.h"
#include "rv32i_npp_ip.h"
#include <ap_fixed.h>
#include "fp_conv_mov.h"

typedef ap_fixed<32,8> fp32_t;   // 32 bit 
typedef ap_int<32>     xword_t;  // entero con signo 32 bits (XLEN)
typedef ap_uint<32>    uxword_t; // entero sin signo 32 bits

union fp32_raw_t {
  fp32_t    f;
  ap_uint<32> u;
};

// float -> entero  (FCVT.W.S / FCVT.WU.S)
static xword_t conv_f2i(fp32_t rv1, decoded_instruction_t d_i) {

  xword_t result = 0;

  ap_uint<5> funct5 = d_i.func7 >> 2;

  switch (f7_5) {
    case FCVT_W_S:            // FCVT.W.S
      result = (xword_t)rv1;  // signado
      break;

    case FCVT_WU_S:                        // FCVT.WU.S
      result = (xword_t)( (uxword_t)rv1 ); // sin signo
      break;
  }
  return result;
}

// entero -> float  (FCVT.S.W / FCVT.S.WU)
static fp32_t conv_i2f(xword_t rv1, decoded_instruction_t d_i) {

  fp32_t result = 0;

  ap_uint<5> funct5 = d_i.func7 >> 2;

  switch (f7_5) {
    case FCVT_S_W:          // FCVT.S.W
      result = (fp32_t)rv1; // signado
      break;

    case FCVT_S_WU:                     // FCVT.S.WU
      result = (fp32_t)((uxword_t)rv1); // sin signo
      break;
  }
  return result;
}

// FSGNJ.S / FSGNJN.S / FSGNJX.S
static fp32_t sign_f(fp32_t rv1, fp32_t rv2,
                                   decoded_instruction_t d_i) {

  fp32_raw_t a, b, r;
  a.f = rv1;
  b.f = rv2;

  ap_uint<1>  sign_a = a.u[31];
  ap_uint<1>  sign_b = b.u[31];
  ap_uint<31> mag_a  = a.u.range(30,0);

  ap_uint<1> new_sign = 0;

  switch (d_i.func3) {
    case 0b000: new_sign = sign_b;                break;    // FSGNJ.S
    case 0b001: new_sign = (ap_uint<1>)(~sign_b); break;    // FSGNJN.S
    case 0b010: new_sign = sign_a ^ sign_b;       break;    // FSGNJX.S
  }

  r.u.range(30,0) = mag_a;
  r.u[31]         = new_sign;
  
  return r.f;
}

// FMV.X.W  (float -> entero, copia de bits)
static xword_t fmv_x_w(fp32_t rv1, decoded_instruction_t d_i) {
  (void)d_i;

  fp32_raw_t u;
  u.f   = rv1;
  result = (xword_t)u.u;   
  
  return (xword_t)u.u;
}

// FMV.W.X  (entero -> float, copia de bits)
static fp32_t fmv_w_x(xword_t rv1, decoded_instruction_t d_i) {
  (void)d_i

  fp32_raw_t u;
  u.u   = (ap_uint<32>)rv1;
  
  return u.f;
}
