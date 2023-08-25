#pragma once
#include <iostream>
using namespace std;

// A classe Item abaixo representa os itens que serão transportados pela transportadora

class Item {

private:

	string nome; // Atributo que representa o nome do item
	double peso; // Atributo que representa o peso do item

public:
	// Construtor da classe
	Item();

	// Getters e Setters do nome e do peso
	string GetNome();
	void SetNome(string n);

	double GetPeso();
	void SetPeso(double p);

	// Método para receber os dados dos dois atributos do item e salva-los
	void SalvarDadosItem(string arg_nome, double arg_peso);
};