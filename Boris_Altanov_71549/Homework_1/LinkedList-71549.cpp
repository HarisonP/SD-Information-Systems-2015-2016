#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node(int _data = 0, Node* _next = nullptr) {
		data = _data;
		next = _next;
	}
};

class LinkedList {
private:
	Node* head;
public:
	LinkedList() {
		head = nullptr;
	}
	~LinkedList() {
		while (head) {
			Node* tempNode = head;
			head = head->next;
			delete tempNode;
			tempNode = head;
		}
	};
	void insertBegin(int x) {
		Node* newNode = new Node(x);
		Node* tempNode = head;

		if (tempNode != nullptr) {
			newNode->next = head;
		}
		head = newNode;
	}
	void insertEnd(int x) {
		Node* newNode = new Node(x);
		Node* tempNode = head;

		if (tempNode != nullptr) {
			while (tempNode->next != nullptr) {
				tempNode = tempNode->next;
			}
			tempNode->next = newNode;
		}
		else {
			head = newNode;
		}

	}

	void insertAfter(Node* node, int x) {
		Node* newNode = new Node(x);
		Node* tempNode = head;

		if (tempNode == nullptr) {
			cout << "Empty list" << endl;
		}
		else if (tempNode != nullptr) {
			while (tempNode != nullptr) {
				if (tempNode == node) {
					Node* tempAfter = tempNode->next;
					tempNode->next = newNode;
					newNode->next = tempAfter;
				}
				tempNode = tempNode->next;
			}
		}
	}
	void insertBefore(Node* nodeb, int x) {
		Node* newNode = new Node(x);
		Node* tempNode = head;

		if (tempNode == nullptr) {
			cout << "Empty list" << endl;
		}
		else if (head == nodeb) {
			Node* tempAfter = head;
			head = newNode;
			newNode->next = tempAfter;
		}

		else if (tempNode != nullptr) {
			while (tempNode != nullptr) {
				if (tempNode->next == nodeb) {
					Node* tempAfter = tempNode->next;
					tempNode->next = newNode;
					newNode->next = tempAfter;
				}
				tempNode = tempNode->next;
			}
		}
	}
	void insertBetween(Node* first, Node* second, int x) {
		Node* newNode = new Node(x);
		Node* tempNode = head;

		if (tempNode == nullptr) {
			cout << "Empty list" << endl;
		}
		else if (tempNode != nullptr) {
			while (tempNode != nullptr) {
				if (tempNode == first && tempNode->next == second) {
					tempNode->next = newNode;
					newNode->next = second;
				}
				tempNode = tempNode->next;
			}
		}
	}

	bool removeBegin() {
		if (head == nullptr) {
			return false;
		}
		else {
			Node* tempNode = head;
			head = tempNode->next;
			delete tempNode;
			return true;
		}
	}
	
	bool removeEnd() {
		if (head == nullptr) {
			return false;
		}
		if (head->next == nullptr) {
			delete head;
			head = nullptr;
			return true;
		}
		else {
			Node* tempToEnd = head;
			Node* end = head->next;
			while (end->next != nullptr) {
				tempToEnd = end;
				end = end->next;
			}
			delete end;
			tempToEnd->next = nullptr;
			return true;
		}
	}

	Node* searchNode(int x) {
		Node* tempNode = head;
		while (tempNode != nullptr) {
			if (tempNode->data == x) {
				return tempNode;
			}
			tempNode = tempNode->next;
		}
		return nullptr;
	}

	void print() {
		Node* tempNode = head;
		if (tempNode == nullptr) {
			cout << "Empty" << endl;
		}
		else{
			while (tempNode != nullptr) {
				cout << tempNode->data << ' ';
				tempNode = tempNode->next;
			}
			cout << endl;
		}
	}


};



int main() {
	LinkedList b;
	b.print();
	b.insertEnd(5);
	b.print();
	b.insertEnd(4);
	b.print();
	b.insertEnd(3);
	b.print();
	b.insertBegin(2);
	b.print();
	b.insertBegin(1);
	b.print();
	b.insertAfter(b.searchNode(5), 17);
	b.print();
	b.insertBefore(b.searchNode(1), 99);
	b.print();
	b.insertBetween(b.searchNode(99), b.searchNode(1), 66);
	b.print();
	b.removeBegin();
	b.print();
	b.removeEnd();
	b.print();

	return 0;
}