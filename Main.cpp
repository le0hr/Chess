#include<vector>
#include<iostream>
//#include <typeinfo.h>

using namespace std;

bool InRange(int a, int b, int c){
    if(a>=b && a<=c){
        return true;
    }
    else{
        return false;
    }
}

class WPawn
{
public:
    tuple<int, int> coordinates = {0,6};
    vector<vector<int>> Predicthion = {{0,5, 1}, {0,4, 1}};
    vector<vector<int>> predicthion(tuple<int, int> coordinates, vector<vector<char>> Board){
        vector<vector<int>> Predicthion;
        if (get<1>(coordinates)==6 && Board[get<1>(coordinates)-2][get<0>(coordinates)] == '.'){
            Predicthion.push_back({get<0>(coordinates), get<1>(coordinates) - 2, 1});
        }
        if (get<1>(coordinates) -1>=0 && Board[get<1>(coordinates)-1][get<0>(coordinates)] == '.'){
            Predicthion.push_back({get<0>(coordinates), get<1>(coordinates) - 1, 1});
        }
        if ((get<1>(coordinates) -1>=0 && get<0>(coordinates) -1>=0) && InRange((int)Board[get<1>(coordinates)-1][get<0>(coordinates)-1], (int)'a', (int)'z')){
           Predicthion.push_back({{get<0>(coordinates)-1, get<1>(coordinates) - 1, 0}});
        }
        if ((get<1>(coordinates)-1>=0 && get<0>(coordinates)+1<=7) && InRange((int)Board[get<1>(coordinates)-1][get<0>(coordinates)+1], (int)'a', (int)'z')){
           Predicthion.push_back({{get<0>(coordinates)+1, get<1>(coordinates) - 1, 0}});
        }
        return Predicthion;
    }
    
        
};

class BPawn{
private:

public:
    tuple<int, int> coordinates = {0,1};
    vector<vector<int>> Predicthion = {{0,2}, {0,3}};
    vector<vector<int>> predicthion(tuple<int, int> coordinates, vector<vector<char>> Board){
        vector<vector<int>> Predicthion;
        if (get<1>(coordinates)==1 && Board[get<1>(coordinates)+2][get<0>(coordinates) ] == '.'){
            Predicthion.push_back({get<0>(coordinates), get<1>(coordinates) + 2, 1});
        }
        if (get<1>(coordinates) +1 <=7 && Board[get<1>(coordinates)+1][get<0>(coordinates)] == '.'){
            Predicthion.push_back({get<0>(coordinates), get<1>(coordinates) + 1, 1});
        }
        if ((get<1>(coordinates) +1<=7 && get<0>(coordinates) -1>=0) && InRange((int)Board[get<1>(coordinates)+1][get<0>(coordinates)-1], (int)'A', (int)'Z')){
           Predicthion.push_back({{get<0>(coordinates)-1, get<1>(coordinates) + 1, 0}});
        }
        if ((get<0>(coordinates)+1<=7 && get<1>(coordinates)+1<=7) && InRange((int)Board[get<1>(coordinates)+1][get<0>(coordinates)+1], (int)'A', (int)'Z')){
           Predicthion.push_back({{get<0>(coordinates)+1, get<1>(coordinates) + 1, 0}});
        }
        return Predicthion;
    }
};

