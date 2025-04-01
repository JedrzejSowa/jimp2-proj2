#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "read.h"
#include "output.h"

#define MAX_PATH 512
#define MAX_FILENAME 256

void replaceFileExtension(const char *input_file, char *output_file, size_t buffer_size) {
    strncpy(output_file, input_file, buffer_size - 1);
    output_file[buffer_size - 1] = '\0'; 
    char *dot = strrchr(output_file, '.');
    if (dot) {
        snprintf(dot, buffer_size - (dot - output_file), ".txt"); 
    } else {
        strncat(output_file, ".txt", buffer_size - strlen(output_file) - 1); 
    }
}

int main() {
    const char *input_dir = "graphs"; 
    DIR *dir = opendir(input_dir);
    if (!dir) {
        fprintf(stderr, "Error: Could not open directory %s\n", input_dir);
        return EXIT_FAILURE;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strstr(entry->d_name, ".csrrg")) {
            char input_file[MAX_PATH];
            char temp_output_file[MAX_FILENAME];
            char output_file[MAX_PATH];

            snprintf(input_file, sizeof(input_file), "%s/%s", input_dir, entry->d_name);
            replaceFileExtension(entry->d_name, temp_output_file, sizeof(temp_output_file));
            snprintf(output_file, sizeof(output_file), "output/%s", temp_output_file);

            int *node_indices, *row_pointers, *edge_groups, *edge_pointers;
            int node_indices_size, row_pointers_size, edge_groups_size, edge_pointers_size;

            readCSRRG(input_file, &node_indices, &node_indices_size,
                      &row_pointers, &row_pointers_size,
                      &edge_groups, &edge_groups_size,
                      &edge_pointers, &edge_pointers_size);

            writeMatrixAndEdges(output_file, node_indices, row_pointers, edge_groups, edge_pointers, row_pointers_size);

            free(node_indices);
            free(row_pointers);
            free(edge_groups);
            free(edge_pointers);

            printf("Processed file: %s -> %s\n", input_file, output_file);
        }
    }

    closedir(dir);
    return EXIT_SUCCESS;
}