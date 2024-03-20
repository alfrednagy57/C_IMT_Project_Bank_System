#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include "../Headers/STD_TYPES.h"
#include "../Headers/BankAcc.h"
#include "../Headers/MainWin.h"


#define AUTHOR "ALFRED_NAGY"

int main()
{           
	system("cls");
	
			printf("\033[1;31mMADE BY %s \033[0m\n",AUTHOR);
			printf("Admin username : %s \n",Admin_User);
			printf("Admin password : %d \n\n\n",Admin_Pass);
            printf("\t\t\t\t\033[1;35mWelcome to IMT Bank System!\033[0m\n\n");
			
	static u8 State=' ';		
			
	sleep(5);

	do
	{
		
		MainWin();
		
		printf("if you want to display all accounts enter 1 : ");
		scanf(" %c",&State);
		
		if (State==1)
		{			
			DisplayAll();
			sleep(20);
		}
		
		system("cls");
		printf("if you want to exit press e : ");
		scanf(" %c",&State);
		
	}while(State!='E'&&State!='e');
	return 0;
}