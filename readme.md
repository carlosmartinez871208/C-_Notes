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

## Data input and output.

### Data output.
**std::cout** Nos sirve para desplegar informacion en la consola.

Por ejemplo:
    std::cout << "Please enter your name: " << std::endl;

### Data input.
**std::cin** Nos sirve para obtener datos desde la consola.

Por ejemplo:
    std::cin >> name;

### Práctica.
El siguiente código nos permite ingresar valores y desplegarlos en consola.

    #include <cstdlib>
    #include <iostream>

    #ifndef EXIT_SUCCESS
     #define EXIT_SUCCESS 0u
    #endif

    int main (int argc, char** argv)
    {
        int age = 0;
        std::string name = "name";
        /* Statements to get a name and store it into a string variable */
        /*
        ** Use this code to enter full name
        ** std::cout << "Please enter your name: " << std::endl;
        ** std::getline(std::cin,name)
        */
        std::cout << "Please enter your name: " << std::endl;
        std::cin >> name;
        /* Statements to get age and store it  into a int variable */
        std::cout << "Please enter you age: " << std::endl;
        std::cin >> age;
        /* Statement to show name and age */
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
        return EXIT_SUCCESS;
    }

Esto nos deplegaria un resultado similar al siguiente:

    Please enter your name: 
    Carlos
    Please enter you age: 
    Name: Carlos, Age: 37

Pero que pasa si agregamos nombre y apellido en la primera entrada.

    Please enter your name: 
    Carlos Martinez
    Please enter you age: 
    Name: Carlos, Age: 0

Nos manda una edad erronea (0)

Para corregir eso usamos el siguiente código.

    #include <cstdlib>
    #include <iostream>

    #ifndef EXIT_SUCCESS
     #define EXIT_SUCCESS 0u
    #endif

    int main (int argc, char** argv)
    {
        int age = 0;
        std::string name = "name";
        /* Statements to get a name and store it into a string variable */
        std::cout << "Please enter your name: " << std::endl;
        std::getline(std::cin,name);
        /* Statements to get age and store it  into a int variable */
        std::cout << "Please enter you age: " << std::endl;
        std::cin >> age;
        /* Statement to show name and age */
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
        return EXIT_SUCCESS;
    }

De esta manera nos acepta la entrada de datos con espacios.

    Please enter your name: 
    Carlos Martinez
    Please enter you age: 
    Name: Carlos, Age: 37

Dentro del folder **Practice002**, nos movemos a la carpeta **build** y en la consola compilamos el programa con **make all**.

    make all
    Project: Practice002
    Practice002 build date: 2025-02-11 20:21:53

    Practice002: building started...
    Creating directory: bin
    Creating directory: obj
    bin/ succesfully created!!!
    obj/ succesfully created!!!

    Practice002: compiling...
    g++-14 -Wall -Werror -Wpedantic -Wno-unused-variable -Wno-unused-function -o0 -std=c++20  -c src/main.cpp -o  ../../build/obj/main.o
    Compilation done!!!

    Practice002: linking...
    g++-14 obj/main.o -o bin/Practice002
    Link done!!!

    Practice002 project building done!!!

Ahora solo ejecutamos el programa, usando ./your_executable_path

    ./bin/Practice002
    Please enter your name: 
    Carlos Martinez
    Please enter you age: 
    37

## Variables and types.
Dentro de la carpeta Exercises se encuentra el folder **Practice003**, una vez abierto **Practice003** abrimos la carpeta **build**.
La intencion de esta práctica es ver la representacion numerica en distintos sistemas:

> 1. Decimal: 0 - 9.
> 2. Octal: 0 - 7.
> 3. Hexadecimal: 0 - F.
> 4. Binario: 0 y 1.

    Type Name            Bytes.             Other Names                                Range of Values

    int                  4                  signed                                     -2,147,483,648 to 2,147,483,647

    unsigned int         4                  unsigned                                   0 to 4,294,967,295

    __int8               1                  char                                       -128 to 127

    unsigned __int8      1                  unsigned char                              0 to 255

    __int16              2                  short, short int, signed short int         -32,768 to 32,767

    unsigned __int16     2                  unsigned short, unsigned short int         0 to 65,535

    __int32              4                  signed, signed int, int                    -2,147,483,648 to 2,147,483,647

    unsigned __int32     4                  unsigned, unsigned int                     0 to 4,294,967,295

    __int64              8                  long long, signed long long                -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807

    unsigned __int64     8                  unsigned long long                         0 to 18,446,744,073,709,551,615

    bool                 1                  none                                       false or true

    char                 1                  none                                       -128 to 127 by default
                                                                                       0 to 255 when compiled by using /J

    signed char          1                  none                                       -128 to 127

    unsigned char        1                  none                                       0 to 255

    short                2                  short int, signed short int                -32,768 to 32,767

    unsigned short       2                  unsigned short int                         0 to 65,535

    long                 4                  long int, signed long int                  -2,147,483,648 to 2,147,483,647

    unsigned long        4                  unsigned long int                          0 to 4,294,967,295

    long long            8                  none (but equivalent to __int64)           -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807

    unsigned long long   8                  none (but equivalent to unsigned __int64)  0 to 18,446,744,073,709,551,615

    enum                 varies             none 

    float                4                  none                                       3.4E +/- 38 (seven digits)

    double               8                  none                                       1.7E +/- 308 (fifteen digits)

    long double          same as double     none                              Same as double

    wchar_t              2                  __wchar_t                                  0 to 65,535

