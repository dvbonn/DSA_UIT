// #include <iostream>
// #include <string>

// using namespace std;

// int main() {
//     int N;
//     cin >> N;

//     const int MAX_N = 10000;
//     string uniqueItems[MAX_N];
//     int uniqueCount = 0;

//     for (int i = 0; i < N; ++i) {
//         string itemCode;
//         cin >> itemCode;
        
//         bool found = false;
//         for (int j = 0; j < uniqueCount; ++j) {
//             if (uniqueItems[j] == itemCode) {
//                 found = true;
//                 break;
//             }
//         }

//         if (!found) {
//             uniqueItems[uniqueCount++] = itemCode;
//         }
//     }

//     cout << uniqueCount << endl;

//     return 0;
// }
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

void heapify(std::vector<std::string> &n, int i, int k)
{
    int j = i * 2 + 1;
    while (j < k)
    {
        if (j + 1 < k)
        {
            if (n[j] < n[j + 1])
            {
                j = j + 1;
            }
        }
        if (n[i] >= n[j])
        {
            return;
        }
        std::swap(n[j], n[i]);
        i = j;
        j = 2 * i + 1;
    }
}
void build_heap(std::vector<std::string> &n)
{
    int i = (n.size() - 1) / 2;
    while (i >= 0)
    {
        heapify(n, i, n.size());
        i--;
    }
}
void sap_xep(std::vector<std::string> &n)
{
    build_heap(n);
    int i = n.size();
    while (i > 0)
    {
        i--;
        std::swap(n[i], n[0]);
        heapify(n, 0, i);
    }
}
int main()
{
    std::vector<std::string> n;
    int x;
    std::cin >> x;
    n.resize(x);
    std::cin.ignore();
    for (int i{0}; i < x; i++)
    {
        std::getline(std::cin, n[i], '\n');
    }
    sap_xep(n);
    int count{0};
    std::string sample{0};
    for (int i{0}; i < n.size();)
    {
        count++;
        sample = n[i];
        while (i < n.size() && n[i] == sample)
        {
            i++;
        }
    }
    std::cout << count;
    return 0;
}