#include <iostream>
#include <cstdlib> // Para system()
#include <fstream> // Para ler o arquivo gerado pelo ./mr
#include <cmath>


double calcularFrequenciaAngular(double k, double mu) {
    return std::sqrt(k / mu);
}

int main() {
    double k, mu;
    char temMassaReduzida;

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

    // Solicitar a constante de força
    std::cout << "Digite a constante de força (k, em N/m): ";
    std::cin >> k;

    // Calcular a frequência angular
    double omega = calcularFrequenciaAngular(k, mu);

    // Exibir o resultado
    std::cout << "A frequência angular é: " << omega << " rad/s\n";

    // Salvar a frequência angular em um arquivo .txt
    std::ofstream arquivoFrequencia("frequencia_angular.txt");
    if (!arquivoFrequencia) {
        std::cerr << "Erro: não foi possível criar o arquivo frequencia_angular.txt.\n";
        return 1;
    }
    arquivoFrequencia << omega;  // Salva o valor da frequência angular
    arquivoFrequencia.close();

    return 0;
}
