
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
  int guess,random;
  int no_guess;
  srand(time(NULL));//GENERATE no at seed of time
  printf("\nWelcome to the world of guessing number!\n");
  random=rand()%100+1;

  
  do{
  	 printf("\nPlease Enter the Number between(1 to 100): ");
     scanf("%d",&guess);
    no_guess++;
    if(guess>random){
      printf("\nEnter Smaller Number !\n");
    }
    else if(guess<random){
      printf("\nEnter Larger Number!\n");
    }
    else {
      printf("\nCongratulation!!! You won the game at total %d attempt",no_guess);
    }
  }while(guess!=random);
  printf("\nBye Bye, Thanks for playig.\n ");
  printf("\nDeveloped by : Bipin Kumar Prjapati");
}