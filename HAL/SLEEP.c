/********************************** (C) COPYRIGHT *******************************
 * File Name          : SLEEP.c
 * Author             : WCH
 * Version            : V1.2
 * Date               : 2022/01/18
 * Description        : ˯�����ü����ʼ��
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * SPDX-License-Identifier: Apache-2.0
 *******************************************************************************/

/******************************************************************************/
/* ͷ�ļ����� */
#include "HAL.h"

/*******************************************************************************
 * @fn          CH58X_LowPower
 *
 * @brief       ����˯��
 *
 * @param   time    - ���ѵ�ʱ��㣨RTC����ֵ��
 *
 * @return      state.
 */
uint32_t CH58X_LowPower(uint32_t time)
{
    (void)(time);
#if(defined(HAL_SLEEP)) && (HAL_SLEEP == TRUE)
    uint32_t tmp, irq_status;

    SYS_DisableAllIrq(&irq_status);
    tmp = RTC_GetCycle32k();
    if((time < tmp) || ((time - tmp) < 30))
    { // ���˯�ߵ����ʱ��
        SYS_RecoverIrq(irq_status);
        return 2;
    }
    RTC_SetTignTime(time);
    SYS_RecoverIrq(irq_status);
  #if(DEBUG == Debug_UART1) // ʹ���������������ӡ��Ϣ��Ҫ�޸����д���
    while((R8_UART1_LSR & RB_LSR_TX_ALL_EMP) == 0)
    {
        __nop();
    }
  #endif
    // LOW POWER-sleepģʽ
    if(!RTCTigFlag)
    {
        LowPower_Sleep(RB_PWR_RAM2K | RB_PWR_RAM30K | RB_PWR_EXTEND);
        if(RTCTigFlag) // ע�����ʹ����RTC����Ļ��ѷ�ʽ����Ҫע���ʱ32M����δ�ȶ�
        {
            time += WAKE_UP_RTC_MAX_TIME;
            if(time > 0xA8C00000)
            {
                time -= 0xA8C00000;
            }
            RTC_SetTignTime(time);
            LowPower_Idle();
        }
        HSECFG_Current(HSE_RCur_100); // ��Ϊ�����(�͹��ĺ�����������HSEƫ�õ���)
    }
    else
    {
        return 3;
    }
#endif
    return 0;
}

/*******************************************************************************
 * @fn      HAL_SleepInit
 *
 * @brief   ����˯�߻��ѵķ�ʽ   - RTC���ѣ�����ģʽ
 *
 * @param   None.
 *
 * @return  None.
 */
void HAL_SleepInit(void)
{
#if(defined(HAL_SLEEP)) && (HAL_SLEEP == TRUE)
    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;
    R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
    SAFEOPERATE;
    R8_SLP_WAKE_CTRL |= RB_SLP_RTC_WAKE; // RTC����
    R8_RTC_MODE_CTRL |= RB_RTC_TRIG_EN;  // ����ģʽ
    R8_SAFE_ACCESS_SIG = 0;              //
    PFIC_EnableIRQ(RTC_IRQn);
#endif
}
