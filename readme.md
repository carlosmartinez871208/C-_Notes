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

Para compilar este ejemplo nos vamos a la carpeta Practice004, que se encuentra dentro del folder Exercises.

Dentro de Practice004, ingresamos a la carpeta build, dentro de build corremos el comando **make all**:

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

Para compilar este ejemplo nos vamos a la carpeta Practice005, que se encuentra dentro del folder Exercises.

Dentro de Practice005, ingresamos a la carpeta build, dentro de build corremos el comando make all:

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

Para compilar este ejemplo nos vamos a la carpeta Practice006, que se encuentra dentro del folder Exercises.

Dentro de Practice006, ingresamos a la carpeta build, dentro de build corremos el comando make all:

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

Para compilar este ejemplo nos vamos a la carpeta Practice007, que se encuentra dentro del folder Exercises.

Dentro de Practice007, ingresamos a la carpeta build, dentro de build corremos el comando make all:

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

Para compilar este ejemplo nos vamos a la carpeta Practice008, que se encuentra dentro del folder Exercises.

Dentro de Practice008, ingresamos a la carpeta build, dentro de build corremos el comando make all:

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

## Operaciones.
### Suma.
Nos permite realizar suma de números usando el operador **+**.

### Resta.
Nos permite realizar resta de números usando el operador **-**.

### Multiplicación.
Nos permite realizar multiplicación de números usando el operador **\***.

### División.
Nos permite realizar división de números usando el operador **/**.

Nos permite obtener el residuo de una división usando el operador **%**.

### Práctica:

    #include <iostream>

    #ifndef EXIT_SUCCESS
     #define EXIT_SUCCESS 0u
    #endif

    int Sum (int a, int b);
    int Subtract (int a, int b);
    int Multiplication (int a, int b);
    int* Division (int a, int b);

    int main (int argc, char** argv)
    {
        int Num1;
        int Num2;
        int* Res = nullptr;
        std::cout << "Ingresa primer numero: " << std::endl;
        std::cin >> Num1;
        std::cout << "Ingresa segundo numero: " << std::endl;
        std::cin >> Num2;
        std::cout << "El resultado de la suma es: " << Sum (Num1,Num2) << std::endl;
        std::cout << "El resultado de la resta es: " << Subtract (Num1,Num2) << std::endl;
        std::cout << "El resultado de la multiplicacion es: " << Multiplication (Num1,Num2) << std::endl;
        if(Num2 != 0)
        {
            Res = Division(Num1, Num2);
            std::cout << "El resultado de la division es: " << *Res <<std::endl;
            std::cout << "El residuo de la division es: " << *(Res+1) <<std::endl;
        }
        else
        {
            std::cout << "Denominador debe ser diferente de 0" << std::endl;
        }
        return EXIT_SUCCESS;
    }

    int Sum (int a, int b)
    {
        return (a + b);
    }

    int Subtract (int a, int b)
    {
        return (a - b);
    }

    int Multiplication (int a, int b)
    {
        return (a * b);
    }

    int* Division (int a, int b)
    {
        int* Res = new int;
        *Res = a/b;
        *(Res+1) = a%b;
        return Res;
    }

Para compilar este ejemplo nos vamos a la carpeta Practice009, que se encuentra dentro del folder Exercises.

Dentro de Practice009, ingresamos a la carpeta build, dentro de build corremos el comando make all:

    make all
    Project: Practice009
    Practice009 build date: 2025-02-16 20:23:25

    Practice009: building started...
    Creating directory: bin
    Creating directory: obj
    bin/ succesfully created!!!
    obj/ succesfully created!!!

    Practice009: compiling...
    g++-14 -Wall -Werror -Wpedantic -Wno-unused-variable -Wno-unused-function -o0 -std=c++20  -c src/main.cpp -o  ../../build/obj/main.o
    Compilation done!!!

    Practice009: linking...
    g++-14 obj/main.o -o bin/Practice009
    Link done!!!

    Practice009 project building done!!!

    Building time: 00:00:00

Ejecutamos nuestro programa:

    ./bin/Practice009 
    Ingresa primer numero: 
    7
    Ingresa segundo numero: 
    2
    El resultado de la suma es: 9
    El resultado de la resta es: 5
    El resultado de la multiplicacion es: 14
    El resultado de la division es: 

## Constantes y literales.
Las **literales** son elementos de un programa que representan directamente un valor.

Las **constantes** son elemento de un programa que representan directamente un valor que no puede ser modificado.

**constinit** es una variable que debe ser inicializada por una constante o literal al momento de compilación.

Las variables son etiquetas asignadas a alguna ubicación de almacenamiento abstracta que contendrá algun valor en ella.

Las literales, por otro lado, son solo una notación utilizada para representar un valor fijo en la sintaxis del lenguaje de programación.

Por ejemplo:

    const int answer = 42;      /* constant integer literal */
    double d = sin(108.87);     /* floating point literal passed to sin function */
    bool b = true;              /* boolean literal */
    MyClass* mc = nullptr;      /* pointer literal */

