#include <iostream>
#include <cmath>

using namespace std;
struct Point {
    double x, y, z;
    Point* next;
};

void insertPoint(Point*& head, double x, double y, double z) {
    Point* newPoint = new Point{x, y, z, nullptr};
    if (!head) {
        head = newPoint;
        return;
    }
    Point* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newPoint;
}

void printPoints(Point* head) {
    Point* current = head;
    while (current) {
        cout << current->x << " " << current->y << " " << current->z << endl;
        current = current->next;
    }
}

void freePoints(Point* head) {
    while (head) {
        Point* temp = head;
        head = head->next;
        delete temp;
    }
}

bool comparePoints(Point* a, Point* b) {
    if (a->x != b->x) return a->x < b->x;
    if (a->y != b->y) return a->y < b->y;
    return a->z < b->z;
}

Point* merge(Point* left, Point* right) {
    if (!left) return right;
    if (!right) return left;
    
    if (comparePoints(left, right)) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

Point* mergeSort(Point* head) {
    if (!head || !head->next) return head;

    Point* slow = head;
    Point* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Point* mid = slow->next;
    slow->next = nullptr;

    Point* left = mergeSort(head);
    Point* right = mergeSort(mid);

    return merge(left, right);
}

void run() {
    int n;
    cin >> n;

    Point* head = nullptr;

    for (int i = 0; i < n; ++i) {
        double x, y, z;
        cin >> x >> y >> z;
        insertPoint(head, x, y, z);
    }

    head = mergeSort(head);
    printPoints(head);
    freePoints(head);
}

int main() {

	int * a = new int[256];
	int * b = new int[256];
	delete [] a;
	run();
	delete [] b;
}