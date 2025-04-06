#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std; 

struct test_case
{
    int n;
    vector<int> A;
};

void Input_Testcase(test_case *arr, int t)
{
    int a;
    for(int i{0}; i < t; i++)
    {
        cin >> arr[i].n;
        for(int j{0}; j < arr[i].n; j++)
        {
            cin >> a;
            arr[i].A.push_back(a);
        }
    }
}

void Linear_search_5(test_case *arr, int t)
{
    int x;
    stringstream ss;
    for(int i{0}; i < t; i++)
    {
        sort(arr[i].A.begin(), arr[i].A.end());
        x = arr[i].A[arr[i].n - 1] - arr[i].A[0];
        if(arr[i].n > 2)
        {
            x += arr[i].A[arr[i].n - 2] - arr[i].A[1];
        } 
        ss << x << endl;
    }
    cout << ss.str();
}

int main()
{
    int n;
    cin >> n;
    test_case arr[n];
    Input_Testcase(arr, n);
    Linear_search_5(arr, n);
    
    return 0;
}