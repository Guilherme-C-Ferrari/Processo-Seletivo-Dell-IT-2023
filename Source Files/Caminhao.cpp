#include "Caminhao.h"

//Implementação dos métodos de mesmo nome declarados e explicados no cabeçalho da classe Item

Caminhao::Caminhao() {
	porte = "";
	carga_max_kg = 0;
	custo_por_km = 0;
}

string Caminhao::GetPorte() {
	return porte;
}

void Caminhao::SetPorte(string p) {
	porte = p;
}

double Caminhao::GetCarga_Max_KG() {
	return carga_max_kg;
}

void Caminhao::SetCarga_Max_KG(double c) {
	carga_max_kg = c;
}

double Caminhao::GetCusto_Por_KM() {
	return custo_por_km;
}

void Caminhao::SetCusto_Por_KM(double c) {
	custo_por_km = c;
}

void Caminhao::SalvarDadosCaminhao(string arg_porte, double arg_carga_max_kg, double arg_custo_por_km) {
	SetPorte(arg_porte);
	SetCarga_Max_KG(arg_carga_max_kg);
	SetCusto_Por_KM(arg_custo_por_km);
}