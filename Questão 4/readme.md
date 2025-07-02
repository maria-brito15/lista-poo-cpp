# Questão – Sistema de Simulação de Elevador em C++

Implemente um programa em C++ para simular o funcionamento básico de um elevador em um prédio com múltiplos andares. O sistema deve controlar a movimentação do elevador e a entrada/saída de pessoas, respeitando a capacidade máxima e os limites dos andares.

## Funcionamento do Programa

- Ao iniciar, o programa deve solicitar ao usuário:
    - A capacidade máxima de pessoas do elevador.
    - O número total de andares do prédio (excluindo o térreo).
- O elevador sempre começa no térreo (andar 0) e vazio.
- O programa deve apresentar um menu interativo com as seguintes opções:
    - **Entrar uma pessoa**: Adiciona uma pessoa ao elevador, respeitando a capacidade máxima.
    - **Sair uma pessoa**: Remove uma pessoa do elevador, se houver alguém presente.
    - **Subir um andar**: Sobe um andar, se não estiver no último andar.
    - **Descer um andar**: Desce um andar, se não estiver no térreo.
    - **Exibir status**: Mostra o andar atual, total de andares, capacidade total e número atual de pessoas.
    - **Sair do programa**: Encerra a execução.

## Regras e Restrições

- O elevador não pode subir além do último andar nem descer abaixo do térreo.
- Não é permitido exceder a capacidade máxima de pessoas.
- Não é possível retirar uma pessoa se o elevador estiver vazio.

## Estrutura da Classe

- Utilize uma classe `Elevador` com os seguintes atributos privados:
    - `andarAtual`: inteiro representando o andar onde o elevador se encontra.
    - `totalAndares`: total de andares do prédio (excluindo o térreo).
    - `capacidade`: capacidade máxima de pessoas no elevador.
    - `pessoasPresentes`: número atual de pessoas no elevador.
- A classe deve conter:
    - Um construtor padrão que inicia todos os atributos com zero.
    - Um método `inicializa(int cap, int total)` que define os parâmetros do elevador.
    - Métodos públicos de acesso (getters) para todos os atributos.
    - Métodos públicos:
        - `entra()`: adiciona uma pessoa, se possível.
        - `sai()`: remove uma pessoa, se possível.
        - `sobe()`: sobe um andar, se possível.
        - `desce()`: desce um andar, se possível.

## Exemplo de Interação com o Usuário

```
Informe a Capacidade do Elevador: 5
Informe o Total de Andares do Prédio (sem contar o térreo): 10

Menu:
1 - Entrar
2 - Sair
3 - Subir
4 - Descer
5 - Exibir
6 - Sair do Programa

Opção: 1
Uma Pessoa Entrou.

Opção: 3
Elevador Subiu para o Andar 1.

Opção: 5
Andar Atual: 1
Total de Andares: 10
Capacidade: 5
Pessoas Presentes: 1
```
