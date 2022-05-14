/**
* \file state.h
* \brief State Machine Implementation
*
* This module implements the functions run the main state machine
* \author Filipe Loureiro & Miguel Silva
* \date 14/05/22
* \version 1.8
* \bug No bugs found
*/

#ifndef _STATE_H
#define _STATE_H

#include "base.h"
#include "buttons.h"
#include "gpio.h"

#define NO_STATE 0
#define BROWSE 1
#define CRED 2
#define ERROR 3
#define RETURN 4
#define MONEY 5
#define OUT_PROD 6
#define CHANGE_PROD 7

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

static int money=0;
static int product=0;
const static double prices[3]={50,100,150};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Private Member Functions

//void read_events();
//int cred_state();
//int browse_state();
//int error_substate();
//int return_substate();
//int money_substate();
//int changeprod_substate();
//int outprod_subtate();

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Public Member Function

/**
* \brief State Machine Function
*
* Runs all the internal states of the state machine
*
* \param [IN] state		    -> Initial State
*
* \date 25/04/22
* \bug No bugs detected
*/
int state_machine(int state);

#endif