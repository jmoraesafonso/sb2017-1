#include "prepro.h"

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
    findtokens();
    //bool achouIF = findif();
}

bool PrePro::findif(){

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
}

void PrePro::findtokens()
{
    modificavel.seekg(0, ios::beg);
    string buffer;
    while (getline(modificavel, buffer)) {
        token.push_back(vector<string>());
        for(uint i = 0; i < buffer.size(); i++){
            if(buffer[i] == ':' || buffer[i] == '+' || buffer[i] == ' '){
                int pos = buffer.find(string(1, buffer[i]));
                cout << buffer.substr(pos) << endl;
                getchar();
//                token.back().push_back(buffer.substr(pos));
            }
            if(buffer[i] != ' '){
                string operador(1, buffer.at(i));
                token.back().push_back(operador);
                buffer.replace(buffer.begin(), buffer.begin()+i, "");
            }
        }
    }
    for(auto line : token)
        for(auto element : line)
            cout << element << endl;
}
