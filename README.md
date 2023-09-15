# TAD Matrix
## Description
This project implements an Abstract Data Type (ADT) for a matrix in C. It provides basic operations such as matrix creation, setting and getting elements, matrix multiplication, and calculating the transpose of a matrix.

## File Structure
- `matriz.c`: Contains the implementation of the functions that manipulate the matrix.
- `matriz.h`: Contains the declaration of the functions and the `Matriz` structure.
- `Apl.c`: Is the application file that uses the Matrix ADT.
- `output/`: Directory where the `Apl` executable is stored and run.

## Requirements
- C/C++ compiler

## Installation
Clone this repository or download the source files.
```bash
git clone https://github.com/gabrielbelodev/TADmatriz.git
```
### Compilation
To compile the code, navigate to the directory and run:
```bash
gcc -o output/Apl matriz.c Apl.c
```
This will generate the `Apl` executable in the output folder.

## Usage
After compiling, you can run the program by navigating to the output folder and using:
```bash
./Apl
```

## Implemented Features
1 - `Matriz *createMatrix(int rows, int columns)`: Creates a new matrix with the given number of rows and columns, initializing all elements to 0.

2 - `void destroyMatrix(Matriz *m)`: Frees the memory allocated for the matrix.

3 - `void setElement(Matriz *m, int i, int j, int value)`: Sets the value of an element in the matrix at positions i and j.

4 - `int getElement(Matriz *m, int i, int j)`: Retrieves the value of an element in the matrix at positions i and j.

5 - `Matriz *multiplyMatrices(Matriz *a, Matriz *b)`: Multiplies two matrices, returning a new matrix as a result.

6 - `Matriz *transpose(Matriz *m)`: Calculates the transpose of a matrix and returns a new matrix as a result.

## Contribution
If you would like to contribute, feel free to fork the project, create a new branch, make your changes, and open a Pull Request.

## License
This project is under the MIT License. See the LICENSE.md file for more details.
