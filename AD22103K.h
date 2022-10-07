// License       : License.txt
// Specifications: Spec-AD22103K.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : AD22103K.h
// Reason for change: 01.00.00 : 05/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#ifndef __AD22103K_H__
#define __AD22103K_H__

#include "user_define.h"

// Components number
#define iAD22103K               109U                    // Analog devices AD22103K

// AD22103K System Parts definitions
#define iAD22103K_xoff          ( 0.25F*(iADC_vdd/3.3F) )       // X offset [V]
#define iAD22103K_yoff          0.0F                    // Y offset [degree celsius]
#define iAD22103K_gain          ( 0.028F*(iADC_vdd/3.3F) )      // Gain [V/degree celsius]
#define iAD22103K_max           100.0F                  // Temperature Max [degree celsius]
#define iAD22103K_min           0.0F                    // Temperature Min [degree celsius]

extern const tbl_adc_t tbl_AD22103K;

#endif /*__AD22103K_H__*/