### Constant expressions.
Estas definen una expresión que puede ser evaluado al momento de compilación.

Por ejemplo:

    constexpr int goals {3};
    constexpr double Pi {3.14159};

### static_assert.
Realiza un chequeo de algunas condiciones en tiempo de compilación.
Si el chequeo falla el programa no esta bien estructurado y se puede generar un mensaje de error de diagnostico.

Sintaxis:

    static_assert( bool-constexpr , unevaluated-string );
    static_assert( bool-constexpr );
    static_assert( bool-constexpr , constant-expression );

Por ejemplo:

    static_assert(03301 == 1729); /* since C++17 the message string is optional */

### constinit.
Esta expresión nos indica que la variable debe ser inicializada en tiempo de compilacion.

Solo se puede aplicar a variables con static o thread (fuera del scope de main).

Solo debe ser inicializado con **conts** o **literales**.

**const** y **constinit** se pueden combinar pero, **const** y **constexpr** no pueden ser combinadas en alguna expresión.

**constinit** no implica que la variable sea tipo **const** solo le dice al compilador que inicialice al momento de compilación.

Ejemplos:

    constinit int age = 37;
    const constinit double weight (80.456);

### Práctica.

    #include <iostream>

    #ifndef EXIT_SUCCESS
     #define EXIT_SUCCESS 0u
    #endif

    /* constinit */
    constinit int age = 37;
    const constinit double weight (80.456);

    int main (int argc, char** argv)
    {
        /* Static assert */
        static_assert(03301 == 1729);

        /* Literales */
        const int answer = 42;      /* constant integer literal */
        double d = 108.87;     /* floating point literal passed to sin function */
        bool b = true;              /* boolean literal */

        /* Constant expressions */
        constexpr int goals {3};
        constexpr double Pi {3.14159};

        std::cout << "const int literal: " << answer << std::endl;
        std::cout << "double literal: " << d << std::endl;
        std::cout << "boolean literal: " << b << std::endl;
        std::cout << "int constant expression: " << goals << std::endl;
        std::cout << "double constant expression: " << Pi << std::endl;
        std::cout << "int constinit: " << age << std::endl;
        std::cout << "double const constinit: " << weight << std::endl;

        return EXIT_SUCCESS;
    }

Para compilar este ejemplo nos vamos a la carpeta Practice010, que se encuentra dentro del folder Exercises.

Dentro de Practice010, ingresamos a la carpeta build, dentro de build corremos el comando make all:

    make all
    Project: Practice010
    Practice010 build date: 2025-02-17 13:34:37

    Practice010: building started...
    Creating directory: bin
    Creating directory: obj
    bin/ succesfully created!!!
    obj/ succesfully created!!!

    Practice010: compiling...
    g++-14 -Wall -Werror -Wpedantic -Wno-unused-variable -Wno-unused-function -o0 -std=c++20  -c src/main.cpp -o  ../../build/obj/main.o
    ompilation done!!!

    Practice010: linking...
    g++-14 obj/main.o -o bin/Practice010
    Link done!!!

    Practice010 project building done!!!

    Building time: 00:00:01

Ejecutamos nuestro programa:

    ./bin/Practice010 
    const int literal: 42
    double literal: 108.87
    boolean literal: 1
    int constant expression: 3
    double constant expression: 3.14159
    int constinit: 37
    double const constinit: 80.456

## Data Conversions, overflow & underflow.
### Implicit data conversions.
Normalmente el compilador realiza una conversión implícita, cuando se tienen diferentes tipos en una expresión.

Las conversiones normalmente son hechas del tipo mas chico al mas grande.

Por ejemplo, int es transformado en double antes de que la expresión sea evaluada.

    double price {45.6};
    int units {10};
    double total_price = price * units;

**narrowing convertion** es de la forma siguiente, y es convertida a int antes de ser asignada:

    int x;
    double y {45.44};
    x=y;

 ### Explicit data conversions.
Estas conversiones se hacen a través de indicar explícitamente la conversión al compilador.

Por ejemplo:

    double x {12.5};
    double y {34.6};
    int sum;
    sum = static_cast<int> (x+y);

