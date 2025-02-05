#include <user.h>
#include <file_ops.h>
#include <transaction.h>
#include <stdio.h>
#include <string.h>

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
      printf("Login successful\n");
      return 1;
    }
  }
  printf("Login failed\nPlease try again");
  return 0;
}

int create_user(struct User new_user)
{
  int status = write_user_to_file(new_user);
  return !status;
}
