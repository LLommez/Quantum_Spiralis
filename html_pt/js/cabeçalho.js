let prevScrollPos = window.pageYOffset; // Armazena a posição de rolagem anterior
const header = document.querySelector("header"); // Seleciona o cabeçalho

window.addEventListener("scroll", () => {
    const currentScrollPos = window.pageYOffset;

    if (prevScrollPos > currentScrollPos) {
        // Rolagem para cima: mostra o cabeçalho
        header.style.top = "0";
    } else {
        // Rolagem para baixo: esconde o cabeçalho completamente
        header.style.top = `-${header.offsetHeight}px`;
    }

    prevScrollPos = currentScrollPos;
});
