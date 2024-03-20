#include "../Headers/STD_TYPES.h"
#include "../Headers/BankAcc.h"
#include "../Headers/Fncs.h"
#include "../Headers/MainWin.h"

#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define max 1999999
#define min 1000000

Acc_Young* Head_Young=NULL;
Acc_Old* Head_Old=NULL;

u32 CountAcc=0;

void DisplayAll()
{
	
	
	Acc_Young* temp =Head_Young;
	while(temp!=NULL)
	{
		printf("\n\nYoung : \n");
		printf("%s, %s ,%s ,%d ,%c ,%lu ,%lu,",temp->FullName,temp->FullAdd,temp->Guardian,temp->Age,temp->AccountStatus,temp->BankAccID,temp->Password);
		printf(" %llu ,%llu, %llu\n",temp->NationalID,temp->GuardianNationalID,temp->Balance);
		temp=temp->Next;
	}
	
	
	Acc_Old* temp2 =Head_Old;
	
	while(temp2!=NULL)
	{
		printf("\nOld : \n");
		printf("%s ,%s ,%d ,%c ,%lu ,%lu,",temp2->FullName,temp2->FullAdd,temp2->Age,temp2->AccountStatus,temp2->BankAccID,temp2->Password);
		printf(" %llu ,%llu\n",temp2->NationalID,temp2->Balance);
		temp2=temp2->Next;
	}
	printf("\n\n");
}

//Admin Window
u32 Admin_Window()
{	
	system("cls");
	u32 pass;	
	u8  name[50];
	u8 trials=1;
	
	printf("Admin username : %s \n",Admin_User);
	printf("Admin password : %d \n\n\n",Admin_Pass);
	
	printf("Enter username : ");
	scanf(" %[^\n\t]s",&name);
	printf("Enter password : ");
	scanf(" %d",&pass);
	while((strcmp(name,Admin_User)!=0||pass!= Admin_Pass))
	{
		printf("\n\nRE-Enter username : ");
		scanf(" %[^\n\t]s",&name);
		printf("\nRe-Enter password : ");
		scanf(" %d",&pass);
		trials++;
		if(trials==3) break;
	}
	
	if (trials==3) 
	{
		printf("Invalid Admin data for 3 trials\nThe program will close\n");
		return FALSE;
	}
	
	choice();
	
	return TRUE;
	
}

