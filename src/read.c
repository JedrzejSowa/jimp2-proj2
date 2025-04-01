#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"

void parseLine(const char *line, int **array, int *size) {
    char *token;
    char *line_copy = strdup(line);
    char *rest = line_copy;

    *size = 0;
    int capacity = 16; 
    *array = (int *)malloc(capacity * sizeof(int));
    if (*array == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for array.\n");
        exit(EXIT_FAILURE);
    }

    while ((token = strtok_r(rest, ";", &rest))) {
        if (*size >= capacity) {
            capacity *= 2;
            *array = (int *)realloc(*array, capacity * sizeof(int));
            if (*array == NULL) {
                fprintf(stderr, "Error: Memory reallocation failed.\n");
                exit(EXIT_FAILURE);
            }
        }
        (*array)[(*size)++] = atoi(token);
    }

    free(line_copy);
}

void readCSRRG(const char *input_file, int **node_indices, int *node_indices_size,
               int **row_pointers, int *row_pointers_size,
               int **edge_groups, int *edge_groups_size,
               int **edge_pointers, int *edge_pointers_size) {
    FILE *file = fopen(input_file, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", input_file);
        exit(EXIT_FAILURE);
    }

    int max_vertices;
    fscanf(file, "%d\n", &max_vertices); 

    char buffer[8192];
    fgets(buffer, sizeof(buffer), file);
    parseLine(buffer, node_indices, node_indices_size);

    fgets(buffer, sizeof(buffer), file);
    parseLine(buffer, row_pointers, row_pointers_size);

    fgets(buffer, sizeof(buffer), file);
    parseLine(buffer, edge_groups, edge_groups_size);

    fgets(buffer, sizeof(buffer), file);
    parseLine(buffer, edge_pointers, edge_pointers_size);

    fclose(file);
}