class WRook{
public:
    tuple<int, int> coordinates = {0,0};
    vector<vector<int>> Predicthion;
    vector<vector<int>> predicthion(tuple<int, int> coordinates, vector<vector<char>> Board){
        vector<vector<int>> Predicthion;
        for(int i =1; i<8; i++){
            if (get<0>(coordinates)-i <0){
                break;
            }
            if (InRange(Board[get<1>(coordinates)][get<0>(coordinates)-i], (int)'a', (int)'z')){
                Predicthion.push_back({get<0>(coordinates)-i, get<1>(coordinates),0});
                break;
            }
            if (InRange(Board[get<1>(coordinates)][get<0>(coordinates)-i], (int)'A', (int)'Z') || Board[get<1>(coordinates)][get<0>(coordinates)-i] =='@'|| Board[get<1>(coordinates)][get<0>(coordinates)-i] =='#'){
                break;
            }
            if (Board[get<1>(coordinates)][get<0>(coordinates)-i] =='.'){
                Predicthion.push_back({get<0>(coordinates)-i, get<1>(coordinates), 1});
            }
            
        }
        for(int i =1; i<8; i++){
            if (get<0>(coordinates)+i >7){
                break;
            }
            if (InRange(Board[get<1>(coordinates)][get<0>(coordinates)+i], (int)'a', (int)'z')){
                Predicthion.push_back({get<0>(coordinates)+i, get<1>(coordinates),0});
                break;
            }
            if (InRange(Board[get<1>(coordinates)][get<0>(coordinates)+i], (int)'A', (int)'Z') || Board[get<1>(coordinates)][get<0>(coordinates)+i] =='@' || Board[get<1>(coordinates)][get<0>(coordinates)+i] =='#'){
                break;
            }
            if (Board[get<1>(coordinates)][get<0>(coordinates)+i] =='.'){
                Predicthion.push_back({get<0>(coordinates)+i, get<1>(coordinates), 1});
            }
            
        }
        for(int i =1; i<8; i++){
            if (get<1>(coordinates)-i <0){
                break;
            }
            if (InRange(Board[get<1>(coordinates)-i][get<0>(coordinates)], (int)'a', (int)'z')){
                Predicthion.push_back({get<0>(coordinates), get<1>(coordinates)-i,0});
                break;
            }
            if (InRange(Board[get<1>(coordinates)-i][get<0>(coordinates)], (int)'A', (int)'Z') || Board[get<1>(coordinates)-i][get<0>(coordinates)] =='@' || Board[get<1>(coordinates)-i][get<0>(coordinates)] =='#'){
                break;
            }
            if (Board[get<1>(coordinates)-i][get<0>(coordinates)] =='.'){
                Predicthion.push_back({get<0>(coordinates), get<1>(coordinates)-i, 1});
            }
            
        }
        for(int i =1; i<8; i++){
            if (get<1>(coordinates)+i >7){
                break;
            }
            if (InRange(Board[get<1>(coordinates)+i][get<0>(coordinates)], (int)'a', (int)'z')){
                Predicthion.push_back({get<0>(coordinates), get<1>(coordinates)+i,0});
                break;
            }
            if (InRange(Board[get<1>(coordinates)+i][get<0>(coordinates)], (int)'A', (int)'Z') || Board[get<1>(coordinates)+i][get<0>(coordinates)] =='@' || Board[get<1>(coordinates)+i][get<0>(coordinates)] =='#'){
                break;
            }
            if (Board[get<1>(coordinates)+i][get<0>(coordinates)] =='.'){
                Predicthion.push_back({get<0>(coordinates), get<1>(coordinates)+i, 1});
            }
            
        }
        return Predicthion;
    }
};

