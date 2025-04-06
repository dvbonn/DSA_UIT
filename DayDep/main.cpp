#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 
void DsNhap(vector<int> &A, int &n)
{
    int a;
    cin >> n;
    for(int i{0}; i < n; i++)
    {
        cin >> a;
        A.push_back(a);
    }
}

void Cal(vector<int> &A , int n)
{
    sort(A.begin(), A.end());
    int h = 0;
    int j = 0;
    int count = 0;
    for(int i{0}; i < n; i += count){
        j = A[i];
        count = 0;
        while(j == A[i + count])
        {
            count++;
        }
        if(count > A[i])
        {
            h += count - A[i];
        }
        else if(count < A[i])
        {
            h += count;
        }
    }
    cout << h;
}

int main()
{
    int n{0};
    vector<int> A;
    DsNhap(A, n);
    Cal(A, n);
    return 0;
}