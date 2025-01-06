// Função para calcular a densidade de probabilidade
function psiSquared(x, L, n) {
    const psi = Math.sqrt(2 / L) * Math.sin((n * Math.PI * x) / L);
    return psi * psi;
}

// Função para integração numérica usando a regra do trapézio
function trapezoidalIntegration(func, x1, x2, steps) {
    const h = (x2 - x1) / steps;
    let integral = 0;

    for (let i = 0; i < steps; i++) {
        const x_i = x1 + i * h;
        const x_ip1 = x1 + (i + 1) * h;
        integral += 0.5 * h * (func(x_i) + func(x_ip1));
    }
    return integral;
}

// Função para calcular a probabilidade
function calculateProbability() {
    const x1 = parseFloat(document.getElementById("x1f").value);
    const x2 = parseFloat(document.getElementById("x2f").value);
    const L = parseFloat(document.getElementById("Lf").value);
    const n = parseInt(document.getElementById("nf").value);
    const errorDiv = document.getElementById("errorf");
    const resultDiv = document.getElementById("resultf");

    errorDiv.style.display = "none";
    resultDiv.style.display = "none";

    if (isNaN(x1) || isNaN(x2) || isNaN(L) || isNaN(n) || x1 >= x2 || L <= 0 || n <= 0) {
        errorDiv.textContent = "Por favor, insira valores válidos.";
        errorDiv.style.display = "block";
        return;
    }

    const steps = 10000;
    const probabilityDensity = (x) => psiSquared(x, L, n);
    const probability = trapezoidalIntegration(probabilityDensity, x1, x2, steps);

    resultDiv.textContent = `A probabilidade da partícula estar no intervalo [${x1}, ${x2}] é: ${(probability * 100).toFixed(2)}%`;
    resultDiv.style.display = "block";
}

// Adiciona evento ao botão
document.getElementById("calculate").addEventListener("click", calculateProbability);
