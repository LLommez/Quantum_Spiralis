#include <iostream>
#include <cmath> // Para funções matemáticas

const double h = 6.62607015e-34; // Constante de Planck em Joules.s

double calcularEnergia(double L, int n, double m) {
    return (std::pow(n, 2) * std::pow(h, 2)) / (8 * m * std::pow(L, 2));
}

int main() {
    double L; // Comprimento da caixa em metros
    int n;    // Número quântico principal
    double m; // Massa da partícula em kg

    // Entrada dos parâmetros
    std::cout << "Use xe-y para notações cientificas se necessário." << std::endl;
    std::cout << "Digite o comprimento da caixa (L) em metros: ";
    std::cin >> L;

    std::cout << "Digite o número quântico principal (n): ";
    std::cin >> n;

    std::cout << "Digite a massa da partícula (m) em kg: ";
    std::cin >> m;

    // Verificar se os valores são válidos
    if (L <= 0 || n <= 0 || m <= 0) {
        std::cerr << "Erro: L, n e m devem ser valores positivos!" << std::endl;
        return 1;
    }

    // Cálculo da energia
    double energia = calcularEnergia(L, n, m);

    // Exibição do resultado
    std::cout << "A energia do estado quantico (En) é: " << energia << " Joules." << std::endl;

    return 0;
}
