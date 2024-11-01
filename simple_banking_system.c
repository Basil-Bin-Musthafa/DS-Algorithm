#include <stdio.h>
#include <stdlib.h>
#define acc_max 100

struct account{
    long long int accountNumber;
    int password;
    char accountHolderName[50];
    float balance;
};

struct account accounts[acc_max];
int acc_count = 0;

int accountExist(long long int accNumber)
{
    for (int i = 0; i < acc_count; i++)
    {
        if (accounts[i].accountNumber == accNumber)
        {
            return i;
        }
    }
    return -1;
}

int isValidAccNumber(long long int accNumber)
{
    return accNumber >= 100000000001 && accNumber <= 999999999999;
}

int isFourDigitPin(int pin)
{
    return pin >= 1000 && pin <= 9999;
}

void createAccount()
{
    if (acc_count >= acc_max)
    {
        printf("Maximum number of accounts reached\n");
        return;
    }
    struct account newAccount;

    do {
        printf("Enter a 12-digit account number: ");
        scanf("%lld", &newAccount.accountNumber);

        if (!isValidAccNumber(newAccount.accountNumber))
        {
            printf("Invalid account number! Please enter a 12-digit non-negative number starting from 000000000001\n");
        }
        else if (accountExist(newAccount.accountNumber) != -1)
        {
            printf("The account number already exists! Please choose another number\n");
        }

    } while (!isValidAccNumber(newAccount.accountNumber) || accountExist(newAccount.accountNumber) != -1);

    do {
        printf("Enter a four-digit pin number: ");
        scanf("%d", &newAccount.password);

        if (!isFourDigitPin(newAccount.password))
        {
            printf("Invalid PIN! Please enter a four-digit number\n");
        }
    } while (!isFourDigitPin(newAccount.password));

    printf("Enter account holder name: ");
    scanf("%s", newAccount.accountHolderName);
    printf("Enter initial deposit: ");
    scanf("%f", &newAccount.balance);

    accounts[acc_count++] = newAccount;
    printf("Account created successfully!\n");
}

void depositMoney()
{
    long long int accNumber;
    int pass;
    float amount;
    printf("Enter account number: ");
    scanf("%lld", &accNumber);

    for (int i = 0; i < acc_count; i++)
    {
        if (accounts[i].accountNumber == accNumber)
        {
            printf("Enter pin number: ");
            scanf("%d", &pass);

            if (accounts[i].password == pass)
            {
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                accounts[i].balance += amount;
                printf("Deposited successfully!\nCurrent balance: %.2f\n", accounts[i].balance);
                return;
            }
            else
            {
                printf("Incorrect password!\n");
                return;
            }
        }
    }
    printf("Account not found!\n");
}

void withdrawMoney()
{
    long long int accNumber;
    int pass;
    float amount;
    printf("Enter account number: ");
    scanf("%lld", &accNumber);

    for (int i = 0; i < acc_count; i++)
    {
        if (accounts[i].accountNumber == accNumber)
        {
            printf("Enter pin number: ");
            scanf("%d", &pass);

            if (accounts[i].password == pass)
            {
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);

                if (accounts[i].balance >= amount)
                {
                    accounts[i].balance -= amount;
                    printf("Withdrawal successful!\nCurrent balance: %.2f\n", accounts[i].balance);
                }
                else
                {
                    printf("Insufficient balance!\n");
                }
                return;
            }
            else
            {
                printf("Incorrect password!\n");
                return;
            }
        }
    }
    printf("Account not found!\n");
}

void checkBalance()
{
    long long int accNumber;
    int pass;
    printf("Enter account number: ");
    scanf("%lld", &accNumber);

    for (int i = 0; i < acc_count; i++)
    {
        if (accounts[i].accountNumber == accNumber)
        {
            printf("Enter pin number: ");
            scanf("%d", &pass);

            if (accounts[i].password == pass)
            {
                printf("Account holder: %s\n", accounts[i].accountHolderName);
                printf("Current balance: %.2f\n", accounts[i].balance);
                return;
            }
            else
            {
                printf("Incorrect password!\n");
                return;
            }
        }
    }
    printf("Account not found!\n");
}

void transferMoney()
{
	long long int srcAccNumber,desAccNumber;
	int pass;
	float amount;

	printf("Enter your account number:");
	scanf("%lld",&srcAccNumber);

	while(getchar() != '\n');

	int srcIndex = accountExist(srcAccNumber);

	if(srcIndex == -1)
	{
		printf("Source account not found!\n");
		return;
	}
	do{
		printf("Enter your four-digit pin number :");
		scanf("%d",&pass);

		while(getchar() != '\n');

		if(!isFourDigitPin(pass))
		{
			printf("Invalid PIN! Please enter a four-digit number\n");
		}
	}while(!isFourDigitPin(pass));

	if(accounts[srcIndex].password != pass)
	{
		printf("Incorrect password!\n");
		return;
	}

	printf("Enter destination account number :");
	scanf("%lld",&desAccNumber);

	while(getchar() != '\n');

	int destIndex = accountExist(desAccNumber);

	if(destIndex == -1)
	{
		printf("Destination account is not found!\n");
		return;
	}
	do{
		printf("Enter amount to transfer :");
		scanf("%f", &amount);

		while(getchar() != '\n');

		if(amount <=0)
		{
			printf("Invalid amount! Please enter a Positive non-zero amount\n");
		}
	}while(amount <=0);

	if(accounts[srcIndex].balance >= amount)
	{
		accounts[srcIndex].balance -= amount;
		accounts[destIndex].balance += amount;
		printf("Transfer successful!\n your new balance %.2f",accounts[srcIndex].balance);
	}
	else
	{
		printf("Insufficient balance!\n");
		return;
	}
}

int main()
{
	setbuf(stdout, NULL);
    int choice;
    do {
        printf("\n--- Banking System ---\n");
        printf("1. Create account\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. Check balance\n");
        printf("5. Transfer money\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
            	transferMoney();
				break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again\n");
        }
    } while (choice != 6);

    return EXIT_SUCCESS;
}
