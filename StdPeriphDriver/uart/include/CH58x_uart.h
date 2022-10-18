/********************************** (C) COPYRIGHT *******************************
 * File Name          : CH57x_uart.h
 * Author             : WCH
 * Version            : V1.2
 * Date               : 2021/11/17
 * Description
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * SPDX-License-Identifier: Apache-2.0
 *******************************************************************************/

#ifndef __CH58x_UART_H__
#define __CH58x_UART_H__

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief	LINE error and status define
 */
#define STA_ERR_BREAK     RB_LSR_BREAK_ERR    // ݼ
#define STA_ERR_FRAME     RB_LSR_FRAME_ERR    // ֡
#define STA_ERR_PAR       RB_LSR_PAR_ERR      // żУλ
#define STA_ERR_FIFOOV    RB_LSR_OVER_ERR     // 

#define STA_TXFIFO_EMP    RB_LSR_TX_FIFO_EMP  // ǰFIFOգԼ䷢
#define STA_TXALL_EMP     RB_LSR_TX_ALL_EMP   // ǰзݶ
#define STA_RECV_DATA     RB_LSR_DATA_RDY     // ǰнյ

/**
 * @brief  Configuration UART TrigByte num
 */
typedef enum
{
    UART_1BYTE_TRIG = 0, // 1ֽڴ
    UART_2BYTE_TRIG,     // 2ֽڴ
    UART_4BYTE_TRIG,     // 4ֽڴ
    UART_7BYTE_TRIG,     // 7ֽڴ

} UARTByteTRIGTypeDef;

/**
 * @brief   Ĭϳʼ
 */
void UART0_DefInit(void);

/**
 * @brief   ڲ
 *
 * @param   baudrate    - 
 */
void UART0_BaudRateCfg(uint32_t baudrate);

/**
 * @brief   ֽڴж
 *
 * @param   b       - ֽ refer to UARTByteTRIGTypeDef
 */
void UART0_ByteTrigCfg(UARTByteTRIGTypeDef b);

/**
 * @brief   ж
 *
 * @param   s       - жϿ״̬ǷʹӦж
 * @param   i       - ж
 *                    RB_IER_MODEM_CHG  - ƽ״̬仯жʹλ UART0 ֧֣
 *                    RB_IER_LINE_STAT  - ·״̬ж
 *                    RB_IER_THR_EMPTY  - ͱּĴж
 *                    RB_IER_RECV_RDY   - ж
 */
void UART0_INTCfg(FunctionalState s, uint8_t i);

/**
 * @brief   λ
 */
void UART0_Reset(void);

/**
 * @brief   ǰFIFO
 */
#define UART0_CLR_RXFIFO()    (R8_UART0_FCR |= RB_FCR_RX_FIFO_CLR)

/**
 * @brief   ǰFIFO
 */
#define UART0_CLR_TXFIFO()    (R8_UART0_FCR |= RB_FCR_TX_FIFO_CLR)

/**
 * @brief   ȡǰжϱ־
 *
 * @return  ǰжϱ־
 */
#define UART0_GetITFlag()     (R8_UART0_IIR & RB_IIR_INT_MASK)

/**
 * @brief   ȡǰͨѶ״̬
 *
 * @return  refer to LINE error and status define
 */
#define UART0_GetLinSTA()     (R8_UART0_LSR)

/**
 * @brief   ڵֽڷ
 *
 * @param   b       ͵ֽ
 */
#define UART0_SendByte(b)     (R8_UART0_THR = b)

/**
 * @brief   ڶֽڷ
 *
 * @param   buf     - ͵׵ַ
 * @param   l       - ͵ݳ
 */
void UART0_SendString(uint8_t *buf, uint16_t l);

/**
 * @brief   ڶȡֽ
 *
 * @return  ȡĵֽ
 */
#define UART0_RecvByte()    (R8_UART0_RBR)

