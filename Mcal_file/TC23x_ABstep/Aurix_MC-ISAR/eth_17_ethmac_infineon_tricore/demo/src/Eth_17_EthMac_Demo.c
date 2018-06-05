/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Eth_17_EthMac_Demo.c $                                     **
**                                                                           **
**  $CC VERSION : \main\33 $                                                 **
**                                                                           **
**  $DATE       : 2015-11-05 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                Demo application for Ethernet driver                       **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Ifx_reg.h"

#include "Eth_17_EthMac.h"
#include "EthIf_Cbk.h"

#include "Test_Setup.h"
#include "Test_Print.h"
#include "Test_Time.h"
#include "Test_Main.h"
/* Inclusion of  Mcal header file */
#include "Mcal.h"
#include "IfxCpu_reg.h"

#include "Eth_17_EthMac_Demo.h"
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define CPU_PSW_USER_MODE_MASK (0xFFFFF3FFU)
#define SET_USER_MODE_MASK ((1U  <<  10U))
#define ETH_IP_PROTOCOL                         (0X0800U)
#define ETH_ARP_PROTOCOL                        (0X0806U)
                                                
#define PHY_CTRL_REG                            (0x00) 
#define PHY_STAT_REG                            (0x01) 
#define PHY_PHYCTL1_REG                         (0x13) 
#define PHY_PHYCTL2_REG                         (0x14) 
#define PHY_MIICTRL_REG                         (0x17)
                                                
#define PHY_100MBPS_FULLDPLX_REG_VAL            (0x2100) 
                                                
#define PHY_PHYCTL1_REG_VAL                     (0x0001) 
#define PHY_PHYCTL2_REG_VAL                     (0x8006) 
                                                
#define PHY_MIICTRL_RMII_REG_VAL                (0xF702)
                                                
#define ETH_PHY_REG_COUNT                       (32U)
                                                
#define ETH_PHY_INIT_DURATION                   (500U)
                                                
#define ETH_FRAME_TYPE_1                        (0xABCDU)
                                                
#define MMC_TX_GB_REG_BASE_OFFSET               (0x124U)
#define MMC_RX_GB_REG_BASE_OFFSET               (0x1ACU)
                                                
#define ETH_ESC_CHAR_ASCII_VAL                  (27U)
                                                
#define ETH_OFFSET_4_BYTE                       (4U)
#define ETH_OFFSET_8_BYTE                       (8U)
#define ETH_OFFSET_12_BYTE                      (12U)
#define ETH_OFFSET_16_BYTE                      (16U)
#define ETH_OFFSET_20_BYTE                      (20U)
                                                
#define ETH_IPADDRESS_LENGTH                    (4U)
                                                
#define ETH_ARPFRAME_DEST_IPADD_OFFSET          (24U)
                                                
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
uint32 JBFrameCount;
uint32 Src_IPaddress = 0xa9fefeab;
static uint16 PhyReg[32];
static uint8 Temp_Macaddress[6];
static uint8 MacDestArpaddress[6]=
{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF}; /*Broadcast*/

static uint8 TmpBuffIdx;
static uint8 *TmpBuffPtr[5];
static volatile BufReq_ReturnType Global_TempUSage1;
volatile Std_ReturnType EthDemoRetVal;

uint8 ArpReply;

uint8 ArpData[28]=
{ 
0x00,0x01,0x08,0x00,0x06,0x04,0x00,0x01,0x00,0x03,0x19,0x00,0x00,0x01,
0xa9,0xfe,0xfe,0xab,0x00,0x00,0x00,0x00,0x00,0x00,0xa9,0xfe,0xab,0xa8
};

static uint8 MacDestBrodaddress[6] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

/*******************************************************************************
**    Fill Tx Buffer           **
*******************************************************************************/

void TxBufferFill(uint8 *pTxBuff,uint16 DataLen,uint8 *Framedatax )
{
  uint8 i=0;
  for(;i<DataLen ;i++)
    {
      *(pTxBuff + i)= Framedatax[i];
    }
 return;
}

