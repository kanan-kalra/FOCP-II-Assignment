#include <iostream>
#include <string>
using namespace std;

// Parallel arrays to store user IDs and their balances
string userIds[1000];
int balances[1000];
int totalUsers = 0;  // keeps track of how many users exist

// Helper function to find the index of a user (-1 if not found)
int findUser(string id) {
    for (int i = 0; i < totalUsers; i++) {
        if (userIds[i] == id) {
            return i;  // return the position where user is found
        }
    }
    return -1;  // user not found
}

bool createAccount(string id, int amount) {
    int index = findUser(id);
    if (index == -1) {
        // User does NOT exist, create new account
        userIds[totalUsers] = id;
        balances[totalUsers] = amount;
        totalUsers++;
        return true;
    } else {
        // User already exists, just add money
        balances[index] += amount;
        return false;
    }
}

bool debit(string id, int amount) {
    int index = findUser(id);
    if (index == -1 || balances[index] < amount) {
        // User not found OR not enough balance
        return false;
    }
    balances[index] -= amount;
    return true;
}

bool credit(string id, int amount) {
    int index = findUser(id);
    if (index == -1) {
        // User not found
        return false;
    }
    balances[index] += amount;
    return true;
}

int getBalance(string id) {
    int index = findUser(id);
    if (index == -1) {
        return -1;  // User not found
    }
    return balances[index];
}

int main() {
    int q;
    cin >> q;

    while (q--) {
        string query;
        cin >> query;

        if (query == "CREATE") {
            string id;
            int amount;
            cin >> id >> amount;
            cout << (createAccount(id, amount) ? "true" : "false") << "\n";

        } else if (query == "DEBIT") {
            string id;
            int amount;
            cin >> id >> amount;
            cout << (debit(id, amount) ? "true" : "false") << "\n";

        } else if (query == "CREDIT") {
            string id;
            int amount;
            cin >> id >> amount;
            cout << (credit(id, amount) ? "true" : "false") << "\n";

        } else if (query == "BALANCE") {
            string id;
            cin >> id;
            cout << getBalance(id) << "\n";
        }
    }

    return 0;
}