/**
 * @brief   ڶȡֽ
 *
 * @param   buf     - ȡŻ׵ַ
 *
 * @return  ȡݳ
 */
uint16_t UART0_RecvString(uint8_t *buf);

/**
 * @brief   Ĭϳʼ
 */
void UART1_DefInit(void);

/**
 * @brief   ڲ
 *
 * @param   baudrate    - 
 */
void UART1_BaudRateCfg(uint32_t baudrate);

/**
 * @brief   ֽڴж
 *
 * @param   b       - ֽ refer to UARTByteTRIGTypeDef
 */
void UART1_ByteTrigCfg(UARTByteTRIGTypeDef b);

/**
 * @brief   ж
 *
 * @param   s       - жϿ״̬ǷʹӦж
 * @param   i       - ж
 *                    RB_IER_MODEM_CHG  - ƽ״̬仯жʹλ UART0 ֧֣
 *                    RB_IER_LINE_STAT  - ·״̬ж
 *                    RB_IER_THR_EMPTY  - ͱּĴж
 *                    RB_IER_RECV_RDY   - ж
 */
void UART1_INTCfg(FunctionalState s, uint8_t i);

/**
 * @brief   λ
 */
void UART1_Reset(void);

/**
 * @brief   ǰFIFO
 */
#define UART1_CLR_RXFIFO()    (R8_UART1_FCR |= RB_FCR_RX_FIFO_CLR)

/**
 * @brief   ǰFIFO
 */
#define UART1_CLR_TXFIFO()    (R8_UART1_FCR |= RB_FCR_TX_FIFO_CLR)

/**
 * @brief   ȡǰжϱ־
 *
 * @return  ǰжϱ־
 */
#define UART1_GetITFlag()     (R8_UART1_IIR & RB_IIR_INT_MASK)

/**
 * @brief   ȡǰͨѶ״̬
 *
 * @return  refer to LINE error and status define
 */
#define UART1_GetLinSTA()     (R8_UART1_LSR)

/**
 * @brief   ڵֽڷ
 *
 * @param   b       ͵ֽ
 */
#define UART1_SendByte(b)     (R8_UART1_THR = b)

/**
 * @brief   ڶֽڷ
 *
 * @param   buf     - ͵׵ַ
 * @param   l       - ͵ݳ
 */
void UART1_SendString(uint8_t *buf, uint16_t l);

/**
 * @brief   ڶȡֽ
 *
 * @return  ȡĵֽ
 */
#define UART1_RecvByte()    (R8_UART1_RBR)

/**
 * @brief   ڶȡֽ
 *
 * @param   buf     - ȡŻ׵ַ
 *
 * @return  ȡݳ
 */
uint16_t UART1_RecvString(uint8_t *buf);

/**
 * @brief   Ĭϳʼ
 */
void UART2_DefInit(void);

/**
 * @brief   ڲ
 *
 * @param   baudrate    - 
 */
void UART2_BaudRateCfg(uint32_t baudrate);

/**
 * @brief   ֽڴж
 *
 * @param   b       - ֽ refer to UARTByteTRIGTypeDef
 */
void UART2_ByteTrigCfg(UARTByteTRIGTypeDef b);

/**
 * @brief   ж
 *
 * @param   s       - жϿ״̬ǷʹӦж
 * @param   i       - ж
 *                    RB_IER_MODEM_CHG  - ƽ״̬仯жʹλ UART0 ֧֣
 *                    RB_IER_LINE_STAT  - ·״̬ж
 *                    RB_IER_THR_EMPTY  - ͱּĴж
 *                    RB_IER_RECV_RDY   - ж
 */
void UART2_INTCfg(FunctionalState s, uint8_t i);

/**
 * @brief   λ
 */
void UART2_Reset(void);

/**
 * @brief   ǰFIFO
 */
#define UART2_CLR_RXFIFO()    (R8_UART2_FCR |= RB_FCR_RX_FIFO_CLR)

