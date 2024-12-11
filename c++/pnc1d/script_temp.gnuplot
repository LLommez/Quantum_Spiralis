set terminal pngcairo
set output 'grafico_temp.png'
set title 'Densidade de Probabilidade'
set xlabel 'x'
set ylabel 'Densidade'
plot 'dados_temp.dat' with lines title 'Psi^2'
