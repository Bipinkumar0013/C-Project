#include<conio.h>
#include<stdio.h>
#include<string.h>
#define MAX_USERS 10
#define CREDENRIAL 30
 void user_register();
int user_login();
void fix_fgets(char *);
void input_password(char *);

typedef struct {
  char username[30];
  char password[30];

}User;
User users[MAX_USERS];
int user_count=0;
int user_index=0;
int main(){
  int choice;
  while(1){
  printf("\n---Welcome to user Management---\n\n");
  printf("1:Register \n");
  printf("2:Login  \n");
  printf("3:Exit  \n");
  printf("Enter the choice: ");
 
  scanf("%d",&choice);
  getchar();//consume extr space
  switch (choice)
  {
  case 1:
     user_register();
    
    break;
     case 2:
    user_index = user_login();
    if(user_index!=-1){
      printf("\nLogin successful! Welcome, %s!",users[user_index].username);
    }
    else{
   printf("\nLogin failed ! Incorrect username or password,\n");
   
    }
    
    

    break;
     case 3:
    return 0;
    break;
  
  default: printf("Invalid Option ,Please try again!");
    break;
  }
  }
}
 void user_register(){
  if(user_count==MAX_USERS){
    printf("Maximum %d user are supportd! No more registration allowed !!!\n",MAX_USERS);
  }
  int new_index = user_count;
  printf("\nRegister new User");
  printf("\nEnter Username: ");
  fgets(users[new_index].username,CREDENRIAL,stdin);
  fix_fgets(users[new_index].username);
    input_password(users[new_index].password);
    printf("\nRegistration Successful!!!");
  user_count++;
 }
 int user_login(){
  char username[CREDENRIAL];
  char password[CREDENRIAL];
  printf("\nEnter Username: ");
  fgets(username,CREDENRIAL,stdin);
  fix_fgets(username);
   input_password(password);
    for(int i=0;i < user_count ; i++){
      if(strcmp(username,users[i].username)==0 && strcmp(password,users[i].password)==0){
        return i;
      }
    }
    return -1; 
 }
// void input_password(char *password){
//   printf("Enter password : ");
//   fgets(password,CREDENRIAL,stdin);
//   fix_fgets(password);
//  }
 // Required for getch()

void input_password(char *password) {
    char ch;
    int i = 0;
    printf("Enter password: ");
while (1) {
    ch = getch(); // Read character without echoing it to screen
 if (ch == 13) { // 13 is the ASCII code for the Enter key
     password[i] = '\0';
        break;
     } else if (ch == 8) { // 8 is the ASCII code for Backspace
      if (i > 0) {
           i--;
    printf("\b \b"); // Move cursor back, print space, move back again
      }
   } else if (i < CREDENRIAL - 1) {
  password[i++] = ch;
   printf("*"); // Print asterisk instead of the actual character
   }
 }
printf("\n");
}
void fix_fgets(char *str){
  int index = strcspn(str,"\n");
   str[index]='\0';
  }
