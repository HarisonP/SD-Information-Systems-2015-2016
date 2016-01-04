#include<iostream>
using namespace std;

struct Node
{
	int info;
	Node* next;
};

class Queue
{
	Node* start;
	Node* end;
public:
	Queue()
	{
		start = NULL;
		end = NULL;
	}

	~Queue()
	{
		while (start != NULL) 
		{
			this->pop();
		}

		start = NULL;
		end = NULL;

	}

	bool push(int x);
	bool pop();

	void insertStart(int x);
	void insertBetween(Node* f1, Node* f2, int x);
	void insertEnd(int x);


	void swap(Node* n1, Node* n2);
	int front()const;
	int back()const;
	int size()const;
	bool empty()const;
	void print()const;

};


//insertion sort push()
bool Queue :: push(int x)
{
	if (start == NULL)
	{
		start = new Node();
		start->info = x;
		start->next = NULL;
		end = start;
	}
	else
	{
		Node* first = start;
		Node* second = start->next;
		if (second == NULL)
		{
			if (x > first->info)
			{
				insertEnd(x);
			}
			else
			{
				insertStart(x);
			}
		}
		else
		{
			if (x < first->info)
			{
				insertStart(x);
			}
			else
			{
				Node* temp1 = first;
				Node* temp2 = second;
				while (temp2 != NULL)
				{
					if (temp1->info < x && temp2->info > x)
					{
						insertBetween(temp1, temp2, x);
						return true;
					}
					else
					{
						temp1 = temp1->next;
						temp2 = temp2->next;
					}
				}
				if (temp1->info < x)
				{
					insertEnd(x);
				}
			}

		}
	}
	return true;
}

bool Queue  :: pop()
{
	if (!empty())
	{
		Node* p = start;
		start = p->next;
		delete p;
		return true;
	}
	else
	{
		return false;
	}
}

void Queue :: insertStart(int x)
{
	Node* elem = new Node();
	elem->info = x;
	elem->next = start;
	start = elem;
}

void Queue :: insertBetween(Node* f1, Node* f2, int x)
{
	Node* elem = new Node();
	elem->info = x;
	elem->next = f2;
	f1->next = elem;
}

void Queue :: insertEnd(int x)
{
	Node* elem = new Node();
	elem->info = x;
	elem->next = NULL;
	end->next = elem;
	end = elem;
}

int Queue :: front()const
{
	return start->info;
}

int Queue :: back()const
{
	return end->info;
}


bool Queue :: empty()const
{
	if (start == NULL && end == NULL)
	{
		return true;
	}
	return false;
}


int Queue :: size()const
{
	Node* p = start;
	int counter = 0;
	while (p != NULL)
	{
		p = p->next;
		counter++;
	}
	return counter;
}

void Queue :: swap(Node* n1, Node* n2)
{
	int temp = n1->info;
	n1->info = n2->info;
	n2->info = temp;

}


void Queue :: print()const
{
	Node* p = start;
	while (p != NULL)
	{
		cout << p->info << endl;
		p = p->next;
	}
}

int main()
{
	Queue* newQueue = new Queue();
	newQueue->push(5);
	newQueue->push(2);
	newQueue->push(1);
	newQueue->push(8);
	newQueue->push(3);
	newQueue->push(10);

	newQueue->print();

	cout << " --------------- " << endl;;
	cout << "pop():" << endl;
	newQueue->pop();
	newQueue->print();
	cout << "Front: " << newQueue->front() << endl;
	cout << "Back: " << newQueue->back() << endl;
	cout << "Size: " << newQueue->size() << endl;


	cout << " --------------- " << endl;
	cout << "pop():" << endl;
	newQueue->pop();
	newQueue->print();
	cout << "Front: " << newQueue->front() << endl;
	cout << "Back: " << newQueue->back() << endl;
	cout << "Size: " << newQueue->size() << endl;


	return 0;
}
