#include <iostream>

using namespace std; 

int LinerSearch1(int a[], int n, int x){
    for(int i{0}; i < n; i++){
        if(x == a[i]){
            return i;
        }
    } 
    return -1;
}
int main(){
    int n, x, t;
    cin >> n;
    int a[n];
    for(int i{0}; i < n; i++){
        cin >> a[i];
    }
    cin >> x;
    t = LinerSearch1(a, n, x);
    if (t == -1){
        cout << -1 << endl;
    }
    else  cout << t << endl << t + 1 << endl << n - t - 1 << endl << n - t << endl; 
    return 0;
}   