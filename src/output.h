#ifndef OUTPUT_H
#define OUTPUT_H

void writeMatrixAndEdges(const char *output_file, int *node_indices, int *row_pointers,
                         int *edge_groups, int *edge_pointers, int row_pointers_size);

#endif