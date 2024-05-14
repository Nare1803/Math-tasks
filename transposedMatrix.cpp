#include <iostream>

int** createMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

void deleteMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void inputMatrix(int** matrix, int rows, int cols) {
    std::cout << "Enter the elements of the matrix:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }
}

void displayMatrix (int ** mat,int row,int col ) {
   for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
          std::cout << mat[i][j] << " ";
      }
      std::cout << std::endl;
   }
}

int ** getTranspose(int ** mat1,int row,int col) {
  int ** result = createMatrix(col,row);
   
  for (int i = 0; i< row; ++i) {
      for (int j = 0; j < col; ++j ) {
            result[j][i] = mat1[i][j];
      }
  }
  return result;
}

int main()
{
  int row;
  std::cout << "Enter the row of the matrix :" << std:: endl;
  std::cin >> row;

  int col;
  std::cout << "Enter the column(k1) of the first matrix :" << std::endl;
  std::cin >> col;

  int **mat1 = createMatrix(row,col);
  inputMatrix(mat1,row,col);

  int ** result = getTranspose(mat1,row,col);
  std::cout << "Show the result :" << std::endl;

  displayMatrix(result,col,row);

  deleteMatrix(mat1,row);
  deleteMatrix(result,col);
}


