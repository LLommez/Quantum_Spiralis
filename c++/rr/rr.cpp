#include <iostream>
#include <cstdlib>  // Necessário para system()

int main() {
    int escolha;

    std::cout << "Esta é a sessão do rotor rígido." << std::endl;
    std::cout << "O que você deseja calcular?" << std::endl;
    std::cout << " 1 - Comprimento de ligação" << std::endl;
    std::cout << " 2 - Constante rotacional (B)" << std::endl;
    std::cout << " 3 - Momento de Inércia (I)" << std::endl;
    std::cout << " 4 - Número de estados de energia" << std::endl;

    // Recebe a escolha do usuário
    std::cout << "Escolha uma opção: ";
    if (!(std::cin >> escolha)) {
        std::cout << "Entrada inválida! Por favor, insira um número." << std::endl;
        return 1;
    }

    switch (escolha) {
        case 1:
            system("./cdl");
            break;
        case 2:
            system("./cr");
            break;
        case 3: {
            int choice;
            std::cout << "O que você tem?" << std::endl;
            std::cout << " 1 - Comprimento de ligação" << std::endl;
            std::cout << " 2 - Constante rotacional (B)" << std::endl;
            std::cout << "Escolha uma opção: ";
            if (!(std::cin >> choice)) {
                std::cout << "Entrada inválida! Por favor, insira um número." << std::endl;
                return 1;
            }

            switch (choice) {
                case 1:
                    system("./mdi");
                    break;
                case 2:
                    system("./iadcr");
                    break;
                default:
                    std::cout << "Opção inválida para Momento de Inércia!" << std::endl;
                    break;
            }
            break;
        }
        case 4:
            system("./nde");
            break;
        default:
            std::cout << "Opção inválida!" << std::endl;
            break;
    }

    return 0;
}

