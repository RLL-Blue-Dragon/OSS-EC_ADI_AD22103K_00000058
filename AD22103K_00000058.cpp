// License       : License.txt
// Specifications: Spec-00000058.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : AD22103K_00000058.cpp
// BSL              : 00000058
// Model number     : Analog devices AD22103K
// Spec               Component type       : ADC
//                    OS                   : Mbed
//                    Calculation          : Floating-point
//                    Conversion type      : Linear
//                    Moving average filter: Moving average filter select
//                    Diagnosis            : Range (Min to Max)
// Reason for change: 01.00.00 : 05/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include "AD22103K.h"

AnalogIn AD22103K_adc( iAD22103K_pin , iVref );         // AnalogIn object

// Main Function
pp2ap_adc_t AD22103K_00000058( void )
{
        pp2ap_adc_t res = pp_00000058( AD22103K_adc , tbl_AD22103K );
        return( res );
}
