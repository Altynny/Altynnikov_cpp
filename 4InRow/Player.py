import math
from ENV_VARS import COLS, ROWS, DEPTH, EMPTY
from AlphaBeta import algorithm

class Player:
    def __init__ (self, chip: str, AI: bool):
        self.chip = chip
        self.AI = AI
    
    # ввод с клавиатуры 
    def __keyInput(self, board):
        column = 0
        while column < 1 or column > COLS or board[ROWS - 1][column == EMPTY] != ' ':
            column = int(input(f'Введите номер колонки [1, {COLS}]: '))
        return column-1

    # высчитывание хода ИИ
    def __calculateMove(self, board):
        print('Рассчитывает ход...')
        col, _ = algorithm(board, DEPTH, -math.inf, math.inf, True)
        return col

    def makeMove(self, board):
        return self.__calculateMove(board) if self.AI else self.__keyInput(board)