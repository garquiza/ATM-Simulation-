#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>
#define code 10

// DATA STRUCTURE FOR THE USER INFORMATION

typedef struct INFO {
    char accountNum[6];
    char name[50];
    char month[10];
    char day[3];
    char year[5];
    char contactNum[12];
    char pin[7];
    double balance;
} info;

info IL[100];
int MAX = 0;
void sampleInfo();

void transaction(int n);

void balanceInquiry(int n);
void withdraw(int n);
void deposit();
void fundTransfer(int n);
void changePin(int n);
void viewProfile(int n);

void load() {
    FILE *fpointer = fopen("ATM accounts.txt", "r");

    fscanf(fpointer, "%d\n", &MAX);
    for(int i=0; i<MAX; i++) {
        fscanf(fpointer, "%s\n", &IL[i].accountNum);
        fgets(IL[i].name, 50, fpointer);
        IL[i].name[strlen(IL[i].name) - 1] = '\0';
        fgets(IL[i].month, 10, fpointer);
        IL[i].month[strlen(IL[i].month) - 1] = '\0';
        fgets(IL[i].day, 10, fpointer);
        IL[i].day[strlen(IL[i].day) - 1] = '\0';
        fgets(IL[i].year, 10, fpointer);
        IL[i].year[strlen(IL[i].year) - 1] = '\0';
        fgets(IL[i].contactNum, 20, fpointer);
        IL[i].contactNum[strlen(IL[i].contactNum) - 1] = '\0';
        fgets(IL[i].pin, 7, fpointer);
        IL[i].pin[strlen(IL[i].pin)] = '\0';
        fscanf(fpointer, "%lf\n", &IL[i].balance);
    }
    fclose(fpointer);
}

void save(){
    FILE *fpointer = fopen("ATM accounts.txt", "w");

    fprintf(fpointer, "%d\n", MAX);
    for(int i=0; i<MAX; i++) {
        fprintf(fpointer, "%s\n", IL[i].accountNum);
        fprintf(fpointer, "%s\n", IL[i].name);
        fprintf(fpointer, "%s\n", IL[i].month);
        fprintf(fpointer, "%s\n", IL[i].day);
        fprintf(fpointer, "%s\n", IL[i].year);
        fprintf(fpointer, "%s\n", IL[i].contactNum);
        fprintf(fpointer, "%s\n", IL[i].pin);
        fprintf(fpointer, "%.2lf\n\n", IL[i].balance);
    }
    fclose(fpointer);
}

int flashDrive() {
    FILE *fpointer = fopen("ATMcard.txt", "r");

    if(fpointer == NULL){
        printf("\n\n\t\t\t==================================================================\n");
        printf("\t\t\t|      There is no card inserted. Please insert an ATM card...      |\n");
        printf("\t\t\t==================================================================\n\n");
    return 0;
    }

    printf("\n\n\t\t\t==================================================================\n");
    printf("\t\t\t|                      WELCOME TO PROGBANK!                      |\n");
    printf("\t\t\t==================================================================\n\n");
    system("pause");
    system("cls");

    printf("\n\n\t\t\t==================================================================\n");
    printf("\t\t\t|                      Reading the ATM card...                   |\n");
    printf("\t\t\t==================================================================\n\n");
    system("pause");
    system("cls");

    printf("\n\n\t\t\t==================================================================\n");
    printf("\t\t\t|             ATM Card inserted. You may now proceed...          |\n");
    printf("\t\t\t==================================================================\n\n");
    system("pause");
    system("cls");
    fclose(fpointer);

return 1;
}

void encrypt(char pin[]) {
    for(int i=0; i<strlen(pin); i++) {
        pin[i] = pin[i] + code;
    }
}

void decrypt(char pin[]) {
    for(int i=0; i<strlen(pin); i++) {
        pin[i] = pin[i] - code;
    }
}

