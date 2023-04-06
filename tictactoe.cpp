#include<bits/stdc++.h>
using namespace std;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char current_marker;
char current_player;

void drawBoard(){
    cout << " " << board[0][0] << " " << board[0][1] << " " << board[0][2] << endl;
    cout << "----------" << endl;
    cout << " " << board[1][0] << " " << board[1][1] << " " << board[1][2] << endl;
    cout << "----------" << endl;

    cout << " " << board[2][0] << " " << board[2][1] << " " << board[2][2] << endl;
}

bool placeMarker(int slot){
    int row, col;
        row = slot / 3;

    if( slot%3==0)
       { row = row-1;
    col = 2;
    }
    else
      col = (slot % 3)-1;
      if( board[row][col]!= 'X' && board[row][col]!='O'){
    board[row][col] = current_marker;
    return true;
      }
      else
    return false;
}
char winner(){
    for (int i = 0; i < 3;i++){
        if( board[i][0]== board[i][1] && board[i][0]== board[i][2] && board[i][2]== board[i][1])
            return current_player;
        if(board[0][i]== board[1][i] && board[0][i]== board[2][i] && board[2][i]== board[1][i] )
            return current_player;
           
    }
    if( board[0][0]== board[1][1] && board[0][0]== board[2][2] && board[2][2]== board[1][1] )
       return current_player;
    if( board[0][2]== board[1][1] && board[0][2]== board[2][0] && board[2][0]== board[1][1] )
        return current_player;
    return '0';
}
void swap_player_and_marker(){
    if( current_marker=='X')
        current_marker = 'O';
    else
        current_marker = 'X';
    if( current_marker==1)
        current_player = 2;
    else
        current_player = 1;
}
void game(){
    cout << "player one, choose your marker : ";
    char marker_pl;
    cin >> marker_pl;
    // current_marker = 'x';
    current_player = 1;
    current_marker = marker_pl;
        drawBoard();
        int player_won;
        for (int i = 0; i < 9; i++)
        {
        cout << "it's player " << current_player << " 's turn. Enter your slot: " << endl;
        int slot;
        cin >> slot;
        if( slot < 1 or slot> 9 ){
            cout << " That is a invalid slot. Try another slot";
            i--;
            continue;

        }
        if(!placeMarker(slot)){
            cout << " That slot Occupies! Try another slot!";
            i--;
            continue;
        }
        player_won = winner();
         drawBoard();
        if( player_won ==1){
            cout << "player one won! Congrats!";
            break;
        }
        if( player_won ==2){
            cout << "player two won! Congrats!";
            break;
        }
        swap_player_and_marker();
       
    }
    if( player_won==0 )
        cout << " that is a tie game!";
}

int main()
{
    game();
    return 0;
}