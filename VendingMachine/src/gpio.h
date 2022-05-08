/**
* \file gpio.h
* \brief GPIO functions
*
* This module implements the functions to initialize and do some gpio configuration
* \author Filipe Loureiro & Miguel Silva
* \date 25/04/22
* \version 0.1
* \bug Currently under tests, and continuous updating
*/

/* OBSERVATION:
* This module will suffer many updates due to the newness that this board brings to us
*/


#ifndef _GPIO_H
#define _GPIO_H

#include "base.h"

///////////////////////////////////////////////////////////////////////////////////////
//  Public Functions:

/**
* \brief GPIO 0 initialization function
*
* Initializes the GPIO 0 in order to use it pins
*
* \author Filipe Loureiro & Miguel Silva
* \return Return a pointer to a device struct type
* \date 25/04/22
* \bug Currently under tests, and continuous updating
*/

struct device *gpio0_init();

/**
* \brief GPIO 1 initialization function
*
* Initializes the GPIO 1 in order to use it pins
*
* \author Filipe Loureiro & Miguel Silva
* \return Return a pointer to a struct of device type
* \date 25/04/22
* \bug Currently under tests, and continuous updating
*/
struct device *gpio1_init();

///////////////////////////////////////////////////////////////////////////////////////
//  Private Functions:

#endif