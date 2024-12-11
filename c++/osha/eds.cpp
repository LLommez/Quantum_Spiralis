#include <iostream>
#include <cstdlib> // Para system()
#include <fstream> // Para ler o arquivo gerado pelo ./fa
#include <cmath>   // Para usar a função sqrt

// Constantes
const double h_bar = 1.0545718e-34;  // Constante de Planck reduzida em J.s
const double c = 3.0e10;             // Velocidade da luz em cm/s

// Função para calcular a energia do sistema
double calcularEnergia(double n, double omega) {
    return (n + 0.5) * h_bar * omega;  // Fórmula da energia
}

int main() {
    double n, omega;
    char temFrequencia;
    int tipoFrequencia;

    // Perguntar se o usuário já possui a frequência angular
    std::cout << "Você já tem a frequência angular (s/n)? ";
    std::cin >> temFrequencia;

    if (temFrequencia == 's' || temFrequencia == 'S') {
        std::cout << "Digite a frequência angular (ω):\n";
        std::cout << "Se está em cm⁻¹, digite 1. Se está em rad/s, digite 2: ";
        std::cin >> tipoFrequencia;

        if (tipoFrequencia == 1) {
            // Frequência fornecida em cm⁻¹, convertendo para rad/s
            double v;
            std::cout << "Digite a frequência em cm⁻¹: ";
            std::cin >> v;
            omega = 2 * M_PI * c * v;  // Convertendo para rad/s
        } else if (tipoFrequencia == 2) {
            // Frequência fornecida diretamente em rad/s
            std::cout << "Digite a frequência angular em rad/s: ";
            std::cin >> omega;
        } else {
            std::cerr << "Opção inválida!\n";
            return 1;
        }
    } else {
        // Chamar o programa ./fa para calcular a frequência angular
        
        system("./fa");

        // Ler o resultado da frequência angular de um arquivo de saída gerado pelo ./fa
        std::ifstream arquivoFrequencia("frequencia_angular.txt");
        if (!arquivoFrequencia) {
            std::cerr << "Erro: não foi possível abrir o arquivo frequencia_angular.txt.\n";
            return 1;
        }
        arquivoFrequencia >> omega;
        arquivoFrequencia.close();
    }

    // Solicitar o número quântico
    std::cout << "Digite o número quântico (n): ";
    std::cin >> n;

    // Calcular a energia do sistema
    double energia = calcularEnergia(n, omega);

    // Exibir o resultado
    std::cout << "A energia do sistema para n = " << n << " é: " << energia << " J\n";

    // Salvar a energia em um arquivo .txt
    std::ofstream arquivoEnergia("energia.txt");
    if (!arquivoEnergia) {
        std::cerr << "Erro: não foi possível criar o arquivo energia.txt.\n";
        return 1;
    }
    arquivoEnergia << energia;  // Salva o valor da energia
    arquivoEnergia.close();

    return 0;
}
