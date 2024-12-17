#include <iostream>
#include <fstream>
#include <cstdlib> // Para system()
#include <cmath>   // Para cálculos matemáticos

//momemnto de inercia a partir de massa reduzida e distancia

using namespace std;

int main() {
    double massa_reduzida = 0.0;
    double distancia;
    int unidade_distancia;
    string resposta;

    // Pergunta se a massa reduzida já está disponível
    cout << "Voce ja tem a massa reduzida? (s/n): ";
    cin >> resposta;

    if (resposta == "s") {
        cout << "Informe a massa reduzida (em kg): ";
        cin >> massa_reduzida;
    } else if (resposta == "n") {
        
        system("./mr");

        // Lendo a massa reduzida do arquivo gerado pelo programa ./mr
        ifstream arquivo("massa_reduzida.txt");
        if (arquivo.is_open()) {
            arquivo >> massa_reduzida;
            arquivo.close();
            
        } else {
            cerr << "Erro: Nao foi possivel abrir o arquivo massa_reduzida.txt\n";
            return 1; // Sai do programa com erro
        }
    } else {
        cerr << "Resposta invalida. Digite 's' ou 'n'.\n";
        return 1; // Sai do programa com erro
    }

    // Pergunta pela unidade da distância entre as partículas
    cout << "Sua distancia esta em angstrom (1) ou metros (2)? Escolha: ";
    cin >> unidade_distancia;

    if (unidade_distancia == 1) {
        cout << "Informe a distancia entre as particulas (em angstrom): ";
        cin >> distancia;
        distancia *= 1e-10; // Converte angstrom para metros
    } else if (unidade_distancia == 2) {
        cout << "Informe a distancia entre as particulas (em metros): ";
        cin >> distancia;
    } else {
        cerr << "Opcao invalida. Digite 1 para angstrom ou 2 para metros.\n";
        return 1; // Sai do programa com erro
    }

    // Calcula o momento de inércia
    double momento_inercia = massa_reduzida * distancia * distancia;
    cout << "O momento de inercia e: " << momento_inercia << " kg.m^2\n";

 // Salva o resultado em um arquivo
    std::ofstream arquivo_inercia("momento_inercia.txt");
    if (!arquivo_inercia) {
        std::cerr << "Erro: Não foi possível criar o arquivo momento_inercia.txt.\n";
        return 1;
    }
    arquivo_inercia << momento_inercia << std::endl;
    arquivo_inercia.close();

    return 0;
}
