#include "Transporte.h"

//Implementação dos métodos de mesmo nome declarados e explicados no cabeçalho da classe Transporte

Transporte::Transporte(){
	qtd_trechos = 0;
	qtd_caminhoes = 0;
	qtd_modalidades = 0;
	qtd_tipos_item = 0;
	distancia_total = 0;
	carga_total = 0.00;
	custo_total = 0.00;
	custo_medio_km = 0.00;
	custo_unitario_medio = 0.00;
	custo_medio_tipo_item = 0.00;
}

void Transporte::AddTrechoPercorrido(string arg_cidade_origem, string arg_cidade_destino, int arg_distancia) {
	trecho[qtd_trechos].cidade_origem = arg_cidade_origem;
	trecho[qtd_trechos].cidade_destino = arg_cidade_destino;
	trecho[qtd_trechos].distancia = arg_distancia;
	qtd_trechos++;
}

void Transporte::AumentarLimiteTrechoPercorrido(int l) {
	int limite = l;
	trecho.resize(limite);
}

void Transporte::AddCaminhaoUsado(string arg_porte, double arg_carga, double arg_custo) {
	caminhao[qtd_caminhoes].porte = arg_porte;
	caminhao[qtd_caminhoes].carga_max_kg = arg_carga;
	caminhao[qtd_caminhoes].custo_por_km = arg_custo;
	qtd_caminhoes++;
}

void Transporte::AumentarLimiteCaminhaoUsado(int l) {
	int limite = l;
	caminhao.resize(limite);
}

void Transporte::AddModalidade(string arg_porte, double arg_carga, double arg_custo) {
	modalidades[qtd_modalidades].porte = arg_porte;
	modalidades[qtd_modalidades].carga_max_kg = arg_carga;
	modalidades[qtd_modalidades].custo_por_km = arg_custo;
	qtd_modalidades++;
}

void Transporte::AumentarLimiteModalidade(int l) {
	int limite = l;
	modalidades.resize(limite);
}

void Transporte::AddItemTransportado(string arg_nome, double arg_peso, int arg_quantidade) {
	item[qtd_tipos_item].nome = arg_nome;
	item[qtd_tipos_item].peso = arg_peso;
	item[qtd_tipos_item].quantidade = arg_quantidade;
	qtd_tipos_item++;
}

void Transporte::AumentarLimiteItem(int l) {
	int limite = l;
	item.resize(limite);
}

void Transporte::CalcularDistanciaTotal() {
	int apoioInt = 0;
	for (int i = 0; i < trecho.size(); i++) {
		apoioInt += trecho[i].distancia;
	}
	distancia_total = apoioInt;
}

void Transporte::CalcularCargaTotal() {
	for (int i = 0; i < item.size(); i++) {
		carga_total += (item[i].peso * item[i].quantidade);
	}
}

void Transporte::IdentificarModelo() {

	// Nesse método se é usado das listas abaixo para realizar um calculo que diz qual caminhão sera mais eficiente no transporte da carga

	vector <int> lista_de_eficiencia; // Lista que representa quantas vezes um caminhão de preço menor pode ser usado antes de um maior ser eficiente
	vector <int> lista_de_quantidades; // Lista de quantidade de caminhões que serão usados em cada modalidade
	vector <double> lista_de_carga; // Lista de carga que cada modalidade é capaz de transportar
	vector <double> lista_de_custos; // Lista do custo de cada modalidade
	double carga = carga_total;
	int index = 0;
	int apoioInt = 0;
	bool apoioBool = false;

	for (int i = 0; i < modalidades.size(); i++) {
		lista_de_carga.push_back(modalidades[i].carga_max_kg);
		lista_de_custos.push_back(modalidades[i].custo_por_km);
	}

	sort(lista_de_custos.begin(), lista_de_custos.end(), greater <>());

	for (int i = 0; i < (lista_de_custos.size() - 1); i++) {
		apoioInt = lista_de_custos[i] / lista_de_custos[i + 1];
		lista_de_eficiencia.push_back(apoioInt);
	}

	sort(lista_de_eficiencia.begin(), lista_de_eficiencia.end());
	sort(lista_de_carga.begin(), lista_de_carga.end());
	lista_de_quantidades.resize(lista_de_carga.size());

	do {
		index = 0;

		carga -= lista_de_carga[index];
		lista_de_quantidades[index] += 1;

		if (lista_de_quantidades[index] > lista_de_eficiencia[index] || lista_de_quantidades[index+1] == lista_de_eficiencia[index+1]) {

			lista_de_quantidades[index] = 0;
			carga = carga_total;
			index++;

			lista_de_quantidades[index] += 1;
			carga -= ((lista_de_carga[index] * lista_de_quantidades[index]) + (lista_de_carga[index+1] * lista_de_quantidades[index+1]));

			if (lista_de_quantidades[index] > lista_de_eficiencia[index]) {

				lista_de_quantidades[index] = 0;
				carga = carga_total;
				index++;

				lista_de_quantidades[index] += 1;
				carga -= lista_de_carga[index] * lista_de_quantidades[index];
			}
		}
	} while (carga > 0.00);

	apoioInt = 0;

	for (int i = 0; i < lista_de_quantidades.size(); i++) {
		apoioInt += lista_de_quantidades[i];
	}

	AumentarLimiteCaminhaoUsado(apoioInt);

	for (int i = 0; i < lista_de_quantidades.size(); i++) {
		for (int j = 0; j < lista_de_quantidades[i]; j++) {
			AddCaminhaoUsado(modalidades[i].porte, modalidades[i].carga_max_kg, modalidades[i].custo_por_km);
		}
	}
}

