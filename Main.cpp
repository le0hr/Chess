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
tuple<vector <vector<vector<vector<int>>>>, vector <vector<vector<vector<int>>>>> PawnsPredicthion (vector <vector<vector<vector<int>>>> black, vector <vector<vector<vector<int>>>> white, int Turn, vector<char>move){
    vector <vector<vector<vector<int>>>> copyofwhite = white;
    int q =0;
    for (size_t i = 0; i < 8; i++)
    {
        white[1][i].clear();
            if ((black[0][q][0][0] !=copyofwhite[0][i][0][0] || black[0][q][0][1] !=copyofwhite[0][i][0][1]-1) && (copyofwhite[0][q][0][0] !=copyofwhite[0][i][0][0] || copyofwhite[0][q][0][1] !=copyofwhite[0][i][0][1]-1)){
                q =0;
                white[1][i].push_back({copyofwhite[0][i][0][0], copyofwhite[0][i][0][1]-1});
                for(size_t d =0; d<8;d++){
                    if (copyofwhite[0][i][0][1]==6){        //дописати виключення
                        white[1][i].push_back({copyofwhite[0][i][0][0], copyofwhite[0][i][0][1]-2});
                    }
                    break;
                }
                
            }
            else{
                q++;
            }
            for (size_t j = 0; j < 16; j++)
            {
                if ((copyofwhite[0][i][0][0]-1 == black[0][j][0][0] && copyofwhite[0][i][0][1]-1 == black[0][j][0][1])){
                    white[1][i].push_back({black[0][j][0][0], black[0][j][0][1]});
                }
                if (copyofwhite[0][i][0][0]-1 == black[0][j][0][0] && copyofwhite[0][i][0][1]+1 == black[0][j][0][1]){
                    white[1][i].push_back({black[0][j][0][0], black[0][j][0][1]});
                }
            
        }
    }
    vector <vector<vector<vector<int>>>> copyofblack = black;
    q =0;
    for (size_t i = 0; i < 8; i++)
    {
        black[1][i].clear();
            if ((white[0][q][0][0] !=copyofblack[0][i][0][0] || white[0][q][0][1] !=copyofblack[0][i][0][1]-1) && (copyofblack[0][q][0][0] !=copyofblack[0][i][0][0] || copyofblack[0][q][0][1] !=copyofblack[0][i][0][1]-1)){
                q =0;
                black[1][i].push_back({copyofblack[0][i][0][0], copyofblack[0][i][0][1]+1});
                for(size_t d =0; d<8;d++){
                    if (copyofblack[0][i][0][1]==1){        //дописати виключення
                        black[1][i].push_back({copyofblack[0][i][0][0], copyofblack[0][i][0][1]+2});
                    }
                    break;
                }
            }
                
            else{
                q++;
            }
        for (size_t j = 0; j < 16; j++)
        {
            if (copyofblack[0][i][0][0]+1 == white[0][j][0][0] && copyofblack[0][i][0][1]+1 == white[0][j][0][1]){
                black[1][i].push_back({white[0][j][0][0], white[0][j][0][1]});
            }
            if (copyofblack[0][i][0][0]+1 == white[0][j][0][0] && copyofblack[0][i][0][1]-1 == white[0][j][0][1]){
                black[1][i].push_back({white[0][j][0][0], white[0][j][0][1]});
            }
        }
    }
    tuple tp ={white, black};
    return tp;
        
}

tuple<vector <vector<vector<vector<int>>>>, vector <vector<vector<vector<int>>>>> RooksPredicthion (vector <vector<vector<vector<int>>>> black, vector <vector<vector<vector<int>>>> white, int Turn, vector<char>move){
    // predicting for white rooks
    int j = 0;
    bool freespace1, freespace2, freespace3, freespace4;
    vector <vector<vector<vector<int>>>> copyofwhite = white;    
    vector <vector<vector<vector<int>>>> copyofblack = black;
    white[1][8].clear();
    for(int j =0; j<7; j++)
    {
        for (int i = 0; i < 16; i++){
            if(copyofwhite[0][8][0][0] -j-1 >=0 ){
                if(copyofwhite[0][8][0][0]-j-1==copyofwhite[0][i][0][0] && copyofwhite[0][8][0][1]==copyofwhite[0][i][0][1]){
                    white[1][8].push_back({copyofwhite[0][8][0][0] -j-1,copyofwhite[0][8][0][1] });
                }
                else if(copyofwhite[0][8][0][1]-j-1==copyofwhite[0][i][0][1] && copyofwhite[0][8][0][0]==copyofwhite[0][i][0][0]){
                    white[1][8].push_back({copyofwhite[0][8][0][0],copyofwhite[0][8][0][1] -j-1});
                }
            }
            else if (copyofwhite[0][8][0][0] +j+1 <=7 ){
                if (copyofwhite[0][8][0][0]+j+1==copyofwhite[0][i][0][0] && copyofwhite[0][8][0][1]==copyofwhite[0][i][0][1]){
                white[1][8].push_back({copyofwhite[0][8][0][0] +j+1,copyofwhite[0][8][0][1] });
                }
            
                else if (copyofwhite[0][8][0][1]+j+1==copyofwhite[0][i][0][1] && copyofwhite[0][8][0][0]==copyofwhite[0][i][0][0]){
                    white[1][8].push_back({copyofwhite[0][8][0][0],copyofwhite[0][8][0][1] +j+1});
                }
            }
        }    
    }

    for (int j = 0; j < 7; j++)
    {
            freespace1 = true;
        freespace2 = true;
        freespace3 = true;
        freespace4 = true;
        for (int i = 0; i < 16; i++){
            if(copyofwhite[0][8][0][0] -j-1 >=0 ){
                if(copyofwhite[0][8][0][0]-j-1==copyofblack[0][i][0][0] && copyofwhite[0][8][0][1]==copyofblack[0][i][0][1] && freespace1){
                    white[1][8].push_back({copyofwhite[0][8][0][0]-j-1,copyofwhite[0][8][0][1] });
                    freespace1 = false;
                }
                else if(copyofwhite[0][8][0][1]-j-1==copyofblack[0][i][0][1] && copyofwhite[0][8][0][0]==copyofblack[0][i][0][0] && freespace2){
                    white[1][8].push_back({copyofwhite[0][8][0][0],copyofwhite[0][8][0][1] -j-1});
                    freespace2 = false;
                }
            }
            else if (copyofwhite[0][8][0][0] +j+1 <=7 ){
                if(copyofwhite[0][8][0][0]+j+1==copyofblack[0][i][0][0] && copyofwhite[0][8][0][1]==copyofblack[0][i][0][1] && freespace3){
                    white[1][8].push_back({copyofwhite[0][8][0][0]+j+1,copyofwhite[0][8][0][1] });
                    freespace3 = false;
                }
                else if(copyofwhite[0][8][0][1]+j+1==copyofblack[0][i][0][1] && copyofwhite[0][8][0][0]==copyofblack[0][i][0][0] && freespace4){
                    white[1][8].push_back({copyofwhite[0][8][0][0],copyofwhite[0][8][0][1] +j+1});
                    freespace4 = false;
                }
            }
        }
    }
    
    white[1][15].clear();
    for( int j =0; j<7; j++)
    {
        for (int i = 0; i < 16; i++){
            if(copyofwhite[0][15][0][0] -j-1 >=0 ){
                if(copyofwhite[0][15][0][0]-j-1==copyofwhite[0][i][0][0] && copyofwhite[0][15][0][1]==copyofwhite[0][i][0][1]){
                    white[1][15].push_back({copyofwhite[0][15][0][0] -j-1,copyofwhite[0][15][0][1] });
                }
                else if(copyofwhite[0][15][0][1]-j-1==copyofwhite[0][i][0][1] && copyofwhite[0][15][0][0]==copyofwhite[0][i][0][0]){
                    white[1][15].push_back({copyofwhite[0][15][0][0],copyofwhite[0][15][0][1] -j-1});
                }
                else if(copyofwhite[0][15][0][1]-j-1==copyofblack[0][i][0][1] && copyofwhite[0][15][0][0]==copyofblack[0][i][0][0]){
                    white[1][15].push_back({copyofwhite[0][15][0][0],copyofwhite[0][15][0][1] -j-1});
                    
                }
            }
            else if (copyofwhite[0][15][0][0] +j+1 <=7 ){
                if (copyofwhite[0][15][0][0]+j+1==copyofwhite[0][i][0][0] && copyofwhite[0][15][0][1]==copyofwhite[0][i][0][1]){
                white[1][15].push_back({copyofwhite[0][15][0][0] +j+1,copyofwhite[0][15][0][1] });
                }
            
                else if (copyofwhite[0][15][0][1]+j+1==copyofwhite[0][i][0][1] && copyofwhite[0][15][0][0]==copyofwhite[0][i][0][0]){
                    white[1][15].push_back({copyofwhite[0][15][0][0],copyofwhite[0][15][0][1] +j+1});
                }
            }
        }    
    }
  
    for (int j = 0; j < 7; j++)
    {
        freespace1 = true;
        freespace2 = true;
        freespace3 = true;
        freespace4 = true;
        for (int i = 0; i < 16; i++){
            if(copyofwhite[0][15][0][0] -j-1 >=0 ){
                if(copyofwhite[0][15][0][0]-j-1==copyofblack[0][i][0][0] && copyofwhite[0][15][0][1]==copyofblack[0][i][0][1] && freespace1){
                    white[1][15].push_back({copyofwhite[0][15][0][0]-j-1,copyofwhite[0][15][0][1] });
                    freespace1 = false;
                }
                else if(copyofwhite[0][15][0][1]-j-1==copyofblack[0][i][0][1] && copyofwhite[0][15][0][0]==copyofblack[0][i][0][0] && freespace2){
                    white[1][15].push_back({copyofwhite[0][15][0][0],copyofwhite[0][15][0][1] -j-1});
                    freespace2 = false;
                }
            }
            else if (copyofwhite[0][15][0][0] +j+1 <=7 ){
                if(copyofwhite[0][15][0][0]+j+1==copyofblack[0][i][0][0] && copyofwhite[0][15][0][1]==copyofblack[0][i][0][1] && freespace3){
                    white[1][15].push_back({copyofwhite[0][15][0][0]+j+1,copyofwhite[0][15][0][1] });
                    freespace3 = false;
                }
                else if(copyofwhite[0][15][0][1]+j+1==copyofblack[0][i][0][1] && copyofwhite[0][15][0][0]==copyofblack[0][i][0][0] && freespace4){
                    white[1][15].push_back({copyofwhite[0][15][0][0],copyofwhite[0][15][0][1] +j+1});
                    freespace4 = false;
                }
            }
        }
    }

    black[1][8].clear();
    for( int j =0; j<7; j++){
        for (int i = 0; i < 16; i++){
            if(copyofblack[0][8][0][0] -j-1 >=0 ){
                if(copyofblack[0][8][0][0]-j-1==copyofblack[0][i][0][0] && copyofblack[0][8][0][1]==copyofblack[0][i][0][1]){
                    black[1][8].push_back({copyofblack[0][8][0][0] -j-1,copyofblack[0][8][0][1] });
                }
                else if(copyofblack[0][8][0][1]-j-1==copyofblack[0][i][0][1] && copyofblack[0][8][0][0]==copyofblack[0][i][0][0]){
                    black[1][8].push_back({copyofblack[0][8][0][0],copyofblack[0][8][0][1] -j-1});
                }
                else if(copyofblack[0][8][0][1]-j-1==copyofblack[0][i][0][1] && copyofblack[0][8][0][0]==copyofblack[0][i][0][0]){
                    black[1][8].push_back({copyofblack[0][8][0][0],copyofblack[0][8][0][1] -j-1});
                    
                }
            }
            else if (copyofblack[0][8][0][0] +j+1 <=7 ){
                if (copyofblack[0][8][0][0]+j+1==copyofblack[0][i][0][0] && copyofblack[0][8][0][1]==copyofblack[0][i][0][1]){
                black[1][8].push_back({copyofblack[0][8][0][0] +j+1,copyofblack[0][8][0][1] });
                }
            
                else if (copyofblack[0][8][0][1]+j+1==copyofblack[0][i][0][1] && copyofblack[0][8][0][0]==copyofblack[0][i][0][0]){
                    black[1][8].push_back({copyofblack[0][8][0][0],copyofblack[0][8][0][1] +j+1});
                }
            }
        }    
    }
    
    for (int j = 0; j < 7; j++)
    {
        freespace1 = true;
        freespace2 = true;
        freespace3 = true;
        freespace4 = true;
        for (int i = 0; i < 16; i++){
            if(copyofblack[0][8][0][0] -j-1 >=0 ){
                if(copyofblack[0][8][0][0]-j-1==copyofwhite[0][i][0][0] && copyofblack[0][8][0][1]==copyofwhite[0][i][0][1] && freespace1){
                    black[1][8].push_back({copyofblack[0][8][0][0]-j-1,copyofblack[0][8][0][1] });
                    freespace1 = false;
                }
                else if(copyofblack[0][8][0][1]-j-1==copyofwhite[0][i][0][1] && copyofblack[0][8][0][0]==copyofwhite[0][i][0][0] && freespace2){
                    black[1][8].push_back({copyofblack[0][8][0][0],copyofblack[0][8][0][1] -j-1});
                    freespace2 = false;
                }
            }
            else if (copyofblack[0][8][0][0] +j+1 <=7 ){
                if(copyofblack[0][8][0][0]+j+1==copyofwhite[0][i][0][0] && copyofblack[0][8][0][1]==copyofwhite[0][i][0][1] && freespace3){
                    black[1][8].push_back({copyofblack[0][8][0][0]+j+1,copyofblack[0][8][0][1] });
                    freespace3 = false;
                }
                else if(copyofblack[0][8][0][1]+j+1==copyofwhite[0][i][0][1] && copyofblack[0][8][0][0]==copyofwhite[0][i][0][0] && freespace4){
                    black[1][8].push_back({copyofblack[0][8][0][0],copyofblack[0][8][0][1] +j+1});
                    freespace4 = false;
                }
            }
        }
    }
    
    black[1][15].clear();
    for( int j =0; j<7; j++)
    {
        for (int i = 0; i < 16; i++){
            if(copyofblack[0][15][0][0] -j-1 >=0 ){
                if(copyofblack[0][15][0][0]-j-1==copyofblack[0][i][0][0] && copyofblack[0][15][0][1]==copyofblack[0][i][0][1]){
                    black[1][15].push_back({copyofblack[0][15][0][0] -j-1,copyofblack[0][15][0][1] });
                }
                else if(copyofblack[0][15][0][1]-j-1==copyofblack[0][i][0][1] && copyofblack[0][15][0][0]==copyofblack[0][i][0][0]){
                    black[1][15].push_back({copyofblack[0][15][0][0],copyofblack[0][15][0][1] -j-1});
                }
                else if(copyofblack[0][15][0][1]-j-1==copyofblack[0][i][0][1] && copyofblack[0][15][0][0]==copyofblack[0][i][0][0]){
                    black[1][15].push_back({copyofblack[0][15][0][0],copyofblack[0][15][0][1] -j-1});
                    
                }
            }
            else if (copyofblack[0][15][0][0] +j+1 <=7 ){
                if (copyofblack[0][15][0][0]+j+1==copyofblack[0][i][0][0] && copyofblack[0][15][0][1]==copyofblack[0][i][0][1]){
                    black[1][15].push_back({copyofblack[0][15][0][0] +j+1,copyofblack[0][15][0][1] });
                }
            
                else if (copyofblack[0][15][0][1]+j+1==copyofblack[0][i][0][1] && copyofblack[0][15][0][0]==copyofblack[0][i][0][0]){
                    black[1][15].push_back({copyofblack[0][15][0][0],copyofblack[0][15][0][1] +j+1});
                }
            }
        }    
    }
   
    for (int j = 0; j < 7; j++)
    {
        freespace1 = true;
        freespace2 = true;
        freespace3 = true;
        freespace4 = true;
        for (int i = 0; i < 16; i++){
            if(copyofblack[0][15][0][0] -j-1 >=0 ){
                if(copyofblack[0][15][0][0]-j-1==copyofwhite[0][i][0][0] && copyofblack[0][15][0][1]==copyofwhite[0][i][0][1] && freespace1){
                    black[1][15].push_back({copyofblack[0][15][0][0]-j-1,copyofblack[0][15][0][1] });
                    freespace1 = false;
                }
                else if(copyofblack[0][15][0][1]-j-1==copyofwhite[0][i][0][1] && copyofblack[0][15][0][0]==copyofwhite[0][i][0][0] && freespace2){
                    black[1][15].push_back({copyofblack[0][15][0][0],copyofblack[0][15][0][1] -j-1});
                    freespace2 = false;
                }
            }
            else if (copyofblack[0][15][0][0] +j+1 <=7 ){
                if(copyofblack[0][15][0][0]+j+1==copyofwhite[0][i][0][0] && copyofblack[0][15][0][1]==copyofwhite[0][i][0][1] && freespace3){
                    black[1][15].push_back({copyofblack[0][15][0][0]+j+1,copyofblack[0][15][0][1] });
                    freespace3 = false;
                }
                else if(copyofblack[0][15][0][1]+j+1==copyofwhite[0][i][0][1] && copyofblack[0][15][0][0]==copyofwhite[0][i][0][0] && freespace4){
                    black[1][15].push_back({copyofblack[0][15][0][0],copyofblack[0][15][0][1] +j+1});
                    freespace4 = false;
                }
            }
        }
    }

    tuple<vector <vector<vector<vector<int>>>>, vector <vector<vector<vector<int>>>>> tp= {white,black};
    return tp;
}

