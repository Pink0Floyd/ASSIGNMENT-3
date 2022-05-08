
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

int cred_state()
{
	int next_state=NO_STATE;
	
	while(next_state==NO_STATE)
	{
		read_events();
		if(up+down!=0)
		{
			next_state=DISP_PROD;
		}
		else if(sel!=0)
		{
			next_state=ERROR;
			error_code=ERROR_NO_SEL;
		}
		else if(ret!=0)
		{
			if(money==0)
			{
				next_state=ERROR;
				error_code=ERROR_NO_RET;
			}
			else
			{
				next_state=RETURN;
			}
		}
		else if(e10+e20+e50+e100)!=0)
		{
			next_state=MONEY;
		}
		else
		{
			next_state=NO_STATE;
		}
	}

	return next_state;
}

int browse_state()
{
	int next_state=NO_STATE;
	float cost=0;

	while(next_state==NO_STATE)
	{
		read_events();
		if(up+down!=0)
		{
			next_state=CHANGE_PROD;
		}
		else if(sel!=0)
		{
			if(money>=prices[product%N_PROD])
			{
				next_state=OUT_PROD;
			}
			else
			{
				next_state=ERROR;
				error_code=ERROR_NO_MONEY;
			}
		}
		else if(ret!=0)
		{
			if(money==0)
			{
				next_state=ERROR;
				error_code=ERROR_NO_RET;
			}
			else
			{
				next_state=RETURN;
			}
		}
		else if(e10+e20+e50+e100!=0)
		{
			next_state=MONEY;
		}
		else
		{
			next_state=NO_STATE;
		}
	}

	return next_state;
}

int error_substate()
{
	int next_state=CREDIT;

	return next_state;
}

int return_substate()
{
	int next_state=DISP_CREDIT;

	return next_state;
}

int money_substate()
{
	int next_state=DISP_CREDIT;

	return next_state;
}

int changeprod_substate()
{
	int next_state=BROWSE;

	return next_state;
}

int outprod_subtate()
{
	int next_state=DISP_CREDIT;

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