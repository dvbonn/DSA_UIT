#include <iostream>
#include <sstream>

using namespace std;

static stringstream ss;

void DsNhap(int A[], int &n){
    cin >> n;
    for(int i{0}; i < n; i++){
        cin >> A[i];
    }
}

void MERGE(int A[], int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], R[n2];

    for(int i{0}; i < n1; i++){
        L[i] = A[i + p];
    }
    for(int j{0}; j < n2; j++){
        R[j] = A[q + 1 + j];
    }

    int i{0};
    int j{0};
    int k{p};

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        A[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        A[k] = R[j];
        j++;
        k++;
    }

}

void MERGE_SORT(int A[], int p, int r, int n){
    if(p < r){
        int q = (p + r)/2;
        MERGE_SORT(A, p, q, n);
        MERGE_SORT(A, q + 1, r, n);
        MERGE(A, p, q, r);
        for(int i{0}; i < n; i++){
            if(i == p){
                ss << "[ ";
            }
            ss << A[i];
            if(i == r){
                ss << " ]";
            }
            ss << " ";
        }
        ss << endl;
    }
}

int main(){
    int n{0};
    int A[100];
    DsNhap(A, n);
    MERGE_SORT(A, 0, n - 1, n);
    cout << ss.str();
    return 0;
}