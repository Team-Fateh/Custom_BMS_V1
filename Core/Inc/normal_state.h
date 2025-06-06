#ifndef __NORMAL_STATE_H
#define __NORMAL_STATE_H

typedef enum{
	voltage,
	current,
	temperature
}input_parameters;

typedef enum{
	range_voltage,
	range_current,
	range_temperature,

}sof_Error_Checks;

void parameter_read(input_parameters);
void soc_Calculate(input_parameters);
void sof_Calculate(sof_Error_Checks);
void sop_Calculate(input_parameters);
void soh_Calculate(input_parameters);
void fan_speed_Control(int temperature);
//fault handler incldue from main for each error
