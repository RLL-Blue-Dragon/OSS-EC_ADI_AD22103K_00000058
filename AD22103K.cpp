// License       : License.txt
// Specifications: Spec-AD22103K.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : AD22103K.cpp
// Reason for change: 01.00.00 : 05/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include        "AD22103K.h"

#if     iAD22103K_ma == iSMA                            // Simple moving average filter
static float32 AD22103K_sma_buf[iAD22103K_SMA_num];
static sma_f32_t AD22103K_Phy_SMA =
{
        iInitial ,                                      // Initial state
        iAD22103K_SMA_num ,                             // Simple moving average number & buf size
        0U ,                                            // buffer position
        0.0F ,                                          // sum
        &AD22103K_sma_buf[0]                            // buffer
};

#elif   iAD22103K_ma == iEMA                            // Exponential moving average filter
static ema_f32_t AD22103K_Phy_EMA =
{
        iInitial ,                                      // Initial state
        0.0F ,                                          // Xn-1
        iAD22103K_EMA_K                                 // Exponential smoothing factor
};

#elif   iAD22103K_ma == iWMA                            // Weighted moving average filter
static float32 AD22103K_wma_buf[iAD22103K_WMA_num];
static wma_f32_t AD22103K_Phy_WMA =
{
        iInitial ,                                      // Initial state
        iAD22103K_WMA_num ,                             // Weighted moving average number & buf size
        0U ,                                            // buffer poition
        iAD22103K_WMA_num * (iAD22103K_WMA_num + 1)/2 , // kn sum
        &AD22103K_wma_buf[0]                            // Xn buffer
};

#else                                                   // Non-moving average filter
#endif

#define iDummy_adr       0xffffffff                     // Dummy address

const tbl_adc_t tbl_AD22103K =
{
        iAD22103K               ,
        iAD22103K_pin           ,
        iAD22103K_xoff          ,
        iAD22103K_yoff          ,
        iAD22103K_gain          ,
        iAD22103K_max           ,
        iAD22103K_min           ,
        iAD22103K_ma            ,
        
#if     iAD22103K_ma == iSMA                            // Simple moving average filter
        &AD22103K_Phy_SMA       ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#elif   iAD22103K_ma == iEMA                            // Exponential moving average filter
        (sma_f32_t*)iDummy_adr  ,
        &AD22103K_Phy_EMA       ,
        (wma_f32_t*)iDummy_adr
#elif   iAD22103K_ma == iWMA                            // Weighted moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        &AD22103K_Phy_WMA
#else                                                   // Non-moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#endif

};
