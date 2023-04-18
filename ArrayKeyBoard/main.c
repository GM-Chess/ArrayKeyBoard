/*
 * main.c
 *
 *  Created on: 2023 Apr 02 20:03:16
 *  Author: curti
 */



#include <XMC4500.h>
#include "DAVE.h"                 //Declarations from DAVE Code Generation (includes SFR declaration)
#include "GPIO.h"
/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */
// board gets started with the use of GPIO.h
/*Mapping:
 8x pins of Keypad - MCU mapped
 R1 -> P1_1
 R2 -> P1_3
 R3 -> P1_5
 R4 -> P1_7
 C1 -> P1_8
 C2 -> P1_2
 C3 -> P1_4
 C4 -> P1_6
 ******************************************************************************
 */



long int delay(long int n){
	int i,j;
	for (i = 0; i < n; i++){
		for (j = 0; j<7500; j++){

		}
	}
}






int main(void)
{
  DAVE_STATUS_t status;

  status = DAVE_Init();           /* Initialization of DAVE APPs  */

  if (status != DAVE_STATUS_SUCCESS)
  {
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialization failed\n");

    while(1U)
    {

    }
  }
	// intialize leds
	P1_0_set_mode(OUTPUT_PP_GP);
	P1_0_set_driver_strength(STRONG);
	P1_1_set_mode(OUTPUT_PP_GP);
	P1_1_set_driver_strength(STRONG);

	// initialize button
	P1_14_set_mode(INPUT);

	// create matrix for the membrane pad pins (1.0 -- 1.8)
	P0_1_set_mode(INPUT_INV_PD);  //zero and even are the columns and set to HIGH or ON
	P0_1_set_driver_strength(STRONG);
	P15_2_set_mode(INPUT_INV_PD);
	P15_2_enable_digital();
	P3_1_set_mode(INPUT_INV_PD);
	P3_1_set_driver_strength(STRONG);
	P3_2_set_mode(INPUT_INV_PD);
	P3_2_set_driver_strength(STRONG);

	P0_9_set_mode(INPUT_PU); // Odd pins are set the rows and are set to LOW or OFF
	P0_9_set_driver_strength(STRONG);
	P14_15_set_mode(INPUT_PU);
	P14_15_enable_digital();
	P0_10_set_mode(INPUT_PU);
	P0_10_set_driver_strength(STRONG);
	P0_0_set_mode(INPUT_PU);
	P0_0_set_driver_strength(STRONG);




  if(SysTick_Config(SystemCoreClock / 100UL) == 0){


  		for(;;) {

  		}
  	}
  	else{
  		asm("BKPT 255");
  	}

}

void SysTick_Handler(void) {
	static uint32_t ticks = 0UL;
	//Create variables for the ARRAY Button pad//

	ticks++;

	if(P0_1_read() == 0UL | P3_2_read() == 0UL | P3_1_read() == 0UL | P15_2_read() == 0UL ){
		P1_0_toggle();
		delay(10000);
		P1_0_toggle();

	}




}