class BRook{
public:
    tuple<int, int> coordinates = {0,0};
    vector<vector<int>> Predicthion;
    vector<vector<int>> predicthion(tuple<int, int> coordinates, vector<vector<char>> Board){
        vector<vector<int>> Predicthion;
        for(int i =1; i<8; i++){
            if (get<0>(coordinates)-i <0){
                break;
            }
            if (InRange(Board[get<1>(coordinates)][get<0>(coordinates)-i], (int)'A', (int)'Z')){
                Predicthion.push_back({get<0>(coordinates)-i, get<1>(coordinates),0});
                break;
            }
            if (InRange(Board[get<1>(coordinates)][get<0>(coordinates)-i], (int)'a', (int)'z'), Board[get<1>(coordinates)][get<0>(coordinates)-i] =='@', Board[get<1>(coordinates)][get<0>(coordinates)-i] =='#'){
                break;
            }
            if (Board[get<1>(coordinates)][get<0>(coordinates)-i] =='.'){
                Predicthion.push_back({get<0>(coordinates)-i, get<1>(coordinates), 1});
            }
            
        }
        for(int i =1; i<8; i++){
            if (get<0>(coordinates)+i >7){
                break;
            }
            if (InRange(Board[get<1>(coordinates)][get<0>(coordinates)+i], (int)'A', (int)'Z')){
                Predicthion.push_back({get<0>(coordinates)+i, get<1>(coordinates),0});
                break;
            }
            if (InRange(Board[get<1>(coordinates)][get<0>(coordinates)+i], (int)'a', (int)'z'), Board[get<1>(coordinates)][get<0>(coordinates)+i] =='@', Board[get<1>(coordinates)][get<0>(coordinates)+i] =='#'){
                break;
            }
            if (Board[get<1>(coordinates)][get<0>(coordinates)+i] =='.'){
                Predicthion.push_back({get<0>(coordinates)+i, get<1>(coordinates), 1});
            }
            
        }
        for(int i =1; i<8; i++){
            if (get<1>(coordinates)-i <0){
                break;
            }
            if (InRange(Board[get<1>(coordinates)-i][get<0>(coordinates)], (int)'A', (int)'Z')){
                Predicthion.push_back({get<0>(coordinates), get<1>(coordinates)-i,0});
                break;
            }
            if (InRange(Board[get<1>(coordinates)-i][get<0>(coordinates)], (int)'a', (int)'z'), Board[get<1>(coordinates)-i][get<0>(coordinates)] =='@', Board[get<1>(coordinates)-i][get<0>(coordinates)] =='#'){
                break;
            }
            if (Board[get<1>(coordinates)-i][get<0>(coordinates)] =='.'){
                Predicthion.push_back({get<0>(coordinates), get<1>(coordinates)-i, 1});
            }
            
        }
        for(int i =1; i<8; i++){
            if (get<1>(coordinates)+i >7){
                break;
            }
            if (InRange(Board[get<1>(coordinates)+i][get<0>(coordinates)], (int)'A', (int)'Z')){
                Predicthion.push_back({get<1>(coordinates), get<0>(coordinates)+i,0});
                break;
            }
            if (InRange(Board[get<1>(coordinates)+i][get<0>(coordinates)], (int)'a', (int)'z'), Board[get<1>(coordinates)+i][get<0>(coordinates)] =='@', Board[get<1>(coordinates)+i][get<0>(coordinates)] =='#'){
                break;
            }
            if (Board[get<1>(coordinates)+i][get<0>(coordinates)] =='.'){
                Predicthion.push_back({get<0>(coordinates), get<1>(coordinates)+i, 1});
            }
            
        }
        return Predicthion;
    }
};

class WKnight{
public:
    tuple<int, int> coordinates = {0,0};
    vector<vector<int>> Predicthion;
    vector<vector<int>> predicthion(tuple<int, int> coordinates, vector<vector<char>> Board){
        if((get<1>(coordinates)-1>=0 && get<0>(coordinates)-2>=0) && (Board[get<1>(coordinates)-1][get<0>(coordinates)-2]=='.' || InRange((int)Board[get<1>(coordinates)-1][get<0>(coordinates)-2], (int)'a', (int)'z'))){
            Predicthion.push_back({get<0>(coordinates)-2, get<1>(coordinates)-1, 1*!InRange((int)Board[get<1>(coordinates)-1][get<0>(coordinates)-2], (int)'a', (int)'z')});
        }
        if ((get<1>(coordinates)+1<=7 && get<0>(coordinates)-2>=0) &&(Board[get<1>(coordinates)+1][get<0>(coordinates)-2]=='.' || InRange((int)Board[get<1>(coordinates)+1][get<0>(coordinates)-2], (int)'a', (int)'z'))){
            Predicthion.push_back({get<0>(coordinates)-2, get<1>(coordinates)+1, 1*!InRange((int)Board[get<1>(coordinates)+1][get<0>(coordinates)-2], (int)'a', (int)'z')});
        }
        if((get<1>(coordinates)-1>=0 && get<0>(coordinates)+2<=7) && (Board[get<1>(coordinates)-1][get<0>(coordinates)+2]=='.' || InRange((int)Board[get<1>(coordinates)-1][get<0>(coordinates)+2], (int)'a', (int)'z'))){
            Predicthion.push_back({get<0>(coordinates)+2, get<1>(coordinates)-1, 1*!InRange((int)Board[get<1>(coordinates)-1][get<0>(coordinates)+2], (int)'a', (int)'z')});
        }
        if ((get<1>(coordinates)+1<=7 && get<0>(coordinates)+2<=7) && (Board[get<1>(coordinates)+1][get<0>(coordinates)+2]=='.' || InRange((int)Board[get<1>(coordinates)+1][get<0>(coordinates)+2], (int)'a', (int)'z'))){
            Predicthion.push_back({get<0>(coordinates)+2, get<1>(coordinates)+1, 1*!InRange((int)Board[get<1>(coordinates)+1][get<0>(coordinates)+2], (int)'a', (int)'z')});
        }

        if((get<1>(coordinates)-2>=0 && get<0>(coordinates)-1>=0) &&(Board[get<1>(coordinates)-2][get<0>(coordinates)-1]=='.' || InRange((int)Board[get<1>(coordinates)-2][get<0>(coordinates)-1], (int)'a', (int)'z'))){
            Predicthion.push_back({get<0>(coordinates)-1, get<1>(coordinates)-2, 1*!InRange((int)Board[get<1>(coordinates)-2][get<0>(coordinates)-1], (int)'a', (int)'z')});
        }
        if ((get<1>(coordinates)-2>=0 && get<0>(coordinates)+1<=7) && (Board[get<1>(coordinates)-2][get<0>(coordinates)+1]=='.' || InRange((int)Board[get<1>(coordinates)-2][get<0>(coordinates)+1], (int)'a', (int)'z'))){
            Predicthion.push_back({get<0>(coordinates)+1, get<1>(coordinates)-2, 1*!InRange((int)Board[get<1>(coordinates)-2][get<0>(coordinates)+1], (int)'a', (int)'z')});
        }
        if((get<1>(coordinates)+2<=7 && get<0>(coordinates)-1>=0) && (Board[get<1>(coordinates)+2][get<0>(coordinates)-1]=='.' || InRange((int)Board[get<1>(coordinates)+2][get<0>(coordinates)-1], (int)'a', (int)'z'))){
            Predicthion.push_back({get<0>(coordinates)-1, get<1>(coordinates)+2, 1*!InRange((int)Board[get<1>(coordinates)+2][get<0>(coordinates)-1], (int)'a', (int)'z')});
        }
        if ((get<1>(coordinates)+2<=7 && get<0>(coordinates)+1<=7) &&(Board[get<1>(coordinates)+2][get<0>(coordinates)+1]=='.' || InRange((int)Board[get<1>(coordinates)+2][get<0>(coordinates)+1], (int)'a', (int)'z'))){
            Predicthion.push_back({get<0>(coordinates)+1, get<1>(coordinates)+2, 1*!InRange((int)Board[get<1>(coordinates)+2][get<0>(coordinates)+1], (int)'a', (int)'z')});
        }
        return Predicthion;
    }

};

