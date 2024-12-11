#include <iostream>
#include <cmath>
#include <functional>

// Função para calcular a densidade de probabilidade
double psiSquared(double x, double L, int n) {
    double psi = std::sqrt(2.0 / L) * std::sin(n * M_PI * x / L);
    return psi * psi;
}

// Função para integração numérica usando a regra do trapézio
double trapezoidalIntegration(std::function<double(double)> func, double x1, double x2, int steps) {
    double h = (x2 - x1) / steps;
    double integral = 0.0;

    for (int i = 0; i < steps; ++i) {
        double x_i = x1 + i * h;
        double x_ip1 = x1 + (i + 1) * h;
        integral += 0.5 * h * (func(x_i) + func(x_ip1));
    }
    return integral;
}

int main() {
    double x1, x2, L;
    int n;

    // Entrada dos parâmetros
    std::cout << "Digite o limite inferior (x1): ";
    std::cin >> x1;
    std::cout << "Digite o limite superior (x2): ";
    std::cin >> x2;
    std::cout << "Digite o comprimento da caixa (L): ";
    std::cin >> L;
    std::cout << "Digite o número quântico (n): ";
    std::cin >> n;

    // Número de passos para a integração numérica
    int steps = 10000;

    // Função a ser integrada
    auto probabilityDensity = [L, n](double x) { return psiSquared(x, L, n); };

    // Cálculo da probabilidade
    double probability = trapezoidalIntegration(probabilityDensity, x1, x2, steps);

    // Exibir o resultado
    std::cout << "A probabilidade da partícula estar no intervalo [" 
          << x1 << ", " << x2 << "] é: " << probability * 100 << "%" << std::endl;


    return 0;
}
