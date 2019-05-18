#include <iostream>
#include <vector>
using namespace std;

struct NODE
{
	int data;
	NODE *next;
};

struct Queue
{
	NODE* head;
	NODE *tail;
};

void Init_Queue(Queue &queue)
{
	queue.head = queue.tail = NULL;
}


bool KiemTraQueueRong(Queue queue)
{
	if (queue.head == NULL && queue.tail == NULL)
	{
		return true;
	}
	return false;
}

NODE* make_node(int data)
{
	NODE *node_create;
	node_create = new NODE();
	if (node_create == NULL)
	{
		cout << "There is not enough memory to provided!" << endl;
	}
	else		//contrast case, if not occured above case, goes to this line, if we not put the else case without the if case above not have a break out command, the case 
	{
		node_create->data = data;
		node_create = NULL;		//block the pointer not point to anywhere.
		return node_create;
	}
}

void Enqueue(Queue &queue, int &data_push)			//Insert node in the last. In Enqueue, the address of last node is changed because pointer pointing to other address.
{
	cout << "Input data: ";
	cin >> data_push;
	NODE *node_create;
	node_create = make_node(data_push);
	if (KiemTraQueueRong(queue) == true)
	{
		queue.head = queue.tail = node_create;
	}
	else
	{
		queue.tail->next = node_create;
		queue.tail = node_create;
	}
}

int Dequeue(Queue &queue)		//Delete first node in the queue.
{
	if (KiemTraQueueRong(queue) == true)
	{
		cout << "Can't Dequeue Because The Queue Has Empty!" << endl;
	}
	else		
	{
		int hold_data_old_head;
		NODE *hold_to_release;

		hold_data_old_head = queue.head->data;  //just keep the data and dequeue out. The old head node we must to release it. 		//if we hold the first node and increase the node of the queue to 1 to set the value of next index to the new front of the queue
		hold_to_release = queue.head;
		queue.head = queue.head->next;				//set the next index is the new front of queue.
		
		delete hold_to_release;
		return hold_data_old_head;		//return the old front when increase front location to 1.
	}
}

int Peek(Queue queue)
{
	if (KiemTraQueueRong(queue) == true)
	{
		cout << "There Is Nothing Node To Peeking!" << endl;
	}
	else		//The Queue Is Not Empty, Maa
	{
		return queue.head->data;		//return the head of the queue. not dequeue it.
	}
}

void MakeEmptyQueue(Queue &queue)
{
	if(KiemTraQueueRong(queue) == true)		//if the queue already empty, do nothing 
	{
		cout << "Queue Had Empty Before! " << endl;
		return;
	}
	else
	{
		while (KiemTraQueueRong(queue) != true)
		{
			NODE *hold_release;
			hold_release = queue.head;
			queue.head = queue.head->next;			//use directly the head origin to impact in the origin queue.
			
			delete hold_release;		//delete the node hold the queue head(in origin and after set the new head).
		}
	}
}