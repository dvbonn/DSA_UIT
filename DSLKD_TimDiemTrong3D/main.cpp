#include <iostream>
#include <cmath>

using namespace std;

struct node{
    double x, y, z; 
    node* next; 
};
class LinkedList{
private: 
    node* head; 
public: 
    LinkedList() : head(nullptr) {}

    ~LinkedList(){
        while(head != nullptr){
            node* temp = head; 
            head = head->next; 
            delete temp;
        }
    }
    void insert(double x, double y, double z){
        node* newNode = new node{x, y, z, nullptr};
        if(head == nullptr){
            head = newNode;
        } else {
            node* current = head; 
            while (current->next != nullptr){
                current = current->next; 
            }
            current->next = newNode; 
        }
    }
    int search(double x, double y, double z){
        node* current = head; 
        int index = 0; 
        while(current != nullptr){
            if(fabs(current->x - x) < 1e-9 && fabs(current->y - y) < 1e-9 && fabs(current->z - z) < 1e-9){
                return index;
            }
            current = current->next;
            index++; 
        }
        return -1; 
    }
};
void run(){
    int n, m;
    cin >> n; 

    LinkedList List; 
    for(int i{0}; i < n; ++i){
        double x, y, z; 
        cin >> x >> y >> z; 
        List.insert(x,y,z); 
    }
    cin >> m; 
    for(int i{0}; i < m; ++i){
        double px, py, pz; 
        cin >> px >> py >> pz; 
        int result = List.search(px,py,pz); 
        if(result == -1){
            cout << "KHONG" << endl; 
        } else {
            cout << result << endl; 
        }
    }
}

int main() {

	int * a = new int[256];
	int * b = new int[256];
	delete [] a;
	run();
	delete [] b;
}