#include<iostream>
#include<algorithm>

using namespace std; 

void DectoBin(int x){
    int binaryNum[32];
    int i{0};

    while(x > 0){
        binaryNum[i] = x % 2;
        x = x/2; 
        i++;
    }

    for(int j = i - 1; j >= 0; j--){
        cout << binaryNum[j];
    }
}   

int main(){
    int x; 
    cin >> x; 
    DectoBin(x);

    return 0; 
}