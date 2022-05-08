
/**
* \file state.h
* \brief State Machine Implementation
*
* This module implements the functions run the main state machine
* \author Filipe Loureiro & Miguel Silva
* \date 08/05/22
* \version 1.5
* \bug No bugs found
*/

#ifndef _STATE_H
#define _STATE_H

#include "button.h"
#include "gpio.h"

#define NO_STATE 0
#define BROWSE 1
#define CRED 2
#define ERROR 3
#define RETURN 4
#define MONEY 5
#define OUT_PROD 6
#define CHANGE_PROD 7

#define ERROR_NO_SEL 1
#define ERROR_NO_RET 2
#define ERROR_NO_MONEY 3 

#define COFFEE 0
#define TUNA 1
#define BEER 2
#define N_PROD 3

static int up=0;
static int down=0;
static int sel=0;
static int ret=0;
static int e10=0;
static int e20=0;
static int e50=0;
static int e100=0;

static int error_code=0;

static float money=0;
static int product=300;
const float prices={0.5,1.0,1.5}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Private Member Functions

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Public Member Function

int state_machine(int state);

#endif