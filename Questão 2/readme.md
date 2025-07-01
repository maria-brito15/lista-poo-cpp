# Questão – Gerenciamento de Cadastro de Pessoas com Data de Aniversário em C++

Implemente um programa em C++ para gerenciar um cadastro de pessoas, onde cada pessoa possui os seguintes atributos: nome, dia do aniversário e mês do aniversário.

## Funcionamento do Programa

- Ao iniciar, o programa deve solicitar o nome do arquivo (sem extensão) para carregar os dados existentes. Caso o arquivo não exista, o programa deve informar que um novo arquivo será criado ao salvar.
- O arquivo texto deve armazenar, na primeira linha, o número total de pessoas cadastradas, seguido dos dados de cada pessoa em sequência: nome, dia do aniversário e mês do aniversário.
- O programa deve permitir que o usuário:
    - Crie uma nova pessoa, solicitando o nome, dia e mês do aniversário via entrada padrão.
    - Liste todas as pessoas cadastradas, exibindo nome, dia e mês do aniversário.
    - Encerre o programa.
- Após a criação de uma nova pessoa, os dados de todas as pessoas devem ser salvos automaticamente no arquivo.
- Use uma classe `Pessoa` para representar cada pessoa, com atributos privados e métodos públicos para acesso e manipulação.
- Utilize um vetor global de ponteiros para `Pessoa` para armazenar os objetos dinamicamente.
- Garanta o correto gerenciamento de memória, liberando todos os objetos criados antes de encerrar o programa.
- Implemente um menu de texto simples para interação com o usuário.
- Trate entradas inválidas no menu para evitar erros durante a execução.

## Requisitos Adicionais

- O programa deve mostrar uma mensagem apropriada caso o arquivo não seja encontrado durante o carregamento.
- O arquivo deve ser salvo com extensão `.txt`.
- O mês do aniversário deve ser armazenado como número (1 a 12), mas o programa deve disponibilizar um array com os nomes dos meses para possíveis usos futuros.
- Use `getline` para leitura dos nomes, permitindo nomes com espaços.
- Seja cuidadoso para limpar o buffer do `cin` entre as leituras para evitar problemas na entrada.
