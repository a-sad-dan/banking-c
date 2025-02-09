#ifndef USER_H
#define USER_H

struct User
{
  int user_id;
  char user_name[50];
  char password[50];
  float balance;
};

int create_user(struct User new_user);
int login_user(char *username, char *password);
void logout_user();
struct User *find_user_by_id(int user_id);
struct User *find_user_by_username(char *username);

float find_balance_by_username(char *username);
int find_user_id_by_username(char *username);
int validate_receiver_id(int receiver_id);

#endif // USER_H