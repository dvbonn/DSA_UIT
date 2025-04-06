#include <iostream>
#include <vector> 

using namespace std;

vector<pair<int, int>> linear_search(vector<int> a, int x) {
    vector<pair<int, int>> found_indices; 
    int count = 0; 
    for (int i = 0; i < a.size(); ++i) {
        count++; 

        if (a[i] == x) {
            found_indices.push_back(make_pair(i, count));
        }
    }
    return found_indices; 
}

int main() {
    int n;
    cin >> n; 
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int x;
    cin >> x; 

    vector<pair<int, int>> found_indices = linear_search(a, x);

    cout << found_indices.size() << endl;
    for (pair<int, int> index : found_indices) {
        cout << index.first << " " << index.second << endl;
    }
    return 0;
}
