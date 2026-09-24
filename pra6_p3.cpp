
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int precedence(char ch) {
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/' || ch == '%')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return 0;
}

string infixToPostfix(string s) {
    stack<char> st;
    string ans = "";

    for (char ch : s) {
        if (isalnum(static_cast<unsigned char>(ch))) {
            ans += ch;
        }
        else if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }

            if (!st.empty())
                st.pop();
        }
        else {
            while (!st.empty() && st.top() != '(' &&
                  (precedence(st.top()) > precedence(ch) ||
                  (precedence(st.top()) == precedence(ch)
                   && ch != '^'))) {
                ans += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main() {
    string s;
    cin >> s;

    cout << infixToPostfix(s) << endl;

    return 0;
}
