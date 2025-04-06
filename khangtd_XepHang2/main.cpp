#include <iostream>
#include <vector>
#include <sstream>

using namespace std; 

int main()
{
    stringstream ss;

    int N, m;
    cin >> N >> m;
    vector<int> n;

    n.reserve(N);

    int T[m];
    int arr[N + 1]{0};

    for(int i{0}; i < m; i++){
        cin >> T[i];
    }
    for(int i{N}; i > 0; i--){
        n.push_back(i);
    }

    int j{0};

    for(int i{0}; i < m; i++){
        n.push_back(T[i]);
        arr[T[i]]++;
        while(arr[n[j]] > 0){
            arr[n[j]]--;
            j++;
        }
        
        ss << n[j] << " ";
    }

    cout << ss.str();

    return 0;
}
// #include <iostream>
// #include <vector>

// using namespace std;

// int main() {
//     int n, m;
//     cout << "Nhap so luong sinh vien (n): ";
//     cin >> n;
//     cout << "Nhap so lan thay giao goi (m): ";
//     cin >> m;

//     vector<int> positions(n + 1);
//     for (int i = 1; i <= n; i++) {
//         positions[i] = i;
//     }

//     int lastPosition = n;
//     for (int i = 0; i < m; i++) {
//         int studentID;
//         cout << "Nhap mssv cua sinh vien duoc goi lan thu " << (i + 1) << ": ";
//         cin >> studentID;

//         // Di chuyển sinh viên được gọi lên đầu dãy
//         for (int j = 1; j <= n; j++) {
//             if (positions[j] == studentID) {
//                 for (int k = j; k < lastPosition; k++) {
//                     positions[k] = positions[k + 1];
//                 }
//                 positions[lastPosition] = studentID;
//                 break;
//             }
//         }

//         lastPosition++;
//     }

//     cout << "MSSV cua sinh vien cuoi cung sau moi lan goi: ";
//     for (int i = lastPosition + 1; i <= n; i++) {
//         cout << positions[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }
