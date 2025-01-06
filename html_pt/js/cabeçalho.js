let prevScrollPos = window.pageYOffset; // Armazena a posição de rolagem anterior
const header = document.querySelector("header"); // Seleciona o cabeçalho
const headerHeight = header.offsetHeight; // Altura do cabeçalho

window.addEventListener("scroll", () => {
    const currentScrollPos = window.pageYOffset;

    // Exibe o cabeçalho somente se o usuário estiver no topo da página
    if (currentScrollPos <= headerHeight) {
        header.style.top = "0";  // Mostra o cabeçalho no topo
    } else {
        // Caso contrário, mantém o cabeçalho escondido
        header.style.top = `-${headerHeight}px`;
    }

    prevScrollPos = currentScrollPos;
});

