#include <stdio.h>
#include <stdlib.h>

// Matrix2D typedef
typedef struct Matrix2D {
    int rowNum;
    int colNum;
    void** data;
} Matrix2D;

// Matrix constructor 2d
Matrix2D* matrix2DConstructor(int rowNum, int colNum, char type) {
    Matrix2D matrix;
    matrix.rowNum = rowNum;
    matrix.colNum = colNum;
    switch(type) {
        case 'i':
            matrix.data = (void**)calloc(rowNum, sizeof(void*));
            if (matrix.data == NULL) {
                perror("Failed to allocate memory for rows");
            }
            for(int i = 0; i < rowNum; i ++){
                matrix.data[i] = (void*)calloc(colNum, sizeof(int));
                if(matrix.data[i] == NULL) {
                    perror("Failed to allocate memory for columns");
                    for (int j = 0; j < i; j++) {
                        free(matrix.data[j]);
                    }
                    free(matrix.data);
                }
            }
            break;
        case 'd':
            matrix.data = (void**)calloc(rowNum, sizeof(void*));
            if (matrix.data == NULL) {
                perror("Failed to allocate memory for rows");
            }
            for(int i = 0; i < rowNum; i ++){
                matrix.data[i] = (void*)calloc(colNum, sizeof(double));
                if(matrix.data[i] == NULL) {
                    perror("Failed to allocate memory for columns");
                    for (int j = 0; j < i; j++) {
                        free(matrix.data[j]);
                    }
                    free(matrix.data);
                }
            }
        default:
            perror("Incorrect type\n");
            break;
    }
    
}
