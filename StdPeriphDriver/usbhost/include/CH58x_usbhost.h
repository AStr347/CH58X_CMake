/********************************** (C) COPYRIGHT *******************************
 * File Name          : CH57x_usbhost.h
 * Author             : WCH
 * Version            : V1.2
 * Date               : 2021/11/17
 * Description
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * SPDX-License-Identifier: Apache-2.0
 *******************************************************************************/

#ifndef __CH58x_USBHOST_H__
#define __CH58x_USBHOST_H__

#ifdef __cplusplus
extern "C" {
#endif

#if DISK_LIB_ENABLE
  #if DISK_WITHOUT_USB_HUB
        /******************************************/
    #define FOR_ROOT_UDISK_ONLY
  #endif
    /******************************************/
  #define DISK_BASE_BUF_LEN    512  /* ĬϵĴݻСΪ512ֽ,ѡΪ20484096֧ĳЩU,Ϊ0ֹ.Hļж建ӦópDISK_BASE_BUFָ */
#endif

// ӳ򷵻״̬
#define ERR_SUCCESS            0x00  // ɹ
#define ERR_USB_CONNECT        0x15  /* ⵽USB豸¼,Ѿ */
#define ERR_USB_DISCON         0x16  /* ⵽USB豸Ͽ¼,ѾϿ */
#define ERR_USB_BUF_OVER       0x17  /* USB̫໺ */
#define ERR_USB_DISK_ERR       0x1F  /* USB洢ʧ,ڳʼʱUSB洢֧,ڶдпǴ𻵻ѾϿ */
#define ERR_USB_TRANSFER       0x20  /* NAK/STALLȸ0x20~0x2F */
#define ERR_USB_UNSUPPORT      0xFB  /* ֵ֧USB豸*/
#define ERR_USB_UNKNOWN        0xFE  /* 豸*/
#define ERR_AOA_PROTOCOL       0x41  /* Э汾 */

/*USB豸Ϣ,֧1豸*/
#define ROOT_DEV_DISCONNECT    0
#define ROOT_DEV_CONNECTED     1
#define ROOT_DEV_FAILED        2
#define ROOT_DEV_SUCCESS       3
#define DEV_TYPE_KEYBOARD      (USB_DEV_CLASS_HID | 0x20)
#define DEV_TYPE_MOUSE         (USB_DEV_CLASS_HID | 0x30)
#define DEF_AOA_DEVICE         0xF0
#define DEV_TYPE_UNKNOW        0xFF

/*
Լ: USB豸ַ(οUSB_DEVICE_ADDR)
ֵַ  豸λ
0x02    Root-HUBµUSB豸ⲿHUB
0x1x    Root-HUBµⲿHUBĶ˿xµUSB豸,xΪ1~n
*/
#define HUB_MAX_PORTS          4
#define WAIT_USB_TOUT_200US    800   // ȴUSBжϳʱʱ

typedef struct
{
    uint8_t  DeviceStatus;  // 豸״̬,0-豸,1-豸δʼ,2-豸ʼöʧ,3-豸ҳʼöٳɹ
    uint8_t  DeviceAddress; // 豸USBַ
    uint8_t  DeviceSpeed;   // 0Ϊ,0Ϊȫ
    uint8_t  DeviceType;    // 豸
    uint16_t DeviceVID;
    uint16_t DevicePID;
    uint8_t  GpVar[4];     // ͨñŶ˵
    uint8_t  GpHUBPortNum; // ͨñ,HUBʾHUB˿
} _RootHubDev;

typedef struct
{
    UINT8  DeviceStatus;  // 豸״̬,0-豸,1-豸δʼ,2-豸ʼöʧ,3-豸ҳʼöٳɹ
    UINT8  DeviceAddress; // 豸USBַ
    UINT8  DeviceSpeed;   // 0Ϊ,0Ϊȫ
    UINT8  DeviceType;    // 豸
    UINT16 DeviceVID;
    UINT16 DevicePID;
    UINT8  GpVar[4]; // ͨñ
} _DevOnHubPort;     // ٶ:1ⲿHUB,ÿⲿHUBHUB_MAX_PORTS˿(˲)

extern _RootHubDev   ThisUsbDev;
extern _DevOnHubPort DevOnHubPort[HUB_MAX_PORTS]; // ٶ:1ⲿHUB,ÿⲿHUBHUB_MAX_PORTS˿(˲)
extern uint8_t       UsbDevEndp0Size;             // USB豸Ķ˵0ߴ */
extern uint8_t       FoundNewDev;

extern uint8_t *pHOST_RX_RAM_Addr;
extern uint8_t *pHOST_TX_RAM_Addr;

extern _RootHubDev   ThisUsb2Dev;
extern _DevOnHubPort DevOnU2HubPort[HUB_MAX_PORTS]; // ٶ:1ⲿHUB,ÿⲿHUBHUB_MAX_PORTS˿(˲)
extern uint8_t       Usb2DevEndp0Size;              // USB豸Ķ˵0ߴ */
extern uint8_t       FoundNewU2Dev;

extern uint8_t *pU2HOST_RX_RAM_Addr;
extern uint8_t *pU2HOST_TX_RAM_Addr;

#define pSetupReq      ((PUSB_SETUP_REQ)pHOST_TX_RAM_Addr)
#define pU2SetupReq    ((PUSB_SETUP_REQ)pU2HOST_TX_RAM_Addr)
extern uint8_t Com_Buffer[];
extern uint8_t U2Com_Buffer[];

/* ΪUSB */
extern const uint8_t SetupGetDevDescr[];     // ȡ豸*/
extern const uint8_t SetupGetCfgDescr[];     // ȡ*/
extern const uint8_t SetupSetUsbAddr[];      // USBַ*/
extern const uint8_t SetupSetUsbConfig[];    // USB*/
extern const uint8_t SetupSetUsbInterface[]; // USBӿ*/
extern const uint8_t SetupClrEndpStall[];    // ˵STALL*/

extern const uint8_t SetupGetU2DevDescr[];    // ȡ豸*/
extern const uint8_t SetupGetU2CfgDescr[];    // ȡ*/
extern const uint8_t SetupSetUsb2Addr[];      // USBַ*/
extern const uint8_t SetupSetUsb2Config[];    // USB*/
extern const uint8_t SetupSetUsb2Interface[]; // USBӿ*/
extern const uint8_t SetupClrU2EndpStall[];   // ˵STALL*/

/**
 * @brief   رROOT-HUB˿,ʵӲѾԶر,˴ֻһЩṹ״̬
 */
void DisableRootHubPort(void);

/**
 * @brief   ROOT-HUB״̬,ROOT-HUB˿ڵ豸¼
 *          豸γ,еDisableRootHubPort(),˿ڹر,¼,Ӧ˿ڵ״̬λ
 *
 * @return  ERR_SUCCESSΪû,ERR_USB_CONNECTΪ⵽,ERR_USB_DISCONΪ⵽Ͽ
 */
uint8_t AnalyzeRootHub(void);

/**
 * @brief   USBǰUSB豸ַ
 *
 * @param   addr    - USB豸ַ
 */
void SetHostUsbAddr(uint8_t addr);

/**
 * @brief   õǰUSBٶ
 *
 * @param   FullSpeed   - USBٶ
 */
void SetUsbSpeed(uint8_t FullSpeed);

/**
 * @brief   ⵽豸,λ,Ϊö豸׼,ΪĬΪȫ
 */
void ResetRootHubPort(void);

/**
 * @brief   ʹROOT-HUB˿,ӦbUH_PORT_EN1˿,豸Ͽܵ·ʧ
 *
 * @return  ERR_SUCCESSΪ⵽,ERR_USB_DISCONΪ
 */
uint8_t EnableRootHubPort(void);

/**
 * @brief   ȴUSBж
 *
 * @return  ERR_SUCCESS ݽջ߷ͳɹ,ERR_USB_UNKNOWN ݽջ߷ʧ
 */
uint8_t WaitUSB_Interrupt(void);

/**
 * @brief   ,ĿĶ˵ַ/PID,ͬ־,20uSΪλNAKʱ(0,0xFFFF),0ɹ,ʱ/
 *          ӳ,ʵӦ,Ϊṩٶ,ӦöԱӳŻ
 *
 * @param   endp_pid    - ƺ͵ַ, 4λtoken_pid, 4λǶ˵ַ
 * @param   tog         - ͬ־
 * @param   timeout     - ʱʱ
 *
 * @return  ERR_USB_UNKNOWN ʱӲ쳣
 *          ERR_USB_DISCON  豸Ͽ
 *          ERR_USB_CONNECT 豸
 *          ERR_SUCCESS     
 */
uint8_t USBHostTransact(uint8_t endp_pid, uint8_t tog, uint32_t timeout);

/**
 * @brief   ִпƴ,8ֽpSetupReq,DataBufΪѡշ
 *
 * @param   DataBuf     - Ҫպͷ,ôDataBufָЧڴź
 * @param   RetLen      - ʵʳɹշܳȱRetLenָֽڱ
 *
 * @return  ERR_USB_BUF_OVER    IN״̬׶γ
 *          ERR_SUCCESS         ݽɹ
 */
uint8_t HostCtrlTransfer(uint8_t *DataBuf, uint8_t *RetLen);

/**
 * @brief   ƿƴ
 *
 * @param   pReqPkt     - ַ
 */
void CopySetupReqPkg(const uint8_t *pReqPkt);

/**
 * @brief   ȡ豸, pHOST_TX_RAM_Addr 
 *
 * @return  ERR_USB_BUF_OVER    ȴ
 *          ERR_SUCCESS         ɹ
 */
uint8_t CtrlGetDeviceDescr(void);

/**
 * @brief   ȡ, pHOST_TX_RAM_Addr 
 *
 * @return  ERR_USB_BUF_OVER    ȴ
 *          ERR_SUCCESS         ɹ
 */
uint8_t CtrlGetConfigDescr(void);

/**
 * @brief   USB豸ַ
 *
 * @param   addr    - 豸ַ
 *
 * @return  ERR_SUCCESS     ɹ
 */
uint8_t CtrlSetUsbAddress(uint8_t addr);

/**
 * @brief   USB豸
 *
 * @param   cfg     - ֵ
 *
 * @return  ERR_SUCCESS     ɹ
 */
uint8_t CtrlSetUsbConfig(uint8_t cfg);

/**
 * @brief   ˵STALL
 *
 * @param   endp    - ˵ַ
 *
 * @return  ERR_SUCCESS     ɹ
 */
uint8_t CtrlClearEndpStall(uint8_t endp);

/**
 * @brief   USB豸ӿ
 *
 * @param   cfg     - ֵ
 *
 * @return  ERR_SUCCESS     ɹ
 */
uint8_t CtrlSetUsbIntercace(uint8_t cfg);

/**
 * @brief   USBܳʼ
 */
void USB_HostInit(void);
uint8_t EnumAllHubPort(void);// öROOT-HUB˿ⲿHUBĶUSB豸
void SelectHubPort(uint8_t HubPortIndex); // HubPortIndex=0ѡָROOT-HUB˿,ѡָROOT-HUB˿ڵⲿHUBָ˿
uint16_t SearchTypeDevice(uint8_t type); // ROOT-HUBԼⲿHUB˿ָ͵豸ڵĶ˿ں,˿ںΪ0xFFFFδ.
uint8_t SETorOFFNumLock(uint8_t *buf); // NumLockĵж

void    DisableRootU2HubPort(void); // رROOT-U2HUB˿,ʵӲѾԶر,˴ֻһЩṹ״̬
uint8_t AnalyzeRootU2Hub(void);     // ROOT-U2HUB״̬,ROOT-U2HUB˿ڵ豸¼
// ERR_SUCCESSΪû,ERR_USB_CONNECTΪ⵽,ERR_USB_DISCONΪ⵽Ͽ
void    SetHostUsb2Addr(uint8_t addr);         // USBǰUSB豸ַ
void    SetUsb2Speed(uint8_t FullSpeed);       // õǰUSBٶ
void    ResetRootU2HubPort(void);              // ⵽豸,λӦ˿ڵ,Ϊö豸׼,ΪĬΪȫ
uint8_t EnableRootU2HubPort(void);             // ʹROOT-HUB˿,ӦbUH_PORT_EN1˿,豸Ͽܵ·ʧ
void    SelectU2HubPort(uint8_t HubPortIndex); // HubPortIndex=0ѡָROOT-HUB˿,ѡָROOT-HUB˿ڵⲿHUBָ˿
uint8_t WaitUSB2_Interrupt(void);              // ȴUSBж
// ,ĿĶ˵ַ/PID,ͬ־,20uSΪλNAKʱ(0,0xFFFF),0ɹ,ʱ/
uint8_t USB2HostTransact(uint8_t endp_pid, uint8_t tog, uint32_t timeout); // endp_pid: 4λtoken_pid, 4λǶ˵ַ
uint8_t U2HostCtrlTransfer(uint8_t *DataBuf, uint8_t *RetLen);           // ִпƴ,8ֽpSetupReq,DataBufΪѡշ
// Ҫպͷ,ôDataBufָЧڴź,ʵʳɹշܳȷرReqLenָֽڱ

void    CopyU2SetupReqPkg(const uint8_t *pReqPkt); // ƿƴ
uint8_t CtrlGetU2DeviceDescr(void);                // ȡ豸, pHOST_TX_RAM_Addr 
uint8_t CtrlGetU2ConfigDescr(void);                // ȡ, pHOST_TX_RAM_Addr 
uint8_t CtrlSetUsb2Address(uint8_t addr);          // USB豸ַ
uint8_t CtrlSetUsb2Config(uint8_t cfg);            // USB豸
uint8_t CtrlClearU2EndpStall(uint8_t endp);        // ˵STALL
uint8_t CtrlSetUsb2Intercace(uint8_t cfg);         // USB豸ӿ

void USB2_HostInit(void); // ʼUSB

/*************************************************************/

/**
 * @brief   ʼָROOT-HUB˿ڵUSB豸
 *
 * @return  
 */
uint8_t InitRootDevice(void);

/**
 * @brief   ȡHID豸,TxBuffer
 *
 * @return  
 */
uint8_t CtrlGetHIDDeviceReport(uint8_t infc);

/**
 * @brief   ȡHUB,Com_Buffer
 *
 * @return  
 */
uint8_t CtrlGetHubDescr(void);

/**
 * @brief   ѯHUB˿״̬,Com_Buffer
 *
 * @param   HubPortIndex    - ˿ں
 *
 * @return  
 */
uint8_t HubGetPortStatus(uint8_t HubPortIndex);

/**
 * @brief   HUB˿
 *
 * @param   HubPortIndex    - ˿ں
 * @param   FeatureSelt     - ˿
 *
 * @return  
 */
uint8_t HubSetPortFeature(uint8_t HubPortIndex, uint8_t FeatureSelt);

/**
 * @brief   HUB˿
 *
 * @param   HubPortIndex    - ˿ں
 * @param   FeatureSelt     - ˿
 *
 * @return  
 */
uint8_t HubClearPortFeature(uint8_t HubPortIndex, uint8_t FeatureSelt);

uint8_t  InitRootU2Device(void);
uint8_t  EnumAllU2HubPort(void);
uint16_t U2SearchTypeDevice(uint8_t type);
uint8_t  U2SETorOFFNumLock(uint8_t *buf);

uint8_t CtrlGetU2HIDDeviceReport(uint8_t infc);                           // HIDSET_IDLEGET_REPORT
uint8_t CtrlGetU2HubDescr(void);                                          // ȡHUB,TxBuffer
uint8_t U2HubGetPortStatus(uint8_t HubPortIndex);                         // ѯHUB˿״̬,TxBuffer
uint8_t U2HubSetPortFeature(uint8_t HubPortIndex, uint8_t FeatureSelt);   // HUB˿
uint8_t U2HubClearPortFeature(uint8_t HubPortIndex, uint8_t FeatureSelt); // HUB˿

#ifdef __cplusplus
}
#endif

#endif // __CH58x_USBHOST_H__
