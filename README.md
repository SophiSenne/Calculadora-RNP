# Calculadora-RNP

## Descrição

Este é um projeto de uma calculadora que resolve expressões na notação polonesa reversa (RPN - Reverse Polish Notation).

## Funcionalidades

- Resolve expressões RPN para: 
    - Soma (+);
    - Subtração (-);
    - Multiplicação (*); e
    - Divisão (/).
- Validação de entrada para garantir que apenas números e operadores válidos sejam processados.
- Tratamento de erros.
- Interface de usuário simples para inserir a expressão RPN.

## Como utilizar

1.  Compile o código:

    ```bash
    gcc src/main.c src/pilha.h src/calcular.h src/exibirInfos.h -o calculadora
    ```
2.  Execute o programa:

    ```bash
    ./calculadora
    ```
3.  Siga as instruções para inserir a expressão RPN.

### Exemplo de uso
Expressão Inserida: `5 3 + 2 *`

Resultado: `16`


## Estrutura de pastas

-   `src/`: Contém o código fonte do projeto.
    -   `main.c`: Função principal que inicia a calculadora e interage com o usuário.
    -   `pilha.h`: Implementação da estrutura de dados Pilha.
    -   `calcular.h`: Funções para realizar os cálculos e ler os valores da entrada.
    -   `exibirInfos.h`: Funções para exibir informações e instruções ao usuário.
-   `.vscode/`: Configurações para o Visual Studio Code.
-   `README.md`: Documentação do projeto.

## Implementação do algoritmo

O algoritmo da calculadora RPN foi implementado utilizando uma pilha para armazenar os operandos. A entrada é lida e separada em tokens. Se o token for um número, ele é convertido para inteiro e empilhado na pilha. Se o token for um operador (+, -, *, /), os dois operandos do topo da pilha são desempilhados, a operação é realizada e o resultado é empilhado de volta na pilha.

### Passos

1.  **Inicialização:** Uma pilha é inicializada para armazenar os operandos.

2.  **Leitura da entrada:** A entrada é lida como uma string e dividida em tokens separados por espaços.

3.  **Processamento dos tokens:**
    *   Se o token for um número: Converte-se o token para um inteiro e o empilha na pilha.
    *   Se o token for um operador: Desempilha-se os dois operandos do topo da pilha (o segundo operando é o primeiro a ser desempilhado), realiza-se a operação especificada pelo operador e se empilha o resultado na pilha.

4.  **Resultado final:** Após todos os tokens serem processados, o resultado final deve ser o único valor restante na pilha; assim, esse valor é desempilhado e exibido como resultado.

### Tratamento de erros:

*   **Pilha vazia:** Ocorre quando um operador é encontrado, mas não há operandos suficientes na pilha.
*   **Pilha cheia:** Ocorre quando a pilha atinge sua capacidade máxima ao tentar empilhar um novo operando.
*   **Divisão por zero:** Ocorre quando o segundo operando é zero.
*   **Entrada inválida:** Ocorre quando um token não é um número nem um operador válido.

### Exemplo

Para a expressão `5 3 + 2 *`:

1.  `5` é lido e empilhado. A pilha contém: `[5]`
2.  `3` é lido e empilhado. A pilha contém: `[5, 3]`
3.  `+` é lido. `3` e `5` são desempilhados, `5 + 3 = 8` é calculado e `8` é empilhado. A pilha contém: `[8]`
4.  `2` é lido e empilhado. A pilha contém: `[8, 2]`
5.  `*` é lido. `2` e `8` são desempilhados, `8 * 2 = 16` é calculado e `16` é empilhado. A pilha contém: `[16]`
6. O resultado final é `16`.