Código del programa:

    #include <iostream>

    #ifndef EXIT_SUCCESS
     #define EXIT_SUCCESS 0u
    #endif

    int main (int argc, char** argv)
    {
        int Num1 = 15;       /* Representacion decimal */
        int Num2 = 017;      /* Representacion octal */
        int Num3 = 0xF;      /* Representacion hexadecimal */
        int Num4 = 0b1111;   /* Representacion binaria */
    
        /* Se imprimen cada de una de las variables */
        std::cout << " Variable Num1 = " << Num1 << std::endl;
        std::cout << " Variable Num2 = " << Num2 << std::endl;
        std::cout << " Variable Num3 = " << Num3 << std::endl;
        std::cout << " Variable Num4 = " << Num4 << std::endl;
        /* Lo anterior solo imprime 15 en cada linea por que la representacion en memoria es el mismo valor */
        return EXIT_SUCCESS;
    }

Compilamos:

    make all
    Project: Practice003
    Practice003 build date: 2025-02-12 12:33:29

    Practice003: building started...
    Creating directory: bin
    Creating directory: obj
    bin/ succesfully created!!!
    obj/ succesfully created!!!

    Practice003: compiling...
    g++-14 -Wall -Werror -Wpedantic -Wno-unused-variable -Wno-unused-function -o0 -std=c++20  -c src/main.cpp -o  ../../build/obj/main.o
    Compilation done!!!

    Practice003: linking...
    g++-14 obj/main.o -o bin/Practice003
    Link done!!!

    Practice003 project building done!!!

    Building time: 00:00:01

Ejecutamos:

    ./bin/Practice003 
     Variable Num1 = 15
     Variable Num2 = 15
     Variable Num3 = 15
     Variable Num4 = 15

### int
Se trata de un tipo de dato que encarga de almacenar valores enteros.

Tipicamente ocupa 4 bytes o mas en memoria (dependen de la cantidad de bits del procesador).

Si una variable no es inicializada, al momento de carga se le asigna un valor basura.

    int variable;

Sin embargo dependiendo de las banderas de compilacion nos puede desplegar un error al momento de compilacion:

    src/main.cpp: In function 'int main(int, char**)':
    src/main.cpp:15:41: error: 'Num1' is used uninitialized [-Werror=uninitialized]
       15 |     std::cout << " Variable Num1 = " << Num1 << std::endl;
          |                                         ^~~~
    src/main.cpp:9:9: note: 'Num1' was declared here
        9 |     int Num1;
          |         ^~~~
    cc1plus: all warnings being treated as errors

Se inicializa a cero.

    int variable{};

o

    int variable = 0;

Se inicializa a un valor deseado, por ejemplo: 10.

    int variable{10};

o

    itn variable = 10;

Nos lanzaria un **warning** o **error**. El valor 2,9 represneta un valor double.

    int variable{2.9}

Para ver cuanto espacion en bytes ocupa una variable usamos: **sizeof()**.

    std::cout << "Size of int: " << sizeof(int) << std::endl;
    std::cout << "Size of variable: " << sizeof(variable) << std::endl;

#### Práctica.
Nuestro código para int seria el siguiente codigo:

    #include <iostream>

    #ifndef EXIT_SUCCESS
     #define EXIT_SUCCESS 0u
    #endif

    int main (int argc, char** argv)
    {
        int Num1 = 1;
        int Num2 {};
        int Num3 {10};
        int Num4 {15};
        int Sum {Num3 + Num4};
        /* Se imprimen cada de una de las variables */
        std::cout << " Variable Num1 = " << Num1 << std::endl;
        std::cout << " Variable Num2 = " << Num2 << std::endl;
        std::cout << " Variable Num3 = " << Num3 << std::endl;
        std::cout << " Variable Num4 = " << Num4 << std::endl;
        std::cout << " Variable Sum = " << Sum << std::endl;

        /* Se imprimen el tamaño de las variables */
        std::cout << "Size of Num1: " << sizeof(Num1) << std::endl;
        std::cout << "Size of int type: " << sizeof(int) << std::endl;
        return EXIT_SUCCESS;
    }

