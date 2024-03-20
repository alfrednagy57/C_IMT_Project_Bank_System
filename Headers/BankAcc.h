#ifndef BankAcc_h
#define BankAcc_h
#include "STD_TYPES.h"

#define BaseId 1000000000

#define Admin_User "Alfred255"
#define Admin_Pass 2562002

struct BankAcc
{
	u8   FullName[50];//User name first four names at least
	u8   FullAdd[50];	//User address in details
	u8   Guardian[50]; // if age<21 .name of his father
	u8   Age;// age 
	u8   AccountStatus;
	u64  BankAccID;// id of the account 
	u64  Password;// password for the account
	u128 NationalID;// national id for the account user
	u128 GuardianNationalID; //national id if he has a guardian
	u128 Balance;// account balance
	struct BankAcc *Next;
};

typedef struct BankAcc Acc_Young;

struct BankAcc2
{
	u8   FullName[50];//User name first four names at least
	u8   FullAdd[50];	//User address in details
	u8   Age;// age 
	u8   AccountStatus;
	u64  BankAccID;// id of the account 
	u64  Password;// password for the account
	u128 NationalID;// national id for the account user
	u128 Balance;// account balance
	struct BankAcc2 *Next;
};

typedef struct BankAcc2 Acc_Old;

#endif