


#include "datatypes.h"


void displayMenu();
void displayUsers(struct User users[], int userCount);
void addUser(struct User users[], int *userCount);


void searchUserByName(struct User users[], int userCount); // T?m ki?m ngý?i dùng theo tên
int isUniqueUser(struct User users[], int userCount, struct User newUser); // Ki?m tra tính duy nh?t
int isValidUser(struct User user); // Ki?m tra thông tin ngý?i dùng h?p l?