/*******************************************************************************
**    Transmit Arp Frame           **
*******************************************************************************/
void TransmitArpFrame(void)
{
  boolean Txstatus1=0; 
  uint16 Tmp_Txlenghth1 = 28;
  
  Global_TempUSage1 = Eth_17_EthMac_ProvideTxBuffer(0,&TmpBuffIdx,TmpBuffPtr,&Tmp_Txlenghth1);

  TxBufferFill(TmpBuffPtr[0],Tmp_Txlenghth1,ArpData);

  EthDemoRetVal = Eth_17_EthMac_Transmit(0,TmpBuffIdx,ETH_ARP_PROTOCOL,Txstatus1,Tmp_Txlenghth1,&MacDestBrodaddress[0]);
}

/*******************************************************************************
**    Initialise Eth Driver including PHY        **
*******************************************************************************/

void TransmitInit (void)
{
  uint32 i;
  
  Eth_17_EthMac_ControllerInit(0, 0);
  Eth_17_EthMac_SetControllerMode(0,ETH_MODE_ACTIVE);
  
  Eth_17_EthMac_GetPhysAddr((uint8)0,&Temp_Macaddress[0]);
 
  /* RMII Mode,Twisted pair MAC,3.5ns timing skew for Tx and Rx,RClk ON */
  Eth_17_EthMac_WriteMii(0,0,PHY_MIICTRL_REG,PHY_MIICTRL_RMII_REG_VAL);

  /* AUTO PHY - MDI*/
  Eth_17_EthMac_WriteMii(0,0,PHY_PHYCTL1_REG,PHY_PHYCTL1_REG_VAL);

  /* ADS3, PSCL ON,Auto Negotiation ON*/
  Eth_17_EthMac_WriteMii(0,0,PHY_PHYCTL2_REG,PHY_PHYCTL2_REG_VAL);

  /* Full_Duplex,100Mbps*/
  Eth_17_EthMac_WriteMii(0,0,PHY_CTRL_REG,PHY_100MBPS_FULLDPLX_REG_VAL);     

  /* Read PHY Registers*/
  for(i=0;i < ETH_PHY_REG_COUNT;i++)
  {     
    Eth_17_EthMac_ReadMii((uint8)0,(uint8)0,(uint8)i,&PhyReg[i]); 
  }
  
  while (1 == 1)
  {
    Eth_17_EthMac_ReadMii((uint8)0,(uint8)0,(uint8)PHY_STAT_REG,&PhyReg[0]);
    
    if ((PhyReg[0] & (1 << 2)) != 0)
      break;/* Link Established */
  }

  print_f("\n ETH Driver Initialised Successfully ");
  print_f("\n Ethernet LINK UP ");

  Timer_DelayMs(ETH_PHY_INIT_DURATION); 
}
/*******************************************************************************
**    Ping Application                                            **
*******************************************************************************/
void Ping_App(void)
{
  char c;
  uint8 i;
  char param[20];
  char szString1[20];
  char *pszString1;
  uint32 paramArray[6];
  uint8 paramCount=0,charCount=0;
  print_f("\n\n Enter IP Address to Ping(Your PC IP) : ");
  getline(szString1, sizeof szString1 - 1);
  pszString1 = &szString1[0];

  do
  {
    /* Look for the '.' delimiter */
    if (*pszString1 != '.')
    {
        param[charCount++]= (char) *pszString1;
    }   
    else
    {
        param[charCount] = 0;
        paramArray[paramCount] = (uint32)atoi(param);
        paramCount++;        
        charCount = 0;
    }
    pszString1++;
  }while (*pszString1 != '\0');

  param[charCount] = 0;
  paramArray[paramCount] = (uint32) atoi(param);
  ETH_OPERATION_MODE.B.DFF = 0U; /* Flush the Rx FIFO */
  for(i=0;i<ETH_IPADDRESS_LENGTH;i++)
  {
    ArpData[ETH_ARPFRAME_DEST_IPADD_OFFSET+i] = (uint8)paramArray[i];
  }
  Src_IPaddress = (((paramArray[0]&0xFF)<<ETH_SHIFT_24BIT)|((paramArray[1]&0xFF)<<ETH_SHIFT_16BIT)|((paramArray[2]&0xFF)<<ETH_SHIFT_8BIT)|(paramArray[3]&0xFF));
  ETH_OPERATION_MODE.B.DFF = 1U; /* Disable Flush the Rx FIFO */
  TransmitArpFrame();

    do
    {
      Eth_17_EthMac_Receive(0);
    }while(( ArpReply != 1)&&((c=(char)get_ch()) != (char)ETH_ESC_CHAR_ASCII_VAL));

    if(ArpReply == 1)
    {
      ArpReply = 0;
    }
    else
    {
      print_f("\n Destination Host Unreachable\n  ");
      print_f("Reason 1: Ethernet Cross Wire is NOT connected between AURIX Tri-Board and Your PC\n ");
      print_f("Reason 2: IP Address Entered is Wrong\n ");
    }
 }

