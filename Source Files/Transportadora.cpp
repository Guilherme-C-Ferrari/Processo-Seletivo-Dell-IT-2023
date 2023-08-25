#include "Transportadora.h"

//Implementação dos métodos de mesmo nome declarados e explicados no cabeçalho da classe Transportadora

Transportadora::Transportadora() {

    //Registro das modalidades de caminhão
    modalidade_registrada.resize(3);
    modalidade_registrada[0].SalvarDadosCaminhao("pequeno porte", 1000, 4.87);
    modalidade_registrada[1].SalvarDadosCaminhao("médio porte", 4000, 11.92);
    modalidade_registrada[2].SalvarDadosCaminhao("grande porte", 10000, 27.44);

    //Registro dos itens
    item_registrado.resize(6);
    item_registrado[0].SalvarDadosItem("Celular", 0.5);
    item_registrado[1].SalvarDadosItem("Geladeira", 60.0);
    item_registrado[2].SalvarDadosItem("Freezer", 100.0);
    item_registrado[3].SalvarDadosItem("Cadeira", 5.0);
    item_registrado[4].SalvarDadosItem("Luminária", 0.8);
    item_registrado[5].SalvarDadosItem("Lavadora de Roupa", 120);

    // Inicializa a quantidade de transporte cadastrados em 0
    transporte_cadastrado.resize(0);
}

void Transportadora::Start() {
    setlocale(LC_ALL, "portuguese");
    cout << "O programa está sendo iniciado." << endl;
}

