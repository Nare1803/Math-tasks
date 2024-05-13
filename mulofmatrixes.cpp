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

int ** mulMatrixes(int ** mat1,int ** mat2,int m,int k,int n) {
  int ** result = createMatrix(m,n);
   
  for (int i = 0; i< m; ++i) {
      for (int j = 0; j < n; ++j ) {
         result[i][j] = 0;
	 for (int l = 0; l < k; ++l) {
	    result[i][j] += mat1[i][l] * mat2[l][j];
	 }
      }
  }
  return result;

}

int main()
{
  int m;
  std::cout << "Enter the row(m) of the first matrix :" << std:: endl;
  std::cin >> m;
  
  int k1;
  std::cout << "Enter the column(k1) of the first matrix :" << std::endl;
  std::cin >> k1;

  int **mat1 = createMatrix(m,k1);
  inputMatrix(mat1,m,k1);
  
  int k2;
  std::cout << "Enter the row(k2) of the second matrix :" << std:: endl;
  
  do {
	  std::cin >> k2;
  } while (k2 != k1);
  
  int n;
  std::cout << "Enter the column(n) of the second matrix :" << std::endl;
  std::cin >> n;

  int **mat2 = createMatrix(k2,n);
  inputMatrix(mat2,k2,n);
  
  int ** result = mulMatrixes(mat1,mat2,m,k1,n);
  std::cout << "Show the result :" << std::endl;
  
  displayMatrix(result,m,k1);
 
  deleteMatrix(mat1,m);
  deleteMatrix(mat2,k1);
  deleteMatrix(result,m);
}


