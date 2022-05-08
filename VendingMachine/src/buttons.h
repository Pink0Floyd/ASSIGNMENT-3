/**
* \file gpio.h
* \brief Buttons functions
*
* This module implements the functions to initialize and use the built in board buttons
* \author Filipe Loureiro & Miguel Silva
* \date 26/04/22
* \version 1.1
* \bug Currently under tests, and continuous updating
*/

/* OBSERVATION:
* This module will suffer many updates due to the newness that this board brings to us
*/

#ifndef _BUTTONS_H
#define _BUTTONS_H

#include "base.h"

const int buttons_pin[4]={BUTTON1,BUTTON2,BUTTON3,BUTTON4,BUTTON5,BUTTON6,BUTTON7,BUTTON8};     // Buttons data with pins numbers             
const int buttons_pos[4]={1,2,4,8,16,32,64,128};						// Buttons data with corresponding position 

static struct gpio_callback but1_cb_data;                                     // Callback structure related to BUTTON 1
static struct gpio_callback but2_cb_data;                                     // Callback structure related to BUTTON 2
static struct gpio_callback but3_cb_data;                                     // Callback structure related to BUTTON 3
static struct gpio_callback but4_cb_data;                                     // Callback structure related to BUTTON 4
static struct gpio_callback but5_cb_data;                                     // Callback structure related to BUTTON 5
static struct gpio_callback but6_cb_data;                                     // Callback structure related to BUTTON 6
static struct gpio_callback but7_cb_data;                                     // Callback structure related to BUTTON 7
static struct gpio_callback but8_cb_data;                                     // Callback structure related to BUTTON 8

static int but1_flag = 0;                                                   // Callback variable, flag to signal a BUTTON 1 press
static int but2_flag = 0;                                                   // Callback variable, flag to signal a BUTTON 2 press 
static int but3_flag = 0;                                                   // Callback variable, flag to signal a BUTTON 3 press 
static int but4_flag = 0;                                                   // Callback variable, flag to signal a BUTTON 4 press 
static int but5_flag = 0;                                                   // Callback variable, flag to signal a BUTTON 5 press 
static int but6_flag = 0;                                                   // Callback variable, flag to signal a BUTTON 6 press 
static int but7_flag = 0;                                                   // Callback variable, flag to signal a BUTTON 7 press 
static int but8_flag = 0;                                                   // Callback variable, flag to signal a BUTTON 8 press 


///////////////////////////////////////////////////////////////////////////////////////
//  Public Functions:

/**
* \brief Built in Buttons initialization function without interrupts
*
* Initializes the board buttons by using a byte for these porpouse, button 1 match to byte=1, button 2 match to byte=2, ect
*
* \author Filipe Loureiro & Miguel Silva
* \param [IN] struct device *gpio0  -> the pointer for gpio0 struct
* \param [IN] char n_buttons        -> byte corresponding to the buttons to activate

* \date 25/04/22
* \bug Currently under tests, and continuous updating
*/
void buttons_init(struct device *gpio0_dev, char n_buttons);


/**
* \brief Built in Buttons initialization function with interrupts
*
* Initializes the board buttons by using a byte for these porpouse, button 1 match to byte=1, button 2 match to byte=2, ect
*
* \author Filipe Loureiro & Miguel Silva
* \param [IN] struct device *gpio0  -> the pointer for gpio0 struct
* \param [IN] char n_buttons        -> byte corresponding to the buttons to activate
* \param [IN] char c                -> 'H' or 'h' to interrupt at rising edge
                                    -> 'L' or 'l' to interrupt at falling edge
                                    -> 'B' or 'b' to interrupt at both edges
* \date 25/04/22
* \bug Currently under tests, and continuous updating
*/
void buttons_init_(struct device *gpio0_dev, char n_buttons, char c);

int read_button1();
int read_button2();
int read_button3();
int read_button4();
int read_button5();
int read_button6();
int read_button7();
int read_button8();

///////////////////////////////////////////////////////////////////////////////////////
//  Private Functions:

void buttons_callback_init(struct device *gpio0_dev,char n_buttons);
void reset_flags();

#endif