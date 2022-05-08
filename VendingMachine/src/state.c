
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

	switch(error_code)
	{
		case ERROR_NO_SEL:
			printk("ERROR: No product has been selected\n");
			error_code=0;
			break;
		case ERROR_NO_RET:
			printk("ERROR: There is no credit to be returned\n");
			error_code=0;
			break;
		case ERROR_NO_MONEY:
			printk("ERROR: There isn't enouph credit to make the purchase\n");
			error_code=0;
			break;
		default:
			printk("ERROR: Unknown Error\n");
			break;
	}

	return next_state;
}

int return_substate()
{
	int next_state=DISP_CREDIT;

	printk("RETURN: Returned %f euros to the user\n",money);
	money=0;

	return next_state;
}

int money_substate()
{
	int next_state=DISP_CREDIT;

	if(e10!=0)
	{
		printk("MONEY: Increased credit by 10 cents\n");
		money+=0.1;
	}
	else if(e20!=0)
	{
		printk("MONEY: Increased credit by 20 cents\n");
		money+=0.2;
	}
	else if(e50!=0)
	{
		printk("MONEY: Increased credit by 50 cents\n");
		money+=0.5;
	}
	else if(e100!=0)
	{
		printk("MONEY: Increased credit by 1 euro\n");
		money+=1.0;
	}

	return next_state;
}

int changeprod_substate()
{
	int next_state=BROWSE;

	if(up!=0)
	{
		printk("CHANGE_PROD: Next prod\n");
		product++;
	}
	else if(down!=0)
	{
		printk("CHANGE_PROD: Previous prod\n");
		product--;
	}

	return next_state;
}

int outprod_subtate()
{
	int next_state=DISP_CREDIT;

	switch(product%N_PROD)
	{
		case COFFEE:
			printk("OUT_PROD: Dispensed a Coffee\n");
			money-=0.5;
			break;
		case TUNA:
			printk("OUT_PROD: Dispensed a Tuna Sandwich\n");
			money-=1.0;
			break;
		case BEER:
			printk("OUT_PROD: Dispensed a Beer\n");
			money-=1.5;
			break;
	}

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