class BKnight{
public:
    tuple<int, int> coordinates = {0,0};
    vector<vector<int>> Predicthion;
    vector<vector<int>> predicthion(tuple<int, int> coordinates, vector<vector<char>> Board){
        if((get<1>(coordinates)-1>=0 && get<0>(coordinates)-2>=0) && (Board[get<1>(coordinates)-1][get<0>(coordinates)-2]=='.' || InRange((int)Board[get<1>(coordinates)-1][get<0>(coordinates)-2], (int)'A', (int)'Z'))){
            Predicthion.push_back({get<0>(coordinates)-2, get<1>(coordinates)-1, 1*!InRange((int)Board[get<1>(coordinates)-1][get<0>(coordinates)-2], (int)'A', (int)'Z')});
        }
        if ((get<1>(coordinates)+1<=7 && get<0>(coordinates)-2>=0) &&(Board[get<1>(coordinates)+1][get<0>(coordinates)-2]=='.' || InRange((int)Board[get<1>(coordinates)+1][get<0>(coordinates)-2], (int)'A', (int)'Z'))){
            Predicthion.push_back({get<0>(coordinates)-2, get<1>(coordinates)+1, 1*!InRange((int)Board[get<1>(coordinates)+1][get<0>(coordinates)-2], (int)'A', (int)'Z')});
        }
        if((get<1>(coordinates)-1>=0 && get<0>(coordinates)+2<=7) && (Board[get<1>(coordinates)-1][get<0>(coordinates)+2]=='.' || InRange((int)Board[get<1>(coordinates)-1][get<0>(coordinates)+2], (int)'A', (int)'Z'))){
            Predicthion.push_back({get<0>(coordinates)+2, get<1>(coordinates)-1, 1*!InRange((int)Board[get<1>(coordinates)-1][get<0>(coordinates)+2], (int)'A', (int)'Z')});
        }
        if ((get<0>(coordinates)+2<=7 && get<1>(coordinates)+1<=7) && (Board[get<1>(coordinates)+1][get<0>(coordinates)+2]=='.' || InRange((int)Board[get<1>(coordinates)+1][get<0>(coordinates)+2], (int)'A', (int)'Z'))){
            Predicthion.push_back({get<0>(coordinates)+2, get<1>(coordinates)+1, 1*!InRange((int)Board[get<1>(coordinates)+1][get<0>(coordinates)+2], (int)'A', (int)'Z')});
        }

        if((get<1>(coordinates)-2>=0 && get<0>(coordinates)-1>=0) &&(Board[get<1>(coordinates)-2][get<0>(coordinates)-1]=='.' || InRange((int)Board[get<1>(coordinates)-2][get<0>(coordinates)-1], (int)'A', (int)'Z'))){
            Predicthion.push_back({get<0>(coordinates)-1, get<1>(coordinates)-2, 1*!InRange((int)Board[get<1>(coordinates)-2][get<0>(coordinates)-1], (int)'A', (int)'Z')});
        }
        if ((get<1>(coordinates)-2>=0 && get<0>(coordinates)+1<=7) && (Board[get<1>(coordinates)-2][get<0>(coordinates)+1]=='.' || InRange((int)Board[get<1>(coordinates)-2][get<0>(coordinates)+1], (int)'A', (int)'Z'))){
            Predicthion.push_back({get<0>(coordinates)+1, get<1>(coordinates)-2, 1*!InRange((int)Board[get<1>(coordinates)-2][get<0>(coordinates)+1], (int)'A', (int)'Z')});
        }
        if((get<1>(coordinates)+2<=7 && get<0>(coordinates)-1>=0) && (Board[get<1>(coordinates)+2][get<0>(coordinates)-1]=='.' || InRange((int)Board[get<1>(coordinates)+2][get<0>(coordinates)-1], (int)'A', (int)'Z'))){
            Predicthion.push_back({get<0>(coordinates)-1, get<1>(coordinates)+2, 1*!InRange((int)Board[get<1>(coordinates)+2][get<0>(coordinates)-1], (int)'A', (int)'Z')});
        }
        if ((get<1>(coordinates)+2<=7 && get<0>(coordinates)+1<=7) &&(Board[get<1>(coordinates)+2][get<0>(coordinates)+1]=='.' || InRange((int)Board[get<1>(coordinates)+2][get<0>(coordinates)+1], (int)'A', (int)'Z'))){
            Predicthion.push_back({get<0>(coordinates)+1, get<1>(coordinates)+2, 1*!InRange((int)Board[get<1>(coordinates)+2][get<0>(coordinates)+1], (int)'A', (int)'Z')});
        }
        return Predicthion;
    }

};
vector<char> enter(){
    string move;
    char piece;

    tuple<char,char, int> t = {};
    cin>>move;
    vector<char> data(move.begin(), move.end());

    return data;
}
vector<WPawn> makeTurn(vector<char> move, vector <WPawn> piece){
    move[0] = ((int)move[0]-97);
    move[1] = 7-((int)move[1] - (int)'1');
    for (size_t i = 0; i < piece.size(); i++){
        for (size_t j = 0; j < piece[i].Predicthion.size(); j++){
            if(piece[i].Predicthion[j][0]==move[0] && piece[i].Predicthion[j][1] == move[1]){
                if (piece[i].Predicthion[j][2] == 0){
                     
                }
                get<0>(piece[i].coordinates) = move[0];
                get<1>(piece[i].coordinates) = move[1];
                return piece;
            }
        }
    }
}

