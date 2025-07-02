#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Eletrodomestico {
private:
    string loja;
    int telefone;
    double custo;

public:
    Eletrodomestico() : loja(""), telefone(0), custo(0.0) {}
    Eletrodomestico(const string& store, int number, double price)
        : loja(store), telefone(number), custo(price) {}

    ~Eletrodomestico() {}

    static void calculoLojas(const string& arqRelatorio);
    static void criarSalvarEletrodomestico(const string& arqName);
    static void carregarEletrodomestico(const string& arqName);

    int getTelefone() const { return telefone; }
    double getCusto() const { return custo; }
    string getLoja() const { return loja; }

    void setTelefone(int number) { telefone = number; }
    void setCusto(double price) { custo = price; }
    void setLoja(const string& store) { loja = store; }
};

vector<Eletrodomestico*> itens;

void Eletrodomestico::calculoLojas(const string& arqRelatorio) {
    if (itens.empty()) {
        cout << "Nenhum Eletrodoméstico Cadastrado!" << endl;
        return;
    }

    double soma = 0;
    for (Eletrodomestico* item : itens) {
        soma += item->getCusto();
    }

    double media = soma / itens.size();

    vector<string> lojasUnicas;
    for (Eletrodomestico* item : itens) {
        bool jaExiste = false;

        for (string loja : lojasUnicas) {
            if (loja == item->getLoja()) {
                jaExiste = true;
                break;
            }
        }

        if (!jaExiste) {
            lojasUnicas.push_back(item->getLoja());
        }
    }

    ofstream arq(arqRelatorio + ".txt");
    if (arq.is_open()) {
        arq << "Media dos Preços: " << media << endl;
        arq << "Quantidade de Lojas Unicas: " << lojasUnicas.size() << endl;
        arq << endl;

        arq << "Eletrodomesticos com Preço Abaixo da Media:" << endl;

        int contador = 0;
        for (int i = 0; i < itens.size(); i++) {
            if (itens[i]->getCusto() < media) {
                contador++;
                arq << "[" << contador << "]" << endl;
                arq << "Loja: " << itens[i]->getLoja() << endl;
                arq << "Telefone: " << itens[i]->getTelefone() << endl;
                arq << "Preco: R$ " << itens[i]->getCusto() << endl;
                arq << endl;

                cout << "[" << contador << "]" << endl;
                cout << "Loja: " << itens[i]->getLoja() << endl;
                cout << "Telefone: " << itens[i]->getTelefone() << endl;
                cout << "Preco: R$ " << itens[i]->getCusto() << endl;
                cout << endl;
            }
        }

        if (contador == 0) {
            arq << "Nenhum Eletrodomestico com Preço Abaixo da Media." << endl;
            cout << "Nenhum Eletrodomestico com Preço Abaixo da Media." << endl;
        }

        cout << "Dados Salvos no Arquivo: " << arqRelatorio << ".txt" << endl;
        arq.close();
    } else {
        cout << "Erro ao Abrir o Arquivo para Escrita!" << endl;
    }
}

void Eletrodomestico::criarSalvarEletrodomestico(const string& arqName) {
    string nomeLoja;
    int telefone;
    double custo;

    cout << "CADASTRO DE NOVO ELETRODOMESTICO" << endl;
    cout << "Nome da Loja: ";
    getline(cin, nomeLoja);

    cout << "Telefone da Loja: ";
    cin >> telefone;

    while (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Telefone Invalido. Digite Novamente: ";
        cin >> telefone;
    }

    cout << "Custo do Produto: R$ ";
    cin >> custo;

    while (cin.fail() || custo < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Custo Invalido. Digite Novamente: R$ ";
        cin >> custo;
    }

    cin.ignore();

    Eletrodomestico* novo = new Eletrodomestico(nomeLoja, telefone, custo);
    itens.push_back(novo);

    ofstream arq(arqName + ".txt");
    if (arq.is_open()) {
        arq << itens.size() << endl;

        for (const auto& item : itens) {
            arq << item->getLoja() << endl;
            arq << item->getTelefone() << endl;
            arq << item->getCusto() << endl;
        }

        cout << "Novo Eletrodomestico Adicionado e Dados Salvos!" << endl;
        arq.close();
    } else {
        cout << "Erro ao Abrir o Arquivo para Escrita!" << endl;
    }
}

void Eletrodomestico::carregarEletrodomestico(const string& arqName) {
    ifstream arq(arqName + ".txt");

    if (!arq.is_open()) {
        cout << "Arquivo '" << arqName << ".txt' não Encontrado. Um Novo Sera Criado ao Salvar." << endl;
        return;
    }

    for (Eletrodomestico* item : itens) {
        delete item;
    }

    itens.clear();

    int quantidade;
    arq >> quantidade;
    arq.ignore();

    for (int i = 0; i < quantidade; i++) {
        string loja;
        int telefone;
        double custo;

        getline(arq, loja);
        arq >> telefone;
        arq >> custo;
        arq.ignore();

        Eletrodomestico* carregado = new Eletrodomestico(loja, telefone, custo);
        itens.push_back(carregado);
    }

    arq.close();
    cout << itens.size() << " Eletrodomesticos Carregados do Arquivo '" << arqName << ".txt'!" << endl;
}

void exibirMenu() {
    cout << "SISTEMA DE ELETRODOMESTICOS" << endl;
    cout << "1 - Cadastrar Novo Eletrodomestico" << endl;
    cout << "2 - Calcular Media e Gerar Relatorio" << endl;
    cout << "3 - Exibir Todos os Eletrodomesticos" << endl;
    cout << "0 - Sair" << endl;
    cout << "Escolha uma Opção: ";
}

void exibirTodosItens() {
    if (itens.empty()) {
        cout << "Nenhum Eletrodomestico Cadastrado!" << endl;
        return;
    }

    cout << "ELETRODOMESTICOS CADASTRADOS" << endl;
    for (int i = 0; i < itens.size(); i++) {
        cout << "[" << (i + 1) << "]" << endl;
        cout << "Loja: " << itens[i]->getLoja() << endl;
        cout << "Telefone: " << itens[i]->getTelefone() << endl;
        cout << "Preco: R$ " << itens[i]->getCusto() << endl;
        cout << "------------------------" << endl;
    }
}

int main() {
    int escolha;
    string arqName;

    cout << "Nome do Arquivo para Salvar/Carregar os Dados: ";
    getline(cin, arqName);

    Eletrodomestico::carregarEletrodomestico(arqName);

    do {
        exibirMenu();
        cin >> escolha;

        while (cin.fail() || (escolha < 0 || escolha > 3)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Escolha Invalida. Tente Novamente: ";
            cin >> escolha;
        }

        cin.ignore();

        switch (escolha) {
            case 1:
                Eletrodomestico::criarSalvarEletrodomestico(arqName);
                break;

            case 2: {
                string arqRelatorio;
                cout << "Nome do Arquivo para Salvar o Relatorio: ";
                getline(cin, arqRelatorio);
                Eletrodomestico::calculoLojas(arqRelatorio);
                break;
            }

            case 3:
                exibirTodosItens();
                break;

            case 0:
                cout << "Programa Finalizado!" << endl;
                break;
        }

    } while (escolha != 0);

    for (Eletrodomestico* item : itens) {
        delete item;
    }

    itens.clear();

    return 0;
}