#include "The_Bank.h"
#include <iomanip>
using namespace std;

// Helper function to find account by account number
int find_account(vector<The_Bank>& accounts, int acco_num) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].get_account_number() == acco_num) {
            return i;
        }
    }
    return -1;
}

// Transfer money between accounts with overdraft protection
void transfer_money(vector<The_Bank>& accounts) {
    int from_acc, to_acc;
    float amount;
    
    cout << "\n=== Transfer Money ===" << endl;
    cout << "Enter your account number: ";
    cin >> from_acc;
    
    int from_index = find_account(accounts, from_acc);
    if (from_index == -1) {
        cout << "Source account not found!" << endl;
        return;
    }
    
    cout << "Enter destination account number: ";
    cin >> to_acc;
    
    int to_index = find_account(accounts, to_acc);
    if (to_index == -1) {
        cout << "Destination account not found!" << endl;
        return;
    }
    
    if (from_acc == to_acc) {
        cout << "Cannot transfer to the same account!" << endl;
        return;
    }
    
    cout << "Enter amount to transfer: $";
    cin >> amount;
    
    // Check if regular transfer works
    if (accounts[from_index].transfer_out(amount, to_acc)) {
        accounts[to_index].transfer_in(amount, from_acc);
        cout << "Transfer successful!" << endl;
        cout << "New balance: $" << fixed << setprecision(2) << accounts[from_index].get_balance() << endl;
    } else {
        // Try overdraft protection
        cout << "Insufficient funds for direct transfer." << endl;
        cout << "Attempting overdraft protection..." << endl;
        
        if (accounts[from_index].process_overdraft(amount, accounts[to_index])) {
            // Now try transfer again
            if (accounts[from_index].transfer_out(amount, to_acc)) {
                accounts[to_index].transfer_in(amount, from_acc);
                cout << "Transfer completed with overdraft protection!" << endl;
            }
        } else {
            cout << "Transfer failed! Insufficient funds." << endl;
        }
    }
}

// Save all accounts to file
void save_all_accounts(vector<The_Bank>& accounts) {
    ofstream outfile("bank_data.txt");
    
    if (!outfile) {
        cout << "Error: Could not create save file!" << endl;
        return;
    }
    
    outfile << accounts.size() << endl;
    
    for (int i = 0; i < accounts.size(); i++) {
        accounts[i].save_to_file(outfile);
    }
    
    outfile.close();
    cout << "All accounts saved successfully!" << endl;
}

// Load all accounts from file
void load_all_accounts(vector<The_Bank>& accounts, int& next_account_number) {
    ifstream infile("bank_data.txt");
    
    if (!infile) {
        cout << "No previous data found. Starting fresh." << endl;
        return;
    }
    
    int account_count;
    infile >> account_count;
    infile.ignore();
    
    for (int i = 0; i < account_count; i++) {
        The_Bank temp_account;
        temp_account.load_from_file(infile);
        accounts.push_back(temp_account);
        
        if (temp_account.get_account_number() >= next_account_number) {
            next_account_number = temp_account.get_account_number() + 1;
        }
    }
    
    infile.close();
    cout << "Loaded " << account_count << " accounts from file." << endl;
}

// Generate account summary report
void generate_report(vector<The_Bank>& accounts) {
    cout << "\n========== BANK SUMMARY REPORT ==========" << endl;
    cout << "Total Accounts: " << accounts.size() << endl;
    
    float total_balance = 0;
    float total_debt = 0;
    int savings_count = 0, checking_count = 0;
    
    for (int i = 0; i < accounts.size(); i++) {
        total_balance += accounts[i].get_balance();
        total_debt += accounts[i].get_total_debt();
        if (accounts[i].get_account_type() == 'S') {
            savings_count++;
        } else {
            checking_count++;
        }
    }
    
    cout << "Savings Accounts: " << savings_count << endl;
    cout << "Checking Accounts: " << checking_count << endl;
    cout << "Total Balance Across All Accounts: $" << fixed << setprecision(2) << total_balance << endl;
    cout << "Total Outstanding Loans: $" << fixed << setprecision(2) << total_debt << endl;
    cout << "Net Bank Position: $" << fixed << setprecision(2) << (total_balance - total_debt) << endl;
    cout << "=========================================\n" << endl;
}