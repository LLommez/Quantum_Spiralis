#include <iostream>
#include <fstream>

double calcularMassaReduzida(double m1, double m2) {
    return (m1 * m2) / (m1 + m2);
}

int main() {
    // Entrada das massas em unidades atômicas (u)
    double massa1, massa2;

    std::cout << "Digite a massa do primeiro átomo (em unidades atômicas u): ";
    std::cin >> massa1;

    std::cout << "Digite a massa do segundo átomo (em unidades atômicas u): ";
    std::cin >> massa2;

    // Conversão para kg (1 u = 1.66054e-27 kg)
    massa1 *= 1.66054e-27;
    massa2 *= 1.66054e-27;

    // Cálculo da massa reduzida
    double massaReduzida = calcularMassaReduzida(massa1, massa2);

    // Salvar o resultado em um arquivo
    std::ofstream arquivoMassa("massa_reduzida.txt");
    if (!arquivoMassa) {
        std::cerr << "Erro: não foi possível criar o arquivo massa_reduzida.txt.\n";
        return 1;
    }
    arquivoMassa << massaReduzida;
    arquivoMassa.close();

    // Exibir o resultado
    std::cout << "A massa reduzida é: " << massaReduzida << " kg \n";

    return 0;
}

