#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WeightType char

typedef enum { Directed, Undirected } GraphKind;

typedef enum { Unvisited, Visited } VisitFlag;

typedef struct Edge {
  int start;
  int end;
  // FIXME: use generic data type
  WeightType weight;

  struct Edge* next;
} Edge;

typedef struct {
  int vertex_number;
  int edge_number;
  VisitFlag* marks;
  GraphKind kind;

} BaseGraph;

typedef struct {
  BaseGraph* base_graph;
  int** matrix;
} AdjGraph;

typedef struct {
  BaseGraph* base_graph;

  // a list of linked list
  //
  // |0|-> |5|-> |6|-> NULL
  // |----
  // |1|-> |7|-> |1|-> NULL
  // |----
  // |2|-> |2|-> |8|-> NULL
  // |----
  // |3|-> |4|-> |9|-> NULL
  //
  Edge** vertex_list;
} ListGraph;

static Edge* jun_edge_create(int start, int end, int weight) {
  Edge* edge = malloc(sizeof(Edge));
  edge->start = start;
  edge->end = end;
  edge->weight = weight;
  edge->next = NULL;

  return edge;
}

static void jun_edge_destroy(Edge* edge) {
  free(edge);
  edge = NULL;
}

static BaseGraph* jun_base_graph_create_internal(int vertex_number,
                                                 GraphKind kind) {
  BaseGraph* base_graph = malloc(sizeof(BaseGraph));
  base_graph->vertex_number = vertex_number;
  base_graph->edge_number = 0;
  base_graph->kind = kind;

  base_graph->marks = malloc(sizeof(VisitFlag) * vertex_number);
  for (int i = 0; i < vertex_number; ++i) {
    base_graph->marks[i] = Unvisited;
  }

  return base_graph;
}

static void jun_base_graph_destroy_internal(BaseGraph* base_graph) {
  free(base_graph->marks);
  free(base_graph);
  base_graph = NULL;
}

AdjGraph* jun_adj_graph_create(int vertex_number, GraphKind kind) {
  AdjGraph* graph = malloc(sizeof(AdjGraph));
  graph->base_graph = jun_base_graph_create_internal(vertex_number, kind);

  graph->matrix = malloc(sizeof(int*) * vertex_number);

  for (int i = 0; i < vertex_number; ++i) {
    graph->matrix[i] = malloc(sizeof(int) * vertex_number);
  }

  return graph;
}

void jun_adj_graph_destroy(AdjGraph* graph) {
  for (int i = 0; i < graph->base_graph->vertex_number; i++) {
    free(graph->matrix[i]);
  }
  free(graph->matrix);

  jun_base_graph_destroy_internal(graph->base_graph);
  free(graph);
  graph = NULL;
}

Edge* jun_adj_graph_first_edge(AdjGraph* adj_graph, int one_vertex) {
  for (int i = 0; i < adj_graph->base_graph->vertex_number; ++i) {
    if (adj_graph->matrix[one_vertex][i] != 0) {
      return jun_edge_create(one_vertex, i, adj_graph->matrix[one_vertex][i]);
    }
  }
  return NULL;
}

Edge* jun_adj_graph_next_edge(AdjGraph* adj_graph, Edge* edge) {
  for (int i = edge->end + 1; i < adj_graph->base_graph->vertex_number; ++i) {
    if (adj_graph->matrix[edge->start][i] != 0) {
      return jun_edge_create(edge->start, i, adj_graph->matrix[edge->start][i]);
    }
  }
  return NULL;
}

void jun_adj_graph_set_edge(AdjGraph* adj_graph, int start, int end,
                            int weight) {
  // if there's already an edge, add one.
  if (adj_graph->matrix[start][end] == 0) {
    adj_graph->base_graph->edge_number++;
  }

  adj_graph->matrix[start][end] = weight;

  // note we should add another if the type of graph is undirected.
  if (adj_graph->base_graph->kind == Undirected) {
    adj_graph->matrix[end][start] = weight;
  }
}

void jun_adj_graph_delete_edge(AdjGraph* adj_graph, int start, int end) {
  if (adj_graph->matrix[start][end] != 0) {
    adj_graph->base_graph->edge_number--;
  }
  adj_graph->matrix[start][end] = 0;

  if (adj_graph->base_graph->kind == Undirected) {
    adj_graph->matrix[end][start] = 0;
  }
}

void jun_adj_graph_print(AdjGraph* adj_graph) {
  for (int i = 0; i < adj_graph->base_graph->vertex_number; ++i) {
    for (int j = 0; j < adj_graph->base_graph->vertex_number; ++j) {
      printf("%d", adj_graph->matrix[i][j]);
    }
    printf("\n");
  }
}

