#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib> // Para system()
#include <string>  // Para string

//comprimento de ligaçao a partir de massa reduzida, freqquencia e delta l

const double h = 6.626e-34;  // Constante de Planck em J·s
const double pi = 3.141592653589793;

// Função para calcular o comprimento da ligação
double calcularComprimentoLigacao(double massaReduzida, double frequencia) {
    return sqrt(h / (4 * pi * pi * frequencia * massaReduzida));
}

int main() {
    std::string resposta;
    double massaReduzida;

    // Pergunta se a massa reduzida já está disponível
    std::cout << "Voce ja tem a massa reduzida? (s/n): ";
    std::cin >> resposta;

    if (resposta == "s") {
        std::cout << "Informe a massa reduzida (em kg): ";
        std::cin >> massaReduzida;
    } else if (resposta == "n") {
        system("./mr");  // Rodar script para gerar massa reduzida
    }

    // Leitura da massa reduzida do arquivo
    std::ifstream file("massa_reduzida.txt");
    if (!file) {
        std::cerr << "Erro ao abrir o arquivo massa_reduzida.txt." << std::endl;
        return 1;
    }

    file >> massaReduzida;
    file.close();

    if (massaReduzida <= 0) {
        std::cerr << "Massa reduzida inválida." << std::endl;
        return 1;
    }

    // Interação com o usuário
    int lInicial, lFinal;
    double frequencia;

    std::cout << "Digite o valor de l inicial: ";
    std::cin >> lInicial;
    std::cout << "Digite o valor de l final: ";
    std::cin >> lFinal;

    // Validar os valores de l
    if (lInicial < 0 || lFinal < 0 || lFinal <= lInicial) {
        std::cerr << "Valores de l inválidos." << std::endl;
        return 1;
    }

    std::cout << "Escolha a unidade de frequência:" << std::endl;
    std::cout << "(1) MHz" << std::endl;
    std::cout << "(2) Hz" << std::endl;
    int escolha;
    std::cin >> escolha;

    std::cout << "Digite a frequência: ";
    std::cin >> frequencia;

    if (escolha == 1) {
        // Converter MHz para Hz
        frequencia *= 1e6;
    } else if (escolha != 2) {
        std::cerr << "Escolha inválida para unidade de frequência." << std::endl;
        return 1;
    }

    // Calcular a diferença de energia
    double deltaE = (h * frequencia);  // Energia da transição em Joules
    double deltaL = (lFinal * (lFinal + 1)) - (lInicial * (lInicial + 1));

    // Cálculo do momento de inércia
    double momentoInercia = (h * h) / (4 * pi * pi * frequencia * deltaL);

    // Calcular o comprimento da ligação
    double comprimentoLigacao = calcularComprimentoLigacao(massaReduzida, frequencia);

    std::cout << "O comprimento da ligação é: " << comprimentoLigacao * 1e9 << " nm" << std::endl;

    return 0;
}
