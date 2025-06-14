#ifndef CHARGING_STATE_H
#define CHARGING_STATE_H

#define NUM_CELLS 112

float voltage[NUM_CELLS];
float current[NUM_CELLS];
float temperature[NUM_CELLS];


typedef enum{
	range_voltage,
	range_current,
	range_temperature,
	maximum_chargeable_voltage

}charging_sof_Error_Checks;

void charging_parameter_read(float *voltage,float *current, float *temperature);
void charging_cell_balancing(float *voltage,float *current, float *temperature,charging_sof_Error_Checks);
//this function must also be called if any cell voltage reaches its maximum voltage
void charging_soc_Calculate(float *voltage,float *current, float *temperature);
void charging_sof_Calculate(charging_sof_Error_Checks);
void charging_sop_Calculate(float *voltage,float *current, float *temperature);
void charging_soh_Calculate(float *voltage,float *current, float *temperature);
void charging_fan_speed_Control(int temperature); //for temperature control
void charge_complete(float *voltage,float *current, float *temperature,charging_sof_Error_Checks);
// if all cells reached their maximum chargeable voltage end the charging
