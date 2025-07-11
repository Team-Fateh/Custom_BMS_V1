#ifndef __NORMAL_STATE_H
#define __NORMAL_STATE_H

#define NUM_CELLS 112
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------//
// 1. VOLTAGE 
#define VCELL_THRESH_UV_OV 0XB //Overvoltage and Undervoltage Cell Threshold RW
#define VBATT_SUM_TH 0XC //Overvoltage and Undervoltage Module Threshold RW
#define VCELLS_EN 0X1C //Enable Cell Conversion jo bhi connected ho 
#define VCELL_1 0x21 //Voltage Measurement of Cell-1
#define VCELL_2 0x22 //Voltage Measurement of Cell-2
#define VCELL_3 0x23 //Voltage Measurement of Cell-3
#define VCELL_4 0x24 //Voltage Measurement of Cell-4
#define VCELL_5 0x25 //Voltage Measurement of Cell-5
#define VCELL_6 0x26 //Voltage Measurement of Cell-6
#define VCELL_7 0x27 //Voltage Measurement of Cell-7
#define VCELL_8 0x28 //Voltage Measurement of Cell-8
#define VCELL_9 0x29 //Voltage Measurement of Cell-9
#define VCELL_10 0x2A //Voltage Measurement of Cell-10
#define VCELL_11 0x2B //Voltage Measurement of Cell-11
#define VCELL_12 0x2C //Voltage Measurement of Cell-12
#define VCELL_13 0x2D //Voltage Measurement of Cell-12
#define VCELL_14 0x2E //Voltage Measurement of Cell-12
#define VSUMBATT 0x40 //Digital Sum Of Cells (MSB)
#define VBATTDIV 0x41 //Digital Summ Of Cells (LSB) and VBAT Direct Conversion Data 
#define VCELL_UV 0x43 //Individual Cell Undervoltages with VBAT Undervoltage 
#define CELL_OV 0x44 //Individual Cell Overvoltages with VBAT Overvoltage 
#define VBURST 0x78 //Instantly sends all frames of cell voltages
#define FAULTMASK 0x1D //Used for masking UV faults in all cells 

// 2. CURRENT 
#define CSA_THRESH_NORM 0x1F //Determines the CSA overcurrent threshold in Normal State 
#define CSA_GPIO_MSK 0x20 //Mix of current & temperature ke parameters both RW and RLR 
#define IBATTERY_SYNCH 0x2F //Current sample synchronise karna smthin smthin (Pg-116)
#define COUL_CNTR_TIME 0x31 //Number of current samples acquired 
#define COUL_CNTR_MSB 0x32 //Current Sample Accumulator (MSB)
#define COUL_CNTR_LSB 0x33 //Current Sample Accumulator (LSB)

// 3. TEMPERATURE (GPIOs ka configure)
#define GPIO9_3CONF 0x14 //GPIOs ko Analog/Digital aur Output/Input 
#define GPIO3_THR 0x15 //GPIO3 Overtemp & Undertemp 
#define GPIO4_THR 0x16 //GPIO4 Overtemp & Undertemp
#define GPIO5_THR 0x17 //GPIO5 Overtemp & Undertemp
#define GPIO6_THR 0x18 //GPIO6 Overtemp & Undertemp
#define GPIO7_THR 0x19 //GPIO7 Overtemp & Undertemp
#define GPIO8_THR 0x1A //GPIO8 Overtemp & Undertemp
#define GPIO9_THR 0x1B //GPIO9 Overtemp & Undertemp
#define GPIO3_MEAS 0x34 //GPIO 3 Measurement Data 
#define GPIO4_MEAS 0x35 //GPIO 4 Measurement Data 
#define GPIO5_MEAS 0x36 //GPIO 5 Measurement Data 
#define GPIO6_MEAS 0x37 //GPIO 6 Measurement Data 
#define GPIO7_MEAS 0x38 //GPIO 7 Measurement Data 
#define GPIO8_MEAS 0x39 //GPIO 8 Measurement Data 
#define GPIO9_MEAS 0x3A //GPIO 9 Measurement Data 
#define TEMP_CHIP 0x3B //Device Die Temperature & Overtemp Detection 
#define GPIO_FASTHG_OT 0x47 //GPIOs ke OT & open detection 




float voltage[NUM_CELLS];
float current[NUM_CELLS];
float temperature[NUM_CELLS];

typedef enum{
	range_voltage,
	range_current,
	range_temperature,
    minimum_cell_voltage
}sof_Error_Checks;

void parameter_read(float *voltage,float *current, float *temperature);
void soc_Calculate(float *voltage,float *current, float *temperature);
void sof_Calculate(sof_Error_Checks);
void sop_Calculate(float *voltage,float *current, float *temperature);
void soh_Calculate(float *voltage,float *current, float *temperature);
void fan_speed_Control(int temperature);
void cell_balancing(float *voltage,float *current, float *temperature);
void discharge_check(float *voltage,float *current, float *temperature,sof_Error_Checks);
//this function checks if any cell is discharged below the minimum threshold voltage
//fault handler include from main for each error

//---------------------------------------------------------------------------------------------------------------------------------------------------------------//
// 03-07-2025                   
// SPI Lines 
#define CS 
#define MOSI
#define MISO 
#define SCLK 






