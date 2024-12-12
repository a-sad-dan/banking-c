int generate_unique_user_id();
int validate_username(char *username);
int *hash_password(char *password);
void display_error(char *error_message);
void clear_input_buffer();

#include <stdio.h>

int generate_unique_user_id()
{
    return 1234567; // todo generate a unique id
}


void display_error(char *error_message)
{
    printf("Error: %s\n", error_message);
}

void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n')
        ;
}