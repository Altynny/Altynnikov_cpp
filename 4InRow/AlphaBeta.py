import math
from ENV_VARS import COLS, ROWS, EMPTY, WINDOW_LENGTH, PLAYER_CHIP, AI_CHIP

# Проверка на победу
def check_winner(board, chip):

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

# Список доступных ходов
def get_valid_locations(board):
    return [c for c in range(COLS) if board[ROWS - 1][c] == EMPTY]

# Проверка на оконченность
def is_terminal_node(board):
    return check_winner(board, PLAYER_CHIP) or check_winner(board, AI_CHIP) or len(get_valid_locations(board)) == 0

# Получение самой нижней свободной строки в столбце
def get_next_open_row(col, board):
    for row in range(ROWS):
        if board[row][col] == EMPTY:
            return row

# Дать оценки за группы фишек
def evaluate_window(window, piece):
    score = 0
    opp_piece = PLAYER_CHIP if piece == AI_CHIP else AI_CHIP

    if window.count(piece) == 4:
        score += 100
    elif window.count(piece) == 3 and window.count(EMPTY) == 1:
        score += 5
    elif window.count(piece) == 2 and window.count(EMPTY) == 2:
        score += 2
    if window.count(opp_piece) == 3 and window.count(EMPTY) == 1:
        score -= 4

    return score

# Оценочная функция
def score_position(board, piece):
    score = 0

    # Награда за занятие центра
    center_array = [board[r][COLS // 2] for r in range(ROWS)]
    score += center_array.count(piece) * 3

    # Проверка горизонтальных групп
    for r in range(ROWS):
        row_array = [board[r][c] for c in range(COLS)]
        for c in range(COLS - 3):
            window = row_array[c:c + WINDOW_LENGTH]
            score += evaluate_window(window, piece)

    # Проверка вертикальных групп
    for c in range(COLS):
        col_array = [board[r][c] for r in range(ROWS)]
        for r in range(ROWS - 3):
            window = col_array[r:r + WINDOW_LENGTH]
            score += evaluate_window(window, piece)

    # Проверки диагональных групп
    for r in range(ROWS - 3):
        for c in range(COLS - 3):
            window = [board[r + i][c + i] for i in range(WINDOW_LENGTH)]
            score += evaluate_window(window, piece)

    for r in range(3, ROWS):
        for c in range(COLS - 3):
            window = [board[r - i][c + i] for i in range(WINDOW_LENGTH)]
            score += evaluate_window(window, piece)

    return score

# Размещение фишки игрока на поле
def drop_piece(row, col, piece, board=None):
    board[row][col] = piece

# Минимакс алгоритм с альфа-бета отсечениями
def algorithm(board, depth: int, alpha, beta, maximizingPlayer: bool):
    valid_locations = get_valid_locations(board)
    is_terminal = is_terminal_node(board)
    if depth == 0 or is_terminal:
        if is_terminal:
            if check_winner(board, AI_CHIP):
                return (None, 100000000000000)
            elif check_winner(board, PLAYER_CHIP):
                return (None, -100000000000000)
            else:  # Игра окончена, больше фишек не поставить
                return (None, 0)
        else:  # Достигнута максимальная глубина
            return (None, score_position(board, AI_CHIP))

    if maximizingPlayer:
        value = -math.inf
        best_col = valid_locations[0]
        for col in valid_locations:
            row = get_next_open_row(col, board)
            temp_board = board.copy()
            drop_piece(row, col, AI_CHIP, temp_board)
            new_score = algorithm(temp_board, depth - 1, alpha, beta, False)[1]
            if new_score > value:
                value = new_score
                best_col = col
            alpha = max(alpha, value)
            if alpha >= beta:
                break
        return best_col, value

    else:  # Minimizing player
        value = math.inf
        best_col = valid_locations[0]
        for col in valid_locations:
            row = get_next_open_row(col, board)
            temp_board = board.copy()
            drop_piece(row, col, PLAYER_CHIP, temp_board)
            new_score = algorithm(temp_board, depth - 1, alpha, beta, True)[1]
            if new_score < value:
                value = new_score
                best_col = col
            beta = min(beta, value)
            if alpha >= beta:
                break
        return best_col, value