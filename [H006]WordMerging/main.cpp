#include <iostream>
#include <string>

using namespace std;

int shortestReducedLength(string s) {
    string reducedString;
    for (char c : s) {
        if (!reducedString.empty() && reducedString.back() == c) {
            reducedString.pop_back();
        } else {
            reducedString.push_back(c);
        }
    }
    return reducedString.length();
}

int main() {
    string s;
    cin >> s;
    cout  << shortestReducedLength(s) << endl;

    return 0;
}
