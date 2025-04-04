#ifndef TRANSACTION_H
#define TRANSACTION_H

struct Transaction
{
  int transaction_id;
  int sender_id;
  int receiver_id;
  float amount;
  char date[20];
};

int send_money(int sender_id, int receiver_id, float amount);
void record_transaction(struct Transaction transaction);
void display_transaction_history(int user_id);

#endif
