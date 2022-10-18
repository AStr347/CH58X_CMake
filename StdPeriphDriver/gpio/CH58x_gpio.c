/********************************** (C) COPYRIGHT *******************************
 * File Name          : CH58x_gpio.c
 * Author             : WCH
 * Version            : V1.2
 * Date               : 2021/11/17
 * Description
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * SPDX-License-Identifier: Apache-2.0
 *******************************************************************************/

#include "CH58x_common.h"

/*********************************************************************
 * @fn      GPIOA_ModeCfg
 *
 * @brief   GPIOA�˿�����ģʽ����
 *
 * @param   pin     - PA0-PA15
 * @param   mode    - �����������
 *
 * @return  none
 */
void GPIOA_ModeCfg(const uint32_t pin, const GPIOModeTypeDef mode)
{
    switch(mode)
    {
        case GPIO_ModeIN_Floating:
            R32_PA_PD_DRV &= ~pin;
            R32_PA_PU &= ~pin;
            R32_PA_DIR &= ~pin;
            break;

        case GPIO_ModeIN_PU:
            R32_PA_PD_DRV &= ~pin;
            R32_PA_PU |= pin;
            R32_PA_DIR &= ~pin;
            break;

        case GPIO_ModeIN_PD:
            R32_PA_PD_DRV |= pin;
            R32_PA_PU &= ~pin;
            R32_PA_DIR &= ~pin;
            break;

        case GPIO_ModeOut_PP_5mA:
            R32_PA_PD_DRV &= ~pin;
            R32_PA_DIR |= pin;
            break;

        case GPIO_ModeOut_PP_20mA:
            R32_PA_PD_DRV |= pin;
            R32_PA_DIR |= pin;
            break;

        default:
            break;
    }
}

/*********************************************************************
 * @fn      GPIOB_ModeCfg
 *
 * @brief   GPIOB�˿�����ģʽ����
 *
 * @param   pin     - PB0-PB23
 * @param   mode    - �����������
 *
 * @return  none
 */
void GPIOB_ModeCfg(const uint32_t pin, const GPIOModeTypeDef mode)
{
    switch(mode)
    {
        case GPIO_ModeIN_Floating:
            R32_PB_PD_DRV &= ~pin;
            R32_PB_PU &= ~pin;
            R32_PB_DIR &= ~pin;
            break;

        case GPIO_ModeIN_PU:
            R32_PB_PD_DRV &= ~pin;
            R32_PB_PU |= pin;
            R32_PB_DIR &= ~pin;
            break;

        case GPIO_ModeIN_PD:
            R32_PB_PD_DRV |= pin;
            R32_PB_PU &= ~pin;
            R32_PB_DIR &= ~pin;
            break;

        case GPIO_ModeOut_PP_5mA:
            R32_PB_PD_DRV &= ~pin;
            R32_PB_DIR |= pin;
            break;

        case GPIO_ModeOut_PP_20mA:
            R32_PB_PD_DRV |= pin;
            R32_PB_DIR |= pin;
            break;

        default:
            break;
    }
}

/*********************************************************************
 * @fn      GPIOA_ITModeCfg
 *
 * @brief   GPIOA�����ж�ģʽ����
 *
 * @param   pin     - PA0-PA15
 * @param   mode    - ��������
 *
 * @return  none
 */
void GPIOA_ITModeCfg(uint32_t pin, GPIOITModeTpDef mode)
{
    switch(mode)
    {
        case GPIO_ITMode_LowLevel: // �͵�ƽ����
            R16_PA_INT_MODE &= ~pin;
            R32_PA_CLR |= pin;
            break;

        case GPIO_ITMode_HighLevel: // �ߵ�ƽ����
            R16_PA_INT_MODE &= ~pin;
            R32_PA_OUT |= pin;
            break;

        case GPIO_ITMode_FallEdge: // �½��ش���
            R16_PA_INT_MODE |= pin;
            R32_PA_CLR |= pin;
            break;

        case GPIO_ITMode_RiseEdge: // �����ش���
            R16_PA_INT_MODE |= pin;
            R32_PA_OUT |= pin;
            break;

        default:
            break;
    }
    R16_PA_INT_IF = pin;
    R16_PA_INT_EN |= pin;
}

