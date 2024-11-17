#include<transaction.h>

int send_money(int sender_id, int receiver_id, float amount);
void record_transaction(struct Transaction transcation);
void display_transaction_history(int user_id);
