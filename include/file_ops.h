// Write
int write_user_to_file(struct User user);
int write_transaction_to_file(struct Transaction *transaction);

// Read
struct User *read_users_from_file();
struct Transaction *read_transactions_from_file();

// Update
int update_user_in_file(struct User *user);
