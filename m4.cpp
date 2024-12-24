#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if a string of brackets is balanced
string isBalanced(const string& s) {
    stack<char> st;

    for (char c : s) {
        // If it's an opening bracket, push it onto the stack
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        }
        // If it's a closing bracket, check for matching opening bracket
        else if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) {
                return "NO"; // Unmatched closing bracket
            }
            char top = st.top();
            st.pop();
            // Check for mismatch
            if ((c == ')' && top != '(') || 
                (c == ']' && top != '[') || 
                (c == '}' && top != '{')) {
                return "NO";
            }
        }
    }

    // If the stack is empty, the string is balanced
    return st.empty() ? "YES" : "NO";
}

int main() {
    int n; // Number of strings
    cin >> n;

    while (n--) {
        string s;
        cin >> s;
        cout << isBalanced(s) << endl;
    }

    return 0;
}
