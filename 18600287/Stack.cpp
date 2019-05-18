#include <iostream>
#include <vector>
using namespace std;

int stack[100];
int quantity;
int top;

void KhoiTaoRong()
{
	if (quantity != NULL)
	{
		quantity = NULL;
	}
}

bool KiemTraRong()
{
	if (top <= -1)
	{
		return true;
	}
	return false;
}

bool KiemTraDay()
{
	if (top >= 0)
	{
		return true;
	}
	return false;
}

void Push(int &data_push)
{
	cout << "Input data: ";
	cin >> data_push;
	if (KiemTraDay() == true)
	{
		cout << "Stack Overflow" << endl;
		return;
	}
	else
	{
		top++;
		stack[top] = data_push;
	}
}

int Pop()
{
	if (KiemTraRong() == true)
	{
		cout << "Stack Underflow" << endl;
		return;
	}
	else
	{
		int hold = stack[top];
		top--;
		return hold;
	}
}

int Peek()
{
	if (KiemTraRong() == true)
	{
		cout << "Nothing to display!!" << endl;
	}
	else
	{
		return stack[top];		//return the currently top.
	}
}

void MakeEmpty(vector<int> &reverse)
{
	if (KiemTraRong() == true)
	{
		cout << "Stack Already Empty Before!" << endl;
		return;
	}
	else
	{
		while (KiemTraRong() == true)		//while the list empty, then break out.
		{
			reverse.push_back(stack[top]);
			top--;
		}
	}
}