class edge:
    def __init__(self, node1: str, node2: str, length=1):
        self.__nodes = (node1, node2)
        self.__length = length
        self.__attractivnes =  1/length
        self.__pheromones = 1

    @property
    def nodes(self):
        return self.__nodes
    
    @property
    def length(self):
        return self.__length
    
    @property
    def attractivnes(self):
        return self.__attractivnes
    
    @property
    def pheromones(self):
        return self.__pheromones
    
    @pheromones.setter
    def pheromones(self, value):
        if value > 0:
            self.__pheromones = value
