function psi(n, x, L) {
    return Math.sqrt(2 / L) * Math.sin((n * Math.PI * x) / L);
}

function densidadeProbabilidade(n, x, L) {
    const onda = psi(n, x, L);
    return onda * onda;
}

function gerarGrafico() {
    const L = parseFloat(document.getElementById("Lx").value);
    const n = parseInt(document.getElementById("nx").value);
    const intervalo = 0.1;
    const errorMsg = document.getElementById("errorMsg");
    const canvas = document.getElementById("grafico");
    const ctx = canvas.getContext("2d");

    errorMsg.innerText = "";

    if (L <= 0 || n <= 0) {
        errorMsg.innerText = "Valores inválidos. Verifique os parâmetros e tente novamente.";
        return;
    }

    const x_vals = [];
    const densidade_vals = [];

    for (let x = 0; x <= L + 1e-9; x += intervalo) {
        x_vals.push(x);
        densidade_vals.push(densidadeProbabilidade(n, x, L));
    }

    if (window.myChart) {
        window.myChart.destroy();
    }

    window.myChart = new Chart(ctx, {
        type: 'line',
        data: {
            labels: x_vals,
            datasets: [{
                label: 'Densidade de Probabilidade (Psi²)',
                data: densidade_vals,
                borderColor: 'rgba(0, 123, 255, 1)',
                borderWidth: 2,
                fill: false
            }]
        },
        options: {
            responsive: true,
            scales: {
                x: {
                    title: {
                        display: true,
                        text: 'x'
                    }
                },
                y: {
                    title: {
                        display: true,
                        text: 'Densidade'
                    }
                }
            }
        }
    });
}