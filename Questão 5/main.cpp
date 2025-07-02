#include <iostream>
using namespace std;

class Relogio {
private:
    int hora, minuto, segundo;

public:
    Relogio() : hora(0), minuto(0), segundo(0) {}

    void setHora(int h, int m, int s) {
        hora = h;
        minuto = m;
        segundo = s;
    }

    int getHora(int& h, int& m, int& s) const {
        h = hora;
        m = minuto;
        s = segundo;
    }

    void proxSegundo() {
        segundo++;
        if (segundo == 60) {
            segundo = 0;
            minuto++;
            if (minuto == 60) {
                minuto = 0;
                hora++;
                if (hora == 24) {
                    hora = 0;
                }
            }
        }
    }
};

void mostrarHorarioFormatado(int h, int m, int s) {
    if (h < 10) cout << "0";
    cout << h << ":";

    if (m < 10) cout << "0";
    cout << m << ":";

    if (s < 10) cout << "0";
    cout << s << endl;
}

int main() {
    Relogio relogio;
    int opcao;
    int h, m, s;

    do {
        cout << "MENU DO RELOGIO" << endl;
        cout << "1 - Definir Horario" << endl;
        cout << "2 - Mostrar Horario Atual" << endl;
        cout << "3 - Avançar 1 Segundo" << endl;
        cout << "4 - Sair" << endl;
        cout << "Escolha: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Informe a Hora (0-23): ";
                cin >> h;
                cout << "Informe o Minuto (0-59): ";
                cin >> m;
                cout << "Informe o Segundo (0-59): ";
                cin >> s;
                relogio.setHora(h, m, s);
                cout << "Horario Definido Com Sucesso!" << endl;
                break;

            case 2:
                relogio.getHora(h, m, s);
                cout << "Horario Atual: ";
                mostrarHorarioFormatado(h, m, s);
                break;

            case 3:
                relogio.proxSegundo();
                relogio.getHora(h, m, s);
                cout << "Novo Horario: ";
                mostrarHorarioFormatado(h, m, s);
                break;

            case 4:
                cout << "Programa Finalizado!" << endl;
                break;

            default:
                cout << "Opcao Invalida! Tente Novamente." << endl;
        }

        cout << endl;

    } while (opcao != 4);

    return 0;
}}