### Overflow & Underflow
**Overflow** se da cuando el resultado de una operación es mayor al limite superior del tipo de dato, esto significa que por arriba de ese limite se reinicia al limite inferior y continua el conteo.

    unsigned char var0 {55};
    unsigned char var1 {130};
    unsigned char var2 {131};
    var0 = var1 + var2; /* La suma deberia ser 261, pero var0 = 5 */

**Underflow** se da cuando el resultado de una operación es menor al limite inferior del tipo de dato, esto significa que por debajo de ese limite se reinicia al limite superior y continua el conteo.

    unsigned char var0 {55};
    unsigned char var1 {130};
    unsigned char var2 {131};
    var0 = var1 - var2; /* La suma deberia ser -1, pero var0 = 255 */

### Práctica.

    #include <iostream>

    #ifndef EXIT_SUCCESS
     #define EXIT_SUCCESS 0u
    #endif

    int main (int argc, char** argv)
    {
        unsigned char var0 {55};
        unsigned char var1 {130};
        unsigned char var2 {131};
        int x;
        int units {10};
        int sum;
        double y {45.44};
        double price {45.6};
        double m {12.5};
        double n {34.6};

        * Implicit convertion */
        double total_price = price * units;
        std::cout << " Precio total:  " << total_price << std::endl;

        /* Implicit narrowing convertion */
        x = y;
        std::cout << " El valor de x: " << x << std::endl;

        /* Explicit convertion */
        sum = static_cast<int> (m+n);
        std::cout << " El valor de sum: " << sum << std::endl;

        /* Overflow */
        var0 = var1 + var2;
        std::cout << " El valor de var0: " << static_cast<int>(var0) << std::endl;

        /* Underflow */
        var0 = var1 - var2;
        std::cout << " El valor de var0: " << static_cast<int>(var0) << std::endl;

        return EXIT_SUCCESS;
    }

Para compilar este ejemplo nos vamos a la carpeta Practice011, que se encuentra dentro del folder Exercises.

Dentro de Practice011, ingresamos a la carpeta build, dentro de build corremos el comando make all:

    make all         
    Project: Practice011
    Practice011 build date: 2025-02-18 13:39:19

    Practice011: building started...
    Creating directory: bin
    Creating directory: obj
    bin/ succesfully created!!!
    bj/ succesfully created!!!

    Practice011: compiling...
    g++-14 -Wall -Werror -Wpedantic -Wno-unused-variable -Wno-unused-function -o0 -std=c++20  -c src/main.cpp -o  ../../build/obj/main.o
    Compilation done!!!

    Practice011: linking...
    g++-14 obj/main.o -o bin/Practice011
    Link done!!!

    Practice011 project building done!!!

    Building time: 00:00:01

Ejecutamos nuestro programa:

    ./bin/Practice011
     Precio total:  456
     El valor de x: 45
     El valor de sum: 47
     El valor de var0: 5
     El valor de var0: 255

## Bitwise operators.
Son operadores para el manejo de datos a nivel bit.

Para desplegar los valores en un formato especifico usamos lo siguiente.

    unsigned short int data {0b11111110};
    std::cout << "data (dec): " << std::dec << data << std::endl;
    std::cout << "data (hex): " << std::hex << std::showbase << data << std::endl;
    std::cout << "data (bin): " << std::bitset<16>(data) << std::endl;

### Shift operator.
Nos permite recorrer hacia la izquierda o derecha posiciones determinadas.
 
**<<** recorrer a la izquierda.

**>>** recorrer a la derecha.

    unsigned short int value {0xff0u};
    value = static_cast<unsigned short int>(value << 1) ; /* Corrimiento a la izquierda. */
    value = static_cast<unsigned short int>(value >> 1); /* Corrimiento a la derecha. */

### AND
Nos permite hacer una operacion AND entre valores.

    const int COLUMN_WIDTH {20};
    unsigned char value1 {0x03};
    unsigned char value2 {0x05};
    std::cout << std::setw(COLUMN_WIDTH) << "value1 & value2: " << std::setw(COLUMN_WIDTH) << std::bitset<8>(value1 & value2) << std::endl;

### OR
Nos permite hacer una operacion OR entre valores.

    const int COLUMN_WIDTH {20};
    unsigned char value1 {0x03};
    unsigned char value2 {0x05};
    std::cout << std::setw(COLUMN_WIDTH) << "value1 | value2: " << std::setw(COLUMN_WIDTH) << std::bitset<8>(value1 | value2) << std::endl;

