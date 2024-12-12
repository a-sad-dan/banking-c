#include <user.h>
#include "file_ops.h"

int create_user(struct User new_user);
int login_user(char *username, char *password)
{
  return 0;
};
struct User *find_user_by_id(int user_id);

int create_user(struct User new_user)
{
  int status = write_user_to_file(new_user);
  return !status;
}