void sampleInfo() {
    printf("\n\n\t\t\t======================================================\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t|           GUIDE TO OPENING NEW ATM ACCOUNT         |\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t======================================================\n");

    printf("\n\t\t\tAccount Number: 02468 \n");
    printf("\t\t\t---------------------------------------\n");
    printf("\n\t\t\tAccount Name: Juan Dela Cruz \n");
    printf("\t\t\t---------------------------------------\n");
    printf("\n\t\t\t[BIRTHDAY]\n");
    printf("\t\t\tMonth: January \n");
    printf("\t\t\tDay: 01\n");
    printf("\t\t\tYear: 1999\n");
    printf("\t\t\t---------------------------------------\n");
    printf("\n\t\t\tContact Number: 09123456789\n");
    printf("\t\t\t---------------------------------------\n");
    printf("\n\t\t\tP5000 MINIMUM OF INITIAL DEPOSIT");
    printf("\n\t\t\tInitial Deposit: P5000\n");
    printf("\t\t\t---------------------------------------\n");
    printf("\n\t\t\tInput PIN Code: ******\n");
    printf("\t\t\t---------------------------------------");
}

char menu() {
    char selection;

    printf("\n\n\t\t\t=========================================================================\n");
    printf("\t\t\t|                                                                       |\n");
    printf("\t\t\t|                       WELCOME TO PROGBANK!                            |\n");
    printf("\t\t\t|                                                                       |\n");
    printf("\t\t\t|        1. REGISTRATION MODULE (opening new ATM account)               |\n");
    printf("\t\t\t|                                                                       |\n");
    printf("\t\t\t|        2. TRANSACTION MODULE / LOG-IN (account number + PIN code)     |\n");
    printf("\t\t\t|                                                                       |\n");
    printf("\t\t\t|        3. EXIT / SAVE DATA                                            |\n");
    printf("\t\t\t|                                                                       |\n");
    printf("\t\t\t|                                                                       |\n");
    printf("\t\t\t=========================================================================\n");
    printf("\n\t\t\tSELECT YOUR CHOICE: ");
    scanf(" %c", &selection);
    fflush(stdin);

return selection;
}