/*******************************************************************************
**    Promiscuous mode Receive all Frames                                     **
*******************************************************************************/
void Receive_Poll (void)
{
  char c;

  do
  {
    Eth_17_EthMac_Receive(0);
  }while( (c=(char)get_ch()) != (char)ETH_ESC_CHAR_ASCII_VAL);
 /* Wait Till Esc Key is pressed */   
 }

/*******************************************************************************
**    Transmit ETH Frame of User Defined Length                               **
*******************************************************************************/
void Tx_EthFrame (void)
{
  char szString[80];
  uint16 TmpTxlength,i;
  uint8 *TmpEthTxBuffPtr;  
  
  TxFrameCount = 0;     

  print_f("\n\n Enter ETH Frame Payload Length(42...1500) : ");
  getline(szString, sizeof szString - 1);                                   
     
  TmpTxlength = (uint16)atoi(szString);

  Global_TempUSage1 = Eth_17_EthMac_ProvideTxBuffer(0,&TmpBuffIdx,&TmpEthTxBuffPtr,&TmpTxlength);

  for (i=0; i < TmpTxlength ; i++)
  {
     *TmpEthTxBuffPtr = i+1;
     TmpEthTxBuffPtr+=1;
  }

  EthDemoRetVal = Eth_17_EthMac_Transmit(0,TmpBuffIdx,ETH_FRAME_TYPE_1,1,TmpTxlength,&MacDestArpaddress[0]);
  Timer_DelayMs(300);
  #if (!((ETH_17_ENA_TX_INT == STD_ON) && (ETH_17_ENA_RX_INT == STD_ON)))
  do
  {
    Eth_17_EthMac_TxConfirmation(0); 
  }
  #endif
  while(!TxFrameCount);

  print_f("\n Transmitted ETH Frame of FrameType 0xABCD");
  print_f("\n Payload Length %d bytes and Total Frame Length %d bytes\n",TmpTxlength,(TmpTxlength+ETH_FRAMEHEADER_LENGTH+ETH_FRAMECHKSUM_LENGTH));
  TxFrameCount = 0;     
}

/*******************************************************************************
**    Get Tx Frame Count for Different Frame Lengths                          **
*******************************************************************************/
void Get_TxFrameCount (void)
{
  uint32 MMC_CtrVal;
  
  Eth_17_EthMac_GetCounterState(0, MMC_TX_GB_REG_BASE_OFFSET, &MMC_CtrVal);              

  print_f("\n No. of Good and Bad Frame Transmitted with Length 64 bytes: %d\n ",MMC_CtrVal);

  Eth_17_EthMac_GetCounterState(0, MMC_TX_GB_REG_BASE_OFFSET + ETH_OFFSET_4_BYTE, &MMC_CtrVal);              

  print_f("No. of Good and Bad Frame Transmitted with Length between 65 and 127 bytes: %d\n ",MMC_CtrVal);

  Eth_17_EthMac_GetCounterState(0, MMC_TX_GB_REG_BASE_OFFSET + ETH_OFFSET_8_BYTE, &MMC_CtrVal);              

  print_f("No. of Good and Bad Frame Transmitted with Length between 128 and 255 bytes: %d\n ",MMC_CtrVal);

  Eth_17_EthMac_GetCounterState(0, MMC_TX_GB_REG_BASE_OFFSET + ETH_OFFSET_12_BYTE, &MMC_CtrVal);              

  print_f("No. of Good and Bad Frame Transmitted with Length between 256 and 511 bytes: %d\n ",MMC_CtrVal);

  Eth_17_EthMac_GetCounterState(0, MMC_TX_GB_REG_BASE_OFFSET + ETH_OFFSET_16_BYTE, &MMC_CtrVal);              

  print_f("No. of Good and Bad Frame Transmitted with Length between 512 and 1023 bytes: %d\n ",MMC_CtrVal);

  Eth_17_EthMac_GetCounterState(0, MMC_TX_GB_REG_BASE_OFFSET + ETH_OFFSET_20_BYTE, &MMC_CtrVal);              

  print_f("No. of Good and Bad Frame Transmitted with Length 1024 and 1522 bytes: %d\n ",MMC_CtrVal);
}

