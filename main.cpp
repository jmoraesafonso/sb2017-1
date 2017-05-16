#include <iostream>
#include <fstream>
using namespace std; //desambiguacao dos nomes das funcoes

int main (int argc, char *argv[] ){
	
	if (argc != 3){ 
		cout<<"Erro: Argumento faltante."<<endl;
		return (0);
	}
	
	else if (argc == 3){
		ifstream arquivo (argv[2], ifstream::in);
		if (!arquivo) { cout<<"Erro: impossivell abrir o arquivo."<<endl;
			return(0);
		}
	}
	
	 
	
	return (0);
}
