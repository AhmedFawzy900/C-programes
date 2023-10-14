#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> // Include this header file to use bool type

// Define a struct to store user information
struct user {
  char username[20];
  char password[20];
  bool active; // Add a bool member to store the active flag
};

// Declare a global pointer to store the array of users
struct user *users = NULL;

// Declare a global variable to store the number of users
int num_users = 0;

// A function to register a new user
void register_user() {
  // Allocate memory for a new user
  struct user *new_user = malloc(sizeof(struct user));
  if (new_user == NULL) {
    printf("Memory allocation failed.\n");
    return;
  }

  // Prompt the user to enter username and password
  printf("Enter username: ");
  scanf("%s", new_user->username);
  printf("Enter password: ");
  scanf("%s", new_user->password);

  // Prompt the user to enter the active flag
  printf("Enter active flag (0 or 1): ");
  int flag; // Declare a temporary variable to store the input
  scanf("%d", &flag);

  // Check if the input is valid
  if (flag == 0) {
    new_user->active = false; // Set the active flag to false
  } else if (flag == 1) {
    new_user->active = true; // Set the active flag to true
  } else {
    printf("Invalid input. Please enter 0 or 1.\n");
    free(new_user); // Free the memory allocated for the new user
    return;
  }

  // Check if the username already exists
  for (int i = 0; i < num_users; i++) {
    if (strcmp(users[i].username, new_user->username) == 0) {
      printf("Username already exists. Please choose another one.\n");
      free(new_user); // Free the memory allocated for the new user
      return;
    }
  }

  // Append the new user to the array of users
  users = realloc(users, (num_users + 1) * sizeof(struct user));
  if (users == NULL) {
    printf("Memory allocation failed.\n");
    free(new_user); // Free the memory allocated for the new user
    return;
  }
  users[num_users] = *new_user; // Copy the new user to the array
  num_users++; // Increment the number of users

  // Display a success message
  printf("Registration successful.\n");
}

// A function to login an existing user
void login_user() {
  // Declare variables to store username and password
  char username[20];
  char password[20];

  // Prompt the user to enter username and password
  printf("Enter username: ");
  scanf("%s", username);
  printf("Enter password: ");
  scanf("%s", password);

  // Check if the username and password match any existing user
  for (int i = 0; i < num_users; i++) {
    if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
      // Check if the user is active
      if (users[i].active) {
        // Display a success message
        printf("Login successful.\n");
        return;
      } else {
        // Display an error message
        printf("This account is inactive. Please contact the administrator.\n");
        return;
      }
    }
    
    }

    // Display an error message
    printf("Invalid username or password.\n");
}

// A function to display the menu and get the user's choice
int get_choice() {
  
    // Declare a variable to store the choice
  
  
    int choice;

  
    // Display the menu options
  
  
    printf("1. Register\n");
  
    printf("2. Login\n");
  
    printf("3. Exit\n");

  
    // Prompt the user to enter a choice
  
  
    printf("Enter your choice: ");
  
    scanf("%d", &choice);

  
    // Return the choice
  
  
    return choice;
}

// The main function
int main() {

  
    // Declare a variable to store the choice
  
  
    int choice;

  
    // Repeat until the user chooses to exit
  
  
    do {
    
        // Get the user's choice from the menu
      
      
        choice = get_choice();

      
        // Perform different actions based on the choice
      
      
        switch (choice) {
        
            case 1:
            
                register_user(); // Register a new user
            
                break;
        
            case 2:
            
                login_user(); // Login an existing user
            
                break;
        
            case 3:
            
                printf("Exiting...\n"); // Exit the program
            
                break;
        
            default:
            
                printf("Invalid choice. Please try again.\n"); // Invalid choice
            
                break;
        }
      
        // Add a newline for readability
      
      
        printf("\n");

    
        } while (choice !=3);

  
    // Free the memory allocated for the array of users
  
  
    free(users);

  
    return(0);
}