/*******************************************************************************
**    Get Rx Frame Count for Different Frame Lengths                          **
*******************************************************************************/
void Get_RxFrameCount (void)
{
  uint32 MMC_CtrVal;
  
  Eth_17_EthMac_GetCounterState(0, MMC_RX_GB_REG_BASE_OFFSET, &MMC_CtrVal);              

  print_f("\n No. of Good and Bad Frame Received with Length 64 bytes: %d\n ",MMC_CtrVal);

  Eth_17_EthMac_GetCounterState(0, MMC_RX_GB_REG_BASE_OFFSET + ETH_OFFSET_4_BYTE, &MMC_CtrVal);              

  print_f("No. of Good and Bad Frame Received with Length between 65 and 127 bytes: %d\n ",MMC_CtrVal);

  Eth_17_EthMac_GetCounterState(0, MMC_RX_GB_REG_BASE_OFFSET + ETH_OFFSET_8_BYTE, &MMC_CtrVal);              

  print_f("No. of Good and Bad Frame Received with Length between 128 and 255 bytes: %d\n ",MMC_CtrVal);

  Eth_17_EthMac_GetCounterState(0, MMC_RX_GB_REG_BASE_OFFSET + ETH_OFFSET_12_BYTE, &MMC_CtrVal);              

  print_f("No. of Good and Bad Frame Received with Length between 256 and 511 bytes: %d\n ",MMC_CtrVal);

  Eth_17_EthMac_GetCounterState(0, MMC_RX_GB_REG_BASE_OFFSET + ETH_OFFSET_16_BYTE, &MMC_CtrVal);              

  print_f("No. of Good and Bad Frame Received with Length between 512 and 1023 bytes: %d\n ",MMC_CtrVal);

  Eth_17_EthMac_GetCounterState(0, MMC_RX_GB_REG_BASE_OFFSET + ETH_OFFSET_20_BYTE, &MMC_CtrVal);              

  print_f("No. of Good and Bad Frame Received with Length 1024 and 1522 bytes: %d\n ",MMC_CtrVal);
}

/*******************************************************************************
**    Read PHY Registers                          **
*******************************************************************************/
void Read_PhyReg (void)
{
  uint16 Ret_RegVal;
  
  Eth_17_EthMac_ReadMii(0, 0, PHY_CTRL_REG, &Ret_RegVal);              

  print_f("\n Reg Value Read from Ethernet PHY RegIdx 0 (PHY_CTRL_REG): 0x%x \n ",Ret_RegVal);

  Eth_17_EthMac_ReadMii(0, 0, PHY_STAT_REG, &Ret_RegVal);              

  print_f("Reg Value Read from Ethernet PHY RegIdx 1 (PHY_STAT_REG): 0x%x \n ",Ret_RegVal);

  Eth_17_EthMac_ReadMii(0, 0, PHY_PHYCTL1_REG, &Ret_RegVal);              

  print_f("Reg Value Read from Ethernet PHY RegIdx 19 (PHY_PHYCTL1_REG): 0x%x \n ",Ret_RegVal);

  Eth_17_EthMac_ReadMii(0, 0, PHY_PHYCTL2_REG, &Ret_RegVal);              

  print_f("Reg Value Read from Ethernet PHY RegIdx 20 (PHY_PHYCTL2_REG): 0x%x \n ",Ret_RegVal);

  Eth_17_EthMac_ReadMii(0, 0, PHY_MIICTRL_REG, &Ret_RegVal);              

  print_f("Reg Value Read from Ethernet PHY RegIdx 23 (PHY_MIICTRL_REG): 0x%x \n ",Ret_RegVal);

}

