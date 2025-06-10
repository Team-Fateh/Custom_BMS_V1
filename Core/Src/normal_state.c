#include "normal_state.h"

void parameter_read(input_parameters)
{
	//get voltage,current,temperature from sensors
}
void soc_Calculate(input_parameters)
{
	//soc calculation using algorithms by yash
}

void soh_Calculate(input_parameters)
{
	//soh using algorithms
}

void sof_Calculate(sof_error_checks)
{
	if(//input in normal range ){
			//continue}
	elseif(//input is higher or lower than than the normal range){
			//send error}
			// call fault handler function
}

void sop_Calculate(input_parameters)
{
	// sop_Calculation using algorithms
}

void fan_speed_Control(int temperature)
{
	if(// temperature above certain values start fans with different rpm using pwm)
}
void cell_balancing(input_parameters){
	    //read cell voltages
		//periodically - passively balance the cells
		//use shunt resistors
}
void discharge_check(input_parameters,sof_Error_Checks){
	if(//any cell voltage <= minimum_cell_voltage){
			//terminate the system
			//stop... discharge
}
