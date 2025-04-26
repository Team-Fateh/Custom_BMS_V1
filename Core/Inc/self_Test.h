/*
 * self_Test.h
 *
 *  Created on: Apr 26, 2025
 *      Author: tanishqsahu
 */

#ifndef INC_SELF_TEST_H_
#define INC_SELF_TEST_H_

#define SELFTEST_OK  0
#define SELFTEST_FAIL 1

/*
 FUNCTION PROTOTYPES
 */

uint8_t SELFTEST_Run(void);

uint8_t SELFTEST_TestCAN(void);

uint8_t SELFTEST_TestSPI(void);

uint8_t SELFTEST_TestGPIO(void);

#endif /* INC_SELF_TEST_H_ */