Para compilar este ejemplo nos vamos a la carpeta Practice4, que se encuentra dentro del folder Exercises.

Dentro de Practice4, ingresamos a la carpeta build, dentro de build corremos el comando **make all**:

    make all
    Project: Practice004
    Practice004 build date: 2025-02-12 13:51:35

    Practice004: building started...
    Creating directory: bin
    Creating directory: obj
    bin/ succesfully created!!!
    obj/ succesfully created!!!

    Practice004: compiling...
    g++-14 -Wall -Werror -Wpedantic -Wno-unused-variable -Wno-unused-function -o0 -std=c++20  -c src/main.cpp -o  ../../build/obj/main.o
    Compilation done!!!

    Practice004: linking...
    g++-14 obj/main.o -o bin/Practice004
    Link done!!!

    Practice004 project building done!!!

    Building time: 00:00:01

Ejecutamos nuestro programa:

    ./bin/Practice004 
     Variable Num1 = 1
     Variable Num2 = 0
     Variable Num3 = 10
     Variable Num4 = 15
     Variable Sum = 25
    Size of Num1: 4
    Size of int type: 4

### int modifiers.
Los modificadores son instrucciones que nos permiten cambiar el comportamiento de una variable.

#### signed.
Significa que el valor de la variable tendra tanto signo positivo como negativo.

    signed int Num1 {10}
    signed int Num2 {-15}

#### unsigned 
Significa que el valor de la variable sera positivo.

    unsigned int Num1 {10}
    unsigned int Num2 {-15} /* Will display an error */

Error desplegado:

    src/main.cpp: In function 'int main(int, char**)':
    src/main.cpp:10:20: error: narrowing conversion of '-15' from 'int' to 'unsigned int' [-Wnarrowing]
       10 |     unsigned Num2 {-15};
          |                    ^~
    make[2]: *** [all] Error 1
    make[1]: *** [start_build] Error 2

#### Práctica.
Nuestro código para los modificadores ser el siguiente:

    #include <iostream>

    #ifndef EXIT_SUCCESS
     #define EXIT_SUCCESS 0u
    #endif

    int main (int argc, char** argv)
    {
        int Num1 = 1;
        unsigned Num2 {3};
        signed Num3 {-10};
        /* Se imprimen cada de una de las variables */
        std::cout << " Variable Num1 = " << Num1 << std::endl;
        std::cout << " Variable Num2 = " << Num2 << std::endl;
        std::cout << " Variable Num3 = " << Num3 << std::endl;

        /* Se imprimen el tamaño de las variables */
        std::cout << "Size of Num1: " << sizeof(Num1) << std::endl;
        std::cout << "Size of int type: " << sizeof(int) << std::endl;
        return EXIT_SUCCESS;
    }

Para compilar este ejemplo nos vamos a la carpeta Practice5, que se encuentra dentro del folder Exercises.

Dentro de Practice5, ingresamos a la carpeta build, dentro de build corremos el comando make all:

    make all
    Project: Practice005
    Practice005 build date: 2025-02-12 14:54:40

    Practice005: building started...
    Creating directory: bin
    Creating directory: obj
    bin/ succesfully created!!!
    obj/ succesfully created!!!

    Practice005: compiling...
    g++-14 -Wall -Werror -Wpedantic -Wno-unused-variable -Wno-unused-function -o0 -std=c++20  -c src/main.cpp -o  ../../build/obj/main.o
    Compilation done!!!

    Practice005: linking...
    g++-14 obj/main.o -o bin/Practice005
    Link done!!!

    Practice005 project building done!!!

    Building time: 00:00:00

Ejecutamos nuestro programa:

    ./bin/Practice005 
     Variable Num1 = 1
     Variable Num2 = 3
     Variable Num3 = -10
     Size of Num1: 4
     Size of int type: 4

### Float
Para números con punto decimal, estos tipos de datos son Floating types.
> 1. float: tiene 4 bytes y 7 digitos despues del punto decimal.
> 2. double: tiene 8 bytes y 15 digitos despues del punto decimal (es el usado por default).
> 3. long double: tiene 12 bytes y es mayor que el double en cuestion de numeros despues del punto decimal.

#### Práctica:

    #include <iomanip>
    #include <iostream>

    #ifndef EXIT_SUCCESS
     #define EXIT_SUCCESS 0u
    #endif

    int main (int argc, char** argv)
    {
        float Num1 {1.12345678901234567890f};
        double Num2 {1.12345678901234567890};
        long double Num3 {1.12345678901234567890L};
        /* Se imprimen cada de una de las variables */
        std::cout << std::setprecision(20);
        std::cout << " Variable Num1 = " << Num1 << std::endl;
        std::cout << " Variable Num2 = " << Num2 << std::endl;
        std::cout << " Variable Num3 = " << Num3 << std::endl;

        /* Se imprimen el tamaño de las variables */
        std::cout << "Size of float: " << sizeof(float) << std::endl;
        std::cout << "Size of double: " << sizeof(double) << std::endl;
        std::cout << "Size of long double: " << sizeof(long double) << std::endl;
        return EXIT_SUCCESS;
    }

