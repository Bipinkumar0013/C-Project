

#include<stdio.h>
#include<string.h>
void Create_Account();
void Deposit_Money();
void Withdraw_Money();
void Balance();
typedef struct bank{
  char name[30];
  int acc_no;
  float balance;
}account;
const char* Account_name="account.dat";

int main(){
  int choice;
  while(1){
  printf("\n\n---Bank Management System---");
printf("\n1.Create Account: ");
printf("\n2.Deposite Money: ");
printf("\n3.Withdraw Money: ");
printf("\n4.Check Balance: ");
printf("\n5.Exit ");
printf("\nEnter your Choice: ");
scanf("%d",&choice);
switch (choice)
{
case 1:
  /* code */Create_Account();
  break;
  case 2:
  /* code */ Deposit_Money();
  break;
  case 3:
  /* code */Withdraw_Money();
  break;
  case 4:
  /* code */ Balance();
  break;
  case 5:
  /* code */printf("Closing Bank , Thank you for your visit.");
  return 0;
  break;

default:
printf("\nInvalid Choice!!!,Retry\n");
  break;
}
  }
}
void Create_Account(){

account acc;
FILE *file=fopen(Account_name,"ab+");
if(file==EOF){
  printf("\nFile opening failed!!");
  return;
}
char c;
do{
  c=getchar();
}while(c!='\n' && c!= EOF);//to clear all enter
printf("\nEnter your name: ");
fgets(acc.name,sizeof(acc.name),stdin);
int index=strcspn(acc.name, "\n");//fixing backspace probelm
acc.name[index]='\0';
printf("Enter your account number: ");
scanf("%d",&acc.acc_no);
fwrite(&acc,sizeof(acc),1,file);//to write all the informatin in file
fclose(file);
acc.balance=0;
printf("\nAccount created successfully!\n");
}


void Deposit_Money(){
  FILE *file=fopen(Account_name,"rb+");
  if(file == NULL){
    printf("\nUnable  to open accounr file");
  }
  int acc_n;
  float money;
  account acc_r;
  printf("\nEnter you account no: ");
  scanf("%d",&acc_n);
  printf("Enter the amount you want to deposit: ");
  scanf("%f",&money);

  while(fread(&acc_r,sizeof(acc_r),1,file)!=EOF){
    if(acc_r.acc_no==acc_n){
      acc_r.balance+=money;
      fseek(file,-sizeof(acc_r),SEEK_CUR);//to move curser one step back
      fwrite(&acc_r,sizeof(acc_r),1,file);
      fclose(file);
      printf("Successfully deposited Rs.%.2f\nNew balance is Rs.%.2f",money,acc_r.balance);
      return;
    }
    else{
       fclose(file);
  printf("\nMoney could not  deposited in account as the Account no %d was not found in records",acc_n);
 return;
    }

  }

}
void Withdraw_Money(){
  
 FILE *file=fopen(Account_name,"rb+");
  if(file == NULL){
    printf("\nUnable  to open accounr file");
  }
  int acc_n;
  float money;
  account acc_r;
  printf("\nEnter you account no: ");
  scanf("%d",&acc_n);
  printf("Enter the amount you want to withdraw: ");
  scanf("%f",&money);

  while(fread(&acc_r,sizeof(acc_r),1,file)!=EOF){
    if(acc_r.acc_no==acc_n){
      if(acc_r.balance>=money){
      acc_r.balance-=money;
      fseek(file,-sizeof(acc_r),SEEK_CUR);//to move curser one step back
      fwrite(&acc_r,sizeof(acc_r),1,file);
      printf("Successfully deposited Rs.%.2f\nNew balance is Rs.%.2f",money,acc_r.balance);
    }
    else{
      printf("Insufficient balance!!");
    }
    fclose(file);
    return;
  }
  else{
    fclose(file);
  printf("\nMoney could not  Withdraw in account as the Account no %d was not found in records",acc_n);
  return;
  }
}

}
void Balance(){
  FILE *file=fopen(Account_name,"rb");
if(file==EOF){
  printf("\nFile opening failed!!");
}
int acc_no;
account acc_read;
printf("Enter your account number: ");
scanf("%d",&acc_no);

while(fread(&acc_read,sizeof(acc_read),1,file)){
  if(acc_read.acc_no==acc_no){
    printf("\nYour current balance is %.2f ",acc_read.balance);
    fclose(file);
    return;
  }
}
fclose(file);
printf("\nAccount no: %d is not found ",acc_no);


}