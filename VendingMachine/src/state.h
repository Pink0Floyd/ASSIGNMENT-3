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
#define CREDIT 2
#define ERROR 3
#define RETURN_CREDIT 4
#define CHANGE_CREDIT 5
#define RETURN_PRODUCT 6
#define CHANGE_PRODUCT 7

#define ERROR_NO_RET 2
#define ERROR_NO_MONEY 3 

#define COFFEE 0
#define TUNA 1
#define BEER 2
#define N_PROD 3

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Private Member Functions

//void read_events();
//void credit_state_action(int money_amount);
//int credit_state_exit();
//int credit_state();
//void browse_state_action(int product_selected);
//int browse_state_exit();
//int browse_state();
//int error_substate();
//int change_credit_substate();
//int return_credit_substate();
//int change_product_substate();
//int return_product_subtate();

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Public Member Function

/**
*\brief State Machine Function
*
* Runs all the internal states of the state machine
*
*\param [IN] current state
*\return next state
*\date 25/04/22
*\bug No bugs detected
*/
int state_machine(int state);

#endif