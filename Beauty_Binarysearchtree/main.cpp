#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* createNode(int key) {
    Node* newNode = new Node;
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int key) {
    if (root == NULL) {
        root = createNode(key);
    } else if (key < root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

bool isPerfect(Node* root, int l, int h) {
    if (root == NULL) {
        return l > h;
    }
    if (root->left == NULL && root->right == NULL) {
        return l == h;
    }
    if (root->left != NULL && root->right != NULL) {
        return isPerfect(root->left, l + 1, h) && isPerfect(root->right, l + 1, h);
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        root = insert(root, k);
    }
    if (isPerfect(root, 1, 0)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}