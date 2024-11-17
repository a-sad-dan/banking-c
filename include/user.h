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