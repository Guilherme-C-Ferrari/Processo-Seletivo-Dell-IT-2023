#pragma once
#include "Caminhao.h";
#include "Item.h";
#include "Transporte.h"
#include <fstream>
#include <sstream>

// A classe Transportadora abaixo representa a transportadora em que ocorrer�o todos os tranportes

class Transportadora {

private:

	vector <Caminhao> modalidade_registrada; // Vetor que armazena as modalidades de caminh�es registradas a transportadora
	vector <Item> item_registrado; // Vetor que armazena os tipos de item registrados na transportadora
	vector <Transporte> transporte_cadastrado; // Vetor que armazena o transportes cadastrados na transportadora

public:
	// Construtor da classe
	Transportadora();

	// M�todo que inicializa o programa
	void Start();

	// M�todo que roda o programa, onde fica o menu que ser� usado pelo usu�rio para acessar as funcionalidades
	void Run();

	// M�todo que finaliza o programa
	void Finish();

	// M�todo que representa a primeira funcionalidade, o qual a partir de um trecho e de uma modalidade calcula se custo e dist�ncia
	void ConsultarTrechoXModalidade();

	// M�todo que representa a segunda funcionalidade que cadastra um transporte
	void CadastrarTransporte();

	// M�todo que representa a terceira funcionalidade que mostra os dados estat�sticos dos cadastros
	void DadosEstatisticos();

	// M�todo que encontra a partir do nome, a posi��o n�merica da cidade dentro da tabela
	int EncontrarPosicaoCidade(string arg_cidade);

	// M�todo que usa as posi��es n�mericas para calcular dist�ncia
	int CalcularDistancia(int arg_cidade_origem, int arg_cidade_destino);

	// M�todo que utiliza da dist�ncia total e o custo por km do caminh�o para calcular o custo total
	double CalcularCustoTotal(double arg_custo_por_km, int arg_distancia);

	// M�todo que testa as possiveis exce��es de inputs da transportadora
	int TestarExcecao(string arg_string);

};