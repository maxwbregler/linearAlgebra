void matrixMultiplyNxN(int n, int matrix1[n][n], int matrix2[n][n], int newMatrix[n][n]){
  65;7006;1c  int i;
  int j;
  int pos;
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      newMatrix[i][j] = 0;
      for(pos = 0; pos < n; pos++){
	newMatrix[i][j] += (matrix1[i][pos] * matrix2[pos][j]);
      }
    }
  }
}
void matrixAddNxN(int n, int matrix1[n][n], int matrix2[n][n], int newMatrix[n][n]){
  int i;
  int j;
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      newMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
}
void matrixSubtractNxN(int n, int matrix1[n][n], int matrix2[n][n], int newMatrix[n][n]){
  int i;
  int j;
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      newMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
    }
  }
}
int isMatrixInRREF(int height, int width, int matrix[height][width], int isVerbose){
  int hasPivotOne[height];
  int i, j, k, l;
  for(i = 0; i < height; i++){
    hasPivotOne[i] = 0;
  }
  for(i = 0; i < height; i++){
    for(j = 0; j < width; j++){
      if(matrix[i][j] != 0){
	if(matrix[i][j] == 1){
	  //pivot one
	  hasPivotOne[i] = 1;
	  for(k = 0; k < height; k++){
	    if((k != i) && (matrix[k][j] != 0)){
	      if(isVerbose == 1){
		printf("Pivot column in column %d has nonzero values other than pivot one (row %d)\n", j+1, k+1);
	      }
	      return 0;
	    }
	  }
	  //pivot column with all other 0
	  if(i > 0){
	    for(k = 0; k < i; k++){
	      if(hasPivotOne[k] == 0){
		if(isVerbose == 1){
		  printf("Pivot one in row %d but not in row %d\n", i+1, k+1);
		}
		return 0;
	      }
	      for(l = 0; l < width; l++){
		if((matrix[k][l] == 1) && (l >> j) && (i >> k)){
		  if(isVerbose == 1){
		    printf("Pivot one in row %d is further right than pivot one in row %d\n", k+1, i+1);
		  }
		  return 0;
		}
	      }
	    }
	  }
	  //all rows above have pivot ones
	  break;
	}
	else{
	  printf("First nonzero value of row %d is not 1\n", i+1);
	  return 0;
	}
      }
    }
  }
  return 1;
}
void matirxMultiplyScalar(int height, int width int matrix[height][width], int scalar){
  int i;
  int j;
  for(i = 0; i < height; i++){
    for(j = 0; j < width; j++){
      matrix[i][j] = matrix[i][j] * scalar;
    }
  }
}
int dotProduct(int n, int vector1[n], int vector2[n]){
  int dotProduct = 0;
  int i;
  for(i = 0; i < n; i++){
    dotProduct += (vector1[i] * vector2[i]);
  }
  return dotProduct;
}
