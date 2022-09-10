#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

struct No {
	int valor;

	No *prox;
};

void Inserir(No **inicio, int valor) {
	
	No *novo = new(No); // criei um No;
	novo->valor = valor;//fiz uma caixinha
	novo->prox = NULL;
	if(*inicio == NULL) {
		*inicio = novo;
	
	} else {
		

		No *aux = *inicio;
		while(aux->prox != NULL) {
			aux = aux->prox;
		}
		
		aux->prox = novo;
	}
}

void MostrarLista(No **inicio) {
	No *aux = *inicio;
				
	while(aux != NULL) {
		cout << aux->valor << "\n";
		aux = aux->prox;
	}
}

int InserirNaPeniultima(No **inicio) {
	
	No *aux = *inicio;
	No *aux2 = *inicio;
	No *aux3 = *inicio;
	
	while(aux->prox != NULL) {
		aux = aux->prox;
	}
	
	while(aux2->prox != aux) {
		aux3 = aux2;
		aux2 = aux2->prox;
		
	}
	
	aux3->prox = aux;
	
	// [10] [20] [40] null
	
	

	
}
int main(int argc, char** argv) {
	
	No *inicio = NULL;
	Inserir(&inicio,10);
	Inserir(&inicio,20);
	Inserir(&inicio,30);
	Inserir(&inicio,40);
	MostrarLista(&inicio);
	cout << "\n\n\n";
	InserirNaPeniultima(&inicio);
	MostrarLista(&inicio);
	return 0;
}
