#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <stdexcept>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const string& token : tokens) {
            if (isOperator(token)) {
                // Pop two operands from the stack
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                
                // Perform the operation and push the result
                st.push(applyOperator(a, b, token));
            } else {
                // Push operand onto the stack
                st.push(stoi(token));
            }
        }

        // The final result will be at the top of the stack
        return st.top();
    }

private:
    // Check if a token is an operator
    bool isOperator(const string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

    // Apply an operator to two operands
    int applyOperator(int a, int b, const string& op) {
        if (op == "+") return a + b;
        if (op == "-") return a - b;
        if (op == "*") return a * b;
        if (op == "/") return a / b; // Integer division
        throw invalid_argument("Invalid operator");
    }
};

int main() {
    Solution solution;

    // Example Input
    vector<string> tokens = {"2", "1", "+", "3", "*"};

    // Evaluate the RPN expression
    int result = solution.evalRPN(tokens);

    // Output the result
    cout << "Result: " << result << endl; // Output: 9

    return 0;
}