/*******************************************************************************
** Syntax : void Eth_17_Demo(void)                                            **
**                                                                            **
** Service ID:   : NA                                                         **
**                                                                            **
** Sync/Async:   : Synchronous                                                **
**                                                                            **
** Reentrancy:   : Non Reentrant                                              **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : Ethernet Demo Application                                   **
*******************************************************************************/
void Eth_17_Demo(void)
{
  #ifdef IFX_MCAL_RUN_MODE_DEFINE
  /* IFX_MCAL_RUN_MODE_DEFINE = 0 indicates MCAL,
  runs in Supervisor mode*/
  #if(IFX_MCAL_RUN_MODE_DEFINE != 0U)
  uint32 Cpu_PSW;
  #endif 
  #endif 
  char szString[10];
  volatile uint8 loopvar = 0;
  volatile uint8 EN1Val, EN1SelVal, PortPC12;
  EN1Val = (uint8)SCU_EXTCON.B.EN1;
  EN1SelVal = (uint8)SCU_EXTCON.B.SEL1;
  PortPC12 = (uint8)P11_IOCR12.B.PC12;

  Mcal_ResetSafetyENDINIT_Timed(150000U);
  P11_IOCR12.B.PC12 = 0x16U;
  SCU_EXTCON.B.SEL1 = 5U;
  SCU_EXTCON.B.EN1 = 1U;
  Mcal_SetSafetyENDINIT_Timed();

  TransmitInit(); /* Initialise Eth Driver including PHY */

  Mcal_ResetSafetyENDINIT_Timed(150000U);
  SCU_EXTCON.B.EN1 = EN1Val;
  SCU_EXTCON.B.SEL1 = EN1SelVal;
  P11_IOCR12.B.PC12 = PortPC12;
  Mcal_SetSafetyENDINIT_Timed();
  
  #ifdef IFX_MCAL_RUN_MODE_DEFINE
  /* IFX_MCAL_RUN_MODE_DEFINE = 0 indicates MCAL,
    runs in Supervisor mode*/
  #if(IFX_MCAL_RUN_MODE_DEFINE != 0U)
      /* Set the user-1 mode on*/
  Cpu_PSW = (uint32)MFCR(CPU_PSW);
  Cpu_PSW = (Cpu_PSW & CPU_PSW_USER_MODE_MASK);
  Cpu_PSW = (Cpu_PSW | SET_USER_MODE_MASK);
  MTCR (CPU_PSW, Cpu_PSW); /* Set mode to user-1 mode. */
  #endif /* IFX_MCAL_RUN_MODE_DEFINE */
  #endif /* IFX_MCAL_RUN_MODE_DEFINE */

  while (loopvar == 0)
  {
     print_f("\n\n\n");
     print_f("\n/*********************************************************/\n");
     print_f("\n           ETH DRIVER DEMO MENU                          ");
     print_f("\n                                                         ");
     print_f("\n  <1> :Promiscuous Mode: Receive All Frames ");
     print_f("\n  Note : Press ESC Key to STOP Receiving Frames\n");
     print_f("\n  <2> :PING Application"     );
     print_f("\n  Note : Press ESC Key to Exit If WRONG IP is Entered and Hence NO ARP Reply\n");
     print_f("\n  <3> :Transmit ETH Frame of User Defined Payload Length");
     print_f("\n  <4> :Get Tx Frame Count for Different Frame Lengths");
     print_f("\n  <5> :Get Rx Frame Count for Different Frame Lengths");
     print_f("\n  <6> :Read PHY Registers ");
     print_f("\n  <x> :Go back to Main Menu    \n");      
     print_f("\n  ENTER YOUR OPTION   : ");
     
     getline(szString, sizeof szString - 1);                                   
    
     switch (*szString)
     {
        case '1':   
          Receive_Poll();
          break;

        case '2':   
          Ping_App();
          break;          

        case '3':   
          Tx_EthFrame();
          break;          

        case '4':   
          Get_TxFrameCount();
          break;          

         case '5':   
          Get_RxFrameCount();
          break;          

         case '6':   
          Read_PhyReg();
          break;          

         case 'x':   
          loopvar = 1;
          break;          

         default:
         print_f("\n\n  INVALID OPTION");
          break;
    }/* End of Case */
  }/* End of While loop */
}