void reg() {
    int f, d;
    int x = 0;
    char ch;
    char accountNum[6];
    char name[50];
    char pin[7];
    double initialDeposit;

    printf("\n\n\t\t\t================================================\n");
    printf("\t\t\t|                                              |\n");
    printf("\t\t\t|                  REGISTRATION                |\n");
    printf("\t\t\t|                                              |\n");
    printf("\t\t\t================================================\n");
    printf("\n\t\t\t[PLEASE ENTER YOUR INFORMATION.]\n");

    do {
        f = 0;
        d = 1;
        printf("\n\t\t\tAccount Number: ");
        gets(accountNum);
        for(int i=0; i<MAX; i++) {
            if(strcmp(accountNum, IL[i].accountNum) == 0) {
                f = 1;
            }
        }
        for(int i=0; i<strlen(accountNum); i++) {
            if(isalpha(accountNum[i])) {
                d = 0;
            }
            if(isalpha(accountNum[i]) == 0 && isdigit(accountNum[i]) == 0) {
                d = 0;
            }
        }
        if(f == 1) {
            printf("\n\t\t\tError! Account Number Already Exist..\n");
            printf("\t\t\t---------------------------------------\n");
        }
        if(strlen(accountNum) <= 4) {
            printf("\n\t\t\tError! Account Number must be 5 Digits..\n");
            printf("\t\t\t---------------------------------------\n");
        }
        if(strlen(accountNum) > 5) {
            printf("\n\t\t\tError! Account Number is Maximum 5 Digits..\n");
            printf("\t\t\t---------------------------------------\n");
        }
        if(d == 0) {
            printf("\n\t\t\tError! Account Number only accept digits..\n");
            printf("\t\t\t---------------------------------------\n");
        }
    } while(f == 1 || strlen(accountNum) > 5 || strlen(accountNum) <= 4 || d == 0);
    strcpy(IL[MAX].accountNum, accountNum);
    printf("\t\t\t---------------------------------------\n");

    do {
        f = 0;
        d = 0;
        printf("\n\t\t\tAccount Name: ");
        gets(name);
        for(int i=0; i<MAX; i++) {
            if(strcmp(name, IL[i].name) == 0) {
                f = 1;
            }
        }
        if(f == 1) {
            printf("\n\t\t\tError! Account Name already exist..\n");
            printf("\t\t\t---------------------------------------\n");
        }
        for(int i=0; i<strlen(name); i++) {
            if(isdigit(name[i])) {
                d = 1;
            }
        }
        if(d == 1) {
            printf("\n\t\t\tError! No digits are allowed in the Account Name..\n");
            printf("\t\t\t-----------------------------------------\n");
        }
    } while(f == 1 || d == 1);
    strcpy(IL[MAX].name, name);
    printf("\t\t\t---------------------------------------\n");

    printf("\n\t\t\t[BIRTHDAY]\n");
    printf("\t\t\tMonth: ");
    gets(IL[MAX].month);
    printf("\t\t\tDay: ");
    gets(IL[MAX].day);
    printf("\t\t\tYear: ");
    gets(IL[MAX].year);
    printf("\t\t\t---------------------------------------\n");
    printf("\n\t\t\tContact Number: ");
    gets(IL[MAX].contactNum);
    printf("\t\t\t---------------------------------------\n");

    do {
        printf("\t\t\tP5000 MINIMUM OF INITIAL DEPOSIT\n");
        printf("\n\t\t\tInitial Deposit: P");
        scanf("%lf", &initialDeposit);
        if(initialDeposit < 5000) {
            printf("\n\t\t\tError! Minimum Initial Deposit is 5000\n");
            printf("\t\t\t=======================================\n");
        }
    } while(initialDeposit < 5000);
    fflush(stdin);
    IL[MAX].balance = initialDeposit;
    printf("\t\t\t---------------------------------------\n");

    printf("\n\t\t\tInput PIN Code: ");
    while((ch = getch()) != 13 && x < 5) {
        if(x < 0) {
            x = 0;
        }
        if(ch == 8) {
            putch('\b');
            putch(' ');
            putch('\b');
            x--;
            continue;
        }
        if(isdigit(ch)) {
            pin[x++] = ch;
            putch('*');
        }
    }
    if(x == 5) {
        pin[x++] = ch;
    }
    encrypt(pin);
    strcpy(IL[MAX].pin, pin);
    printf("\n\t\t\t---------------------------------------\n");
    printf("\n\t\t\tREGISTRATION COMPLETE. THANK YOU!\n");
    MAX++;
}

void login() {
    printf("\n\n\t\t\t================================================\n");
    printf("\t\t\t|                                              |\n");
    printf("\t\t\t|                    LOG-IN                    |\n");
    printf("\t\t\t|                                              |\n");
    printf("\t\t\t================================================\n");

    if(MAX == 0) {
        printf("\n\t\t\tThere is no registered account!\n\t\t\tRegister an account first.\n\n");
        printf("\t\t\t=======================================\n");
        system("pause");
        system("cls");
        return;
    }

    int n, v;
    int f = 0;
    int x = 0;
    int tries = 1;
    char ch;
    char accountNum[6];
    char pin[7];

    printf("\n\t\t\tEnter Account Number: ");
    gets(accountNum);
    for(int i=0; i<MAX; i++) {
        if(strcmp(accountNum, IL[i].accountNum) == 0) {
            n = i;
            f = 1;
        }
    }
    printf("\t\t\t=======================================\n");

    if(f == 0) {
        printf("\n\t\t\tInvalid Account Number.\n");
        printf("\t\t\t=======================================\n");
        printf("\n");
        system("pause");
        system("cls");
        return;
    }

    decrypt(IL[n].pin);

    do {
        x = 0;
        printf("\n\t\t\tEnter PIN Code: ");
        while((ch = getch()) != 13 && x < 5) {
            if(x < 0) {
                x = 0;
            }
            if(ch == 8) {
                putch('\b');
                putch(' ');
                putch('\b');
                x--;
                continue;
            }
            if(isdigit(ch)) {
                pin[x++] = ch;
                putch('*');
            }
        }
        if(x == 5) {
            pin[x++] = ch;
        }
        pin[x] = '\0';

        if(strcmp(pin, IL[n].pin) == 0) {
            v = 1;
            break;
        }
        else {
            printf("\n\t\t\tInvalid PIN Code! Please Try Again.\n");
            printf("\t\t\t=======================================\n");
            tries++;
            v = 0;
        }
    } while(tries <= 4);
    encrypt(IL[n].pin);

    if(v == 0) {
        printf("\n\t\t\tToo many attempts! Returning...\n\n");
        printf("\t\t\t=======================================\n");
        system("pause");
        system("cls");
        return;
    }

    printf("\n\t\t\tLOG-IN SUCESSFUL.\n\n");
    printf("\t\t\t=======================================\n");
    system("pause");
    system("cls");
    transaction(n);
}

