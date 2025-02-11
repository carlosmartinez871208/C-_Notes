# C++: Notas y ejercicios.
## Introduccion. 
Dentro de los ejercicios viene una carpeta llamada template la cual contiene el estructura del proyecto y el makefile para su compilación.

A continuacion se muestra la estructura del proyecto:

    ├── build
    │   └── Makefile
    └── src
        └── main
            ├── makefile
            └── src
                └── main.cpp

Pasos para la compilación del proyecto:
> 1. Ingresar a la carpeta: **build**.
> 2. Dentro de **build**, para compilar usamos:

    make all

> 3. Para borrar la compilacion usamos:

    make clean

Existen algunas opciones para seleccionar el compilador, por default tenemos gcc de GNU. Para seleccionar **CLANG** usamos el siguiente comando:

    make all COMP=CLANG

Dentro de la carpeta source (**src**) existe una carpeta **main**, dentro de la carpeta main **main** se encuentra un **makefile** que se encarga de compilar los archivos dentro la carpeta **src** (que pertenece a la carpeta main), dentro de la carpeta **src** se encuentra **main.cpp**.

Para ir agregando modulos solo se copia y pega la carpeta **main**, se renombra la copia y se modifican principalmente las variables:

    INCLUDES=\

Esto mismo se modifica en el Makefile principal ubicado en la carpeta **build**.

También una vez terminada la compilacion, dentro de la carpeta **report** podemos encontrar los logs de compilación.

## Comentarios
Los comentarios en **C++** se tienen de dos tipos:
> 1. Comentario de una sola linea: 

    // your comments

> 2. Comentario de multiples lineas:

    /* 
       your
       comment
    */

Por ejemplo: main.cpp

    #include <iostream>

    // Evitar magic numbers.
    #ifndef EXIT_SUCCESS
     #define EXIT_SUCCESS 0u
    #endif

    /*
        Inicio de la funcion principal
    */

    int main(void)
    {
        std::cout << "Hello World!" << std::endl;
        return EXIT_SUCCESS;
    }

