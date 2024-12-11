#include <iostream>
#include <cstdlib>  // Necessário para system()

int main() {
    int escolha;
    
    std::cout << "Esta é a sessão da particula na caixa 1D." << std::endl;
    std::cout << "O que você deseja calcular?" << std::endl;
    std::cout << " 1 - Estado de energia Quantico" << std::endl;
    std::cout << " 2 - Partícula em uma determinada posição X" << std::endl;
    std::cout << " 3 - Densidade de probabilidade" << std::endl;
    

    // Recebe a escolha do usuário
    std::cin >> escolha;

    // Executa o programa correspondente dependendo da escolha
    switch (escolha) {
        case 1:
            system("./eeq");
            break;
        case 2:
            system("./pepx");
            break;
        case 3:
            system("./ddp");
            break;
        
        default:
            std::cout << "Opção inválida!" << std::endl;
            break;
    }

    return 0;
}
