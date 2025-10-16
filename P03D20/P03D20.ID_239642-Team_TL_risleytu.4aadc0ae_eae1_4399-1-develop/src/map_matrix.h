#ifndef PLOT_GRAPH_H
#define PLOT_GRAPH_H

void plot_graph(char **matrix);

char **allocate_matrix(int *error);
void free_matrix(char ***matrix);

#endif
