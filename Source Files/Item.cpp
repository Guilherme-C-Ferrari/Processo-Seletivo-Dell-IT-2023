#include "Item.h"

//Implementação dos métodos de mesmo nome declarados e explicados no cabeçalho da classe Item

Item::Item() {
	nome = "";
	peso = 0;
}

string Item::GetNome() {
	return nome;
}

void Item::SetNome(string n) {
	nome = n;
}

double Item::GetPeso() {
	return peso;
}

void Item::SetPeso(double p) {
	peso = p;
}

void Item::SalvarDadosItem(string arg_nome, double arg_peso) {
	SetNome(arg_nome);
	SetPeso(arg_peso);
}