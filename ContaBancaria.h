#ifndef CONTA_BANCARIA_H
#define CONTA_BANCARIA_H

#include <string>
#include <vector>

struct Operacao {
    std::string tipo;
    double valor;
    double saldoApos;
};

class ContaBancaria {
    private:
        std::string titular;
        double saldo;
        std::vector<Operacao> historico;
        void registrarOperacao(const std::string& tipo, double valor);
    
    public:
        ContaBancaria(std::string titular, double saldoInicial);
        double consultarSaldo() const;
        bool depositar(double valor, std::string& mensagemErro);
        bool sacar(double valor, std::string& mensagemErro);
        bool expotarExtrato(const std::string& nomeArquivo) const;
        void exibirExtratoConsole() const;
};

#endif