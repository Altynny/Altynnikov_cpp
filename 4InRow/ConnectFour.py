import numpy as np
from Player import Player
from ENV_VARS import COLS, ROWS, PLAYERSAI, EMPTY, PLAYER_CHIPS, WINDOW_LENGTH

class ConnectFour:

    # Конструктор игры
    def __init__(self, cols=COLS, rows=ROWS, playersAI=PLAYERSAI, chips=PLAYER_CHIPS):
        self.cols = cols
        self.rows = rows
        self.board = np.full((ROWS, COLS), EMPTY)
        self.players = (Player(chips[0], playersAI[0]), Player(chips[1], playersAI[1]))
        self.playerTurn = False

    # Строковое представление игры для вывода в консоль
    def __str__(self):
        s = ''
        for col in range(1, COLS+1):
            s += f' {col} '
        s += '\n'
        for row in np.flip(self.board, 0):
            for col in row:
                s += f'[{col}]'
            s += '\n'
        return s

    # Получение самой нижней свободной строки в столбце
    def get_next_open_row(self, col, board=None):
        if not board: board = self.board
        for row in range(ROWS):
            if board[row][col] == EMPTY:
                return row
    
    # Размещение фишки игрока на поле
    def drop_piece(self, row, col, piece, board=None):
        if not board: board = self.board
        board[row][col] = piece

    # Проверка на победу
    def check_winner(self, chip, board=None):
        if not board: board = self.board

        # горизонтали
        for r in range(ROWS):
            for c in range(COLS - 3):
                if all(board[r][c + i] == chip for i in range(WINDOW_LENGTH)):
                    return True

        # вертикали
        for r in range(ROWS - 3):
            for c in range(COLS):
                if all(board[r + i][c] == chip for i in range(WINDOW_LENGTH)):
                    return True

        # диагонали слева направо
        for r in range(ROWS - 3):
            for c in range(COLS - 3):
                if all(board[r + i][c + i] == chip for i in range(WINDOW_LENGTH)):
                    return True

        # диагонали справа налево
        for r in range(3, ROWS):
            for c in range(COLS - 3):
                if all(board[r - i][c + i] == chip for i in range(WINDOW_LENGTH)):
                    return True

        return False

    def start(self):
        while True:
            print(str(self))
            player_chip = self.players[self.playerTurn].chip
            player = f'Игрок {player_chip}'
            print(player)
            col = self.players[self.playerTurn].makeMove(self.board)
            row = self.get_next_open_row(col)
            self.drop_piece(row, col, player_chip)
            if self.check_winner(player_chip):
                print(str(self))
                print(f'Победил {player} !')
                break
            self.playerTurn = not self.playerTurn