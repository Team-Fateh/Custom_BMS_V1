#include "charging_state.h"

void charging_parameter_read(charging_parameters){
	//get voltage,current and temperature from sensors
}

void charging_soc_Calculate(charging_parameters){
	//soc calculation algorithm
}


void charging_soh_Calculate(charging_parameters){
	//soh calculation algorithm
}


void charging_sop_Calculate(charging_parameters){
	//sop calculation algorithm
}
void charge_complete(charging_parameters,charging_sof_Error_Checks){
	//all cells reached their maximum chargeable voltage
	//disconnect the charger with the battery pack
	//charging is complete
}

void charging_fan_speed_Control(int temperature){
	//control fan pwm according to the temperature of the battery pack
}

void charging_sof_Calculate(charging_sof_Error_Checks){

	if(//input in normal range ){
			//continue}
	elseif(//input is higher or lower than than the normal range){
			//send error}
			// call fault handler function
}

void charging_cell_balancing(charging_parameters,charging_sof_Error_Checks){
	//read cell voltages
	//periodically - passively balance the cells
	//use shunt resistors
	if(//cell volatge >= threshold maximum chargeable voltage){
			//balance the cell;
}

