#include <stdio.h>
#include <stdlib.h>

#define MAX_ACCOUNTS 10

typedef struct
{   
    int id;
    char *name;
    char surname[255];
    double balance;
} BankAccount;

int total_clients = 0;
BankAccount accounts[MAX_ACCOUNTS];

void create_account() {
    if(total_clients >= MAX_ACCOUNTS) {
        printf("There is max value of bank accounts!\n");
        return;
    }
    
    accounts[total_clients].name=malloc(255*sizeof(char));
    accounts[total_clients].id = total_clients + 1;
    printf("Enter Your name: ");
    scanf("%s", accounts[total_clients].name);  
    printf("Enter Your surname: ");
    scanf("%s", accounts[total_clients].surname);
    accounts[total_clients].balance = 0.0;
    printf("Your id is : %d\n",accounts[total_clients].id);
    total_clients++;
}

void check_balance() {
    int id;
    printf("Enter id of account: ");
    scanf("%d", &id);

    if(id < 1 || id > total_clients) {
        printf("There is no bank account with this id!\n");
        return;
    }

    printf("Your balance is %f \n", accounts[id-1].balance);
}

void add_to_balance() {
    int id;
    double sum;
    printf("Enter id of account: ");
    scanf("%d", &id);

    if(id < 1 || id > total_clients) {
        printf("There is no bank account with this id!\n");
        return;
    }

    printf("Enter sum that you want to add to your balance: ");
    scanf("%lf", &sum);  
    accounts[id-1].balance += sum;
    printf("Your balance is: %f\n", accounts[id-1].balance);
}

void info()
{
    int id;
    printf("Enter id of account: ");
    scanf("%d", &id);

    if(id < 1 || id > total_clients) {
        printf("There is no bank account with this id!\n");
        return;
    }

    printf("Name: %s\nSurname: %s\nBalance: %lf\nid: %d\n",accounts[id-1].name,accounts[id-1].surname,accounts[id-1].balance,accounts[id-1].id);
}

int main() {
    char choice;
    
    do {
        printf("\n--- Bank Account Management ---\n");
        printf("1. Create Account\n");
        printf("2. Check Balance\n");
        printf("3. Add to Balance\n");
        printf("4. Check info\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%c,%c", &choice);

        switch (choice) {
            case '1':
                create_account();
                break;
            case '2':
                check_balance();
                break;
            case '3':
                add_to_balance();
                break;
            case '4':
                info();
                break;
            case '0':
                printf("Exiting...\n");
                for(int i=0;i<total_clients;i++)
                    free(accounts[i].name);
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
