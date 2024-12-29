#include "functions.h"
#include <stdio.h>
#include <string.h>

void displayMenu() {
    printf("\n==============================\n");
    printf(" User Management System\n");
    printf("==============================\n");
    printf("1. Display user list\n");
    printf("2. Add new user\n");
    printf("3. Search for a user by name\n");
    printf("4. Exit\n");
    printf("==============================\n");
    printf("Enter your choice: ");
}

void displayUsers(struct User users[], int userCount) {
    if (userCount == 0) {
        printf("\nNo users found!\n");
        return;
    }

    printf("\n%s %s %s %s %s\n", "UserID", "Name", "Gender", "Phone", "Email");
    printf("---------------------------------------------------------------\n");
	int i; 
    for ( i = 0; i < userCount; i++) {
        printf("%s %s %s %s %s\n", 
            users[i].userId, 
            users[i].name, 
            users[i].gender, 
            users[i].phone, 
            users[i].email);
    }
}


void addUser(struct User users[], int *userCount) {
    struct User newUser;
    printf("\n*** Add New User ***\n");

   
    printf("Enter User ID : ");
    fgets(newUser.userId, sizeof(newUser.userId), stdin);
    newUser.userId[strcspn(newUser.userId, "\n")] = 0;

    
    printf("Enter Name : ");
    fgets(newUser.name, sizeof(newUser.name), stdin);
    newUser.name[strcspn(newUser.name, "\n")] = 0;

    
    
    printf("Enter Gender : ");
    fgets(newUser.gender, sizeof(newUser.gender), stdin);
    newUser.gender[strcspn(newUser.gender, "\n")] = 0;

    
    printf("Enter Phone : ");
    fgets(newUser.phone, sizeof(newUser.phone), stdin);
    newUser.phone[strcspn(newUser.phone, "\n")] = 0;

    
    printf("Enter Email : ");
    fgets(newUser.email, sizeof(newUser.email), stdin);
    newUser.email[strcspn(newUser.email, "\n")] = 0;
    
    if (!isValidUser(newUser)) {
        printf("Error: User information cannot be empty.\n");
        return;
    }

    if (!isUniqueUser(users, *userCount, newUser)) {
        printf("Error: User ID, Phone, Email, or Username already exists.\n");
        return;
    }

    
    users[*userCount] = newUser;
    (*userCount)++;

    printf("\nUser added successfully!\n");
}
void searchUserByName(struct User users[], int userCount) {
    char searchName[20];
    int found = 0;

    printf("Enter the name of the user to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; 

    printf("\nSearching for users with name: %s\n", searchName);
	int i; 
    for ( i = 0; i < userCount; i++) {
        if (strstr(users[i].name, searchName) != NULL) {
            if (!found) {
                printf("\n%-10s %-20s %-10s %-10s %-20s\n", "UserID", "Name", "Gender", "Phone", "Email");
                printf("------------------------------------------------------------\n");
            }
            printf("%-10s %-20s %-10s %-10s %-20s\n",
                   users[i].userId,
                   users[i].name,
                   users[i].gender,
                   users[i].phone,
                   users[i].email);
            found = 1;
        }
    }

    if (!found) {
        printf("\nNo users found with the given name.\n");
    }
}
int isUniqueUser(struct User users[], int userCount, struct User newUser) {
	int i; 
    for (i = 0; i < userCount; i++) {
        if (strcmp(users[i].userId, newUser.userId) == 0 ||
            strcmp(users[i].phone, newUser.phone) == 0 ||
            strcmp(users[i].email, newUser.email) == 0 ||
            strcmp(users[i].name, newUser.name) == 0) {
            return 0; // Không duy nh?t
        }
    }
    return 1; 
}
int isValidUser(struct User user) {
    if (strlen(user.userId) == 0 || strlen(user.name) == 0 ||
        strlen(user.phone) == 0 || strlen(user.email) == 0 ||
        strlen(user.name) == 0) {
        return 0; 
    }
    return 1; 
}

