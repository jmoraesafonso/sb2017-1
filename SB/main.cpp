#include <iostream>
#include <fstream>
#include <string>
#include "prepro.h"
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
        arquivo.close();
	}
    string diretiva(argv[1]);
    if (diretiva=="-p"){
        PrePro prepro(argv[2]);
        prepro.run();
    }

    else if (diretiva=="-o"){

    }

    else{
        cout<<"Diretiva invalida"<<endl;
        return 0;
    }
	 
	
	return (0);
}
