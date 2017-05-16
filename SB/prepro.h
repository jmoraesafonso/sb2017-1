#ifndef PREPRO_H
#define PREPRO_H
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Linha{
    string label;
    string operacao;
    vector<string> operandos;
};



struct Erro{
    string linhaerro;
    string msgerro;
    Erro(string linha, string msg){
        linhaerro = linha;
        msgerro = msg;
    }
};
class PrePro
{
public:
    PrePro(char *nome_arquivo);
    void run();

private:

    vector<vector<string>> token;
    ifstream arquivo;
    stringstream arqfonte;
    stringstream modificavel;
    bool findif();
    void removecoment();
    void findtokens();
    bool findequ();
    unordered_map <string,int> equMap;
    vector<Erro> erro;
};

#endif // PREPRO_H
