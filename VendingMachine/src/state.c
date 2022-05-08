
#include "state.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Private Member Functions

int up_subevent()
{
	
}

int down_subevent()
{
	
}

int EUD_event()
{
	
}

int sel_event()
{
	
}

int ret_event()
{
	
}

int e10_subevent()
{

}

int e20_subevent()
{

}

int e50_subevent()
{

}

int e100_subevent()
{

}

int EX_event()
{
	
}

int credit_state()
{
	int next_state=0;
	
	while(1)
	{
		if(
	}

	return next_state;
}

int browse_state()
{
	int next_state=0;

	return next_state;
}

int printerror_substate()
{
	int next_state=CREDIT;

	return next_state;
}

int return_substate()
{
	int next_state=DISPLAY_CREDIT;

	return next_state;
}

int displaycredit_substate()
{
	int next_state=CREDIT;

	return next_state;
}

int money_substate()
{
	int next_state=DISPLAY_CREDIT;

	return next_state;
}

int displayprod_substate()
{
	int next_state=BROWSE;

	return next_state;
}

int outprod_subtate()
{
	int next_state=DISPLAY_CREDIT;

	return next_state;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Public Member Function

int state_machine(int state)
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
		default:
			printk("STATE NOT FOUND\n");
			break;
	}
}