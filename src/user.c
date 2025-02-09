#include <user.h>
#include <file_ops.h>
#include <transaction.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <utils.h>

int create_user(struct User new_user);
int login_user(char *username, char *password)
{
  // open the user.dat file
  FILE *file = fopen("./data/users.dat", "rb");
  if (file == NULL)
  {
    printf("Error opening file\n");
    return 0;
  }

  struct User user;
  while (fread(&user, sizeof(struct User), 1, file) == 1)
  {
    if (strcmp(username, user.user_name) == 0 && strcmp(password, user.password) == 0)
    {
      printf("\033[32mLogin successful\033[0m\n");
      return 1;
    }
  }
  display_error("Invalid username or password.\n");
  return 0;
}

int create_user(struct User new_user)
{
  int status = write_user_to_file(new_user);
  return !status;
}

struct User *find_user_by_username(char *username)
{
  FILE *file = fopen("./data/users.dat", "rb");
  if (file == NULL)
  {
    printf("Error opening file\n");
    return NULL;
  }

  struct User *user = malloc(sizeof(struct User));
  if (user == NULL)
  {
    printf("Error allocating memory\n");
    fclose(file);
    return NULL;
  }

  while (fread(user, sizeof(struct User), 1, file) == 1)
  {
    if (strcmp(username, user->user_name) == 0)
    {
      fclose(file);
      return user;
    }
  }

  free(user);
  fclose(file);
  return NULL;
}

struct User *find_user_by_id(int user_id)
{
  FILE *file = fopen("./data/users.dat", "rb");
  if (file == NULL)
  {
    printf("Error opening file\n");
    return NULL;
  }

  struct User *user = malloc(sizeof(struct User));
  if (user == NULL)
  {
    printf("Error allocating memory\n");
    fclose(file);
    return NULL;
  }

  while (fread(user, sizeof(struct User), 1, file) == 1)
  {
    if (user->user_id == user_id)
    {
      fclose(file);
      return user;
    }
  }
  return NULL;
}

float find_balance_by_username(char *username)
{
  FILE *file = fopen("./data/users.dat", "rb");
  if (file == NULL)
  {
    display_error("Error opening file\n");
    return 0;
  }

  struct User user;
  while (fread(&user, sizeof(struct User), 1, file) == 1)
  {
    if (strcmp(username, user.user_name) == 0)
    {
      return user.balance;
    }
  }
  return 0;
}

int find_user_id_by_username(char *username)
{
  FILE *file = fopen("./data/users.dat", "rb");
  if (file == NULL)
  {
    printf("Error opening file\n");
    return 0;
  }

  // Traverse the opened file to find the user with the given username
  struct User user;
  while (fread(&user, sizeof(struct User), 1, file) == 1)
  {
    if (strcmp(username, user.user_name) == 0)
    {
      fclose(file);
      return user.user_id;
    }
  }
  return 0;
}