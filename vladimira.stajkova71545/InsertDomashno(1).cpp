#include<iostream>
using namespace std;

struct Node
{
 int inf;
 Node* next;
};

class Queue
{
protected:
 Node* start;
 Node* end;
public:
 Queue()
 {
	 start = NULL;
	 end == NULL;
 }



void InsertEnd(int x)
{
 Node* elem = new Node;
 elem -> inf = x;
 elem -> next = NULL;
 end -> next = elem;
 end = elem;
}

void InsertStart(int x)
{
 Node* elem = new Node;
 elem -> inf = x;
 elem -> next = start;
 start = elem;
}

void InsertBetween(Node*first ,Node* second,int x)
{
 Node* elem = new Node;
 elem -> inf = x;
 first ->next = elem;
 elem -> next = second;
}

bool push(int x)
{
 if(start == NULL)
 {
  start = new Node;
  start -> inf = x;
  start -> next = NULL;
  end = start;
 }
 else
 {
  Node* first = start;
  Node* second = start -> next;
  if(second == NULL)
  {
   if(x > first -> inf)
   {
    InsertEnd(x);
   }
   else
   {
    InsertStart(x);
   }
  }
  else
  {
   if(x < first -> inf)
   {
    InsertStart(x);
   }
   else
   {
   Node* temp1 = first;
     Node* temp2 = second;
     while (temp2 != NULL)
     {
      if (temp1->inf < x && temp2->inf > x)
      {
       InsertBetween(temp1, temp2, x);
      return true;
      }
      else
      {
       temp1 = temp1->next;
       temp2 = temp2->next;
      }
     }            
     if (temp1->inf < x)
     {
      InsertEnd(x);
     }
    } 

  }
 }
}
void print()const
{
	Node* p = start;
  while (p != NULL)
  {
   cout << p->inf << endl;
   p = p->next;
  }
}
};

int main()
{
 Queue* numbers = new Queue;
 numbers->push(7);
 numbers->push(1);
 numbers->push(8);
 numbers->push(6);
 numbers->print();
 system("pause");
 return 0;
}