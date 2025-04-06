#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std; 

void DsNhap(vector<int> &A, int &n, long long &s) {
    long long a;
    cin >> n >> s;
    for (int i{0}; i < n; i++) {
        cin >> a;
        A.push_back(a);
    }
}

long long Min_Cost(vector<int> &A, int n, long long s) {
    priority_queue<long long, vector<long long>, greater<long long>> minHeap(A.begin(), A.end());
    long long totalCost = 0;

    while(minHeap.size() > 1) {
        long long wood1 = minHeap.top();
        minHeap.pop();
        long long wood2 = minHeap.top();
        minHeap.pop();

        long long cost = wood1 + wood2;
        totalCost += cost;

        minHeap.push(cost);
    }

    return totalCost; 
}

int main() {
    vector<int> A;
    int n{0};
    long long s{0};
    DsNhap(A, n, s);
    cout << Min_Cost(A, n, s);
    return 0;
}