tuple<vector <vector<vector<vector<int>>>>, vector <vector<vector<vector<int>>>>> KnightPredicthion (vector <vector<vector<vector<int>>>> black, vector <vector<vector<vector<int>>>> white, int Turn, vector<char>move){
    tuple<vector <vector<vector<vector<int>>>>, vector <vector<vector<vector<int>>>>> tp;
    vector <vector<vector<vector<int>>>> copyofwhite = white;
    white[1][9].clear();
    //first white knight
    if (copyofwhite[0][9][0][0]-1>=0 || copyofwhite[0][9][0][1]+2<=7)
    {
        white[1][9].push_back({copyofwhite[0][9][0][0]-1, copyofwhite[0][9][0][1]+2 });
    }
    if (copyofwhite[0][9][0][0]+1<=7 || copyofwhite[0][9][0][1]+2<=7)
    {
        white[1][9].push_back({copyofwhite[0][9][0][0]+1, copyofwhite[0][9][0][1]+2 });
    }
    if (copyofwhite[0][9][0][0]-1>=0 || copyofwhite[0][9][0][1]-2>=0)
    {
        white[1][9].push_back({copyofwhite[0][9][0][0]-1, copyofwhite[0][9][0][1]-2 });
    }
    if (copyofwhite[0][9][0][0]+1<=7 || copyofwhite[0][9][0][1]-2>=0)
    {
        white[1][9].push_back({copyofwhite[0][9][0][0]+1, copyofwhite[0][9][0][1]-2 });
    }

    if (copyofwhite[0][9][0][0]-2>=0 || copyofwhite[0][9][0][1]+1<=7)
    {
        white[1][9].push_back({copyofwhite[0][9][0][0]-2, copyofwhite[0][9][0][1]+1 });
    }
    if (copyofwhite[0][9][0][0]+2<=7 || copyofwhite[0][9][0][1]+1<=7)
    {
        white[1][9].push_back({copyofwhite[0][9][0][0]+2, copyofwhite[0][9][0][1]+1 });
    }
    if (copyofwhite[0][9][0][0]-2>=0 || copyofwhite[0][9][0][1]-1>=0)
    {
        white[1][9].push_back({copyofwhite[0][9][0][0]-2, copyofwhite[0][9][0][1]-1 });
    }
    if (copyofwhite[0][9][0][0]+2<=7 || copyofwhite[0][9][0][1]-1>=0)
    {
        white[1][9].push_back({copyofwhite[0][9][0][0]+2, copyofwhite[0][9][0][1]-1 });
    }
    
    //second white knight
    if (copyofwhite[0][14][0][0]-1>=0 || copyofwhite[0][14][0][1]+2<=7)
    {
        white[1][14].push_back({copyofwhite[0][14][0][0]-1, copyofwhite[0][14][0][1]+2 });
    }
    if (copyofwhite[0][14][0][0]+1<=7 || copyofwhite[0][14][0][1]+2<=7)
    {
        white[1][14].push_back({copyofwhite[0][14][0][0]+1, copyofwhite[0][14][0][1]+2 });
    }
    if (copyofwhite[0][14][0][0]-1>=0 || copyofwhite[0][14][0][1]-2>=0)
    {
        white[1][14].push_back({copyofwhite[0][14][0][0]-1, copyofwhite[0][14][0][1]-2 });
    }
    if (copyofwhite[0][14][0][0]+1<=7 || copyofwhite[0][14][0][1]-2>=0)
    {
        white[1][14].push_back({copyofwhite[0][14][0][0]+1, copyofwhite[0][14][0][1]-2 });
    }

    if (copyofwhite[0][14][0][0]-2>=0 || copyofwhite[0][14][0][1]+1<=7)
    {
        white[1][14].push_back({copyofwhite[0][14][0][0]-2, copyofwhite[0][14][0][1]+1 });
    }
    if (copyofwhite[0][14][0][0]+2<=7 || copyofwhite[0][14][0][1]+1<=7)
    {
        white[1][14].push_back({copyofwhite[0][14][0][0]+2, copyofwhite[0][14][0][1]+1 });
    }
    if (copyofwhite[0][14][0][0]-2>=0 || copyofwhite[0][14][0][1]-1>=0)
    {
        white[1][14].push_back({copyofwhite[0][14][0][0]-2, copyofwhite[0][14][0][1]-1 });
    }
    if (copyofwhite[0][14][0][0]+2<=7 || copyofwhite[0][14][0][1]-1>=0)
    {
        white[1][14].push_back({copyofwhite[0][14][0][0]+2, copyofwhite[0][14][0][1]-1 });
    }



    vector <vector<vector<vector<int>>>> copyofblack = black;
    black[1][9].clear();
    //first black knight
        if (copyofblack[0][9][0][0]-1>=0 || copyofblack[0][9][0][1]+2<=7)
    {
        black[1][9].push_back({copyofblack[0][9][0][0]-1, copyofblack[0][9][0][1]+2 });
    }
    if (copyofblack[0][9][0][0]+1<=7 || copyofblack[0][9][0][1]+2<=7)
    {
        black[1][9].push_back({copyofblack[0][9][0][0]+1, copyofblack[0][9][0][1]+2 });
    }
    if (copyofblack[0][9][0][0]-1>=0 || copyofblack[0][9][0][1]-2>=0)
    {
        black[1][9].push_back({copyofblack[0][9][0][0]-1, copyofblack[0][9][0][1]-2 });
    }
    if (copyofblack[0][9][0][0]+1<=7 || copyofblack[0][9][0][1]-2>=0)
    {
        black[1][9].push_back({copyofblack[0][9][0][0]+1, copyofblack[0][9][0][1]-2 });
    }

    if (copyofblack[0][9][0][0]-2>=0 || copyofblack[0][9][0][1]+1<=7)
    {
        black[1][9].push_back({copyofblack[0][9][0][0]-2, copyofblack[0][9][0][1]+1 });
    }
    if (copyofblack[0][9][0][0]+2<=7 || copyofblack[0][9][0][1]+1<=7)
    {
        black[1][9].push_back({copyofblack[0][9][0][0]+2, copyofblack[0][9][0][1]+1 });
    }
    if (copyofblack[0][9][0][0]-2>=0 || copyofblack[0][9][0][1]-1>=0)
    {
        black[1][9].push_back({copyofblack[0][9][0][0]-2, copyofblack[0][9][0][1]-1 });
    }
    if (copyofblack[0][9][0][0]+2<=7 || copyofblack[0][9][0][1]-1>=0)
    {
        black[1][9].push_back({copyofblack[0][9][0][0]+2, copyofblack[0][9][0][1]-1 });
    }
    
    //second black knight
    if (copyofblack[0][14][0][0]-1>=0 || copyofblack[0][14][0][1]+2<=7)
    {
        black[1][14].push_back({copyofblack[0][14][0][0]-1, copyofblack[0][14][0][1]+2 });
    }
    if (copyofblack[0][14][0][0]+1<=7 || copyofblack[0][14][0][1]+2<=7)
    {
        black[1][14].push_back({copyofblack[0][14][0][0]+1, copyofblack[0][14][0][1]+2 });
    }
    if (copyofblack[0][14][0][0]-1>=0 || copyofblack[0][14][0][1]-2>=0)
    {
        black[1][14].push_back({copyofblack[0][14][0][0]-1, copyofblack[0][14][0][1]-2 });
    }
    if (copyofblack[0][14][0][0]+1<=7 || copyofblack[0][14][0][1]-2>=0)
    {
        black[1][14].push_back({copyofblack[0][14][0][0]+1, copyofblack[0][14][0][1]-2 });
    }

    if (copyofblack[0][14][0][0]-2>=0 || copyofblack[0][14][0][1]+1<=7)
    {
        black[1][14].push_back({copyofblack[0][14][0][0]-2, copyofblack[0][14][0][1]+1 });
    }
    if (copyofblack[0][14][0][0]+2<=7 || copyofblack[0][14][0][1]+1<=7)
    {
        black[1][14].push_back({copyofblack[0][14][0][0]+2, copyofblack[0][14][0][1]+1 });
    }
    if (copyofblack[0][14][0][0]-2>=0 || copyofblack[0][14][0][1]-1>=0)
    {
        black[1][14].push_back({copyofblack[0][14][0][0]-2, copyofblack[0][14][0][1]-1 });
    }
    if (copyofblack[0][14][0][0]+2<=7 || copyofblack[0][14][0][1]-1>=0)
    {
        black[1][14].push_back({copyofblack[0][14][0][0]+2, copyofblack[0][14][0][1]-1 });
    }

    return tp = {white, black};
}

