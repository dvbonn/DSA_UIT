#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> freq(n + 1, 0); 
    int next_mex = 0;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        freq[num]++;

        while (freq[next_mex] > 0) {
            next_mex++;
        }
        cout << next_mex << " ";
    }

    return 0;
}
