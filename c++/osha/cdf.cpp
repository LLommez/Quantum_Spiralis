#include <iostream>
#include <cstdlib> // Para system()
#include <fstream> // Para ler o arquivo gerado pelo ./mr
#include <cmath>   // Para usar a função sqrt

// Função para calcular a constante de força
double calcularConstanteDeForca(double omega, double mu) {
    return omega * omega * mu;
}

int main() {
    double k, omega, mu;
    char temMassaReduzida;
    int opcaoFrequencia;

    // Perguntar se o usuário já possui a massa reduzida
    std::cout << "Você já tem a massa reduzida (s/n)? ";
    std::cin >> temMassaReduzida;

    if (temMassaReduzida == 's' || temMassaReduzida == 'S') {
        std::cout << "Digite a massa reduzida (em kg): ";
        std::cin >> mu;
    } else {
        // Chamar o programa ./mr
       
        system("./mr");

        // Ler o resultado da massa reduzida de um arquivo de saída gerado pelo ./mr
        std::ifstream arquivoMassa("massa_reduzida.txt");
        if (!arquivoMassa) {
            std::cerr << "Erro: não foi possível abrir o arquivo massa_reduzida.txt.\n";
            return 1;
        }
        arquivoMassa >> mu;
        arquivoMassa.close();

        
    }

     // Perguntar a unidade da frequência
    std::cout << "A frequência está em cm⁻¹ (1) ou rad/s (2)? ";
    std::cin >> opcaoFrequencia;

    // Solicitar a frequência angular, dependendo da unidade escolhida
    if (opcaoFrequencia == 1) {
        double v;
        std::cout << "Digite a frequência em cm⁻¹: ";
        std::cin >> v;
        // Converter de cm⁻¹ para rad/s: w = 2 * pi * c * v (c = 3 x 10^10 cm/s)
        omega = 2 * M_PI * 3e10 * v; // 3e10 cm/s é a velocidade da luz
    } else if (opcaoFrequencia == 2) {
        std::cout << "Digite a frequência angular (ω, em rad/s): ";
        std::cin >> omega;
    } else {
        std::cerr << "Opção inválida para a unidade de frequência.\n";
        return 1;
    }

    // Calcular a constante de força
    k = calcularConstanteDeForca(omega, mu);

    // Exibir o resultado
    std::cout << "A constante de força é: " << k << " N/m\n";

    // Salvar a constante de força em um arquivo .txt
    std::ofstream arquivoConstante("constante_de_forca.txt");
    if (!arquivoConstante) {
        std::cerr << "Erro: não foi possível criar o arquivo constante_de_forca.txt.\n";
        return 1;
    }
    arquivoConstante << k;  // Salva o valor da constante de força
    arquivoConstante.close();


    return 0;
}
