# Ceci est un commentaire.
# Retirez le # pour que l'instruction soit prise en compte.
cmake_minimum_required(VERSION 3.16)
project(CPP_TP1)
add_compile_options(-std=c++17 -W -Wall -Wextra -Werror)
# La commande ci-dessous permet de générer un exécutable à partir des fichiers spécifiés.
add_executable(
     hello-world
     helloworld.cpp
)