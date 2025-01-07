#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <cstdlib>

double psi(int n, double x, double L) {
    return std::sqrt(2.0 / L) * std::sin(n * M_PI * x / L);
}

double densidadeProbabilidade(int n, double x, double L) {
    double onda = psi(n, x, L);
    return onda * onda;
}

int main() {
    double L, x_inicio, x_fim;
    const double intervalo = 0.1; // Intervalo fixo
    int n;

    // Entrada dos parâmetros
    std::cout << "Digite o valor de L (comprimento da caixa): ";
    std::cin >> L;
    std::cout << "Digite o valor de n (número quântico): ";
    std::cin >> n;
    std::cout << "Digite o valor do início do intervalo (x_inicio): ";
    std::cin >> x_inicio;
    std::cout << "Digite o valor do final do intervalo (x_fim): ";
    std::cin >> x_fim;
    

    if (L <= 0 || n <= 0 || x_inicio < 0 || x_fim > L || x_inicio >= x_fim) {
        std::cerr << "Valores inválidos. Verifique os parâmetros e tente novamente." << std::endl;
        return 1;
    }

    std::vector<double> x_vals;
    std::vector<double> densidade_vals;

    // Calcula a densidade de probabilidade
    for (double x = x_inicio; x <= x_fim + 1e-9; x += intervalo) {
        x_vals.push_back(x);
        densidade_vals.push_back(densidadeProbabilidade(n, x, L));
    }

    
        // Cria arquivo temporário de dados
        std::ofstream dados("dados_temp.dat");
        for (size_t i = 0; i < x_vals.size(); ++i) {
            dados << x_vals[i] << " " << densidade_vals[i] << "\n";
        }
        dados.close();

        // Cria script gnuplot
        std::ofstream script("script_temp.gnuplot");
        script << "set terminal pngcairo\n";
        script << "set output 'grafico_temp.png'\n";
        script << "set title 'Densidade de Probabilidade'\n";
        script << "set xlabel 'x'\n";
        script << "set ylabel 'Densidade'\n";
        script << "plot 'dados_temp.dat' with lines title 'Psi^2'\n";
        script.close();

        // Executa o gnuplot
        std::system("gnuplot script_temp.gnuplot");

         // Abre o gráfico usando xdg-open no Ubuntu
        std::system("xdg-open grafico_temp.png");

        
    

    return 0;
}

