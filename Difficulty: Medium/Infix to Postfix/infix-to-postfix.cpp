//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
private:
    stack<char> st; // Change to stack<char> as we're dealing with individual characters

    int priority(char ch) {
        if (ch == '^') return 3;
        else if (ch == '*' || ch == '/') return 2;
        else if (ch == '+' || ch == '-') return 1;
        else return -1;
    }

public:
    string infixToPostfix(string s) {
        int slen = s.length();
        string result = "";

        for (int i = 0; i < slen; i++) {
            char ch = s[i];

            if (isalnum(ch)) {
                result += ch;
            }
            else if (ch == '(') {
                st.push(ch);
            }
            else if (ch == ')') {
                while (!st.empty() && st.top() != '(') {
                    result += st.top();
                    st.pop();
                }
                if (!st.empty() && st.top() == '(') {
                    st.pop(); // Remove the '('
                }
            }
            else {
                while (!st.empty() && priority(st.top()) >= priority(ch)) {
                    result += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }

        // Pop any remaining operators from the stack
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};

//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends