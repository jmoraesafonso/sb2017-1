#include "prepro.h"

PrePro::PrePro(char *nome_arquivo)
{
    arquivo.open(nome_arquivo,ifstream::binary);        //Abre o arquivo com nome: "nome_arquivo"

    if(!arquivo){
        cout<<"Arquivo nao pode ser aberto no pre-processamento."<<endl;
        exit(1);
    }
    arqtodo<<arquivo.rdbuf();
    arquivo.close();
}

//
void PrePro::run(){
    removecoment();
    //bool achouIF = findif();
}

bool PrePro::findif(){
    arquivo.seekg(0,arquivo.beg);
    string buffer;
    while(!arquivo.eof()){
        getline(arquivo, buffer);
        int position = buffer.find("IF");
    }
}

void PrePro::removecoment()
{
    int pos;
    string buff;
    string aux;
    while (getline(arqtodo,buff)) {
        pos = buff.find(";");
        if(pos!=string::npos){
            buff.replace(pos, buff.length(), "");
        }
        aux.append(buff+"\n");
    }
    arqtodo = aux;
}