void choice()
{
	system("cls");
	
	static u8 State2;
	do 
	{
		printf("Welcome admin %s \n\n",Admin_User);
		printf("1.To create an account\n");
		printf("2.To open an existing account\n");
		printf("3.Exit system\n");
		printf("\n\nWhat is your desicion : ");
		scanf(" %c",&State2);
		
		switch(State2)
		{
			case '1':
			
			CreateNewAcc();
			
			break;
			
			
			case '2':
			
			OpenExistingAcc();
			
			break;
			
			
			case '3':
			
			MainWin();
			
			break;
			
			default:
				choice();
			break;
		}
	}while(State2!='3');
}
void CreateNewAcc()
{
	system("cls");
	
	u8   Age2;//age 
	
	printf("Enter your Age : ");
	scanf(" %d",&Age2);
	
	
	if(Age2<1||Age2>80)
	{
		printf("Invalid Age!\nCan not open any accounts\n\nAge [1,80]\n");
		sleep(5);
	}
	else if(Age2<21)
	{
		Acc_Young *NewAcc=(Acc_Young *)malloc(sizeof(Acc_Young));
		
		printf("Enter your Full Name : ");
		scanf(" %[^\n\t]s",&(NewAcc->FullName));
	
	
		printf("Enter your Full Address : ");
		scanf(" %[^\n\t]s",&(NewAcc->FullAdd));

		(NewAcc->Age)=(u8)Age2;
		
		(NewAcc->AccountStatus)='a';
		
		(NewAcc->BankAccID)=BaseId+CountAcc;
		
		srand(time(NULL));

		(NewAcc->Password)=rand()%(max-min+1)+min;
		printf("Enter your Guardian Full Name : ");
		scanf(" %[^\n\t]s",&(NewAcc->Guardian));
		
		printf("Enter your Guardian National ID : ");
		scanf("%llu",&(NewAcc->GuardianNationalID));
		
		printf("Enter your National ID : ");
		scanf("%llu",&(NewAcc->NationalID));
	
		printf("Enter your the amout you will deposit : ");
		scanf("%llu",&(NewAcc->Balance));
		
		if(Head_Young==NULL)
		{
			Head_Young=	NewAcc;
		}
		else 
		{
			Acc_Young* temp=Head_Young;
			while(temp->Next!=NULL)
			{
				temp=temp->Next;
			}
			
			temp->Next=NewAcc;
		}
		NewAcc->Next=NULL;
		CountAcc++;
	}
	else 
	{

		Acc_Old *NewAcc=(Acc_Old *)malloc(sizeof(Acc_Old));
		
		printf("Enter your Full Name : ");
		scanf(" %[^\n\t]s",&(NewAcc->FullName));
	
	
		printf("Enter your Full Address : ");
		scanf(" %[^\n\t]s",&(NewAcc->FullAdd));
		
		(NewAcc->Age)=(u8)Age2;
		
		printf("Enter your National ID : ");
		scanf("%llu",&(NewAcc->NationalID));
	
		printf("Enter your the amout you will deposit : ");
		scanf("%llu",&(NewAcc->Balance));
		
		(NewAcc->AccountStatus)='a';
		
		(NewAcc->BankAccID)=BaseId+CountAcc;
		
		srand(time(NULL));

		(NewAcc->Password)=rand()%(max-min+1)+min;
				
		if(Head_Old==NULL)
		{
			Head_Old=NewAcc;
		}
		else 
		{
			Acc_Old* temp=Head_Old;
			while(temp->Next!=NULL)
			{
				temp=temp->Next;
			}
			temp->Next=NewAcc;
		}
		(NewAcc->Next)=NULL;
		CountAcc++;
	}
}

