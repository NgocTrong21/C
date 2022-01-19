#include <iostream>
#define max 100
using namespace std;
struct Tree
{
int Data[max];   //thay thu de test git
int MaxNode;
};
void swap(int &a, int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
}
int Left_Child(int p, Tree T) 
{
    return 2 * (p + 1) - 1;
}
int Right_Child(int p, Tree T) 
{
    return 2 * (p + 1);
}
void CreatHeap(Tree &T, int i, int n) //ham tao dong, n la tong so nut
{
    int j = 2 * (i + 1) - 1; 
    int key = T.Data[i];
    while (j <= (n - 1)) 
	{
        if ((j < n - 1) && (T.Data[j] < T.Data[j + 1])) 
		{ 
		j = (j + 1); 
		}
		if (key < T.Data[j]) 
		     { 
				swap(T.Data[(j-1)/2],T.Data[j]);
			 }
        key = T.Data[j];
        j = 2 * (j + 1) - 1;
    }
}
void taodong (Tree& T, int n)// n la so  nut
{
	int k=n/2;
	for(int i=k; i>=0; i--)
	{
		CreatHeap(T, i, n);
	}
}
void heapsort(Tree  &T, int n) //ham vun dong, n la nut cuoi
{
    for (int i = (n - 1)/2; i >= 0; i--) 
	{
        CreatHeap(T, i, n +1);
    }
    for (int i = n; i > 0; i--)
    {
    	swap(T.Data[0], T.Data[i]);
    	CreatHeap(T, 0, i);
	}
}
void NLR(int p, Tree T) //Duyet tien to
{
    if (p<15) 
	{
		cout<< T.Data[p] << " ";
        NLR(Left_Child(p, T), T);
        NLR(Right_Child(p, T), T);       
    }
}

int main()
{
	int i;
	Tree  T;
	T.Data[0]=66;
	T.Data[1]=57;
	T.Data[2]=79;
	T.Data[3]=73;
	T.Data[4]=62;
	T.Data[5]=91;
	T.Data[6]=67;
	T.Data[7]=51;
	T.Data[8]=30;
	T.Data[9]=55;
	heapsort(T,9);
	for(int i=0; i<=9; i++)
	cout<<T.Data[i]<<" ";
	return 0;
}
