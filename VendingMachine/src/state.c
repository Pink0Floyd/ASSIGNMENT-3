
#include "state.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Private Member Functions

void read_events()
{
	up=read_button1();
	down=read_button3();
	sel=read_button2();
	ret=read_button4();
	e10=read_button5();
	e20=read_button6();
	e50=read_button7();
	e100=read_button8();
}

int credit_state()
{
	int next_state=0;
	
	while(1)
	{
		if(SEL_event()==1)
		{
			next_state=PRINT_ERROR;
		}

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