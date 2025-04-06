#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int h_index(vector<int>& citations) {
    sort(citations.begin(), citations.end(), greater<int>()); 
    int n = citations.size();
    int h_index = 0;
    
    for (int i = 0; i < n; ++i) {
        if (citations[i] >= i + 1) {
            h_index = i + 1;
        } else {
            break;
        }
    }
    return h_index;
}

int main() {
    int n;
    cin >> n;

    vector<int> citations(n);
    for (int i = 0; i < n; ++i) {
        cin >> citations[i];
    }

    cout << h_index(citations) << endl;

    return 0;
}
