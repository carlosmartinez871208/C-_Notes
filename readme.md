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

## Errores.
En C++ normalmente se tiene dos tipos de errores.

### Errores de compilacion. 
Se dan normalmente por errores en la sintaxis de un programa.

    std::cout << "Hello World!" << std::endl

Nos desplegaria el siguiente error.

    src/main.cpp: In function 'int main()':
    src/main.cpp:14:45: error: expected ';' before 'return'
       14 |     std::cout << "Hello World!" << std::endl
          |                                             ^
          |                                             ;
       15 |     return EXIT_SUCCESS;
          |     ~~~~~~                                   
    make[2]: *** [all] Error 1
    make[1]: *** [start_build] Error 2



### Errores en tiempo de ejecucion (runtime).

    consteval int get_value()
    {
        return (7/0);
    }

Nos desplegaria warnings como las siguientes:

    src/main.cpp:9:14: error: division by zero [-Werror=div-by-zero]
        9 |     return (7/0);
          |             ~^~
    src/main.cpp:10:1: error: division by zero is not a constant expression [-Werror=invalid-constexpr]
       10 | }
          | ^

Al final el programa se detendría.

## Statements.
Una instruccion (statement) en lenguaje C++ es la unidad basica de un programa.

Cada programa en C++ es una colección de instrucciones organizadas de una forma que nos permite realizar una accion especificada.

Cada instruccion tiene una terminacion con **;**.

Por ejemplo:

    std::cout <<"Hello World!" << std::endl;

### Práctica.

Dentro de la carpeta **Exercises** se encuentra el folder **template** que contiene un ejemplo de un programa que imprime en consola ***Hello World***. 

Como práctica de statements podemos ver el ejercicio en el folder ***Practice000** que se encuentra dentro del folder ***Exercises***.

    #include <iostream>

    #ifndef EXIT_SUCCESS
     #define EXIT_SUCCESS 0u
    #endif

    int main (int argc, char** argv)
    {
        int Num1 = 12; /* Se define una variable de tipo int, con nombre Num1, y se le asigna el valor de 12 */
        int Num2 = 9;  /* Se define una variable de tipo int, con nombre Num2, y se le asigna el valor de 9 */
        int Sum = Num1 + Num2; /* Se define una variable de int, con nombre Sum, y se le asigna de Num1 y Num2 */
        std::cout << "Sum of two numbers is: " << Sum <<std::endl; /* Despliega en consola el reusltado de la suma contenido en la variable Sum */
        return EXIT_SUCCESS;
    }

Como se puede ver en la práctica, el objetivo de este programa es hacer la suma de dos números y se tienen las distintas instrucciones para realizarlo.

Dentro del folder **Practice000**, nos movemos a la carpeta **build** y en la consola compilamos el programa con **make all**

    make all
    Project: Practice000
    Practice000 build date: 2025-02-11 12:13:52

    Practice000: building started...
    Creating directory: bin
    Creating directory: obj
    bin/ succesfully created!!!
    obj/ succesfully created!!!

    Practice000: compiling...
    g++-14 -Wall -Werror -Wpedantic -Wno-unused-variable -Wno-unused-function -o0 -std=c++20  -c src/main.cpp -o  ../../build/obj/main.o
    Compilation done!!!

    Practice000: linking...
    g++-14 obj/main.o -o bin/Practice000
    Link done!!!

    Practice000 project building done!!!

    Building time: 00:00:00

Ahora solo ejecutamos el programa, usando ./your_executable_path

    ./bin/Practice
    Sum of two numbers is: 21

## Functions
Una función es un bloque de codigo que realiza alguna operacion o proceso.

Una función opcionalmente puede definir parametros de entrada que permite al proceso que llama a la función pasar argumentos.

Una funcion tambien puede devolver un valor como salida.

Una función debe ser definidad anter de ser usada.

Las funciones son útiles para encapsular operaciones comunes en un solo bloque reutilizable, idealmente con un nombre que describa claramente lo que hace la función.

### Declaración.
Una declaración de una funcion consta del tipo de valor devuelto, el nombre la función y la lista de parámetro (puede estar vacio), junto con palabras claves opcionales que proporcionan más instrucciones al compilador.

Por ejemplo:

    int Sum (int Num1, int Num2);

### Definición.

Una definición de una función consta de la declaración más el cuerpo de la función, que es todo el codigo entre las llaves.

Por ejemplo:

    int Sum (int Num1, int Num2)
    {
        return (Num1 + Num2);
    }

### Práctica.
Como se ha manejado en estas notas las funciones contienen instrucciones en un solo bloque.

Una función debe ser invocada o llamada, desde cualquier parte del programa. Los valores que se pasan son los argumentos, cuyos tipos deben ser compatibles con los tipos de los parámetros en la definición de la función.

Por ejemplo, podemos poner la operacion suma en una funcion que nos devuelva el resultado de la suma de dos numeros.

    int Sum (int Num1, int Num2)
    {
        return (Num1 + Num2);
    }

Tambien podemos tener funciones que no devuelvan algun valor.

Por ejemplo, la siguiente funcion recibe un valor como parametro **result** y lo despliega en la consola.

    void printResult (int result)
    {
        std::cout << "Sum of two numbers is: " << result <<std::endl;
    }

El codigo completo quedaría de la siguiente forma:

    #include <iostream>

    #ifndef EXIT_SUCCESS
     #define EXIT_SUCCESS 0u
    #endif

    /* Sum function declaration */
    int Sum (int Num1, int Num2);

    /* Display result funcion declaration */
    void printResult (int result);

    int main (int argc, char** argv)
    {
        int result = Sum(12,9);
        printResult (result); /* Llamada a la funcion printResult con el argumento result que es compatible con parámetro de entrada de la funcion.*/
        return EXIT_SUCCESS;
    }

    /* Sum function definition */
        int Sum (int Num1, int Num2) /* int: nos indica que devolvera un dato tipo int */
    {
        return (Num1 + Num2);
    }

    /* Display sum function definition */
    void printResult (int result) /* void: nos indica que no va a devolver un valor de retorno */
    {
        std::cout << "Sum of two numbers is: " << result <<std::endl;
    }

Dentro del folder **Practice001**, nos movemos a la carpeta **build** y en la consola compilamos el programa con **make all**.

    make all
    Project: Practice001
    Practice001 build date: 2025-02-11 13:20:42

    Practice001: building started...
    Creating directory: bin
    Creating directory: obj
    bin/ succesfully created!!!
    obj/ succesfully created!!!

    Practice001: compiling...
    g++-14 -Wall -Werror -Wpedantic -Wno-unused-variable -Wno-unused-function -o0 -std=c++20  -c src/main.cpp -o  ../../build/obj/main.o
    Compilation done!!!

    Practice001: linking...
    g++-14 obj/main.o -o bin/Practice001
    Link done!!!

    Practice001 project building done!!!

    Building time: 00:00:00

Ahora solo ejecutamos el programa, usando ./your_executable_path

    ./bin/Practice001
    Sum of two numbers is: 21