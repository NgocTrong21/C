#include<string.h>
#include<iostream>

using namespace std;
struct Stack
{
	int capacity;
	int top;
	int* array;
};
void CreateStack (Stack& stack, int capacity)
{
	stack.capacity= capacity;
	stack.top= -1;
	stack.array= new int (capacity);
}
int IsFull (Stack stack)
{
	return stack.top == stack.capacity- 1;
}
int IsEmpty (Stack stack)
{
	return stack.top == -1;
}
void Push(Stack& stack, int val)
{
	if(IsFull (stack))
	return;
	else
	{
		stack.top= stack.top+ 1;
		stack.array[stack.top]= val;
		cout<<"Pushed "<<val<<endl;
	}
}
int Pop (Stack& stack)
{
		int k= stack.array[stack.top];
		stack.top= stack.top- 1;
		return k;
}
int change (char a[])
{
	int k, res= 0;
	int n= strlen(a);
	for (int i=0; i<n; i++)
	{
		k= a[i]- 48;
		res= res* 10+ k;
	}
	return res;
}
int Isdigit (char a[])
{
	int n, k;
	n= strlen(a);
	for (int i=0; i<n; i++)
	{
		if(isdigit(a[i]))
		k= a[i]- 48;
		else
		return 0;
	}
	return 1;
}
int hauto (Stack& stack, char a[][10],int n)
{
	int k1, k2, k, h;
	char b[10];
	for(int i=0; i<n; i++)
	{
	strcpy (b, a[i]);
	if(Isdigit(b))
	{
		int k= change(b);
		Push(stack, k);
	}
	else
	{
		switch(b[0])
		{
			case '+':
				k1= Pop(stack);
				k2= Pop(stack);
				h= k2+ k1;
				Push(stack, h);
				break;
			case '-':
				k1= Pop(stack); 
				k2= Pop(stack); 
				h= k2 - k1;
				Push(stack, h); 
				break;
			case '*':
				k1= Pop(stack);
				k2= Pop(stack);
				h= k2* k1;
				Push(stack, h);
				break;
			case '/':
				k1= Pop(stack);
				k2= Pop(stack);
				h= k2/ k1;
				Push(stack, h);
				break;
		}
	}
    }
    return Pop(stack);
}
int main()
{
	Stack stack;
	char a[10][10]= {"13", "2", "5", "2", "*", "4", "-", "*", "-"};
	CreateStack(stack, 9);
	cout<<hauto(stack, a, 9);
	return 0;
}









