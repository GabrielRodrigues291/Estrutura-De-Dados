#include<iostream>
#include<stdlib.h>


using namespace std;

struct Arvore{
	int valor;
	Arvore *esquerda,*direita;
};

void Inserir(Arvore **Raiz,int valor) {
	Arvore *no = new Arvore;
	no->valor = valor;
	no->esquerda = no->direita = NULL;
	
	if(*Raiz == NULL) {
		*Raiz = no;
	} 
	else{
		
			if(valor < (*Raiz)->valor) {
				if((*Raiz)->esquerda == NULL)
					(*Raiz)->esquerda = no;
				else
					Inserir(&(*Raiz)->esquerda,valor);	
			}
			else{
			
				if(valor > (*Raiz)->valor)
					if((*Raiz)->direita == NULL)
						(*Raiz)->direita = no;	
					else
						Inserir(&(*Raiz)->direita,valor);
						
			}
		} 
		
			
							
}

void Imprimir(Arvore **Raiz) {
	
	if(*Raiz == NULL)
		return;
		/*
					 	RAIZ
   					 	(500)
			    (300)	      	(900)
			(90)    ( )  	(null)	(null)
		(null) (null)
	*/
	
	cout << " | " <<(*Raiz)->valor << "|";
	Imprimir(&(*Raiz)->esquerda);
	Imprimir(&(*Raiz)->direita);

}

int busca(Arvore **raiz,int valor) {
	if(*raiz == NULL) 
		return 0;
	else 	
		if((*raiz)->valor == valor)
			return 1;
		else
			if((*raiz)->esquerda->valor == valor)
				return 1;
			else
				busca(&(*raiz)->esquerda,valor);
				
			if((*raiz)->direita->valor == valor)
				return 1;		
			else
				busca(&(*raiz)->esquerda,valor);	
			
		
	
}
int main()
{
	Arvore *raiz = NULL;   
	Inserir(&raiz,500);
	Inserir(&raiz,300);
	Inserir(&raiz,90);
	Inserir(&raiz,900);
	Inserir(&raiz,800);
	Imprimir(&raiz);
	cout << "\n\n\n";
	cout << busca(&raiz,300);
	
		
}
