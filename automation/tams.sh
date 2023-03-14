#!/bin/bash

# Define o diretório a ser verificado
diretorio="pub_random/"

# Lista todos os arquivos no diretório e seus tamanhos em MB
du -m "$diretorio"/* | sort -n -k 1 > saida_tam.txt

# Extrai os tamanhos dos arquivos e os lista separados por vírgulas
awk '{print $1}' saida_tam.txt | tr '\n' ', ' >> tams.txt