#ifndef THE_BANK_H
#define THE_BANK_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// Transaction class to track account activity
class Transaction {
public:
    string type;
    float amount;
    string date;
    int account_number;
    
    Transaction(string t, float a, string d, int acc);
};

// Loan class to manage loans
class Loan {
public:
    int loan_id;
    float principal;
    float interest_rate;
    float remaining_balance;
    int months_remaining;
    float monthly_payment;
    string start_date;
    bool is_active;
    
    Loan(int id, float p, float rate, int months, string date);
    float calculate_monthly_payment();
};

// Recurring Transaction class for scheduled payments
class RecurringTransaction {
public:
    string description;
    float amount;
    string frequency;
    int day_of_execution;
    bool is_active;
    
    RecurringTransaction(string desc, float amt, string freq, int day);
};

// Main Bank Account Class
class The_Bank {
private:
    string name_person, Location;
    char account_type;
    float balance_amount;
    int account_number;
    string pin;
    vector<Transaction> transaction_history;
    vector<Loan> loans;
    vector<RecurringTransaction> recurring_transactions;
    int overdraft_linked_account;
    bool overdraft_enabled;
    float overdraft_limit;
    
public:
    // Constructor
    The_Bank();
    
    // Basic account operations
    void opening_account(int acc_num);
    void deposit_money();
    void display_account();
    void withdraw_money();
    void change_pin();
    bool verify_pin(string entered_pin);
    void display_transaction_history();
    void calculate_interest();
    
    // Getters
    float get_balance();
    int get_account_number();
    string get_name();
    char get_account_type();
    
    // Transfer functions
    bool transfer_out(float amount, int to_account);
    void transfer_in(float amount, int from_account);
    
    // Loan functions
    void apply_for_loan(int loan_id);
    void make_loan_payment(int loan_id);
    void display_loans();
    float get_total_debt();
    
    // Recurring transaction functions
    void setup_recurring_transaction();
    void display_recurring_transactions();
    void execute_recurring_transactions(int current_day);
    void cancel_recurring_transaction(int index);
    
    // Overdraft protection functions
    void setup_overdraft_protection(int linked_account);
    void disable_overdraft_protection();
    bool process_overdraft(float amount, The_Bank& linked_account);
    void display_overdraft_info();
    
    // File operations
    void save_to_file(ofstream& outfile);
    void load_from_file(ifstream& infile);
};

// Utility function prototypes
string get_current_datetime();
int get_current_day();
int find_account(vector<The_Bank>& accounts, int acco_num);
void transfer_money(vector<The_Bank>& accounts);
void save_all_accounts(vector<The_Bank>& accounts);
void load_all_accounts(vector<The_Bank>& accounts, int& next_account_number);
void generate_report(vector<The_Bank>& accounts);

#endif