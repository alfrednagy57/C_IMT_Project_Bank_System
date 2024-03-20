#include<stdio.h>
#include<stdlib.h>


#include "../Headers/STD_TYPES.h"
#include "../Headers/MainWin.h"
#include "../Headers/Fncs.h"

//Main Window
void MainWin()
{
	system("cls");
	printf("Please Choose from the Following List:\n1.Admin Window. \n2.Client Window.\n3.To Exit System.\n\n\nWhat is your desicion : ");
	
	u8 Choices= ' ';
	
	scanf(" %c",&Choices);
	
	switch (Choices)
	{
		case '1':
		
		Admin_Window();
		
		break;
		
		case '2':
		
		Client_Window();
		
		break;
		
		case '3': 
		
		/*nothing*/
		
		break;
		
		default:
		
		printf("Invalid choice you will be directed to main window again");
		MainWin();
		
		break;
		
	}
}