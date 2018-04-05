#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Atividade {
	int inicio;
	int fim;

	Atividade(int inicio, int fim) 
	{
		this->inicio = inicio;
		this->fim = fim;
	}
};

struct compara {
	bool operator()(Atividade * x, Atividade * y)
	{
		return (x->fim > y->fim);
	}
};

void printaArr(int * arr, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\n";
	}
}


void criaEventos(int s[], int f[], int size) 
{
	priority_queue<Atividade*, vector<Atividade*>, compara> minHeap;

	for (int i = 0; i < size; i++)
	{
		minHeap.push(new Atividade(s[i], f[i]));
	}

	//printaArr(s, size);
	//cout << "--------------" << "\n";
	//printaArr(f, size);

	int st = 0, ctrlFim = 0;

	for (int i = 0; i < size; i++)
	{	
		if (ctrlFim <= minHeap.top()->inicio)
		{
			cout << i+1 << " = " << minHeap.top()->inicio << " | " << minHeap.top()->fim << "\n";
			ctrlFim = minHeap.top()->fim;
		}
		minHeap.pop();
	}
}

int main ()
{
	int s[] = {12, 2, 8, 8, 6, 5, 3, 5, 0, 3, 1};
	int f[] = { 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4 };

	criaEventos(s, f, 11);

	system("pause");
	return 0;
}
