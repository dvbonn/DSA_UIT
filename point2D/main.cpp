#include <iostream>

using namespace std;

struct Point
{
    int x,y;
};

void DsNhap(Point *p, int &n)
{
    cin >> n;
    for(int i{0}; i < n; i++)
    {
        cin >> p[i].x;
        cin >> p[i].y;
    }
}

void Swap(Point &A, Point &B)
{
    Point buff = A;
    A = B;
    B = buff;
}

void Heapify(Point *p, int k, int n)
{
    int j{k*2 + 1};
    while(j < n)
    {
        if(j + 1 < n)
        {
            if(p[j].x < p[j + 1].x)
            {
                j = j + 1;
            }
            else if(p[j].x == p[j + 1].x && p[j].y > p[j + 1].y)
            {
                j = j + 1;
            }
        }
        if(p[j].x < p[k].x)
        {
            break;
        }
        else if(p[j].x == p[k].x && p[j].y > p[k].y)
        {
            break;
        }
        Swap(p[j], p[k]);
        k = j;
        j = 2*k + 1;
    }
}

void Build_Heap(Point *p, int n)
{
    int i{(n-1)/2};
    while(i >= 0)
    {
        Heapify(p, i, n);
        i--;
    }

}

void Sort_Heap(Point *p, int n)
{
    Build_Heap(p, n);
    while(n > 0)
    {
        n--;
        Swap(p[0], p[n]);
        Heapify(p, 0, n);
    }

}

void Print_Array(Point p[], int n)
{
    for(int i{0}; i < n; i++)
    {
        cout << p[i].x << " " << p[i].y << '\n';
    }
}

int main()
{
    Point *p = new Point[1000000];
    int n;
    DsNhap(p, n);
    Sort_Heap(p, n);
    Print_Array(p, n);
    return 0;
}