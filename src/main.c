#include <stdio.h>
#include <stdbool.h>

#include <user.h>
#include <transaction.h>
#include <file_ops.h>
#include <utils.h>
#include <string.h>

void display_menu();
void handle_login();
void handle_logout();
void handle_user_creation();
void handle_transaction();
void logout_user();

bool isLoggedIn = false;
char current_user[50] = "";

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
    if (!isLoggedIn)
    {
      printf("\n===== Banking System Menu =====\n");
      printf("\033[1m1.\033[0m Create User\n");
      printf("\033[1m2.\033[0m Login\n");
    }
    if (isLoggedIn)
    {
      printf("\n\033[34m===== Welcome %s =====\033[0m\n", current_user);
      printf("\033[1m3.\033[0m Logout\n");
      printf("\033[1m4.\033[0m Make a Transaction\n");
      printf("\033[1m5.\033[0m View Balance\n");
      printf("\033[1m6.\033[0m View Transaction History\n");
    }
    printf("\033[31m\033[1m0.\033[0m Exit\033[0m\n");
    printf("================================\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Clear input buffer to avoid issues with leftover input
    clear_input_buffer();

    switch (choice)
    {
    case 0:
      printf("\033[34m\nGoodbye!.\033[0m\n\n");
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
    case 5:
      if (isLoggedIn)
      {
        float bal = find_balance_by_username(current_user);
        printf("Your balance is: \033[1m%.2f\033[0m\n", bal);
      }
      else
      {
        printf("Error: Please log in to view your balance.\n");
      }
      break;
    case 6:
      if (isLoggedIn)
      {
        display_transaction_history(find_user_id_by_username(current_user));
      }
      else
      {
        printf("Error: Please log in to view your transaction history.\n");
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
  if (status)
  {
    printf("\n\033[32mUser created successfully!\033[0m\n");
    printf("\033[34mUser ID: \033[1m%d\033[0m\033[0m\n", u.user_id);
  }
  else
  {
    printf("Error creating user!\n");
  }
}

void handle_transaction()
{
  // Take the receiver id
  int receiver_id;
  printf("Enter the receiver id.\t");
  scanf("%d", &receiver_id);
  clear_input_buffer();

  // Take the amount
  float amount;
  printf("Enter the amount.\t");
  scanf("%f", &amount);
  clear_input_buffer();

  int status = send_money(find_user_id_by_username(current_user), receiver_id, amount);

  if (status)
  {
    printf("\033[32mTransaction successful!\033[0m\n");
    // record the transaction
    struct Transaction transaction;
    transaction.transaction_id = generate_unique_transaction_id();
    transaction.sender_id = find_user_id_by_username(current_user);
    transaction.receiver_id = receiver_id;
    transaction.amount = amount;
    transaction.date[0] = '\0'; // Initialize date to an empty string
    strcpy(transaction.date, get_current_date());
    record_transaction(transaction);
  }
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

  printf("\nLogging in %s\n", u_name);
  int flag = login_user(u_name, pass);

  if (flag)
  {
    // Save current user detail
    strcpy(current_user, u_name);
    isLoggedIn = true;
  }
}

void logout_user()
{
  isLoggedIn = false;
  printf("%s logged out.\n", current_user);
  strcpy(current_user, "");
}