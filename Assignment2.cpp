#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isPalindrome(string str) {
    stack<char> s;

    // Step 1: Push all characters onto the stack
    for (char ch : str) {
        s.push(ch);
    }

    // Step 2: Build reversed string by popping from stack
    string reversed = "";
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }

    // Step 3: Compare original and reversed
    return str == reversed;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    if (isPalindrome(input)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is NOT a palindrome." << endl;
    }

    return 0;
}
