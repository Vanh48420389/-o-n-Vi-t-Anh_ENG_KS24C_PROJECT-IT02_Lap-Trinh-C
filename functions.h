


#include "datatypes.h"


void displayMenu();
void displayUsers(struct User users[], int userCount);
void addUser(struct User users[], int *userCount);


void searchUserByName(struct User users[], int userCount); // T?m ki?m ng�?i d�ng theo t�n
int isUniqueUser(struct User users[], int userCount, struct User newUser); // Ki?m tra t�nh duy nh?t
int isValidUser(struct User user); // Ki?m tra th�ng tin ng�?i d�ng h?p l?

