#include <iostream>
#include <cmath>

using namespace std;

struct Node {
    double x, y, z;
    Node* next;
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    void add(double x, double y, double z) {
        Node* newNode = new Node{x, y, z, nullptr};
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void print(double b, double e) {
        Node* temp = head;
        bool found = false;
        while (temp) {
            double distance = sqrt(temp->x * temp->x + temp->y * temp->y + temp->z * temp->z);
            if (distance >= b && distance <= e) {
                cout << temp->x << " " << temp->y << " " << temp->z << endl;
                found = true;
            }
            temp = temp->next;
        }
        if (!found) {
            cout << "KHONG" << endl;
        }
    }

    ~LinkedList() {
        clear();
    }
    void clear(){
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    int n;
    cin >> n;
    
    LinkedList list;

    for (int i = 0; i < n; i++) {
        double x, y, z;
        cin >> x >> y >> z;
        list.add(x, y, z);
    }

    double b, e;
    cin >> b >> e;

    list.print(b, e);

    return 0;
}
