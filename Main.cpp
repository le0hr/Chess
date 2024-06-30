#include<vector>
#include<iostream>
#include <typeinfo.h>

using namespace std;

vector<char> enter(){
    string move;
    char piece;

    tuple<char,char, int> t = {};
    cin>>move;
    vector<char> data(move.begin(), move.end());

    return data;
}

vector <vector<vector<vector<int>>>> predicthion (vector <vector<vector<vector<int>>>> black, vector <vector<vector<vector<int>>>> white, int Turn){
    
    if (Turn ==0)
    {
        vector <vector<vector<vector<int>>>> copyofwhite = white;
        white[1].clear();
        for (size_t i = 0; i < 8; i++)
        {
            white[1].push_back({});
            while (true)
            {
                white[1][i].push_back({copyofwhite[0][i][0][0], copyofwhite[0][i][0][1]+1});
                if (copyofwhite[0][i][0][1]==1){
                    white[1][i].push_back({copyofwhite[0][i][0][0], copyofwhite[0][i][0][1]+2});
                }
                for (size_t j = 0; j < 8; j++)
                {
                    if (copyofwhite[0][i][0][0]+1 == black[0][j][0][0] && copyofwhite[0][i][0][1]+1 == black[0][j][0][1]){
                        white[1][i].push_back({black[0][j][0][0], black[0][j][0][1]});
                    }
                    if (copyofwhite[0][i][0][0]-1 == black[0][j][0][0] && copyofwhite[0][i][0][1]+1 == black[0][j][0][1]){
                        white[1][i].push_back({black[0][j][0][0], black[0][j][0][1]});
                    }
                }
                
                
            }
            
            
        }
        return white;
    }
    else{
        vector <vector<vector<vector<int>>>> copyofblack = black;
        black[1].clear();
        for (size_t i = 0; i < 8; i++)
        {
             black[1].push_back({});
            while (true)
            {
                black[1][i].push_back({copyofblack[0][i][0][0], copyofblack[0][i][0][1]-1});
                if (copyofblack[0][i][0][1]==6){
                    white[1][i].push_back({copyofblack[0][i][0][0], copyofblack[0][i][0][1]-2});
                }
                for (size_t j = 0; j < 8; j++)
                {
                    if (copyofblack[0][i][0][0]-1 == white[0][j][0][0] && copyofblack[0][i][0][1]-1 == white[0][j][0][1]){
                        black[1][i].push_back({white[0][j][0][0], white[0][j][0][1]});
                    }
                    if (copyofblack[0][i][0][0]-1 == white[0][j][0][0] && copyofblack[0][i][0][1]+1 == white[0][j][0][1]){
                        black[1][i].push_back({white[0][j][0][0], white[0][j][0][1]});
                    }
                }
                
                
            }
        }
        return black;
    }
    
    
    
}

vector <vector<vector<vector<int>>>> makeTurn(vector<char> move, vector <vector<vector<vector<int>>>> piece){
    if (move.size() == 2){
        move[0] = (int)move[0]-97;
    }
    else{
        move[1] = (int)move[1]-97;
    }
    for (size_t i = 0; i < piece[1].size(); i++)
    {
        for (size_t j = 0; j < piece[1][i].size(); j++)
        {
            if(piece[1][i][j][0]==move[0] && piece[1][i][j][1] == move[1]){
                piece[0][i][j][0] = move[0];
                piece[0][i][j][1] = move[1];
            }
        }
        
    }
    
    
    return piece;
}

void render(vector <vector<vector<vector<int>>>> black, vector <vector<vector<vector<int>>>> white, vector < vector <string> > board){
    for (size_t i = 0; i < 8; i++)
    {
        board[white[0][i][0][1]][white[0][i][0][0]] = "P";
        board[black[0][i][0][1]][black[0][i][0][0]] = "P";
    }
    board[white[0][8][0][1]][white[0][8][0][0]] = "R";
    board[black[0][8][0][1]][black[0][8][0][0]] = "R";
    board[white[0][15][0][1]][white[0][15][0][0]] = "R";
    board[black[0][15][0][1]][black[0][15][0][0]] = "R";

    board[white[0][9][0][1]][white[0][9][0][0]] = "K";
    board[black[0][9][0][1]][black[0][9][0][0]] = "K";
    board[white[0][14][0][1]][white[0][14][0][0]] = "K";
    board[black[0][14][0][1]][black[0][14][0][0]] = "K";

    board[white[0][10][0][1]][white[0][10][0][0]] = "B";
    board[black[0][10][0][1]][black[0][10][0][0]] = "B";
    board[white[0][13][0][1]][white[0][13][0][0]] = "B";
    board[black[0][13][0][1]][black[0][13][0][0]] = "B";

    board[white[0][11][0][1]][white[0][11][0][0]] = "Q";
    board[black[0][11][0][1]][black[0][11][0][0]] = "Q";

    board[white[0][12][0][1]][white[0][12][0][0]] = "@";
    board[black[0][12][0][1]][black[0][12][0][0]] = "@";
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            cout<<board[i][j];

        }
        cout<<endl;
        
    }
    
    
}

int main(){
    int Turn =0;
    vector<char> move = {};

    vector < vector <string> > board = {{".",".",".",".",".",".",".","."},
    {".",".",".",".",".",".",".","."},
    {".",".",".",".",".",".",".","."},
    {".",".",".",".",".",".",".","."},
    {".",".",".",".",".",".",".","."},
    {".",".",".",".",".",".",".","."},
    {".",".",".",".",".",".",".","."},
    {".",".",".",".",".",".",".", "."}};

    vector <vector<vector<vector<int>>>> black = {{{{0, 1}}, {{1,1}}, {{2,1}}, {{3,1}}, {{4,1}}, {{5,1}}, {{6,1}}, {{7,1}}, {{0,0}}, {{1,0}}, {{2,0}}, {{3,0}}, {{4,0}}, {{5,0}}, {{6,0}}, {{7,0}}},
                                             {{{0, 2},{0,3}}, {{1,2}, {1,3}}, {{2,2}, {2,3}}, {{3,2},{3,3}}, {{4,2},{4,3}}, {{5,2},{5,3}}, {{6,2},{6,3}}, {{7,2},{7,3}}, {{-1}}, {{0,2},{2,2}}, {{-1}}, {{-1}}, {{-1}}, {{-1}}, {{5,2},{7,2}}, {{-1}}}};

    vector <vector<vector<vector<int>>>> white = {{{{0, 6}}, {{1,6}}, {{2,6}}, {{3,6}}, {{4,6}}, {{5,6}}, {{6,6}}, {{7,6}}, {{0,7}}, {{1,7}}, {{2,7}}, {{3,7}}, {{4,7}}, {{5,7}}, {{6,7}}, {{7,7}}},
                                             {{{0, 5},{0,4}}, {{1,5}, {1,4}}, {{2,5}, {2,4}}, {{3,5},{3,4}}, {{4,5},{4,4}}, {{5,5},{5,4}}, {{6,5},{6,4}}, {{7,5},{7,4}}, {{-1}}, {{0,5},{2,5}}, {{-1}}, {{-1}}, {{-1}}, {{-1}}, {{5,5},{7,5}}, {{-1}}}};
    while(true){
        render(black, white, board);
        move= enter(); 
        predicthion(black, white, Turn);      
        if (Turn ==0){
            white = makeTurn(move, white);
            white = predicthion(black, white, Turn);     
        }
        else{
            black = makeTurn(move, black);
            black = predicthion(black, black, Turn); 
            return 1;
        }
        Turn = (Turn +1)%2;
    }
}
