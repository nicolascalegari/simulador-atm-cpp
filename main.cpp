#include "ContaBancaria.h"
#include <iomanip>
#include <iostream>
#include <limits>

using namespace std;

namespace {
    bool lerDouble(const string& prompt, double& saida) {
        cout << prompt;
        if (!(cin >> saida)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return false;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true;
    }

    bool lerInt(const string& prompt, int& saida) {
        cout << prompt;
        if (!(cin >> saida)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return false;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true;
    }
} // namespace

int main() {
    ContaBancaria conta("Cliente Demo", 1000.00);
    int opcao = 0;

    cout << fixed << setprecision(2);
    cout << "Bem-vindo ao Simulador de Caixa Eletronico!\n";

    while (true) {
        cout << "\n1 - Consultar saldo\n";
        cout << "2 - Depositar\n";
        cout << "3 - Sacar\n";
        cout << "4 - Ver extrato na tela\n";
        cout << "5 - Exportar extrato (.txt)\n";
        cout << "0 - Sair\n";

        if (!lerInt("Escolha uma opcao: ", opcao)) {
            cout << "Entrada invalida. Digite um numero inteiro.";
            continue;
        }

        if (opcao == 0) {
            cout << "Encerrando sessao. Ate logo!\n";
            break;
        }

        switch (opcao) {
            case 1: {
                cout << "Saldo atual: R$ " << conta.consultarSaldo() << "\n";
                break;
            }

            case 2: {
                double valor = 0.0;
                string erro;
                if (!lerDouble("Valor do deposito: R$ ", valor)) {
                    cout << "valor invalido. Use apenas numeros.\n";
                    break;
                }
                if (conta.depositar(valor, erro)) {
                    cout << "Deposito realizado! Novo saldo: R$ " << conta.consultarSaldo() << "\n";
                } else {
                    cout << "Falha no deposito: " << erro << "\n";
                }
                break;
            }

            case 3: {
                double valor = 0.0;
                string erro;
                if (!lerDouble("Valor do saque: R$ ", valor)) {
                    cout << "valor invalido. Use apenas numeros.\n";
                    break;
                }
                if (conta.sacar(valor, erro)) {
                    cout << "Saque realizado! Novo saldo: R$ " << conta.consultarSaldo() << "\n";
                } else {
                    cout << "Falha no saque: " << erro << "\n";
                }
                break;
            }

            case 4: {
                conta.exibirExtratoConsole();
                break;
            }

            case 5: {
                const string arquivo = "extrato.txt";
                if (conta.expotarExtrato(arquivo)) {
                    cout << "Extrato salvo com sucesso em '" << arquivo << "'\n";
                } else {
                    cout << "Nao foi possivel criar o arquivo de extrato.\n";
                }
                break;
            }
            
            default:
                cout << "Opcao desconhecida. Tente novamente.\n";
        }
    }

    return 0;
    
}