from edge import edge
from route import route
from collections import defaultdict

class graph:
    __matrix = defaultdict(lambda: {}) # матрица смежности

    def add_edge(self, edge: edge):
        self.__matrix[edge.nodes[0]][edge.nodes[1]] = edge

    def create_edge(self, node1: str, node2: str, length=1):
        self.add_edge(edge(node1, node2, length))
    
    # поделить 1 на длину каждого ребра 
    def _pheromones_update(self, route: route, ro: float):
        delta_pher = 1 / route.length
        for node1 in self.__matrix:
            for node2 in self.__matrix[node1]:
                self.__matrix[node1][node2].pheromones *= ro
        for n in range(1, len(route.nodes)):
            node1 = route.nodes[n-1]
            node2 = route.nodes[n]
            self.__matrix[node1][node2].pheromones += delta_pher

    @property
    def matrix(self):
        return dict(self.__matrix)