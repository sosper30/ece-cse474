#include <stdio.h>
#include <stdlib.h>

//Obj: to create a user information management software, to gather information, save information, and display information.
//Author: Sep M.
//ECE/CSE 474 Week 2 Class Example


//'struct' is a way to group related variables under one name

typedef struct {
    int id;
    int age;
    char name[100];
} UserInfo;

//Functioin prototypes:

void getUserInfo (UserInfo *user);
void saveUserInfo (const UserInfo *user);
void displayUserInfo (const UserInfo *user);

int main () {
    UserInfo user; 

    getUserInfo(&user);
    saveUserInfo(&user);
    displayUserInfo(&user);

    return 0;
}


void getUserInfo (UserInfo *user){
    
    printf("Enter your ID:");
    scanf("%d", &user->id); //Use -> to access struct members when you use a pointer.
    
    printf("What is your First Name:");
    scanf("%s", user->name);

    printf("Enter your Age:");
    scanf("%d", &user->age);

// no return is needed as this is a void function.
}

void saveUserInfo (const UserInfo *user){
    FILE *file = fopen ("474UserInfo.txt", "w"); //optional step. we wont use this file for displayUserInfo

    if (file == NULL){
        printf("Error in opening the file");
        exit(1);
    }

    //Write information into the file
    fprintf(file, "ID:%d\nAge:%d\n,Name:%s\n", user->id, user->age, user->name);
    fclose(file);
}

void displayUserInfo (const UserInfo *user){
    printf ("\nUser Information:\n");
    printf ("ID:%d\n", user->id);
    printf ("Age:%d\n", user->age);
    printf ("Name:%s\n", user->name);



}