cmake_minimum_required(VERSION 3.14)
project(ExamenII)

set(CMAKE_CXX_STANDARD 17)

add_executable(ejecutable Entretenimiento.cpp Pelicula.cpp Libro.cpp Cancion.cpp 
                          Validaciones.cpp Interaccion.cpp main.cpp)

#Comandos de compilación y ejecución:
    #Primero, ocupo estar en powershell, dentro de la carpeta build
    #2: 
        # cmake .. -G "MinGW Makefiles"
        # Crea un Makefile
    #3: 
        # mingw32-make
        # Lee el make file y lo compila usando g++.
        # Crea el ejecutable del nombre indicado.