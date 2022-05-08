
#include "base.h"
#include "gpio.h"
#include "buttons.h"


void main()
{
	printk("Main");
	printk("\n\n\n\r");
        const struct device *gpio0_dev;
        gpio0_dev=gpio0_init();
        printk("End of gpio0 initialization\n\r");              // Debbug line
  
        buttons_init_(gpio0_dev,15,'h');
        printk("The Buttons are Active\n\r");
        while(1)
        {
            if(read_button1()==1)
            {
		  printk("LED 1 Pressed\n\r");
            }
	    if(read_button2()==1)
            {
		  printk("LED 2 Pressed\n\r");
            }
	    if(read_button3()==1)
            {
		  printk("LED 3 Pressed\n\r");
            }
	    if(read_button4()==1)
            {
		  printk("LED 4 Pressed\n\r");
            }
        }       
}
