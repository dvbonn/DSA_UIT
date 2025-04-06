#include <bits/stdc++.h>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;
	
	DONTHUC(double _heso = 0,int _somu=0){
		heso = _heso;
		somu  = _somu;
	}
	
	DONTHUC& operator = (const DONTHUC &rhs){
		if (this == &rhs) return *this;
		this->heso = rhs.heso;
		this->somu = rhs.somu;
		return *this;
	}
};


struct Node{
	DONTHUC* data;
	Node* next;
	
	Node(DONTHUC* _data = nullptr){
		this->data = _data;
		this->next = nullptr;
	}
	
};

struct DATHUC{
	Node* head;
	Node* tail;
	DATHUC(){
		this->head = nullptr;
		this->tail = nullptr;
	}
};

void AddDonThuc(DATHUC &B, double heso, int somu){
	DONTHUC *new_node = new DONTHUC(heso, somu);
	Node *new_element = new Node(new_node);

	if(B.head == nullptr){
		B.head = B.tail = new_element;
	}
	else{
		B.tail->next = new_element;
		B.tail = new_element; 
	}
}

void Nhap(DATHUC &B, double heso, int somu){
	AddDonThuc(B, heso, somu); 
}

void Xuat(const DATHUC &B){
	stringstream ss;
    DATHUC *Buff = new DATHUC(); 
    Buff->head = B.head;
    while(Buff->head != nullptr){   
        if(Buff->head->data->heso == 0){
            Buff->head = Buff->head->next;
            continue;
        }
        else if(Buff->head->data->heso == 1){
            if(ss.rdbuf()->in_avail() != 0){
                ss << '+';
            }
        }
        else if(Buff->head->data->heso == -1){
            ss << '-';
        }
        else {
            if(Buff->head->data->heso > 0 && ss.rdbuf()->in_avail() != 0){
                ss << '+';
            }
            ss << Buff->head->data->heso;
        }
        if(Buff->head->data->somu == 0){
            if(abs(Buff->head->data->heso) == 1){
                ss << '1';
            }
            Buff->head = Buff->head->next;
            continue;
        }
        else if(Buff->head->data->somu == 1){
            ss << 'x';
        }
        else{
            ss << "x^" << Buff->head->data->somu;
        }
        Buff->head = Buff->head->next;
    }
    if(ss.rdbuf()->in_avail() != 0){
        cout << ss.str();
    }
    else{
        cout << '0';
    } 
}

double TinhDaThuc(const DATHUC &B, double x){
	double result = 0.0;
	Node *current = B.head; 
	while(current != nullptr){
		result += current->data->heso * pow(x, current->data->somu);
		current = current->next; 
	}
	return result; 
}

int main() {
    DATHUC B;
    int N;
    
    cin >> N;
    for (int test = 0; test < N; test++){
		double heso; int somu;
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }
    
    
    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