vector<BPawn> makeTurn(vector<char> move, vector <BPawn> piece){
    move[0] = ((int)move[0]-97);
    move[1] = 7-((int)move[1] - (int)'1');
    for (size_t i = 0; i < piece.size(); i++){
        for (size_t j = 0; j < piece[i].Predicthion.size(); j++){
            if(piece[i].Predicthion[j][0]==move[0] && piece[i].Predicthion[j][1] == move[1]){
                get<0>(piece[i].coordinates) = move[0];
                get<1>(piece[i].coordinates) = move[1];
                return piece;
            }
        }
    }
}

vector<WRook> makeTurn(vector<char> move, vector <WRook> piece){
    move[1] = ((int)move[1]-97);
    move[2] = 7-((int)move[2] - (int)'1');
    for (size_t i = 0; i < piece.size(); i++){
        for (size_t j = 0; j < piece[i].Predicthion.size(); j++){
            if(piece[i].Predicthion[j][0]==move[1] && piece[i].Predicthion[j][1] == move[2]){
                get<0>(piece[i].coordinates) = move[1];
                get<1>(piece[i].coordinates) = move[2];
                return piece;
            }
        }
    }
}

vector<BRook> makeTurn(vector<char> move, vector <BRook> piece){
    move[1] = ((int)move[1]-97);
    move[2] = 7-((int)move[2] - (int)'1');
    for (size_t i = 0; i < piece.size(); i++){
        for (size_t j = 0; j < piece[i].Predicthion.size(); j++){
            if(piece[i].Predicthion[j][0]==move[1] && piece[i].Predicthion[j][1] == move[2]){
                get<0>(piece[i].coordinates) = move[1];
                get<1>(piece[i].coordinates) = move[2];
                return piece;
            }
        }
    }
}

