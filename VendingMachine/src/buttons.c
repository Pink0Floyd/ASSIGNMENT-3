#include "buttons.h"

void buttons_init(struct device *gpio0_dev, char n_buttons)                                     // Initialize the board's buttons  
{
  int i=0;
  int ret=0;

  for(i=0; i<4; i++)
  {
    //printk("%d\n\r",buttons_pos[i]);
    if((n_buttons & buttons_pos[i]) == buttons_pos[i])
    {
      ret = gpio_pin_configure(gpio0_dev, buttons_pin[i], GPIO_INPUT | GPIO_PULL_UP);
      if (ret < 0) 
      {
        printk("Error %d: Failed to configure Button %d \n\r", ret, (i+1));
	return;
      }
    }
  }
}


void buttons_init_(struct device *gpio0_dev, char n_buttons, char c)
{
  buttons_init(gpio0_dev,n_buttons);
  int ret=0;
  int i=0;
    
  if((c=='H') || (c='h'))                                                                           // Rising edge interrupt configuration
  {
    for(i=0; i<4; i++)
    {
      printk("%d\n\r",buttons_pos[i]);
      if((n_buttons & buttons_pos[i]) == buttons_pos[i])
      {
        ret=gpio_pin_interrupt_configure(gpio0_dev, buttons_pin[i], GPIO_INT_EDGE_TO_ACTIVE);         // Button rising edge interrupt configuration 
        if (ret < 0)                                                                                  // In case of fail initialization and consequent error message
        { 
          printk("Error %d: failed to configure interrupt on BUTTON %d pin \n\r", ret, (i+1));
          return;
        }
      }
    }
  }
  else if((c=='L') || (c='l'))                                                                        // Falling edge interrupt configuration
  {
    for(i=0; i<4; i++)
    {
      //printk("%d\n\r",buttons_pos[i]);
      if((n_buttons & buttons_pos[i]) == buttons_pos[i])
      {
        ret=gpio_pin_interrupt_configure(gpio0_dev, buttons_pin[i], GPIO_INT_EDGE_TO_INACTIVE);       // Button falling edge interrupt configuration 
        if (ret < 0)                                                                                  // In case of fail initialization and consequent error message
        { 
          printk("Error %d: failed to configure interrupt on BUTTON %d pin \n\r", ret, (i+1));
          return;
        }
      }
    }
  }
  else if((c=='B') || (c='b'))                                                                        // Rising and falling edge interrupt configuration
  {
    for(i=0; i<4; i++)
    {
      //printk("%d\n\r",buttons_pos[i]);
      if((n_buttons & buttons_pos[i]) == buttons_pos[i])
      {
        ret=gpio_pin_interrupt_configure(gpio0_dev, buttons_pin[i], GPIO_INT_EDGE_BOTH);              // Button rising and fallinf edge interrupt configuration 
        if (ret < 0)                                                                                  // In case of fail initialization and consequent error message
        { 
          printk("Error %d: failed to configure interrupt on BUTTON %d pin \n\r", ret, (i+1));
          return;
        }
      }
    }
  }

}


// Several Buttons Callbacks, that are necessary for good interrupt use
/*
    // Set Button 1 callback 
    gpio_init_callback(&but1_cb_data, but1_cbfunction, BIT(BUTTON1));
    gpio_add_callback(gpio0_dev, &but1_cb_data);

    void but1_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
    {
      printk("Button 1 pressed\n\r");                                                               // Inform that button was hit
      but1_Flag = 1;                                                                                // Update Flag                                           
    } 
    

    // Set Button 2 callback 
    gpio_init_callback(&but2_cb_data, but2_cbfunction, BIT(BUTTON2));
    gpio_add_callback(gpio0_dev, &but2_cb_data);

    void but2_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
    {
      printk("Button 2 pressed\n\r");                                                               // Inform that button was hit
      but2_Flag = 1;                                                                                // Update Flag 
    } 


    // Set Button 3 callback 
    gpio_init_callback(&but3_cb_data, but3_cbfunction, BIT(BUTTON3));
    gpio_add_callback(gpio0_dev, &but3_cb_data);

    void but3_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
    {
      printk("Button 3 pressed\n\r");                                                               // Inform that button was hit
      but3_Flag = 1;                                                                                // Update Flag 
    } 


    // Set Button 4 callback 
    gpio_init_callback(&but4_cb_data, but4_cbfunction, BIT(BUTTON4));
    gpio_add_callback(gpio0_dev, &but4_cb_data);

    void but4_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
    {
      printk("Button 4 pressed\n\r");                                                               // Inform that button was hit
      but4_Flag = 1;                                                                                // Update Flag 
    } 
 
 */
  
void button1_init(struct device *gpio0_dev)                                                         // Button 1                 
{
  int ret=0;

  ret=gpio_pin_configure(gpio0_dev, BUTTON1, GPIO_INPUT | GPIO_PULL_UP);                            // Button pin configuration as input and internal pull-up resistor
  if (ret < 0)                                                                                      // In case of fail initialization and consequent error message
  {
    printk("Error %d: Failed to configure BUTTON 1 \n\r", ret);
    return;
  }
}


void button2_init(struct device *gpio0_dev)                                                         // Button 2
{
  int ret=0;

  ret=gpio_pin_configure(gpio0_dev, BUTTON2, GPIO_INPUT | GPIO_PULL_UP);                            // Button pin configuration as input and internal pull-up resistor
  if (ret < 0)                                                                                      // In case of fail initialization and consequent error message
  {
    printk("Error %d: Failed to configure BUTTON 2 \n\r", ret);
    return;
  }
}


void button3_init(struct device *gpio0_dev)                                                         // Button 3
{
  int ret=0;

  ret=gpio_pin_configure(gpio0_dev, BUTTON3, GPIO_INPUT | GPIO_PULL_UP);                            // Button pin configuration as input and internal pull-up resistor
  if (ret < 0)                                                                                      // In case of fail initialization and consequent error message
  {
    printk("Error %d: Failed to configure BUTTON 3 \n\r", ret);
    return;
  }
}


void button4_init(struct device *gpio0_dev)                                                         // Button 4
{
  int ret=0;

  ret=gpio_pin_configure(gpio0_dev, BUTTON4, GPIO_INPUT | GPIO_PULL_UP);                            // Button pin configuration as input and internal pull-up resistor
  if (ret < 0)                                                                                      // In case of fail initialization and consequent error message
  {
    printk("Error %d: Failed to configure BUTTON 4 \n\r", ret);
    return;
  }
}