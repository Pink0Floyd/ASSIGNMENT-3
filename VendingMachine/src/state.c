
#include "state.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Private Member Functions

int credit_state()
{
	int next_state=0;

	return next_state;
}

int browse_state()
{
	int next_state=0;

	return next_state;
}

int printerror_substate()
{
	int next_state=0;

	return next_state;
}

int return_substate()
{
	int next_state=0;

	return next_state;
}

int displaycredit_substate()
{
	int next_state=0;

	return next_state;
}

int money_substate()
{
	int next_state=0;

	return next_state;
}

int displayprod_substate()
{
	int next_state=0;

	return next_state;
}

int outprod_subtate()
{
	int next_state=0;

	return next_state;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Public Member Function

void state_machine(int state)
{
	switch(state)
	{
		case CREDIT:
			credit_state();
			break;
		case BROWSE:
			browse_state();
			break;
		case PRINT_ERROR:
			printerror_substate();
			break;
		case RETURN:
			return_substate();
			break;
		case DISPLAY_CREDIT:
			displaycredit_substate();
			break;
		case MONEY:
			money_substate();
			break;
		case DISPLAY_PROD:
			displayprod_substate();
			break;
		case OUT_PROD:
			outprod_substate();
			break;
	}
}