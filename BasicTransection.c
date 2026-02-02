
#include<stdio.h>
#include<stdlib.h>
int list();
int TotalAmount=1000,Amount,wd,tr,tt=0,tw=0,td=0,ch;
void detail();
void deposite();
void draw();
void transfer();
void detail();
void last();
void clr_screen();
char a[50];
int acc;
int main(){
while(1){

	printf("\n-------Basic Transection Mode---------\n");
	printf("\nChoose a digit(1to5) ");
 
 	switch(list()){
 		case 1: 
     	 deposite();
 		td+=Amount;
 		break;
 	    case 2:draw();
 	    if(TotalAmount>=wd) tw+=wd;
 	    break;
 	    case 3: transfer();
		if(TotalAmount>=tr) tt+=tr;
		break;
		system("pause");
		case 4:detail();
		// system("pause");
		//system("cls");
		break;
		case 5:last();
		return 0;
		break;
		default: printf("-----invalid number,retry-----");
		break;	
	 }
	 
 }
}
int list(){
	
	printf("\n1.Deposite amount: ");
	printf("\n2.Withdraw amount: ");
	printf("\n3.Transfer amount: ");
	printf("\n4.Check detail: ");
	printf("\n5.Exit: ");
	printf("\nEnter choice: ");
	scanf("%d",&ch);
	return (ch);
}
void deposite(){
	printf("\nEnter the Amount you want to deposite: ");
	scanf("%d",&Amount);
	TotalAmount+=Amount;
	
}
void draw(){
	printf("\nEnter the Amount you want to Withdraw: ");
	scanf("%d",&wd);
	if(TotalAmount>=wd) TotalAmount-=wd;
	else printf("\nLess amount,Withdraw is not possible ");
}
void transfer(){
	printf("\nEnter the Amount you want to Transfer: ");
	scanf("%d",&tr);
	if(TotalAmount>=tr) TotalAmount-=tr;
	else printf("\nLess amount,Transfer is not possible ");
	
}
void detail(){
	
  
	printf("\nTotal amount:%d",TotalAmount);
	printf("\nTotal Deposite:%d",td);
	printf("\nTotal Withdraw:%d",tw);
	printf("\nTotal Transfer:%d",tt);
	printf("\n\n");
	
}
void last(){

  
printf("\n\n");
printf("---THANK FOR TAKING OUR SERVICE---");
	printf("\nTotal amount:%d",TotalAmount);
	printf("\nTotal Deposite:%d",td);
	printf("\nTotal Withdraw:%d",tw);
	printf("\nTotal Transfer:%d",tt);
	printf("\n\n");
	
}

