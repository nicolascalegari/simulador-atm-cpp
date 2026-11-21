#include "ContaBancaria.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <utility>

using namespace std;

ContaBancaria::ContaBancaria(std::string titular, double saldoInicial)
    : titular(std::move(titular)), saldo(saldoInicial >= 0.0 ? saldoInicial : 0.0) {
        registrarOperacao("SALDO INICIAL", this -> saldo);
}

void ContaBancaria::registrarOperacao(const std::string& tipo, double valor) {
    historico.push_back({tipo, valor, saldo});
}

double ContaBancaria::consultarSaldo() const {
    return saldo;
}

bool ContaBancaria::depositar(double valor, std::string& mensagemErro) {
    if (valor <= 0.0) {
        mensagemErro = "O valor do deposito deve ser maior que zero.";
        return false;
    }
    saldo += valor;
    registrarOperacao("DEPOSITO", valor);
    return true;
}

bool ContaBancaria::sacar(double valor, std::string& mensagemErro) {
    if (valor <= 0.0) {
        mensagemErro = "O valor do saque deve ser maior que zero.";
        return false;
    }

    if (valor > saldo) {
        mensagemErro = "Saldo insuficiente para realizar esse saque.";
        return false;
    }

    saldo -= valor;
    registrarOperacao("SAQUE", valor);
    return true;
}

bool ContaBancaria::expotarExtrato(const std::string& nomeArquivo) const {
    ofstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        return false;
    }

    arquivo << "=========================================\n";
    arquivo << "         EXTRATO BANCARIO - ATM          \n";
    arquivo << "=========================================\n";
    arquivo << "Titular: " << titular << "\n\n";
    arquivo << fixed << setprecision(2);

    for (const auto& op : historico) {
        arquivo << left << setw(15) << op.tipo
                << " | Valor: R$ " << right << setw(9) << op.valor
                << " | Saldo: R$ " << setw(9) << op.saldoApos << "\n";
    }

    arquivo << "\nSaldo final: R$ " << saldo << "\n";
    arquivo << "=========================================\n";
    return true;
}

void ContaBancaria::exibirExtratoConsole() const {
    cout << "\n================ EXTRATO ================\n";
    cout << "Titular: " << titular << "\n";
    cout << fixed << setprecision(2);

    for (const auto& op : historico) {
        cout << "- " << left << setw(15) << op.tipo
             << " | R$ " << right << setw(9) << op.valor
             << " | Saldo: R$ " << setw(9) << op.saldoApos << "\n";
    }
    cout << "=========================================\n";
}