int main() {
    if(flashDrive() == 1) {

        load();
        sampleInfo();
        char m;

        do {
            m = menu();
            switch(m) {
            case '1':
                system("cls");
                reg();
                printf("\n");
                system("pause");
                system("cls");
                break;
            case '2':
                system("cls");
                login();
                break;
            case '3':
                printf("\n\t\t\tTHANK YOU FOR USING PROGBANK. HAVE A NICE DAY!\n\n");
                system("pause");
                system("cls");
                printf("   ATM SIMULATION PROJECT\n");
                printf("   Submitted by: Grace Nicole Arquiza and Mariecris Camasis from BSIS-NS-2A\n");
                printf("\n\t\t\tDATA SAVED to --ATM accounts.txt-- \n");
                save();
                break;
            default:
                printf("\n\n\t\t\tInvalid Input! Try again.\n");
                system("pause");
                system("cls");
            }

        } while(m != '3');
    }
    return 0;
}

void transaction(int n) {
    char selection;

    do {
        printf("\n\n\t\t\t===================================================================\n");
        printf("\t\t\t|                                                                 |\n");
        printf("\t\t\t|                          TRANSACTION MODULE                     |\n");
        printf("\t\t\t|                                                                 |\n");
        printf("\t\t\t|              1. BALANCE INQUIRY                                 |\n");
        printf("\t\t\t|              2. WITHDRAW                                        |\n");
        printf("\t\t\t|              3. DEPOSIT                                         |\n");
        printf("\t\t\t|              4. FUND TRANSFER                                   |\n");
        printf("\t\t\t|              5. CHANGE PIN CODE                                 |\n");
        printf("\t\t\t|              6. VIEW PROFILE                                    |\n");
        printf("\t\t\t|              7. EXIT ACCOUNT                                    |\n");
        printf("\t\t\t|                                                                 |\n");
        printf("\t\t\t|                                                                 |\n");
        printf("\t\t\t===================================================================\n");
        printf("\n\t\t\tSELECT YOUR CHOICE: ");
        scanf(" %c", &selection);
        fflush(stdin);

        switch(selection) {
        case '1':
            system("cls");
            balanceInquiry(n);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case '2':
            system("cls");
            withdraw(n);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case '3':
            system("cls");
            deposit(n);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case '4':
            system("cls");
            fundTransfer(n);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case '5':
            system("cls");
            changePin(n);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case '6':
            system("cls");
            viewProfile(n);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case '7':
            system("cls");
            break;
        default:
            printf("\n\t\t\tInvalid Input.\n");
            system("pause");
        }
    } while(selection != '7');
}

void balanceInquiry(int n) {
    printf("\n\n\t\t\t======================================================\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t|                  BALANCE INQUIRY                   |\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t======================================================\n");
    printf("\n\t\t\t|   YOUR BALANCE IS P%.2lf\n", IL[n].balance);
    printf("\t\t\t=======================================\n");
}