/**
 * @brief   ǰFIFO
 */
#define UART2_CLR_TXFIFO()    (R8_UART2_FCR |= RB_FCR_TX_FIFO_CLR)

/**
 * @brief   ȡǰжϱ־
 *
 * @return  ǰжϱ־
 */
#define UART2_GetITFlag()     (R8_UART2_IIR & RB_IIR_INT_MASK)

/**
 * @brief   ȡǰͨѶ״̬
 *
 * @return  refer to LINE error and status define
 */
#define UART2_GetLinSTA()     (R8_UART2_LSR)

/**
 * @brief   ڵֽڷ
 *
 * @param   b       ͵ֽ
 */
#define UART2_SendByte(b)     (R8_UART2_THR = b)

/**
 * @brief   ڶֽڷ
 *
 * @param   buf     - ͵׵ַ
 * @param   l       - ͵ݳ
 */
void UART2_SendString(uint8_t *buf, uint16_t l);

/**
 * @brief   ڶȡֽ
 *
 * @return  ȡĵֽ
 */
#define UART2_RecvByte()    (R8_UART2_RBR)

/**
 * @brief   ڶȡֽ
 *
 * @param   buf     - ȡŻ׵ַ
 *
 * @return  ȡݳ
 */
uint16_t UART2_RecvString(uint8_t *buf);

/**
 * @brief   Ĭϳʼ
 */
void UART3_DefInit(void);

/**
 * @brief   ڲ
 *
 * @param   baudrate    - 
 */
void UART3_BaudRateCfg(uint32_t baudrate);

/**
 * @brief   ֽڴж
 *
 * @param   b       - ֽ refer to UARTByteTRIGTypeDef
 */
void UART3_ByteTrigCfg(UARTByteTRIGTypeDef b);

/**
 * @brief   ж
 *
 * @param   s       - жϿ״̬ǷʹӦж
 * @param   i       - ж
 *                    RB_IER_MODEM_CHG  - ƽ״̬仯жʹλ UART0 ֧֣
 *                    RB_IER_LINE_STAT  - ·״̬ж
 *                    RB_IER_THR_EMPTY  - ͱּĴж
 *                    RB_IER_RECV_RDY   - ж
 */
void UART3_INTCfg(FunctionalState s, uint8_t i);

/**
 * @brief   λ
 */
void UART3_Reset(void);

/**
 * @brief   ǰFIFO
 */
#define UART3_CLR_RXFIFO()    (R8_UART3_FCR |= RB_FCR_RX_FIFO_CLR)

/**
 * @brief   ǰFIFO
 */
#define UART3_CLR_TXFIFO()    (R8_UART3_FCR |= RB_FCR_TX_FIFO_CLR)

/**
 * @brief   ȡǰжϱ־
 *
 * @return  ǰжϱ־
 */
#define UART3_GetITFlag()     (R8_UART3_IIR & RB_IIR_INT_MASK)

/**
 * @brief   ȡǰͨѶ״̬
 *
 * @return  refer to LINE error and status define
 */
#define UART3_GetLinSTA()     (R8_UART3_LSR)

/**
 * @brief   ڵֽڷ
 *
 * @param   b       ͵ֽ
 */
#define UART3_SendByte(b)     (R8_UART3_THR = b)

/**
 * @brief   ڶֽڷ
 *
 * @param   buf     - ͵׵ַ
 * @param   l       - ͵ݳ
 */
void UART3_SendString(uint8_t *buf, uint16_t l);

/**
 * @brief   ڶȡֽ
 *
 * @return  ȡĵֽ
 */
#define UART3_RecvByte()    (R8_UART3_RBR)

/**
 * @brief   ڶȡֽ
 *
 * @param   buf     - ȡŻ׵ַ
 *
 * @return  ȡݳ
 */
uint16_t UART3_RecvString(uint8_t *buf);

#ifdef __cplusplus
}
#endif

#endif // __CH58x_UART_H__
