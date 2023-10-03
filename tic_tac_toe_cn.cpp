//who will win first player 1 or player2 or draw or uncertain
//player1 will first move 'X' and next player2 'O'


#include <bits/stdc++.h>
bool check(vector<vector<char>>& grid,int turn){
    if(turn==1){
        //row check
        for(int i=0;i<3;i++){
            bool x = true;
            for(int j=0;j<3;j++){
                if(grid[i][j]!='X')
                    x = false;
                    //break;
            }
            if(x==true)
                return true;
        }
        //column check
        for(int i=0;i<3;i++){
            bool x = true;
            for(int j=0;j<3;j++){
                if(grid[j][i]!='X')
                    x = false;
                    //break;
            }
            if(x==true)
                return true;
        }
        //forward diagonal check
        bool x = true;
        for(int i=0;i<3;i++){
            if(grid[i][i]!='X'){
                x = false;
                break;
            }
        }
        if(x==true)
            return true;
        //backward diagonal check
        x = true;
        int start = 2;
        int end = 0;
        while(start>=0 && end<=3){
            if(grid[start][end]!='X')
                x = false;
            start--;
            end++;
        }
        if(x==true)
            return true;
    }
    else{
        //row check
        for(int i=0;i<3;i++){
            bool x = true;
            for(int j=0;j<3;j++){
                if(grid[i][j]!='O')
                    x = false;
            }
            if(x==true)
                return true;
        }
        //column check
        for(int i=0;i<3;i++){
            bool x = true;
            for(int j=0;j<3;j++){
                if(grid[j][i]!='O')
                    x = false;
            }
            if(x==true)
                return true;
        }
        //forward diagonal check
        bool x = true;
        for(int i=0;i<3;i++){
            if(grid[i][i]!='O'){
                x = false;
            }
        }
        if(x==true)
            return true;
        //backward diagonal check
        x = true;
        int start = 2;
        int end = 0;
        while(start>=0 && end<=2){
            if(grid[start][end]!='O')
                x = false;
            start--;
            end++;
        }
        if(x==true)
            return true;
    }
    return false;
} 
string ticTacToeWinner(vector<vector<int>> moves, int n) {
    // Write your code here
    vector<vector<char>> grid(3,vector<char>(3,'N'));
    string player1 = "player1";
    string player2 = "player2";
    int turn = 1;
    for(int i=0;i<n;i++){
        int row = moves[i][0];
        int column = moves[i][1];
        if(turn==1){
            grid[row][column] = 'X';
        }
        else{
            grid[row][column] = 'O';
        }
        if(check(grid,turn)){
            if(turn==1){
                return player1;
            }
            else{
                return player2;
            }
        }
        turn = 1-turn;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(grid[i][j]=='N')
                return "uncertain";
        }
    }
    return "draw";
}
