#include "prepro.h"
#include <stdlib.h> 

PrePro::PrePro(char *nome_arquivo)
{
    arquivo.open(nome_arquivo,ifstream::binary);        //Abre o arquivo com nome: "nome_arquivo"

    if(!arquivo){
        cout<<"Arquivo nao pode ser aberto no pre-processamento."<<endl;
        exit(1);
    }
    arqfonte<<arquivo.rdbuf();

    arquivo.close();
}

//
void PrePro::run(){
    removecoment();
    removeEspaco();
    separatokens();
    imprimetokens();
    //bool achouIF = findif();
}

/*bool PrePro::findif(){

}*/

void PrePro::imprimetokens(){

}

bool PrePro::findequ(){
    int pos;
    string buff;
    string aux;
    while (getline(arqfonte,buff)) {
        pos = buff.find("EQU");
        if(pos!=string::npos){
            int pos_label = buff.find(":");
            if((pos_label>pos)||(pos_label==string::npos)){
                erro.push_back(Erro(buff, "erro sintatico: diretiva EQU. Uso: <rotulo>: EQU <numero>"));
            }
            else {
                 int pos_label = buff.find(":");
            }
        }
    }
}

void PrePro::removecoment()
{
    int pos;
    string buff;
    string aux;
    while (getline(arqfonte,buff)) {
        pos = buff.find(";");
        if(pos!=string::npos){
            buff.replace(pos, buff.length(), "");
        }
        aux.append(buff+"\n");
    }
    modificavel.str(""); // limpa arqtodo
    modificavel.clear(); // limpa `erros`
    modificavel.str(aux);// aqrtodo = aux
    cout<<"noComents:"<<aux<<endl;
}

void PrePro::removeEspaco()
{
    int pos_espaco;
    int pos_tab;
    int count=1; //recebe o numero de ocorrencias de espaços excedentes;
    string buff;
    string aux;
    while (getline(modificavel,buff)) {
	//cout<<"tam:"<<buff.size()<<"\n"<<endl;
        pos_espaco = buff.find(" ",0);
	pos_tab = buff.find("\t",0);
        while(pos_tab!=string::npos){
	    //cout<<"pos_tab:"<<pos_tab<<"\n"<<endl;
	    buff.erase(pos_tab,1);
	    pos_tab = buff.find("\t",pos_tab+1);
        }
	
        while((pos_espaco!=string::npos)){
	    //cout<<"pos_espaco:"<<pos_espaco<<"\n"<<endl;
	    if (pos_espaco==0){
		buff.erase(pos_espaco,1);
	    }
	    while(buff[pos_espaco+1]==' '){
	    	buff.erase(pos_espaco,1);
	    }
	    pos_espaco = buff.find(" ",pos_espaco+1);
        }
	
        if(buff.size()!=0){ //retira as linhas vazias
		aux.append(buff+"\n");
	}
    }
    modificavel.str(""); // limpa arqtodo
    modificavel.clear(); // limpa `erros`
    modificavel.str(aux);// aqrtodo = aux
    cout<<"noEspaços:"<<aux<<endl;
}

