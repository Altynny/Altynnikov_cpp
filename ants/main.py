from algorithm import ant_colony
from graph import graph
import numpy as np
import matplotlib.pyplot as plt

g1 = graph()
g1.create_edge('a', 'f', 1)
g1.create_edge('a', 'b', 3)
g1.create_edge('b', 'a', 3)
g1.create_edge('b', 'c', 8)
g1.create_edge('b', 'g', 3)
g1.create_edge('c', 'b', 3)
g1.create_edge('c', 'g', 1)
g1.create_edge('c', 'd', 1)
g1.create_edge('d', 'c', 8)
g1.create_edge('d', 'f', 1)
g1.create_edge('f', 'a', 3)
g1.create_edge('f', 'd', 3)
g1.create_edge('g', 'a', 3)
g1.create_edge('g', 'b', 3)
g1.create_edge('g', 'c', 3)
g1.create_edge('g', 'd', 5)
g1.create_edge('g', 'f', 4)


ITERATIONS = 25
ANTS = 1
ALPHA = 0.5
BETA = 0.15
RO = 0.4

ant_alg = ant_colony()
result = ant_alg.algorithm(g1, iterations=ITERATIONS, ants=ANTS, alpha=ALPHA, beta=BETA, ro=RO)
print(result[0])

x = []
y = []
for n, r in enumerate(result[1]): 
    if r:
        x.append(n)
        y.append(r.length)

x = np.array(x)
y = np.array(y)
plt.xlabel('iterations')
plt.ylabel('min len of iteration')
plt.title(f'ants - {ANTS}, alpha - {ALPHA}, beta - {BETA}, ro - {RO}\nmin length found - {result[0].length}')
plt.plot(x, y, '.-', mec='red', mfc='black')
plt.show()