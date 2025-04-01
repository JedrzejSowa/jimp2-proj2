#ifndef READ_H
#define READ_H

void readCSRRG(const char *input_file, int **node_indices, int *node_indices_size,
               int **row_pointers, int *row_pointers_size,
               int **edge_groups, int *edge_groups_size,
               int **edge_pointers, int *edge_pointers_size);

#endif