void Transportadora::Run() {
    int menu = 0;
    int apoioInt = 0;
    string apoioString = "";

    do {
        apoioInt = 0;

        cout << "\n---------------------MENU----------------------" << endl << endl;
        cout << "Diga a opção que deseja:\n\n";
        cout << "1 - Consultar trechos X modalidade\n";
        cout << "2 - Cadastrar transporte\n";
        cout << "3 - Relatório de dados estatísticos\n";
        cout << "4 - Encerrar programa\n\n> ";
        cin >> apoioString;
        menu = TestarExcecao(apoioString);

        switch (menu) {
        case 1:
            ConsultarTrechoXModalidade();
            break;
        case 2:
            CadastrarTransporte();
            break;
        case 3:
            DadosEstatisticos();
            break;
        case 4:
            do {
                cout << "\nVocê tem certeza que deseja encerrar o programa?" << endl;
                cout << "1 - Sim" << endl;
                cout << "2 - Não\n\n> ";
                cin >> apoioString;
                apoioInt = TestarExcecao(apoioString);

                if (apoioInt == 1) {
                    cout << "\nO programa será finalizado." << endl;
                } else if (apoioInt == 2) {
                    cout << "\nO programa voltará ao menu." << endl;
                    menu = 0;
                } else {
                    cout << "\nEscolha uma opção válida." << endl;
                }
            } while (apoioInt != 1 && apoioInt != 2);
            break;
        default:
            cout << "\nEscolha uma opção válida." << endl;
        }
        if (menu != 4) {
            cout << "\nPressione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
    } while (menu != 4);
}

void Transportadora::Finish() {
    cout << "\nO programa foi finalizado." << endl;
    exit(0);
}

void Transportadora::ConsultarTrechoXModalidade() {

    int cidade_origem = 0;
    int cidade_destino = 0;
    int distancia = 0;
    int apoioInt = 0;
    double custo = 0;
    string cidade_origem_nome = "";
    string cidade_destino_nome = "";
    string apoioString = "";
    bool apoioBool = false;

    cin.ignore();

    do {
        cout << "\nDigite, sem acentos, o nome da cidade de origem: ";
        getline(cin, apoioString);
        cidade_origem_nome = apoioString;
        cidade_origem = EncontrarPosicaoCidade(apoioString);

        if (cidade_origem == -1) {
            cout << "Nome da cidade de origem não encontrado no sistema." << endl;
        } else {
            apoioBool = true;
        }

        if (apoioBool == true) {
            apoioBool = false;
            apoioString = "";

            do {
                cout << "\nDigite, sem acentos, o nome da cidade de destino: ";
                getline(cin, apoioString);
                cidade_destino_nome = apoioString;
                cidade_destino = EncontrarPosicaoCidade(apoioString);

                if (cidade_destino == -1) {
                    cout << "Nome da cidade de destino não encontrado no sistema." << endl;
                } else {
                    apoioBool = true;
                }

                if (apoioBool == true) {
                    apoioBool = false;
                    distancia = CalcularDistancia(cidade_origem, cidade_destino);

                    cout << "\nA distância entre essas cidades, em KM, é de: " << distancia << endl;

                    do {
                        cout << "\nDigite o número da modalide de transporte deseja utilizar:" << endl;
                        cout << "\n1 - Pequeno Porte" << endl;
                        cout << "2 - Médio Porte" << endl;
                        cout << "3 - Grande Porte" << endl << endl;
                        cin >> apoioString;
                        apoioInt = TestarExcecao(apoioString);

                        if (apoioInt == 1) {
                            custo = CalcularCustoTotal(modalidade_registrada[0].GetCusto_Por_KM(), distancia);
                            cout << "\nDe " << cidade_origem_nome << " para " << cidade_destino_nome << ", utilizando um caminhão de pequeno porte, a distância é de " << distancia << " km e o custo será de R$ " << custo << "." << endl;
                            apoioBool = true;
                        } else if (apoioInt == 2) {
                            custo = CalcularCustoTotal(modalidade_registrada[1].GetCusto_Por_KM(), distancia);
                            cout << "\nDe " << cidade_origem_nome << " para " << cidade_destino_nome << ", utilizando um caminhão de médio porte, a distância é de " << distancia << " km e o custo será de R$ " << custo << "." << endl;
                            apoioBool = true;
                        } else if (apoioInt == 3) {
                            custo = CalcularCustoTotal(modalidade_registrada[2].GetCusto_Por_KM(), distancia);
                            cout << "\nDe " << cidade_origem_nome << " para " << cidade_destino_nome << ", utilizando um caminhão de grande porte, a distância é de " << distancia << " km e o custo será de R$ " << custo << "." << endl;
                            apoioBool = true;
                        } else {
                            cout << "\nOpção inválida. Escolha uma opção válida." << endl;
                        }
                    } while (apoioBool != true);
                }
            } while (apoioBool != true);
        }
    } while (apoioBool != true);
}

void Transportadora::CadastrarTransporte() {

    int i_cadastro = 0;
    int qnt_item_cadastrado = 0;
    int cidade_origem = 0;
    int cidade_destino = 0;
    int distancia = 0;
    int index = 0;
    int apoioInt = 0;
    double apoioDouble = 0.00;
    string cidade_origem_nome = "";
    string cidade_destino_nome = "";
    string apoioString = "";
    bool apoioBool = false;

    i_cadastro = transporte_cadastrado.size();
    transporte_cadastrado.resize(transporte_cadastrado.size() + 1);

    do {
        cout << "\nQuantas paradas você deseja fazer a partir da cidade de origem?\n\n> ";
        cin >> apoioString;
        apoioInt = TestarExcecao(apoioString);
    } while (apoioInt <= 0);

    transporte_cadastrado[i_cadastro].AumentarLimiteTrechoPercorrido(apoioInt);

    cin.ignore();

    for (int i = 0; i < apoioInt; i++) {
        cout << "\nTrecho " << (i+1) << endl;

        do {
            if (i == 0) {
                cout << "\nDigite, sem acentos, o nome da cidade de origem do trecho: ";
                getline(cin, apoioString);
                cidade_origem_nome = apoioString;
                cidade_origem = EncontrarPosicaoCidade(apoioString);
            }
            else {
                cidade_origem_nome = cidade_destino_nome;
                cidade_origem = cidade_destino;
            }

            if (cidade_origem == -1) {
                cout << "Nome da cidade de origem não encontrado no sistema." << endl;
            } else {
                apoioBool = true;
            }

            if (apoioBool == true) {
                apoioBool = false;
                apoioString = "";

                do {
                    cout << "\nDigite, sem acentos, o nome da cidade de destino do trecho: ";
                    getline(cin, apoioString);
                    cidade_destino_nome = apoioString;
                    cidade_destino = EncontrarPosicaoCidade(apoioString);

                    if (cidade_destino == -1) {
                        cout << "Nome da cidade de destino não encontrado no sistema." << endl;
                    } else {
                        apoioBool = true;
                    }

                    if (apoioBool == true) {
                        distancia = CalcularDistancia(cidade_origem, cidade_destino);
                    }
                } while (apoioBool != true);
            }
        } while (apoioBool != true);
        transporte_cadastrado[i_cadastro].AddTrechoPercorrido(cidade_origem_nome, cidade_destino_nome, distancia);
    }

    transporte_cadastrado[i_cadastro].CalcularDistanciaTotal();
    apoioBool = false;

    do {

        qnt_item_cadastrado++;
        transporte_cadastrado[i_cadastro].AumentarLimiteItem(qnt_item_cadastrado);
        cout << "\nQual tipo de item deseja transportar? Digite o número da opção" << endl << endl;

        for (int i = 0; i < item_registrado.size(); i++) {
            cout << (i+1) << " - Nome: " << item_registrado[i].GetNome() << " - Peso: " << item_registrado[i].GetPeso() << endl;;
            apoioInt = i;
        }

        apoioInt += 2;
        cout << apoioInt << " - Cadastrar item" << endl << endl << "> ";
        cin >> apoioString;
        apoioInt = TestarExcecao(apoioString);
        index = apoioInt;

        if (index > 0 && index <= (item_registrado.size() + 1)) {
            if (index <= item_registrado.size()) {
                index -= 1;
                cout << "\nQual a quantidade de itens desse tipo que deseja transportar? ";
                cin >> apoioString;
                apoioInt = TestarExcecao(apoioString);
                transporte_cadastrado[i_cadastro].AddItemTransportado(item_registrado[index].GetNome(), item_registrado[index].GetPeso(), apoioInt);
            } else {

                item_registrado.resize(index);
                index -= 1;

                cout << "\nQual é o nome do item? ";
                cin >> apoioString;

                cout << "\nQual é, em kg, o peso do item? ";
                cin >> apoioDouble;

                item_registrado[index].SalvarDadosItem(apoioString, apoioDouble);

                cout << "\nQual a quantidade de itens desse tipo que será transportada? ";
                cin >> apoioInt;

                transporte_cadastrado[i_cadastro].AddItemTransportado(item_registrado[index].GetNome(), item_registrado[index].GetPeso(), apoioInt);
            }

            do {
                cout << "\nVocê gostaria de adicionar outro item ao seu transporte?" << endl;
                cout << "1 - Sim" << endl;
                cout << "2 - Não\n\n> ";
                cin >> apoioString;
                apoioInt = TestarExcecao(apoioString);

                if (apoioInt == 2) {
                    apoioBool = true;
                } else if (apoioInt != 1) {
                    cout << "\nEscolha uma opção válida." << endl;
                }
            } while (apoioInt != 1 && apoioInt != 2);
        }
    } while (apoioBool != true);

    transporte_cadastrado[i_cadastro].CalcularCargaTotal();
    transporte_cadastrado[i_cadastro].AumentarLimiteModalidade(modalidade_registrada.size());

    for (int i = 0; i < modalidade_registrada.size(); i++) {
        transporte_cadastrado[i_cadastro].AddModalidade(modalidade_registrada[i].GetPorte(), modalidade_registrada[i].GetCarga_Max_KG(), modalidade_registrada[i].GetCusto_Por_KM());
    }

    transporte_cadastrado[i_cadastro].IdentificarModelo();
    transporte_cadastrado[i_cadastro].CalcularCustos();
    transporte_cadastrado[i_cadastro].FinalizarCadastro();
}

void Transportadora::DadosEstatisticos() {
    int i_cadastro = 0;
    i_cadastro = transporte_cadastrado.size();

    if (i_cadastro > 0) {
        for (int i = 0; i < transporte_cadastrado.size(); i++) {
            cout << "\nTransporte Cadastrado " << i + 1 << endl;
            transporte_cadastrado[i].MostrarDadosEstatiscos();
        }
    }
    else {
        cout << "\nAinda não há transportes cadastrados. Faça um cadastro para vê-lo aqui." << endl;
    }
}

int Transportadora::EncontrarPosicaoCidade(string arg_cidade) {
    bool apoioBool = false;
    string cidade = "";
    string linha = "";
    string apoioString = "";
    int i = 0;

    apoioString = arg_cidade;
    cidade = apoioString;
    transform(cidade.begin(), cidade.end(), cidade.begin(), toupper);
    apoioString = "";

    ifstream Tabela;
    Tabela.open("DNIT-Distancias.csv");

    while (getline(Tabela, linha) && cidade != apoioString) {
        stringstream input(linha);

        if (cidade != apoioString) {
            while (getline(Tabela, linha) && cidade != apoioString) {
                getline(input, apoioString, ';');

                if (cidade != apoioString) {
                    i++;
                } else {
                    apoioBool = true;
                }
            }
        }
        linha = "";
    }

    if (apoioBool == false) {
        i = -1;
    }

    return i;
}

int Transportadora::CalcularDistancia(int arg_cidade_origem, int arg_cidade_destino) {

    int cidade_origem = 0;
    int cidade_destino = 0;
    int distancia = 0;
    int i = 0;
    int j = 0;
    string linha = "";
    string apoioString = "";

    cidade_origem = arg_cidade_origem;
    cidade_origem = cidade_origem + 2;
    cidade_destino = arg_cidade_destino;

    ifstream Tabela;
    Tabela.open("DNIT-Distancias.csv");

    while (getline(Tabela, linha) && cidade_origem != i) {

        stringstream input(linha);
        getline(input, apoioString, ';');
        i++;

        if (cidade_origem == i) {
            while (cidade_destino != j) {
                getline(input, apoioString, ';');
                j++;
            }
        }
        linha = "";
    }

    distancia = stoi(apoioString);
    return distancia;
}

double Transportadora::CalcularCustoTotal(double arg_custo_por_km, int arg_distancia) {
    cout << setprecision(2) << fixed;
    int distancia = arg_distancia;
    double distancia_d = (double)distancia + 0.00;
    double custo_por_km = arg_custo_por_km;
    double custo_total = 0;

    custo_total = (custo_por_km * distancia_d);
    return custo_total;
}

int Transportadora::TestarExcecao(string arg_string) {
    int apoioInt = 0;
    string apoioString = arg_string;

    try {
        apoioInt = atoi(apoioString.c_str());
        if (apoioInt <= 0) {
            throw (apoioString);
        }
    }
    catch (string apoioString) {
        cout << "\nA opção " << apoioString << " é inválida." << endl;
    }
    return apoioInt;
}