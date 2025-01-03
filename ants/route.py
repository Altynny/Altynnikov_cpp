class route:
    def __init__(self, nodes: list, length: int, chance: float):
        self.__nodes = nodes
        self.__length = length
        self.chance = chance

    def __str__(self):
        return f'length - {self.__length}\n{self.__nodes}'

    @property
    def nodes(self):
        return self.__nodes    
    
    @property
    def length(self):
        return self.__length   