u8 OpenExistingAcc()
{
	system("cls");
	
	u64  BankAccID;
	u64  Password;
	u8   Age;
	u8   trials=0;
	printf(" Base id is : %d \n" ,BaseId);
	printf("Enter the bank account ID you want to open : ");
	scanf("%lu",&BankAccID);
	
	printf("Enter Password : ");
	scanf("%lu",&Password);
	
	printf("Enter your age : ");
	scanf("%lu",&Age);
	
	if(Age>80||Age<1)
	{
		printf("Invalid age range\n");
		OpenExistingAcc();
	}
	else if(Age<21)
	{
		Acc_Young* temp=Head_Young;
		
		while(temp!=NULL&&(temp->BankAccID!=BankAccID))
		{
			temp=temp->Next;
		}
		
		if(temp==NULL)
		{
			printf("No account with this id exists\n");
			return FALSE;
		}
		printf("Hint pass %lu\n\n",(temp->Password));

		while((temp->Password)!=Password && trials <3)
		{
			printf("Re enter your Password : ");
			scanf("%lu",&Password);
			trials++;
		}
		
		if(trials==3)
		{
			printf("You enter a wrong password for 3 times\nAccess denied\n");
			return FALSE;
		}
		printf("1.Make Transaction\n");
		printf("2.Change Account Status\n");
		printf("3.Get Cash\n");
		printf("4.Deposit in Account\n");
		printf("5.Return to main Menu\n\n\n");
		printf("\n\nWhat is your desicion : ");
		
		u128 money;
		
		scanf(" %c",&trials);
		
		system("cls");
		
		switch(trials)
		{
			case '1':
			
			printf("Enter age of the account owner you want to send money to : ");
			scanf("%lu",&Age);
			if(Age>80||Age<1)
			{
				printf("Invalid age range\n");
				OpenExistingAcc();
			}
			else if(Age<21)
			{
				Acc_Young* tempto=Head_Young;
				printf("Enter the bank account ID you want to send money to : ");
				scanf("%lu",&BankAccID);
				while(tempto!=NULL&&((tempto->BankAccID)!=BankAccID))
				{
					tempto=tempto->Next;
				}
				
				if(tempto==NULL)
				{
					printf("No account with this id exists\n");
					return FALSE;
				}
				u128 money;
				
				printf("Enter the money you want to send\n");
				scanf("%llu",&money);
				
				if(((temp->Balance)>=money)&&money>0)
				{
					(temp->Balance)-=money;
					(tempto->Balance)+=money;
					printf("sussecful operatiion\n");
					printf("your remaining balance is %llu\n",temp->Balance);
				}
				else 
				{
					printf("Un suffiecient balance in your account\n");
					printf("your balance is %llu\n",temp->Balance);
				}
			}
			else
			{
				
				Acc_Old* tempto=Head_Old;
				printf("Enter the bank account ID you want to send money to : ");
				scanf("%lu",&BankAccID);
				while(tempto!=NULL&&((tempto->BankAccID)!=BankAccID))
				{
					tempto=tempto->Next;
				}
				
				if(tempto==NULL)
				{
					printf("No account with this id exists\n");
					return FALSE;
				}
				u128 money;
				
				printf("Enter the money you want to send\n");
				scanf("%llu",&money);
				
				if(((temp->Balance)>=money)&&money>0)
				{
					(temp->Balance)-=money;
					(tempto->Balance)+=money;
					printf("sussecful operatiion\n");
					printf("your remaining balance is %llu\n",temp->Balance);
				}
				else 
				{
					printf("Un suffiecient balance in your account\n");
					printf("your balance is %llu\n",temp->Balance);
				}
				
			}
			
			break;
			
			case '2':
			
			printf("Enter the new status : ");
			scanf(" %c",&(temp->AccountStatus));
			if((temp->AccountStatus)=='c'||(temp->AccountStatus)=='C')
			{
					free(temp);
			}
			MainWin();
			
			break;
			
			case '3':
			
				
				printf("Enter the money you want to withdraw\n");
				scanf("%llu",&money);
				
				if(((temp->Balance)>=money)&&money>0)
				{
					(temp->Balance)-=money;
					printf("sussecful operatiion\n");
					printf("your remaining balance is %llu\n",temp->Balance);
				}
				else 
				{
					printf("Un suffiecient balance in your account\n");
					printf("your balance is %llu\n",temp->Balance);
				}
			
			break;
			
			case '4': 
			
				
				printf("Enter the money you want to deposit\n");
				scanf("%llu",&money);
				
				(temp->Balance)+=money;
				printf("sussecful operatiion\n");
				printf("your remaining balance is %llu\n",temp->Balance);

						
			break;
			
			case '5':
			/*nothing*/
			break;
			
			default :
			OpenExistingAcc();
			
			break;
		}
	}
	else
	{
		Acc_Old* temp=Head_Old;
		u128 money;

		while(temp!=NULL&&(temp->BankAccID!=BankAccID))
		{
			temp=temp->Next;
		}
		
		if(temp==NULL)
		{
			printf("No account with this id exists\n");
			return FALSE;
		}
		printf("Hint pass %lu\n\n",(temp->Password));
		
		while((temp->Password)!=Password && trials <3)
		{
			printf("Re enter your Password : ");
			scanf("%lu",&Password);
			trials++;
		}
		
		if(trials==3)
		{
			printf("You enter a wrong password for 3 times\nAccess denied\n");
			return FALSE;
		}
		if((temp->AccountStatus)!='a')
		{
			printf("This account is closed or restricted\n");
			return FALSE;
		}
		printf("1.Make Transaction\n");
		printf("2.Change Account Status\n");
		printf("3.Get Cash\n");
		printf("4.Deposit in Account\n");
		printf("5.Return to main Menu\n\n\n");
		printf("\n\nWhat is your desicion : ");
		
		scanf(" %c",&trials);
		
		system("cls");
		
		switch(trials)
		{
			case '1':
			
			printf("Enter age of the account owner you want to send money to : ");
			scanf("%lu",&Age);
			if(Age>80||Age<1)
			{
				printf("Invalid age range\n");
				OpenExistingAcc();
			}
			else if(Age<21)
			{
				Acc_Young* tempto=Head_Young;
				printf("Enter the bank account ID you want to send money to : ");
				scanf("%lu",&BankAccID);
				while(tempto!=NULL&&((tempto->BankAccID)!=BankAccID))
				{
					tempto=tempto->Next;
				}
				
				if(tempto==NULL)
				{
					printf("No account with this id exists\n");
					return FALSE;
				}
				u128 money;
				
				printf("Enter the money you want to send\n");
				scanf("%llu",&money);
				
				if(((temp->Balance)>=money)&&money>0)
				{
					(temp->Balance)-=money;
					(tempto->Balance)+=money;
					printf("sussecful operatiion\n");
					printf("your remaining balance is %llu\n",temp->Balance);
				}
				else 
				{
					printf("Un suffiecient balance in your account\n");
					printf("your balance is %llu\n",temp->Balance);
				}
			}
			else
			{
				Acc_Old* tempto=Head_Old;
				printf("Enter the bank account ID you want to send money to : ");
				scanf("%lu",&BankAccID);
				while(tempto!=NULL&&((tempto->BankAccID)!=BankAccID))
				{
					tempto=tempto->Next;
				}
				
				if(tempto==NULL)
				{
					printf("No account with this id exists\n");
					return FALSE;
				}
				u128 money;
				
				printf("Enter the money you want to send\n");
				scanf("%llu",&money);
				
				if(((temp->Balance)>=money)&&money>0)
				{
					(temp->Balance)-=money;
					(tempto->Balance)+=money;
					printf("sussecful operatiion\n");
					printf("your remaining balance is %llu\n",temp->Balance);
				}
				else 
				{
					printf("Un suffiecient balance in your account\n");
					printf("your balance is %llu\n",temp->Balance);
				}
			}
			
			break;
			
			
			case '2':
			
			printf("Enter the new status : ");
			scanf(" %c",&(temp->AccountStatus));
			if((temp->AccountStatus)=='c'||(temp->AccountStatus)=='C')
			{
					free(temp);
					CountAcc--;
			}
			MainWin();
			
			break;
			
			case '3':
			
				
				printf("Enter the money you want to withdraw\n");
				scanf("%llu",&money);
				
				if(((temp->Balance)>=money)&&money>0)
				{
					(temp->Balance)-=money;
					printf("sussecful operatiion\n");
					printf("your remaining balance is %llu\n",temp->Balance);
				}
				else 
				{
					printf("Un suffiecient balance in your account\n");
					printf("your balance is %llu\n",temp->Balance);
				}
			
			break;
			
			case '4': 
			
				
				printf("Enter the money you want to deposit\n");
				scanf("%llu",&money);
				
				(temp->Balance)+=money;
				printf("sussecful operatiion\n");
				printf("your remaining balance is %llu\n",temp->Balance);

						
			break;
			
			case '5':
			/*nothing*/
			break;
			
			default :
			OpenExistingAcc();
			
			break;
		}
		
	}
	
	return TRUE;
}
//Client Window

