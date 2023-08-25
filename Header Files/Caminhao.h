#pragma once
#include <iostream>
using namespace std;

// A classe Caminhao abaixo representa os caminhoes que ser�o usados pela transportadora em seus transportes

class Caminhao {

private:

	string porte; // Atributo que representa o porte do caminhao, como pequeno, m�dio ou grande
	double carga_max_kg; // Atributo que representa a carga m�xima em KG que o caminhao � capaz de transportar
	double custo_por_km; // Atributo que representa o custo por KM rodado do caminhao

public:
	// Construtor da classe
	Caminhao();

	// Getters e Setters
	string GetPorte();
	void SetPorte(string p);

	double GetCarga_Max_KG();
	void SetCarga_Max_KG(double c);

	double GetCusto_Por_KM();
	void SetCusto_Por_KM(double c);

	// M�todo para receber os dados dos tr�s atributos do caminhao e salva-los
	void SalvarDadosCaminhao(string arg_porte, double arg_carga_max_kg, double arg_custo_por_km);
};