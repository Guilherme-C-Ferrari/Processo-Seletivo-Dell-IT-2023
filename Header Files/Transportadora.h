#pragma once
#include "Caminhao.h";
#include "Item.h";
#include "Transporte.h"
#include <fstream>
#include <sstream>

// A classe Transportadora abaixo representa a transportadora em que ocorrerão todos os tranportes

class Transportadora {

private:

	vector <Caminhao> modalidade_registrada; // Vetor que armazena as modalidades de caminhões registradas a transportadora
	vector <Item> item_registrado; // Vetor que armazena os tipos de item registrados na transportadora
	vector <Transporte> transporte_cadastrado; // Vetor que armazena o transportes cadastrados na transportadora

public:
	// Construtor da classe
	Transportadora();

	// Método que inicializa o programa
	void Start();

	// Método que roda o programa, onde fica o menu que será usado pelo usuário para acessar as funcionalidades
	void Run();

	// Método que finaliza o programa
	void Finish();

	// Método que representa a primeira funcionalidade, o qual a partir de um trecho e de uma modalidade calcula se custo e distância
	void ConsultarTrechoXModalidade();

	// Método que representa a segunda funcionalidade que cadastra um transporte
	void CadastrarTransporte();

	// Método que representa a terceira funcionalidade que mostra os dados estatísticos dos cadastros
	void DadosEstatisticos();

	// Método que encontra a partir do nome, a posição númerica da cidade dentro da tabela
	int EncontrarPosicaoCidade(string arg_cidade);

	// Método que usa as posições númericas para calcular distância
	int CalcularDistancia(int arg_cidade_origem, int arg_cidade_destino);

	// Método que utiliza da distância total e o custo por km do caminhão para calcular o custo total
	double CalcularCustoTotal(double arg_custo_por_km, int arg_distancia);

	// Método que testa as possiveis exceções de inputs da transportadora
	int TestarExcecao(string arg_string);

};