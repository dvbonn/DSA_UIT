#include<iostream>

using namespace std;

int binarysearch(int a[], int n, int x, int& count){
    int high = n - 1;
    int low = 0;
    count = 0;
    while(low <= high){
        count++; 
        int mid = low + (high - low)/2;
        if(a[mid] == x){
            return mid;
        }
        if(a[mid] < x){
            low = mid +1;
        }
        if(a[mid] > x){
            high = mid -1;
        } 
    }
    return -1;
}

int main(){
    int n;
    cin >> n; 
    int a[n]; 
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    int x; 
    cin >> x; 
    int count;
    int result = binarysearch(a, n, x, count);
    cout << result << endl; 
    if(result != -1){
        cout << count << endl;
    }

    return 0;
}