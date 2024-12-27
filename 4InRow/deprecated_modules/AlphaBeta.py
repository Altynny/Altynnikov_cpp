from Tree import Tree, Node

class AlphaBeta:
    def __init__(self):
        self.tree = Tree()
        self.start_node = None

    def calculateMove(self, node: Node, ):
        self.start_node = node