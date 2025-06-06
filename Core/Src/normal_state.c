#incldue "normal_state.h"

void parameter_read(input_parameters)
{
	//get voltage,current,temperature from sensors
}
void soc_calculate(input_parameters)
{
	//soc calculation using algorithms by yash
}

void soh_calculate(input_parameters)
{
	//soh using algorithms
}

void sof_calculate(sof_error_checks)
{
	if(//input in normal range ){
			//continue}
	elseif(//input is higher or lower than than the normal range){
			//send error}
			// call fault handler function
}

void sop_calculate(input_paraemeters)
{
	// sop_Calculation using algorithms
}

void fan_speed_Control(int temperature)
{
	if(// temperature above certain values start fans with different rpm using pwm)
}

