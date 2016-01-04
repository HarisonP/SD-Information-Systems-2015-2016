#include<iostream>
using namespace std;

struct Node
{
	int inf;
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
	void insertBetween(Node* first, Node* second, int x);
	void insertEnd(int x);
	bool empty()const;
	void print()const;

};

bool Queue :: push(int x)
{
	if (start == NULL)
	{
		start = new Node();
		start->inf = x;
		start->next = NULL;
		end = start;
	}
	else
	{
		Node* first = start;
		Node* second = start->next;
		if (second == NULL)
		{
			if (x > first->inf)
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
			if (x < first->inf)
			{
				insertStart(x);
			}
			else
			{
				Node* temporary1 = first;
				Node* temporary2 = second;
				while (temporary2 != NULL)
				{
					if (temporary1->inf < x && temporary2->inf > x)
					{
						insertBetween(temporary1, temporary2, x);
						return true;
					}
					else
					{
						temporary1 = temporary1->next;
						temporary2 = temporary2->next;
					}
				}
				if (temporary1->inf < x)
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
		Node* temporary = start;
		start = temporary->next;
		delete temporary;
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
	elem->inf = x;
	elem->next = start;
	start = elem;
}

void Queue :: insertBetween(Node* first, Node* second, int x)
{
	Node* elem = new Node();
	elem->inf = x;
	elem->next = second;
	first->next = elem;
}

void Queue :: insertEnd(int x)
{
	Node* elem = new Node();
	elem->inf = x;
	elem->next = NULL;
	end->next = elem;
	end = elem;
}

bool Queue :: empty()const
{
	if (start == NULL && end == NULL)
	{
		return true;
	}
	return false;
}
void Queue::print()const
	{
		Node* temp = start;
		while (temp != NULL)
		{
			cout << temp->inf << ' ';
			temp = temp->next;

		}
		cout << endl;
	}


int main()
{
	Queue* example = new Queue();
	example->push(3);
	example->push(2);
	example->push(5);
	example->push(7);
	example->push(13);
	example->push(4);

	example->print();
	return 0;
}
