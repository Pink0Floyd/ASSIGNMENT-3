#include "state.h"

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

void read_events()
{
	up=read_buttons(1);
	down=read_buttons(3);
	sel=read_buttons(2);
	ret=read_buttons(4);
	e10=read_buttons(5);
	e20=read_buttons(6);
	e50=read_buttons(7);
	e100=read_buttons(8);
	//k_msleep(10);
}

void cred_state_action()
{
	printk("CRED: %i cents creditted\n",money);
}

int cred_state_exit()
{
	int next_state=CRED;
	read_events();
	if((up+down)!=0)
	{
		next_state=CHANGE_PROD;
	}
	else if(sel!=0)
	{
		next_state=BROWSE;
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
	else if((e10+e20+e50+e100)!=0)
	{
		next_state=MONEY;
	}
}

int cred_state()
{
	cred_state_action();

	int next_state=CRED;
	while(next_state=CRED)
	{
		next_state=cred_state_exit()
	}
	return next_state;
}

void browse_state_action()
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
}

int browse_state_exit()
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
}

int browse_state()
{
	int next_state=BROWSE;
	while(next_state==BROWSE)
	{
		next_state=browse_state_exit();
	}
	return next_state;
}

int error_substate()
{
	switch(error_code)
	{
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
	printk("RETURN: Returned %i cents to the user\n",money);
	money=0;

	return CRED;
}

int money_substate()
{
	if(e10!=0)
	{
		printk("MONEY: Increased credit by 10 cents\n");
		money+=10;
	}
	else if(e20!=0)
	{
		printk("MONEY: Increased credit by 20 cents\n");
		money+=20;
	}
	else if(e50!=0)
	{
		printk("MONEY: Increased credit by 50 cents\n");
		money+=50;
	}
	else if(e100!=0)
	{
		printk("MONEY: Increased credit by 1 euro\n");
		money+=100;
	}

	return CRED;
}

int changeprod_substate()
{
	if(up!=0)
	{
		printk("CHANGE_PROD: Next prod\n");
		if(product==2)
		{
			product=0;
		}
		else
		{
			product++;
		}
	}
	else if(down!=0)
	{
		printk("CHANGE_PROD: Previous prod\n");
		if(product==0)
		{
			product=2;
		}
		else
		{
			product--;
		}
	}

	return BROWSE;
}

int outprod_substate()
{
	switch(product%N_PROD)
	{
		case COFFEE:
			printk("OUT_PROD: Dispensed a Coffee\n");
			money-=50;
			break;
		case TUNA:
			printk("OUT_PROD: Dispensed a Tuna Sandwich\n");
			money-=100;
			break;
		case BEER:
			printk("OUT_PROD: Dispensed a Beer\n");
			money-=150;
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
		case CRED:
			next_state=cred_state();
			break;
		case BROWSE:
			next_state=browse_state();
			break;
		case ERROR:
			next_state=error_substate();
			break;
		case RETURN:
			next_state=return_substate();
			break;
		case MONEY:
			next_state=money_substate();
			break;
		case CHANGE_PROD:
			next_state=changeprod_substate();
			break;
		case OUT_PROD:
			next_state=outprod_substate();
			break;	
		default:
			printk("Unknown State\n");
			break;
	}
}