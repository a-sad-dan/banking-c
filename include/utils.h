#ifndef UTILS_H
#define UTILS_H
#include <transaction.h>

int generate_unique_user_id();
int generate_unique_transaction_id();
int validate_username(char *username);
int *hash_password(char *password);
void display_error(char *error_message);
void clear_input_buffer();
char *get_current_date();

#endif
