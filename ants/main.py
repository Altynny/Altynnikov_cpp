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


ITERATIONS = 10**4
ANTS = 1
ALPHA = 1
BETA = 0.6
RO = 0

ant_alg = ant_colony()
result = ant_alg.algorithm(g1, iterations=ITERATIONS, ants=ANTS, alpha=ALPHA, beta=BETA, ro=RO)
print(result[0])

found_routes = [[], []]
chances = [[],[]]
sh_routes = result[1]

# жизненный цикл каждого муравья
ant_iters = np.array(result[2])
fig, axs = plt.subplots(ant_iters.shape[0]+2,sharex=True)
for n in range(ant_iters.shape[0]):
    axs[n].plot(ant_iters[n])
    axs[n].set_xscale('log')

# средние показатели кратчайших маршрутов за каждые 10 итераций
for n in range(10, len(sh_routes), 10): 
    found_routes[0].append(n-5)
    avg_10 = [route.length for route in sh_routes[n-10:n] if route]
    found_routes[1].append(np.mean(avg_10))

# шанс пройти по оптимальному маршруту каждую итерацию
for n, r in enumerate(sh_routes):
    if r and r.length == result[0].length:
        chances[0].append(n)
        chances[1].append(r.chance)

axs[-1].plot(found_routes[0], found_routes[1], '.-', mec='red', mfc='black')
axs[-1].set_xscale('log')
axs[-2].plot(chances[0], chances[1], '.-', mec='green', mfc='black')
axs[-2].set_xscale('log')
plt.show()