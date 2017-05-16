#ifndef PREPRO_H
#define PREPRO_H
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class PrePro
{
public:
    PrePro(char *nome_arquivo);
    void run();

private:
    ifstream arquivo;
    stringstream arqtodo;
    bool findif();
    void removecoment();
};

#endif // PREPRO_H
