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

int ** addMatrixes(int ** mat1,int ** mat2,int row,int col) {
  int ** result = createMatrix(row,col);

  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col;++j) {
       result[i][j] = mat1[i][j] + mat2[i][j];
    }
  }

  return result;

}

int main()
{
  int row1;
  std::cout << "Enter the row of the first matrix :" << std:: endl;
  std::cin >> row1;

  int col1;
  std::cout << "Enter the column of the first matrix :" << std::endl;
  std::cin >> col1;
  
  int **mat1 = createMatrix(row1,col1);
  inputMatrix(mat1,row1,col1);

  int row2;
  std::cout << "Enter the row of the second matrix :" << std:: endl;

  do {
	  std::cin >> row2;
  } while (row2 != row1);
  
  int col2;
  std::cout << "Enter the column of the second matrix :" << std::endl;
  do {
	  std::cin >> col2;
  } while (col2 != col1);
  
  int **mat2 = createMatrix(row2,col2);
  inputMatrix(mat2,row2,col2);
  
  int ** result = addMatrixes(mat1,mat2,row1,col2);
  std::cout << "Show the result :" << std::endl;
  
  displayMatrix(result,row1,col1);

  deleteMatrix(mat1,row1);
  deleteMatrix(mat2,row2);
  deleteMatrix(result,row1);
}
