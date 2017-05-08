cmake_minimum_required(VERSION 3.7)
project(Patricia)

set(CMAKE_C_STANDARD 11)

#set(Patricia_Letras Patricia_Letras/main.c Patricia_Letras/patricia.c Patricia_Letras/patricia.h Patricia_Letras/auxprocedures.c Patricia_Letras/auxprocedures.h)

set(Patricia_Palavras Patricia_Palavras/main.c Patricia_Palavras/patricia.c Patricia_Palavras/patricia.h Patricia_Palavras/auxprocedures.c Patricia_Palavras/auxprocedures.h Patricia_Palavras/listaencadeada.c Patricia_Palavras/listaencadeada.h Patricia_Palavras/dados.h)

#add_executable(Patricia_Letras ${Patricia_Letras})  #Descomente para usar a patricia_letras

add_executable(Patricia_Palavras ${Patricia_Palavras})  #Descomente para usar a patricia_palavras