void withdraw(int n) {
    double withdrawAmount;

    printf("\n\n\t\t\t======================================================\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t|                      WITHDRAW                      |\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t======================================================\n");
    printf("\n\t\t\t|   BALANCE: P%.2lf\n", IL[n].balance);
    printf("\t\t\t=======================================\n");
    if(IL[n].balance <= 0) {
        printf("\n\t\t\tInsufficient Balance!\n");
        printf("\t\t\t=======================================\n");
        return;
    }

    do {
        printf("\n\t\t\t|   WITHDRAW AMOUNT: P");
        scanf("%lf", &withdrawAmount);
        fflush(stdin);
        if(withdrawAmount > IL[n].balance) {
            printf("\n\t\t\tWithdraw Amount Exceeded Account Balance! Please Try Again.\n");
            printf("\t\t\t=======================================\n");
            continue;
        }
        else if(withdrawAmount < 500) {
            printf("\n\t\t\tWithdraw Amount has a Minimum of P500! Please Try Again.\n");
            printf("\t\t\t=======================================\n");
            continue;
        }
        else {
            printf("\n\t\t\tWithdraw Successful.\n");
            printf("\t\t\tP%.2lf - P%.2lf\n", IL[n].balance, withdrawAmount);
            IL[n].balance -= withdrawAmount;
            printf("\n\t\t\t|   BALANCE NOW: P%.2lf\n", IL[n].balance);
            printf("\t\t\t=======================================\n");
            break;
        }
    } while(1);
}

void deposit(int n) {
    double depositAmount;

    printf("\n\n\t\t\t======================================================\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t|                       DEPOSIT                      |\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t======================================================\n");
    printf("\n\t\t\t|   BALANCE: P%.2lf\n", IL[n].balance);
    printf("\t\t\t=======================================\n");

    do {
        printf("\n\t\t\t|   DEPOSIT AMOUNT: P");
        scanf("%lf", &depositAmount);
        fflush(stdin);
        if(depositAmount < 500) {
            printf("\n\t\t\tMinimum Deposit Amount is 500! Please Try Again.\n");
            printf("\t\t\t=======================================\n");
            continue;
        }
        else {
            printf("\n\t\t\tDeposit Successful.\n");
            printf("\t\t\tP%.2lf + P%.2lf\n", IL[n].balance, depositAmount);
            IL[n].balance += depositAmount;
            printf("\n\t\t\t|   YOUR BALANCE: P%.2lf\n", IL[n].balance);
            printf("\t\t\t=======================================\n");
            break;
        }
    } while(1);
}

void fundTransfer(int n) {
    printf("\n\n\t\t\t======================================================\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t|                   FUND TRANSFER                    |\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t======================================================\n");
    printf("\n\t\t\t|   YOUR BALANCE: P%.2lf\n", IL[n].balance);
    printf("\t\t\t=======================================\n");

    if(MAX == 1) {
        printf("\n\t\t\t You cannot Transfer Funds! None registered account(s) detected.\n");
        printf("\t\t\t=======================================\n");
        return;
    }
    if(IL[n].balance <= 0) {
        printf("\n\t\t\tInsufficient Balance.\n");
        printf("\t\t\t=======================================\n");
        return;
    }

    int nMAX = 0;
    int x, f = 0;
    char accountNum[6];
    double transfer;

    printf("\n\t\t\t|   REGISTERED ACCOUNT(S)\n");
    for(int i=0; i<MAX; i++) {
        if(i == n) {
            continue;
        }
        printf("\t\t\t%s  ", IL[i].accountNum);
        nMAX++;
        if(nMAX % 2 == 0) {
            printf("\n");
        }
    }
    printf("\n\t\t\t=======================================\n");

    printf("\n\t\t\t|   ACCOUNT NUMBER TO TRANSFER FUNDS: ");
    gets(accountNum);
    for(int i=0; i<MAX; i++) {
        if(strcmp(accountNum, IL[i].accountNum) == 0) {
            x = i;
            f = 1;
        }
    }

    if(f == 0) {
        printf("\n\t\t\tInvalid Account Number.\n");
        printf("\t\t\t=======================================\n");
        return;
    }

    do {
        printf("\n\t\t\t|   TRANSFER AMOUNT: P");
        scanf("%lf", &transfer);
        fflush(stdin);
        if(transfer > IL[n].balance) {
            printf("\n\t\t\tTransfer Amount Exceeded Account Balance! Please Try Again.\n");
            printf("\t\t\t=======================================\n");
            continue;
        }
        else if(transfer <= 200) {
            printf("\n\t\t\tMinimum Transfer Amount is 200. Please Try Again.\n");
            printf("\t\t\t=======================================\n");
            continue;
        }
        else {
            printf("\n\t\t\tTransfer Funds Successful.\n");
            printf("\t\t\tP%.2lf - P%.2lf\n", IL[n].balance, transfer);
            IL[n].balance -= transfer;
            printf("\n\t\t\t|   YOUR BALANCE: P%.2lf\n", IL[n].balance);
            printf("\t\t\t=======================================\n");

            printf("\n\t\t\t[TRANSFERED]\n");
            printf("\n\t\t\tAccount %s\n", IL[x].accountNum);
            printf("\t\t\tP%.2lf + P%.2lf\n", IL[x].balance, transfer);
            IL[x].balance += transfer;
            printf("\n\t\t\t|   ACCOUNT %s BALANCE: P%.2lf\n", IL[x].accountNum, IL[x].balance);
            printf("\t\t\t=======================================\n");
            break;
        }
    } while(1);
}

