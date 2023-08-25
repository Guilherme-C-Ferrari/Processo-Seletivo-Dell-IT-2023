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

	// M�todo que cadastra um trecho percorrido
	void AddTrechoPercorrido(string arg_cidade_origem, string arg_cidade_destino, int arg_distancia);

	// M�todo que aumenta o limite de trechos que podem ser cadastrados no transporte
	void AumentarLimiteTrechoPercorrido(int l);

	// M�todo que cadastra um caminhao
	void AddCaminhaoUsado(string arg_porte, double arg_carga, double arg_custo);

	// M�todo que aumenta o limite de caminhoes que podem ser cadastrados no transporte
	void AumentarLimiteCaminhaoUsado(int l);

	// M�todo que cadastra uma modalidade de caminhao
	void AddModalidade(string arg_porte, double arg_carga, double arg_custo);

	// M�todo que aumenta o limite de modalidades que podem ser cadastrados no transporte
	void AumentarLimiteModalidade(int l);

	// M�todo que cadastra um tipo de item
	void AddItemTransportado(string arg_nome, double arg_peso, int arg_quantidade);

	// M�todo que aumenta o limite de itens que podem ser cadastrados no transporte
	void AumentarLimiteItem(int l);
	
	// M�todo que calcula a dist�ncia total percorrida
	void CalcularDistanciaTotal();

	// M�todo que calcula a carga total transportada
	void CalcularCargaTotal();

	// M�todo que identifica os melhores modelos de caminh�o a serem usados para um transporte mais barato
	void IdentificarModelo();

	// M�todo que chama todos os m�todos de custo
	void CalcularCustos();

	// M�todo que calcula o custo por trecho
	double CalcularCustoTrecho(int i);

	// M�todo que calcula o custo total
	double CalcularCustoTotal();

	// M�todo que calcula o custo m�dio por KM
	double CalcularCustoMedioKm();

	// M�todo que calcula o custo unit�rio m�dio
	double CalcularCustoUnitarioMedio();

	// M�todo que calcula o custo m�dio por tipo de item/produto
	double CalcularCustoMedioTipoItem();

	// M�todo que calcula o custo total de cada modalidade de caminhao
	double CalcularCustoModalidade(int i);

	// M�todo que finaliza o cadastro
	void FinalizarCadastro();

	// M�todo que mostra os dados est�tisticos
	void MostrarDadosEstatiscos();
};