Para compilar este ejemplo nos vamos a la carpeta Practice6, que se encuentra dentro del folder Exercises.

Dentro de Practice6, ingresamos a la carpeta build, dentro de build corremos el comando make all:

    Project: Practice006
    Practice006 build date: 2025-02-12 21:31:20

    Practice006: building started...
    Creating directory: bin
    Creating directory: obj
    bin/ succesfully created!!!
    obj/ succesfully created!!!

    Practice006: compiling...
    g++-14 -Wall -Werror -Wpedantic -Wno-unused-variable -Wno-unused-function -o0 -std=c++20  -c src/main.cpp -o  ../../build/obj/main.o
    Compilation done!!!

    Practice006: linking...
    g++-14 obj/main.o -o bin/Practice006
    Link done!!!

    Practice006 project building done!!!

    Building time: 00:00:00

Ejecutamos nuestro programa:

    ./bin/Practice006
     Variable Num1 = 1.1234568357467651367
     Variable Num2 = 1.1234567890123456912
     Variable Num3 = 1.1234567890123456912
    Size of float: 4
    Size of double: 8
    Size of long double: 8

### Booleans 
Son tipos de datos que contienen dos valores true o false.

#### Práctica:

    #include <iostream>

    #ifndef EXIT_SUCCESS
     #define EXIT_SUCCESS 0u
    #endif

    int main (int argc, char** argv)
    {
        bool red_light {true};
        bool green_light {false};

        if (red_light)
        {
            std::cout << "Stop!" << std::endl;
        }
        else
        {
            std::cout << "Go throught!" << std::endl;
        }

        if (green_light)
        {
            std::cout << "Go throught!" << std::endl;
        }
        else
        {
            std::cout << "Stop!" << std::endl;
        }
        return EXIT_SUCCESS;
    }

Para compilar este ejemplo nos vamos a la carpeta Practice7, que se encuentra dentro del folder Exercises.

Dentro de Practice7, ingresamos a la carpeta build, dentro de build corremos el comando make all:

    make all
    Project: Practice007
    Practice007 build date: 2025-02-12 22:08:08

    Practice007: building started...
    Creating directory: bin
    Creating directory: obj
    bin/ succesfully created!!!
    obj/ succesfully created!!!

    Practice007: compiling...
    g++-14 -Wall -Werror -Wpedantic -Wno-unused-variable -Wno-unused-function -o0 -std=c++20  -c src/main.cpp -o  ../../build/obj/main.o
    Compilation done!!!

    Practice007: linking...
    g++-14 obj/main.o -o bin/Practice007
    Link done!!!

    Practice007 project building done!!!

    Building time: 00:00:01

Ejecutamos nuestro programa:

    ./bin/Practice007 
    Stop!
    Stop!

### Caracters and strings.
Este tipo de datos nos permite manejar caracteres y cadenas de caracteres.

**char** es el tipo de dato usado, tiene 1 byte de tamaño esto significa que tiene 256 caracteres distintos para ser usados.

En el caso de las cadenas estas se manejan como arreglos de caracteres.

Práctica:

    #include <iostream>
    #include <string>

    #ifndef EXIT_SUCCESS
     #define EXIT_SUCCESS 0u
    #endif

    int main (int argc, char** argv)
    {
        char value = 65; /* ASCII character for 'A' */
        std::string phrase {"Hello"};
        std::cout << "value: " << value << std::endl;
        std::cout << "value (int): " << static_cast<int>(value) << std::endl;
        std::cout << "value: " << phrase << std::endl;
        return EXIT_SUCCESS;
    }

Para compilar este ejemplo nos vamos a la carpeta Practice8, que se encuentra dentro del folder Exercises.

Dentro de Practice8, ingresamos a la carpeta build, dentro de build corremos el comando make all:

    Project: Practice008
    Practice008 build date: 2025-02-12 22:21:24

    Practice008: building started...
    Creating directory: bin
    Creating directory: obj
    bin/ succesfully created!!!
    obj/ succesfully created!!!

    Practice008: compiling...
    g++-14 -Wall -Werror -Wpedantic -Wno-unused-variable -Wno-unused-function -o0 -std=c++20  -c src/main.cpp -o  ../../build/obj/main.o
    Compilation done!!!

    Practice008: linking...
    g++-14 obj/main.o -o bin/Practice008
    Link done!!!

    Practice008 project building done!!!

    Building time: 00:00:00

Ejecutamos nuestro programa:

    ./bin/Practice008 
    value: A
    value (int): 65
    value: Hello