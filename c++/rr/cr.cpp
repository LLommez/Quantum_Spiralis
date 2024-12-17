#include <iostream>
#include <fstream>
#include <cstdlib> // Para system()
#include <cmath>   // Para cálculos matemáticos

//constante rotacional com momento de inercia

using namespace std;

int main() {
    double I;
    const double p = 3.141592653589793;
    const double c = 2.998e8; // Velocidade da luz em m/s
    const double h = 6.626e-34; // Constante de Planck
    string resposta;

    // Pergunta se a massa reduzida já está disponível
    cout << "Voce ja tem o momento de inércia? (s/n): ";
    cin >> resposta;

    if (resposta == "s") {
        cout << "Informe o momento de inércia: ";
        cin >> I;
    } else if (resposta == "n") {
        
        system("./mdi");

        // Lendo a massa reduzida do arquivo gerado pelo programa ./mr
        ifstream arquivo("momento_inercia.txt");
        if (arquivo.is_open()) {
            arquivo >> I;
            arquivo.close();
            
        } else {
            cerr << "Erro: Nao foi possivel abrir o arquivo massa_reduzida.txt\n";
            return 1; // Sai do programa com erro
        }
    } else {
        cerr << "Resposta invalida. Digite 's' ou 'n'.\n";
        return 1; // Sai do programa com erro
    }

    
    // Calcula B
    double B = h/(8*p*p*I*c);
    cout << "A constante rotacional B é: " << B << " m⁻1\n";

    return 0;
}