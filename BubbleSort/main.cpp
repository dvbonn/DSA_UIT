#include<iostream>
#include<vector>

using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b; 
    b = temp; 
}

void bubbleSort(vector<int>& arr, int n){
    bool swapped;
    for(int i{0}; i < n - 1; i ++){
        swapped = false;
        for(int j{0}; j < n - 1 -i; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
                for(int k{0}; k < n; k++){
                    cout << arr[k] << " " ;  
                }cout << endl;
            }
            if(!swapped){
                break;
            }   
        }
    }
}

int main(){
    int n; 
    cin >> n; 

    vector<int> arr(n);
    for(int i{0}; i < n; i++){
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    return 0;
}
