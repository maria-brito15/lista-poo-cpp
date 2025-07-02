# Questão – Sistema de Simulação de Relógio em C++

Implemente um programa em C++ que simula o funcionamento de um relógio digital, armazenando e manipulando informações de horário no formato de 24 horas (horas, minutos e segundos). O programa deve permitir que o usuário defina um horário, visualize o horário atual e avance o tempo em segundos.

## Funcionamento do Programa

- O programa deve utilizar uma classe chamada `Relogio`, responsável por armazenar as informações de horário e realizar as operações desejadas.
- O usuário deve interagir com o programa por meio de um menu com as seguintes opções:
    - **Definir Horário**: Permite ao usuário informar a hora, o minuto e o segundo desejado.
    - **Mostrar Horário Atual**: Exibe o horário atual no formato `HH:MM:SS`.
    - **Avançar 1 Segundo**: Avança o horário em um segundo, atualizando corretamente os minutos e as horas se necessário.
    - **Sair**: Encerra a execução do programa.

## Regras e Restrições

- A hora deve ser um valor entre 0 e 23.
- O minuto e o segundo devem ser valores entre 0 e 59.
- Ao atingir `23:59:59`, o próximo segundo deve reiniciar o horário para `00:00:00`.

## Estrutura da Classe

- A classe `Relogio` deve conter os seguintes atributos privados:
    - `hora`: inteiro representando a hora (0–23)
    - `minuto`: inteiro representando os minutos (0–59)
    - `segundo`: inteiro representando os segundos (0–59)
- Métodos públicos obrigatórios:
    - `void setHora(int h, int m, int s)`: define um novo horário.
    - `void getHora(int& h, int& m, int& s) const`: retorna o horário atual por referência.
    - `void proxSegundo()`: avança o horário em um segundo, com tratamento de virada de minuto e hora.
- O programa deve exibir o horário com dois dígitos para cada unidade, por exemplo: `03:07:09`.
