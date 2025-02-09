#include <transaction.h>
#include <utils.h>
#include <stdio.h>
#include <user.h>

int send_money(int sender_id, int receiver_id, float amount)
{
  if (sender_id == receiver_id)
  {
    display_error("You cannot send money to yourself!\n");
    return 0;
  }

  // Check if enough money is present
  float sender_balance = find_user_by_id(sender_id)->balance;
  if (sender_balance < amount)
  {
    display_error("Insufficient sender_balance!\n");
    return 0;
  }

  char *receiver_name = find_user_by_id(receiver_id)->user_name;
  printf("Sending %.2f to %s\n", amount, receiver_name);
  printf("Press Y to confirm the transaction\n");
  char choice;
  scanf("%c", &choice);
  if (choice != 'Y' && choice != 'y')
  {
    display_error("Transaction cancelled\n");
    return 0;
  }

  // Deduct amount from sender
  sender_balance -= amount;

  FILE *sender_file = fopen("./data/users.dat", "rb+");
  if (sender_file == NULL)
  {
    display_error("Error opening file\n");
    return 0;
  }

  struct User user;
  while (fread(&user, sizeof(struct User), 1, sender_file) == 1)
  {
    if (user.user_id == sender_id)
    {
      user.balance = sender_balance;
      fseek(sender_file, -sizeof(struct User), SEEK_CUR);
      fwrite(&user, sizeof(struct User), 1, sender_file);
      printf("%.2f has been deducted from your account\nYour current balance is %.2f\n", amount, user.balance);
      break;
    }
  }
  fclose(sender_file);

  // Add amount to receiver
  float receiver_balance = find_user_by_id(receiver_id)->balance;
  receiver_balance += amount;
  FILE *receiver_file = fopen("./data/users.dat", "rb+");
  if (receiver_file == NULL)
  {
    display_error("Error opening file\n");
    return 0;
  }

  while (fread(&user, sizeof(struct User), 1, receiver_file) == 1)
  {
    if (user.user_id == receiver_id)
    {
      user.balance = receiver_balance;
      fseek(receiver_file, -sizeof(struct User), SEEK_CUR);
      fwrite(&user, sizeof(struct User), 1, receiver_file);
      break;
    }
  }
  fclose(receiver_file);

  return 1;
}

void record_transaction(struct Transaction transaction)
{
  // Open transaction File
  FILE *file = fopen("./data/transactions.dat", "ab+");
  if (file == NULL)
  {
    display_error("Error opening file\n");
  }

  fwrite(&transaction, sizeof(struct Transaction), 1, file);
  fclose(file);
}

void display_transaction_history(int user_id)
{
  FILE *file = fopen("./data/transactions.dat", "rb");
  if (file == NULL)
  {
    display_error("Error opening file\n");
    return;
  }

  struct Transaction transaction;
  while (fread(&transaction, sizeof(struct Transaction), 1, file) == 1)
  {
    if (transaction.sender_id == user_id || transaction.receiver_id == user_id)
    {
      printf("Transaction ID: %d\t", transaction.transaction_id);
      printf("Date: %s\n", transaction.date);
      printf("Sender ID: %d \t Sender Name: %s\n", transaction.sender_id, transaction.sender_id == user_id ? "You" : find_user_by_id(transaction.sender_id)->user_name);
      printf("Receiver ID: %d\t Receiver Name: %s\n", transaction.receiver_id, transaction.receiver_id == user_id ? "You" : find_user_by_id(transaction.receiver_id)->user_name);
      printf("Amount: %.2f\n", transaction.amount);
      printf("\n");
    }
  }
}