#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct test_case{
    int n, k;
    vector<int> A;
};

void Input_testcase(test_case T[], int t){
    int a;
    for (int i{0}; i < t; i++)
    {
        cin >> T[i].n >> T[i].k;
        for (int j{0}; j < T[i].n; j++)
        {
            cin >> a;
            T[i].A.push_back(a);
        }
    }
}

void Find_X(test_case T[], int t)
{
    int j;
    int h;
    int g;
    stringstream ss;
    for (int i{0}; i < t; i++)
    {
        g = j = h = 0;
        int B[100000]{0};
        sort(T[i].A.begin(), T[i].A.end());
        for (int m{0}; m < T[i].n; m++)
        {
            B[T[i].A[m]]++;
        }
        while (j < T[i].n)
        {
            h++;
            if(B[T[i].A[j]] >= 2)
            {
                g+=1;
            }
            j += B[T[i].A[j]];
        }
        while(h < 2 * T[i].k && g > 0)
        {
            h++;
            g--;
        }
        if (h == 2 * T[i].k)
        {
            ss << "YES\n";
        }    
        else
        {
            ss << "NO\n";
        }
    }
    cout << ss.str();
}

int main(){
    int t{0};
    cin >> t;
    test_case T[t];
    Input_testcase(T, t);
    Find_X(T, t);

    return 0;
}
