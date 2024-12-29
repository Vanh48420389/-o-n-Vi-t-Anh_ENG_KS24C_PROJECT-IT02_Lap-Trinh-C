
#include "functions.h"
/*run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]){
	struct User users[100]; 
    int userCount = 0;      
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                displayUsers(users, userCount);
                break;
            case 2:
                addUser(users, &userCount);
                break;
            case 3:
                searchUserByName(users, userCount);
    			break;
            case 4:
				printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

	return 0;
}
