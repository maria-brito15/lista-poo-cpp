# Questão 1 – Gerenciamento de Cadastro de Pessoas em C++

Implemente um programa em C++ para gerenciar um cadastro de pessoas, onde cada pessoa possui os seguintes atributos: ID (inteiro), nome, idade, endereço, número e complemento.

Ao iniciar, o programa deve carregar os dados existentes a partir de um arquivo texto, caso este arquivo exista. O arquivo armazenará primeiro o número total de pessoas cadastradas e, em seguida, os dados de cada pessoa.

O programa deve permitir que o usuário crie uma nova pessoa, solicitando os dados via entrada padrão. O ID dessa pessoa deve ser gerado aleatoriamente, garantindo que seja único entre todos os cadastrados. Após a criação, os dados de todas as pessoas devem ser salvos automaticamente no arquivo texto.

Além disso, o programa deve oferecer a funcionalidade de listar todas as pessoas cadastradas, exibindo seus dados completos na tela. A execução do programa deve continuar até que o usuário escolha encerrar a aplicação.

Para representar as pessoas, utilize uma classe chamada `Pessoa`. Os objetos dessa classe devem ser armazenados dinamicamente em um vetor global. Certifique-se de liberar toda a memória alocada antes de encerrar o programa. A interação com o usuário deve ser feita por meio de um menu de texto simples, que permita escolher entre criar uma pessoa, listar pessoas e sair do programa.

---

### Requisitos Adicionais

- O programa deve garantir que os IDs gerados para as pessoas sejam únicos.
- Os dados devem ser armazenados em arquivo texto com o seguinte formato:
    - A primeira linha contém o número total de pessoas.
    - Em seguida, os dados de cada pessoa em sequência: ID, nome, idade, endereço, número e complemento.
- Use entradas do tipo `getline` para ler textos com espaços.
- Trate entradas inválidas no menu para evitar erros de execução.
- Libere corretamente a memória alocada antes de encerrar o programa.

---
