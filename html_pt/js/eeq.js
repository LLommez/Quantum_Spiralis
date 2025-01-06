const h = 6.62607015e-34; // Constante de Planck (J.s)

        function calcularEnergia() {
            // Obter valores dos inputs
            const L = parseFloat(document.getElementById('L').value);
            const n = parseInt(document.getElementById('n').value);
            const m = parseFloat(document.getElementById('m').value);

            // Referências para exibição de resultado e erro
            const resultDiv = document.getElementById('result');
            const errorDiv = document.getElementById('error');
            const energiaSpan = document.getElementById('energia');

            // Limpar mensagens anteriores
            resultDiv.style.display = "none";
            errorDiv.style.display = "none";

            // Verificar se os valores são válidos
            if (isNaN(L) || isNaN(n) || isNaN(m) || L <= 0 || n <= 0 || m <= 0) {
                errorDiv.textContent = "Erro: Todos os valores devem ser positivos e válidos!";
                errorDiv.style.display = "block";
                return;
            }

            // Calcular a energia
            const energia = (Math.pow(n, 2) * Math.pow(h, 2)) / (8 * m * Math.pow(L, 2));

            // Exibir o resultado
            energiaSpan.textContent = energia.toExponential(6); // Formatar resultado em notação científica
            resultDiv.style.display = "block";}