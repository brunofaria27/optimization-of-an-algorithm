#!/bin/bash

# Define os valores mínimo e máximo de X e Y
min_x=1000
max_x=10000
min_y=1000
max_y=10000

# Define o número de arquivos a serem gerados
num_files=100

# Loop para gerar os arquivos
for i in $(seq 1 $num_files)
do
  # Gera valores aleatórios para X e Y
  x=$((RANDOM % ($max_x - $min_x + 1) + $min_x))
  y=$((RANDOM % ($max_y - $min_y + 1) + $min_y))
  
  # Verifica se o arquivo com o nome "ra-X-Y" já existe
  while [ -f "ra-$x-$y" ]
  do
    x=$((RANDOM % ($max_x - $min_x + 1) + $min_x))
    y=$((RANDOM % ($max_y - $min_y + 1) + $min_y))
  done
  
  # Cria o arquivo com o nome "ra-X-Y" usando o comando gcc
  gcc generateFile.c -o a.exe -lm
  ./a.exe "ra-$x-$y" $x $y
  echo "./a.exe ra-$x-$y $x $y" >> files.txt
done