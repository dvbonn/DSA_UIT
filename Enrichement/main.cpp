#include<iostream>
#include<vector>

using namespace std;

void NhapDS(vector<vector<int>> &a, int n, int m){
    for(int i{0}; i < n; i++){
        for(int j{0}; j < m; j++){
            cin >> a[i][j];
        }
    }
}
int main(){
    int n, m; 
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    NhapDS(a, n, m);
    int min_sum = INT_MAX;

    for(int i{1}; i < n - 1; i ++){
            for(int j{1}; j < m - 1; j ++){
                int Sum = 0; 

                for(int ii{i-1}; ii <= i+1; ii++){
                    for(int jj(j-1); jj <= j + 1; jj++){
                        Sum += a[ii][jj];
                    }
                }
            min_sum = min(Sum, min_sum);
            }
        } 
        cout << min_sum << endl; 

    return 0; 
}
