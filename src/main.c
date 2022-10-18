/********************************** (C) COPYRIGHT *******************************
 * File Name          : Main.c
 * Author             : WCH
 * Version            : V1.0
 * Date               : 2020/08/06
 * Description        : 1շʾ
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * SPDX-License-Identifier: Apache-2.0
 *******************************************************************************/

#include "CH58x_common.h"

uint8_t TxBuff[] = "This is a tx exam\r\n";
uint8_t RxBuff[100];
uint8_t trigB;

/*********************************************************************
 * @fn      main
 *
 * @brief   
 *
 * @return  none
 */
int main()
{
    SetSysClock(CLK_SOURCE_PLL_60MHz);

    GPIOA_SetBits(GPIO_Pin_9);
    GPIOA_ModeCfg(GPIO_Pin_8, GPIO_ModeIN_PU);
    GPIOA_ModeCfg(GPIO_Pin_9, GPIO_ModeOut_PP_5mA);
    UART1_DefInit();

    UART1_SendString(TxBuff, sizeof(TxBuff));
    while(1)
    {
        const uint8_t len = UART1_RecvString(RxBuff);
        if(0 != len) {
            UART1_SendString(RxBuff, len);
        }
    }

    while(1);
}

/*********************************************************************
 * @fn      UART1_IRQHandler
 *
 * @brief   UART1жϺ
 *
 * @return  none
 */
__INTERRUPT
__HIGH_CODE
void UART1_IRQHandler(void)
{
    const uint8_t flag = UART1_GetITFlag();
    switch(flag)
    {
        case UART_II_LINE_STAT: {
            UART1_GetLinSTA();
        } break;

        case UART_II_RECV_RDY: {
            for(uint8_t i = 0; i != trigB; i++)
            {
                RxBuff[i] = UART1_RecvByte();
                UART1_SendByte(RxBuff[i]);
            }
        } break;

        case UART_II_RECV_TOUT: {
            const uint8_t len = UART1_RecvString(RxBuff);
            UART1_SendString(RxBuff, len);
        } break;

        default:
            break;
    }
}
