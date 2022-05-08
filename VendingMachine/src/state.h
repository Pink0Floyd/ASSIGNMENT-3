
/**
* \file state.h
* \brief State Machine Implementation
*
* This module implements the functions run the main state machine
* \author Filipe Loureiro & Miguel Silva
* \date 08/05/22
* \version 1.3
* \bug No bugs found
*/

#ifndef _STATE_H
#define _STATE_H

#include "button.h"
#include "gpio.h"

#define BROWSE 1
#define CREDIT 2
#define PRINT_ERROR 3
#define RETURN 4
#define DISPLAY_CREDIT 5
#define MONEY 6
#define OUT_PRODUCT 7
#define DISPLAY_PRODUCT 8

static int up=0;
static int down=0;
static int sel=0;
static int ret=0;
static int e10=0;
static int e20=0;
static int e50=0;
static int e100=0;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Private Member Functions

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Public Member Function

int state_machine(int state);

#endif