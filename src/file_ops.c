#include <user.h>
#include <stdio.h>
#include <transaction.h>

// Write
int write_user_to_file(struct User user);
int write_transaction_to_file(struct Transaction transaction);

// Read
struct User *read_users_from_file();
struct Transaction *read_transactions_from_file();

// Update
int update_user_in_file(struct User *user);

int write_user_to_file(struct User user)
{
  FILE *file = fopen("./data/users.dat", "ab+");

  if (file == NULL)
  {
    printf("Error opening file\n");
    return 1;
  }

  fwrite(&user, sizeof(struct User), 1, file);
  fclose(file);

  return 0;
}

int write_transaction_to_file(struct Transaction transaction)
{
  FILE *file = fopen("./data/transactions.dat", "ab+");

  if (file == NULL)
  {
    printf("Error opening file\n");
    return 1;
  }

  fwrite(&transaction, sizeof(struct Transaction), 1, file);
  fclose(file);
  return 0;
};
