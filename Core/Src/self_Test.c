/*
 * self_Test.c
 *
 *  Created on: Apr 26, 2025
 *      Author: tanishqsahu
 */

#include "self_Test.h"

//static uint8_t SELFTEST_TestCAN(void);
//static uint8_t SELFTEST_TestSPI(void);
//static uint8_t SELFTEST_TestGPIO(void);
//static uint8_t SELFTEST_TestCAN(void);

uint8_t SELFTEST_Run(void){
	if(SELFTEST_TestCAN()!=SELFTEST_OK){
		result=SELFTEST_FAIL;
	}
	if(SELFTEST_TestSPI()!=SELFTEST_OK){
		result=SELFTEST_FAIL;
	}
	if(SELFTEST_TestGPIO()!=SELFTEST_OK){
		result=SELFTEST_FAIL;
	}
	return result;
}

uint8_t SELFTEST_TestCAN(void){
	if(CAN_Init()!=CAN_OK){
		return SELFTEST_FAIL;
	}
	return SELFTEST_OK;
}

uint8_t SELFTEST_TestSPI(void){
	if(SPI_Init()!=SPI_OK){
		return SELFTEST_FAIL;
	}
	return SELFTEST_OK;
}

uint8_t SELFTEST_TestGPIO(void){
	if(GPIO_Init()!=GPIO_OK){
		return SELFTEST_FAIL;
	}
	return SELFTEST_OK;
}



