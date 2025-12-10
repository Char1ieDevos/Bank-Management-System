#include "The_Bank.h"
#include <iostream>
using namespace std;

int main() {
    vector<The_Bank> customers;
    int choice;
    int next_account_number = 1001;
    int next_loan_id = 5001;
    
    cout << "----- Welcome To The Harlington Bank! -----" << endl;
    
    // Load existing accounts
    load_all_accounts(customers, next_account_number);
    
    do {
        cout << "\n--- Main Menu ---" << endl;
        cout << "1. Open A New Bank Account" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Display Account" << endl;
        cout << "5. Display All Accounts" << endl;
        cout << "6. View Transaction History" << endl;
        cout << "7. Transfer Money Between Accounts" << endl;
        cout << "8. Calculate Interest (Savings Only)" << endl;
        cout << "9. Change PIN" << endl;
        cout << "10. Generate Bank Report" << endl;
        cout << "11. Apply for Loan" << endl;
        cout << "12. Make Loan Payment" << endl;
        cout << "13. View Loans" << endl;
        cout << "14. Setup Recurring Transaction" << endl;
        cout << "15. View Recurring Transactions" << endl;
        cout << "16. Execute Recurring Transactions" << endl;
        cout << "17. Cancel Recurring Transaction" << endl;
        cout << "18. Setup Overdraft Protection" << endl;
        cout << "19. View Overdraft Info" << endl;
        cout << "20. Save All Data" << endl;
        cout << "21. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        
        switch(choice) {
            case 1: {
                The_Bank welcome_customer;
                welcome_customer.opening_account(next_account_number);
                customers.push_back(welcome_customer);
                next_account_number++;
                break;
            }
            
            case 2: {
                if (customers.empty()) {
                    cout << "No accounts found. Please open an account first." << endl;
                    break;
                }
                int acco_num;
                cout << "Enter account number: ";
                cin >> acco_num;
                int index = find_account(customers, acco_num);
                if (index != -1) {
                    customers[index].deposit_money();
                } else {
                    cout << "Account not found!" << endl;
                }
                break;
            }
                
            case 3: {
                if (customers.empty()) {
                    cout << "No accounts exist." << endl;
                    break;
                }
                int acco_num;
                cout << "Enter account number: ";
                cin >> acco_num;
                int index = find_account(customers, acco_num);
                if (index != -1) {
                    customers[index].withdraw_money();
                } else {
                    cout << "Account not found!" << endl;
                }
                break;
            }
                
            case 4: {
                if (customers.empty()) {
                    cout << "No accounts found." << endl;
                    break;
                }
                int acco_num;
                cout << "Enter account number: ";
                cin >> acco_num;
                int index = find_account(customers, acco_num);
                if (index != -1) {
                    customers[index].display_account();
                } else {
                    cout << "Account not found!" << endl;
                }
                break;
            }
               
            case 5: {
                if (customers.empty()) {
                    cout << "No accounts exist." << endl;
                } else {
                    cout << "\n--- All Accounts ---" << endl;
                    for (int i = 0; i < customers.size(); i++) {
                        cout << "Account #" << customers[i].get_account_number()
                            << " - " << customers[i].get_name() 
                            << " ($" << customers[i].get_balance() << ")" << endl;
                    }
                    cout << "Total accounts: " << customers.size() << endl;
                }
                break;
            }
            
            case 6: {
                if (customers.empty()) {
                    cout << "No accounts exist." << endl;
                    break;
                }
                int acco_num;
                cout << "Enter account number: ";
                cin >> acco_num;
                int index = find_account(customers, acco_num);
                if (index != -1) {
                    customers[index].display_transaction_history();
                } else {
                    cout << "Account not found!" << endl;
                }
                break;
            }
            
            case 7: {
                if (customers.size() < 2) {
                    cout << "Need at least 2 accounts!" << endl;
                    break;
                }
                transfer_money(customers);
                break;
            }
            
            case 8: {
                if (customers.empty()) {
                    cout << "No accounts exist." << endl;
                    break;
                }
                int acco_num;
                cout << "Enter account number: ";
                cin >> acco_num;
                int index = find_account(customers, acco_num);
                if (index != -1) {
                    customers[index].calculate_interest();
                } else {
                    cout << "Account not found!" << endl;
                }
                break;
            }
            
            case 9: {
                if (customers.empty()) {
                    cout << "No accounts exist." << endl;
                    break;
                }
                int acco_num;
                cout << "Enter account number: ";
                cin >> acco_num;
                int index = find_account(customers, acco_num);
                if (index != -1) {
                    customers[index].change_pin();
                } else {
                    cout << "Account not found!" << endl;
                }
                break;
            }
            
            case 10: {
                generate_report(customers);
                break;
            }
            
            case 11: {
                if (customers.empty()) {
                    cout << "No accounts exist." << endl;
                    break;
                }
                int acco_num;
                cout << "Enter account number: ";
                cin >> acco_num;
                int index = find_account(customers, acco_num);
                if (index != -1) {
                    customers[index].apply_for_loan(next_loan_id);
                    next_loan_id++;
                } else {
                    cout << "Account not found!" << endl;
                }
                break;
            }
            
            case 12: {
                if (customers.empty()) {
                    cout << "No accounts exist." << endl;
                    break;
                }
                int acco_num, loan_id;
                cout << "Enter account number: ";
                cin >> acco_num;
                int index = find_account(customers, acco_num);
                if (index != -1) {
                    cout << "Enter loan ID: ";
                    cin >> loan_id;
                    customers[index].make_loan_payment(loan_id);
                } else {
                    cout << "Account not found!" << endl;
                }
                break;
            }
            
            case 13: {
                if (customers.empty()) {
                    cout << "No accounts exist." << endl;
                    break;
                }
                int acco_num;
                cout << "Enter account number: ";
                cin >> acco_num;
                int index = find_account(customers, acco_num);
                if (index != -1) {
                    customers[index].display_loans();
                } else {
                    cout << "Account not found!" << endl;
                }
                break;
            }
            
            case 14: {
                if (customers.empty()) {
                    cout << "No accounts exist." << endl;
                    break;
                }
                int acco_num;
                cout << "Enter account number: ";
                cin >> acco_num;
                int index = find_account(customers, acco_num);
                if (index != -1) {
                    customers[index].setup_recurring_transaction();
                } else {
                    cout << "Account not found!" << endl;
                }
                break;
            }
            
            case 15: {
                if (customers.empty()) {
                    cout << "No accounts exist." << endl;
                    break;
                }
                int acco_num;
                cout << "Enter account number: ";
                cin >> acco_num;
                int index = find_account(customers, acco_num);
                if (index != -1) {
                    customers[index].display_recurring_transactions();
                } else {
                    cout << "Account not found!" << endl;
                }
                break;
            }
            
            case 16: {
                if (customers.empty()) {
                    cout << "No accounts exist." << endl;
                    break;
                }
                int acco_num, day;
                cout << "Enter account number: ";
                cin >> acco_num;
                int index = find_account(customers, acco_num);
                if (index != -1) {
                    cout << "Enter day of month (1-28): ";
                    cin >> day;
                    customers[index].execute_recurring_transactions(day);
                } else {
                    cout << "Account not found!" << endl;
                }
                break;
            }
            
            case 17: {
                if (customers.empty()) {
                    cout << "No accounts exist." << endl;
                    break;
                }
                int acco_num, trans_index;
                cout << "Enter account number: ";
                cin >> acco_num;
                int index = find_account(customers, acco_num);
                if (index != -1) {
                    customers[index].display_recurring_transactions();
                    cout << "Enter transaction number to cancel: ";
                    cin >> trans_index;
                    customers[index].cancel_recurring_transaction(trans_index - 1);
                } else {
                    cout << "Account not found!" << endl;
                }
                break;
            }
            
            case 18: {
                if (customers.empty()) {
                    cout << "No accounts exist." << endl;
                    break;
                }
                int checking_acc, savings_acc;
                cout << "Enter checking account number: ";
                cin >> checking_acc;
                int checking_index = find_account(customers, checking_acc);
                
                if (checking_index == -1) {
                    cout << "Checking account not found!" << endl;
                    break;
                }
                
                cout << "Enter savings account number to link: ";
                cin >> savings_acc;
                int savings_index = find_account(customers, savings_acc);
                
                if (savings_index == -1) {
                    cout << "Savings account not found!" << endl;
                    break;
                }
                
                customers[checking_index].setup_overdraft_protection(savings_acc);
                break;
            }
            
            case 19: {
                if (customers.empty()) {
                    cout << "No accounts exist." << endl;
                    break;
                }
                int acco_num;
                cout << "Enter account number: ";
                cin >> acco_num;
                int index = find_account(customers, acco_num);
                if (index != -1) {
                    customers[index].display_overdraft_info();
                } else {
                    cout << "Account not found!" << endl;
                }
                break;
            }
            
            case 20: {
                save_all_accounts(customers);
                break;
            }
            
            case 21:
                save_all_accounts(customers);
                cout << "\nThank you for using Harlington Bank!" << endl;
                break;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 21);
    
    return 0;
}