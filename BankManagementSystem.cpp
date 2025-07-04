#include <iostream> 
#include <string> 
#include <iomanip>  // For fixed and setprecision 
using namespace std; 
class BankAccount { 
private: 
    string customerName; 
    int accountNumber;
    double balance; 
    int pin; 
    string accountType; 
    bool isChildAccount;  // Flag to indicate if it's a child account 
 
public: 
    // Constructor to initialize account details 
    BankAccount(string name, int accNum, double initialBalance, int accountPin, 
string type, bool isChild = false) { 
        customerName = name; 
        accountNumber = accNum; 
        balance = initialBalance; 
        pin = accountPin; 
        accountType = type; 
        isChildAccount = isChild; 
    } 
 
    // Function to check if the PIN is correct 
    bool verifyPin(int enteredPin) { 
        return pin == enteredPin; 
    } 
 
    // Function to deposit money into the account 
    void deposit(double amount) { 
        if (amount > 0) { 
            balance += amount; 
            cout << "Deposited " << amount << ". New balance: " << fixed << 
setprecision(0) << balance << endl; 
        } else { 
            cout << "Deposit amount must be positive." << endl; 
        } 
    } 
 
    // Function to withdraw money from the account 
    void withdraw(double amount) { 
        if (amount > 0 && amount <= balance) { 
            balance -= amount; 
            cout << "Withdrew " << amount << ". New balance: " << fixed << 
setprecision(0) << balance << endl; 
        } else if (amount > balance) { 
            cout << "Insufficient balance." << endl; 
        } else { 
            cout << "Invalid withdrawal amount." << endl; 
        } 
    } 
 
    // Function to check the balance 
    void checkBalance() { 
        cout << "Balance: " << fixed << setprecision(0) << balance << endl; 
    } 
 
    // Function to display customer details 
    void displayCustomerDetails() { 
        cout << "Customer Name: " << customerName << endl; 
        cout << "Account Number: " << accountNumber << endl; 
        cout << "Account Type: " << accountType << endl; 
        cout << "Balance: " << fixed << setprecision(0) << balance << endl; 
    } 
 
    // Function to calculate interest based on account type 
    void calculateInterest() { 
        double interestRate = 0; 
        if (accountType == "Saving") { 
            interestRate = 0.04; // 4% interest for saving accounts 
        } else if (accountType == "Current") { 
            interestRate = 0.02; // 2% interest for current accounts 
        } else { 
            cout << "Unknown account type!" << endl; 
            return; 
        } 
 
        double interest = balance * interestRate; 
        cout << "Interest calculated for " << accountType << " account: " << fixed << 
setprecision(0) << interest << endl; 
        balance += interest;  // Add interest to balance 
        cout << "New balance after interest: " << fixed << setprecision(0) << balance 
<< endl; 
    } 
 
    // Function to calculate tax based on balance 
    void calculateTax() { 
        if (balance > 1200000 && !isChildAccount) {  // Non-child account: Balance is 
over 12 lakhs 
            double tax = 0; 
 
            // Apply progressive tax based on balance for non-child accounts 
            if (balance <= 2500000) { 
                tax = balance * 0.05;  // 5% tax for balances between 12 lakhs and 25 
lakhs 
            } else if (balance <= 5000000) { 
                tax = balance * 0.10;  // 10% tax for balances between 25 lakhs and 50 
lakhs 
            } else { 
                tax = balance * 0.15;  // 15% tax for balances over 50 lakhs 
            } 
 
            cout << "Tax calculated for non-child account: " << fixed << setprecision(0) 
<< tax << endl; 
            balance -= tax;  // Deduct tax from balance 
            cout << "New balance after tax deduction: " << fixed << setprecision(0) << 
balance << endl; 
        } 
        else if (isChildAccount && balance > 1800000) {  // Child account: Balance is 
over 18 lakhs 
            double tax = 0; 
 
            // Apply progressive tax based on balance for child accounts 
            if (balance <= 2500000) { 
                tax = balance * 0.05;  // 5% tax for balances between 18 lakhs and 25 
lakhs 
            } else if (balance <= 5000000) { 
                tax = balance * 0.10;  // 10% tax for balances between 25 lakhs and 50 
lakhs 
            } else { 
                tax = balance * 0.15;  // 15% tax for balances over 50 lakhs 
            } 
 
            cout << "Tax calculated for child account: " << fixed << setprecision(0) << 
tax << endl; 
            balance -= tax;  // Deduct tax from balance 
            cout << "New balance after tax deduction: " << fixed << setprecision(0) << 
balance << endl; 
        } 
        else { 
            cout << "No tax for balance less than 12 lakhs for non-child or 18 lakhs for 
child accounts." << endl; 
        } 
    } 
}; 
 
// Function to determine if the account should be a child account based on the 
age 
bool isChildAccountBasedOnAge(int age) { 
    return age < 18; // Consider as a child account if age is less than 18 
} 
 
int main() { 
    string name; 
    int accNum, pin, age; 
    double initialBalance; 
    string accountType; 
    bool isChild; 
 
    // Get customer details 
    cout << "Enter Customer Name: "; 
    getline(cin, name); 
    cout << "Enter Account Number: "; 
    cin >> accNum; 
    cout << "Enter Initial Balance: "; 
    cin >> initialBalance; 
    cout << "Enter PIN (4 digits): "; 
    cin >> pin; 
    cout << "Enter Age: "; 
    cin >> age; 
 
    // Determine if the account should be a child account 
    isChild = isChildAccountBasedOnAge(age); 
 
    // Set account type based on the child status 
    if (isChild) { 
        accountType = "Child Account"; 
    } else { 
        cout << "Enter Account Type (Saving/Current): "; 
        cin >> accountType; 
    } 
 
    // Create an account object 
    BankAccount account(name, accNum, initialBalance, pin, accountType, isChild); 
 
    int choice; 
    do { 
        int enteredPin; 
        cout << "\nEnter your PIN to continue: "; 
        cin >> enteredPin; 
 
        // Verify the PIN 
        if (!account.verifyPin(enteredPin)) { 
            cout << "Incorrect PIN. Please try again." << endl; 
            continue; 
        } 
 
        cout << "\nBank Management System" << endl; 
        cout << "1. Deposit" << endl; 
        cout << "2. Withdraw" << endl; 
        cout << "3. Check Balance" << endl; 
        cout << "4. Display Account Details" << endl; 
        cout << "5. Calculate Interest" << endl; 
        cout << "6. Calculate Tax" << endl;  // Option for tax calculation 
        cout << "7. Exit" << endl; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        switch (choice) { 
        case 1: 
            double depositAmount; 
            cout << "Enter deposit amount: "; 
            cin >> depositAmount; 
            account.deposit(depositAmount); 
            break; 
        case 2: 
            double withdrawAmount; 
            cout << "Enter withdrawal amount: "; 
            cin >> withdrawAmount; 
            account.withdraw(withdrawAmount); 
            break; 
        case 3: 
            account.checkBalance(); 
            break; 
        case 4: 
            account.displayCustomerDetails(); 
            break; 
        case 5: 
            account.calculateInterest(); 
            break; 
        case 6: 
            account.calculateTax();  // Using calculateTax instead of calculateGST 
            break; 
        case 7: 
            cout << "Exiting system." << endl; 
            break; 
        default: 
            cout << "Invalid choice! Please try again." << endl; 
        } 
    } while (choice != 7); 
 
    return 0; 
}
