#include <stdio.h>
#include <string.h>

// Define a struct to store user name and password
struct login {
    char userName[20];
    char password[20];
};

// Declare the authentication function
int authenticate(char userName[], char password[], struct login user);

int main()
{
    // Declare variables to store user input
    char userName[20];
    char password[20];

    // Declare and initialize a struct variable with valid credentials
    struct login user = {"admin", "secret"};

    // Prompt the user to enter user name and password
    printf("Enter user name: ");
    scanf("%s", userName);
    printf("Enter password: ");
    scanf("%s", password);

    // Call the authentication function and check the return value
    if (authenticate(userName, password, user) == 1)
    {
        // If the return value is 1, the login is successful
        printf("Login successful!\n");
    }
    else
    {
        // If the return value is 0, the login is failed
        printf("Login failed!\n");
    }

    return 0;
}

// Define the authentication function
int authenticate(char userName[], char password[], struct login user)
{
    // Compare the user name and password with the ones stored in the struct
    if (strcmp(userName, user.userName) == 0 && strcmp(password, user.password) == 0)
    {
        // If they match, return 1
        return 1;
    }
    else
    {
        // If they don't match, return 0
        return 0;
    }
}
