# Simulador de Caixa Eletrônico (ATM) em C++

Aplicação de linha de comando (CLI) desenvolvida em **C++17** para simular operações bancárias básicas com **validação rigorosa de regras de negócio** e **exportação de extrato em arquivo texto** (`extrato.txt`).

---

## Funcionalidades

- **Consultar saldo** atualizado em reais (`R$`)
- **Depositar dinheiro** bloqueando valores menores ou iguais a zero
- **Sacar dinheiro** bloqueando valores inválidos (`<= 0`) ou maiores que o saldo disponível
- **Visualizar extrato** diretamente no terminal com histórico de operações e saldo após cada movimentação
- **Exportar extrato** para arquivo de texto formatado (`extrato.txt`)

---

## Conceitos e Boas Práticas Aplicadas

- **Encapsulamento e POO** com separação entre declaração (`ContaBancaria.h`) e implementação (`ContaBancaria.cpp`)
- **Validação de regras de negócio** e tratamento de entradas inválidas no `std::cin`
- **Coleções da STL** (`std::vector`) para armazenar o histórico de operações com segurança
- **Manipulação de arquivos** com `std::ofstream`, `std::fixed` e `std::setprecision(2)`
- **Automação de build** com `Makefile` e compilação incremental (`-MMD -MP`)

---

## Estrutura do Projeto

```text
simulador-atm-cpp/
├── ContaBancaria.h     # Declaração da classe ContaBancaria e struct Operacao
├── ContaBancaria.cpp   # Regras de negócio, histórico e exportação do extrato
├── main.cpp            # Menu interativo CLI e validação de entradas
├── Makefile            # Regras de compilação, testes e limpeza
├── .gitignore          # Arquivos ignorados pelo Git
└── README.md           # Documentação do projeto
```

---

## Como Compilar e Executar

### Pré-requisitos
- Compilador C++17 (`g++` ou `clang++`)
- Utilitário `make` (opcional, mas recomendado)

### Usando o `Makefile`

```bash
# Clonar o repositório
git clone https://github.com/nicolascalegari/simulador-atm-cpp.git
cd simulador-atm-cpp

# Compilar o projeto
make

# Executar o programa
./atm_sim
```

Outros comandos úteis:
```bash
make run       # Compila (se necessário) e executa o programa
make test      # Compila e executa os testes (quando houver tests.cpp)
make clean     # Remove arquivos objeto (.o), dependências (.d) e binários
make distclean # Remove binários e o arquivo extrato.txt gerado
```

### Compilando manualmente com `g++`

Caso não tenha o `make` instalado:

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic -O2 main.cpp ContaBancaria.cpp -o atm_sim
./atm_sim
```

---

## Exemplo de Uso

```text
Bem-vindo ao Simulador de Caixa Eletronico!

1 - Consultar saldo
2 - Depositar
3 - Sacar
4 - Ver extrato na tela
5 - Exportar extrato (.txt)
0 - Sair
Escolha uma opcao: 3
Valor do saque: R$ 1500.00
Falha no saque: Saldo insuficiente para realizar este saque.

Escolha uma opcao: 2
Valor do deposito: R$ 500.00
Deposito realizado! Novo saldo: R$ 1500.00
```

---