vector<BKnight> makeTurn(vector<char> move, vector <BKnight> piece){
    move[1] = ((int)move[1]-97);
    move[2] = 7-((int)move[2] - (int)'1');
    for (size_t i = 0; i < piece.size(); i++){
        for (size_t j = 0; j < piece[i].Predicthion.size(); j++){
            if(piece[i].Predicthion[j][0]==move[1] && piece[i].Predicthion[j][1] == move[2]){
                get<0>(piece[i].coordinates) = move[1];
                get<1>(piece[i].coordinates) = move[2];
                return piece;
            }
        }
    }
}

vector<WKnight> makeTurn(vector<char> move, vector <WKnight> piece){
    move[1] = ((int)move[1]-97);
    move[2] = 7-((int)move[2] - (int)'1');
    for (size_t i = 0; i < piece.size(); i++){
        for (size_t j = 0; j < piece[i].Predicthion.size(); j++){
            if(piece[i].Predicthion[j][0]==move[1] && piece[i].Predicthion[j][1] == move[2]){
                get<0>(piece[i].coordinates) = move[1];
                get<1>(piece[i].coordinates) = move[2];
                return piece;
            }
        }
    }
}

tuple <vector <WPawn>, vector <WRook>, vector <WKnight>,vector <BPawn>, vector <BRook>, vector <BKnight>>  captured (vector <WPawn> WPawns, vector <WRook> WRooks, vector <WKnight> WKnights,  vector <BPawn> BPawns, vector <BRook> BRooks, vector <BKnight> BKnights, string piece ){
    tuple <vector <WPawn>, vector <WRook>, vector <WKnight>,vector <BPawn>, vector <BRook>, vector <BKnight>> a = {WPawns, WRooks, WKnights, BPawns, BRooks, BKnights};
    if (piece == "WPawn"){
        for (size_t i = 0; i < WPawns.size(); i++){
            for (size_t j = 0; j < WPawns[i].Predicthion.size(); j++){
                if (WPawns[i].Predicthion[j][2] == 0){
                     for (size_t q = 0; q < WPawns.size(); q++){
                        if (WPawns[i].Predicthion[j][0] == get<0>(BPawns[q].coordinates) && WPawns[i].Predicthion[j][1] == get<1>(BPawns[q].coordinates)){
                            BPawns.erase(BPawns.begin()+q);
                            a = {WPawns, WRooks, WKnights, BPawns, BRooks, BKnights};
                            return a;
                        }
                     }
                }
            }
        }
    }
    else if (piece == "WRook"){

    }
    else if (piece == "WKnight"){
        
    }
    else if (piece == "WBishop"){
        
    }
    else if (piece == "WQueen"){
        
    }
    else if (piece == "WKing"){
        
    }
    else if (piece == "BPawn"){

    }
    else if (piece == "BRooks"){

    }
    else if (piece == "BKnights"){
        
    }
    else if (piece == "BBishops"){
        
    }
    else if (piece == "BQueen"){
        
    }
    else if (piece == "BKing"){
        
    }
    return a;
};