void Transporte::CalcularCustos() {
	custo_modalidade.resize(3);

	for (int i = 0; i < trecho.size(); i++) {
		trecho[i].custo_trecho = CalcularCustoTrecho(i);
	}

	custo_total = CalcularCustoTotal();
	custo_medio_km = CalcularCustoMedioKm();
	custo_unitario_medio = CalcularCustoUnitarioMedio();
	custo_medio_tipo_item = CalcularCustoMedioTipoItem();

	for (int i = 0; i < modalidades.size(); i++) {
		custo_modalidade[i] = CalcularCustoModalidade(i);
	}
}

double Transporte::CalcularCustoTrecho(int i) {
	int index = i;
	double apoioDouble = 0;
	double distancia_d = (double)trecho[index].distancia + 0.00;

	for (int i = 0; i < caminhao.size(); i++) {
		apoioDouble += caminhao[i].custo_por_km;
	}

	apoioDouble *= distancia_d;

	return apoioDouble;
}

double Transporte::CalcularCustoTotal() {
	double apoioDouble = 0;

	for (int i = 0; i < trecho.size(); i++) {
		apoioDouble += trecho[i].custo_trecho;
	}

	return apoioDouble;
}

double Transporte::CalcularCustoMedioKm() {
	double apoioDouble = 0;
	apoioDouble = custo_total / distancia_total;
	return apoioDouble;
}

double Transporte::CalcularCustoUnitarioMedio() {
	double apoioDouble = 0;
	double apoioInt = 0;

	for (int i = 0; i < item.size(); i++) {
		apoioInt += item[i].quantidade;
	}

	apoioDouble = (double)apoioInt + 0.00;
	apoioDouble = custo_total / apoioDouble;
	return apoioDouble;
}

double Transporte::CalcularCustoMedioTipoItem() {
	double apoioDouble = 0;
	int apoioInt = 0;
	apoioInt = item.size();
	apoioDouble = (double)apoioInt + 0.00;
	apoioDouble = custo_total / apoioDouble;
	return apoioDouble;
}

double Transporte::CalcularCustoModalidade(int i) {
	double apoioDouble = 0;
	int apoioInt = 0;
	apoioDouble = modalidades[i].custo_por_km;

	for (int i = 0; i < caminhao.size(); i++) {
		if (apoioDouble == caminhao[i].custo_por_km) {
			apoioInt++;
		}
	}

	apoioDouble = distancia_total * apoioInt * apoioDouble;
	return apoioDouble;
}

void Transporte::FinalizarCadastro() {
	int apoioInt;
	cout << setprecision(2) << fixed;

	for (int i = 0; i < trecho.size(); i++) {
		cout << "\nTrecho " << i + 1 << endl;
		cout << "Cidade de origem : " << trecho[i].cidade_origem << endl;
		cout << "Cidade de destino: " << trecho[i].cidade_destino << endl;
		cout << "Distancia do trecho: " << trecho[i].distancia << endl;
	}

	cout << "\nDistancia total percorrida em KM: " << distancia_total << endl;
	cout << "\nItens transportados: " << endl;

	for (int i = 0; i < item.size(); i++) {
		cout << i + 1 << " - " << item[i].nome << " - Quantidade: " << item[i].quantidade << endl;
	}

	cout << "\nDe forma a resultar no menor custo de transporte por KM rodado será necessário: " << endl;

	for (int i = 0; i < modalidades.size(); i++) {
		apoioInt = 0;
		for (int j = 0; j < caminhao.size(); j++) {
			if (modalidades[i].porte == caminhao[j].porte) {
				apoioInt++;
			}
		}
		cout << apoioInt << " de porte " << modalidades[i].porte << "." << endl;
	}
	
	cout << "\nO custo total do transporte é R$ " << custo_total << "." << endl;
	cout << "O custo unitário médio é R$" << custo_unitario_medio << "." << endl;
	cout << "\nO cadastro foi finalizado." << endl;
}

void Transporte::MostrarDadosEstatiscos() {
	int apoioInt = 0;
	cout << "Custo total: R$ " << custo_total << endl;

	for (int i = 0; i < trecho.size(); i++) {
		cout << "Custo trecho " << i+1 << ": R$ " << trecho[i].custo_trecho << endl;
	}

	cout << "Custo médio por KM: R$" << custo_medio_km << endl;
	cout << "Custo médio por tipo de produto: R$ " << custo_medio_tipo_item << endl;

	for (int i = 0; i < custo_modalidade.size(); i++) {
		cout << "Custo modalidade " << i+1 << ": R$ " << custo_modalidade[i] << endl;
	}

	cout << "Número total de veículos deslocados : " << caminhao.size() << endl;

	for (int i = 0; i < item.size(); i++) {
		apoioInt += item[i].quantidade;
	}

	cout << "Total de itens transportados: " << apoioInt << endl;
}