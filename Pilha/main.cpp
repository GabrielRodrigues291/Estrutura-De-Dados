#include <iostream>
#define MAX 5
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
struct No {
	int topo;
	string resp;
	int *prox;
	int pilha[MAX];
};

void Vazia(No *p) {
	p->topo = -1;
}

int cheiavazia(No *p) {
	if(p->topo == -1) {
		return 0;
	} else {
		return 1;
	}
}

void encher(No *p, int valor) {
	if(p->topo == -1 || p->topo != MAX) {		
			p->topo++;
			p->pilha[p->topo] = valor;
		
	} else {
		cout << "Pilha Cheia\n";
	}
}

int esvaziar(No *p) {
	
	if(cheiavazia(p) == -1) {
		cout << "Pilha Esta Vazia";
	} else {
		while(p->topo != -1) {
			cout <<  p->pilha[p->topo];
			p->topo--;
		}
	}
}
int main(int argc, char** argv) {
	No p;
	Vazia(&p);
	encher(&p,1);
	encher(&p,2);
	encher(&p,3);
	encher(&p,4);
	encher(&p,5);
	esvaziar(&p);
	esvaziar(&p);
	esvaziar(&p);
	esvaziar(&p);
	esvaziar(&p);
	encher(&p,4);
}