### NOT
Nos permite hacer una operacion NOT a un valor.

    const int COLUMN_WIDTH {20};
    unsigned char value1 {0x03};
    unsigned char value2 {0x05};
    std::cout << std::setw(COLUMN_WIDTH) << "~value1: " << std::setw(COLUMN_WIDTH) << std::bitset<8>(~value1) << std::endl;
    std::cout << std::setw(COLUMN_WIDTH) << "~value2: " << std::setw(COLUMN_WIDTH) << std::bitset<8>( ~value2) << std::endl;

### XOR
Nos permite hacer una operacion XOR entre valores.

    const int COLUMN_WIDTH {20};
    unsigned char value1 {0x03};
    unsigned char value2 {0x05};
    std::cout << std::setw(COLUMN_WIDTH) << "value1 ^ value2: " << std::setw(COLUMN_WIDTH) << std::bitset<8>(value1 ^ value2) << std::endl;

### Máscaras.
Las máscaras son usadas para filtrar valores o en este caso que posiciones de bits queremos procesar.

Por ejemplo, si queremos que los bits 3 y 4 sean procesados, aplicariamos la siguiente mascara 0b00011000 y despues un corrimiento de 3 posiciones a la derecha para determinar el valor en decimal.

    unsigned const char MASK {0b00011000};
    unsigned char value {0b11110000};
    value &= MASK;

### Ejemplo:

    #include <iomanip>
    #include <iostream>
    #include <bitset>

    #ifndef EXIT_SUCCESS
     #define EXIT_SUCCESS 0u
    #endif

    int main (int argc, char** argv)
    {
        unsigned short int data {0b11111110};
        std::cout << " Display value of data: " << std::endl;
        std::cout << "data (dec): " << std::dec << data << std::endl;
        std::cout << "data (hex): " << std::hex << std::showbase << data << std::endl;
        std::cout << "data (bin): " << std::bitset<16>(data) << std::endl;
        std::cout << std::endl;

        /* Shift operators */
        unsigned short int value {0xff0u};
        std::cout << " Shift operators: " << std::endl;
        std::cout << "Size of short int: " << sizeof(short int) << std::endl;
        std::cout << "value: " << std::bitset<16>(value) << ", dec: " << value << std::endl;
        value = static_cast<unsigned short int>(value << 1);
        std::cout << "value: " << std::bitset<16>(value) << ", dec: " << value << std::endl;
        value = static_cast<unsigned short int>(value >> 2);
        std::cout << "value: " << std::bitset<16>(value) << ", dec: " << value << std::endl;
        std::cout << std::endl;

        /* AND */
        const int COLUMN_WIDTH {20};
        unsigned char value1 {0x03};
        unsigned char value2 {0x05};
        std::cout << " AND bitwise: " << std::endl;
        std::cout << std::setw(COLUMN_WIDTH) << "value1: " << std::setw(COLUMN_WIDTH) << std::bitset<8>(value1) << std::endl;
        std::cout << std::setw(COLUMN_WIDTH) << "value2: " << std::setw(COLUMN_WIDTH) << std::bitset<8>(value2) << std::endl;
        std::cout << std::setw(COLUMN_WIDTH) << "value1 & value2: " << std::setw(COLUMN_WIDTH) << std::bitset<8>(value1 & value2) << std::endl;
        std::cout << std::endl;
        /* OR */
        std::cout << " OR bitwise: " << std::endl;
        std::cout << std::setw(COLUMN_WIDTH) << "value1 | value2: " << std::setw(COLUMN_WIDTH) << std::bitset<8>(value1 | value2) << std::endl;
        std::cout << std::endl;
        /* NOT */
        std::cout << " NOT bitwise: " << std::endl;
        std::cout << std::setw(COLUMN_WIDTH) << "~value1: " << std::setw(COLUMN_WIDTH) << std::bitset<8>(~value1) << std::endl;
        std::cout << std::setw(COLUMN_WIDTH) << "~value2: " << std::setw(COLUMN_WIDTH) << std::bitset<8>( ~value2) << std::endl;
        std::cout << std::endl;
        /* XOR */
        std::cout << " XOR bitwise: " << std::endl;
        std::cout << std::setw(COLUMN_WIDTH) << "value1 ^ value2: " << std::setw(COLUMN_WIDTH) << std::bitset<8>(value1 ^ value2) << std::endl;
        std::cout << std::endl;

        /* Compound shift operator */
        unsigned char sandbox {0b00110100};
        std::cout << " Compound bitwise: " << std::endl;
        std::cout << std::setw(COLUMN_WIDTH) << "Initial value: " << std::setw(COLUMN_WIDTH) << std::bitset<8>(sandbox) << std::endl;
        sandbox <<= 2; /* Shift left */
        std::cout << std::setw(COLUMN_WIDTH) << "Shift left 2: " << std::setw(COLUMN_WIDTH) << std::bitset<8>(sandbox) << std::endl; 
        sandbox >>= 4; /* Shift right*/
        std::cout << std::setw(COLUMN_WIDTH) << "Shift right 4: " << std::setw(COLUMN_WIDTH) << std::bitset<8>(sandbox) << std::endl; 
        sandbox &= 0b00111100; /* AND compound */
        std::cout << std::setw(COLUMN_WIDTH) << "AND 0b00111100: " << std::setw(COLUMN_WIDTH) << std::bitset<8>(sandbox) << std::endl; 
        sandbox |= 0b00001111; /* OR compound */
        std::cout << std::setw(COLUMN_WIDTH) << "OR 0b00001111: " << std::setw(COLUMN_WIDTH) << std::bitset<8>(sandbox) << std::endl;
        sandbox = ~sandbox; /* NOT */
        td::cout << std::setw(COLUMN_WIDTH) << "NOT: " << std::setw(COLUMN_WIDTH) << std::bitset<8>(sandbox) << std::endl;
        sandbox ^= 0b00111100; /* XOR compound */
        std::cout << std::setw(COLUMN_WIDTH) << "XOR 0b00111100: " << std::setw(COLUMN_WIDTH) << std::bitset<8>(sandbox) << std::endl; 

        /* Máscaras */
        unsigned const char MASK {0b00011000};
        unsigned char value3 {0b11110000};
        std::cout << " Mask: " << std::endl;
        std::cout << std::setw(COLUMN_WIDTH) << "Mask: " << std::setw(COLUMN_WIDTH) << std::bitset<8>(MASK) << std::endl;
        std::cout << std::setw(COLUMN_WIDTH) << "Value: " << std::setw(COLUMN_WIDTH) << std::bitset<8>(value3) << std::endl;
        value3 &= MASK;
        std::cout << std::setw(COLUMN_WIDTH) << "Masked value: " << std::setw(COLUMN_WIDTH) << std::bitset<8>(value3) << std::endl;
        value3 >>= 3;
        std::cout << std::setw(COLUMN_WIDTH) << "Masked value: " << std::setw(COLUMN_WIDTH) << std::bitset<8>(value3) << std::endl;
        std::cout << std::setw(COLUMN_WIDTH) << "Decimal: " << std::setw(COLUMN_WIDTH) << static_cast<int>(value3) << std::endl;
        return EXIT_SUCCESS;
    }

