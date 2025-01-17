#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to register a new user
void registerUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ofstream file("database.txt", ios::app);
    file << username << " " << password << endl;
    file.close();
    cout << "Registration successful!" << endl;
}

// Function to login an existing user
bool loginUser() {
    string username, password, u, p;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("database.txt");
    while (file >> u >> p) {
        if (u == username && p == password) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

int main() {
    int choice;
    cout << "1. Register\n2. Login\nChoose an option: ";
    cin >> choice;

    if (choice == 1) {
        registerUser();
    } else if (choice == 2) {
        if (loginUser()) {
            cout << "Login successful!" << endl;
        } else {
            cout << "Login failed. Invalid credentials." << endl;
        }
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}

