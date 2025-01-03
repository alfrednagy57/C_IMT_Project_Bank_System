# Bank System Project

## Overview
The **Bank System Project** is a C-based application that manages bank account operations. It includes functionalities for managing accounts, executing transactions, and interacting with a graphical interface.

## Project Structure

### App Directory
- **Main.c**: The entry point of the application, which initializes and orchestrates the program.

### Headers Directory
Contains header files that define the structures and functions used in the project:
- **BankAcc.h**: Manages bank account structures and related operations.
- **Fncs.h**: Declares utility functions for the application.
- **MainWin.h**: Contains definitions related to the graphical interface or main window.
- **STD_TYPES.h**: Defines standard types and macros.

### Sources Directory
Contains the implementation of the project logic:
- **Fncs.c**: Implements utility functions.
- **MainWin.c**: Implements graphical interface or window-related logic.

## Compilation and Usage

### Prerequisites
- A C compiler (e.g., GCC).
- An environment to run C programs (e.g., Linux terminal, Code::Blocks, or an IDE like Eclipse).

### Steps to Compile
1. Navigate to the project directory.
2. Compile the source files using the following command:
   ```bash
   gcc -o BankSystem App/Main.c Sources/Fncs.c Sources/MainWin.c -I Headers
   ```
3. Run the executable:
   ```bash
   ./BankSystem
   ```

## Features
- **Account Management**: Create, update, and manage bank accounts.
- **Transaction Handling**: Execute deposits, withdrawals, and transfers.
- **Graphical Interface**: Interact with the system through a GUI.

## License
This project is licensed under the MIT License. See the LICENSE file for details.

## Contributing
Contributions are welcome! Please fork the repository and submit a pull request with your improvements or fixes.

## Contact

For any inquiries, please contact the project maintainer at [linkedin](https://www.linkedin.com/in/alfred-nagy-882445224/).

