#include <iostream>
#include <sstream>
using namespace std;
    
void Cal_Num(int x)
{
    stringstream ss;
    int n1, n2;
    if(x / 1000 > 0)
    {
        n1 = x % 100;
        n2 = x / 100;
        if(n1 == 0)
        {
            n2 = 19;
        }
    }
    else if(x / 100 > 0)
    {
        n1 = x % 10;
        n2 = x / 10;
    }
    else
    {
        n1 = x % 10;
        n2 = x / 10;
        if(n1 == 0 && n2 == 0)
        {
            n2 = 19;
        }
    }
    if(n1 > 18 || n2 > 18 || n2 < n1)
    {
        ss << 0;
    }
    else
    {
        if(n1 == 0)
        {
            n1 = n2;
            n2 = 0;
        }
        if(n1 > 9)
        {
            ss << n1 - 9 << 9;
        }
        else
        {
            ss << 1 << n1 - 1;
        }
        if(n2 == 0)
        {
            ss << 0 << 0;
        }
        else if(n2 > 9)
        {
            ss << n2 - 9 << 9;
        }
        else
        {
            ss << 0 << n2;
        }
    }
    cout << ss.str();
}

int main(){
    int x{0};
    cin >> x;
    Cal_Num(x);
    return 0;
}