vector < vector <char> > render(vector <WPawn> WPawns, vector <BPawn> BPawns, vector <WRook> WRooks, vector <BRook> BRooks,  vector<WKnight> WKnights, vector<BKnight> BKnights){
    vector < vector <char> > board = {{'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.', '.'}};
    for (size_t i = 0; i < WPawns.size(); i++)
    {
        board[get<1>(WPawns[i].coordinates)][get<0>(WPawns[i].coordinates)] = 'P';
    }
    for (size_t i = 0; i < BPawns.size(); i++){
        board[get<1>(BPawns[i].coordinates)][get<0>(BPawns[i].coordinates)] = 'p';
    }

    for (size_t i = 0; i < WRooks.size(); i++){
        board[get<1>(WRooks[i].coordinates)][get<0>(WRooks[i].coordinates)] = 'R';
    }
    
    for (size_t i = 0; i < BRooks.size(); i++){
        board[get<1>(BRooks[i].coordinates)][get<0>(WRooks[i].coordinates)] = 'r';
    }

    for (size_t i = 0; i < WKnights.size(); i++){
        board[get<1>(WKnights[i].coordinates)][get<0>(WKnights[i].coordinates)] = 'K';
    }

    for (size_t i = 0; i < BKnights.size(); i++){
        board[get<1>(BKnights[i].coordinates)][get<0>(BKnights[i].coordinates)] = 'k';
    }

    // board[get<0>(WBishops[0].coordinates)][get<1>(WBishops[0].coordinates)] = 'B';
    // board[get<0>(BBishops[0].coordinates)][get<1>(BBishops[0].coordinates)] = 'b';
    // board[get<0>(WBishops[1].coordinates)][get<1>(WBishops[1].coordinates)] = 'B';
    // board[get<0>(BBishops[1].coordinates)][get<1>(BBishops[1].coordinates)] = 'b';

    // board[get<0>(WQueen[0].coordinates)][get<1>(WQueens[0].coordinates)] = 'Q';
    // board[get<0>(BQueen[0].coordinates)][get<1>(BQueens[0].coordinates)] = 'q';

    // board[get<0>(WKing[0].coordinates)][get<1>(WKing[0].coordinates)] = '#';
    // board[get<0>(BKing[0].coordinates)][get<1>(BKing[0].coordinates)] = '@';
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            cout<<board[i][j];

        }
        cout<<endl;
        
    }
    return board;
    
    
}

