#include<iostream>

using namespace std;

struct Point{
    int x, y;
};
void NhapDS(Point p[], int &n){
    cin >> n;
    for(int i{0}; i < n; i++){
        cin >> p[i].x >> p[i].y;
    }
}

void swap(Point &p1, Point &p2){
    Point temp = p1;
    p1 = p2; 
    p2 = temp; 
}

void Heapify(Point p[], int k, int n)
{
    int j{k*2 + 1};
    while(j < n)
    {
        if(j + 1 < n)
        {
            if(p[j].x < p[j + 1].x){
                j++;
            }
            else if(p[j].x == p[j + 1].x && p[j].y > p[j + 1].y){
                j++;
            }
        }
        if(p[j].x < p[k].x){
            break;
        }
        else if(p[j].x == p[k].x && p[j].y > p[k].y){
            break; 
        }
        swap(p[j], p[k]);
        k = j;
        j = 2*k + 1;
    }
}

void Build_Heap(Point p[], int n)
{
    int i{(n-1)/2};
    while(i >= 0)
    {
        Heapify(p, i, n);
        i--;
    }

}

void HeapSort(Point p[], int n)
{
    Build_Heap(p, n);
    while(n > 0)
    {
        n--;
        swap(p[0], p[n]);
        Heapify(p, 0, n);
    }

}
void XuatDS(Point p[], int n){
    for(int i{0}; i < n; i++){
        cout << p[i].x << " " << p[i].y << endl; 
    }
}
int main(){   
    Point *p = new Point[1000000];
    int n;
    NhapDS(p, n);
    HeapSort(p, n);
    XuatDS(p, n);

    return 0;
}