
#include "base.h"
#include "gpio.h"
#include "buttons.h"
#include "state.h"

#define INITIAL_STATE 2

void main()
{
	printk("\n\n\n\n\n\nStart\n");
	const struct device *gpio0_dev;
      gpio0_dev=gpio0_init();
      printk("End of gpio0 initialization\n\r");              // Debbug line
  
      buttons_init_(gpio0_dev,255,'h');
      printk("The Buttons are Active\n\r");
	int state=INITIAL_STATE;
	
	while(state!=0)
	{
		state=state_machine(state);
	}
	state=state_machine(state);  
}
