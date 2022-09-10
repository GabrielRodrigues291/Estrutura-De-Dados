#include <iostream>
#define max 10
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Grafo{
	int matrizadj[max][max];
	int qtdVertiz,qtdAresta;
	string Visitador[max] ;
	string PilhaAmigos[max] = {"A","B","C","D","E","F","G","H","I","J"};
	Grafo *prox;
};

void IniciarGrafo(Grafo *grafo,int qtdVertiz) {
	grafo->qtdVertiz = qtdVertiz;
	grafo->qtdAresta = 0;
	
	for(int i = 0; i <= qtdVertiz; i++) {
		for(int j = 0; j <= qtdVertiz; j++)
			grafo->matrizadj[i][j] = 0;
	}
	
	return;
	/*      A   B   C   D   E   F   G   H   I   J 
		A  [0] [0] [0] [0] [0] [0] [0] [0] [0] [0]
		B  [0] [0] [0] [0] [0] [0] [0] [0] [0] [0]
		C  [0] [0] [0] [0] [0] [0] [0] [0] [0] [0]
		D  [0] [0] [0] [0] [0] [0] [0] [0] [0] [0]
		E  [0] [0] [0] [0] [0] [0] [0] [0] [0] [0]
		F  [0] [0] [0] [0] [0] [0] [0] [0] [0] [0]
		G  [0] [0] [0] [0] [0] [0] [0] [0] [0] [0]
		H  [0] [0] [0] [0] [0] [0] [0] [0] [0] [0]
		I  [0] [0] [0] [0] [0] [0] [0] [0] [0] [0]
		J  [0] [0] [0] [0] [0] [0] [0] [0] [0] [0]
	*/
}


void InserirAresta(Grafo *grafo,int l,int c) {
	//l Linha //c Coluna
	if(grafo->matrizadj[l][c] == 1) {
		return;
	} else {
		grafo->matrizadj[l][c] = 1;
		grafo->qtdAresta = +1;
	}
}

int MostrarGrafo(Grafo *grafo) {
	cout << "    A B C D E F G H I J ";
	cout << "\n";
	for(int i = 0; i <= grafo->qtdVertiz; i++) {
		cout << "\n";
		if(i == 0)
			cout << "A: ";
		if(i == 1)
			cout << "B: ";
		if(i == 2)
			cout << "C: ";
		if(i == 3)
			cout << "D: ";
		if(i == 4)
			cout << "E: ";
		if(i == 5)
			cout << "F: ";
		if(i == 6)
			cout << "G: ";
		if(i == 7)
			cout << "H: ";
		if(i == 8)
			cout << "I: ";
		if(i == 9)
			cout << "J: ";
		for(int j = 0; j <= grafo->qtdVertiz; j++)
			cout << " " << grafo->matrizadj[i][j];
	}
	
}

void MostarAmigos(Grafo *grafo) {

	for(int i = 0; i <= grafo->qtdVertiz; i++) {
		grafo->PilhaAmigos[i];
		for(int j = 0; j <= grafo->qtdVertiz; j++) {
			if(grafo->matrizadj[i][j] == 1) {
		
				grafo->Visitador[i] +=  grafo->PilhaAmigos[j];
			} 						
		}		
	}
}

void Visitador(Grafo *grafo) {

	for(int i = 0; i <= grafo->qtdVertiz; i++) {
		cout << grafo->PilhaAmigos[i] << "->";
		for(int j = 0; j < grafo->qtdAresta; j++) {
			cout << grafo->Visitador[i];
		}
		cout << "\n";
	}
}
bool BuscaProfunda(Grafo *grafo, int l,int c) {
	if(grafo->matrizadj[l][c] == 1)
		return true; // tem caminho
	else
		return false;
}
int main(int argc, char** argv) {
	Grafo grafo;
	IniciarGrafo(&grafo,max-1);
	InserirAresta(&grafo,1,1);
	InserirAresta(&grafo,1,3);
	InserirAresta(&grafo,3,4);
	InserirAresta(&grafo,7,9);
	MostrarGrafo(&grafo);
	cout << "\n\n";
	MostarAmigos(&grafo);
	Visitador(&grafo);
	cout << "\n\n";
	cout << BuscaProfunda(&grafo,7,9);
	return 0;
}
