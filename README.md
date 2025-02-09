
# Banking System in C

This is a simple banking system implemented in C. The system allows users to create accounts, log in, send money, and view transaction histories. Data is persistently stored in files, ensuring information is retained between program executions.

## User Story

Upon launching the application, the user is greeted with a menu with three options:

1. **Create User**
2. **Login**
3. **Exit** (Exit the program)

### Create User
- This flow is working as intended.

### Login
- The user enters their username and password.
- Upon successful login, the user is greeted with a welcome menu with four options:

  4. **Logout**
  5. **Make a Transaction**
  6. **View Balance**
  7. **Exit** (Exit the program)

## Sample Accounts
Delete the users.dat to remove the accounts.
All the accounts get started with the default of 10,000 as balance.

| Account Name   | Password    | User ID   |
| -------------- | ----------- | --------- |
| danishasad     | danish123   | 543240203 |
| akramkhan      | akram29     | 545961583 |
| vaibhav_mishra | pine_2025   | 550216902 |
| devansh        | struct@algo | 554963052 |
| anurag-sharma  | tallGuy@123 | 559513305 |


## Features
- **User Management**:
  - Create a new account.
  - Secure login with passwords.
  - Logout functionality.
- **Banking Transactions**:
  - Transfer money between accounts.
  - View transaction history.
- **File Storage**:
  - Persistent user and transaction data storage.
  - Uses `users.dat` for user information and `transactions.dat` for transaction records.

## Project Structure

```
banking_system/
├── src/               # Source code
│   ├── main.c         # Entry point
│   ├── user.c         # User-related operations
│   ├── transaction.c  # Money transfer and transaction history
│   ├── file_ops.c     # File input/output operations
│   └── utils.c        # Utility functions
├── include/           # Header files
│   ├── user.h
│   ├── transaction.h
│   ├── file_ops.h
│   └── utils.h
├── data/              # Persistent storage
│   ├── users.dat      # User data file
│   └── transactions.dat # Transaction records file
├── Makefile           # Build script
└── README.md          # Project documentation
```

## Requirements
- **Compiler**: GCC or any C compiler.
- **Operating System**: Linux, macOS, or Windows.

## How to Compile and Run
1. Clone the repository:
   ```bash
   git clone <repository_url>
   cd banking_system
   ```
2. Compile the project:
   ```bash
   make all
   ```
3. Run the program:
   ```bash
   make run
   ```
4. Clean build files:
   ```bash
   make clean
   ```

## Usage
1. **Create Account**:
   - Enter a unique username and password.
   - Start with an initial balance.

2. **Login**:
   - Log in using your username and password.

3. **Send Money**:
   - Enter the recipient's user ID and the amount to transfer.

4. **Transaction History**:
   - View all past transactions for your account.

5. **Logout**:
   - Safely exit the session.

## File Details
- **`users.dat`**:
  - Stores user records in binary format.
  - Fields: `user_id`, `username`, `password`, `balance`.

- **`transactions.dat`**:
  - Logs all transactions in binary format.
  - Fields: `transaction_id`, `sender_id`, `receiver_id`, `amount`, `date`.

## Contributing
1. Fork the repository.
2. Create a new feature branch:
   ```bash
   git checkout -b feature/your-feature-name
   ```
3. Commit your changes:
   ```bash
   git commit -m "Add your feature"
   ```
4. Push to the branch:
   ```bash
   git push origin feature/your-feature-name
   ```
5. Submit a pull request.

## License
This project is licensed under the MIT License.

## Contact
- **Author**: a-sad-dan
- **Email**: danishasad91@gmail.com

Feel free to report bugs or suggest features!