/*********************************************************************
 * @fn      GPIOB_ITModeCfg
 *
 * @brief   GPIOB�����ж�ģʽ����
 *
 * @param   pin     - PB0-PB23
 * @param   mode    - ��������
 *
 * @return  none
 */
void GPIOB_ITModeCfg(uint32_t pin, GPIOITModeTpDef mode)
{
    uint32_t Pin = pin | ((pin & (GPIO_Pin_22 | GPIO_Pin_23)) >> 14);
    switch(mode)
    {
        case GPIO_ITMode_LowLevel: // �͵�ƽ����
            R16_PB_INT_MODE &= ~Pin;
            R32_PB_CLR |= pin;
            break;

        case GPIO_ITMode_HighLevel: // �ߵ�ƽ����
            R16_PB_INT_MODE &= ~Pin;
            R32_PB_OUT |= pin;
            break;

        case GPIO_ITMode_FallEdge: // �½��ش���
            R16_PB_INT_MODE |= Pin;
            R32_PB_CLR |= pin;
            break;

        case GPIO_ITMode_RiseEdge: // �����ش���
            R16_PB_INT_MODE |= Pin;
            R32_PB_OUT |= pin;
            break;

        default:
            break;
    }
    R16_PB_INT_IF = Pin;
    R16_PB_INT_EN |= Pin;
}

/*********************************************************************
 * @fn      GPIOPinRemap
 *
 * @brief   ���蹦������ӳ��
 *
 * @param   s       - �Ƿ�ʹ��ӳ��
 * @param   perph   - RB_PIN_SPI0   -  SPI0:  PA12/PA13/PA14/PA15 -> PB12/PB13/PB14/PB15
 *                    RB_PIN_UART1  -  UART1: PA8/PA9 ->  PB12/PB13
 *                    RB_PIN_UART0  -  UART0: PB4/PB7 ->  PA15/PA14
 *                    RB_PIN_TMR2   -  TMR2:  PA11 ->  PB11
 *                    RB_PIN_TMR1   -  TMR1:  PA10 ->  PB10
 *                    RB_PIN_TMR0   -  TMR0:  PA9 ->  PB23
 *
 * @return  none
 */
void GPIOPinRemap(FunctionalState s, uint16_t perph)
{
    if(s)
    {
        R16_PIN_ALTERNATE |= perph;
    }
    else
    {
        R16_PIN_ALTERNATE &= ~perph;
    }
}

/*********************************************************************
 * @fn      GPIOAGPPCfg
 *
 * @brief   ģ������GPIO���Ź��ܿ���
 *
 * @param   s       -   ENABLE  - ��ģ�����蹦�ܣ��ر����ֹ���
 *                      DISABLE - �������ֹ��ܣ��ر�ģ�����蹦��
 * @param   perph   -   RB_PIN_ADC0_1_IE    -  ADC0-1ͨ��
 *                      RB_PIN_ADC2_3_IE    -  ADC2-3ͨ��
 *                      RB_PIN_ADC4_5_IE    -  ADC4-5ͨ��
 *                      RB_PIN_ADC6_7_IE    -  ADC6-7ͨ��
 *                      RB_PIN_ADC8_9_IE    -  ADC8-9ͨ��
 *                      RB_PIN_ADC10_11_IE  -  ADC10-11ͨ��
 *                      RB_PIN_ADC12_13_IE  -  ADC12-13ͨ��
 *                      RB_PIN_XT32K_IE     -  �ⲿ32K����
 *                      RB_PIN_USB_IE       -  USB�����ź�����
 *                      RB_PIN_ETH_IE       -  ��̫�������ź�����
 *                      RB_PIN_SEG0_3_IE    -  LCD������SEG0-3��������
 *                      RB_PIN_SEG4_7_IE    -  LCD������SEG4-7��������
 *                      RB_PIN_SEG8_11_IE   -  LCD������SEG8-11��������
 *                      RB_PIN_SEG12_15_IE  -  LCD������SEG12-15��������
 *                      RB_PIN_SEG16_19_IE  -  LCD������SEG16-19��������
 *                      RB_PIN_SEG20_23_IE  -  LCD������SEG20-23��������
 *
 * @return  none
 */
void GPIOAGPPCfg(FunctionalState s, uint16_t perph)
{
    if(s)
    {
        R16_PIN_ANALOG_IE |= perph;
    }
    else
    {
        R16_PIN_ANALOG_IE &= ~perph;
    }
}
