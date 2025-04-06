#include<iostream>

using namespace std; 

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* insert(Node* node, int data) {
        if (node == nullptr) {
            return new Node(data);
        }
        if (data < node->data) {
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }
        return node;
    }

    bool isLeaf(Node* node) {
        return (node->left == nullptr && node->right == nullptr);
    }

    bool checkIdealTree(Node* node, int level, int& leafLevel) {
        if (node == nullptr) {
            return true;
        }

        // If it's a leaf node
        if (isLeaf(node)) {
            // If it's the first leaf node, record the level
            if (leafLevel == -1) {
                leafLevel = level;
            }
            // Check if all leaf nodes are on the same level
            return (level == leafLevel);
        }

        // Ensure every non-leaf node has two children
        if (node->left == nullptr || node->right == nullptr) {
            return false;
        }

        // Recursively check the left and right subtrees
        return checkIdealTree(node->left, level + 1, leafLevel) && checkIdealTree(node->right, level + 1, leafLevel);
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int data) {
        root = insert(root, data);
    }

    bool isIdealTree() {
        int leafLevel = -1;
        return checkIdealTree(root, 0, leafLevel);
    }
    ~BinarySearchTree() {
        destroyTree(root);
    }

    void destroyTree(Node* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }
};

void run() {
    int n;
    cin >> n;

    BinarySearchTree bst;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        bst.insert(k);
    }

    if (bst.isIdealTree()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
   run();
   return 0; 
}