ListGraph* jun_list_graph_create(int vertex_number, GraphKind kind) {
  ListGraph* list_graph = malloc(sizeof(ListGraph));
  list_graph->base_graph = jun_base_graph_create_internal(vertex_number, kind);
  list_graph->vertex_list = malloc(sizeof(Edge*) * vertex_number);
  for (int i = 0; i < vertex_number; ++i) {
    list_graph->vertex_list[i] = jun_edge_create(-1, -1, 'x');
  }
  return list_graph;
}

void jun_list_graph_destroy(ListGraph* list_graph) {
  jun_base_graph_destroy_internal(list_graph->base_graph);

  for (int i = 0; i < list_graph->base_graph->vertex_number; ++i) {
    Edge* iter = list_graph->vertex_list[i];
    while (iter != NULL) {
      Edge* tmp = iter->next;
      free(iter);
      iter = tmp;
    }
  }
}

Edge* jun_list_edge_first_edge(ListGraph* list_graph, int one_vertex) {
  return list_graph->vertex_list[one_vertex];
}

Edge* jun_list_graph_next_edge(ListGraph* list_graph, Edge* edge) {
  Edge* iter = list_graph->vertex_list[edge->start];
  while (iter != NULL && iter->end <= edge->end) {
    iter = iter->next;
  }

  if (iter != NULL) {
    return iter;
  }
  return NULL;
}

static void jun_list_graph_set_edge_internal(ListGraph* list_graph, int beg,
                                             int end, WeightType weight) {
  Edge* iter = list_graph->vertex_list[beg];
  if (iter->next == NULL) {
    iter->next = jun_edge_create(beg, end, weight);
  } else {
    Edge* tmp = iter->next;
    Edge* edge = jun_edge_create(beg, end, weight);
    iter->next = edge;
    edge->next = tmp;
  }
}

static void jun_list_graph_delete_edge_internal(ListGraph* list_graph, int beg,
                                                int end) {
  Edge* iter = list_graph->vertex_list[beg];
  Edge* tmp = iter;
  while (iter != NULL && iter->end < end) {
    tmp = iter;
    iter = iter->next;
    if (iter == NULL) {
      return;
    }

    // delete the edge if we found it.
    if (iter->end == end) {
      if (iter == tmp) {
        list_graph->vertex_list[beg] = iter->next;
      } else {
        tmp->next = iter->next;
      }

      free(iter);
    }
  }
}

void jun_list_graph_set_edge(ListGraph* list_graph, int beg, int end, char a,
                             char b) {
  jun_list_graph_set_edge_internal(list_graph, beg, end, a);

  if (list_graph->base_graph->kind == Undirected) {
    jun_list_graph_set_edge_internal(list_graph, end, beg, b);
  }
}

void jun_list_graph_delete_edge(ListGraph* list_graph, int beg, int end) {
  jun_list_graph_delete_edge_internal(list_graph, beg, end);
  if (list_graph->base_graph->kind == Undirected) {
    jun_list_graph_delete_edge_internal(list_graph, end, beg);
  }
}

void jun_list_graph_print(ListGraph* list_graph) {
  for (int i = 0; i < list_graph->base_graph->vertex_number; ++i) {
    Edge* edge = list_graph->vertex_list[i];
    printf("%p\n", edge);

    while (edge != NULL) {
      printf("%c", edge->weight);
      edge = edge->next;
    }
    printf("\n");
  }
}

void jun_list_graph_set_vertex(ListGraph* list_graph, WeightType* vertex_arr) {
  for (int i = 0; i < list_graph->base_graph->vertex_number; ++i) {
    list_graph->vertex_list[i]->weight = vertex_arr[i];
    list_graph->vertex_list[i]->end = i;
  }
}

int main() {
  char nodes[30] = {'\0'};

  int x, y, type;
  GraphKind kind;

  int beg, end;

  scanf("%d %d", &x, &y);
  scanf("%d", &type);

  if (type == 0) {
    kind = Undirected;
  } else {
    kind = Directed;
  }

  for (int i = 0; i < x; ++i) {
    scanf(" %c", &nodes[i]);
  }

  ListGraph* graph = jun_list_graph_create(x, kind);

  jun_list_graph_set_vertex(graph, nodes);

  for (int i = 0; i < y; ++i) {
    scanf("%d %d", &beg, &end);
    jun_list_graph_set_edge(graph, beg, end, nodes[end], nodes[beg]);
  }

  int start = 0;
  int marks[x];
  for (int i = 0; i < x; ++i) {
    marks[i] = 0;
  }

  Edge* iter = graph->vertex_list[0];
  Edge* tmp = NULL;
  if (iter->next) {
    tmp = iter->next;
  }

  for (int i = 1; i < graph->base_graph->vertex_number; ++i) {
    if (iter->next) {
      tmp = iter->next;
    }
    while (iter != NULL) {
      if (marks[iter->end] == 0) {
        printf("%c ", iter->weight);
        marks[iter->end] = 1;
      }
      iter = iter->next;
    }

    iter = graph->vertex_list[tmp->end];
  }

  printf("\n");
}
