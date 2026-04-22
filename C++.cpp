#include <iostream>
#include <string>
#include <windows.h> 

class Produto {
private:
    std::string nome;
    double PrecoUnitario;
    int quantidade;

public:
    Produto() : nome("vazio"), PrecoUnitario(0.0), quantidade(0) {}

    void SetDados(int indice) {
        std::cout << "Digite o nome do Produto " << (indice + 1) << ": ";
        std::cin.ignore();
        std::getline(std::cin, nome);

        std::cout << "Digite o Preco do Produto " << (indice + 1) << ": ";
        std::cin >> PrecoUnitario;

        std::cout << "Digite a Quantidade do Produto " << (indice + 1) << ": ";
        std::cin >> quantidade;
        std::cout << "\n";
    }

    double calcularTotal() {
        return quantidade * PrecoUnitario;
    }

    void Exibir() {
        std::cout << "Nome: " << nome << "\n";
        std::cout << "Preco Unidade: R$ " << PrecoUnitario << "\n";
        std::cout << "Subtotal: R$ " << calcularTotal() << "\n";
        std::cout << "---------------------------\n";
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int Qnt;
    double ValorTotalLote = 0;

    std::cout << "Quantos produtos diferentes chegaram ao estoque: ";
    if (!(std::cin >> Qnt)) return 1;

    std::cout << "\n";

    Produto* ptrLote = new Produto[Qnt];

    for (int i = 0; i < Qnt; i++) {
        ptrLote[i].SetDados(i);
        ValorTotalLote += ptrLote[i].calcularTotal();
    }

    std::cout << "--- RESUMO DO ESTOQUE ---\n";
    for (int i = 0; i < Qnt; i++) {
        ptrLote[i].Exibir();
    }

    std::cout << "VALOR TOTAL DO LOTE: R$ " << ValorTotalLote << "\n";

    delete[] ptrLote;
    ptrLote = nullptr;

    return 0;
}
