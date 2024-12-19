def print_board(board):
    count = 0
    count_col = 0
    for row in board:
        print("  ", end="")
        for col in row:
            count_col += 1 
            if count_col != 3:
                print(f"{col}", end=" | ")
            else:
                count_col = 0
                print(f"{col}", end=" ")
        count += 1
        if count != 3:
            print("\n ---|---|--- ")

    print()


def check_boundary_overlapping(board, row, col):
    while True:
        if row < 1 or row > 3 or col < 1 or col > 3:
            print("Invalid row or col")
            row, col = map(int, input("Enter row and col: ").split())
        elif board[row-1][col-1] != "-":
            print("Position already taken")
            row, col = map(int, input("Enter row and col: ").split())
        else:
            break

    return row, col

def check_winner(board):
    for i in range(3):
        if board[i][0] == board[i][1] == board[i][2] != "-":
            return 1
        
    for i in range(3):
        if board[0][i] == board[1][i] == board[2][i] != "-":
            return 1

    if board[0][0] == board[1][1] == board[2][2] != "-":
        return 1
    if board[0][2] == board[1][1] == board[2][0] != "-":
        return 1

    return None

def check_draw(board):
    for row in board:
        for col in row:
            if col == "-":
                return 0
    return 1
    

def main():
    board = [
        ["-", "-", "-"],
        ["-", "-", "-"],
        ["-", "-", "-"]
    ]

    player1 = "X"
    player2 = "O"
    print_board(board)

    
    while True:

        print("Player 1 move")
        row, col = map(int, input("Enter row and col: ").split())
        row, col = check_boundary_overlapping(board, row, col)
        board[row-1][col-1] = player1
        print_board(board)
        if check_winner(board) == 1:
            print("Player 1 wins")
            print_board(board)
            break

        if check_draw(board) == 1:
            print("Draw")
            print_board(board)
            break


        print("Player 2 move")
        row,col = map(int, input("Enter row and col: ").split())
        row, col = check_boundary_overlapping(board, row, col)
        board[row-1][col-1] = player2
        print_board(board)
        if check_winner(board) == 1:
            print("Player 2 wins")
            print_board(board)
            break

        if check_draw(board) == 1:
            print("Draw")
            print_board(board)
            break


if __name__ == "__main__":
    main() 