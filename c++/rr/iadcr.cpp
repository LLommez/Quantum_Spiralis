#include <iostream>
#include <fstream>
#include <cstdlib> // Para system()
#include <cmath>   // Para cálculos matemáticos

//inercia a partir da constante rotacional

using namespace std;

int main() {
    double B;
    const double p = 3.141592653589793;
    const double c = 2.998e8; // Velocidade da luz em m/s
    const double h = 6.626e-34; // Constante de Planck
    string resposta;

    // Pergunta se a massa reduzida já está disponível
    cout << "Voce tem a constante rotacional em cm⁻1 (1) o em m⁻1 (2)?: ";
    cin >> resposta;

    if (resposta == "1") {
        cout << "Informe a constante rotacional: ";
        cin >> B;
        B = B*100;
    } else if (resposta == "2") {
        cout << "Informe a constante rotacional: ";
        cin >> B;
    }
    // Calcula B
    double I = h/(8*p*p*B*c);
    cout << "O momento de inércia I é: " << I << " m⁻1\n";

    return 0;
}