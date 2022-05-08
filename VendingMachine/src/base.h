/*  
* \file base.h
* \brief This file contain the basic includes and variables for general porpouse
*
* \author Filipe Loureiro & Miguel Silva
* \date 08/05/22
* \version 1.0
* \bug Currently under tests, and continuous updating
*/

#ifndef _BASE_H
#define _BASE_H

#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>
#include <sys/printk.h>
#include <sys/__assert.h>
#include <string.h>
#include <timing/timing.h>
#include <stdio.h>
#include <stdint.h>

#define LED1 13                                             // LED1 pin number of GPIO_0
#define LED2 14                                             // LED2 pin number of GPIO_0
#define LED3 15                                             // LED3 pin number of GPIO_0
#define LED4 16                                             // LED4 pin number of GPIO_0

#define BUTTON1 11                                          // BUTTON1 pin number of GPIO_0
#define BUTTON2 12                                          // BUTTON2 pin number of GPIO_0
#define BUTTON3 24                                          // BUTTON3 pin number of GPIO_0
#define BUTTON4 25                                          // BUTTON4 pin number of GPIO_0

#endif