#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generate_unique_user_id()
{
    srand(time(NULL));
    int random_part = rand();
    time_t time_part = time(NULL);
    int unique_id = (time_part << 16) | (random_part & 0xFFFF);
    unique_id &= 0x7FFFFFFF; // ensures that the highest bit is 0 for positive numbers
    return unique_id;
}

void display_error(char *error_message)
{
    printf("\033[31mError: %s\033[0m\n", error_message);
}

void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n')
        ;
}

int generate_unique_transaction_id()
{
    srand(time(NULL));
    int random_part = rand();
    time_t time_part = time(NULL);
    int unique_id = (time_part << 16) | (random_part & 0xFFFFF);
    unique_id &= 0x7FFFFFFF; // ensures that the highest bit is 0 for positive numbers
    return unique_id;
}
char *get_current_date()
{
    time_t now = time(NULL);
    struct tm *timeinfo = localtime(&now);
    static char date[20];
    strftime(date, sizeof(date), "%Y-%m-%d", timeinfo);
    return date;
}