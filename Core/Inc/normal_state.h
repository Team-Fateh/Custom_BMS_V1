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
    minimum_cell_voltage
}sof_Error_Checks;

void parameter_read(input_parameters);
void soc_Calculate(input_parameters);
void sof_Calculate(sof_Error_Checks);
void sop_Calculate(input_parameters);
void soh_Calculate(input_parameters);
void fan_speed_Control(int temperature);
void cell_balancing(input_parameters);
void discharge_check(input_parameters,sof_Error_Checks);
//this function checks if any cell is discharged below the minimum threshold voltage
//fault handler include from main for each error
