#include <iostream>
#include <cstdlib>  // Necessário para system()

int main() {
    int escolha;
    
    std::cout << "Bem vindo ao Sphaera Quantum." << std::endl;
    std::cout << "O que você deseja estudar?" << std::endl;
    std::cout << " 1 - Particula na caixa 1D" << std::endl;
    std::cout << " 2 - Oscilador Harmônico" << std::endl;
    std::cout << " 3 - Rotor rígido" << std::endl;
    

    // Recebe a escolha do usuário
    std::cin >> escolha;

    // Executa o programa correspondente dependendo da escolha
    switch (escolha) {
        case 1:
            system("cd ./pnc1d && ./pnc1d");
            break;
        case 2:
            system("cd ./osha && ./osha");
            break;
        case 3:
            system("cd ./rr && ./rr");
            break;
        
        default:
            std::cout << "Opção inválida!" << std::endl;
            break;
    }

    return 0;
}
