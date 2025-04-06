#include <iostream>

using namespace std;

struct Hocsinh {
    int Maso;
    string Hoten;
    int Namsinh;
    bool Gioitinh;
    double TBK;
};
void Input(Hocsinh &x) {
    cin >> x.Maso;
    getline(cin>>ws, x.Hoten);
    cin >> x.Namsinh;
    cin >> x.Gioitinh;
    cin >> x.TBK;
}
void Output(Hocsinh hs) {
    cout << '[' << hs.Maso << "\t" << hs.Hoten << "\t" << hs.Gioitinh << "\t" << hs.Namsinh << "\t" << hs.TBK << "]\n";
}


int QuickSort(Hocsinh [] , int, int);

int main()
{
    Hocsinh *ls = NULL;
    int n;
    cin >> n;
    ls = new Hocsinh[n];
    for (int i = 0; i < n; i++) {
        Input(ls[i]);
    }
    cout << QuickSort(ls, 0, n-1) << endl;
    for (int i = 0; i < n; i++) {
        Output(ls[i]);
    }
    delete [] ls;
    return 0;
}

// Function prototypes
// void Swap(Hocsinh &a, Hocsinh &b);
// int CompareNames(const string &name1, const string &name2);

// QuickSort function with embedded partitioning
int QuickSort(Hocsinh ls[], int b, int e) {
    int shifts = 0;

    if (b < e) {
        string pivot = ls[(b + e) / 2].Hoten; // Choose middle element as pivot
        int left = b;
        int right = e;

        while (left <= right) {
            const string &lleft = ls[left].Hoten; 
            const string &rright = ls[right].Hoten; 
            // while (CompareNames(ls[left].Hoten, pivot) < 0) {
            while(lleft.compare(pivot) < 0){
                left++;
            }
            //while (CompareNames(ls[right].Hoten, pivot) > 0) {
            while(rright.compare(pivot) > 0){
                right--;
            }
            if (left <= right) {
                if (left != right) {
                    // Swap(ls[left], ls[right]);
                    Hocsinh temp = ls[left];
                    ls[left] = ls[right]; 
                    ls[right] = temp; 
                    shifts++;
                }
                left++;
                right--;
            }
        }

        shifts += QuickSort(ls, b, right);
        shifts += QuickSort(ls, left, e);
    }

    return shifts;
}

// void Swap(Hocsinh &a, Hocsinh &b) {
//     Hocsinh temp = a;
//     a = b;
//     b = temp;
// }

// int CompareNames(const string &name1, const string &name2) {
//     return name1.compare(name2);
// }
