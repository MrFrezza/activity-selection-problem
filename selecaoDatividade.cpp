#include <iostream>
#include <string>
#include <queue>

using namespace std;

// define a estrutura de uma atividade
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


// Ordena os eventos passados pelo final em ordem crescente
void criaEventos(int s[], int f[], int size) 
{
	// Inicia a fila de prioridade
	priority_queue<Atividade*, vector<Atividade*>, compara> minHeap;

	// Popula a heap
	for (int i = 0; i < size; i++)
	{
		minHeap.push(new Atividade(s[i], f[i]));
	}

	int ctrlFim = 0;

	cout << "Maior sequencia de atividades e seus respectivos tempos de inicializacao e finalizacao: \n\n";

	// Itera pela fila de prioridade exibindo apenas a melhor escolha local
	for (int i = 0; i < size; i++)
	{	
		// Verifica qual é a melhor atividade em sequencia
		if (ctrlFim <= minHeap.top()->inicio)
		{
			cout << "Atividade " << i+1 << " = Inicio " << minHeap.top()->inicio << " | Fim " << minHeap.top()->fim << "\n";
			ctrlFim = minHeap.top()->fim;
		}
		minHeap.pop();
	}
	cout << "\n";
}

int main ()
{
	// Horários de inicio das atividades
	int s[] = {12, 2, 8, 8, 6, 5, 3, 5, 0, 3, 1};

	// Horários final das atividades
	int f[] = {14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4 };

	criaEventos(s, f, 11);

	system("pause");
	return 0;
}
