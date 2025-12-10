# Harlington Bank Management System

## Project Overview
A comprehensive C++ banking management system with advanced features including loan management, recurring transactions, and overdraft protection.

## Author
**Your Name**  
C++ Programming Course Project  
Date: December 2025

## Features

### Core Banking Operations
- ✅ **Account Management**: Create savings and checking accounts
- ✅ **Deposits & Withdrawals**: Standard banking transactions
- ✅ **Money Transfers**: Transfer funds between accounts
- ✅ **Transaction History**: Complete audit trail of all transactions
- ✅ **Interest Calculation**: 3% annual interest for savings accounts
- ✅ **PIN Security**: 4-digit PIN authentication

### Advanced Features
- ✅ **Loan Management**: 
  - Apply for loans up to $50,000
  - Amortized payment calculations
  - Track multiple loans per account
  - Monthly loan payments with interest
  
- ✅ **Recurring Transactions**:
  - Schedule automatic monthly payments
  - Bill pay automation
  - Rent, subscriptions, etc.
  
- ✅ **Overdraft Protection**:
  - Link checking to savings account
  - Automatic transfer on insufficient funds
  - Configurable overdraft limits

### Data Persistence
- ✅ **File I/O**: Save and load all account data
- ✅ **Auto-save on exit**: Never lose data
- ✅ **Multi-account support**: Unlimited accounts

### Reporting
- ✅ **Account summaries**: View all account details
- ✅ **Bank-wide reports**: Total balances, loans, statistics
- ✅ **Transaction logs**: Complete history with timestamps

## File Structure

```
Bank-Management-System/
├── include/
│   └── The_Bank.h          # Header file with class declarations
├── src/
│   ├── The_Bank.cpp        # Class implementation
│   ├── utilities.cpp       # Helper functions
│   └── main.cpp            # Main program
├── data/
│   └── bank_data.txt       # Persistent storage (auto-generated)
├── docs/
│   └── USER_MANUAL.md      # User guide
├── README.md               # This file
├── Makefile                # Build configuration
└── .gitignore              # Git ignore rules
```

## Compilation Instructions

### Using Makefile (Recommended)
```bash
make                # Compile the program
make run            # Compile and run
make clean          # Remove compiled files
```

### Manual Compilation
```bash
# Compile all files
g++ -c src/The_Bank.cpp -o The_Bank.o
g++ -c src/utilities.cpp -o utilities.o
g++ -c src/main.cpp -o main.o

# Link
g++ The_Bank.o utilities.o main.o -o bank_system

# Run
./bank_system
```

### Windows
```bash
g++ src/The_Bank.cpp src/utilities.cpp src/main.cpp -o bank_system.exe
bank_system.exe
```

## Usage Guide

### Quick Start
1. Compile the program
2. Run `./bank_system`
3. Choose option 1 to create your first account
4. Follow the on-screen prompts

### Common Operations

**Opening an Account:**
- Select option 1 from main menu
- Enter your personal information
- Choose account type (S = Savings, C = Checking)
- Make initial deposit
- Create a 4-digit PIN

**Making a Deposit:**
- Select option 2
- Enter account number
- Enter deposit amount

**Applying for a Loan:**
- Select option 11
- Enter account number
- Specify loan amount (max $50,000)
- Enter interest rate and term
- System automatically approves/denies based on account balance

**Setting Up Recurring Transactions:**
- Select option 14
- Enter account number
- Describe the transaction (e.g., "Netflix")
- Enter amount and day of month

**Enabling Overdraft Protection:**
- Select option 18
- Enter checking account number
- Enter savings account number to link
- System automatically transfers funds when needed

## Technical Details

### Classes
- **Transaction**: Stores transaction data (type, amount, date, account)
- **Loan**: Manages loan information and calculations
- **RecurringTransaction**: Handles scheduled payments
- **The_Bank**: Main account class with all banking operations

### Data Storage Format
- Text-based file storage (`bank_data.txt`)
- Sequential record format
- Automatic backup on exit

### Error Handling
- Input validation for all user inputs
- Insufficient funds checks
- Account existence verification
- Overdraft limit enforcement

## Software Development Lifecycle

### Version Control
```bash
# Initialize repository
git init
git add .
git commit -m "Initial commit: Complete BMS with advanced features"

# Push to remote
git remote add origin <your-repo-url>
git push -u origin main
```

### Development Phases
1. **Requirements**: Basic banking operations
2. **Design**: Class structure and file organization
3. **Implementation**: Iterative feature additions
4. **Testing**: Manual testing of all features
5. **Deployment**: Final compilation and documentation

### Future Enhancements
- [ ] GUI implementation (Qt or wxWidgets)
- [ ] Database integration (SQLite)
- [ ] Multi-user support with authentication
- [ ] Network capabilities for online banking
- [ ] Credit card management
- [ ] Investment portfolio tracking

## Testing Checklist

- [ ] Create multiple accounts (savings and checking)
- [ ] Perform deposits and withdrawals
- [ ] Transfer money between accounts
- [ ] Apply for and pay off a loan
- [ ] Set up recurring transactions
- [ ] Enable overdraft protection and test
- [ ] Save data and restart program
- [ ] Verify data persistence
- [ ] Generate bank reports
- [ ] Test all edge cases (negative amounts, invalid accounts, etc.)

## Known Limitations
- Single-user application (no concurrent access)
- Plain text file storage (not encrypted)
- No network capabilities
- Command-line interface only
- Limited to 28 days for recurring transactions (avoids month-end complexity)

## License
Educational project - Free to use and modify

## Acknowledgments
- C++ Standard Library
- Course instructor and teaching assistants
- Online C++ documentation and resources

## Contact
For questions or feedback about this project, please contact [your email]

---
**Version**: 3.0  
**Last Updated**: December 2025  
**Status**: Complete and Functional