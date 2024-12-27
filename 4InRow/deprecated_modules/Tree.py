from ConnectFour import calculate_valid_moves

class Node:
    def __init__(self, value: int, matrix: list):
        self.value = value
        self.matrix = matrix.copy()
        self.parent = None
        self.children = []

class Tree:
    def __init__(self, maxplayer_sign: str):
        self.nodes=[]
        self.start_node = None
        self.player_sign = maxplayer_sign

    def addNode(self, node: Node):
        self.nodes.append(node)

    def calculate_move(self, node: Node):
        
        if not self.start_node: 
            self.start_node = node
        
        moves = calculate_valid_moves(node.matrix, self.player_sign)

        for move in moves:
            # calculate_points(move)
            pass
        


        # self.start_node = None
        # return move