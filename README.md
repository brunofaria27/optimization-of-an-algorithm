# Optimization of an algorithm
Optimization of an algorithm in the subject of Design and Analysis of Algorithms, seeking better efficiency in an algorithm for calculating numbers in a matrix.

----------------------
## Application

#### 1️ - Algorithmn [`(main.c)`](https://github.com/brunofaria27/optimization-of-an-algorithm/edit/main/main.c) -  Teacher Alexei Machado
This code is a C program that calculates a 2D matrix of float values, given a binary data file, number of rows and number of columns as inputs. The code calculates the matrix by performing various mathematical operations on the elements of the input data file.

#### 📋 Functionalities
1. Reads a binary data file and stores its elements into a 2D matrix.
2. Performs mathematical operations on the elements of the matrix, including sin and cosine calculations, exponentiation, and logarithm.
3. Saves the output matrix into a text file.
4. Measures the execution time of the code and prints it to the console.

#### ➡️ Input
The input consists of three parameters:
- The name of the binary data file.
- The number of rows of the 2D matrix.
- The number of columns of the 2D matrix.

#### ⬅️ Output
The output is a text file containing the resulting 2D matrix of float values. The execution time of the code is also printed to the console.

#### 🖇 Functions
The code contains four functions:

- `ReadElement` - Reads a single element from the binary data file and returns it.
- `DetSinCos` - Calculates the sine and cosine values of an element and stores the results in the pointers passed as parameters.
- `DetOutput` - Calculates the output values for a given element, using the sine and cosine values calculated by the `DetSinCos` function.
- `main` - The main function of the program, which contains the code for reading the binary data file, performing the mathematical operations, saving the output matrix to a text file, and measuring the execution time.

#### 📒 Notes
- The code assumes that the binary data file is not corrupt and contains only valid elements. If the file is corrupt, the program will print a message and exit with error code -1.
- The code uses the `malloc` function to allocate memory dynamically for the 2D matrix. If there is not enough memory available, the program will print a message and exit with error code -1.
- The code uses the `clock` function from the `time.h` library to measure the execution time.
- The code defines the constant `PI` with the value of 3.141592.
- The code saves the output matrix to a text file named "real_values.txt".

#### 2️ - Algorithm [`(generateFile.cpp)`](https://github.com/brunofaria27/optimization-of-an-algorithm/edit/main/generateFile.cpp)
This algorithm is auxiliary and generates a file with `n x m` random values between `0` and `255`. Just pass the number of values `n = lines` and `m = columns` as a parameter in the terminal during the compilation time.

-------------------

## ✅ Run Code
To run the code, just have the [**MinGW**](https://sourceforge.net/projects/mingw/) compiler on your machine and use the following commands:

- Generate the file to be sent to main 
```bash 
$ g++ generateFile.cpp -o generate.exe
$ ./generate.exe <number of rows> <number of columns>
````
- Run the main program and save the result to a file
```bash 
$ gcc main.c -o main.exe
$ ./generate.exe randomValues.txt <number of rows> <number of columns>
````
