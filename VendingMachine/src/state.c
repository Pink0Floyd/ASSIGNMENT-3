
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
	printk("CRED: %f credit available\n",money);

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
	switch(product%N_PROD)
	{
		case COFFEE:
			printk("BROWSE: Selected a Coffee\n");
			break;
		case TUNA:
			printk("BROWSE: Selected a Tuna Sandwich\n");
			break;
		case BEER:
			printk("BROWSE: Selected a Beer\n");
			break;
		default:
			printk("BROWSE: Selected an Unknown Product\n");
			break;
	}

	int next_state=NO_STATE;
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

	return CRED;
}

int return_substate()
{
	printk("RETURN: Returned %f euros to the user\n",money);
	money=0;

	return CRED;
}

int money_substate()
{
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

	return CRED;
}

int changeprod_substate()
{
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

	return BROWSE;
}

int outprod_subtate()
{
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

	return CRED;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Public Member Function

int state_machine(int state)
{
	int next_state=NO_STATE;
	switch(state)
	{
		case CREDIT:
			next_state=credit_state();
			break;
		case BROWSE:
			next_state=browse_state();
			break;
		case PRINT_ERROR:
			next_state=printerror_substate();
			break;
		case RETURN:
			next_state=return_substate();
			break;
		case MONEY:
			next_state=money_substate();
			break;
		case DISPLAY_PROD:
			next_state=displayprod_substate();
			break;
		case OUT_PROD:
			next_state=outprod_substate();
			break;	
		default:
			printk("Unknown State\n");
			break;
	}
}