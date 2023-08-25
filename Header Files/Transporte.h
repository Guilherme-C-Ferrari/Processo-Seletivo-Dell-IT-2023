#pragma once
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

// Estrutura que representa os trechos do transporte, sendo o trecho o ponto entre duas cidades
struct TrechoPercorrido {
	string cidade_origem = "";
	string cidade_destino = "";
	int distancia = 0.00;
	double custo_trecho = 0.00;
};

// Estrutura que representa os caminhoes do transporte
struct CaminhaoUsado {
	string porte = "";
	double carga_max_kg = 0.00;
	double custo_por_km = 0.00;
};

// Estrututura que representa os itens do transporte
struct ItemTransportado {
	string nome = "";
	double peso = 0.00;
	int quantidade = 0.00;
};

// A classe Transporte abaixo representa os transportes cadastrados pela transportadora

class Transporte {

private:

	int qtd_trechos; // Atributo que representa a quantidade de trechos do transporte
	int qtd_caminhoes; // Atributo que representa a quantidade de caminhoes do transporte
	int qtd_modalidades; // Atributo que representa a quantidade de modalidades do transporte
	int qtd_tipos_item; // Atributo que representa a quantidade de tipos de itens diferentes do transporte
	int distancia_total; // Atributo que representa a distancia total percorrida pelo transporte
	double carga_total; // Atributo que representa a carga total do transporte
	double custo_total; // Atributo que representa o custo total do transporte
	double custo_medio_km; // Atributo que representa o custo medio por KM do transporte
	double custo_unitario_medio; // Atributo que representa o custo unitario medio do transporte
	double custo_medio_tipo_item; // Atributo que representa o custo medio por tipo diferente de item no transporte
	vector <double> custo_modalidade; // Vetor de atributos que represetam o custo por cada modalide de caminhao usada no transporte
	vector <TrechoPercorrido> trecho; // Vetor que armazena os trechos do transporte
	vector <CaminhaoUsado> modalidades; // Vetor que armazena as modalidades de caminhoes para serem usadas no transporte
	vector <CaminhaoUsado> caminhao; // Vetor que armazena os caminhoes usados no transporte
	vector <ItemTransportado> item; // Vetor que arzena os itens do transporte

public:
	// Construtor da Classe
	Transporte();

	// Método que cadastra um trecho percorrido
	void AddTrechoPercorrido(string arg_cidade_origem, string arg_cidade_destino, int arg_distancia);

	// Método que aumenta o limite de trechos que podem ser cadastrados no transporte
	void AumentarLimiteTrechoPercorrido(int l);

	// Método que cadastra um caminhao
	void AddCaminhaoUsado(string arg_porte, double arg_carga, double arg_custo);

	// Método que aumenta o limite de caminhoes que podem ser cadastrados no transporte
	void AumentarLimiteCaminhaoUsado(int l);

	// Método que cadastra uma modalidade de caminhao
	void AddModalidade(string arg_porte, double arg_carga, double arg_custo);

	// Método que aumenta o limite de modalidades que podem ser cadastrados no transporte
	void AumentarLimiteModalidade(int l);

	// Método que cadastra um tipo de item
	void AddItemTransportado(string arg_nome, double arg_peso, int arg_quantidade);

	// Método que aumenta o limite de itens que podem ser cadastrados no transporte
	void AumentarLimiteItem(int l);
	
	// Método que calcula a distância total percorrida
	void CalcularDistanciaTotal();

	// Método que calcula a carga total transportada
	void CalcularCargaTotal();

	// Método que identifica os melhores modelos de caminhão a serem usados para um transporte mais barato
	void IdentificarModelo();

	// Método que chama todos os métodos de custo
	void CalcularCustos();

	// Método que calcula o custo por trecho
	double CalcularCustoTrecho(int i);

	// Método que calcula o custo total
	double CalcularCustoTotal();

	// Método que calcula o custo médio por KM
	double CalcularCustoMedioKm();

	// Método que calcula o custo unitário médio
	double CalcularCustoUnitarioMedio();

	// Método que calcula o custo médio por tipo de item/produto
	double CalcularCustoMedioTipoItem();

	// Método que calcula o custo total de cada modalidade de caminhao
	double CalcularCustoModalidade(int i);

	// Método que finaliza o cadastro
	void FinalizarCadastro();

	// Método que mostra os dados estátisticos
	void MostrarDadosEstatiscos();
};