Para compilar este ejemplo nos vamos a la carpeta Practice012, que se encuentra dentro del folder Exercises.

Dentro de Practice012, ingresamos a la carpeta build, dentro de build corremos el comando make all:

    make all
    Project: Practice012
    Practice012 build date: 2025-02-19 14:39:54

    Practice012: building started...
    Creating directory: bin
    Creating directory: obj
    bin/ succesfully created!!!
    obj/ succesfully created!!!

    ractice012: compiling...
    g++-14 -Wall -Werror -Wpedantic -Wno-unused-variable -Wno-unused-function -o0 -std=c++20  -c src/main.cpp -o  ../../build/obj/main.o
    Compilation done!!!

    Practice012: linking...
    g++-14 obj/main.o -o bin/Practice012
    Link done!!!

    Practice012 project building done!!!

    Building time: 00:00:01

Ejecutamos nuestro programa:

    ./bin/Practice012
     Display value of data: 
    data (dec): 254
    data (hex): 0xfe
    data (bin): 0000000011111110

     Shift operators: 
    Size of short int: 0x2
    value: 0000111111110000, dec: 0xff0
    value: 0001111111100000, dec: 0x1fe0
    value: 0000011111111000, dec: 0x7f8

     AND bitwise: 
                value1:             00000011
                value2:             00000101
       value1 & value2:             00000001

     OR bitwise: 
       value1 | value2:             00000111

     NOT bitwise: 
               ~value1:             11111100
               ~value2:             11111010

     XOR bitwise: 
       value1 ^ value2:             00000110

     Compound bitwise: 
         Initial value:             00110100
          Shift left 2:             11010000
         Shift right 4:             00001101
        AND 0b00111100:             00001100
         OR 0b00001111:             00001111
                   NOT:             11110000
        XOR 0b00111100:             11001100
     Mask: 
                  Mask:             00011000
                 Value:             11110000
          Masked value:             00010000
          Masked value:             00000010
               Decimal:                  0x2