# Questão – Sistema de Gerenciamento de Cadastro de Eletrodomésticos em C++

Implemente um programa em C++ para gerenciar um sistema de cadastro de eletrodomésticos, onde cada eletrodoméstico possui os seguintes atributos: nome da loja, telefone da loja e custo do produto.

## Funcionamento do Programa

- Ao iniciar, o programa deve solicitar o nome do arquivo (sem extensão) para carregar os dados existentes. Caso o arquivo não exista, o programa deve informar que um novo arquivo será criado ao salvar.
- O arquivo texto deve armazenar, na primeira linha, o número total de eletrodomésticos cadastrados, seguido dos dados de cada eletrodoméstico em sequência: nome da loja, telefone da loja e custo do produto.
- O programa deve apresentar um menu com as seguintes opções:
    - **Cadastrar Novo Eletrodoméstico**: Solicita nome da loja, telefone e custo via entrada padrão, validando as entradas.
    - **Calcular Média e Gerar Relatório**: Calcula a média dos preços e gera um relatório detalhado.
    - **Exibir Todos os Eletrodomésticos**: Lista todos os eletrodomésticos cadastrados.
    - **Sair**: Encerra o programa.
- Após o cadastro de um novo eletrodoméstico, os dados de todos os itens devem ser salvos automaticamente no arquivo.

## Funcionalidade de Relatório

O programa deve implementar uma funcionalidade para gerar relatórios que:
- Calcula a média dos preços de todos os eletrodomésticos cadastrados.
- Conta o número de lojas únicas no cadastro.
- Lista todos os eletrodomésticos com preço abaixo da média calculada.
- Salva o relatório em um arquivo de texto separado, cujo nome é solicitado ao usuário.
- Exibe na tela os eletrodomésticos com preço abaixo da média.

## Estrutura da Classe

- Use uma classe `Eletrodomestico` para representar cada item, com atributos privados e métodos públicos para acesso e manipulação.
- Implemente métodos estáticos para:
    - Carregar eletrodomésticos do arquivo
    - Criar e salvar novos eletrodomésticos
    - Calcular médias e gerar relatórios
- Utilize um vetor global de ponteiros para `Eletrodomestico` para armazenar os objetos dinamicamente.

## Formato dos Arquivos

### Arquivo de Dados (entrada/saída):
```
<numero_total_de_eletrodomesticos>
<nome_da_loja_1>
<telefone_1>
<custo_1>
<nome_da_loja_2>
<telefone_2>
<custo_2>
...
```

### Arquivo de Relatório (saída):
```
Media dos Preços: <valor_media>
Quantidade de Lojas Unicas: <numero_lojas>

Eletrodomesticos com Preço Abaixo da Media:
[1]
Loja: <nome_loja>
Telefone: <telefone>
Preco: R$ <custo>

[2]
...
```