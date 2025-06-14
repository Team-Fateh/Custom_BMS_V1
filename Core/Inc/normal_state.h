#ifndef __NORMAL_STATE_H
#define __NORMAL_STATE_H

#define NUM_CELLS 112

float voltage[NUM_CELLS];
float current[NUM_CELLS];
float temperature[NUM_CELLS];

typedef enum{
	range_voltage,
	range_current,
	range_temperature,
    minimum_cell_voltage
}sof_Error_Checks;

void parameter_read(float voltage,float current, float temperature);
void soc_Calculate(float voltage,float current, float temperature);
void sof_Calculate(sof_Error_Checks);
void sop_Calculate(float voltage,float current, float temperature);
void soh_Calculate(float voltage,float current, float temperature);
void fan_speed_Control(int temperature);
void cell_balancing(float voltage,float current, float temperature);
void discharge_check(float voltage,float current, float temperature,sof_Error_Checks);
//this function checks if any cell is discharged below the minimum threshold voltage
//fault handler include from main for each error
