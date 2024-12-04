//24P-3118 Muhammad Kaif
//24P-3116 Ghulam Muhammad





#include<stdio.h>
#include<string.h>

#define MAX_USERS 5
#define NAME_LENGHT 50
#define ZAKAT_RATE 0.025

char names[MAX_USERS][NAME_LENGHT];
int accnum[MAX_USERS];
double balances[MAX_USERS];
double loans[MAX_USERS];
int userCount = 0;


void createAccount(){
    if (userCount >= MAX_USERS)
    {
        printf("Can't create more accounts.\n");
        return;
    }

    int accountNumber;
    char name[NAME_LENGHT];

    printf("Enter your name: ");
    scanf(" %[^\n]", name); 
    
    printf("Enter new account number: ");
    scanf("%d",&accountNumber);

    //store the name and acc number
    strcpy(names[userCount],name);
    accnum[userCount] = accountNumber;
    balances[userCount] =0.00;
    loans[userCount] =0.00;
    userCount++;

    printf("Account created successfully! Your account number is : %d.\n",accountNumber);
    
}
int findAccount(int accountNumber){
    for(int i=0 ; i < userCount ; i++){
        if(accnum[i]== accountNumber){
            return i;
        }
    }
    return -1;
}
void checkBalance(){
    int accountNumber;
    printf("Enter Account Number: ");
    scanf("%d",&accountNumber);

    int index = findAccount(accountNumber);
    if(index != -1){
        printf("Account Holder : %s\n",names[index]);
        printf("Current Balance of account is %d: %.2f\n", accountNumber, balances[index]);
    }else{
        printf("No Account found.\n");
    }

}
void depositMoney(){
    int accountNumber;
    double amount;

    printf("Enter Account Number: ");
    scanf("%d",&accountNumber);

    printf("Enter the Amount to deposit: ");
    scanf("%lf",&amount);

    int index = findAccount(accountNumber);
    if(index != -1){
        if(amount > 0){
            balances[index] += amount;
            printf("Deposit successful! New balance: %.2f\n",balances[index]);
        }else{
            printf("Amount must be positive");
        }
    }else{
        printf("No account Found.\n");}
}
void transferMoney(){
    int senderAmount,reciverAmount;
    double amount;

    printf("Enter your account number: ");
    scanf("%d",&senderAmount);
    printf("Enter reciver's account number: ");
    scanf("%d",&reciverAmount);
    printf("Enter the ammount to transfer: ");
    scanf("%lf",&amount);    

    int senderIndex = findAccount(senderAmount);
    int reciverIndex = findAccount(reciverAmount);

    if(senderIndex != -1 && reciverIndex != -1){
        if(amount>0 && balances[senderIndex] >= amount){
            balances[senderIndex] -= amount;
            balances[reciverIndex] += amount;
            printf("Transfer succesful! new balace of account %d: %.2f\n", senderAmount, balances[senderIndex]);
        }else{
            printf("Insufficient balance or invalid amount.\n");
        }
    }else{
        printf("Account not found.\n");
    }
}
void payBill(){
    int accountNumber;
    double billAmount;

    printf("Enter the account Number: ");
    scanf("%d",&accountNumber);
    printf("Enter bill amount: ");
    scanf("%lf",&billAmount);

    int index = findAccount(accountNumber);
    if(index != -1){
        if(billAmount > 0 && balances[index] >= billAmount){
            balances[index] -= billAmount;
            printf("Bill payment successfully paid! New balance: %.2f\n",balances[index]);
        }else{
            printf("Insufficient balance or invalid bill amount.\n");
        }   
    }else{
        printf("Account not found.\n");
    }
}

void takeLoan(){
    int accountnumber;
    double loanamount;
    
    printf("\tEnter the account number: ");
    scanf("%d",&accountnumber);
    printf("\n\tEnter the loan amount: ");
    scanf("%lf",&loanamount);
    
    int accountNumbers= findAccount(accountnumber);
    if(accountNumbers != -1){
        if(loanamount>0){
            
            loans[accountNumbers] += loanamount;
            balances[accountNumbers] += loanamount;
            printf("\n\tLoan approved! New balance is %.2f & Total loan is %.2f", balances[accountNumbers],loans[accountNumbers]);
        }
        else{
            printf("\n\tPlease enter valid loan ammount.");
        }
    }
        else{
            printf("\n\tAccount not found.");
        }
}

void repayLoan(){
    
    int accountnumber;
    double repaymentamount;
    
    printf("\n\tEnter the account number: ");
    scanf("%d",&accountnumber);
    printf("\n\tEnter the amount you want to repay: ");
    scanf("%lf",&repaymentamount);
    
    int accountNumbers = findAccount(accountnumber);
    if(accountNumbers != -1){
        if(repaymentamount>0 && balances[accountNumbers]>=repaymentamount && loans[accountNumbers]>=repaymentamount){
            loans[accountNumbers] -= repaymentamount;
            balances[accountNumbers] -= repaymentamount;
            printf("\n\t Loan repaid successfully!, New balance is %.2f and loan is %.2f", balances[accountNumbers],loans[accountNumbers]);
        }
        else{
            printf("\n\tInvalid balance or incorrect repayment amount.");
        }
    }
    else{
        printf("\n\tAccount not found.");
    }
}

void mobileRecharge(){
    int accountnumber;
    double rechargeAmount;
    
    printf("\tEnter the account number: ");
    scanf("%d",&accountnumber);
    printf("\n\tEnter the amount you want to recharge: ");
    scanf("%lf",&rechargeAmount);
    
   int accountNumbers = findAccount(accountnumber);
   
   if(accountNumbers != -1){
       if(rechargeAmount>0 && balances[accountNumbers]>=rechargeAmount){
       balances[accountNumbers] -= rechargeAmount;
       printf("\n\t Recharged successfully! , New balance is %.2f",balances[accountNumbers]);
   }
   else{
       printf("\n\tInsufficient balance or invalid recharge amount");
   }
   }
   else{
       printf("\n\tAccount not found.");
   }
}

void deductZakat(){
    
    int accountnumber;
    printf("\tEnter the account number: ");
    scanf("%d",&accountnumber);
    
    int accountNumbers = findAccount(accountnumber);
    if(accountNumbers!=-1){
        double zakatAmount= balances[accountNumbers] * ZAKAT_RATE;
        if(balances[accountNumbers]>=zakatAmount){
            balances[accountNumbers]-=zakatAmount;
            printf("\n\tZakat deduction successful! Zakat amount is %.2f , new balance is %.2f", zakatAmount,balances[accountNumbers]);
        }
        else{
            printf("\n\tInsufficient balance for zakat deduction");
        }
    }
    else{
        printf("\n\tAccount not found");
    }
}

void menu() {
    int choice;

    while (1) {
        printf("\n---- Mehfooz Wallet ----\n\n");
        printf("1. Create Account\n");
        printf("2. Check Balance\n");
        printf("3. Deposit Money\n");
        printf("4. Transfer Money\n");
        printf("5. Pay Utility Bill\n");
        printf("6. Take Loan\n");
        printf("7. Repay Loan\n");
        printf("8. Mobile Recharge\n");
        printf("9. Deduct Zakat\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                checkBalance();
                break;
            case 3:
                depositMoney();
                break;
            case 4:
                transferMoney();
                break;
            case 5:
                payBill();
                break;
            case 6:
                takeLoan();
                break;
            case 7:
                repayLoan();
                break;
            case 8:
                mobileRecharge();
                break;
            case 9:
                deductZakat();
                break;
            case 10:
                printf("Thank you for using our service!\n");
                return;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}
