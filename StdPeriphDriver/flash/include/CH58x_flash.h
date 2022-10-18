/********************************** (C) COPYRIGHT *******************************
 * File Name          : CH57x_flash.h
 * Author             : WCH
 * Version            : V1.2
 * Date               : 2021/11/17
 * Description
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * SPDX-License-Identifier: Apache-2.0
 *******************************************************************************/

#ifndef __CH58x_FLASH_H__
#define __CH58x_FLASH_H__

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   ȡFlash-ROM
 *
 * @param   StartAddr   - read address
 * @param   Buffer      - read buffer
 * @param   len         - read len
 */
extern void FLASH_ROM_READ(uint32_t StartAddr, void *Buffer, uint32_t len);

//extern void FLASH_ROM_READ(UINT32 StartAddr, PVOID Buffer, UINT32 len); /* ȡFlash-ROM */

uint8_t UserOptionByteConfig(FunctionalState RESET_EN, FunctionalState BOOT_PIN, FunctionalState UART_NO_KEY_EN,
                           uint32_t FLASHProt_Size);

extern UINT8 UserOptionByteClose_SWD(void);

extern void UserOptionByte_Active(void);

#ifdef __cplusplus
}
#endif

#endif // __CH58x_FLASH_H__