tuple<vector <vector<vector<vector<int>>>>, vector <vector<vector<vector<int>>>>> BishopPredicthion (vector <vector<vector<vector<int>>>> black, vector <vector<vector<vector<int>>>> white, int Turn, vector<char>move){
    
}

vector <vector<vector<vector<int>>>> makeTurn(vector<char> move, vector <vector<vector<vector<int>>>> piece){
    if (move.size() == 2){
        move[0] = ((int)move[0]-97);
        move[1] = 7-((int)move[1] - (int)'0'-1);
        for (size_t i = 0; i < 8; i++)
        {
            for (size_t j = 0; j < piece[1][i].size(); j++)
            {
                if(piece[1][i][j][0]==move[0] && piece[1][i][j][1] == move[1]){
                    piece[0][i][0][0] = move[0];
                    piece[0][i][0][1] = move[1];
                    return piece;
                }
            }
            
        }
    }
    else{
        move[1] = ((int)move[1]-97);
        move[2] = 7-((int)move[2] - (int)'0'-1);
        switch ((int)move[0])
        {
        case (int)'R':
            for (size_t i = 0; i < piece[1][8].size(); i++)
            {
                if(piece[1][8][i][0]==move[1] && piece[1][8][i][1] == move[2]){
                    piece[0][8][0][0] = move[1];
                    piece[0][8][0][1] = move[2];
                    return piece;
                }
            }
            for (size_t i = 0; i < piece[1][15].size(); i++)
            {
                if(piece[1][15][i][0]==move[1] && piece[1][15][i][1] == move[2]){
                    piece[0][15][0][0] = move[1];
                    piece[0][15][0][1] = move[2];
                    return piece;
                }
            }
        
        case (int)'K':
            for (size_t i = 0; i < piece[1][9].size(); i++)
            {
                if(piece[1][9][i][0]==move[1] && piece[1][9][i][1] == move[2]){
                    piece[0][9][0][0] = move[1];
                    piece[0][9][0][1] = move[2];
                    return piece;
                }
            }
            for (size_t i = 0; i < piece[1][14].size(); i++)
            {
                if(piece[1][14][i][0]==move[1] && piece[1][14][i][1] == move[2]){
                    piece[0][14][0][0] = move[1];
                    piece[0][14][0][1] = move[2];
                    return piece;
                }
            }
        default:
            break;
        }
        
}}
    
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
    tuple<vector <vector<vector<vector<int>>>>, vector <vector<vector<vector<int>>>>> tp;
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
        if (Turn ==0){
            white = makeTurn(move, white);
            
        }
        else{
            black = makeTurn(move, black);  
        }
        tp = PawnsPredicthion(black, white, 0, move);  
        white = get<0>(tp);
        black = get<1>(tp);
        tp = RooksPredicthion(black, white, 0, move);  
        white = get<0>(tp);
        black = get<1>(tp);
        tp = KnightPredicthion(black, white, 0, move);  
        white = get<0>(tp);
        black = get<1>(tp);
        Turn = (Turn +1)%2;
        }
        
    return 1;
}
