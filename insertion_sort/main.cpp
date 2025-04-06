#include<iostream>
#include<vector>

using namespace std;

void insertionSort(vector<int>& arr, int n){
    for(int i{1}; i < n; i++){
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
            for(int k{0}; k < n; k++){
                cout << arr[k] << " "; 
            }cout << endl ;
        }
        arr[j + 1] = key;
        for(int t{0}; t < n; t++){
            cout << arr[t] << " ";
        }cout << endl; 
    }
}

int main(){
    int n; 
    cin >> n;

    vector<int> arr(n);
    for(int i{0}; i < n; i++){
        cin >> arr[i]; 
    }

    insertionSort(arr, n);

    return 0;
}