#include<iostream>
using namespace std; 

double sqrt(int num) {
    if (num == 0 || num == 1)
        return num;
 
    double precision = 0.00001;
    double start = 0, end = num;
    double mid;
 
    while ((end - start) > precision) {
        mid = (start + end) / 2;
        if (mid * mid == num)
            return mid;
        else if (mid * mid < num)
            start = mid;
        else
            end = mid;
    }
    return start;
}
struct Point {
    int x;
    int y;
    double distance; 

    // Constructor để khởi tạo một điểm với tọa độ x, y và tính khoảng cách từ điểm đến gốc tọa độ
    Point(int x, int y) : x(x), y(y) {
        distance = sqrt(x * x + y * y); // Sử dụng công thức Euclid để tính khoảng cách
    }
};

// Định nghĩa cấu trúc dữ liệu cho một node trong danh sách liên kết
struct Node {
    Point point;
    Node* next;

    Node(Point point) : point(point), next(nullptr) {}
};

// Hàm thêm một node mới vào danh sách liên kết
void insertNode(Node*& head, Point point) {
    Node* newNode = new Node(point);
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

// Hàm sắp xếp danh sách liên kết theo yêu cầu
void sortLinkedList(Node*& head) {
    if (!head || !head->next) {
        return;
    }

    Node* current = head;
    while (current) {
        Node* minNode = current;
        Node* temp = current->next;
        while (temp) {
            if (temp->point.distance < minNode->point.distance ||
                (temp->point.distance == minNode->point.distance && temp->point.x < minNode->point.x)) {
                minNode = temp;
            }
            temp = temp->next;
        }
        // Hoán đổi giá trị của current và minNode
        Point tempPoint = current->point;
        current->point = minNode->point;
        minNode->point = tempPoint;

        current = current->next;
    }
}

// Hàm in ra danh sách liên kết
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->point.x << " " << temp->point.y << endl;
        temp = temp->next;
    }
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;

    // Đọc và lưu trữ thông tin của các điểm vào danh sách liên kết
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        insertNode(head, Point(x, y));
    }

    // Sắp xếp danh sách liên kết theo yêu cầu
    sortLinkedList(head);

    // In ra tọa độ của các điểm đã được sắp xếp
    printLinkedList(head);

    // Giải phóng bộ nhớ
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}