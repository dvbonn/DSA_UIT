#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    unordered_map<string, string> database;

    for (int i = 0; i < N; i++) {
        string account, password;
        cin >> account >> password; 
        database[account] = password; //Trỏ giá trị của pw vào ô nhớ account tương ứng, nếu đã có thì ghi đè lên còn không thì thêm vào
    }

    stringstream output; 
    for (int i = 0; i < Q; i++) {
        string account;
        cin >> account;

        auto it = database.find(account);
        if (it != database.end()) {
            output << it->second << endl;
        } else {
            output << "Chua Dang Ky!" << endl;
        }
    }

    cout << output.str();

    return 0;
}