int main(){
    int Turn =0;
    vector<char> move = {};
    tuple<vector <vector<vector<vector<int>>>>, vector <vector<vector<vector<int>>>>> tp;
    

    vector <vector<vector<vector<int>>>> black = {{{{0, 1}}, {{1,1}}, {{2,1}}, {{3,1}}, {{4,1}}, {{5,1}}, {{6,1}}, {{7,1}}, {{0,0}}, {{1,0}}, {{2,0}}, {{3,0}}, {{4,0}}, {{5,0}}, {{6,0}}, {{7,0}}},
                                             {{{0, 2},{0,3}}, {{1,2}, {1,3}}, {{2,2}, {2,3}}, {{3,2},{3,3}}, {{4,2},{4,3}}, {{5,2},{5,3}}, {{6,2},{6,3}}, {{7,2},{7,3}}, {{-1}}, {{0,2},{2,2}}, {{-1}}, {{-1}}, {{-1}}, {{-1}}, {{5,2},{7,2}}, {{-1}}}};

    vector <vector<vector<vector<int>>>> white = {{{{0, 6}}, {{1,6}}, {{2,6}}, {{3,6}}, {{4,6}}, {{5,6}}, {{6,6}}, {{7,6}}, {{0,7}}, {{1,7}}, {{2,7}}, {{3,7}}, {{4,7}}, {{5,7}}, {{6,7}}, {{7,7}}},
                                             {{{0, 5},{0,4}}, {{1,5}, {1,4}}, {{2,5}, {2,4}}, {{3,5},{3,4}}, {{4,5},{4,4}}, {{5,5},{5,4}}, {{6,5},{6,4}}, {{7,5},{7,4}}, {{-1}}, {{0,5},{2,5}}, {{-1}}, {{-1}}, {{-1}}, {{-1}}, {{5,5},{7,5}}, {{-1}}}};

    WPawn P1, P2, P3, P4, P5, P6, P7, P8;
    vector<WPawn> WPawns = {P1, P2, P3, P4, P5, P6, P7, P8};
    BPawn p1, p2, p3, p4, p5, p6, p7, p8;
    vector<BPawn> BPawns = {p1,p2,p3,p4,p5,p6,p7,p8} ;
    for (int i =0; i<8; i++){
        WPawns[i].coordinates = {i, 6};
        WPawns[i].Predicthion = {{i, 5}, {i, 4}};
    }   
    for (int i =0; i<8; i++){
        BPawns[i].coordinates = {i, 1};
        BPawns[i].Predicthion = {{i, 5}, {i, 4}};
    }  
    WRook R1, R2; BRook r1,r2;
    vector <WRook> WRooks = {R1, R2}; WRooks[0].coordinates = {0,7}; WRooks[1].coordinates = {7,7};
    vector <BRook> BRooks = {r1, r2}; BRooks[0].coordinates = {0,0}; BRooks[1].coordinates = {7,0};
    WKnight K1, K2; BKnight k1,k2;
    vector <WKnight> WKnights = {K1, K2}; WKnights[0].coordinates = {1,7}; WKnights[1].coordinates = {6,7};
    vector <BKnight> BKnights = {k1, k2}; BKnights[0].coordinates = {1,0}; BKnights[1].coordinates = {6,0};
    vector<vector<char>> board;
    tuple <vector <WPawn>, vector <WRook>, vector <WKnight>,vector <BPawn>, vector <BRook>, vector <BKnight>> a;
    board = render(WPawns, BPawns, WRooks, BRooks, WKnights, BKnights);
    while(true){
        
        
        move= enter();
        if (Turn ==0){
            if (move.size() ==2){
                a = captured(WPawns, WRooks, WKnights, BPawns, BRooks, BKnights, "WPawn");
                BPawns = get<3>(a);
                WPawns = makeTurn(move, WPawns);
            }
            else{
                if (move[0] == 'R'){
                    a = captured(WPawns, WRooks, WKnights, BPawns, BRooks, BKnights, "WRook");
                    WRooks = get<1>(a);
                    WRooks = makeTurn(move, WRooks);
                }
                else if (move[0] == 'K'){
                    a = captured(WPawns, WRooks, WKnights, BPawns, BRooks, BKnights, "WKnight");
                    WKnights = get<2>(a);
                    WKnights = makeTurn(move, WKnights);
                }
            }
        }
        else{
            if (move.size() ==2){
                a = captured(WPawns, WRooks, WKnights, BPawns, BRooks, BKnights, "BPawn");
                BPawns = get<3>(a);
                BPawns = makeTurn(move, BPawns);
            }
            else{
                if (move[0] == 'R'){
                    a = captured(WPawns, WRooks, WKnights, BPawns, BRooks, BKnights, "BRook");
                    BRooks = get<4>(a);
                    BRooks = makeTurn(move, BRooks);
                }
                else if (move[0] == 'K'){
                    a = captured(WPawns, WRooks, WKnights, BPawns, BRooks, BKnights, "BKnight");
                    BKnights = get<5>(a);
                    BKnights = makeTurn(move, BKnights);
                }
            }
        }
        board = render(WPawns, BPawns, WRooks, BRooks, WKnights, BKnights);
        for (int i =0; i < WPawns.size(); i++){
            WPawns[i].Predicthion = WPawns[i].predicthion(WPawns[i].coordinates, board);
        }
        for (int i =0; i < BPawns.size(); i++){
            BPawns[i].Predicthion = BPawns[i].predicthion(BPawns[i].coordinates, board);
        }
        // tp = PawnsPredicthion(black, white, 0, move);  
        // white = get<0>(tp);
        // black = get<1>(tp);
        for (int i =0; i <WRooks.size(); i++){
            WRooks[i].Predicthion = WRooks[i].predicthion(WRooks[i].coordinates, board);
        }
        for (int i =0; i <BRooks.size(); i++){
            BRooks[i].Predicthion = BRooks[i].predicthion(BRooks[i].coordinates, board);
        }
        // tp = RooksPredicthion(black, white, 0, move);  
        // white = get<0>(tp);
        // black = get<1>(tp);
        for (int i =0; i <WKnights.size(); i++){
            WKnights[i].Predicthion = WKnights[i].predicthion(WKnights[i].coordinates, board);
        }
        for (int i =0; i <BKnights.size(); i++){
            BKnights[i].Predicthion = BKnights[i].predicthion(BKnights[i].coordinates, board);
        }
        // tp = KnightPredicthion(black, white, 0, move);  
        // white = get<0>(tp);
        // black = get<1>(tp);
        Turn = (Turn +1)%2;
        }
        
    return 1;
}
