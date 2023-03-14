#!/bin/bash

# Compilando o código C
gcc main_1.c -o main.exe -lm

# Define o arquivo de entrada
arquivo="saida_tam.txt"

# Lê o arquivo de entrada e executa o programa para cada linha
i=0
while read linha; do
    nome=$(echo "$linha" | awk '{print $1}')
    valor1=$(echo "$linha" | awk '{print $2}')
    valor2=$(echo "$linha" | awk '{print $3}')
    saida[$i]=$(./main.exe "pub_random/$nome" "$valor1" "$valor2")
    echo "$nome ${saida[$i]}" >> saida2.txt
    i=$((i+1))
done < "$arquivo"