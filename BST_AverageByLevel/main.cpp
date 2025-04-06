#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct TNode {
    int key;
    TNode * left, * right;
};

typedef TNode * TREE;

TREE CreateTree(vector<int> pre, vector<int> in, int preB, int preE, int inB, int inE) {
	int i;
	TREE root;
	if (inE < inB) return NULL;
	root = new TNode;
	if (root != NULL) {
		root->key = pre[preB];
		for (i = inB; i <= inE; i++)
			if (in[i] == pre[preB]) break;
		root->left = CreateTree(pre, in, preB+1, preE, inB, i - 1);
		root->right = CreateTree(pre, in, preB+i-inB+1, preE, i+1,inE);
	} return root;
}


double AverageByLevel(TREE root, int level) {
    double sum = 0.0;
    int count = 0;

    vector<pair<TREE, int>> stack;
    stack.push_back(make_pair(root, 0));

    while (!stack.empty()) {
        TREE node = stack.back().first;
        int currentLevel = stack.back().second;
        stack.pop_back();

        if (node != nullptr) {
            if (currentLevel == level) {
                sum += node->key;
                count++;
            }
            if (node->left != nullptr) {
                stack.push_back(make_pair(node->left, currentLevel + 1));
            }
            if (node->right != nullptr) {
                stack.push_back(make_pair(node->right, currentLevel + 1));
            }
        }
    }

    return count == 0 ? 0.0 : sum / count;
}

int main() {
    vector<int> nlr, lnr;
    int n, key, m, lvl;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> key;
        nlr.push_back(key);
    }

    for (int i = 0; i < n; i++) {
        cin >> key;
        lnr.push_back(key);
    }

    TREE r = CreateTree(nlr, lnr, 0, nlr.size()-1, 0, lnr.size()-1);

    cin >> m;

    cout << setprecision(2) << fixed;

    for (int i = 0; i < m; i++) {
        cin >> lvl;
        cout << AverageByLevel(r, lvl) << endl;
    }

    return 0;
}

	
