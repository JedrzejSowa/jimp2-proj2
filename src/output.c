#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "output.h"

void writeMatrixAndEdges(const char *output_file, int *node_indices, int *row_pointers,
                         int *edge_groups, int *edge_pointers, int row_pointers_size) {
    FILE *output = fopen(output_file, "w");
    if (output == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", output_file);
        exit(EXIT_FAILURE);
    }


    int matrix_size = row_pointers_size - 1;


    int **matrix = (int **)malloc(matrix_size * sizeof(int *));
    for (int i = 0; i < matrix_size; i++) {
        matrix[i] = (int *)calloc(matrix_size, sizeof(int));
    }

    for (int i = 0; i < matrix_size; i++) {
        int start_index = row_pointers[i];
        int end_index = row_pointers[i + 1];
        for (int j = start_index; j < end_index; j++) {
            int column = node_indices[j];
            matrix[i][column] = 1; 
        }
    }

    for (int i = 0; i < matrix_size; i++) {
        fprintf(output, "[");
        for (int j = 0; j < matrix_size; j++) {
            fprintf(output, "%d", matrix[i][j]);
            if (j < matrix_size - 1) {
                fprintf(output, " ");
            }
        }
        fprintf(output, "]\n");
    }
    fprintf(output, "\n");

    for (int i = 0; i < row_pointers_size - 1; i++) {
        int source = edge_groups[edge_pointers[i]];
        for (int j = edge_pointers[i] + 1; j < edge_pointers[i + 1]; j++) {
            fprintf(output, "%d - %d\n", source, edge_groups[j]);
        }
    }

    fclose(output);

    for (int i = 0; i < matrix_size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}