#include <iostream>
#include <cstdlib>  // Necessário para system()

int main() {
    int escolha;
    
    std::cout << "Esta é a sessão de oscilador harmônico." << std::endl;
    std::cout << "O que você deseja calcular?" << std::endl;
    std::cout << " 1 - Massa reduzida" << std::endl;
    std::cout << " 2 - Frequência angular" << std::endl;
    std::cout << " 3 - Constante de força" << std::endl;
    std::cout << " 4 - Energia do sistema" << std::endl;

    // Recebe a escolha do usuário
    std::cin >> escolha;

    // Executa o programa correspondente dependendo da escolha
    switch (escolha) {
        case 1:
            system("./mr");
            break;
        case 2:
            system("./fa");
            break;
        case 3:
            system("./cdf");
            break;
        case 4:
            system("./eds");
            break;
        default:
            std::cout << "Opção inválida!" << std::endl;
            break;
    }

    return 0;
}
