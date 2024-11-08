//  Code of the Tic Tac Toe  Game


#include <tuple>
#include <iostream>

using namespace std;

int print_board(char board[3][3])
{
    for (int i = 0; i < 3; i = i + 1)
    {
        for (int j = 0; j < 3; j = j + 1)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

int check_winner(char board[3][3]) {
    // check rows
    for (int i = 0; i<3; i++){
        if (board[i][0] == '-' || board[i][1] == '-' || board[i][2] == '-'){
            continue;
        }
        else if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return 1;
        }
    }

    // column check
    for (int i = 0; i<3; i++){
        if (board[0][i] == '-' || board[1][i] == '-' || board[2][i] == '-'){
            continue;
        }
        else if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return 1;
        }
    }

    //diagonal check
    if(board[0][0] != '-' && board[1][1] != '-' && board[2][2] != '-'){
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    }
      

     if(board[0][2] != '-' && board[1][1] != '-' && board[2][0] != '-'){
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    }

    
    return 0;
}

// Draw Checking
int draw_check(char board[3][3]){
    int counter = 0;
    for (int i = 0; i < 3; i = i + 1){
        for (int j = 0; j < 3; j = j + 1){
            if (board[i][j]!= '-') {
                if (board[i][j] == 'X' || board[i][j] == 'O'){
                counter = counter + 1;
                }
            }
        }
    }
    if (counter == 9){
        return 1;
    }
    return 0;
}

tuple<int, int> check_boundary(char board[3][3]){
    int row, col;
    while (true) {
        cout << "Enter row and col (1-3): ";
        cin >> row >> col;

        // Check if input is within bounds
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            cout << "Invalid input. Row and col must be between 1 and 3." << endl;
            continue;
        }
                // Check if the cell is already occupied
        if (board[row - 1][col - 1] != '-') {
            cout << "Cell is already occupied! Choose a different cell." << endl;
        } else {
            break;
        }
    }
    return make_tuple(row, col);
}





int main()
{
    // learning 2d array
    char board[3][3] = {{'-', '-', '-'},
                        {'-', '-', '-'},
                        {'-', '-', '-'}};

    
    char player1 = 'X';
    char player2 = 'O';

    // print_board(board);
    // board[1-1][1-1] = 'X';
    // print_board(board);

    // print_board(board);

    while (1)
    {
        // player 1 inputs
        print_board(board);
        int row, col;
        cout << "Player 1 move" << endl;
        cout << "Enter row and col: ";
        // cin >> row >> col;
        //check boundary
        auto [player1_row, player1_col] = check_boundary(board); // tuple unpacking and getting the error free row and col
        board[player1_row-1][player1_col-1] = player1; // setting player 1 move
        int isWinner = check_winner(board);
        if(isWinner == 1){
            print_board(board);
            cout << "Player 1 is the winner" << endl;
            break;
        }

        if (draw_check(board) == 1){
            print_board(board);
            cout << "Draw" << endl;
            break;
        }
        

        // player 2 inputs
        print_board(board);
        cout << "Player 2 move" << endl;
        cout << "Enter row and col: ";
        // cin >> row >> col;
        //check boundary
        auto [player2_row, player2_col] = check_boundary(board); // tuple unpacking and getting the error free row and col
        board[player2_row-1][player2_col-1] = player2; // setting player 2 move
        isWinner = check_winner(board);
        if(isWinner == 1){
            print_board(board);
            cout << "Player 2 is the winner" << endl;
            break;
        }

         if (draw_check(board) == 1){
            print_board(board);
            cout << "Draw" << endl;
            break;
        }
       
    }

    cout << endl;
}