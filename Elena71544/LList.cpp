#include <iostream>
using namespace std;

struct Node{
	int inf;
	Node* next;
	Node(){
		inf = 0;
		next = NULL;
	}
};

class LList {
private:
	Node* start;
	Node* end;
public:
	LList(){
		start = NULL;
		end = NULL;
	}
	void toEnd(int x){
		if (isEmpty()){
			start = new Node;
			start->inf = x;
			start->next = NULL;
			end = start;
			end->next = NULL;

		}
		else{
			Node* elem = new Node;
			elem->inf = x;
			elem->next = NULL;
			end->next = elem;
			end = elem;
		}
	}
	void toStart(int x){
		if (isEmpty()){
			start = new Node;
			start->inf = x;
			start->next = NULL;
			end = start;

		}
		else{
			Node* elem = new Node;
			elem->inf = x;
			elem->next = start;
			start = elem;
		}

	}
	bool removeEnd(){

		if (isEmpty())
			return false;
		else{
			Node* elem = start;
			while (elem->next != end){
				elem = elem->next;
			}
			delete end;
			end = elem;
			end->next = NULL;
			return true;
		}
	}
	bool removeStart(){
		if (isEmpty())
			return false;
		else{
			Node* p = start;
			start = p->next;
			delete p;
			return true;
		}
	}
	bool isEmpty(){
		return start == NULL;
	}
	Node* find(int x){
		Node* elem = start;
		while (elem->inf != x){
			elem = elem->next;
		}
		return elem;
	}
	void insertBefore(Node* second, int x){
		Node* first = start;
		while (first->next->inf != second->inf){
			first = first->next;
		}
		Node* elem = new Node;
		elem->inf = x;
		first->next = elem;
		elem->next = second;

	}
	void insertAfter(Node* first, int x){

		Node* second = first->next;
		Node* elem = new Node;
		elem->inf = x;
		first->next = elem;
		elem->next = second;
	}

	void insertBetween(int x, Node* first, Node* second){
		Node* elem = new Node;
		elem->inf = x;
		first->next = elem;
		elem->next = second;
	}
	void print(){
		Node *p = start;
		while (p != NULL){
			cout << p->inf << ' ';
			p = p->next;
		}
		cout << endl;
	}

};


int main(){
	LList a;
	a.toEnd(8);
	a.toEnd(4);
	a.toEnd(10);

	a.insertBetween(3, a.find(4), a.find(10));
	a.print();

	return 0;
}