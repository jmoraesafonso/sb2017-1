
/*  MONTADOR
 *  Caio Neno Silva Cavalcante - 10/0095402
 *  Pedro Henrique Hecksher Faber - 10/0119140
 */


#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <ctype.h>





 struct tokens
 {
	 std::string label;
	 std::string operacao;
	 std::string operando1;
	 std::string operando2;
	 std::string diretiva;
	 int aux_ope1;
	 int aux_ope2;
	 bool secao;
 };

 struct tokens_mem
 {
	 std::string label;
	 std::string operacao;
	 std::string operando1;
	 int end_ope1;
	 std::string operando2;
	 int end_ope2;
	 std::string diretiva;
	 int data_num;
	 int memoria;
	 bool secao;
	 int linha_original;
	 int aux_ope1;
	 int aux_ope2;
	 int end_linha;

 };


//função do analisador léxico e alguns sintáticos
//função do analisador léxico e alguns sintáticos
int analisador (std::string word, int linenum, char casenum){

	int count1 = 0;

	switch (casenum){

		// Caso default
		case 'A':
			break;

		// Caso de label
		case 'B':
			for (count1 = 0; count1<(word.length()-1); count1++)
			{
				if (count1 == 0 && word[count1] > 0 && word[count1] < 65){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 == 0 && word[count1] > 90 && word[count1] < 97){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 == 0 && word[count1] > 122){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 > 0 && word[count1] > 0 && word[count1] < 48){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 > 0 && word[count1] > 57 && word[count1] < 65){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 > 0 && word[count1] > 90 && word[count1] < 95){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 > 0 && word[count1] > 95 && word[count1] < 97){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 > 0 && word[count1] > 122){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
			}
			break;

		// Caso de operação ou de diretiva
		// Também se aplica ao caso de "operando" do comando SECTION e de operando do comando IF
		case 'C':
			for (count1 = 0; count1<word.length(); count1++)
			{
				if (count1 == 0 && word[count1] > 0 && word[count1] < 65){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 == 0 && word[count1] > 90 && word[count1] < 97){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 == 0 && word[count1] > 122){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 > 0 && word[count1] > 0 && word[count1] < 48){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 > 0 && word[count1] > 57 && word[count1] < 65){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 > 0 && word[count1] > 90 && word[count1] < 95){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 > 0 && word[count1] > 95 && word[count1] < 97){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 > 0 && word[count1] > 122){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
			}
			break;

		// Caso de haver somente operando 1 em área de seção de texto
		// Também se aplica ao caso de operando 2 em área de seção de texto
		case 'D':
			for (count1 = 0; count1<word.length(); count1++)
			{
				if (count1 == 0 && word[count1] > 0 && word[count1] < 65){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 == 0 && word[count1] > 90 && word[count1] < 97){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 == 0 && word[count1] > 122){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 > 0 && word[count1] > 0 && word[count1] < (word.length()-1) && word[count1] < 43){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 > 0 && word[count1] > 43 && word[count1] < (word.length()-1) && word[count1] < 48){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 > 0 && word[count1] > 57 && word[count1] < (word.length()-1) && word[count1] < 65){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 > 0 && word[count1] > 90 && word[count1] < (word.length()-1) && word[count1] < 95){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 > 0 && word[count1] > 95 && word[count1] < (word.length()-1) && word[count1] < 97){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 > 0 && word[count1] > 122 && word[count1] < (word.length()-1)){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 == (word.length()-1) && word[count1] > 0 && word[count1] < 48){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 == (word.length()-1) && word[count1] > 57 && word[count1] < 65){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 == (word.length()-1) && word[count1] > 90 && word[count1] < 97){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 == (word.length()-1) && word[count1] > 122){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
			}
			break;

		// Caso do operando 1 em área de seção de texto, quando há operando 1 e operando 2
		case 'E':
			for (count1 = 0; count1<(word.length()-1); count1++)
			{
				if (count1 == 0 && word[count1] > 0 && word[count1] < 65){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 == 0 && word[count1] > 90 && word[count1] < 97){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 == 0 && word[count1] > 122){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 > 0 && word[count1] > 0 && word[count1] < (word.length()-2) && word[count1] < 43){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 > 0 && word[count1] > 43 && word[count1] < (word.length()-2) && word[count1] < 48){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 > 0 && word[count1] > 57 && word[count1] < (word.length()-2) && word[count1] < 65){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 > 0 && word[count1] > 90 && word[count1] < (word.length()-2) && word[count1] < 95){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 > 0 && word[count1] > 95 && word[count1] < (word.length()-2) && word[count1] < 97){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 > 0 && word[count1] > 122 && word[count1] < (word.length()-2)){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 == (word.length()-2) && word[count1] > 0 && word[count1] < 48){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 == (word.length()-2) && word[count1] > 57 && word[count1] < 65){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 == (word.length()-2) && word[count1] > 90 && word[count1] < 97){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
				else if (count1 == (word.length()-2) && word[count1] > 122){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
				}
			}
			break;

		// Caso de operando SPACE na seção de dados (só pode ser um número positivo e não pode haver operando 2 na seção de dados)
		case 'F':
			for (count1 = 0; count1<word.length(); count1++)
			{
				if (count1 == 0 && word[count1] > 0 && word[count1] < 48){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser um número inteiro positivo." << std::endl;
				}
				else if (count1 == 0 && word[count1] > 57 && word[count1] < 65){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser um número inteiro positivo." << std::endl;
				}
				else if (count1 == 0 && word[count1] > 64 && word[count1] < 91){
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser um número inteiro positivo." << std::endl;
				}
				else if (count1 == 0 && word[count1] > 90 && word[count1] < 97){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser um número inteiro positivo." << std::endl;
				}
				else if (count1 == 0 && word[count1] > 96 && word[count1] < 123){
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser um número inteiro positivo." << std::endl;
				}
				else if (count1 == 0 && word[count1] > 122){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser um número inteiro positivo." << std::endl;
				}
				else if (count1 > 0 && word[count1] > 0 && word[count1] < 48){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser um número inteiro positivo." << std::endl;
				}
				else if (count1 > 0 && word[count1] > 57 && word[count1] < 65){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser um número inteiro positivo." << std::endl;
				}
				else if (count1 > 0 && word[count1] > 90 && word[count1] < 95){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser um número inteiro positivo." << std::endl;
				}
				else if (count1 > 0 && word[count1] > 95 && word[count1] < 97){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser um número inteiro positivo." << std::endl;
				}
				else if (count1 > 0 && word[count1] > 122){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser um número inteiro positivo." << std::endl;
				}
			}
			break;

		// Caso de operando CONST na seção de dados (só pode ser um número, positivo ou negativo, e não pode haver operando 2 na seção de dados)
		case 'G':
			for (count1 = 0; count1<word.length(); count1++)
			{
				if (count1 == 0 && word[count1] > 0 && word[count1] < 45){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser um número inteiro." << std::endl;
				}
				else if (count1 == 0 && word[count1] > 45 && word[count1] < 48){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser um número inteiro." << std::endl;
				}
				else if (count1 == 0 && word[count1] > 57 && word[count1] < 65){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser um número inteiro." << std::endl;
				}
				else if (count1 == 0 && word[count1] > 64 && word[count1] < 91){
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser um número inteiro." << std::endl;
				}
				else if (count1 == 0 && word[count1] > 90 && word[count1] < 97){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser um número inteiro." << std::endl;
				}
				else if (count1 == 0 && word[count1] > 96 && word[count1] < 123){
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser um número inteiro." << std::endl;
				}
				else if (count1 == 0 && word[count1] > 122){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser um número inteiro." << std::endl;
				}
				else if (count1 > 0 && word[count1] > 0 && word[count1] < 48){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser um número inteiro." << std::endl;
				}
				else if (count1 > 0 && word[count1] > 57 && word[count1] < 65){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser um número inteiro." << std::endl;
				}
				else if (count1 > 0 && word[count1] > 64 && word[count1] < 91){
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser um número inteiro." << std::endl;
				}
				else if (count1 > 0 && word[count1] > 90 && word[count1] < 95){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser um número inteiro." << std::endl;
				}
				else if (count1 > 0 && word[count1] > 94 && word[count1] < 96){
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser um número inteiro." << std::endl;
				}
				else if (count1 > 0 && word[count1] > 95 && word[count1] < 97){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser um número inteiro." << std::endl;
				}
				else if (count1 > 0 && word[count1] > 96 && word[count1] < 123){
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser um número inteiro." << std::endl;
				}
				else if (count1 > 0 && word[count1] > 122){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser um número inteiro." << std::endl;
				}
			}
			break;

		// Caso de operando da diretiva EQU em área de seção de texto
		case 'H':
			for (count1 = 0; count1<word.length(); count1++)
			{
				if (count1 == 0 && word[count1] > 0 && word[count1] < 48){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser 0 ou 1." << std::endl;
				}
				else if (count1 == 0 && word[count1] > 49 && word[count1] < 58){
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser 0 ou 1." << std::endl;
				}
				else if (count1 == 0 && word[count1] > 57 && word[count1] < 65){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser 0 ou 1." << std::endl;
				}
				else if (count1 == 0 && word[count1] > 64 && word[count1] < 91){
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser 0 ou 1." << std::endl;
				}
				else if (count1 == 0 && word[count1] > 90 && word[count1] < 97){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser 0 ou 1." << std::endl;
				}
				else if (count1 == 0 && word[count1] > 96 && word[count1] < 123){
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser 0 ou 1." << std::endl;
				}
				else if (count1 == 0 && word[count1] > 122){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser 0 ou 1." << std::endl;
				}
				else if (count1 > 0 && word[count1] > 0 && word[count1] < 48){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser 0 ou 1." << std::endl;
				}
				else if (count1 > 0 && word[count1] > 57 && word[count1] < 65){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser 0 ou 1." << std::endl;
				}
				else if (count1 > 0 && word[count1] > 90 && word[count1] < 95){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser 0 ou 1." << std::endl;
				}
				else if (count1 > 0 && word[count1] > 95 && word[count1] < 97){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser 0 ou 1." << std::endl;
				}
				else if (count1 > 0 && word[count1] > 122){
					std::cout << "Erro léxico na linha "<< linenum+1 << std::endl;
					std::cout << "Erro sintático na linha "<< linenum+1 << ". Este operando só pode ser 0 ou 1." << std::endl;
				}
			}
			break;
	}
	return (0);
}


 int main(){
	//variáveis usadas ao longo do código
	bool section = false; //0 para text, 1 para data
	bool check_equ;
	bool endcomma = false;
	bool hasText = false;
	bool hasData = false;
	bool hasBegin = false;
	bool hasEnd = false;
	bool hasStop = false;
	char c, ch;
	int i=0, j;
	int num_lines2;
	int counter = 0;
	int num_aux;
	int n, m;
	std::string arquivo_entrada;
	std::string arquivo_saida;




	std::cout << "Olá, por favor digite o nome do arquivo de entrada.\n.";
	std::cout << "Obs: O arquivo não deve conter extensão.\n.";

	getline (std::cin, arquivo_entrada);

	std::cout << "Muito obrigado! Por favor, agora digite o nome do arquivo de saída.\n.";
	std::cout << "Lembre-se: O arquivo não deve conter extensão.\n.";

	getline (std::cin, arquivo_saida);


	std::vector<std::string> tokens;

	std::string palavra;

	//conta o numero de linhas
	std::ifstream inFile(arquivo_entrada.c_str());
	int num_lines = std::count(std::istreambuf_iterator<char>(inFile),
			 std::istreambuf_iterator<char>(), '\n');

	num_lines=num_lines+1;

	//imprime o numero de linhas na tela
	std::cout << "Número de linhas:" << num_lines << std::endl;


	//cria struct para a primeira alocao
	struct tokens linha[num_lines];

	//coloca a palavra empty em cada local e false no boleano
	for (i=0; i<num_lines; i++)
	{
		linha[i].operando1 = "EMPTY";
		linha[i].operando2 = "EMPTY";
		linha[i].aux_ope1 = 0;
		linha[i].aux_ope2 = 0;
		linha[i].diretiva = "EMPTY";
		linha[i].label = "EMPTY";
		linha[i].operacao = "EMPTY";
		linha[i].secao = false;
	}



	//pegar o arquivo de texto e colocar numa string só

    std::ifstream in(arquivo_entrada.c_str());
    std::stringstream buffer;
    buffer << in.rdbuf();
    std::string test = buffer.str();

    for (i=0; i< test.size(); i++)
    {
    	test[i] = toupper(test[i]);
    }

    std::cout << test << std::endl << std::endl;

    //criar variaveis que vao agir como cursores
    size_t pos1 = 0;
    size_t pos2;


    //cria um array
    std::string str[num_lines];


    //salva cada linha no vetor de strings str[i]
    for (i=0; i<num_lines; i++)
    {
        pos2 = test.find("\n", pos1); //procura pelo final da linha, pos2 vai ser aonde encontrar.
        str[i] = test.substr(pos1, (pos2-pos1)); //cria um substring
        pos1 = pos2+1; // coloca pos1 no caracter logo depois do pos2
	}


    ////////////////////////////////////////////////
    // descobre o que é cada palavra de cada linha /
    ////////////////////////////////////////////////


    for (i=0; i<num_lines; i++)
    {
    	std::stringstream is(str[i]);
		bool issection = false;
		bool isequ = false;
		bool iscopy = false;
		bool isif = false;
		bool HASoperationORdirective = false;
		bool alreadyPrinted = false;
		bool plussign = false;
		bool isspace = false;
		bool isconst = false;
		bool hasLabel = false;
		char numcase = 'A';
		std::string limpa_linha;



		limpa_linha = str[i];

		while (limpa_linha[limpa_linha.size() - 1] == 32)
		{
				limpa_linha = limpa_linha.substr(0, limpa_linha.size() - 1);
		};

		while (limpa_linha[0] == 32)
		{
				limpa_linha = limpa_linha.substr(1, limpa_linha.size());
		};

		if (i == 0)
		{
			std::cout << limpa_linha;
		}

    	//determina se é section text
    	if (limpa_linha == "SECTION TEXT")
    	{
			section = false;
			hasText = true;
			//std::cout << str[i] << " " << section << std::endl;
			continue;
    	}


    	//determina se é section data
    	else if (limpa_linha == "SECTION DATA")
    	{
			section = true;
			hasData =true;
			//std::cout << str[i] << " " << section << std::endl;
			continue;
    	}



    	//determina que tipo de secao a linha está: DATA ou TEXT
    	if (section == true)
        {
        	linha[i].secao = true;
        }


		while( is >> palavra)
		{

			//retira comentários
			if(palavra[0] == ';')
			{
				break;
			}

			// no caso de ser section, checa se	é text ou data
			if (issection == true){
				if ((palavra != "TEXT")&&(palavra != "DATA")){
					std::cout << "Erro sintático na linha "<< i+1 << ". Nome incorreto de Seção. Use somente text ou data após o comando Section."<<std::endl;
					numcase = 'C';
					analisador (palavra,i,numcase);
					alreadyPrinted = true;
				}
				issection = false;
			}

			// checa se é section
			if (palavra == "SECTION"){
				issection = true;
			}

			//checa se é label
			ch = palavra[palavra.length() - 1];
			if (ch == ':' && issection == false)
			{
				if (hasLabel == true){
		    		std::cout << "Erro sintático na linha:" << i + 1<< ". Há dois rótulos na mesma linha." << std::endl;
				}

				if (hasLabel == false){
					linha[i].label = palavra.substr(0, palavra.size()-1);
					hasLabel = true;
				}
					//std::cout << "label da linha "<< i << ": " << linha[i].label << std::endl;
				numcase = 'B';
				analisador (palavra, i, numcase);

			}

			//checa se é operacao
			else if ((palavra == "ADD"
				|| palavra == "SUB"
				|| palavra == "MULT"
				|| palavra == "DIV"
				|| palavra == "JMP"
				|| palavra == "JMPN"
				|| palavra == "JMPP"
				|| palavra == "JMPZ"
				|| palavra == "COPY"
				|| palavra == "LOAD"
				|| palavra== "STORE"
				|| palavra== "INPUT"
				|| palavra == "OUTPUT"
				|| palavra == "STOP")
				&& issection == false)
			{
				linha[i].operacao = palavra;
				//std::cout << "operacao da linha "<< i << ": " << linha[i].operacao << std::endl;			std::cout <<  << std::endl;

				numcase = 'C';
				analisador (palavra,i,numcase);
				HASoperationORdirective = true;

				if (palavra == "COPY")
				{
					iscopy = true;
				}
				if (palavra == "STOP")
				{
					hasStop = true;
				}


			}

			//checa se é diretiva
			else if ((palavra == "BEGIN"
				|| palavra == "END"
				|| palavra == "SPACE"
				|| palavra == "CONST"
				|| palavra == "PUBLIC"
				|| palavra == "EXTERN"
				|| palavra == "IF"
				|| palavra == "EQU")
				&& issection == false)
			{
				linha[i].diretiva = palavra;
				//std::cout << "diretiva da linha "<< i << ": " << linha[i].diretiva << std::endl;

				numcase = 'C';
				analisador (palavra,i,numcase);
				HASoperationORdirective = true;

				if (palavra == "EQU")
				{
					isequ = true;
				}
				if (palavra == "IF")
				{
					isif = true;
				}
				if (palavra == "SPACE")
				{
					isspace = true;
				}
				if (palavra == "CONST")
				{
					isconst = true;
				}
				if (palavra == "BEGIN")
				{
					hasBegin = true;
				}
				if (palavra == "END")
				{
					hasEnd = true;
				}
			}
			// operando 2 da secao de texto
			else if (plussign==true && linha[i].operando2 != "EMPTY" && linha[i].operando1 != "EMPTY" && isequ == false && isif == false)
			{
				std::stringstream string_aux(palavra);
				string_aux >> num_aux;
				linha[i].aux_ope2 = num_aux;

				plussign=false;
				continue;
								//std::cout << "ope2 da secao de texto, linha "<< i << ": " << linha[i].operando2 << std::endl;
			}



			else if (plussign==true && linha[i].operando1 != "EMPTY")
			{
				if (endcomma == true)
				{
		    		std::cout << "Erro sintático na linha:" << i + 1<< ". Tem uma vírgula colocada em local errado." << std::endl;
		    	}

				if ( palavra[palavra.length()-1] == ',')
				{
					endcomma = true;
				}

				std::stringstream string_aux(palavra);
				string_aux >> num_aux;
				linha[i].aux_ope1 = num_aux;

				plussign=false;
				continue;
								//std::cout << "ope2 da secao de texto, linha "<< i << ": " << linha[i].operando2 << std::endl;
			}


			//vê se a palavra é só um +
			else if (palavra == "+"
					&& linha[i].secao != true
					&& linha[i].operando1 != "EMPTY"
					&& HASoperationORdirective == true
					&& issection == false)
			{
				plussign=true;
				continue;
								//std::cout << "ope2 da secao de texto, linha "<< i << ": " << linha[i].operando2 << std::endl;
			}

			// operando 2 da secao de texto
			else if (linha[i].secao != true
					&& linha[i].operando1 != "EMPTY"
					&& linha[i].operando2 == "EMPTY"
					&& HASoperationORdirective == true
					&& issection == false)
			{
				if (endcomma == false)
				{
		    		std::cout << "Erro sintático na linha:" << i + 1 << ". Não tem uma vírgula no final do operando." << std::endl;
		    	}
				endcomma = false;

				linha[i].operando2 = palavra;
				numcase = 'D';
				analisador (palavra,i,numcase);

								//std::cout << "ope2 da secao de texto, linha "<< i << ": " << linha[i].operando2 << std::endl;
			}


			// operando 1 da secao de texto
			else if (linha[i].secao != true
					&& linha[i].operando1 == "EMPTY"
					&& linha[i].operando2 == "EMPTY"
					&& HASoperationORdirective == true
					&& issection == false)
			{

				endcomma = false;
				if ( palavra[palavra.length()-1] == ',')
				{
					endcomma = true;
				}

				if (endcomma ==  true)
				{
					linha[i].operando1= palavra.substr(0, palavra.length()-1);
				}
				else
				{
					linha[i].operando1= palavra;
				}


								//std::cout << "ope1 da secao de texto, linha "<< i << ": " << linha[i].operando1 << std::endl;
				if (palavra[(palavra.length()-1)] != 44 && isequ == false){
						numcase = 'D';
						analisador (palavra,i,numcase);
					}
				if (palavra[(palavra.length()-1)] == 44 && isequ == false){

					numcase = 'E';
					analisador (palavra,i,numcase);
				}

				if (isequ == true)
				{
					numcase = 'H';
					analisador (palavra, i, numcase);
					isequ = false;
				}
				if (isif == true)
				{
					numcase = 'C';
					analisador (palavra, i, numcase);
					isif = false;
				}

			}

			// operando 1 da secao de dados (vai ser sempre um numero)

			else if (linha[i].secao == true && HASoperationORdirective == true && issection == false)
			{
				linha[i].operando1= palavra;
								//std::cout << "ope da secao de data, linha "<< i << ": " << linha[i].operando1 << std::endl;

				if (isspace == true && isconst == false){
					numcase = 'F';
					analisador (palavra,i,numcase);
				}

				if (isspace == false && isconst == true){
					numcase = 'G';
					analisador (palavra,i,numcase);
				}
			}

			else if (HASoperationORdirective == false && alreadyPrinted == false && issection == false && palavra != "TEXT" && palavra != "DATA")
			{
				std::cout << "Erro sintático na linha "<< i+1 << ". A linha não tem operação nem diretiva válida." << std::endl;
				alreadyPrinted = true;
				numcase = 'C';
				analisador (palavra,i,numcase);
			}
		}
		HASoperationORdirective = false;
		if (linha[i].diretiva != "EMPTY" && linha[i].operacao != "EMPTY" && issection == false)
		{
			std::cout << "Erro sintático na linha "<< i+1 << ". A linha tem operação e diretiva ao mesmo tempo." << std::endl;
		}

		if (linha[i].diretiva == "EMPTY"
			&& linha[i].operacao == "EMPTY"
			&& alreadyPrinted == false
			&& issection == false
			&& ((linha[i].operando1 != "EMPTY")
			|| (linha[i].operando2 != "EMPTY")
			|| (linha[i].label != "EMPTY")))
		{
			std::cout << "Erro sintático na linha "<< i+1 << ". A linha não tem operação, nem diretiva." << std::endl;
		}


		//Checagem de diretivas e operações em seção errada
		if ((linha[i].diretiva == "SPACE"
			|| linha[i].diretiva == "CONST")
			&& (linha[i].secao == false))
		{
			std::cout << "Erro semântico na linha "<< i+1 << ". Esta diretiva deveria estar na seção DATA." << std::endl;
		}
		if ((linha[i].diretiva == "PUBLIC"
			|| linha[i].diretiva == "EXTERN"
			|| linha[i].diretiva == "IF"	// EI!!! IF E EQU PODEM ESTAR EM QUALQUER SEÇÃO OU SÓ NA SECTION TEXT???
 			|| linha[i].diretiva == "EQU")
			&& (linha[i].secao == true))
		{
			std::cout << "Erro semântico na linha "<< i+1 << ". Esta diretiva não deveria estar na seção DATA." << std::endl;
		}


		if ((linha[i].operacao == "ADD"
			|| linha[i].operacao == "SUB"
			|| linha[i].operacao == "MULT"
			|| linha[i].operacao == "DIV"
			|| linha[i].operacao == "JMP"
			|| linha[i].operacao == "JMPN"
			|| linha[i].operacao == "JMPP"
			|| linha[i].operacao == "JMPZ"
			|| linha[i].operacao == "COPY"
			|| linha[i].operacao == "LOAD"
			|| linha[i].operacao == "STORE"
			|| linha[i].operacao == "INPUT"
			|| linha[i].operacao == "OUTPUT"
			|| linha[i].operacao == "STOP")
			&& (linha[i].secao == true))
		{
			std::cout << "Erro semântico na linha "<< i+1 << ". Esta operação não deveria estar na seção DATA." << std::endl;
		}

		// Checagem do número de operandos em operações
		if ((linha[i].operacao == "ADD" || linha[i].operacao == "SUB" || linha[i].operacao == "MULT" || linha[i].operacao == "DIV" || linha[i].operacao == "JMP" || linha[i].operacao == "JMPN" || linha[i].operacao == "JMPP" || linha[i].operacao == "JMPZ" || linha[i].operacao == "LOAD" || linha[i].operacao == "STORE" || linha[i].operacao == "INPUT" || linha[i].operacao == "OUTPUT") && ((linha[i].operando1 == "EMPTY") || (linha[i].operando2 != "EMPTY"))){
			std::cout << "Erro sintático na linha "<< i+1 << ". Esta operação deveria receber um único operando." << std::endl;
		}
		if ((linha[i].operacao == "STOP") && ((linha[i].operando1 != "EMPTY") || (linha[i].operando2 != "EMPTY"))){
			std::cout << "Erro sintático na linha "<< i+1 << ". Esta operação não deveria receber nenhum operando." << std::endl;
		}
		if ((linha[i].operacao == "COPY") && ((linha[i].operando1 == "EMPTY") || (linha[i].operando2 == "EMPTY"))){
			std::cout << "Erro sintático na linha "<< i+1 << ". Esta operação não deveria receber nenhum operando." << std::endl;
		}
		/*if ((linha[i].diretiva == "SPACE") && ((linha[i].operando1 != "EMPTY") && (linha[i].operando2 != "EMPTY"))){
			std::cout << "Erro sintático na linha "<< i+1 << ". Esta diretiva não pode receber mais de um operando." << std::endl;
		}
		if ((linha[i].diretiva == "PUBLIC" || linha[i].diretiva == "EXTERN" || linha[i].diretiva == "IF" || linha[i].diretiva == "EQU") && ((linha[i].operando1 == "EMPTY") || (linha[i].operando2 != "EMPTY"))){
			std::cout << "Erro sintático na linha "<< i+1 << ". Esta diretiva deveria receber um único operando." << std::endl;
		}
		if ((linha[i].diretiva == "BEGIN" || linha[i].diretiva == "END") && ((linha[i].operando1 == "EMPTY") &&((linha[i].operando1 != "EMPTY") || (linha[i].operando2 != "EMPTY")) )){
			std::cout << "Erro sintático na linha "<< i+1 << ". EEsta diretiva não deveria receber nenhum operando." << std::endl;
		}*/    }

    if (hasText == false){
		std::cout << "Erro semântico. Está faltando SECTION TEXT." << std::endl;

    }

    if (hasData == false){
		std::cout << "Erro semântico. Está faltando SECTION DATA." << std::endl;

    }
    if (hasBegin == false && hasEnd == true)
    {
		std::cout << "Erro semântico. END sem BEGIN." << std::endl;

    }

    if (hasBegin == true && hasEnd == false)
    {
		std::cout << "Erro semântico. BEGIN sem END." << std::endl;

    }

    if (hasBegin == false && hasEnd == false && hasStop == false)
    {
		std::cout << "Erro semântico. Não é módulo e não há instrução STOP." << std::endl;

    }

    //checa se há modificação de valor constante
    for (i=0; i<num_lines; i++)
    {
    	if (linha[i].operacao == "COPY")
    	{
    		for (j=0; j<num_lines; j++)
    		{
    			if (linha[i].operando1 == linha[j].label)
    			{
    				if (linha[j].diretiva == "CONST")
    				{
    					std::cout << "Erro semântico na linha " << i + 1 << ". Há tentativa de alteração de um valor constante." << std::endl;
    				}
    			}
    		}
    	}
    }

    std::cout << "\n" << std::endl;


	//imprime para ver se está tudo ok
    /*for (i=0; i<=num_lines-1; i++)
    {

    		std::cout << "numero da linha: "<< i << std::endl;
    		std::cout << "operacao da linha: "<< linha[i].operacao << std::endl;
    		std::cout << "operando1 da linha: "<< linha[i].operando1 << std::endl;
    		std::cout << "auxiliar do operando1: "<< linha[i].aux_ope1 << std::endl;

    		std::cout << "operando2 da linha: "<< linha[i].operando2 << std::endl;
    		std::cout << "auxiliar do operando2: "<< linha[i].aux_ope2 << std::endl;

    		std::cout << "diretiva da linha: "<< linha[i].diretiva << std::endl;
    		std::cout << "label da linha: "<< linha[i].label << std::endl;

    		if (linha[i].secao == true)
    		{
    			std::cout << "secao de data" << "\n" << std::endl;
    		}
    		else
    		{
    			std::cout << "secao de texto" << "\n" << std::endl;
    		}
    }*/

    j=0;

    //conta o número de linhas não vazias
    for (i=0; i<num_lines; i++)
    {
    	if  (	linha[i].operando1 == "EMPTY"
    			&& linha[i].operando2 == "EMPTY"
    			&& linha[i].diretiva == "EMPTY"
    			&& linha[i].label == "EMPTY"
    			&& linha[i].operacao == "EMPTY")
    	{
    		continue;
    	}
    	else
    	{
    		j++;
    	}
    	//std::cout << j << std::endl;
    }


    ///////////////////////////////////////////////////
    // Cria Segunda Struct Contendo a Lista Arrumada //
    ///////////////////////////////////////////////////

    num_lines2 = j;
    j=0;
    num_aux =0;

    //cria struct com as linhas vazias limpas e com a memória utilizada
   	struct tokens_mem linha2[num_lines2];

    for (i=0; i<num_lines; i++)
    {
		linha2[j].data_num = 0;
		linha2[j].memoria = 0;
		linha2[j].end_ope1 = -1;
		linha2[j].end_ope2 = -1;
		linha2[j].linha_original = i;
		linha2[j].end_linha = 0;

			//limpa as linhas vazias
    	if  (	linha[i].operando1 == "EMPTY"
    			&& linha[i].operando2 == "EMPTY"
    			&& linha[i].diretiva == "EMPTY"
    			&& linha[i].label == "EMPTY"
    			&& linha[i].operacao == "EMPTY")
    	{
    		continue;
    	}

    	//iguala as structs
    	else
    	{
    		linha2[j].diretiva = linha[i].diretiva;
    		linha2[j].label = linha[i].label;
    		linha2[j].operacao = linha[i].operacao;
    		linha2[j].secao = linha[i].secao;
    		linha2[j].aux_ope1 = linha[i].aux_ope1;
    		linha2[j].aux_ope2 = linha[i].aux_ope2;

   			linha2[j].operando1 = "EMPTY";
    		linha2[j].operando2 = "EMPTY";

    		if (linha[i].secao == false)
    		{
        		linha2[j].operando1 = linha[i].operando1;
        		linha2[j].operando2 = linha[i].operando2;
    		}


    		else if (linha[i].secao == true && linha[i].operando1 != "EMPTY")
    		{
        		std::stringstream string_aux(linha[i].operando1);
        		string_aux >> num_aux;
            	//std::cout << num_aux << std::endl;
    			linha2[j].data_num = num_aux;
        		linha2[j].operando1 = linha[i].operando1;
    		}


    		else if (linha[i].secao == true && linha[i].diretiva == "SPACE" && linha[i].operando1 == "EMPTY")
    		{
    			linha2[j].data_num = 1;
    		}



    		if (linha2[j].secao == false && linha2[j].operacao != "EMPTY")
    		{
        		if (linha2[j].operacao != "EMPTY")
        		{
        			linha2[j].memoria++;
        		}

        		if (linha2[j].operando1 != "EMPTY")
    			{
        			linha2[j].memoria++;
    			}

        		if (linha2[j].operando2 != "EMPTY")
    			{
        			linha2[j].memoria++;
    			}
    		}
    		else if (linha2[j].secao == true )
    		{
    			linha2[j].memoria = linha2[j].data_num;
    		}

    		j++;
    	}
    }

    //CHECA IF E EQU
	check_equ = false;

    for (i=0; i<num_lines2-1; i++)
    {


    	if (linha2[i].diretiva == "EQU" && linha2[i].operando1 == "1")
		{
			check_equ = true;
			continue;

		}
		else if (linha2[i].diretiva == "EQU" && linha2[i].operando1 == "0")
		{
			check_equ = false;
			continue;
		}



		if (linha2[i].diretiva == "IF" && linha2[i].operando1 != "EMPTY")
		{


			for (j=0; j<=num_lines2-1; j++)
			{
				if (linha2[i].operando1 == linha2[j].label)
				{
					if (check_equ == true )
					{

						linha2[i+1].operando1 = "EMPTY";
						linha2[i+1].operando2 = "EMPTY";
						linha2[i+1].diretiva = "EMPTY";
						linha2[i+1].label = "EMPTY";
						linha2[i+1].operacao = "EMPTY";
						linha2[i+1].end_linha = 0;
					}
					else
						continue;
				}
			}
		}
    }

    j=0;

   	struct tokens_mem linha3[num_lines2 - counter];

    for (i=0; i<num_lines2; i++)
        {
    			//limpa as linhas vazias
        	if  (linha2[i].operando1 == "EMPTY"
        			&& linha2[i].operando2 == "EMPTY"
        			&& linha2[i].diretiva == "EMPTY"
        			&& linha2[i].label == "EMPTY"
        			&& linha2[i].operacao == "EMPTY"
        			&& linha2[i].end_linha == 0)
        	{
        		continue;
        	}

        	else if (linha2[i].diretiva == "IF")
        	{
        		continue;
        	}

        	else if (linha2[i].diretiva == "EQU")
        	{
        		continue;
        	}
        	//iguala as structs
        	else
        	{
        		linha3[j]=linha2[i];

        		j++;
        	}
        }


    	int num_lines3 = j;
	//imprime para ver se está tudo ok no segundo vetor de struct


        for(i = 0; i < num_lines3; i++)
        {
        	if (linha3[i].diretiva == "CONST")
        	{
        		linha3[i].memoria = 1;
        	}
        }

    for (i=0; i<num_lines3; i++)
    {

    		std::cout << "numero da linha: "<< i << std::endl;
    		std::cout << "operacao da linha: "<< linha3[i].operacao << std::endl;
    		std::cout << "operando1 da linha: "<< linha3[i].operando1 << std::endl;
    		std::cout << "auxiliar do operando1: "<< linha3[i].aux_ope1 << std::endl;
    		std::cout << "operando2 da linha: "<< linha3[i].operando2 << std::endl;
    		std::cout << "auxiliar do operando2: "<< linha3[i].aux_ope2 << std::endl;
    		std::cout << "diretiva da linha: "<< linha3[i].diretiva << std::endl;
    		std::cout << "label da linha: "<< linha3[i].label << std::endl;
    		std::cout << "numero na secao data: "<< linha3[i].data_num << std::endl;
    		std::cout << "tamanho na memoria: "<< linha3[i].memoria << std::endl;
    		std::cout << "linha original: "<< linha3[i].linha_original+1 << std::endl;
    		std::cout << check_equ <<std::endl;


    		if (linha2[i].secao == true)
    		{
    			std::cout << "secao de data" << "\n" << std::endl;
    		}
    		else
    		{
    			std::cout << "secao de texto" << "\n" << std::endl;
    		}
    }

    //////////////////////////////////////////////////
    // Imprime código objeto (transformar em função //
    //////////////////////////////////////////////////



    // checagem de divisão por zero
    // checa acesso incorreto a memória

    for (i=0; i<num_lines3; i++)
    {
    	if (linha3[i].operacao == "DIV")
    	{
    		for (j=0; j<num_lines3; j++)
    		{
    			if (linha3[i].operando1 == linha3[j].label)
    			{
    				if (linha3[j].diretiva == "CONST" && linha3[j].data_num == 0)
    				{
    					std::cout << "Erro semântico. Há tentativa  de dividir por zero na linha "<< linha3[i].linha_original+1 << ".\n"<< std::endl;
    				}
    			}
    		}
    	}
    	if (linha3[i].aux_ope1 > 0 && linha3[i].operando1 != "EMPTY")
    	{
			for (j=0; j<num_lines3; j++)
			{
				if (linha3[i].operando1 == linha3[j].label)
				{
					if (linha3[j].diretiva == "SPACE" && linha3[i].aux_ope1 < linha3[j].data_num)
					{
						//std::cout << "Erro semântico. Há tentativa  de dividir por zero.\n" << std::endl;
						continue;
					}
					else if (linha3[j].diretiva != "EXTERN")
					{
						std::cout << "Erro semântico na linha "<< linha3[i].linha_original +1 << ". Operando 1 está tentando acessar espaco de memória não reservado."<< std::endl;
					}
				}
			}
    	}

    	if (linha3[i].aux_ope2 > 0 && linha3[i].operando2 != "EMPTY")
    	{
			for (j=0; j<num_lines3; j++)
			{
				if (linha3[i].operando2 == linha3[j].label)
				{
					if (linha3[j].diretiva == "SPACE" && linha3[i].aux_ope2 < linha3[j].data_num)
					{
						//std::cout << "Erro semântico. Há tentativa  de dividir por zero.\n" << std::endl;
						continue;
					}
					else if (linha3[j].diretiva != "EXTERN")
					{
						std::cout << "Erro semântico na linha "<< linha3[i].linha_original +1 << ". Operando 2 está tentando acessar espaco de memória não reservado."<< std::endl;
					}
				}
			}
    	}






		//Checagem de diretiva BEGIN e END em local diferente da última linha do código
		if ((linha3[i].diretiva == "BEGIN")&& (i != 0))
		{
			std::cout << "Erro semântico na linha "<< linha3[i].linha_original+1 << ". A diretiva BEGIN deve estar na primeira linha útil de código." << std::endl;
		}
		if ((linha3[i].diretiva == "END")&& (i != num_lines3-1))
		{
			std::cout << "Erro semântico na linha "<< linha3[i].linha_original+1 << ". A diretiva END deve estar na última linha útil de código." << std::endl;
		}




    }




    ///////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////
    ///////TRANSFORMA AUX_OPE NO ENDERECO DESSES OPERANDOS/////////
    ///////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////

    //checa qual é o end de cada operando tem que vir após a checagem de acesso a memória
    // transforma .memoria no endereco da declaracao do operando
    for (i=0; i<num_lines3; i++)
    {
    	if (linha3[i].secao == true)
    	{
    		continue;
    	}

    	else
    	{
    		if (linha3[i].operando2 != "EMPTY")
    		{
    		    num_aux=0;
    			for (j=0; j<num_lines3; j++)
    			{
    				if (linha3[i].operando2 == linha3[j].label)
    				{
    					linha3[i].aux_ope2 = linha3[i].aux_ope2 + num_aux;
    				}
    		    	num_aux=num_aux+linha3[j].memoria;

    			}
    		}

    		if (linha3[i].operando1 != "EMPTY")
    		{
    		    num_aux=0;
    			for (j=0; j<num_lines3; j++)
    			{
    				if (linha3[i].operando1 == linha3[j].label)
    				{
    					linha3[i].aux_ope1 = linha3[i].aux_ope1 + num_aux;
    					//continue;
    				}
    				//std::cout << i+1 << " " << j+1<<" " <<num_aux << " ";
    		    	num_aux=num_aux+linha3[j].memoria;
    		    	//std:: cout << num_aux << " " <<linha3[j].memoria << std::endl;

    			}
    		}
    	}
    }



    //checa se alguma label foi declarada duas vezes
    for (i=0; i<num_lines3; i++)
    {
        for (j=0; j<num_lines3; j++)
        {
        	if (linha3[i].label == linha3[j].label && linha3[i].label != "EMPTY" && i != j && j > i)
        	{
				std::cout << "\nErro semântico, labels declaradas duas vezes nas linhas: " << linha3[i].linha_original+1 << " e "<< linha3[j].linha_original+1 << "\n" <<std::endl;
        	}
        }
    }


    //checa se algum operando 1 não tem respectivo label
    for (i=0; i<num_lines3; i++)
    {
        num_aux = 0;

        for (j=0; j<num_lines3; j++)
        {
        	if (linha3[i].operando1 == linha3[j].label && linha3[i].operando1 != "EMPTY")
        	{
        		num_aux = 1;
        	}
        }
        if (num_aux == 0 && linha3[i].operando1 != "EMPTY" && linha3[i].secao == false)
        {
			std::cout << "\nErro semântico, operando 1 na linha " << linha3[i].linha_original + 1 << " sem rótudo válido.\n"<<std::endl;

        }
    }

    //checa se algum operando 2 não tem respectivo label
    for (i=0; i<num_lines3; i++)
    {
        num_aux = 0;

        for (j=0; j<num_lines3; j++)
        {
        	if (linha3[i].operando2 == linha3[j].label && linha3[i].operando2 != "EMPTY")
        	{
        		num_aux = 1;
        	}
        }
        if (num_aux == 0 && linha3[i].operando2 != "EMPTY" && linha3[i].secao == false)
        {
			std::cout << "\nErro semântico, operando 2 na linha " << linha3[i].linha_original + 1 << " sem rótudo válido.\n"<<std::endl;

        }
    }



    std::vector<int> code(0);



    //IMPRIME CODIGO OBJETO
    num_aux=0;
    for (i=0; i<num_lines3; i++)
    {
    	linha3[i].end_linha = num_aux;
    	if (linha3[i].secao == false)
    	{
    		if (linha3[i].operacao == "ADD")
			{
				std::cout << "End: " << num_aux << " 01 " << linha3[i].aux_ope1 << std::endl;
				code.push_back(1);
				code.push_back(linha3[i].aux_ope1);
			}

			else if (linha3[i].operacao == "SUB")
			{
				std::cout << "End: " << num_aux << " 02 " << linha3[i].aux_ope1 <<std::endl;
				code.push_back(2);
				code.push_back(linha3[i].aux_ope1);
			}

			else if (linha3[i].operacao == "MULT")
			{
				std::cout << "End: " << num_aux << " 03 " << linha3[i].aux_ope1 <<std::endl;
				code.push_back(3);
				code.push_back(linha3[i].aux_ope1);
			}

			else if (linha3[i].operacao == "DIV")
			{
				std::cout << "End: " << num_aux << " 04 " << linha3[i].aux_ope1 <<std::endl;
				code.push_back(4);
				code.push_back(linha3[i].aux_ope1);
			}


			else if (linha3[i].operacao == "JMP")
			{
				std::cout << "End: " << num_aux << " 05 " << linha3[i].aux_ope1 <<std::endl;
				code.push_back(5);
				code.push_back(linha3[i].aux_ope1);
			}

			else if (linha3[i].operacao == "JMPN")
			{
				std::cout << "End: " << num_aux << " 06 " << linha3[i].aux_ope1 <<std::endl;
				code.push_back(6);
				code.push_back(linha3[i].aux_ope1);
			}

			else if (linha3[i].operacao == "JMPP")
			{
				std::cout << "End: " << num_aux << " 07 " << linha3[i].aux_ope1 <<std::endl;
				code.push_back(7);
				code.push_back(linha3[i].aux_ope1);
			}

			else if (linha3[i].operacao == "JMPZ")
			{
				std::cout << "End: " << num_aux << " 08 " << linha3[i].aux_ope1 <<std::endl;
				code.push_back(8);
				code.push_back(linha3[i].aux_ope1);
			}

			else if (linha3[i].operacao == "COPY")
			{
				std::cout << "End: " << num_aux << " 09 " << linha3[i].aux_ope1 << " "<< linha3[i].aux_ope2 <<std::endl;
				code.push_back(9);
				code.push_back(linha3[i].aux_ope1);
				code.push_back(linha3[i].aux_ope2);

			}

			else if (linha3[i].operacao == "LOAD")
			{
				std::cout << "End: " << num_aux << " 10 " << linha3[i].aux_ope1 <<std::endl;
				code.push_back(10);
				code.push_back(linha3[i].aux_ope1);
			}

			else if (linha3[i].operacao == "STORE")
			{
				std::cout << "End: " << num_aux << " 11 " << linha3[i].aux_ope1 <<std::endl;
				code.push_back(11);
				code.push_back(linha3[i].aux_ope1);
			}

			else if (linha3[i].operacao == "INPUT")
			{
				std::cout << "End: " << num_aux << " 12 " << linha3[i].aux_ope1 <<std::endl;
				code.push_back(12);
				code.push_back(linha3[i].aux_ope1);
			}

			else if (linha3[i].operacao == "OUTPUT")
			{
				std::cout << "End: " << num_aux << " 13 " << linha3[i].aux_ope1 <<std::endl;
				code.push_back(13);
				code.push_back(linha3[i].aux_ope1);
			}

			else if (linha3[i].operacao == "STOP")
			{
				std::cout << "End: " << num_aux << " 14 " <<std::endl;
				code.push_back(14);
			}
    	}
    		//std::cout << "\nOKAY\n" << std::endl;

    	if (linha3[i].secao == true)
    	{


    		if (linha3[i].diretiva == "CONST")
    		{
				std::cout << "End: " << num_aux << " "<< linha3[i].data_num <<std::endl;
				code.push_back(linha3[i].data_num);
    		}

    		else if (linha3[i].diretiva == "SPACE")
    		{
    			std::cout << "End: "<< num_aux ;
    			for (int l=0; l<linha3[i].data_num; l++)
    			{
    				std::cout << " 00";
    				code.push_back(0);
    			}
    			std::cout << std::endl;
    		}
    	}
    	num_aux=num_aux+linha3[i].memoria;
    }

	std::cout << std::endl;




    std::ofstream writefile (arquivo_saida.c_str());


	std::cout << std::endl;




    /////////////////////////////////
    //        TABELAS              //
	/////////////////////////////////



	if (hasBegin == true && hasEnd == true)
	{
		std::cout<< "\n é modulo\n" << std::endl;

	    std::cout << "\nTABLE USE" << std::endl;
		writefile << "TABLE USE\n";

		for (i=0; i<num_lines3; i++)
	    {
	    	if (linha3[i].diretiva == "EXTERN")
	    	{
				for (j=0; j<num_lines3; j++)
				{

					if (linha3[j].operando1 == linha3[i].label && linha3[j].operando1 != "EMPTY")
					{
						std::cout << linha3[i].label << "\t";
						std::cout << linha3[j].end_linha + 1 << std::endl;
						writefile << linha3[i].label<<"\t";
						writefile << linha3[j].end_linha + 1 << "\n";
					}

					else if (linha3[j].operando2 == linha3[i].label && linha3[j].operando2 != "EMPTY")
					{
						std::cout << linha3[i].label << "\t";
						std::cout << linha3[j].end_linha + 2 << std::endl;
						writefile << linha3[i].label<<"\t";
						writefile << linha3[j].end_linha + 2 << "\n";
					}
				}
			}
	    }


		std::cout << "\nTABLE DEFINITION" << std::endl;
		writefile << "\nTABLE DEFINITION\n";

				for (i=0; i<num_lines3; i++)
			    {
			    	if (linha3[i].diretiva == "PUBLIC")
			    	{
						for (j=0; j<num_lines3; j++)
						{

							if (linha3[j].label == linha3[i].operando1)
							{
								std::cout << linha3[j].label << "\t";
								std::cout << linha3[j].end_linha << std::endl;
								writefile << linha3[j].label<<"\t";
								writefile << linha3[j].end_linha << "\n";
							}
						}
					}
			    }

		std::cout << "\nRELATIVE" << std::endl;
		writefile << "\nRELATIVE\n";


		for (i=0; i<num_lines3; i++)
	    {
	    	if (linha3[i].diretiva == "EMPTY")
	    	{
				if (linha3[i].operando1 != "EMPTY")
				{
					std::cout << linha3[i].end_linha + 1 << " ";
					writefile << linha3[i].end_linha + 1 << " ";
				}

				if (linha3[i].operando2  != "EMPTY")
				{
					std::cout << linha3[i].end_linha + 2 << " ";
					writefile << linha3[i].end_linha + 2 << " ";
				}
			}
	    }



		std::cout << "\n\nCODE" << std::endl;
		writefile << "\n\nCODE\n";
	}



	for (i = 0; i< code.size(); i++)
    {

		 if (0 > code[i] && code[i] > -9)
		{
			std::cout << "-0" << abs(code[i])<< " ";
			writefile << "-0" << abs(code[i])<< " ";
		}
		else if (0 <= code[i] && code[i] < 10)
		{
			std::cout << "0" << code[i]<< " ";
			writefile << "0" << code[i]<< " ";

		}
		else{
			std::cout <<code[i]<< " " ;
			writefile  << code[i]<< " ";
		}
    }



    writefile.close();


    std::cout << "\nOKAY\n" << std::endl;
	return 0;

 }


