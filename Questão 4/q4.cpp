#include <iostream>
using namespace std;

class Elevador {
private:
    int andarAtual;
    int totalAndares;
    int capacidade;
    int pessoasPresentes;

public:
    Elevador() : andarAtual(0), totalAndares(0), capacidade(0), pessoasPresentes(0) {}

    void inicializa(int cap, int total) {
        capacidade = cap;
        totalAndares = total;
        andarAtual = 0;
        pessoasPresentes = 0;
    }

    int getAndarAtual() const { return andarAtual; }
    int getTotalAndares() const { return totalAndares; }
    int getCapacidade() const { return capacidade; }
    int getPessoasPresentes() const { return pessoasPresentes; }

    void entra() {
        if (pessoasPresentes < capacidade) {
            pessoasPresentes++;
            cout << "Uma Pessoa Entrou no Elevador.\n";
        } else {
            cout << "Elevador Cheio! Não é Possível Entrar.\n";
        }
    }

    void sai() {
        if (pessoasPresentes > 0) {
            pessoasPresentes--;
            cout << "Uma Pessoa Saiu do Elevador.\n";
        } else {
            cout << "O Elevador Já está Vazio!\n";
        }
    }

    void sobe() {
        if (andarAtual < totalAndares) {
            andarAtual++;
            cout << "Elevador Subiu para o Andar " << andarAtual << ".\n";
        } else {
            cout << "O Elevador Já Está no Último Andar!\n";
        }
    }

    void desce() {
        if (andarAtual > 0) {
            andarAtual--;
            cout << "Elevador Desceu para o Andar " << andarAtual << ".\n";
        } else {
            cout << "O Elevador Já Está no Térreo!\n";
        }
    }
};

int main() {
    Elevador e;
    int capacidade, totalAndares;
    int opc;

    cout << "Informe a Capacidade do Elevador: ";
    cin >> capacidade;
    cout << "Informe o Total de Andares do Prédio (Tirando o Térreo): ";
    cin >> totalAndares;

    e.inicializa(capacidade, totalAndares);

    do {
        cout << "MENU" << endl;
        cout << "1 - Entrar" << endl;
        cout << "2 - Sair" << endl;
        cout << "3 - Subir" << endl;
        cout << "4 - Descer" << endl;
        cout << "5 - Exibir status" << endl;
        cout << "6 - Sair do Programa" << endl;
        cout << "Opção: ";
        cin >> opc;

        switch (opc) {
            case 1:
                e.entra();
                break;
            case 2:
                e.sai();
                break;
            case 3:
                e.sobe();
                break;
            case 4:
                e.desce();
                break;
            case 5:
                cout << "STATUS DO ELEVADOR" << endl;
                cout << "Andar Atual: " << e.getAndarAtual() << endl;
                cout << "Total de Andares: " << e.getTotalAndares() << endl;
                cout << "Capacidade Máxima: " << e.getCapacidade() << endl;
                cout << "Pessoas Presentes: " << e.getPessoasPresentes() << endl;
                break;
            case 6:
                cout << "Programa Finalizado!" << endl;
                break;
            default:
                cout << "Opção Inválida. Tente Novamente." << endl;
        }
    } while (opc != 6);

    return 0;
}