void changePin(int n) {
    printf("\n\n\t\t\t======================================================\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t|                   CHANGE PIN CODE                  |\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t======================================================\n");

    int d, x = 0;
    char ch;
    char newPin[7];

    printf("\n\t\t\t|   ENCRYPTED PIN: %s\n", IL[n].pin);
    decrypt(IL[n].pin);
    printf("\t\t\t|   DECRYPTED PIN: %s\n", IL[n].pin);
    printf("\t\t\t=======================================\n");

    printf("\n\t\t\t|   Enter New PIN Code: ");
    while((ch = getch()) != 13 && x < 5) {
        if(x < 0) {
            x = 0;
        }
        if(ch == 8) {
            putch('\b');
            putch(' ');
            putch('\b');
            x--;
            continue;
        }
        if(isdigit(ch)) {
            newPin[x++] = ch;
            putch('*');
        }
    }
    if(x == 5) {
        newPin[x++] = ch;
    }
    newPin[x] = '\0';
    printf("\n");
    encrypt(newPin);
    printf("\t\t\t|   ENCRYPTED NEW PIN CODE: %s\n", newPin);
    strcpy(IL[n].pin, newPin);
    printf("\n\t\t\tPIN CODE CHANGED SUCCESSFULLY.\n");
    printf("\t\t\t=======================================\n");
}

void viewProfile(int n) {
    printf("\n\n\t\t\t======================================================\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t|                    VIEW PROFILE                    |\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t======================================================\n");
    printf("\n\t\t\t|   ACCOUNT NUMBER: %s\n", IL[n].accountNum);
    printf("\t\t\t=======================================\n");
    printf("\n\t\t\t|   ACCOUNT NAME: %s\n", IL[n].name);
    printf("\t\t\t=======================================\n");
    printf("\n\t\t\t|   BIRTHDAY: %s %s, %s\n", IL[n].month, IL[n].day, IL[n].year);
    printf("\t\t\t=======================================\n");
    printf("\n\t\t\t|   CONTACT NUMBER: %s\n", IL[n].contactNum);
    printf("\t\t\t=======================================\n");
    printf("\n\t\t\t|   BALANCE: P%.2lf\n", IL[n].balance);
    printf("\t\t\t=======================================\n");
    decrypt(IL[n].pin);
    printf("\n\t\t\t|   PIN CODE (DECRYPTED): %s\n", IL[n].pin);
    encrypt(IL[n].pin);
    printf("\t\t\t=======================================\n");
}

