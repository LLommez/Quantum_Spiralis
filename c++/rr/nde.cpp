#include <iostream>
#include <fstream>
#include <cstdlib> // Para system()
#include <cmath>   // Para cálculos matemáticos

// Número de estados de energia a partir do momento de inércia e numero quantico rotacional

using namespace std;

int main() {
    double J = 0.0;
    double I = 0.0;
    const double h = 1.054e-34; // Constante de Planck
    string resposta;

    // Pergunta se a massa reduzida já está disponível
    cout << "Voce ja tem o momento de inércia? (s/n): ";
    cin >> resposta;

    if (resposta == "s") {
        cout << "Informe momento de inércia: ";
        cin >> I;
    } else if (resposta == "n") {
        
        system("./mdi");

        // Lendo a massa reduzida do arquivo gerado pelo programa ./mr
        ifstream arquivo("momento_inercia.txt");
        if (arquivo.is_open()) {
            arquivo >> I;
            arquivo.close();
            
        } else {
            cerr << "Erro: Nao foi possivel abrir o arquivo momento_inercia.txt\n";
            return 1; // Sai do programa com erro
        }
    } else {
        cerr << "Resposta invalida. Digite 's' ou 'n'.\n";
        return 1; // Sai do programa com erro
    }

    // Pergunta pela distância entre as partículas
    cout << "Informe o número quântico rotacional: ";
    cin >> J;

    // Calcula o momento de inércia
    double E = h * h * J * (J + 1)/(2 * I);
    cout << "A energia é: " << E << " Joules\n";

 // Salva o resultado em um arquivo
    std::ofstream arquivo_energia("energia.txt");
    if (!arquivo_energia) {
        std::cerr << "Erro: Não foi possível criar o arquivo energia.txt.\n";
        return 1;
    }
    arquivo_energia << E << std::endl;
    arquivo_energia.close();

    return 0;
}