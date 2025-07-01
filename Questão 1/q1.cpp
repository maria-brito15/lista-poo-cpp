#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <ctime>
using namespace std;

class Pessoa {
private:
    int id;
    string name;
    int age;
    string address;
    int number;
    string complement;

public:
    Pessoa() {}
    Pessoa(int i, const string& nam, int a, const string& adre, int num, const string& comp) :
        id(i), name(nam), age(a), address(adre), number(num), complement(comp) {}
    ~Pessoa() {}

    int getId() const {return id;}
    string getName() const {return name;}
    int getAge() const {return age;}
    string getAddress() const {return address;}
    int getNumber() const {return number;}
    string getComplement() const {return complement;}

    void setId(int i) {id = i;}
    void setName(const string& nam) {name = nam;}
    void setAge(int a) {age = a;}
    void setAddress(const string& adre) {address = adre;}
    void setNumber(int num) {number = num;}
    void setComplement(const string& comp) {complement = comp;}

    static void criarPessoa(const string& arqName);
    static void carregarPessoas(const string& arqName);
    static void listarPessoas();
};

vector <Pessoa*> pessoas;

void Pessoa::criarPessoa(const string& arqName) {
    int idGerado = rand() % 9000 + 1000;

    string nome;
    cout << "Nome: ";
    getline(cin, nome);

    int idade;
    cout << "Idade: ";
    cin >> idade;
    cin.ignore();

    string bairro;
    cout << "Bairro: ";
    getline(cin, bairro);

    int numero;
    cout << "Número: ";
    cin >> numero;
    cin.ignore();

    string complemento;
    cout << "Complemento: ";
    getline(cin, complemento);

    cout << "ID Gerado: " << idGerado << endl;

    Pessoa* newPerson = new Pessoa();
    newPerson->setId(idGerado);
    newPerson->setName(nome);
    newPerson->setAge(idade);
    newPerson->setAddress(bairro);
    newPerson->setNumber(numero);
    newPerson->setComplement(complemento);

    pessoas.push_back(newPerson);

    ofstream arq(arqName + ".txt");
    if (arq.is_open()) {
        arq << pessoas.size() << endl;

        int i = 0;
        for (Pessoa* p : pessoas) {
            arq << "[" << i + 1 << "]" << endl;

            arq << p->getId() << endl
                << p->getName() << endl
                << p->getAge() << endl
                << p->getAddress() << endl
                << p->getNumber() << endl
                << p->getComplement() << endl;

            i++;
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
        string linha;
        getline(arq, linha);

        int id;
        string nome;
        int idade;
        string bairro;
        int numero;
        string complemento;

        arq >> id;
        arq.ignore();

        getline(arq, nome);

        arq >> idade;
        arq.ignore();

        getline(arq, bairro);

        arq >> numero;
        arq.ignore();

        getline(arq, complemento);

        Pessoa* loadPerson = new Pessoa();
        loadPerson->setId(id);
        loadPerson->setName(nome);
        loadPerson->setAge(idade);
        loadPerson->setAddress(bairro);
        loadPerson->setNumber(numero);
        loadPerson->setComplement(complemento);

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
        cout << "ID: " << p->getId() << endl;
        cout << "Nome: " << p->getName() << endl;
        cout << "Idade: " << p->getAge() << endl;
        cout << "Endereço: " << p->getAddress() << endl;
        cout << "Numero: " << p->getNumber() << endl;
        cout << "Complemento: " << p->getComplement() << endl;

        i++;
    }
}

int main() {
    srand(time(NULL));

    string arqName;
    int resp;

    cout << "Nome do Arquivo (Salvar ou Carregar): ";
    getline(cin, arqName);

    Pessoa::carregarPessoas(arqName);

    do {
        cout << "\nMenu:\n";
        cout << "1 - Criar Pessoa\n";
        cout << "2 - Listar Pessoas\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> resp;

        while (cin.fail() || (resp != 0 && resp != 1 && resp != 2)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada Inválida. Tente Novamente: ";
            cin >> resp;
        }
        cin.ignore();

        switch (resp) {
            case 1:
                Pessoa::criarPessoa(arqName);
                break;
            case 2:
                Pessoa::listarPessoas();
                break;
            case 0:
                cout << "Saindo do Programa..." << endl;
                break;
            default:
                break;
        }

    } while (resp != 0);

    for (Pessoa* p : pessoas) {
        delete p;
    }

    pessoas.clear();

    cout << "Programa Finalizado!" << endl;

    return 0;
}