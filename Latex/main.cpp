#include <iostream>
#include <stack>
#include <string>

using namespace std;

int isValidLatex(const string& s) {
    stack<char> st;

    for (char c : s) {
        if (c == '{' || c == '[' || c == '(') {
            st.push(c);
        } else if (c == '}' || c == ']' || c == ')') {
            if (st.empty()) return 0;
            char top = st.top();
            st.pop();
            if ((c == '}' && top != '{') ||
                (c == ']' && top != '[') ||
                (c == ')' && top != '(')) {
                return 0;
            }
        }
    }

    return st.empty() ? 1 : 0;
}

int main() {
    string s;
    getline(cin, s);

    cout << isValidLatex(s) << endl;

    return 0;
}
