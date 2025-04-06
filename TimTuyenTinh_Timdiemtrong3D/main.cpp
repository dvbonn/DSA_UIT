#include <iostream>
#include <sstream>

using namespace std;

struct Point {
    double x, y, z;
    int index;
    Point* left;
    Point* right;
    Point(double _x, double _y, double _z, int _index) : x(_x), y(_y), z(_z), index(_index), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Point* root;

    Point* insert(Point* node, double x, double y, double z, int index) {
        if (!node) {
            return new Point(x, y, z, index);
        }

        if (x < node->x || (x == node->x && y < node->y) || (x == node->x && y == node->y && z < node->z)) {
            node->left = insert(node->left, x, y, z, index);
        } else {
            node->right = insert(node->right, x, y, z, index);
        }

        return node;
    }

    int search(Point* node, double x, double y, double z) {
        if (!node) {
            return -1; // Not found
        }

        if (node->x == x && node->y == y && node->z == z) {
            return node->index;
        }

        if (x < node->x || (x == node->x && y < node->y) || (x == node->x && y == node->y && z < node->z)) {
            return search(node->left, x, y, z);
        } else {
            return search(node->right, x, y, z);
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(double x, double y, double z, int index) {
        root = insert(root, x, y, z, index);
    }

    int search(double x, double y, double z) {
        return search(root, x, y, z);
    }
};

int main() {
    int n;
    cin >> n;

    BST bst;
    for (int i = 0; i < n; i++) {
        double x, y, z;
        cin >> x >> y >> z;
        bst.insert(x, y, z, i);
    }

    int m;
    cin >> m;

    stringstream ss; 
    for (int i = 0; i < m; i++) {
        double x, y, z;
        cin >> x >> y >> z;
        int result = bst.search(x, y, z);
        if (result == -1) {
            ss << "KHONG" << endl;
        } else {
            ss << result << endl;
        }
    } cout << ss.str(); 

    return 0;
}
