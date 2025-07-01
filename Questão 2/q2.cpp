#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Pessoa {
private:
    string name;
    int bDay;
    int bMonth;

public:
    Pessoa() {}
    Pessoa(const string& nam, int dia, int mes) :
        name(nam), bDay(dia), bMonth(mes) {}
    ~Pessoa() {}

    string getName() const {return name;}
    int getbDay() const {return bDay;}
    int getbMonth() const {return bMonth;}

    void setName(const string& nam) {name = nam;}
    void setbDay(int dia) {bDay = dia;}
    void setbMonth(int mes) {bMonth = mes;}

    static void criarPessoa(const string& arqName);
    static void carregarPessoas(const string& arqName);
    static void listarPessoas();
};

vector <Pessoa*> pessoas;
string meses[12] = {
    "JANEIRO", "FEVEREIRO", "MARÇO", "ABRIL", "MAIO", "JUNHO",
    "JULHO", "AGOSTO", "SETEMBRO", "OUTUBRO", "NOVEMBRO", "DEZEMBRO"
};

void Pessoa::criarPessoa(const string& arqName) {
    string nome;
    cout << "Nome: ";
    getline(cin, nome);

    int dia;
    cout << "Dia do Aniversário: ";
    cin >> dia;

    int mes;
    cout << "Mês do Aniversário (1-12): ";
    cin >> mes;

    Pessoa* newPerson = new Pessoa();
    newPerson->setName(nome);
    newPerson->setbDay(dia);
    newPerson->setbMonth(mes);

    pessoas.push_back(newPerson);

    ofstream arq(arqName + ".txt");
    if (arq.is_open()) {
        arq << pessoas.size() << endl;

        for (Pessoa* p : pessoas) {
            arq << p->getName() << endl;
            arq << p->getbDay() << endl;
            arq << p->getbMonth() << endl;
        }

        cout << "Nova Pessoa Registrada e Adicionada ao Arquivo '" << arqName << "'" << endl;
        arq.close();
    } else {
        cout << "Erro ao Abrir o Arquivo!" << endl;
    }
}

void Pessoa::carregarPessoas(const string& arqName) {
    ifstream arq(arqName + ".txt");

    if (!arq.is_open()) {
        cout << "Arquivo Não Encontrado. Um Novo será Criado ao Salvar." << endl;
        return;
    }

    int total;
    arq >> total;
    arq.ignore();

    for (int i = 0; i < total; i++) {
        string nome;
        getline(arq, nome);

        if (nome.empty()) break;

        int dia;
        arq >> dia;

        int mes;
        arq >> mes;
        arq.ignore();

        Pessoa* loadPerson = new Pessoa();
        loadPerson->setName(nome);
        loadPerson->setbDay(dia);
        loadPerson->setbMonth(mes);

        pessoas.push_back(loadPerson);
    }

    arq.close();
    cout << "Dados Carregados com Sucesso. Total de Pessoas: " << pessoas.size() << endl;
}

void Pessoa::listarPessoas() {
    if (pessoas.empty()) {
        cout << "Nenhuma Pessoa Cadastrada." << endl;
        return;
    }

    cout << "\n=== Lista de Pessoas ===\n";
    int i = 0;

    for (Pessoa* p : pessoas) {
        cout << "[" << i + 1 << "]" << endl;
        cout << "Nome: " << p->getName() << endl;
        cout << "Dia do Aniversário: " << p->getbDay() << endl;
        cout << "Mês do Aniversário: " << p->getbMonth() << endl;

        i++;
    }
}

int main() {
    int esc;

    string arqName;
    cout << "Nome do Arquivo (Salvar ou Carregar): ";
    getline(cin, arqName);

    Pessoa::carregarPessoas(arqName);

    do {
        cout << "0 - Sair" << endl;
        cout << "1 - Criar Pessoa" << endl;
        cout << "2 - Listar Pessoas" << endl;
        cout << "Escolha: ";
        cin >> esc;

        while (cin.fail() || (esc != 0 && esc != 1 && esc != 2)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada Inválida. Tente Novamente: ";
            cin >> esc;
        }
        cin.ignore();

        switch (esc) {
            case 1:
                Pessoa::criarPessoa(arqName);
                break;
            case 2:
                Pessoa::listarPessoas();
                break;
        }

    } while (esc != 0);


    for (Pessoa* p : pessoas) {
        delete p;
    }

    pessoas.clear();

    cout << "Programa Finalizado!" << endl;

    return 0;
}