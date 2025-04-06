#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void DsNhap(vector<int> &A, int &n, int &x)
{
    cin >> n >> x;
    int a;
    for (int i{0}; i < n; i++)
    {
        cin >> a;
        A.push_back(a);
    }
}

void Find_Max(vector<int> &A, int n, int x)
{
    sort(A.begin(), A.end());
    int i{0};
    int j{n - 1};
    int sum{0};
    int cost{0};
    while(j > i)
    {
        sum = A[i] + A[j];
        if(sum == x)
        {
            cost = sum;
            break;
        }
        if(sum < x)
        {
            if(sum > cost)
            {
                cost = sum;
            }
            i++;
        }
        else
        {
            j--;
        }
    }
    cout << cost;
}

int main()
{
    vector<int> A;
    int n, x;
    DsNhap(A, x, n);
    Find_Max(A, x, n);
    return 0;
}
