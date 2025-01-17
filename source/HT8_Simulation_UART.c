/**
  ******************************************************************************
  * @file HT8_Simulation_UART.c
  * @brief This file provides all the Simulation UART firmware functions.
  * @author Holtek Semiconductor Inc.
  * @version V1.0.0
  * @date 2018-12-20
  ******************************************************************************
  * @attention
  *
  * Firmware Disclaimer Information
  *
  * 1. The customer hereby acknowledges and agrees that the program technical documentation, including the
  *    code, which is supplied by Holtek Semiconductor Inc., (hereinafter referred to as "HOLTEK") is the
  *    proprietary and confidential intellectual property of HOLTEK, and is protected by copyright law and
  *    other intellectual property laws.
  *
  * 2. The customer hereby acknowledges and agrees that the program technical documentation, including the
  *    code, is confidential information belonging to HOLTEK, and must not be disclosed to any third parties
  *    other than HOLTEK and the customer.
  *
  * 3. The program technical documentation, including the code, is provided "as is" and for customer reference
  *    only. After delivery by HOLTEK, the customer shall use the program technical documentation, including
  *    the code, at their own risk. HOLTEK disclaims any expressed, implied or statutory warranties, including
  *    the warranties of merchantability, satisfactory quality and fitness for a particular purpose.
  *
  * <h2><center>Copyright (C) Holtek Semiconductor Inc. All rights reserved</center></h2>
  ************************************************************************************************************/
//#include "..\cc_generated_files\CodeConfig.h"
#include "HT8_Simulation_UART.h"


/**
  * @brief Simulation UART transmit function.
  * @param[in] transmit data,data bit:8,stop bit:1,parity:none
  * @retval None
  */
void UART_SoftWareSendByte(unsigned char TxData)
{
  _emi = 0;
	unsigned char  i;
	TXD = 0;					//start bit
	GCC_DELAY(BAUDRATE);
	
	for(i=0;i<8;i++)			//send 8-bit data
	{	
	
		if(TxData & 0x01)
		{
			TXD = 1;
		}
		else 
		{
			TXD = 0;
		}
		GCC_DELAY(BAUDRATE);
		TxData >>= 1;
	}
	TXD = 1;					//stop bit
	GCC_DELAY(BAUDRATE);
  _emi = 1;
}
void my_printf(char *p)
{
  while(*p != '\n')
  {
    UART_SoftWareSendByte(*p);
    p++;
  }
}

void my_printf_int(int num)
{
  char buffer[4]; // 假设整数最多20位
  int index = 0;
  int i = 0;
  if (num == 0)
  {
    UART_SoftWareSendByte('0');
    return;
  }

  if (num < 0)
  {
    UART_SoftWareSendByte('-');
    num = -num;
  }

  while (num > 0)
  {
    buffer[index++] = num % 10 + '0';
    num /= 10;
  }
   
  for (i = index - 1; i >= 0; i--)
  {
    UART_SoftWareSendByte(buffer[i]);
  }
}

/******************* (C) COPYRIGHT 2018 Holtek Semiconductor Inc *****END OF FILE****/