u8 Client_Window()
{
	system("cls");
	static u8 State2;
	do 
	{
	u64  BankAccID;
	u64  Password;
	u8   Age;
	u8   trials=0;
	printf(" Base id is : %d \n" ,BaseId);
	printf("Enter the bank account ID you want to open : ");
	scanf("%lu",&BankAccID);
	
	printf("Enter Password : ");
	scanf("%lu",&Password);
	
	printf("Enter your age : ");
	scanf("%lu",&Age);
	
	if(Age>80||Age<1)
	{
		printf("Invalid age range\n");
		OpenExistingAcc();
	}
	else if(Age<21)
	{
		Acc_Young* temp=Head_Young;
		
		while(temp!=NULL&&(temp->BankAccID!=BankAccID))
		{
			temp=temp->Next;
		}
		
		if(temp==NULL)
		{
			printf("No account with this id exists\n");
			return FALSE;
		}
		printf("Hint pass %lu\n\n",(temp->Password));

		while((temp->Password)!=Password && trials <3)
		{
			printf("Re enter your Password : ");
			scanf("%lu",&Password);
			trials++;
		}
		
		if(trials==3)
		{
			printf("You enter a wrong password for 3 times\nAccess denied\n");
			return FALSE;
		}
		if((temp->AccountStatus)!='a')
		{
			printf("This account is closed or restricted\n");
			return FALSE;
		}
		printf("1.Make Transaction\n");
		printf("2.Change Account Password\n");
		printf("3.Get Cash\n");
		printf("4.Deposit in Account\n");
		printf("5.Return to main Menu\n\n\n");
		
		u128 money;
		
		scanf(" %c",&trials);
		
		system("cls");
		
		switch(trials)
		{
			case '1':
			
			printf("Enter age of the account owner you want to send money to : ");
			scanf("%lu",&Age);
			if(Age>80||Age<1)
			{
				printf("Invalid age range\n");
				OpenExistingAcc();
			}
			else if(Age<21)
			{
				Acc_Young* tempto=Head_Young;
				printf("Enter the bank account ID you want to send money to : ");
				scanf("%lu",&BankAccID);
				while(tempto!=NULL&&((tempto->BankAccID)!=BankAccID))
				{
					tempto=tempto->Next;
				}
				
				if(tempto==NULL)
				{
					printf("No account with this id exists\n");
					return FALSE;
				}
				u128 money;
				
				printf("Enter the money you want to send\n");
				scanf("%llu",&money);
				
				if(((temp->Balance)>=money)&&money>0)
				{
					(temp->Balance)-=money;
					(tempto->Balance)+=money;
					printf("sussecful operatiion\n");
					printf("your remaining balance is %llu\n",temp->Balance);
				}
				else 
				{
					printf("Un suffiecient balance in your account\n");
					printf("your balance is %llu\n",temp->Balance);
				}
			}
			else
			{
				
				Acc_Old* tempto=Head_Old;
				printf("Enter the bank account ID you want to send money to : ");
				scanf("%lu",&BankAccID);
				while(tempto!=NULL&&((tempto->BankAccID)!=BankAccID))
				{
					tempto=tempto->Next;
				}
				
				if(tempto==NULL)
				{
					printf("No account with this id exists\n");
					return FALSE;
				}
				u128 money;
				
				printf("Enter the money you want to send\n");
				scanf("%llu",&money);
				
				if(((temp->Balance)>=money)&&money>0)
				{
					(temp->Balance)-=money;
					(tempto->Balance)+=money;
					printf("sussecful operatiion\n");
					printf("your remaining balance is %llu\n",temp->Balance);
				}
				else 
				{
					printf("Un suffiecient balance in your account\n");
					printf("your balance is %llu\n",temp->Balance);
				}
				
			}
			
			break;
			
			case '2':
			
			printf("Enter the new Password : ");
			scanf(" %c",&(temp->Password));
			MainWin();
			
			break;
			
			case '3':
			
				
				printf("Enter the money you want to withdraw\n");
				scanf("%llu",&money);
				
				if(((temp->Balance)>=money)&&money>0)
				{
					(temp->Balance)-=money;
					printf("sussecful operatiion\n");
					printf("your remaining balance is %llu\n",temp->Balance);
				}
				else 
				{
					printf("Un suffiecient balance in your account\n");
					printf("your balance is %llu\n",temp->Balance);
				}
			
			break;
			
			case '4': 
			
				
				printf("Enter the money you want to deposit\n");
				scanf("%llu",&money);
				
				(temp->Balance)+=money;
				printf("sussecful operatiion\n");
				printf("your remaining balance is %llu\n",temp->Balance);

						
			break;
			
			case '5':
			/*nothing*/
			break;
			
			default :
			OpenExistingAcc();
			
			break;
		}
	}
	else
	{
		Acc_Old* temp=Head_Old;
		u128 money;

		while(temp!=NULL&&(temp->BankAccID!=BankAccID))
		{
			temp=temp->Next;
		}
		
		if(temp==NULL)
		{
			printf("No account with this id exists\n");
			return FALSE;
		}
		printf("Hint pass %lu\n\n",(temp->Password));
		
		while((temp->Password)!=Password && trials <3)
		{
			printf("Re enter your Password : ");
			scanf("%lu",&Password);
			trials++;
		}
		
		if(trials==3)
		{
			printf("You enter a wrong password for 3 times\nAccess denied\n");
			return FALSE;
		}
		if((temp->AccountStatus)!='a')
		{
			printf("This account is closed or restricted\n");
			return FALSE;
		}
		printf("1.Make Transaction\n");
		printf("2.Change Account Status\n");
		printf("3.Get Cash\n");
		printf("4.Deposit in Account\n");
		printf("5.Return to main Menu\n\n\n");
				
		scanf(" %c",&trials);
		
		system("cls");
		
		switch(trials)
		{
			case '1':
			
			printf("Enter age of the account owner you want to send money to : ");
			scanf("%lu",&Age);
			if(Age>80||Age<1)
			{
				printf("Invalid age range\n");
				OpenExistingAcc();
			}
			else if(Age<21)
			{
				Acc_Young* tempto=Head_Young;
				printf("Enter the bank account ID you want to send money to : ");
				scanf("%lu",&BankAccID);
				while(tempto!=NULL&&((tempto->BankAccID)!=BankAccID))
				{
					tempto=tempto->Next;
				}
				
				if(tempto==NULL)
				{
					printf("No account with this id exists\n");
					return FALSE;
				}
				u128 money;
				
				printf("Enter the money you want to send\n");
				scanf("%llu",&money);
				
				if(((temp->Balance)>=money)&&money>0)
				{
					(temp->Balance)-=money;
					(tempto->Balance)+=money;
					printf("sussecful operatiion\n");
					printf("your remaining balance is %llu\n",temp->Balance);
				}
				else 
				{
					printf("Un suffiecient balance in your account\n");
					printf("your balance is %llu\n",temp->Balance);
				}
			}
			else
			{
				Acc_Old* tempto=Head_Old;
				printf("Enter the bank account ID you want to send money to : ");
				scanf("%lu",&BankAccID);
				while(tempto!=NULL&&((tempto->BankAccID)!=BankAccID))
				{
					tempto=tempto->Next;
				}
				
				if(tempto==NULL)
				{
					printf("No account with this id exists\n");
					return FALSE;
				}
				u128 money;
				
				printf("Enter the money you want to send\n");
				scanf("%llu",&money);
				
				if(((temp->Balance)>=money)&&money>0)
				{
					(temp->Balance)-=money;
					(tempto->Balance)+=money;
					printf("sussecful operatiion\n");
					printf("your remaining balance is %llu\n",temp->Balance);
				}
				else 
				{
					printf("Un suffiecient balance in your account\n");
					printf("your balance is %llu\n",temp->Balance);
				}
			}
			
			break;
			
			
			case '2':
			
			printf("Enter the new Password : ");
			scanf(" %c",&(temp->Password));
			MainWin();
			
			break;
			
			case '3':
			
				
				printf("Enter the money you want to withdraw\n");
				scanf("%llu",&money);
				
				if(((temp->Balance)>=money)&&money>0)
				{
					(temp->Balance)-=money;
					printf("sussecful operatiion\n");
					printf("your remaining balance is %llu\n",temp->Balance);
				}
				else 
				{
					printf("Un suffiecient balance in your account\n");
					printf("your balance is %llu\n",temp->Balance);
				}
			
			break;
			
			case '4': 
			
				
				printf("Enter the money you want to deposit\n");
				scanf("%llu",&money);
				
				(temp->Balance)+=money;
				printf("sussecful operatiion\n");
				printf("your remaining balance is %llu\n",temp->Balance);

						
			break;
			
			case '5':
			/*nothing*/
			break;
			
			default :
			OpenExistingAcc();
			
			break;
		}
		
	}
	}while(State2!='5');

	return TRUE;
}
