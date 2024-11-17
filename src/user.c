#include <user.h>

int create_user(struct User new_user);
int login_user(char *username, char *password);
void logout_user();
struct User *find_user_by_id(int user_id);