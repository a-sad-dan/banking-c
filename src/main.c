#include <stdio.h>
#include <stdbool.h>

#include <user.h>
#include <transaction.h>
#include <file_ops.h>
#include <utils.h>

void display_menu();
void handle_login();
void handle_logout();
void handle_user_creation();
void handle_transaction();
void logout_user();

bool isLoggedIn = false;

int main()
{
  display_menu();
  return 0;
};

void display_menu()
{
  int choice;
  do
  {
    printf("\n===== Banking System Menu =====\n");
    printf("1. Create User\n");
    printf("2. Login\n");
    printf("3. Logout\n");
    printf("4. Make a Transaction\n");
    printf("0. Exit\n");
    printf("================================\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Clear input buffer to avoid issues with leftover input
    clear_input_buffer();

    switch (choice)
    {
    case 0:
      printf("Exiting the program.\n");
      break;
    case 1:
      handle_user_creation();
      break;
    case 2:
      if (!isLoggedIn)
      {
        handle_login();
      }
      else
      {
        printf("You are already logged in.\n");
      }
      break;
    case 3:
      handle_logout();
      break;
    case 4:
      if (isLoggedIn)
      {
        handle_transaction();
      }
      else
      {
        printf("Error: Please log in to make a transaction.\n");
      }
      break;

    default:
      printf("Invalid choice. Please try again.\n\n\n");
    }
  } while (choice != 0);
}

void handle_logout()
{
  if (isLoggedIn)
  {
    logout_user();
    printf("Successfully logged out.\n");
  }
  else
  {
    display_error("You must be logged in to log out!");
  }
}

void handle_user_creation()
{
  struct User u;
  printf("Enter a username.\t ");

  scanf("%[^\n]", u.user_name);
  clear_input_buffer();

  // Do username validation - cannot be duplicate

  // todo make a new util function to take passwords and validate them
  printf("Enter your password. \t");
  scanf("%[^\n]", u.password);
  clear_input_buffer();

  u.balance = 10000;
  u.user_id = generate_unique_user_id();
  int status = create_user(u);
  status ? printf("User created successfully!\n") : printf("Error creating user!\n");
}

void handle_transaction()
{
  struct Transaction t = {0};
  // amount, sender id , rec id, trans id

  printf("Enter receiver Id. \t");
  scanf("%d", &t.receiver_id);
  clear_input_buffer();
  // validate_receiver_id();
  // send_money();
  // record_transaction()
}

void handle_login()
{
  char u_name[50];
  char pass[50];
  printf("Enter your username. \t");
  scanf("%s", u_name);
  clear_input_buffer();
  printf("Enter your password. \t");
  scanf("%s", pass);
  clear_input_buffer();

  printf("Logging in %s\n", u_name);
  int flag = login_user(u_name, pass);

  if (flag)
  {
    isLoggedIn = true;
  }
}

void logout_user()
{
  isLoggedIn = false;
}