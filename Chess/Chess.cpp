#include<vector>
#include<iostream>
#include <tuple>
#include <math.h>
using namespace std;

bool InRange(int a, int b, int c) {
    if(b <=c){
        if (a >= b && a <= c) {
            return true;
        }
        else {
            return false;
        }   
    }
    else{
        if (a <= b && a >= c) {
            return true;
        }
        else {
            return false;
        }   
    }
}
class WPawn; class WRook; class WKnight; class WBishop; class WQueen; class WKing;
class BPawn; class BRook; class BKnight; class BBishop; class BQueen; class BKing;
class WPawn
{
public:
    tuple<int, int> coordinates = { 0,6 };
    vector<vector<int>> Predicthion = { {0,5, 1}, {0,4, 1} };
    tuple<vector<vector<int>>, vector<vector<char>>> predicthion(tuple<int, int> coordinates, vector<vector<char>> Board, vector<vector<char>> BDead) {
        vector<vector<int>> Predicthion;
        tuple<vector<vector<int>>, vector<vector<char>>> a;
        if (get<1>(coordinates) == 6 && Board[get<1>(coordinates) - 2][get<0>(coordinates)] == '.') {
            Predicthion.push_back({ get<0>(coordinates), get<1>(coordinates) - 2 });
        }
        if (get<1>(coordinates) - 1 >= 0 && Board[get<1>(coordinates) - 1][get<0>(coordinates)] == '.') {
            Predicthion.push_back({ get<0>(coordinates), get<1>(coordinates) - 1 });
        }
        if ((get<1>(coordinates) - 1 >= 0 && get<0>(coordinates) - 1 >= 0) && InRange((int)Board[get<1>(coordinates) - 1][get<0>(coordinates) - 1], (int)'a', (int)'z')) {
            Predicthion.push_back({ {get<0>(coordinates) - 1, get<1>(coordinates) - 1} });
        }
        else if((get<1>(coordinates) - 1 >= 0 && get<0>(coordinates) - 1 >= 0) && InRange((int)Board[get<1>(coordinates) - 1][get<0>(coordinates) - 1], (int)'A', (int)'Z'))
        {
            BDead[get<1>(coordinates)][get<0>(coordinates)] = 'X';
        }
        if ((get<1>(coordinates) - 1 >= 0 && get<0>(coordinates) + 1 <= 7) && InRange((int)Board[get<1>(coordinates) - 1][get<0>(coordinates) + 1], (int)'a', (int)'z')) {
            Predicthion.push_back({ {get<0>(coordinates) + 1, get<1>(coordinates) - 1} });
        }
        else if((get<1>(coordinates) - 1 >= 0 && get<0>(coordinates) + 1 <=7) && InRange((int)Board[get<1>(coordinates) - 1][get<0>(coordinates) + 1], (int)'A', (int)'Z'))
        {
            BDead[get<1>(coordinates)][get<0>(coordinates)] = 'X';
        }
        a = {Predicthion, BDead};
        return a;
    }


};

class BPawn {
private:

public:
    tuple<int, int> coordinates = { 0,1 };
    vector<vector<int>> Predicthion = { {0,2}, {0,3} };
    tuple<vector<vector<int>>, vector<vector<char>>> predicthion(tuple<int, int> coordinates, vector<vector<char>> Board, vector<vector<char>> WDead) {
        vector<vector<int>> Predicthion;
        tuple<vector<vector<int>>, vector<vector<char>>> a;
        if (get<1>(coordinates) == 1 && Board[get<1>(coordinates) + 2][get<0>(coordinates)] == '.') {
            Predicthion.push_back({ get<0>(coordinates), get<1>(coordinates) + 2 });
        }
        if (get<1>(coordinates) + 1 <= 7 && Board[get<1>(coordinates) + 1][get<0>(coordinates)] == '.') {
            Predicthion.push_back({ get<0>(coordinates), get<1>(coordinates) + 1 });
        }
        if ((get<1>(coordinates) + 1 <= 7 && get<0>(coordinates) - 1 >= 0) && InRange((int)Board[get<1>(coordinates) + 1][get<0>(coordinates) - 1], (int)'A', (int)'Z')) {
            Predicthion.push_back({ {get<0>(coordinates) - 1, get<1>(coordinates) + 1} });
        }
        else if((get<1>(coordinates) + 1 <= 7 && get<0>(coordinates) - 1 >= 0) && InRange((int)Board[get<1>(coordinates) - 1][get<0>(coordinates) - 1], (int)'a', (int)'z'))
        {
            WDead[get<1>(coordinates)][get<0>(coordinates)] = 'X';
        }
        if ((get<0>(coordinates) + 1 <= 7 && get<1>(coordinates) + 1 <= 7) && InRange((int)Board[get<1>(coordinates) + 1][get<0>(coordinates) + 1], (int)'A', (int)'Z')) {
            Predicthion.push_back({ {get<0>(coordinates) + 1, get<1>(coordinates) + 1} });
        }
        else if((get<1>(coordinates) + 1 <= 7 && get<0>(coordinates) + 1 <=7) && InRange((int)Board[get<1>(coordinates) - 1][get<0>(coordinates) + 1], (int)'a', (int)'z'))
        {
            WDead[get<1>(coordinates)][get<0>(coordinates)] = 'X';
        }
        a = {Predicthion, WDead};
        return a;
    }
};

class WRook {
public:
    tuple<int, int> coordinates = { 0,0 };
    vector<vector<int>> Predicthion;
    tuple<vector<vector<int>>, vector<vector<char>>> predicthion(tuple<int, int> coordinates, vector<vector<char>> Board, vector<vector<char>> BDead) {
        vector<vector<int>> Predicthion;
        tuple<vector<vector<int>>, vector<vector<char>>> a;
        for (int i = 1; i < 8; i++) {
            if (get<0>(coordinates) - i < 0) {
                break;
            }
            if (InRange(Board[get<1>(coordinates)][get<0>(coordinates) - i], (int)'a', (int)'z')) {
                Predicthion.push_back({ get<0>(coordinates) - i, get<1>(coordinates) });
                break;
            }
            if (InRange(Board[get<1>(coordinates)][get<0>(coordinates) - i], (int)'A', (int)'Z') || Board[get<1>(coordinates)][get<0>(coordinates) - i] == '@' || Board[get<1>(coordinates)][get<0>(coordinates) - i] == '#') {
                BDead[get<1>(coordinates)][get<0>(coordinates) - i] = 'X';
                break;
            }
            if (Board[get<1>(coordinates)][get<0>(coordinates) - i] == '.') {
                BDead[get<1>(coordinates)][get<0>(coordinates) - i] = 'X';
                Predicthion.push_back({ get<0>(coordinates) - i, get<1>(coordinates) });
            }

        }
        for (int i = 1; i < 8; i++) {
            if (get<0>(coordinates) + i > 7) {
                break;
            }
            if (InRange(Board[get<1>(coordinates)][get<0>(coordinates) + i], (int)'a', (int)'z')) {
                Predicthion.push_back({ get<0>(coordinates) + i, get<1>(coordinates) });
                break;
            }
            if (InRange(Board[get<1>(coordinates)][get<0>(coordinates) + i], (int)'A', (int)'Z') || Board[get<1>(coordinates)][get<0>(coordinates) + i] == '@' || Board[get<1>(coordinates)][get<0>(coordinates) + i] == '#') {
                BDead[get<1>(coordinates)][get<0>(coordinates) + i] = 'X';
                break;
            }
            if (Board[get<1>(coordinates)][get<0>(coordinates) + i] == '.') {
                BDead[get<1>(coordinates)][get<0>(coordinates) + i] = 'X';
                Predicthion.push_back({ get<0>(coordinates) + i, get<1>(coordinates) });
            }

        }
        for (int i = 1; i < 8; i++) {
            if (get<1>(coordinates) - i < 0) {
                break;
            }
            if (InRange(Board[get<1>(coordinates) - i][get<0>(coordinates)], (int)'a', (int)'z')) {
                Predicthion.push_back({ get<0>(coordinates), get<1>(coordinates) - i });
                break;
            }
            if (InRange(Board[get<1>(coordinates) - i][get<0>(coordinates)], (int)'A', (int)'Z') || Board[get<1>(coordinates) - i][get<0>(coordinates)] == '@' || Board[get<1>(coordinates) - i][get<0>(coordinates)] == '#') {
                BDead[get<1>(coordinates)-i][get<0>(coordinates)] = 'X';
                break;
            }
            if (Board[get<1>(coordinates) - i][get<0>(coordinates)] == '.') {
                BDead[get<1>(coordinates) - i][get<0>(coordinates)] = 'X';
                Predicthion.push_back({ get<0>(coordinates), get<1>(coordinates) - i });
            }

        }
        for (int i = 1; i < 8; i++) {
            if (get<1>(coordinates) + i > 7) {
                break;
            }
            if (InRange(Board[get<1>(coordinates) + i][get<0>(coordinates)], (int)'a', (int)'z')) {
                Predicthion.push_back({ get<0>(coordinates), get<1>(coordinates) + i });
                break;
            }
            if (InRange(Board[get<1>(coordinates) + i][get<0>(coordinates)], (int)'A', (int)'Z') || Board[get<1>(coordinates) + i][get<0>(coordinates)] == '@' || Board[get<1>(coordinates) + i][get<0>(coordinates)] == '#') {
                BDead[get<1>(coordinates)+i][get<0>(coordinates)] = 'X';
                break;
            }
            if (Board[get<1>(coordinates) + i][get<0>(coordinates)] == '.') {
                BDead[get<1>(coordinates)+i][get<0>(coordinates)] = 'X';
                Predicthion.push_back({ get<0>(coordinates), get<1>(coordinates) + i });
            }

        }
        a = {Predicthion, BDead};
        return a;
    }
};

class BRook {
public:
    tuple<int, int> coordinates = { 0,0 };
    vector<vector<int>> Predicthion;
    tuple<vector<vector<int>>, vector<vector<char>>> predicthion(tuple<int, int> coordinates, vector<vector<char>> Board, vector<vector<char>> WDead) {
        vector<vector<int>> Predicthion;
        tuple<vector<vector<int>>, vector<vector<char>>> a;
        for (int i = 1; i < 8; i++) {
            if (get<0>(coordinates) - i < 0) {
                break;
            }
            if (InRange(Board[get<1>(coordinates)][get<0>(coordinates) - i], (int)'A', (int)'Z')) {
                Predicthion.push_back({ get<0>(coordinates) - i, get<1>(coordinates) });
                break;
            }
            if (InRange(Board[get<1>(coordinates)][get<0>(coordinates) - i], (int)'a', (int)'z') || Board[get<1>(coordinates)][get<0>(coordinates) - i] == '@' || Board[get<1>(coordinates)][get<0>(coordinates) - i] == '#') {
                WDead[get<1>(coordinates)][get<0>(coordinates) - i] = 'X';
                break;
            }
            if (Board[get<1>(coordinates)][get<0>(coordinates) - i] == '.') {
                WDead[get<1>(coordinates)][get<0>(coordinates) - i] = 'X';
                Predicthion.push_back({ get<0>(coordinates) - i, get<1>(coordinates) });
            }

        }
        for (int i = 1; i < 8; i++) {
            if (get<0>(coordinates) + i > 7) {
                break;
            }
            if (InRange(Board[get<1>(coordinates)][get<0>(coordinates) + i], (int)'A', (int)'Z')) {
                Predicthion.push_back({ get<0>(coordinates) + i, get<1>(coordinates) });
                break;
            }
            if (InRange(Board[get<1>(coordinates)][get<0>(coordinates) + i], (int)'a', (int)'z') || Board[get<1>(coordinates)][get<0>(coordinates) + i] == '@' || Board[get<1>(coordinates)][get<0>(coordinates) + i] == '#') {
                WDead[get<1>(coordinates)][get<0>(coordinates) + i] = 'X';
                break;
            }
            if (Board[get<1>(coordinates)][get<0>(coordinates) + i] == '.') {
                WDead[get<1>(coordinates)][get<0>(coordinates) + i] = 'X';
                Predicthion.push_back({ get<0>(coordinates) + i, get<1>(coordinates) });
            }

        }
        for (int i = 1; i < 8; i++) {
            if (get<1>(coordinates) - i < 0) {
                break;
            }
            if (InRange(Board[get<1>(coordinates) - i][get<0>(coordinates)], (int)'A', (int)'Z')) {
                Predicthion.push_back({ get<0>(coordinates), get<1>(coordinates) - i });
                break;
            }
            if (InRange(Board[get<1>(coordinates) - i][get<0>(coordinates)], (int)'a', (int)'z') || Board[get<1>(coordinates) - i][get<0>(coordinates)] == '@' || Board[get<1>(coordinates) - i][get<0>(coordinates)] == '#') {
                WDead[get<1>(coordinates)-i][get<0>(coordinates)] = 'X';
                break;
            }
            if (Board[get<1>(coordinates) - i][get<0>(coordinates)] == '.') {
                WDead[get<1>(coordinates)-i][get<0>(coordinates)] = 'X';
                Predicthion.push_back({ get<0>(coordinates), get<1>(coordinates) - i });
            }

        }
        for (int i = 1; i < 8; i++) {
            if (get<1>(coordinates) + i > 7) {
                break;
            }
            if (InRange(Board[get<1>(coordinates) + i][get<0>(coordinates)], (int)'A', (int)'Z')) {
                Predicthion.push_back({ get<1>(coordinates), get<0>(coordinates) + i });
                break;
            }
            if (InRange(Board[get<1>(coordinates) + i][get<0>(coordinates)], (int)'a', (int)'z') || Board[get<1>(coordinates) + i][get<0>(coordinates)] == '@' || Board[get<1>(coordinates) + i][get<0>(coordinates)] == '#') {
                WDead[get<1>(coordinates)+i][get<0>(coordinates)] = 'X';
                break;
            }
            if (Board[get<1>(coordinates) + i][get<0>(coordinates)] == '.') {
                WDead[get<1>(coordinates)+i][get<0>(coordinates)] = 'X';
                Predicthion.push_back({ get<0>(coordinates), get<1>(coordinates) + i });
            }

        }
        a = {Predicthion, WDead};
        return a;
    }
};

class WKnight {
public:
    tuple<int, int> coordinates = { 0,0 };
    vector<vector<int>> Predicthion;
    tuple<vector<vector<int>>, vector<vector<char>>> predicthion(tuple<int, int> coordinates, vector<vector<char>> Board, vector<vector<char>> BDead) {
        vector<vector<int>> Predicthion;
        tuple<vector<vector<int>>, vector<vector<char>>> a;
        if ((get<1>(coordinates) - 1 >= 0 && get<0>(coordinates) - 2 >= 0) && (Board[get<1>(coordinates) - 1][get<0>(coordinates) - 2] == '.' || InRange((int)Board[get<1>(coordinates) - 1][get<0>(coordinates) - 2], (int)'a', (int)'z'))) {
            Predicthion.push_back({ get<0>(coordinates) - 2, get<1>(coordinates) - 1 });
        }
        if ((get<1>(coordinates) + 1 <= 7 && get<0>(coordinates) - 2 >= 0) && (Board[get<1>(coordinates) + 1][get<0>(coordinates) - 2] == '.' || InRange((int)Board[get<1>(coordinates) + 1][get<0>(coordinates) - 2], (int)'a', (int)'z'))) {
            Predicthion.push_back({ get<0>(coordinates) - 2, get<1>(coordinates) + 1 });
        }
        if ((get<1>(coordinates) - 1 >= 0 && get<0>(coordinates) + 2 <= 7) && (Board[get<1>(coordinates) - 1][get<0>(coordinates) + 2] == '.' || InRange((int)Board[get<1>(coordinates) - 1][get<0>(coordinates) + 2], (int)'a', (int)'z'))) {
            Predicthion.push_back({ get<0>(coordinates) + 2, get<1>(coordinates) - 1 });
        }
        if ((get<1>(coordinates) + 1 <= 7 && get<0>(coordinates) + 2 <= 7) && (Board[get<1>(coordinates) + 1][get<0>(coordinates) + 2] == '.' || InRange((int)Board[get<1>(coordinates) + 1][get<0>(coordinates) + 2], (int)'a', (int)'z'))) {
            Predicthion.push_back({ get<0>(coordinates) + 2, get<1>(coordinates) + 1 });
        }
        if ((get<1>(coordinates) - 2 >= 0 && get<0>(coordinates) - 1 >= 0) && (Board[get<1>(coordinates) - 2][get<0>(coordinates) - 1] == '.' || InRange((int)Board[get<1>(coordinates) - 2][get<0>(coordinates) - 1], (int)'a', (int)'z'))) {
            Predicthion.push_back({ get<0>(coordinates) - 1, get<1>(coordinates) - 2 });
        }
        if ((get<1>(coordinates) - 2 >= 0 && get<0>(coordinates) + 1 <= 7) && (Board[get<1>(coordinates) - 2][get<0>(coordinates) + 1] == '.' || InRange((int)Board[get<1>(coordinates) - 2][get<0>(coordinates) + 1], (int)'a', (int)'z'))) {
            Predicthion.push_back({ get<0>(coordinates) + 1, get<1>(coordinates) - 2 });
        }
        if ((get<1>(coordinates) + 2 <= 7 && get<0>(coordinates) - 1 >= 0) && (Board[get<1>(coordinates) + 2][get<0>(coordinates) - 1] == '.' || InRange((int)Board[get<1>(coordinates) + 2][get<0>(coordinates) - 1], (int)'a', (int)'z'))) {
            Predicthion.push_back({ get<0>(coordinates) - 1, get<1>(coordinates) + 2 });
        }
        if ((get<1>(coordinates) + 2 <= 7 && get<0>(coordinates) + 1 <= 7) && (Board[get<1>(coordinates) + 2][get<0>(coordinates) + 1] == '.' || InRange((int)Board[get<1>(coordinates) + 2][get<0>(coordinates) + 1], (int)'a', (int)'z'))) {
            Predicthion.push_back({ get<0>(coordinates) + 1, get<1>(coordinates) + 2 });
        }
       
        if (get<1>(coordinates) - 1 >= 0 && get<0>(coordinates) - 2 >= 0){
            BDead[get<1>(coordinates)-1][get<0>(coordinates) - 2] = 'X';
        }
        if (get<1>(coordinates) + 1 <= 7 && get<0>(coordinates) - 2 >= 0){
            BDead[get<1>(coordinates)+1][get<0>(coordinates) - 2] = 'X';
        }
        if (get<1>(coordinates) - 1 >= 0 && get<0>(coordinates) + 2 <= 7){
            BDead[get<1>(coordinates)-1][get<0>(coordinates) + 2] = 'X';
        }
        if (get<1>(coordinates) + 1 <= 7 && get<0>(coordinates) + 2 <= 7){
            BDead[get<1>(coordinates)+1][get<0>(coordinates) + 2] = 'X';
        }
        if (get<1>(coordinates) - 2 >= 0 && get<0>(coordinates) - 1 >= 0){
            BDead[get<1>(coordinates)-2][get<0>(coordinates) - 1] = 'X';
        }
        if (get<1>(coordinates) + 2 <= 7 && get<0>(coordinates) - 1 >= 0){
            BDead[get<1>(coordinates)+2][get<0>(coordinates) - 1] = 'X';
        }
        if (get<1>(coordinates) - 2 >=0 && get<0>(coordinates) - 1 >= 0){
            BDead[get<1>(coordinates)-2][get<0>(coordinates) + 1] = 'X';
        }
        if (get<1>(coordinates) + 2 <= 7 && get<0>(coordinates) + 1 <= 7){
            BDead[get<1>(coordinates)+2][get<0>(coordinates) + 1] = 'X';
        }
        a = {Predicthion, BDead};
        return a;
    }

};

class BKnight {
public:
    tuple<int, int> coordinates = { 0,0 };
    vector<vector<int>> Predicthion;
    tuple<vector<vector<int>>, vector<vector<char>>> predicthion(tuple<int, int> coordinates, vector<vector<char>> Board, vector<vector<char>> WDead) {
        vector<vector<int>> Predicthion;
        tuple<vector<vector<int>>, vector<vector<char>>> a;
        if ((get<1>(coordinates) - 1 >= 0 && get<0>(coordinates) - 2 >= 0) && (Board[get<1>(coordinates) - 1][get<0>(coordinates) - 2] == '.' || InRange((int)Board[get<1>(coordinates) - 1][get<0>(coordinates) - 2], (int)'A', (int)'Z'))) {
            Predicthion.push_back({ get<0>(coordinates) - 2, get<1>(coordinates) - 1 });
        }
        if ((get<1>(coordinates) + 1 <= 7 && get<0>(coordinates) - 2 >= 0) && (Board[get<1>(coordinates) + 1][get<0>(coordinates) - 2] == '.' || InRange((int)Board[get<1>(coordinates) + 1][get<0>(coordinates) - 2], (int)'A', (int)'Z'))) {
            Predicthion.push_back({ get<0>(coordinates) - 2, get<1>(coordinates) + 1 });
        }
        if ((get<1>(coordinates) - 1 >= 0 && get<0>(coordinates) + 2 <= 7) && (Board[get<1>(coordinates) - 1][get<0>(coordinates) + 2] == '.' || InRange((int)Board[get<1>(coordinates) - 1][get<0>(coordinates) + 2], (int)'A', (int)'Z'))) {
            Predicthion.push_back({ get<0>(coordinates) + 2, get<1>(coordinates) - 1 });
        }
        if ((get<0>(coordinates) + 2 <= 7 && get<1>(coordinates) + 1 <= 7) && (Board[get<1>(coordinates) + 1][get<0>(coordinates) + 2] == '.' || InRange((int)Board[get<1>(coordinates) + 1][get<0>(coordinates) + 2], (int)'A', (int)'Z'))) {
            Predicthion.push_back({ get<0>(coordinates) + 2, get<1>(coordinates) + 1 });
        }

        if ((get<1>(coordinates) - 2 >= 0 && get<0>(coordinates) - 1 >= 0) && (Board[get<1>(coordinates) - 2][get<0>(coordinates) - 1] == '.' || InRange((int)Board[get<1>(coordinates) - 2][get<0>(coordinates) - 1], (int)'A', (int)'Z'))) {
            Predicthion.push_back({ get<0>(coordinates) - 1, get<1>(coordinates) - 2 });
        }
        if ((get<1>(coordinates) - 2 >= 0 && get<0>(coordinates) + 1 <= 7) && (Board[get<1>(coordinates) - 2][get<0>(coordinates) + 1] == '.' || InRange((int)Board[get<1>(coordinates) - 2][get<0>(coordinates) + 1], (int)'A', (int)'Z'))) {
            Predicthion.push_back({ get<0>(coordinates) + 1, get<1>(coordinates) - 2 });
        }
        if ((get<1>(coordinates) + 2 <= 7 && get<0>(coordinates) - 1 >= 0) && (Board[get<1>(coordinates) + 2][get<0>(coordinates) - 1] == '.' || InRange((int)Board[get<1>(coordinates) + 2][get<0>(coordinates) - 1], (int)'A', (int)'Z'))) {
            Predicthion.push_back({ get<0>(coordinates) - 1, get<1>(coordinates) + 2 });
        }
        if ((get<1>(coordinates) + 2 <= 7 && get<0>(coordinates) + 1 <= 7) && (Board[get<1>(coordinates) + 2][get<0>(coordinates) + 1] == '.' || InRange((int)Board[get<1>(coordinates) + 2][get<0>(coordinates) + 1], (int)'A', (int)'Z'))) {
            Predicthion.push_back({ get<0>(coordinates) + 1, get<1>(coordinates) + 2 });
        }

        if (get<1>(coordinates) - 1 >= 0 && get<0>(coordinates) - 2 >= 0){
            WDead[get<1>(coordinates)-1][get<0>(coordinates) - 2] = 'X';
        }
        if (get<1>(coordinates) + 1 <= 7 && get<0>(coordinates) - 2 >= 0){
            WDead[get<1>(coordinates)+1][get<0>(coordinates) - 2] = 'X';
        }
        if (get<1>(coordinates) - 1 >= 0 && get<0>(coordinates) + 2 <= 7){
            WDead[get<1>(coordinates)-1][get<0>(coordinates) + 2] = 'X';
        }
        if (get<1>(coordinates) + 1 <= 7 && get<0>(coordinates) + 2 <= 7){
            WDead[get<1>(coordinates)+1][get<0>(coordinates) + 2] = 'X';
        }
        if (get<1>(coordinates) - 2 >= 0 && get<0>(coordinates) - 1 >= 0){
            WDead[get<1>(coordinates)-2][get<0>(coordinates) - 1] = 'X';
        }
        if (get<1>(coordinates) + 2 <= 7 && get<0>(coordinates) - 1 >= 0){
            WDead[get<1>(coordinates)+2][get<0>(coordinates) - 1] = 'X';
        }
        if (get<1>(coordinates) - 2 >=0 && get<0>(coordinates) - 1 >= 0){
            WDead[get<1>(coordinates)-2][get<0>(coordinates) + 1] = 'X';
        }
        if (get<1>(coordinates) + 2 <= 7 && get<0>(coordinates) + 1 <= 7){
            WDead[get<1>(coordinates)+2][get<0>(coordinates) + 1] = 'X';
        }
        a = {Predicthion, WDead};
        return a;
    }

};

class WBishop {
public:
    tuple<int, int> coordinates = { 0,0 };
    vector<vector<int>> Predicthion;
    tuple<vector<vector<int>>, vector<vector<char>>> predicthion(tuple<int, int> coordinates, vector<vector<char>> Board, vector<vector<char>> BDead) {
        vector<vector<int>> Predicthion;
        tuple<vector<vector<int>>, vector<vector<char>>> a;
        for (int i = 1; i < 8; i++) {
            if (get<0>(coordinates) - i < 0 || get<1>(coordinates) - i < 0) {
                break;
            }
            if (InRange(Board[get<1>(coordinates) - i][get<0>(coordinates) - i], (int)'a', (int)'z')) {
                Predicthion.push_back({ get<0>(coordinates) - i, get<1>(coordinates) - i });
                break;
            }
            if (InRange(Board[get<1>(coordinates) - i][get<0>(coordinates) - i], (int)'A', (int)'Z') || Board[get<1>(coordinates) - i][get<0>(coordinates) - i] == '@' || Board[get<1>(coordinates) - i][get<0>(coordinates) - i] == '#') {
                BDead[get<1>(coordinates)-i][get<0>(coordinates)-i] = 'X';
                break;
            }
            if (Board[get<1>(coordinates) - i][get<0>(coordinates) - i] == '.') {
                BDead[get<1>(coordinates)-i][get<0>(coordinates)-i] = 'X';
                Predicthion.push_back({ get<0>(coordinates) - i, get<1>(coordinates) - i });
            }

        }
        for (int i = 1; i < 8; i++) {
            if (get<0>(coordinates) + i > 7 || get<1>(coordinates) - i < 0) {
                break;
            }
            if (InRange(Board[get<1>(coordinates) - i][get<0>(coordinates) + i], (int)'a', (int)'z')) {
                Predicthion.push_back({ get<0>(coordinates) + i, get<1>(coordinates) - i });
                break;
            }
            if (InRange(Board[get<1>(coordinates) - i][get<0>(coordinates) + i], (int)'A', (int)'Z') || Board[get<1>(coordinates) - i][get<0>(coordinates) + i] == '@' || Board[get<1>(coordinates) - i][get<0>(coordinates) + i] == '#') {
                BDead[get<1>(coordinates)-i][get<0>(coordinates)+i] = 'X';
                break;
            }
            if (Board[get<1>(coordinates) - i][get<0>(coordinates) + i] == '.') {
                BDead[get<1>(coordinates)-i][get<0>(coordinates)+i] = 'X';
                Predicthion.push_back({ get<0>(coordinates) + i, get<1>(coordinates) - i });
            }

        }
        for (int i = 1; i < 8; i++) {
            if (get<1>(coordinates) + i > 7 || get<0>(coordinates) + i > 7) {
                break;
            }
            if (InRange(Board[get<1>(coordinates) + i][get<0>(coordinates) + i], (int)'a', (int)'z')) {
                Predicthion.push_back({ get<0>(coordinates) + i, get<1>(coordinates) + i });
                break;
            }
            if (InRange(Board[get<1>(coordinates) + i][get<0>(coordinates) + i], (int)'A', (int)'Z') || Board[get<1>(coordinates) + i][get<0>(coordinates) + i] == '@' || Board[get<1>(coordinates) + i][get<0>(coordinates) + i] == '#') {
                BDead[get<1>(coordinates)+i][get<0>(coordinates)+i] = 'X';
                break;
            }
            if (Board[get<1>(coordinates) + i][get<0>(coordinates) + i] == '.') {
                BDead[get<1>(coordinates)+i][get<0>(coordinates)+i] = 'X';
                Predicthion.push_back({ get<0>(coordinates) + i, get<1>(coordinates) + i });
            }

        }
        for (int i = 1; i < 8; i++) {
            if (get<1>(coordinates) + i > 7 || get<0>(coordinates) - i < 0) {
                break;
            }
            if (InRange(Board[get<1>(coordinates) + i][get<0>(coordinates) - i], (int)'a', (int)'z')) {
                Predicthion.push_back({ get<0>(coordinates) - i, get<1>(coordinates) + i });
                break;
            }
            if (InRange(Board[get<1>(coordinates) + i][get<0>(coordinates) - i], (int)'A', (int)'Z') || Board[get<1>(coordinates) + i][get<0>(coordinates) - i] == '@' || Board[get<1>(coordinates) + i][get<0>(coordinates) - i] == '#') {
                BDead[get<1>(coordinates)+i][get<0>(coordinates)-i] = 'X';
                break;
            }
            if (Board[get<1>(coordinates) + i][get<0>(coordinates) - i] == '.') {
                BDead[get<1>(coordinates)+i][get<0>(coordinates)-i] = 'X';
                Predicthion.push_back({ get<0>(coordinates) - i, get<1>(coordinates) + i });
            }

        }
        a = {Predicthion, BDead};
        return a;
    }
};

class BBishop {
public:
    tuple<int, int> coordinates = { 0,0 };
    vector<vector<int>> Predicthion;
    tuple<vector<vector<int>>, vector<vector<char>>> predicthion(tuple<int, int> coordinates, vector<vector<char>> Board, vector<vector<char>> WDead) {
        vector<vector<int>> Predicthion;
        tuple<vector<vector<int>>, vector<vector<char>>> a;
        for (int i = 1; i < 8; i++) {
            if (get<1>(coordinates) - i < 0 || get<0>(coordinates) - i < 0) {
                break;
            }
            if (InRange(Board[get<1>(coordinates) - i][get<0>(coordinates) - i], (int)'A', (int)'Z')) {
                Predicthion.push_back({ get<0>(coordinates) - i, get<1>(coordinates) - i });
                break;
            }
            if (InRange(Board[get<1>(coordinates) - i][get<0>(coordinates) - i], (int)'a', (int)'z') || Board[get<1>(coordinates) - i][get<0>(coordinates) - i] == '@' || Board[get<1>(coordinates) - i][get<0>(coordinates) - i] == '#') {
                WDead[get<1>(coordinates) - i][get<0>(coordinates) - i] = 'X';
                break;
            }
            if (Board[get<1>(coordinates) - i][get<0>(coordinates) - i] == '.') {
                WDead[get<1>(coordinates) - i][get<0>(coordinates) - i] = 'X';
                Predicthion.push_back({ get<0>(coordinates) - i, get<1>(coordinates) - i });
            }

        }
        for (int i = 1; i < 8; i++) {
            if (get<1>(coordinates) - i < 0 || get<0>(coordinates) + i >7) {
                break;
            }
            if (InRange(Board[get<1>(coordinates) - i][get<0>(coordinates) + i], (int)'A', (int)'Z')) {
                Predicthion.push_back({ get<0>(coordinates) + i, get<1>(coordinates) - i });
                break;
            }
            if (InRange(Board[get<1>(coordinates) - i][get<0>(coordinates) + i], (int)'a', (int)'z') || Board[get<1>(coordinates) - i][get<0>(coordinates) + i] == '@' || Board[get<1>(coordinates) - i][get<0>(coordinates) + i] == '#') {
                WDead[get<1>(coordinates) - i][get<0>(coordinates) + i] = 'X';
                break;
            }
            if (Board[get<1>(coordinates) - i][get<0>(coordinates) + i] == '.') {
                WDead[get<1>(coordinates) - i][get<0>(coordinates) + i] = 'X';
                Predicthion.push_back({ get<0>(coordinates) + i, get<1>(coordinates) - i });
            }

        }
        for (int i = 1; i < 8; i++) {
            if (get<1>(coordinates) + i > 7 || get<0>(coordinates) - i < 0) {
                break;
            }
            if (InRange(Board[get<1>(coordinates) + i][get<0>(coordinates) - i], (int)'A', (int)'Z')) {
                Predicthion.push_back({ get<0>(coordinates) - i, get<1>(coordinates) + i });
                break;
            }
            if (InRange(Board[get<1>(coordinates) + i][get<0>(coordinates) - i], (int)'a', (int)'z') || Board[get<1>(coordinates) + i][get<0>(coordinates) - i] == '@' || Board[get<1>(coordinates) + i][get<0>(coordinates) - i] == '#') {
                WDead[get<1>(coordinates) + i][get<0>(coordinates) - i] = 'X';
                break;
            }
            if (Board[get<1>(coordinates) + i][get<0>(coordinates) - i] == '.') {
                WDead[get<1>(coordinates) + i][get<0>(coordinates) - i] = 'X';
                Predicthion.push_back({ get<0>(coordinates) - i, get<1>(coordinates) + i });
            }

        }
        for (int i = 1; i < 8; i++) {
            if (get<1>(coordinates) + i > 7 || get<0>(coordinates) + i > 7) {
                break;
            }
            if (InRange(Board[get<1>(coordinates) + i][get<0>(coordinates) + i], (int)'A', (int)'Z')) {
                Predicthion.push_back({ get<1>(coordinates) + i, get<0>(coordinates) + i });
                break;
            }
            if (InRange(Board[get<1>(coordinates) + i][get<0>(coordinates) + i], (int)'a', (int)'z') || Board[get<1>(coordinates) + i][get<0>(coordinates) + i] == '@' || Board[get<1>(coordinates) + i][get<0>(coordinates) + i] == '#') {
                WDead[get<1>(coordinates) + i][get<0>(coordinates) + i] = 'X';
                break;
            }
            if (Board[get<1>(coordinates) + i][get<0>(coordinates) + i] == '.') {
                WDead[get<1>(coordinates) + i][get<0>(coordinates) + i] = 'X';
                Predicthion.push_back({ get<0>(coordinates) + i, get<1>(coordinates) + i });
            }

        }
        a = {Predicthion, WDead};
        return a;
    }
};

class WQueen {
public:
    tuple<int, int> coordinates = { 0,0 };
    vector<vector<int>> Predicthion;
    tuple<vector<vector<int>>, vector<vector<char>>> predicthion(tuple<int, int> coordinates, vector<vector<char>> Board, vector<vector<char>> BDead) {
        vector<vector<int>> Predicthion;
        tuple<vector<vector<int>>, vector<vector<char>>> a;
        for (int i = 1; i < 8; i++) {
            if (get<0>(coordinates) - i < 0 || get<1>(coordinates) - i < 0) {
                break;
            }
            if (InRange(Board[get<1>(coordinates) - i][get<0>(coordinates) - i], (int)'a', (int)'z')) {
                Predicthion.push_back({ get<0>(coordinates) - i, get<1>(coordinates) - i });
                break;
            }
            if (InRange(Board[get<1>(coordinates) - i][get<0>(coordinates) - i], (int)'A', (int)'Z') || Board[get<1>(coordinates) - i][get<0>(coordinates) - i] == '@' || Board[get<1>(coordinates) - i][get<0>(coordinates) - i] == '#') {
                BDead[get<1>(coordinates) - i][get<0>(coordinates) - i] = 'X';
                break;
            }
            if (Board[get<1>(coordinates) - i][get<0>(coordinates) - i] == '.') {
                BDead[get<1>(coordinates) - i][get<0>(coordinates) - i] = 'X';
                Predicthion.push_back({ get<0>(coordinates) - i, get<1>(coordinates) - i });
            }

        }
        for (int i = 1; i < 8; i++) {
            if (get<0>(coordinates) + i > 7 || get<1>(coordinates) - i < 0) {
                break;
            }
            if (InRange(Board[get<1>(coordinates) - i][get<0>(coordinates) + i], (int)'a', (int)'z')) {
                Predicthion.push_back({ get<0>(coordinates) + i, get<1>(coordinates) - i });
                break;
            }
            if (InRange(Board[get<1>(coordinates) - i][get<0>(coordinates) + i], (int)'A', (int)'Z') || Board[get<1>(coordinates) - i][get<0>(coordinates) + i] == '@' || Board[get<1>(coordinates) - i][get<0>(coordinates) + i] == '#') {
                BDead[get<1>(coordinates) - i][get<0>(coordinates) + i] = 'X';
                break;
            }
            if (Board[get<1>(coordinates) - i][get<0>(coordinates) + i] == '.') {
                BDead[get<1>(coordinates) - i][get<0>(coordinates) + i] = 'X';
                Predicthion.push_back({ get<0>(coordinates) + i, get<1>(coordinates) - i });
            }

        }
        for (int i = 1; i < 8; i++) {
            if (get<1>(coordinates) + i > 7 || get<0>(coordinates) + i > 7) {
                break;
            }
            if (InRange(Board[get<1>(coordinates) + i][get<0>(coordinates) + i], (int)'a', (int)'z')) {
                Predicthion.push_back({ get<0>(coordinates) + i, get<1>(coordinates) + i });
                break;
            }
            if (InRange(Board[get<1>(coordinates) + i][get<0>(coordinates) + i], (int)'A', (int)'Z') || Board[get<1>(coordinates) + i][get<0>(coordinates) + i] == '@' || Board[get<1>(coordinates) + i][get<0>(coordinates) + i] == '#') {
                BDead[get<1>(coordinates) + i][get<0>(coordinates) + i] = 'X';
                break;
            }
            if (Board[get<1>(coordinates) + i][get<0>(coordinates) + i] == '.') {
                BDead[get<1>(coordinates) + i][get<0>(coordinates) + i] = 'X';
                Predicthion.push_back({ get<0>(coordinates) + i, get<1>(coordinates) + i });
            }

        }
        for (int i = 1; i < 8; i++) {
            if (get<1>(coordinates) + i > 7 || get<0>(coordinates) - i < 0) {
                break;
            }
            if (InRange(Board[get<1>(coordinates) + i][get<0>(coordinates) - i], (int)'a', (int)'z')) {
                Predicthion.push_back({ get<0>(coordinates) - i, get<1>(coordinates) + i });
                break;
            }
            if (InRange(Board[get<1>(coordinates) + i][get<0>(coordinates) - i], (int)'A', (int)'Z') || Board[get<1>(coordinates) + i][get<0>(coordinates) - i] == '@' || Board[get<1>(coordinates) + i][get<0>(coordinates) - i] == '#') {
                BDead[get<1>(coordinates) + i][get<0>(coordinates) - i] = 'X';
                break;
            }
            if (Board[get<1>(coordinates) + i][get<0>(coordinates) - i] == '.') {
                BDead[get<1>(coordinates) + i][get<0>(coordinates) - i] = 'X';
                Predicthion.push_back({ get<0>(coordinates) - i, get<1>(coordinates) + i });
            }

        }
        for (int i = 1; i < 8; i++) {
            if (get<0>(coordinates) - i < 0) {
                break;
            }
            if (InRange(Board[get<1>(coordinates)][get<0>(coordinates) - i], (int)'a', (int)'z')) {
                Predicthion.push_back({ get<0>(coordinates) - i, get<1>(coordinates) });
                break;
            }
            if (InRange(Board[get<1>(coordinates)][get<0>(coordinates) - i], (int)'A', (int)'Z') || Board[get<1>(coordinates)][get<0>(coordinates) - i] == '@' || Board[get<1>(coordinates)][get<0>(coordinates) - i] == '#') {
                BDead[get<1>(coordinates)][get<0>(coordinates) - i] = 'X';
                break;
            }
            if (Board[get<1>(coordinates)][get<0>(coordinates) - i] == '.') {
                BDead[get<1>(coordinates)][get<0>(coordinates) - i] = 'X';
                Predicthion.push_back({ get<0>(coordinates) - i, get<1>(coordinates) });
            }

        }
        for (int i = 1; i < 8; i++) {
            if (get<0>(coordinates) + i > 7) {
                break;
            }
            if (InRange(Board[get<1>(coordinates)][get<0>(coordinates) + i], (int)'a', (int)'z')) {
                Predicthion.push_back({ get<0>(coordinates) + i, get<1>(coordinates) });
                break;
            }
            if (InRange(Board[get<1>(coordinates)][get<0>(coordinates) + i], (int)'A', (int)'Z') || Board[get<1>(coordinates)][get<0>(coordinates) + i] == '@' || Board[get<1>(coordinates)][get<0>(coordinates) + i] == '#') {
                BDead[get<1>(coordinates)][get<0>(coordinates) + i] = 'X';
                break;
            }
            if (Board[get<1>(coordinates)][get<0>(coordinates) + i] == '.') {
                BDead[get<1>(coordinates)][get<0>(coordinates) + i] = 'X';
                Predicthion.push_back({ get<0>(coordinates) + i, get<1>(coordinates) });
            }

        }
        for (int i = 1; i < 8; i++) {
            if (get<1>(coordinates) - i < 0) {
                break;
            }
            if (InRange(Board[get<1>(coordinates) - i][get<0>(coordinates)], (int)'a', (int)'z')) {
                Predicthion.push_back({ get<0>(coordinates), get<1>(coordinates) - i });
                break;
            }
            if (InRange(Board[get<1>(coordinates) - i][get<0>(coordinates)], (int)'A', (int)'Z') || Board[get<1>(coordinates) - i][get<0>(coordinates)] == '@' || Board[get<1>(coordinates) - i][get<0>(coordinates)] == '#') {
                BDead[get<1>(coordinates)-i][get<0>(coordinates)] = 'X';
                break;
            }
            if (Board[get<1>(coordinates) - i][get<0>(coordinates)] == '.') {
                BDead[get<1>(coordinates)-i][get<0>(coordinates)] = 'X';
                Predicthion.push_back({ get<0>(coordinates), get<1>(coordinates) - i });
            }

        }
        for (int i = 1; i < 8; i++) {
            if (get<1>(coordinates) + i > 7) {
                break;
            }
            if (InRange(Board[get<1>(coordinates) + i][get<0>(coordinates)], (int)'a', (int)'z')) {
                Predicthion.push_back({ get<0>(coordinates), get<1>(coordinates) + i });
                break;
            }
            if (InRange(Board[get<1>(coordinates) + i][get<0>(coordinates)], (int)'A', (int)'Z') || Board[get<1>(coordinates) + i][get<0>(coordinates)] == '@' || Board[get<1>(coordinates) + i][get<0>(coordinates)] == '#') {
                BDead[get<1>(coordinates)+i][get<0>(coordinates)] = 'X';
                break;
            }
            if (Board[get<1>(coordinates) + i][get<0>(coordinates)] == '.') {
                BDead[get<1>(coordinates)+i][get<0>(coordinates)] = 'X';
                Predicthion.push_back({ get<0>(coordinates), get<1>(coordinates) + i });
            }

        }
        a = {Predicthion, BDead};
        return a;
    }

};

class BQueen {
public:
    tuple<int, int> coordinates = { 0,0 };
    vector<vector<int>> Predicthion;
    tuple<vector<vector<int>>, vector<vector<char>>> predicthion(tuple<int, int> coordinates, vector<vector<char>> Board, vector<vector<char>> WDead) {
        vector<vector<int>> Predicthion;
        tuple<vector<vector<int>>, vector<vector<char>>> a;
        for (int i = 1; i < 8; i++) {
            if (get<1>(coordinates) - i < 0 || get<0>(coordinates) - i < 0) {
                break;
            }
            if (InRange(Board[get<1>(coordinates) - i][get<0>(coordinates) - i], (int)'A', (int)'Z')) {
                Predicthion.push_back({ get<0>(coordinates) - i, get<1>(coordinates) - i });
                break;
            }
            if (InRange(Board[get<1>(coordinates) - i][get<0>(coordinates) - i], (int)'a', (int)'z') || Board[get<1>(coordinates) - i][get<0>(coordinates) - i] == '@' || Board[get<1>(coordinates) - i][get<0>(coordinates) - i] == '#') {
                WDead[get<1>(coordinates) - i][get<0>(coordinates) - i] = 'X';
                break;
            }
            if (Board[get<1>(coordinates) - i][get<0>(coordinates) - i] == '.') {
                WDead[get<1>(coordinates) - i][get<0>(coordinates) - i] = 'X';
                Predicthion.push_back({ get<0>(coordinates) - i, get<1>(coordinates) - i });
            }

        }
        for (int i = 1; i < 8; i++) {
            if (get<1>(coordinates) - i < 0 || get<0>(coordinates) + i >7) {
                break;
            }
            if (InRange(Board[get<1>(coordinates) - i][get<0>(coordinates) + i], (int)'A', (int)'Z')) {
                Predicthion.push_back({ get<0>(coordinates) + i, get<1>(coordinates) - i });
                break;
            }
            if (InRange(Board[get<1>(coordinates) - i][get<0>(coordinates) + i], (int)'a', (int)'z') || Board[get<1>(coordinates) - i][get<0>(coordinates) + i] == '@' || Board[get<1>(coordinates) - i][get<0>(coordinates) + i] == '#') {
                WDead[get<1>(coordinates) - i][get<0>(coordinates) + i] = 'X';
                break;
            }
            if (Board[get<1>(coordinates) - i][get<0>(coordinates) + i] == '.') {
                WDead[get<1>(coordinates) - i][get<0>(coordinates) + i] = 'X';
                Predicthion.push_back({ get<0>(coordinates) + i, get<1>(coordinates) - i });
            }

        }
        for (int i = 1; i < 8; i++) {
            if (get<1>(coordinates) + i > 7 || get<0>(coordinates) - i < 0) {
                break;
            }
            if (InRange(Board[get<1>(coordinates) + i][get<0>(coordinates) - i], (int)'A', (int)'Z')) {
                Predicthion.push_back({ get<0>(coordinates) - i, get<1>(coordinates) + i });
                break;
            }
            if (InRange(Board[get<1>(coordinates) + i][get<0>(coordinates) - i], (int)'a', (int)'z') || Board[get<1>(coordinates) + i][get<0>(coordinates) - i] == '@' || Board[get<1>(coordinates) + i][get<0>(coordinates) - i] == '#') {
                WDead[get<1>(coordinates) + i][get<0>(coordinates) - i] = 'X';
                break;
            }
            if (Board[get<1>(coordinates) + i][get<0>(coordinates) - i] == '.') {
                WDead[get<1>(coordinates) + i][get<0>(coordinates) - i] = 'X';
                Predicthion.push_back({ get<0>(coordinates) - i, get<1>(coordinates) + i });
            }

        }
        for (int i = 1; i < 8; i++) {
            if (get<1>(coordinates) + i > 7 || get<0>(coordinates) + i > 7) {
                break;
            }
            if (InRange(Board[get<1>(coordinates) + i][get<0>(coordinates) + i], (int)'A', (int)'Z')) {
                Predicthion.push_back({ get<1>(coordinates) + i, get<0>(coordinates) + i });
                break;
            }
            if (InRange(Board[get<1>(coordinates) + i][get<0>(coordinates) + i], (int)'a', (int)'z') || Board[get<1>(coordinates) + i][get<0>(coordinates) + i] == '@' || Board[get<1>(coordinates) + i][get<0>(coordinates) + i] == '#') {
                WDead[get<1>(coordinates) + i][get<0>(coordinates) + i] = 'X';
                break;
            }
            if (Board[get<1>(coordinates) + i][get<0>(coordinates) + i] == '.') {
                WDead[get<1>(coordinates) + i][get<0>(coordinates) + i] = 'X';
                Predicthion.push_back({ get<0>(coordinates) + i, get<1>(coordinates) + i });
            }

        }
        for (int i = 1; i < 8; i++) {
            if (get<0>(coordinates) - i < 0) {
                break;
            }
            if (InRange(Board[get<1>(coordinates)][get<0>(coordinates) - i], (int)'A', (int)'Z')) {
                Predicthion.push_back({ get<0>(coordinates) - i, get<1>(coordinates) });
                break;
            }
            if (InRange(Board[get<1>(coordinates)][get<0>(coordinates) - i], (int)'a', (int)'z') || Board[get<1>(coordinates)][get<0>(coordinates) - i] == '@' || Board[get<1>(coordinates)][get<0>(coordinates) - i] == '#') {
                WDead[get<1>(coordinates)][get<0>(coordinates) - i] = 'X';
                break;
            }
            if (Board[get<1>(coordinates)][get<0>(coordinates) - i] == '.') {
                WDead[get<1>(coordinates)][get<0>(coordinates) - i] = 'X';
                Predicthion.push_back({ get<0>(coordinates) - i, get<1>(coordinates) });
            }

        }
        for (int i = 1; i < 8; i++) {
            if (get<0>(coordinates) + i > 7) {
                break;
            }
            if (InRange(Board[get<1>(coordinates)][get<0>(coordinates) + i], (int)'A', (int)'Z')) {
                Predicthion.push_back({ get<0>(coordinates) + i, get<1>(coordinates) });
                break;
            }
            if (InRange(Board[get<1>(coordinates)][get<0>(coordinates) + i], (int)'a', (int)'z') || Board[get<1>(coordinates)][get<0>(coordinates) + i] == '@' || Board[get<1>(coordinates)][get<0>(coordinates) + i] == '#') {
                WDead[get<1>(coordinates)][get<0>(coordinates) + i] = 'X';
                break;
            }
            if (Board[get<1>(coordinates)][get<0>(coordinates) + i] == '.') {
                WDead[get<1>(coordinates)][get<0>(coordinates) + i] = 'X';
                Predicthion.push_back({ get<0>(coordinates) + i, get<1>(coordinates) });
            }

        }
        for (int i = 1; i < 8; i++) {
            if (get<1>(coordinates) - i < 0) {
                break;
            }
            if (InRange(Board[get<1>(coordinates) - i][get<0>(coordinates)], (int)'A', (int)'Z')) {
                Predicthion.push_back({ get<0>(coordinates), get<1>(coordinates) - i });
                break;
            }
            if (InRange(Board[get<1>(coordinates) - i][get<0>(coordinates)], (int)'a', (int)'z') || Board[get<1>(coordinates) - i][get<0>(coordinates)] == '@' || Board[get<1>(coordinates) - i][get<0>(coordinates)] == '#') {
                WDead[get<1>(coordinates)-i][get<0>(coordinates)] = 'X';
                break;
            }
            if (Board[get<1>(coordinates) - i][get<0>(coordinates)] == '.') {
                WDead[get<1>(coordinates)-i][get<0>(coordinates)] = 'X';
                Predicthion.push_back({ get<0>(coordinates), get<1>(coordinates) - i });
            }

        }
        for (int i = 1; i < 8; i++) {
            if (get<1>(coordinates) + i > 7) {
                break;
            }
            if (InRange(Board[get<1>(coordinates) + i][get<0>(coordinates)], (int)'A', (int)'Z')) {
                Predicthion.push_back({ get<1>(coordinates), get<0>(coordinates) + i });
                break;
            }
            if (InRange(Board[get<1>(coordinates) + i][get<0>(coordinates)], (int)'a', (int)'z') || Board[get<1>(coordinates) + i][get<0>(coordinates)] == '@' || Board[get<1>(coordinates) + i][get<0>(coordinates)] == '#') {
                WDead[get<1>(coordinates)+i][get<0>(coordinates)] = 'X';
                break;
            }
            if (Board[get<1>(coordinates) + i][get<0>(coordinates)] == '.') {
                WDead[get<1>(coordinates)+i][get<0>(coordinates)] = 'X';
                Predicthion.push_back({ get<0>(coordinates), get<1>(coordinates) + i });
            }

        }
        a = {Predicthion, WDead};
        return a;
    }
};

class BKing {
public:
    tuple<int, int> coordinates = { 0,0 };
    vector<vector<int>> Predicthion;
    vector<vector<int>> predicthion(tuple<int, int> coordinates, vector<vector<char>> Board, vector<vector<char>> DeadSquares) {
        vector<vector<int>> Predicthion;
        if (get<1>(coordinates) - 1 >= 0 && DeadSquares[get<1>(coordinates) - 1][get<0>(coordinates)] == '.') {
            Predicthion.push_back({ get<0>(coordinates), get<1>(coordinates) - 1 });
        }
        if (get<1>(coordinates) - 1 >= 0 && get<0>(coordinates) + 1 < 8 && DeadSquares[get<1>(coordinates) - 1][get<0>(coordinates) + 1] == '.') {
            Predicthion.push_back({ get<0>(coordinates) + 1, get<1>(coordinates) - 1 });
        }
        if (get<1>(coordinates) - 1 >= 0 && get<1>(coordinates) - 1 >= 0 && DeadSquares[get<1>(coordinates) - 1][get<0>(coordinates) - 1] == '.') {
            Predicthion.push_back({ get<0>(coordinates) - 1, get<1>(coordinates) - 1 });
        }
        if (get<1>(coordinates) + 1 < 8 && DeadSquares[get<1>(coordinates) + 1][get<0>(coordinates)] == '.') {
            Predicthion.push_back({ get<0>(coordinates), get<1>(coordinates) + 1 });
        }
        if (get<1>(coordinates) + 1 < 8 && get<0>(coordinates) + 1 < 8 && DeadSquares[get<1>(coordinates) + 1][get<0>(coordinates) + 1] == '.') {
            Predicthion.push_back({ get<0>(coordinates) + 1, get<1>(coordinates) + 1 });
        }
        if (get<1>(coordinates) + 1 < 8 && get<0>(coordinates) - 1 >= 0 && DeadSquares[get<1>(coordinates) + 1][get<0>(coordinates) - 1] == '.') {
            Predicthion.push_back({ get<0>(coordinates) - 1, get<1>(coordinates) + 1 });
        }

        if (get<0>(coordinates) - 1 >= 0 && DeadSquares[get<1>(coordinates)][get<0>(coordinates) - 1] == '.') {
            Predicthion.push_back({ get<0>(coordinates) - 1, get<1>(coordinates) });
        }
        if (get<0>(coordinates) + 1 < 8 && DeadSquares[get<1>(coordinates)][get<0>(coordinates) + 1] == '.') {
            Predicthion.push_back({ get<0>(coordinates) + 1, get<1>(coordinates) });
        }
        return Predicthion;
    }
};

class WKing {
public:
    tuple<int, int> coordinates = { 0,0 };
    vector<vector<int>> Predicthion{ {0,0} };
    vector<vector<int>> predicthion(tuple<int, int> coordinates, vector<vector<char>> Board, vector<vector<char>> DeadSquares) {
        vector<vector<int>> Predicthion;
        if (get<1>(coordinates) - 1 >= 0 && DeadSquares[get<1>(coordinates) - 1][get<0>(coordinates)] == '.') {
            Predicthion.push_back({ get<0>(coordinates), get<1>(coordinates) - 1 });
        }
        if (get<1>(coordinates) - 1 >= 0 && get<0>(coordinates) + 1 < 8 && DeadSquares[get<1>(coordinates) - 1][get<0>(coordinates) + 1] == '.') {
            Predicthion.push_back({ get<0>(coordinates) + 1, get<1>(coordinates) - 1 });
        }
        if (get<1>(coordinates) - 1 >= 0 && get<1>(coordinates) - 1 >= 0 && DeadSquares[get<1>(coordinates) - 1][get<0>(coordinates) - 1] == '.') {
            Predicthion.push_back({ get<0>(coordinates) - 1, get<1>(coordinates) - 1 });
        }
        if (get<1>(coordinates) + 1 < 8 && DeadSquares[get<1>(coordinates) + 1][get<0>(coordinates)] == '.') {
            Predicthion.push_back({ get<0>(coordinates), get<1>(coordinates) + 1 });
        }
        if (get<1>(coordinates) + 1 < 8 && get<0>(coordinates) + 1 < 8 && DeadSquares[get<1>(coordinates) + 1][get<0>(coordinates) + 1] == '.') {
            Predicthion.push_back({ get<0>(coordinates) + 1, get<1>(coordinates) + 1 });
        }
        if (get<1>(coordinates) + 1 < 8 && get<0>(coordinates) - 1 >= 0 && DeadSquares[get<1>(coordinates) + 1][get<0>(coordinates) - 1] == '.') {
            Predicthion.push_back({ get<0>(coordinates) - 1, get<1>(coordinates) + 1 });
        }

        if (get<0>(coordinates) - 1 >= 0 && DeadSquares[get<1>(coordinates)][get<0>(coordinates) - 1] == '.') {
            Predicthion.push_back({ get<0>(coordinates) - 1, get<1>(coordinates) });
        }
        if (get<0>(coordinates) + 1 < 8 && DeadSquares[get<1>(coordinates)][get<0>(coordinates) + 1] == '.') {
            Predicthion.push_back({ get<0>(coordinates) + 1, get<1>(coordinates) });
        }
        return Predicthion;
    }
};


vector<vector<char>> BDeadSquares(vector <BPawn> BPawns, vector <BRook> BRooks, vector <BKnight> BKnights, vector <BBishop> BBishops, vector<BQueen> BQueens, vector <BKing> BKings, vector < vector <char> > DeadBoard) {

    for (size_t i = 0; i < BPawns.size(); i++)
    {
        DeadBoard[get<1>(BPawns[i].coordinates)][get<0>(BPawns[i].coordinates)] = 'X';
    }

    for (size_t i = 0; i < BRooks.size(); i++)
    {
        DeadBoard[get<1>(BRooks[i].coordinates)][get<0>(BRooks[i].coordinates)] = 'X';
    }
    for (size_t i = 0; i < BKnights.size(); i++)
    {
        DeadBoard[get<1>(BKnights[i].coordinates)][get<0>(BKnights[i].coordinates)] = 'X';
    }

    for (size_t i = 0; i < BBishops.size(); i++)
    {
        DeadBoard[get<1>(BBishops[i].coordinates)][get<0>(BBishops[i].coordinates)] = 'X';
    }

    for (size_t i = 0; i < BQueens.size(); i++)
    {
        DeadBoard[get<1>(BQueens[i].coordinates)][get<0>(BQueens[i].coordinates)] = 'X';
    }

    return DeadBoard;
}

vector<vector<char>> WDeadSquares(vector <WPawn> WPawns, vector <WRook> WRooks, vector <WKnight> WKnights, vector <WBishop> WBishops, vector<WQueen> WQueens, vector <WKing> WKings, vector < vector <char> > DeadBoard) {


    for (size_t i = 0; i < WPawns.size(); i++) {
        DeadBoard[get<1>(WPawns[i].coordinates)][get<0>(WPawns[i].coordinates)] = 'X';
    }

    for (size_t i = 0; i < WRooks.size(); i++)
    {
        DeadBoard[get<1>(WRooks[i].coordinates)][get<0>(WRooks[i].coordinates)] = 'X';
    }

    for (size_t i = 0; i < WKnights.size(); i++)
    {
        DeadBoard[get<1>(WKnights[i].coordinates)][get<0>(WKnights[i].coordinates)] = 'X';
    }

    for (size_t i = 0; i < WBishops.size(); i++)
    {
        DeadBoard[get<1>(WBishops[i].coordinates)][get<0>(WBishops[i].coordinates)] = 'X';
    }

    for (size_t i = 0; i < WQueens.size(); i++)
    {
        DeadBoard[get<1>(WQueens[i].coordinates)][get<0>(WQueens[i].coordinates)] = 'X';
    }

    return DeadBoard;
}

tuple <vector<WPawn>, vector<WRook>, vector<WKnight>, vector<WBishop>, vector<WQueen>> WMorph (vector<WPawn> WPawns, vector<WRook> WRooks, vector<WKnight> WKnights, vector<WBishop> WBishops , vector<WQueen> WQueens){
    for (size_t i = 0; i < WPawns.size(); i++){
        if (get<1>(WPawns[i].coordinates) == 0){
            int askedFigure;
            bool InvalidNum = 1;
            while (InvalidNum){
                cout << "Choose your figure (enter number):" << "\n"<< "1.Knight" << "\t" << "2.Bishop" << "\t" << "3.Rook" << "\t" << "4.Queen" << "\n";
                cin >> askedFigure;
                switch(askedFigure){
                case 1:   //Knight
                    {
                        WKnight Kn1;
                        get<0>(Kn1.coordinates) = get<0>(WPawns[i].coordinates);
                        get<1>(Kn1.coordinates) = get<1>(WPawns[i].coordinates);
                        WKnights.push_back(Kn1);
                        InvalidNum = 0;
                        break;
                    }
                case 2:   //Bishop
                    {
                        WBishop B1;
                        get<0>(B1.coordinates) = get<0>(WPawns[i].coordinates);
                        get<1>(B1.coordinates) = get<1>(WPawns[i].coordinates);
                        WBishops.push_back(B1);
                        InvalidNum = 0;
                        break;
                    }
                case 3:   //Rook
                    {
                        WRook R1;
                        get<0>(R1.coordinates) = get<0>(WPawns[i].coordinates);
                        get<1>(R1.coordinates) = get<1>(WPawns[i].coordinates);
                        WRooks.push_back(R1);
                        InvalidNum = 0;
                        break;
                    }
                case 4:   //Queen
                    {
                        WQueen Q1;
                        get<0>(Q1.coordinates) = get<0>(WPawns[i].coordinates);
                        get<1>(Q1.coordinates) = get<1>(WPawns[i].coordinates);
                        WQueens.push_back(Q1);
                        InvalidNum = 0;
                        break;
                    }   
                default:
                    cout << "Invalid figure";
                };
            }
            WPawns.erase(WPawns.begin() + i);
            tuple <vector<WPawn>, vector<WRook>, vector<WKnight>, vector<WBishop>, vector<WQueen>> a = {WPawns, WRooks, WKnights, WBishops, WQueens};
            return a;
        }
    }
}

tuple <vector<BPawn>, vector<BRook>, vector<BKnight>, vector<BBishop>, vector<BQueen>> BMorph (vector<BPawn> BPawns, vector<BRook> BRooks, vector<BKnight> BKnights, vector<BBishop> BBishops , vector<BQueen> BQueens){
    for (size_t i = 0; i < BPawns.size(); i++){
        if (get<1>(BPawns[i].coordinates) == 7){
            int askedFigure;
            bool InvalidNum = 1;
            while (InvalidNum){
                cout << "Choose your figure (enter number):" << "\n"<< "1.Knight" << "\t" << "2.Bishop" << "\t" << "3.Rook" << "\t" << "4.Queen" << "\n";
                cin >> askedFigure;
                switch(askedFigure){
                case 1:   //Knight
                    {
                        BKnight Kn1;
                        get<0>(Kn1.coordinates) = get<0>(BPawns[i].coordinates);
                        get<1>(Kn1.coordinates) = get<1>(BPawns[i].coordinates);
                        BKnights.push_back(Kn1);
                        InvalidNum = 0;
                        break;
                    }   
                case 2:   //Bishop
                    {
                        BBishop B1;
                        get<0>(B1.coordinates) = get<0>(BPawns[i].coordinates);
                        get<1>(B1.coordinates) = get<1>(BPawns[i].coordinates);
                        BBishops.push_back(B1);
                        InvalidNum = 0;
                        break;
                    }   
                case 3:   //Rook
                    {
                        BRook R1;
                        get<0>(R1.coordinates) = get<0>(BPawns[i].coordinates);
                        get<1>(R1.coordinates) = get<1>(BPawns[i].coordinates);
                        BRooks.push_back(R1);
                        InvalidNum = 0;
                        break;
                    }       
                case 4:   //Queen
                    {
                        BQueen Q1;
                        get<0>(Q1.coordinates) = get<0>(BPawns[i].coordinates);
                        get<1>(Q1.coordinates) = get<1>(BPawns[i].coordinates);
                        BQueens.push_back(Q1);
                        InvalidNum = 0;
                        break;
                    }       
                default:
                    cout << "Invalid figure";
                };
            }
            BPawns.erase(BPawns.begin() + i);
            tuple <vector<BPawn>, vector<BRook>, vector<BKnight>, vector<BBishop>, vector<BQueen>> a = {BPawns, BRooks, BKnights, BBishops, BQueens};
            return a;
        }
    }
}

tuple <vector<WPawn>, vector<WRook>, vector<WKnight>, vector<WBishop>, vector<WQueen>>WEterethion (vector <WPawn> WPawns, vector <WRook> WRooks, vector <WKnight> WKnights, vector <WBishop> WBishops, vector<WQueen> WQueens, vector <WKing> WKings, vector<vector<char>> Board){
    vector<vector<int>> atackers;
    for (int i = 1; i < 8; i++) {
        if (get<1>(WKings[0].coordinates) - i < 0 || get<0>(WKings[0].coordinates) - i < 0) {
            break;
        }
        if (Board[get<1>(WKings[0].coordinates) - i][get<0>(WKings[0].coordinates) - i] == 'b' || Board[get<1>(WKings[0].coordinates) - i][get<0>(WKings[0].coordinates) - i] == 'q') {
            atackers.push_back({get<0>(WKings[0].coordinates) - i, get<1>(WKings[0].coordinates) - i,  (int) Board[get<1>(WKings[0].coordinates) - i][get<0>(WKings[0].coordinates) - i] });
            break;
        }
        if (InRange(Board[get<1>(WKings[0].coordinates) - i][get<0>(WKings[0].coordinates) - i], (int)'A', (int)'Z') || Board[get<1>(WKings[0].coordinates) - i][get<0>(WKings[0].coordinates) - i] == '@' || Board[get<1>(WKings[0].coordinates) - i][get<0>(WKings[0].coordinates) - i] == '#') {
            break;
        }

    }
    for (int i = 1; i < 8; i++) {
        if (get<1>(WKings[0].coordinates) + i > 7 || get<0>(WKings[0].coordinates) - i < 0) {
            break;
        }
        if (Board[get<1>(WKings[0].coordinates) + i][get<0>(WKings[0].coordinates) - i] == 'b' || Board[get<1>(WKings[0].coordinates) + i][get<0>(WKings[0].coordinates) - i] == 'q') {
            atackers.push_back({get<0>(WKings[0].coordinates) - i, get<1>(WKings[0].coordinates) + i,  (int) Board[get<1>(WKings[0].coordinates) + i][get<0>(WKings[0].coordinates) - i] });
            break;
        }
        if (InRange(Board[get<1>(WKings[0].coordinates) + i][get<0>(WKings[0].coordinates) - i], (int)'A', (int)'Z') || Board[get<1>(WKings[0].coordinates) + i][get<0>(WKings[0].coordinates) - i] == '@' || Board[get<1>(WKings[0].coordinates) + i][get<0>(WKings[0].coordinates) - i] == '#') {
            break;
        }

    }
    for (int i = 1; i < 8; i++) {
        if (get<1>(WKings[0].coordinates) + i > 7 || get<0>(WKings[0].coordinates) + i > 0) {
            break;
        }
        if (Board[get<1>(WKings[0].coordinates) + i][get<0>(WKings[0].coordinates) + i] == 'b' || Board[get<1>(WKings[0].coordinates) + i][get<0>(WKings[0].coordinates) + i] == 'q') {
            atackers.push_back({get<0>(WKings[0].coordinates) + i, get<1>(WKings[0].coordinates) + i,  (int) Board[get<1>(WKings[0].coordinates) + i][get<0>(WKings[0].coordinates) + i] });
            break;
        }
        if (InRange(Board[get<1>(WKings[0].coordinates) + i][get<0>(WKings[0].coordinates) + i], (int)'A', (int)'Z') || Board[get<1>(WKings[0].coordinates) + i][get<0>(WKings[0].coordinates) + i] == '@' || Board[get<1>(WKings[0].coordinates) + i][get<0>(WKings[0].coordinates) + i] == '#') {
            break;
        }

    }

    for (int i = 1; i < 8; i++) {
        if (get<1>(WKings[0].coordinates) - i < 0 || get<0>(WKings[0].coordinates) + i > 7) {
            break;
        }
        if (Board[get<1>(WKings[0].coordinates) - i][get<0>(WKings[0].coordinates) + i] == 'b' || Board[get<1>(WKings[0].coordinates) - i][get<0>(WKings[0].coordinates) + i] == 'q') {
            atackers.push_back({get<0>(WKings[0].coordinates) + i, get<1>(WKings[0].coordinates) - i,  (int) Board[get<1>(WKings[0].coordinates) - i][get<0>(WKings[0].coordinates) + i] });
            break;
        }
        if (InRange(Board[get<1>(WKings[0].coordinates) - i][get<0>(WKings[0].coordinates) + i], (int)'A', (int)'Z') || Board[get<1>(WKings[0].coordinates) - i][get<0>(WKings[0].coordinates) + i] == '@' || Board[get<1>(WKings[0].coordinates) - i][get<0>(WKings[0].coordinates) + i] == '#') {
            break;
        }

    }
    for (int i = 1; i < 8; i++) {
        if (get<0>(WKings[0].coordinates) - i < 0) {
            break;
        }
        if (Board[get<1>(WKings[0].coordinates)][get<0>(WKings[0].coordinates) - i]== 'r' || Board[get<1>(WKings[0].coordinates)][get<0>(WKings[0].coordinates) - i]== 'q') {
            atackers.push_back({ get<0>(WKings[0].coordinates) - i, get<1>(WKings[0].coordinates), (int) Board[get<1>(WKings[0].coordinates)][get<0>(WKings[0].coordinates) - i] });
            break;
        }
        if (InRange(Board[get<1>(WKings[0].coordinates)][get<0>(WKings[0].coordinates) - i], (int)'A', (int)'Z') || Board[get<1>(WKings[0].coordinates)][get<0>(WKings[0].coordinates) - i] == '@' || Board[get<1>(WKings[0].coordinates)][get<0>(WKings[0].coordinates) - i] == '#') {
            break;
        }

    }
    for (int i = 1; i < 8; i++) {
        if (get<0>(WKings[0].coordinates) + i > 7) {
            break;
        }
        if (Board[get<1>(WKings[0].coordinates)][get<0>(WKings[0].coordinates) + i]== 'r' || Board[get<1>(WKings[0].coordinates)][get<0>(WKings[0].coordinates) + i]== 'q') {
            atackers.push_back({ get<0>(WKings[0].coordinates) + i, get<1>(WKings[0].coordinates), (int) Board[get<1>(WKings[0].coordinates)][get<0>(WKings[0].coordinates) + i] });
            break;
        }
        if (InRange(Board[get<1>(WKings[0].coordinates)][get<0>(WKings[0].coordinates) + i], (int)'A', (int)'Z') || Board[get<1>(WKings[0].coordinates)][get<0>(WKings[0].coordinates) + i] == '@' || Board[get<1>(WKings[0].coordinates)][get<0>(WKings[0].coordinates) + i] == '#') {
            break;
        }

    }
    for (int i = 1; i < 8; i++) {
        if (get<1>(WKings[0].coordinates) - i < 0) {
            break;
        }
        if (Board[get<1>(WKings[0].coordinates)- i][get<0>(WKings[0].coordinates) ]== 'r' || Board[get<1>(WKings[0].coordinates)- i][get<0>(WKings[0].coordinates) ]== 'q') {
            atackers.push_back({ get<0>(WKings[0].coordinates) , get<1>(WKings[0].coordinates)- i, (int) Board[get<1>(WKings[0].coordinates)- i][get<0>(WKings[0].coordinates) ] });
            break;
        }
        if (InRange(Board[get<1>(WKings[0].coordinates)- i][get<0>(WKings[0].coordinates) ], (int)'A', (int)'Z') || Board[get<1>(WKings[0].coordinates) - i][get<0>(WKings[0].coordinates)] == '@' || Board[get<1>(WKings[0].coordinates)- i][get<0>(WKings[0].coordinates) ] == '#') {
            break;
        }

    }
    for (int i = 1; i < 8; i++) {
        if (get<1>(WKings[0].coordinates) + i > 7) {
            break;
        }
        if (Board[get<1>(WKings[0].coordinates)+ i][get<0>(WKings[0].coordinates) ]== 'r' || Board[get<1>(WKings[0].coordinates)+ i][get<0>(WKings[0].coordinates) ]== 'q') {
            atackers.push_back({ get<0>(WKings[0].coordinates) , get<1>(WKings[0].coordinates)+ i, (int) Board[get<1>(WKings[0].coordinates)+ i][get<0>(WKings[0].coordinates) ] });
            break;
        }
        if (InRange(Board[get<1>(WKings[0].coordinates)+ i][get<0>(WKings[0].coordinates) ], (int)'A', (int)'Z') || Board[get<1>(WKings[0].coordinates)+ i][get<0>(WKings[0].coordinates) ] == '@' || Board[get<1>(WKings[0].coordinates)+ i][get<0>(WKings[0].coordinates) ] == '#') {
            break;
        }

    }



    if ((get<1>(WKings[0].coordinates) - 1 >= 0 && get<0>(WKings[0].coordinates) - 2 >= 0) && Board[get<1>(WKings[0].coordinates) - 1][get<0>(WKings[0].coordinates) - 2] == 'k' ) {
        atackers.push_back({ get<0>(WKings[0].coordinates) - 2, get<1>(WKings[0].coordinates) - 1, (int)'k' });
    }
    if ((get<1>(WKings[0].coordinates) + 1 <= 7 && get<0>(WKings[0].coordinates) - 2 >= 0) && Board[get<1>(WKings[0].coordinates) + 1][get<0>(WKings[0].coordinates) - 2] == 'k') {
        atackers.push_back({ get<0>(WKings[0].coordinates) - 2, get<1>(WKings[0].coordinates) + 1, (int)'k' });
    }
    if ((get<1>(WKings[0].coordinates) - 1 >= 0 && get<0>(WKings[0].coordinates) + 2 <= 7) && Board[get<1>(WKings[0].coordinates) - 1][get<0>(WKings[0].coordinates) + 2] == 'k') {
        atackers.push_back({ get<0>(WKings[0].coordinates) + 2, get<1>(WKings[0].coordinates) - 1, (int)'k' });
    }
    if ((get<1>(WKings[0].coordinates) + 1 <= 7 && get<0>(WKings[0].coordinates) + 2 <= 7) && Board[get<1>(WKings[0].coordinates) + 1][get<0>(WKings[0].coordinates) + 2] == 'k') {
        atackers.push_back({ get<0>(WKings[0].coordinates) + 2, get<1>(WKings[0].coordinates) + 1, (int)'k' });
    }
    if ((get<1>(WKings[0].coordinates) - 2 >= 0 && get<0>(WKings[0].coordinates) - 1 >= 0) && Board[get<1>(WKings[0].coordinates) - 2][get<0>(WKings[0].coordinates) - 1] == 'k') {
        atackers.push_back({ get<0>(WKings[0].coordinates) - 1, get<1>(WKings[0].coordinates) - 2, (int)'k' });
    }
    if ((get<1>(WKings[0].coordinates) - 2 >= 0 && get<0>(WKings[0].coordinates) + 1 <= 7) && Board[get<1>(WKings[0].coordinates) - 2][get<0>(WKings[0].coordinates) + 1] == 'k') {
        atackers.push_back({ get<0>(WKings[0].coordinates) + 1, get<1>(WKings[0].coordinates) - 2, (int)'k' });
    }
    if ((get<1>(WKings[0].coordinates) + 2 <= 7 && get<0>(WKings[0].coordinates) - 1 >= 0) && Board[get<1>(WKings[0].coordinates) + 2][get<0>(WKings[0].coordinates) - 1] == 'k') {
        atackers.push_back({ get<0>(WKings[0].coordinates) - 1, get<1>(WKings[0].coordinates) + 2, (int)'k' });
    }
    if ((get<1>(WKings[0].coordinates) + 2 <= 7 && get<0>(WKings[0].coordinates) + 1 <= 7) && Board[get<1>(WKings[0].coordinates) + 2][get<0>(WKings[0].coordinates) + 1] == 'k') {
        atackers.push_back({ get<0>(WKings[0].coordinates) + 1, get<1>(WKings[0].coordinates) + 2, (int)'k' });
    }

    if((get<1>(WKings[0].coordinates) -1 >=0 || get<0>(WKings[0].coordinates) + 1<=7) && Board[get<1>(WKings[0].coordinates) -1][get<0>(WKings[0].coordinates) + 1] == 'p'){
        atackers.push_back({get<0>(WKings[0].coordinates) + 1, get<1>(WKings[0].coordinates) -1, (int)'p'});
    }
    if((get<1>(WKings[0].coordinates) -1 >=0 || get<0>(WKings[0].coordinates) - 1>=0) && Board[get<1>(WKings[0].coordinates) -1][get<0>(WKings[0].coordinates) - 1] == 'p'){
        atackers.push_back({get<0>(WKings[0].coordinates) + 1, get<1>(WKings[0].coordinates) -1, (int)'p'});
    }

    tuple <vector<WPawn>, vector<WRook>, vector<WKnight>, vector<WBishop>, vector<WQueen>> pieces;
    if (atackers.size() >1){
        for(size_t i =0; i < WPawns.size(); i++){
            WPawns[i].Predicthion = {};
        }
        for(size_t i =0; i < WRooks.size(); i++){
            WRooks[i].Predicthion = {};
        }
        for(size_t i =0; i < WKnights.size(); i++){
            WKnights[i].Predicthion = {};
        }
        for(size_t i =0; i < WBishops.size(); i++){
            WBishops[i].Predicthion = {};
        }
        for(size_t i =0; i < WQueens.size(); i++){
            WQueens[i].Predicthion = {};
        }
        pieces = {WPawns, WRooks, WKnights, WBishops, WQueens};
        return pieces;
    }
    else{
        vector<WPawn> PawnsCopy = WPawns;
        vector<WRook> RooksCopy= WRooks;
        vector<WBishop> BishopsCopy = WBishops;
        vector<WKnight> KnightsCopy = WKnights;
        vector<WQueen> QueensCopy = WQueens;
        if (atackers[0][2] == (int)'r'){
            for (size_t j = 0; j < WPawns.size(); j++){
                PawnsCopy[j].Predicthion = {};
                if ((get<1>(WPawns[j].coordinates)-1 >=0) 
                && (atackers[0][0] == get<0>(WPawns[j].coordinates)  == get<0>(WKings[0].coordinates) 
                && InRange(get<1>(WPawns[j].coordinates)-1, atackers[0][1], get<1>(WKings[0].coordinates) ))){
                    PawnsCopy[j].Predicthion.push_back({get<0>(WPawns[j].coordinates), get<1>(WPawns[j].coordinates)-1});
                }
                else if ((get<1>(WPawns[j].coordinates)-1 >=0) 
                && (atackers[0][1] == get<1>(WPawns[j].coordinates)-1  == get<1>(WKings[0].coordinates)
                && InRange(get<0>(WPawns[j].coordinates), atackers[0][0], get<0>(WKings[0].coordinates) ))){
                    PawnsCopy[j].Predicthion.push_back({get<0>(WPawns[j].coordinates), get<1>(WPawns[j].coordinates)-1});
                }

                if ((get<1>(WPawns[j].coordinates) ==6) && (get<1>(WPawns[j].coordinates)-2 >=0) 
                && (atackers[0][0] == get<0>(WPawns[j].coordinates)  == get<0>(WKings[0].coordinates) 
                && InRange(get<1>(WPawns[j].coordinates)-2, atackers[0][1], get<1>(WKings[0].coordinates) ))){
                    PawnsCopy[j].Predicthion.push_back({get<0>(WPawns[j].coordinates), get<1>(WPawns[j].coordinates)-2});
                }
                else if ((get<1>(WPawns[j].coordinates) ==6) && (get<1>(WPawns[j].coordinates)-2 >=0) 
                && (atackers[0][1] == get<1>(WPawns[j].coordinates)-2  == get<1>(WKings[0].coordinates)
                && InRange(get<0>(WPawns[j].coordinates), atackers[0][0], get<0>(WKings[0].coordinates) ))){
                    PawnsCopy[j].Predicthion.push_back({get<0>(WPawns[j].coordinates), get<1>(WPawns[j].coordinates)-2});
                }
            }
            for (size_t j = 0; j < WRooks.size(); j++)
            {
                RooksCopy[j].Predicthion = {};
                for (size_t i =0; i<WRooks[j].Predicthion.size(); i++){
                    if (atackers[0][0] == WRooks[j].Predicthion[i][0] == get<0>(WKings[0].coordinates) 
                    && InRange(WRooks[j].Predicthion[i][1],atackers[0][1], get<1>(WKings[0].coordinates) )){
                        RooksCopy[j].Predicthion.push_back(WRooks[j].Predicthion[i]);
                    }
                    else if (atackers[0][1] == WRooks[j].Predicthion[i][1] == get<1>(WKings[0].coordinates) 
                    && InRange(WRooks[j].Predicthion[i][0],atackers[0][0], get<0>(WKings[0].coordinates) )){
                        RooksCopy[j].Predicthion.push_back(WRooks[j].Predicthion[i]);
                    }
                }

            }
            for (size_t j = 0; j < WBishops.size(); j++)
            {
                BishopsCopy[j].Predicthion = {};
                for (size_t i =0; i<WBishops[j].Predicthion.size(); i++){
                    if (atackers[0][0] == WBishops[j].Predicthion[i][0] == get<0>(WKings[0].coordinates) 
                    && InRange(WBishops[j].Predicthion[i][1],atackers[0][1], get<1>(WKings[0].coordinates) )){
                        
                    }
                    else if (atackers[0][1] == WBishops[j].Predicthion[i][1] == get<1>(WKings[0].coordinates) 
                    && InRange(WBishops[j].Predicthion[i][0],atackers[0][0], get<0>(WKings[0].coordinates) )){
                        BishopsCopy[j].Predicthion.push_back(WBishops[j].Predicthion[i]);
                    }
                }

            }
            for (size_t j = 0; j < WKnights.size(); j++){
                KnightsCopy[j].Predicthion = {};
                for (size_t i =0; i<WKnights[j].Predicthion.size(); i++){
                    if (atackers[0][0] == WKnights[j].Predicthion[i][0] == get<0>(WKings[0].coordinates) 
                    && InRange(WKnights[j].Predicthion[i][1],atackers[0][1], get<1>(WKings[0].coordinates) )){
                        KnightsCopy[j].Predicthion.push_back(WKnights[j].Predicthion[i]);
                    }
                    if (atackers[0][1] == WKnights[j].Predicthion[i][1] == get<1>(WKings[0].coordinates) 
                    && InRange(WKnights[j].Predicthion[i][0],atackers[0][0], get<0>(WKings[0].coordinates) )){
                        KnightsCopy[j].Predicthion.push_back(WKnights[j].Predicthion[i]);
                    }
                }
            }
            for (size_t j = 0; j < WQueens.size(); j++)
            {
                QueensCopy[j].Predicthion ={};
                for (size_t i =0; i<WQueens[j].Predicthion.size(); i++){
                    if ((atackers[0][0] == WQueens[j].Predicthion[i][0] == get<0>(WKings[0].coordinates) 
                    && InRange(WQueens[j].Predicthion[i][1],atackers[0][1], get<1>(WKings[0].coordinates) ))){
                        QueensCopy[j].Predicthion.push_back(WQueens[j].Predicthion[i]);
                    }
                    if ((atackers[0][1] == WQueens[j].Predicthion[i][1] == get<1>(WKings[0].coordinates) 
                    && InRange(WQueens[j].Predicthion[i][0],atackers[0][0], get<0>(WKings[0].coordinates) ))){
                        QueensCopy[j].Predicthion.push_back(WQueens[j].Predicthion[i]);
                    }
                }

            }
        }

        // не правильно написана частина з модулем
        else if (atackers[0][2] == (int)'b'){
            for (size_t j = 0; j < WPawns.size(); j++){
                PawnsCopy[j].Predicthion = {};
                if ((InRange(get<0>(WPawns[j].coordinates),atackers[0][0], get<0>(WKings[0].coordinates) )
                && InRange(get<1>(WPawns[j].coordinates)-1,atackers[0][1], get<1>(WKings[0].coordinates) )
                && abs(get<1>(WKings[0].coordinates) - (get<1>(WPawns[j].coordinates)-1)) == abs(get<0>(WKings[0].coordinates) - get<0>(WPawns[j].coordinates)))){
                    PawnsCopy[j].Predicthion.push_back({get<0>(WPawns[j].coordinates), get<1>(WPawns[j].coordinates)-1});
                }
                else if ((InRange(get<0>(WPawns[j].coordinates),atackers[0][0], get<0>(WKings[0].coordinates) ) 
                && InRange(get<1>(WPawns[j].coordinates)-1,atackers[0][1], get<1>(WKings[0].coordinates) )
                && abs(get<1>(WKings[0].coordinates) - (get<1>(WPawns[j].coordinates)-1)) == abs(get<0>(WKings[0].coordinates) - get<0>(WPawns[j].coordinates)))){
                    PawnsCopy[j].Predicthion.push_back({get<0>(WPawns[j].coordinates), get<1>(WPawns[j].coordinates)-1});
                }

                if ((get<1>(WPawns[j].coordinates) == 6) && (InRange(get<0>(WPawns[j].coordinates),atackers[0][0], get<0>(WKings[0].coordinates) )
                && InRange(get<1>(WPawns[j].coordinates)-2,atackers[0][1], get<1>(WKings[0].coordinates) )
                && abs(get<1>(WKings[0].coordinates) - (get<1>(WPawns[j].coordinates)-2)) == abs(get<0>(WKings[0].coordinates) - get<0>(WPawns[j].coordinates)))){
                    PawnsCopy[j].Predicthion.push_back({get<0>(WPawns[j].coordinates), get<1>(WPawns[j].coordinates)-2});
                }
                else if ((get<1>(WPawns[j].coordinates) == 6) && (InRange(get<0>(WPawns[j].coordinates),atackers[0][0], get<0>(WKings[0].coordinates) ) 
                && InRange(get<1>(WPawns[j].coordinates)-2,atackers[0][1], get<1>(WKings[0].coordinates) )
                && abs(get<1>(WKings[0].coordinates) - (get<1>(WPawns[j].coordinates)-2)) == abs(get<0>(WKings[0].coordinates) - get<0>(WPawns[j].coordinates)))){
                    PawnsCopy[j].Predicthion.push_back({get<0>(WPawns[j].coordinates), get<1>(WPawns[j].coordinates)-2});
                }
            }
            for (size_t j = 0; j < WRooks.size(); j++)
            {
                RooksCopy[j].Predicthion = {};
                for (size_t i =0; i<WRooks[j].Predicthion.size(); i++){
                    if (InRange(WRooks[j].Predicthion[i][0],atackers[0][0], get<0>(WKings[0].coordinates) ) 
                    && InRange(WRooks[j].Predicthion[i][1],atackers[0][1], get<1>(WKings[0].coordinates) ) 
                    && abs(get<1>(WKings[0].coordinates) - WRooks[j].Predicthion[i][1]) == abs(get<0>(WKings[0].coordinates) - WRooks[j].Predicthion[i][0])){
                        RooksCopy[j].Predicthion.push_back(WRooks[j].Predicthion[i]);
                    }
                    if (InRange(WRooks[j].Predicthion[i][0],atackers[0][0], get<0>(WKings[0].coordinates) ) 
                    && InRange(WRooks[j].Predicthion[i][1],atackers[0][1], get<1>(WKings[0].coordinates) ) 
                    && abs(get<1>(WKings[0].coordinates) - WRooks[j].Predicthion[i][1]) == abs(get<0>(WKings[0].coordinates) - WRooks[j].Predicthion[i][0])){
                        RooksCopy[j].Predicthion.push_back(WRooks[j].Predicthion[i]);
                    }
                }

            }
            for (size_t j = 0; j < WBishops.size(); j++)
            {
                BishopsCopy[j].Predicthion = {};
                for (size_t i =0; i<WBishops[j].Predicthion.size(); i++){
                    if (InRange(WBishops[j].Predicthion[i][0],atackers[0][0], get<0>(WKings[0].coordinates) ) 
                    && InRange(WBishops[j].Predicthion[i][1],atackers[0][1], get<1>(WKings[0].coordinates) ) 
                    && abs(get<1>(WKings[0].coordinates) - WBishops[j].Predicthion[i][1]) == abs(get<0>(WKings[0].coordinates) - WBishops[j].Predicthion[i][0])){
                        BishopsCopy[j].Predicthion.push_back(WBishops[j].Predicthion[i]);
                    }
                    if (InRange(WBishops[j].Predicthion[i][0],atackers[0][0], get<0>(WKings[0].coordinates) ) 
                    && InRange(WBishops[j].Predicthion[i][1],atackers[0][1], get<1>(WKings[0].coordinates) ) 
                    && abs(get<1>(WKings[0].coordinates) - WBishops[j].Predicthion[i][1]) == abs(get<0>(WKings[0].coordinates) - WBishops[j].Predicthion[i][0])){
                        BishopsCopy[j].Predicthion.push_back(WBishops[j].Predicthion[i]);
                    }
                }

            }
            for (size_t j = 0; j < WKnights.size(); j++){
                KnightsCopy[j].Predicthion = {};
                for (size_t i =0; i<WKnights[j].Predicthion.size(); i++){
                    if (InRange(WKnights[j].Predicthion[i][0],atackers[0][0], get<0>(WKings[0].coordinates) ) 
                    && InRange(WKnights[j].Predicthion[i][1],atackers[0][1], get<1>(WKings[0].coordinates) ) 
                    && abs(get<1>(WKings[0].coordinates) - WKnights[j].Predicthion[i][1]) == abs(get<0>(WKings[0].coordinates) - WKnights[j].Predicthion[i][0])){
                        KnightsCopy[j].Predicthion.push_back(WKnights[j].Predicthion[i]);
                    }
                    if (InRange(WKnights[j].Predicthion[i][0],atackers[0][0], get<0>(WKings[0].coordinates) ) 
                    && InRange(WKnights[j].Predicthion[i][1],atackers[0][1], get<1>(WKings[0].coordinates) ) 
                    && abs(get<1>(WKings[0].coordinates) - WKnights[j].Predicthion[i][1]) == abs(get<0>(WKings[0].coordinates) - WKnights[j].Predicthion[i][0])){
                        KnightsCopy[j].Predicthion.push_back(WKnights[j].Predicthion[i]);
                    }
                }
            }
            for (size_t j = 0; j < WQueens.size(); j++)
            {
                QueensCopy[j].Predicthion ={};
                for (size_t i =0; i<WQueens[j].Predicthion.size(); i++){
                   if (InRange(WQueens[j].Predicthion[i][0],atackers[0][0], get<0>(WKings[0].coordinates) ) 
                   && InRange(WQueens[j].Predicthion[i][1],atackers[0][1], get<1>(WKings[0].coordinates) ) 
                   && abs(get<1>(WKings[0].coordinates) - WQueens[j].Predicthion[i][1]) == abs(get<0>(WKings[0].coordinates) - WQueens[j].Predicthion[i][0])){
                        QueensCopy[j].Predicthion.push_back(WQueens[j].Predicthion[i]);
                    }
                    if (InRange(WQueens[j].Predicthion[i][0],atackers[0][0], get<0>(WKings[0].coordinates) ) 
                    && InRange(WQueens[j].Predicthion[i][1],atackers[0][1], get<1>(WKings[0].coordinates) ) 
                    && abs(get<1>(WKings[0].coordinates) - WQueens[j].Predicthion[i][1]) == abs(get<0>(WKings[0].coordinates) - WQueens[j].Predicthion[i][0])){
                        QueensCopy[j].Predicthion.push_back(WQueens[j].Predicthion[i]);
                    }
                }

            }

        }
        else  if (atackers[0][2] == (int)'q'){
            for (size_t j = 0; j < WPawns.size(); j++){
                PawnsCopy[j].Predicthion = {};
                if ((get<1>(WPawns[j].coordinates)-1 >=0) 
                && (atackers[0][0] == get<0>(WPawns[j].coordinates) == get<0>(WKings[0].coordinates) 
                && InRange(get<1>(WPawns[j].coordinates)-1, atackers[0][1], get<1>(WKings[0].coordinates) ))){
                    PawnsCopy[j].Predicthion.push_back({get<0>(WPawns[j].coordinates), get<1>(WPawns[j].coordinates)-1});
                }
                else if ((get<1>(WPawns[j].coordinates)-1 >=0) 
                && (atackers[0][1] == get<1>(WPawns[j].coordinates)-1  == get<1>(WKings[0].coordinates)
                && InRange(get<0>(WPawns[j].coordinates), atackers[0][0], get<0>(WKings[0].coordinates) ))){
                    PawnsCopy[j].Predicthion.push_back({get<0>(WPawns[j].coordinates), get<1>(WPawns[j].coordinates)-1});
                }

                if ((get<1>(WPawns[j].coordinates) == 6) && (get<1>(WPawns[j].coordinates)-1 >=0) 
                && (atackers[0][0] == get<0>(WPawns[j].coordinates) == get<0>(WKings[0].coordinates) 
                && InRange(get<1>(WPawns[j].coordinates)-1, atackers[0][1], get<1>(WKings[0].coordinates) ))){
                    PawnsCopy[j].Predicthion.push_back({get<0>(WPawns[j].coordinates), get<1>(WPawns[j].coordinates)-1});
                }
                else if ((get<1>(WPawns[j].coordinates) == 6) && (get<1>(WPawns[j].coordinates)-1 >=0) 
                && (atackers[0][1] == get<1>(WPawns[j].coordinates)-1  == get<1>(WKings[0].coordinates)
                && InRange(get<0>(WPawns[j].coordinates), atackers[0][0], get<0>(WKings[0].coordinates) ))){
                    PawnsCopy[j].Predicthion.push_back({get<0>(WPawns[j].coordinates), get<1>(WPawns[j].coordinates)-1});
                }

                if ((InRange(get<0>(WPawns[j].coordinates),atackers[0][0], get<0>(WKings[0].coordinates) ) 
                && InRange(get<1>(WPawns[j].coordinates)-1,atackers[0][1], get<1>(WKings[0].coordinates) ) 
                && abs(get<1>(WKings[0].coordinates) - (get<1>(WPawns[j].coordinates)-1)) == abs(get<0>(WKings[0].coordinates) - get<0>(WPawns[j].coordinates)))){
                    PawnsCopy[j].Predicthion.push_back({get<0>(WPawns[j].coordinates), get<1>(WPawns[j].coordinates)-1});
                }
                else if ((get<1>(WPawns[j].coordinates) == 6) && (InRange(get<0>(WPawns[j].coordinates),atackers[0][0], get<0>(WKings[0].coordinates) ) 
                && InRange(get<1>(WPawns[j].coordinates)-2,atackers[0][1], get<1>(WKings[0].coordinates) ) 
                && abs(get<1>(WKings[0].coordinates) - (get<1>(WPawns[j].coordinates)-2)) == abs(get<0>(WKings[0].coordinates) - get<0>(WPawns[j].coordinates)))){
                    PawnsCopy[j].Predicthion.push_back({get<0>(WPawns[j].coordinates), get<1>(WPawns[j].coordinates)-2});
                }
            }
            for (size_t j = 0; j < WRooks.size(); j++)
            {
                RooksCopy[j].Predicthion = {};
                for (size_t i =0; i<WRooks[j].Predicthion.size(); i++){
                    if ((atackers[0][0] == WRooks[j].Predicthion[i][0] == get<0>(WKings[0].coordinates) 
                    && InRange(WRooks[j].Predicthion[i][1],atackers[0][1], get<1>(WKings[0].coordinates) ))){
                        RooksCopy[j].Predicthion.push_back(WRooks[j].Predicthion[i]);
                    }
                    else if ((atackers[0][1] == WRooks[j].Predicthion[i][1] == get<1>(WKings[0].coordinates) 
                    && InRange(WRooks[j].Predicthion[i][0],atackers[0][0], get<0>(WKings[0].coordinates) ))){
                        RooksCopy[j].Predicthion.push_back(WRooks[j].Predicthion[i]);
                    }

                    if (InRange(WRooks[j].Predicthion[i][0],atackers[0][0], get<0>(WKings[0].coordinates) ) 
                    && InRange(WRooks[j].Predicthion[i][1],atackers[0][1], get<1>(WKings[0].coordinates) ) 
                    && abs(get<1>(WKings[0].coordinates) - WRooks[j].Predicthion[i][1]) == abs(get<0>(WKings[0].coordinates) - WRooks[j].Predicthion[i][0])){
                        RooksCopy[j].Predicthion.push_back(WRooks[j].Predicthion[i]);
                    }
                }

            }
            for (size_t j = 0; j < WBishops.size(); j++)
            {
                BishopsCopy[j].Predicthion = {};
                for (size_t i =0; i<WBishops[j].Predicthion.size(); i++){
                    if ((atackers[0][0] == WBishops[j].Predicthion[i][0] == get<0>(WKings[0].coordinates) 
                    && InRange(WBishops[j].Predicthion[i][1],atackers[0][1], get<1>(WKings[0].coordinates) ))){
                        BishopsCopy[j].Predicthion.push_back(WBishops[j].Predicthion[i]);
                    }
                    else if ((atackers[0][1] == WBishops[j].Predicthion[i][1] == get<1>(WKings[0].coordinates) 
                    && InRange(WBishops[j].Predicthion[i][0],atackers[0][0], get<0>(WKings[0].coordinates) ))){
                        BishopsCopy[j].Predicthion.push_back(WBishops[j].Predicthion[i]);
                    }

                    if (InRange(WBishops[j].Predicthion[i][0],atackers[0][0], get<0>(WKings[0].coordinates) ) 
                    && InRange(WBishops[j].Predicthion[i][1],atackers[0][1], get<1>(WKings[0].coordinates) ) 
                    && abs(get<1>(WKings[0].coordinates) - WBishops[j].Predicthion[i][1]) == abs(get<0>(WKings[0].coordinates) - WBishops[j].Predicthion[i][0])){
                        BishopsCopy[j].Predicthion.push_back(WBishops[j].Predicthion[i]);
                    }
                    
                }

            }
            for (size_t j = 0; j < WKnights.size(); j++){
                KnightsCopy[j].Predicthion = {};
                for (size_t i =0; i<WKnights[j].Predicthion.size(); i++){
                    if ((atackers[0][0] == WKnights[j].Predicthion[i][0] == get<0>(WKings[0].coordinates) 
                    && InRange(WKnights[j].Predicthion[i][1],atackers[0][1], get<1>(WKings[0].coordinates) ))){
                        KnightsCopy[j].Predicthion.push_back(WKnights[j].Predicthion[i]);
                    }
                    else if ((atackers[0][1] == WKnights[j].Predicthion[i][1] == get<1>(WKings[0].coordinates) 
                    && InRange(WKnights[j].Predicthion[i][0],atackers[0][0], get<0>(WKings[0].coordinates) ))){
                        KnightsCopy[j].Predicthion.push_back(WKnights[j].Predicthion[i]);
                    }

                    if (InRange(WKnights[j].Predicthion[i][0],atackers[0][0], get<0>(WKings[0].coordinates) ) 
                    && InRange(WKnights[j].Predicthion[i][1],atackers[0][1], get<1>(WKings[0].coordinates) ) 
                    && abs(get<1>(WKings[0].coordinates) - WKnights[j].Predicthion[i][1]) == abs(get<0>(WKings[0].coordinates) - WKnights[j].Predicthion[i][0])){
                        KnightsCopy[j].Predicthion.push_back(WKnights[j].Predicthion[i]);
                    }
                }
            }
            for (size_t j = 0; j < WQueens.size(); j++)
            {
                QueensCopy[j].Predicthion ={};
                for (size_t i =0; i<WQueens[j].Predicthion.size(); i++){
                    if ((atackers[0][0] == WQueens[j].Predicthion[i][0] == get<0>(WKings[0].coordinates) 
                    && InRange(WQueens[j].Predicthion[i][1],atackers[0][1], get<1>(WKings[0].coordinates) ))){
                        QueensCopy[j].Predicthion.push_back(WQueens[j].Predicthion[i]);
                    }
                    else if ((atackers[0][1] == WQueens[j].Predicthion[i][1] == get<1>(WKings[0].coordinates) 
                    && InRange(WQueens[j].Predicthion[i][0],atackers[0][0], get<0>(WKings[0].coordinates) ))){
                        QueensCopy[j].Predicthion.push_back(WQueens[j].Predicthion[i]);
                    }


                    if (InRange(WQueens[j].Predicthion[i][0],atackers[0][0], get<0>(WKings[0].coordinates) ) 
                    && InRange(WQueens[j].Predicthion[i][1],atackers[0][1], get<1>(WKings[0].coordinates) ) 
                    && abs(get<1>(WKings[0].coordinates) - WQueens[j].Predicthion[i][1]) == abs(get<0>(WKings[0].coordinates) - WQueens[j].Predicthion[i][0])){
                        QueensCopy[j].Predicthion.push_back(WQueens[j].Predicthion[i]);
                    }

                }

            }
            
        }
    
//---------------------------------------------------------------------------
        for (size_t j = 0; j < WPawns.size(); j++)
        {
            if ((get<0>(WPawns[j].coordinates)-1 == atackers[0][0] && (get<1>(WPawns[j].coordinates))-1 == atackers[0][1])){
                PawnsCopy[j].Predicthion.push_back({get<0>(WPawns[j].coordinates)-1, get<1>(WPawns[j].coordinates)-1} );
            }
            else if ((get<0>(WPawns[j].coordinates)+1 == atackers[0][0] && (get<1>(WPawns[j].coordinates))-1 == atackers[0][1])){
                PawnsCopy[j].Predicthion.push_back({get<0>(WPawns[j].coordinates)+1, get<1>(WPawns[j].coordinates)-1} );
            }

        }
        for (size_t j = 0; j < WRooks.size(); j++)
        {
            for (size_t i = 0; i <WRooks[j].Predicthion.size(); i++){
                if ((WRooks[j].Predicthion[i][0] == atackers[0][0] && WRooks[j].Predicthion[i][1] == atackers[0][1])){
                    RooksCopy[j].Predicthion.push_back({WRooks[j].Predicthion[i][0], WRooks[j].Predicthion[i][1]});
                }
            }
        }
        for (size_t j = 0; j < WKnights.size(); j++)
        {
            for (size_t i = 0; i <WKnights[j].Predicthion.size(); i++){
                if ((WKnights[j].Predicthion[i][0] == atackers[0][0] && WKnights[j].Predicthion[i][1] == atackers[0][1])){
                    KnightsCopy[j].Predicthion.push_back({WKnights[j].Predicthion[i][0], WKnights[j].Predicthion[i][1]});
                }
            }
        }
        for (size_t j = 0; j < WBishops.size(); j++)
        {
            for (size_t i = 0; i <WBishops[j].Predicthion.size(); i++){
                if ((WBishops[j].Predicthion[i][0] == atackers[0][0] && WBishops[j].Predicthion[i][1] == atackers[0][1])){
                    BishopsCopy[j].Predicthion.push_back({WBishops[j].Predicthion[i][0], WBishops[j].Predicthion[i][1]});
                }
            }
        }
        for (size_t j = 0; j < WQueens.size(); j++)
        {
            for (size_t i = 0; i <WQueens[j].Predicthion.size(); i++){
                if ((WQueens[j].Predicthion[i][0] == atackers[0][0] && WQueens[j].Predicthion[i][1] == atackers[0][1])){
                    QueensCopy[j].Predicthion.push_back({WQueens[j].Predicthion[i][0], WQueens[j].Predicthion[i][1]});
                }
            }
        }
        pieces = {PawnsCopy, RooksCopy, KnightsCopy, BishopsCopy, QueensCopy};
        return pieces;
    }
}

bool idk (vector<BPawn> BPawns, vector<BRook> BRooks, vector<BKnight> BKnights, vector<BBishop> BBishops, vector<BQueen> BQueens, vector<WKing> WKings,  vector<vector<char>> board){
        vector<vector<char>> WDead = { {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','X','X','X','.','.'},
    {'.','.','.','X','.','X','.', '.'} };
        tuple<vector<vector<int>>, vector<vector<char>>> func;
        for (int i =0; i < BPawns.size(); i++){
            func = BPawns[i].predicthion(BPawns[i].coordinates, board, WDead);
            BPawns[i].Predicthion = get<0>(func);
            WDead = get<1>(func);
        }
        for (int i =0; i <BRooks.size(); i++){
            func = BRooks[i].predicthion(BRooks[i].coordinates, board, WDead);
            BRooks[i].Predicthion = get<0>(func) ;
            WDead = get<1>(func);
        }
        for (int i =0; i <BKnights.size(); i++){
            func = BKnights[i].predicthion(BKnights[i].coordinates, board, WDead);
            BKnights[i].Predicthion = get<0>(func);
            WDead = get<1>(func);
        }
        for (int i =0; i <BBishops.size(); i++){
            func = BBishops[i].predicthion(BBishops[i].coordinates, board, WDead);
            BBishops[i].Predicthion = get<0>(func);
            WDead = get<1>(func);
        }
        for (int i =0; i <BQueens.size(); i++){
            func = BQueens[i].predicthion(BQueens[i].coordinates, board, WDead);
            BQueens[i].Predicthion = get<0>(func);
            WDead = get<1>(func);
        }
        if (WDead[get<1>(WKings[0].coordinates)][get<0>(WKings[0].coordinates)] == 'X'){
            return true;
        }
        else{
            return false;
        }

}
    // После того, как прогрма определит атакующих, нужно проверить их количество, если атакующих 2, и более, нужно удалить все возможные ходы кроме ходов короля, при количстве 
    // атакующих равнаму 1, нужно найти лишь те ходы, которые перекрывают короля

// дописати класи для слона, короля й королеви
vector<char> enter() {
    string move;
    cin >> move;
    vector<char> data(move.begin(), move.end());

    return data;
}
vector<WPawn> makeTurn(vector<char> move, vector <WPawn> piece) {
    move[0] = ((int)move[0] - 97);
    move[1] = 7 - ((int)move[1] - (int)'1');
    for (size_t i = 0; i < piece.size(); i++) {
        for (size_t j = 0; j < piece[i].Predicthion.size(); j++) {
            if (piece[i].Predicthion[j][0] == move[0] && piece[i].Predicthion[j][1] == move[1]) {
                get<0>(piece[i].coordinates) = move[0];
                get<1>(piece[i].coordinates) = move[1];
                return piece;
            }
        }
    }
}

vector<BPawn> makeTurn(vector<char> move, vector <BPawn> piece) {
    move[0] = ((int)move[0] - 97);
    move[1] = 7 - ((int)move[1] - (int)'1');
    for (size_t i = 0; i < piece.size(); i++) {
        for (size_t j = 0; j < piece[i].Predicthion.size(); j++) {
            if (piece[i].Predicthion[j][0] == move[0] && piece[i].Predicthion[j][1] == move[1]) {
                get<0>(piece[i].coordinates) = move[0];
                get<1>(piece[i].coordinates) = move[1];
                return piece;
            }
        }
    }
}

vector<WRook> makeTurn(vector<char> move, vector <WRook> piece) {
    move[1] = ((int)move[1] - 97);
    move[2] = 7 - ((int)move[2] - (int)'1');
    for (size_t i = 0; i < piece.size(); i++) {
        for (size_t j = 0; j < piece[i].Predicthion.size(); j++) {
            if (piece[i].Predicthion[j][0] == move[1] && piece[i].Predicthion[j][1] == move[2]) {
                get<0>(piece[i].coordinates) = move[1];
                get<1>(piece[i].coordinates) = move[2];
                return piece;
            }
        }
    }
}

vector<BRook> makeTurn(vector<char> move, vector <BRook> piece) {
    move[1] = ((int)move[1] - 97);
    move[2] = 7 - ((int)move[2] - (int)'1');
    for (size_t i = 0; i < piece.size(); i++) {
        for (size_t j = 0; j < piece[i].Predicthion.size(); j++) {
            if (piece[i].Predicthion[j][0] == move[1] && piece[i].Predicthion[j][1] == move[2]) {
                get<0>(piece[i].coordinates) = move[1];
                get<1>(piece[i].coordinates) = move[2];
                return piece;
            }
        }
    }
}

vector<BKnight> makeTurn(vector<char> move, vector <BKnight> piece) {
    move[1] = ((int)move[2] - 97);
    move[2] = 7 - ((int)move[3] - (int)'1');
    for (size_t i = 0; i < piece.size(); i++) {
        for (size_t j = 0; j < piece[i].Predicthion.size(); j++) {
            if (piece[i].Predicthion[j][0] == move[2] && piece[i].Predicthion[j][1] == move[3]) {
                get<0>(piece[i].coordinates) = move[2];
                get<1>(piece[i].coordinates) = move[3];
                return piece;
            }
        }
    }
}

vector<WKnight> makeTurn(vector<char> move, vector <WKnight> piece) {
    move[2] = ((int)move[2] - 97);
    move[3] = 7 - ((int)move[3] - (int)'1');
    for (size_t i = 0; i < piece.size(); i++) {
        for (size_t j = 0; j < piece[i].Predicthion.size(); j++) {
            if (piece[i].Predicthion[j][0] == move[2] && piece[i].Predicthion[j][1] == move[3]) {
                get<0>(piece[i].coordinates) = move[2];
                get<1>(piece[i].coordinates) = move[3];
                return piece;
            }
        }
    }
}

vector<BBishop> makeTurn(vector<char> move, vector <BBishop> piece) {
    move[1] = ((int)move[1] - 97);
    move[2] = 7 - ((int)move[2] - (int)'1');
    for (size_t i = 0; i < piece.size(); i++) {
        for (size_t j = 0; j < piece[i].Predicthion.size(); j++) {
            if (piece[i].Predicthion[j][0] == move[1] && piece[i].Predicthion[j][1] == move[2]) {
                get<0>(piece[i].coordinates) = move[1];
                get<1>(piece[i].coordinates) = move[2];
                return piece;
            }
        }
    }
}

vector<WBishop> makeTurn(vector<char> move, vector <WBishop> piece) {
    move[1] = ((int)move[1] - 97);
    move[2] = 7 - ((int)move[2] - (int)'1');
    for (size_t i = 0; i < piece.size(); i++) {
        for (size_t j = 0; j < piece[i].Predicthion.size(); j++) {
            if (piece[i].Predicthion[j][0] == move[1] && piece[i].Predicthion[j][1] == move[2]) {
                get<0>(piece[i].coordinates) = move[1];
                get<1>(piece[i].coordinates) = move[2];
                return piece;
            }
        }
    }
}

vector<BQueen> makeTurn(vector<char> move, vector<BQueen> piece) {
    move[1] = ((int)move[1] - 97);
    move[2] = 7 - ((int)move[2] - (int)'1');
    for (size_t i = 0; i < piece.size(); i++) {
        for (size_t j = 0; j < piece[i].Predicthion.size(); j++) {
            if (piece[i].Predicthion[j][0] == move[1] && piece[i].Predicthion[j][1] == move[2]) {
                get<0>(piece[i].coordinates) = move[1];
                get<1>(piece[i].coordinates) = move[2];
                return piece;
            }
        }
    }
}

vector<WQueen> makeTurn(vector<char> move, vector <WQueen> piece) {
    move[1] = ((int)move[1] - 97);
    move[2] = 7 - ((int)move[2] - (int)'1');
    for (size_t i = 0; i < piece.size(); i++) {
        for (size_t j = 0; j < piece[i].Predicthion.size(); j++) {
            if (piece[i].Predicthion[j][0] == move[1] && piece[i].Predicthion[j][1] == move[2]) {
                get<0>(piece[i].coordinates) = move[1];
                get<1>(piece[i].coordinates) = move[2];
                return piece;
            }
        }
    }
}

vector <BKing> makeTurn(vector<char> move, vector <BKing> piece) {
    move[1] = ((int)move[1] - 97);
    move[2] = 7 - ((int)move[2] - (int)'1');

    for (size_t j = 0; j < piece[0].Predicthion.size(); j++) {
        if (piece[0].Predicthion[j][0] == move[1] && piece[0].Predicthion[j][1] == move[2]) {
            get<0>(piece[0].coordinates) = move[1];
            get<1>(piece[0].coordinates) = move[2];
            return piece;
        }
    }
}

vector <WKing> makeTurn(vector<char> move, vector <WKing> piece) {
    move[1] = ((int)move[1] - 97);
    move[2] = 7 - ((int)move[2] - (int)'1');
    for (size_t j = 0; j < piece[0].Predicthion.size(); j++) {
        if (piece[0].Predicthion[j][0] == move[1] && piece[0].Predicthion[j][1] == move[2]) {
            get<0>(piece[0].coordinates) = move[1];
            get<1>(piece[0].coordinates) = move[2];
            return piece;
        }
    }
}
tuple <vector <WPawn>, vector <WRook>, vector <WKnight>, vector <WBishop>, vector <WQueen>, vector <WKing>, vector <BPawn>, vector <BRook>, vector <BKnight>, vector <BBishop>, vector <BQueen>, vector <BKing>>  captured(vector <WPawn> WPawns, vector <WRook> WRooks, vector <WKnight> WKnights, vector <WBishop> WBishops, vector <WQueen> WQueens, vector <WKing> WKings, vector <BPawn> BPawns, vector <BRook> BRooks, vector <BKnight> BKnights, vector <BBishop> BBishops, vector <BQueen> BQueens, vector <BKing> BKings, string piece) {
    tuple <vector <WPawn>, vector <WRook>, vector <WKnight>, vector <WBishop>, vector <WQueen>, vector <WKing>, vector <BPawn>, vector <BRook>, vector <BKnight>, vector <BBishop>, vector <BQueen>, vector <BKing>> a;
    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
    if (piece == "WPawn") {
        for (size_t i = 0; i < WPawns.size(); i++) {
            for (size_t q = 0; q < BPawns.size(); q++) {
                if (get<0>(WPawns[i].coordinates) == get<0>(BPawns[q].coordinates) && get<1>(WPawns[i].coordinates) == get<1>(BPawns[q].coordinates)) {
                    BPawns.erase(BPawns.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < BRooks.size(); q++) {
                if (get<0>(WPawns[i].coordinates) == get<0>(BRooks[q].coordinates) && get<1>(WPawns[i].coordinates) == get<1>(BRooks[q].coordinates)) {
                    BRooks.erase(BRooks.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < BKnights.size(); q++) {
                if (get<0>(WPawns[i].coordinates) == get<0>(BKnights[q].coordinates) && get<1>(WPawns[i].coordinates) == get<1>(BKnights[q].coordinates)) {
                    BKnights.erase(BKnights.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < BBishops.size(); q++) {
                if (get<0>(WPawns[i].coordinates) == get<0>(BBishops[q].coordinates) && get<1>(WPawns[i].coordinates) == get<1>(BBishops[q].coordinates)) {
                    BBishops.erase(BBishops.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < BQueens.size(); q++) {
                if (get<0>(WPawns[i].coordinates) == get<0>(BQueens[q].coordinates) && get<1>(WPawns[i].coordinates) == get<1>(BQueens[q].coordinates)) {
                    BQueens.erase(BQueens.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
        }
    }
    else if (piece == "WRook") {
        for (size_t i = 0; i < WRooks.size(); i++) {
            for (size_t q = 0; q < BPawns.size(); q++) {
                if (get<0>(WRooks[i].coordinates) == get<0>(BPawns[q].coordinates) && get<1>(WRooks[i].coordinates) == get<1>(BPawns[q].coordinates)) {
                    BPawns.erase(BPawns.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < BRooks.size(); q++) {
                if (get<0>(WRooks[i].coordinates) == get<0>(BRooks[q].coordinates) && get<1>(WRooks[i].coordinates) == get<1>(BRooks[q].coordinates)) {
                    BRooks.erase(BRooks.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < BKnights.size(); q++) {
                if (get<0>(WRooks[i].coordinates) == get<0>(BKnights[q].coordinates) && get<1>(WRooks[i].coordinates) == get<1>(BKnights[q].coordinates)) {
                    BKnights.erase(BKnights.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < BBishops.size(); q++) {
                if (get<0>(WRooks[i].coordinates) == get<0>(BBishops[q].coordinates) && get<1>(WRooks[i].coordinates) == get<1>(BBishops[q].coordinates)) {
                    BBishops.erase(BBishops.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < BQueens.size(); q++) {
                if (get<0>(WRooks[i].coordinates) == get<0>(BQueens[q].coordinates) && get<1>(WRooks[i].coordinates) == get<1>(BQueens[q].coordinates)) {
                    BQueens.erase(BQueens.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
        }

    }
    else if (piece == "WKnight") {
        for (size_t i = 0; i < WKnights.size(); i++) {
            for (size_t q = 0; q < BPawns.size(); q++) {
                if (get<0>(WKnights[i].coordinates) == get<0>(BPawns[q].coordinates) && get<1>(WKnights[i].coordinates) == get<1>(BPawns[q].coordinates)) {
                    BPawns.erase(BPawns.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < BRooks.size(); q++) {
                if (get<0>(WKnights[i].coordinates) == get<0>(BRooks[q].coordinates) && get<1>(WKnights[i].coordinates) == get<1>(BRooks[q].coordinates)) {
                    BRooks.erase(BRooks.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < BKnights.size(); q++) {
                if (get<0>(WKnights[i].coordinates) == get<0>(BKnights[q].coordinates) && get<1>(WKnights[i].coordinates) == get<1>(BKnights[q].coordinates)) {
                    BKnights.erase(BKnights.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < BBishops.size(); q++) {
                if (get<0>(WKnights[i].coordinates) == get<0>(BBishops[q].coordinates) && get<1>(WKnights[i].coordinates) == get<1>(BBishops[q].coordinates)) {
                    BBishops.erase(BBishops.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < BQueens.size(); q++) {
                if (get<0>(WKnights[i].coordinates) == get<0>(BQueens[q].coordinates) && get<1>(WKnights[i].coordinates) == get<1>(BQueens[q].coordinates)) {
                    BQueens.erase(BQueens.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
        }
    }
    else if (piece == "WBishop") {
        for (size_t i = 0; i < WBishops.size(); i++) {
            for (size_t q = 0; q < BPawns.size(); q++) {
                if (get<0>(WBishops[i].coordinates) == get<0>(BPawns[q].coordinates) && get<1>(WBishops[i].coordinates) == get<1>(BPawns[q].coordinates)) {
                    BPawns.erase(BPawns.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < BRooks.size(); q++) {
                if (get<0>(WBishops[i].coordinates) == get<0>(BRooks[q].coordinates) && get<1>(WBishops[i].coordinates) == get<1>(BRooks[q].coordinates)) {
                    BRooks.erase(BRooks.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < BKnights.size(); q++) {
                if (get<0>(WBishops[i].coordinates) == get<0>(BKnights[q].coordinates) && get<1>(WBishops[i].coordinates) == get<1>(BKnights[q].coordinates)) {
                    BKnights.erase(BKnights.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < BBishops.size(); q++) {
                if (get<0>(WBishops[i].coordinates) == get<0>(BBishops[q].coordinates) && get<1>(WBishops[i].coordinates) == get<1>(BBishops[q].coordinates)) {
                    BBishops.erase(BBishops.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < BQueens.size(); q++) {
                if (get<0>(WBishops[i].coordinates) == get<0>(BQueens[q].coordinates) && get<1>(WBishops[i].coordinates) == get<1>(BQueens[q].coordinates)) {
                    BQueens.erase(BQueens.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
        }

    }
    else if (piece == "WQueen") {
        for (size_t i = 0; i < WQueens.size(); i++) {
            for (size_t q = 0; q < BPawns.size(); q++) {
                if (get<0>(WQueens[i].coordinates) == get<0>(BPawns[q].coordinates) && get<1>(WQueens[i].coordinates) == get<1>(BPawns[q].coordinates)) {
                    BPawns.erase(BPawns.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < BRooks.size(); q++) {
                if (get<0>(WQueens[i].coordinates) == get<0>(BRooks[q].coordinates) && get<1>(WQueens[i].coordinates) == get<1>(BRooks[q].coordinates)) {
                    BRooks.erase(BRooks.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < BKnights.size(); q++) {
                if (get<0>(WQueens[i].coordinates) == get<0>(BKnights[q].coordinates) && get<1>(WQueens[i].coordinates) == get<1>(BKnights[q].coordinates)) {
                    BKnights.erase(BKnights.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < BBishops.size(); q++) {
                if (get<0>(WQueens[i].coordinates) == get<0>(BBishops[q].coordinates) && get<1>(WQueens[i].coordinates) == get<1>(BBishops[q].coordinates)) {
                    BBishops.erase(BBishops.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < BQueens.size(); q++) {
                if (get<0>(WQueens[i].coordinates) == get<0>(BQueens[q].coordinates) && get<1>(WQueens[i].coordinates) == get<1>(BQueens[q].coordinates)) {
                    BQueens.erase(BQueens.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
        }
    }
    else if (piece == "WKing") {
        for (size_t i = 0; i < WKings.size(); i++) {
            for (size_t q = 0; q < BPawns.size(); q++) {
                if (get<0>(WKings[i].coordinates) == get<0>(BPawns[q].coordinates) && get<1>(WKings[i].coordinates) == get<1>(BPawns[q].coordinates)) {
                    BPawns.erase(BPawns.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < BRooks.size(); q++) {
                if (get<0>(WKings[i].coordinates) == get<0>(BRooks[q].coordinates) && get<1>(WKings[i].coordinates) == get<1>(BRooks[q].coordinates)) {
                    BRooks.erase(BRooks.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < BKnights.size(); q++) {
                if (get<0>(WKings[i].coordinates) == get<0>(BKnights[q].coordinates) && get<1>(WKings[i].coordinates) == get<1>(BKnights[q].coordinates)) {
                    BKnights.erase(BKnights.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < BBishops.size(); q++) {
                if (get<0>(WKings[i].coordinates) == get<0>(BBishops[q].coordinates) && get<1>(WKings[i].coordinates) == get<1>(BBishops[q].coordinates)) {
                    BBishops.erase(BBishops.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < BQueens.size(); q++) {
                if (get<0>(WKings[i].coordinates) == get<0>(BQueens[q].coordinates) && get<1>(WKings[i].coordinates) == get<1>(BQueens[q].coordinates)) {
                    BQueens.erase(BQueens.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
        }
    }
    else if (piece == "BPawn") {
        for (size_t i = 0; i < BPawns.size(); i++) {
            for (size_t q = 0; q < WPawns.size(); q++) {
                if (get<0>(BPawns[i].coordinates) == get<0>(WPawns[q].coordinates) && get<1>(BPawns[i].coordinates) == get<1>(WPawns[q].coordinates)) {
                    WPawns.erase(WPawns.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < WRooks.size(); q++) {
                if (get<0>(BPawns[i].coordinates) == get<0>(WRooks[q].coordinates) && get<1>(BPawns[i].coordinates) == get<1>(WRooks[q].coordinates)) {
                    WRooks.erase(WRooks.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < WKnights.size(); q++) {
                if (get<0>(BPawns[i].coordinates) == get<0>(WKnights[q].coordinates) && get<1>(BPawns[i].coordinates) == get<1>(WKnights[q].coordinates)) {
                    WKnights.erase(WKnights.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < WBishops.size(); q++) {
                if (get<0>(BPawns[i].coordinates) == get<0>(WBishops[q].coordinates) && get<1>(BPawns[i].coordinates) == get<1>(WBishops[q].coordinates)) {
                    WBishops.erase(WBishops.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < WQueens.size(); q++) {
                if (get<0>(BPawns[i].coordinates) == get<0>(WQueens[q].coordinates) && get<1>(BPawns[i].coordinates) == get<1>(WQueens[q].coordinates)) {
                    WQueens.erase(WQueens.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
        }
    }
    else if (piece == "BRooks") {
        for (size_t i = 0; i < BRooks.size(); i++) {
            for (size_t q = 0; q < WPawns.size(); q++) {
                if (get<0>(BRooks[i].coordinates) == get<0>(WPawns[q].coordinates) && get<1>(BRooks[i].coordinates) == get<1>(WPawns[q].coordinates)) {
                    WPawns.erase(WPawns.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < WRooks.size(); q++) {
                if (get<0>(BRooks[i].coordinates) == get<0>(WRooks[q].coordinates) && get<1>(BRooks[i].coordinates) == get<1>(WRooks[q].coordinates)) {
                    WRooks.erase(WRooks.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < WKnights.size(); q++) {
                if (get<0>(BRooks[i].coordinates) == get<0>(WKnights[q].coordinates) && get<1>(BRooks[i].coordinates) == get<1>(WKnights[q].coordinates)) {
                    WKnights.erase(WKnights.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < WBishops.size(); q++) {
                if (get<0>(BRooks[i].coordinates) == get<0>(WBishops[q].coordinates) && get<1>(BRooks[i].coordinates) == get<1>(WBishops[q].coordinates)) {
                    WBishops.erase(WBishops.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < WQueens.size(); q++) {
                if (get<0>(BRooks[i].coordinates) == get<0>(WQueens[q].coordinates) && get<1>(BRooks[i].coordinates) == get<1>(WQueens[q].coordinates)) {
                    WQueens.erase(WQueens.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
        }
    }
    else if (piece == "BKnights") {
        for (size_t i = 0; i < BKnights.size(); i++) {
            for (size_t q = 0; q < WPawns.size(); q++) {
                if (get<0>(BKnights[i].coordinates) == get<0>(WPawns[q].coordinates) && get<1>(BKnights[i].coordinates) == get<1>(WPawns[q].coordinates)) {
                    WPawns.erase(WPawns.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < WRooks.size(); q++) {
                if (get<0>(BKnights[i].coordinates) == get<0>(WRooks[q].coordinates) && get<1>(BKnights[i].coordinates) == get<1>(WRooks[q].coordinates)) {
                    WRooks.erase(WRooks.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < WKnights.size(); q++) {
                if (get<0>(BKnights[i].coordinates) == get<0>(WKnights[q].coordinates) && get<1>(BKnights[i].coordinates) == get<1>(WKnights[q].coordinates)) {
                    WKnights.erase(WKnights.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < WBishops.size(); q++) {
                if (get<0>(BKnights[i].coordinates) == get<0>(WBishops[q].coordinates) && get<1>(BKnights[i].coordinates) == get<1>(WBishops[q].coordinates)) {
                    WBishops.erase(WBishops.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < WQueens.size(); q++) {
                if (get<0>(BKnights[i].coordinates) == get<0>(WQueens[q].coordinates) && get<1>(BKnights[i].coordinates) == get<1>(WQueens[q].coordinates)) {
                    WQueens.erase(WQueens.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
        }

    }
    else if (piece == "BBishops") {
        for (size_t i = 0; i < BBishops.size(); i++) {
            for (size_t q = 0; q < WPawns.size(); q++) {
                if (get<0>(BBishops[i].coordinates) == get<0>(WPawns[q].coordinates) && get<1>(BBishops[i].coordinates) == get<1>(WPawns[q].coordinates)) {
                    WPawns.erase(WPawns.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < WRooks.size(); q++) {
                if (get<0>(BBishops[i].coordinates) == get<0>(WRooks[q].coordinates) && get<1>(BBishops[i].coordinates) == get<1>(WRooks[q].coordinates)) {
                    WRooks.erase(WRooks.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < WKnights.size(); q++) {
                if (get<0>(BBishops[i].coordinates) == get<0>(WKnights[q].coordinates) && get<1>(BBishops[i].coordinates) == get<1>(WKnights[q].coordinates)) {
                    WKnights.erase(WKnights.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < WBishops.size(); q++) {
                if (get<0>(BBishops[i].coordinates) == get<0>(WBishops[q].coordinates) && get<1>(BBishops[i].coordinates) == get<1>(WBishops[q].coordinates)) {
                    WBishops.erase(WBishops.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < WQueens.size(); q++) {
                if (get<0>(BBishops[i].coordinates) == get<0>(WQueens[q].coordinates) && get<1>(BBishops[i].coordinates) == get<1>(WQueens[q].coordinates)) {
                    WQueens.erase(WQueens.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
        }
    }
    else if (piece == "BQueen") {
        for (size_t i = 0; i < BQueens.size(); i++) {
            for (size_t q = 0; q < WPawns.size(); q++) {
                if (get<0>(BQueens[i].coordinates) == get<0>(WPawns[q].coordinates) && get<1>(BQueens[i].coordinates) == get<1>(WPawns[q].coordinates)) {
                    WPawns.erase(WPawns.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < WRooks.size(); q++) {
                if (get<0>(BQueens[i].coordinates) == get<0>(WRooks[q].coordinates) && get<1>(BQueens[i].coordinates) == get<1>(WRooks[q].coordinates)) {
                    WRooks.erase(WRooks.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < WKnights.size(); q++) {
                if (get<0>(BQueens[i].coordinates) == get<0>(WKnights[q].coordinates) && get<1>(BQueens[i].coordinates) == get<1>(WKnights[q].coordinates)) {
                    WKnights.erase(WKnights.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < WBishops.size(); q++) {
                if (get<0>(BQueens[i].coordinates) == get<0>(WBishops[q].coordinates) && get<1>(BQueens[i].coordinates) == get<1>(WBishops[q].coordinates)) {
                    WBishops.erase(WBishops.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < WQueens.size(); q++) {
                if (get<0>(BQueens[i].coordinates) == get<0>(WQueens[q].coordinates) && get<1>(BQueens[i].coordinates) == get<1>(WQueens[q].coordinates)) {
                    WQueens.erase(WQueens.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
        }

    }
    else if (piece == "BKing") {
        for (size_t i = 0; i < BKings.size(); i++) {
            for (size_t q = 0; q < WPawns.size(); q++) {
                if (get<0>(BKings[i].coordinates) == get<0>(WPawns[q].coordinates) && get<1>(BKings[i].coordinates) == get<1>(WPawns[q].coordinates)) {
                    WPawns.erase(WPawns.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < WRooks.size(); q++) {
                if (get<0>(BKings[i].coordinates) == get<0>(WRooks[q].coordinates) && get<1>(BKings[i].coordinates) == get<1>(WRooks[q].coordinates)) {
                    WRooks.erase(WRooks.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < WKnights.size(); q++) {
                if (get<0>(BKings[i].coordinates) == get<0>(WKnights[q].coordinates) && get<1>(BKings[i].coordinates) == get<1>(WKnights[q].coordinates)) {
                    WKnights.erase(WKnights.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < WBishops.size(); q++) {
                if (get<0>(BKings[i].coordinates) == get<0>(WBishops[q].coordinates) && get<1>(BKings[i].coordinates) == get<1>(WBishops[q].coordinates)) {
                    WBishops.erase(WBishops.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
            for (size_t q = 0; q < WQueens.size(); q++) {
                if (get<0>(BKings[i].coordinates) == get<0>(WQueens[q].coordinates) && get<1>(BKings[i].coordinates) == get<1>(WQueens[q].coordinates)) {
                    WQueens.erase(WQueens.begin() + q);
                    a = { WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings };
                    return a;
                }
            }
        }

    }
    return a;
};

void render(vector <vector<char>> board) {
    system("cls");
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            cout << board[i][j];

        }
        cout << endl;

    }

}

vector<vector<char>> update (vector <WPawn> WPawns, vector <BPawn> BPawns, vector <WRook> WRooks, vector <BRook> BRooks, vector<WKnight> WKnights, vector<BKnight> BKnights, vector <WBishop> WBishops, vector <BBishop> BBishops, vector <WQueen> WQueens, vector <BQueen> BQueens, vector <WKing> WKings, vector <BKing> BKings, vector <vector<char>> board){
    board = { {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.', '.'} };
    for (size_t i = 0; i < WPawns.size(); i++)
    {
        board[get<1>(WPawns[i].coordinates)][get<0>(WPawns[i].coordinates)] = 'P';
    }
    for (size_t i = 0; i < BPawns.size(); i++) {
        board[get<1>(BPawns[i].coordinates)][get<0>(BPawns[i].coordinates)] = 'p';
    }

    for (size_t i = 0; i < WRooks.size(); i++) {
        board[get<1>(WRooks[i].coordinates)][get<0>(WRooks[i].coordinates)] = 'R';
    }

    for (size_t i = 0; i < BRooks.size(); i++) {
        board[get<1>(BRooks[i].coordinates)][get<0>(BRooks[i].coordinates)] = 'r';
    }

    for (size_t i = 0; i < WKnights.size(); i++) {
        board[get<1>(WKnights[i].coordinates)][get<0>(WKnights[i].coordinates)] = 'K';
    }

    for (size_t i = 0; i < BKnights.size(); i++) {
        board[get<1>(BKnights[i].coordinates)][get<0>(BKnights[i].coordinates)] = 'k';
    }

    for (size_t i = 0; i < WBishops.size(); i++) {
        board[get<1>(WBishops[i].coordinates)][get<0>(WBishops[i].coordinates)] = 'B';
    }

    for (size_t i = 0; i < BBishops.size(); i++) {
        board[get<1>(BBishops[i].coordinates)][get<0>(BBishops[i].coordinates)] = 'b';
    }

    for (size_t i = 0; i < WQueens.size(); i++) {
        board[get<1>(WQueens[i].coordinates)][get<0>(WQueens[i].coordinates)] = 'Q';
    }

    for (size_t i = 0; i < BQueens.size(); i++) {
        board[get<1>(BQueens[i].coordinates)][get<0>(BQueens[i].coordinates)] = 'q';
    }
    for (size_t i = 0; i < WKings.size(); i++) {
        board[get<1>(WKings[i].coordinates)][get<0>(WKings[i].coordinates)] = '#';
    }

    for (size_t i = 0; i < BKings.size(); i++) {
        board[get<1>(BKings[i].coordinates)][get<0>(BKings[i].coordinates)] = '@';
    }

    return board;
}

int main() {
    int Turn = 0, wwww = 0;
    bool status = 1;
    vector<vector<char>> trouble1, trouble2;
    WPawn P1, P2, P3, P4, P5, P6, P7, P8; BPawn p1, p2, p3, p4, p5, p6, p7, p8;
    WRook R1, R2; BRook r1, r2;
    WKnight Kn1, Kn2; BKnight kn1, kn2;
    WBishop B1, B2; BBishop b1, b2;
    WQueen Q1; BQueen q1;
    WKing K1; BKing k1;
    vector<char> move = {};
    vector<WPawn> WPawns = { P1, P2, P3, P4, P5, P6, P7, P8 };
    vector<BPawn> BPawns = { p1,p2,p3,p4,p5,p6,p7,p8 };
    vector <WRook> WRooks = { R1, R2 }; WRooks[0].coordinates = { 0,7 }; WRooks[1].coordinates = { 7,7 };
    vector <BRook> BRooks = { r1, r2 }; BRooks[0].coordinates = { 0,0 }; BRooks[1].coordinates = { 7,0 };
    vector <WKnight> WKnights = { Kn1, Kn2 }; WKnights[0].coordinates = { 1,7 }; WKnights[1].coordinates = { 6,7 };
    vector <BKnight> BKnights = { kn1, kn2 }; BKnights[0].coordinates = { 1,0 }; BKnights[1].coordinates = { 6,0 };
    vector <WBishop> WBishops = { B1, B2 }; WBishops[0].coordinates = { 2,7 }; WBishops[1].coordinates = { 5,7 };
    vector <BBishop> BBishops = { b1, b2 }; BBishops[0].coordinates = { 2,0 }; BBishops[1].coordinates = { 5,0 };
    vector <WQueen> WQueens = { Q1 }; WQueens[0].coordinates = { 3, 7 };
    vector <BQueen> BQueens = { q1 }; BQueens[0].coordinates = { 3, 0 };
    vector <WKing> WKings = { K1 }; WKings[0].coordinates = { 4,7 };
    vector <BKing> BKings = { k1 }; BKings[0].coordinates = { 4,0 };
    vector <WPawn> WPawnsCopy = WPawns; vector <BPawn> BPawnsCopy = BPawns;
    vector <WRook> WRooksCopy = WRooks; vector <BRook> BRooksCopy = BRooks;
    vector <WKnight> WKnightsCopy = WKnights; vector <BKnight> BKnightsCopy = BKnights;
    vector <WBishop> WBishopsCopy = WBishops; vector <BBishop> BBishopsCopy = BBishops;
    vector <WQueen> WQueensCopy = WQueens; vector <BQueen> BQueensCopy = BQueens;

    vector < vector <char> > board = { {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.', '.'} };
    vector<vector<char>> WDead = { {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','X','X','X','.','.'},
    {'.','.','.','X','.','X','.', '.'} };
    vector<vector<char>> BDead = { {'.','.','.','X','.','X','.','.'},
    {'.','.','.','X','X','X','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.', '.'} };
    tuple <vector<WPawn>, vector<WRook>, vector<WKnight>, vector<WBishop>, vector<WQueen>, vector <WKing>, vector<BPawn>, vector<BRook>, vector<BKnight>, vector<BBishop>, vector<BQueen>, vector<BKing>> A;
    tuple <vector<WPawn>, vector<WRook>, vector<WKnight>, vector<WBishop>, vector<WQueen>> w;
    tuple <vector<BPawn>, vector<BRook>, vector<BKnight>, vector<BBishop>, vector<BQueen>> b;
    tuple <vector<WPawn>, vector<WRook>, vector<WKnight>, vector<WBishop>, vector<WQueen>> er;
    tuple<vector<vector<int>>, vector<vector<char>>> func;
    for (int i = 0; i < WKnights.size(); i++) {
        func = WKnights[i].predicthion(WKnights[i].coordinates, board, BDead);
        WKnights[i].Predicthion = get<0>(func);
        BDead = get<1>(func);
    }
    for (int i = 0; i < BKnights.size(); i++) {
        func = BKnights[i].predicthion(BKnights[i].coordinates, board, WDead);
        BKnights[i].Predicthion = get<0>(func);
        WDead = get<1>(func);
    }
    for (int i = 0; i < 8; i++) {
        WPawns[i].coordinates = { i, 6 };
        WPawns[i].Predicthion = { {i, 5}, {i, 4} };
    }
    for (int i = 0; i < 8; i++) {
        BPawns[i].coordinates = { i, 1 };
        BPawns[i].Predicthion = { {i, 2}, {i, 3} };
    }
    board = update(WPawns, BPawns, WRooks, BRooks, WKnights, BKnights, WBishops, BBishops, WQueens, BQueens, WKings, BKings, board);
    render(board);
    while (true) {
        
        if (Turn == 0) {
            if (WDead[get<1>(WKings[0].coordinates)][get<0>(WKings[0].coordinates)] == 'X'){
                er = WEterethion(WPawns, WRooks, WKnights, WBishops, WQueens, WKings, board);
                WPawns = get<0>(er);
                WRooks = get<1>(er);
                WKnights = get<2>(er);
                WBishops = get<3>(er);
                WQueens = get<4>(er);

            }
            while (status){

                move = enter();
                if (move.size() == 2) {
                    WPawnsCopy = makeTurn(move, WPawns);
                    A = captured(WPawnsCopy, WRooks, WKnights, WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings, "WPawn");
                    BPawnsCopy = get<6>(A);
                    BRooksCopy = get<7>(A);
                    BKnightsCopy = get<8>(A);
                    BBishopsCopy = get<9>(A);
                    BQueensCopy = get<10>(A);
                    BKings = get<11>(A);
                    if (move[1] == '8'){
                        w = WMorph(WPawnsCopy, WRooks, WKnights, WBishops, WQueens);
                        WPawnsCopy = get<0>(w);
                        WRooksCopy = get<1>(w);
                        WKnightsCopy = get<2>(w);
                        WBishopsCopy = get<3>(w);
                        WQueensCopy = get<4>(w);
                    }
                    
                }
                else {
                    if (move[0] == 'R') {
                        WRooksCopy = makeTurn(move, WRooks);
                        A = captured(WPawns, WRooksCopy, WKnights, WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings, "WRook");
                        BPawnsCopy = get<6>(A);
                        BRooksCopy = get<7>(A);
                        BKnightsCopy = get<8>(A);
                        BBishopsCopy = get<9>(A);
                        BQueensCopy = get<10>(A);
                        BKings = get<11>(A);

                    }
                    else if (move[0] == 'K' && move[1] == 'n') {
                        WKnightsCopy = makeTurn(move, WKnights);
                        A = captured(WPawns, WRooks, WKnightsCopy, WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings, "WKnight");
                        BPawnsCopy = get<6>(A);
                        BRooksCopy = get<7>(A);
                        BKnightsCopy = get<8>(A);
                        BBishopsCopy = get<9>(A);
                        BQueensCopy = get<10>(A);
                        BKings = get<11>(A);

                    }
                    else if (move[0] == 'B') {
                        WBishopsCopy = makeTurn(move, WBishops);
                        A = captured(WPawns, WRooks, WKnights, WBishopsCopy, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings, "WBishop");
                        BPawnsCopy = get<6>(A);
                        BRooksCopy = get<7>(A);
                        BKnightsCopy = get<8>(A);
                        BBishopsCopy = get<9>(A);
                        BQueensCopy = get<10>(A);
                        BKings = get<11>(A);

                    }
                    else if (move[0] == 'Q') {
                        WQueensCopy = makeTurn(move, WQueens);
                        A = captured(WPawns, WRooks, WKnights, WBishops, WQueensCopy, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings, "WQueen");
                        BPawnsCopy = get<6>(A);
                        BRooksCopy = get<7>(A);
                        BKnightsCopy = get<8>(A);
                        BBishopsCopy = get<9>(A);
                        BQueensCopy = get<10>(A);
                        BKings = get<11>(A);

                    }
                    else if (move[0] == 'K') {
                        WKings = makeTurn(move, WKings);
                        A = captured(WPawns, WRooks, WKnights, WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings, "WKing");
                        BPawns = get<6>(A);
                        BRooks = get<7>(A);
                        BKnights = get<8>(A);
                        BBishops = get<9>(A);
                        BQueens = get<10>(A);
                        BKings = get<11>(A);

                    }
                }
                board = update(WPawnsCopy, BPawnsCopy, WRooksCopy, BRooksCopy, WKnightsCopy, BKnightsCopy, WBishopsCopy, BBishopsCopy, WQueensCopy, BQueensCopy, WKings, BKings, board);
                status = idk(BPawnsCopy, BRooksCopy, BKnightsCopy, BBishopsCopy, BQueensCopy, WKings, board);
                
            }
            
            WPawns = WPawnsCopy; WRooks = WRooksCopy; WKnights = WKnightsCopy; WBishops = WBishopsCopy; WQueens = WQueensCopy;
            BPawns = BPawnsCopy; BRooks = BRooksCopy; BKnights = BKnightsCopy; BBishops = BBishopsCopy; BQueens = BQueensCopy;
            
        }
        else {
            move = enter();
            if (move.size() == 2) {
                BPawns = makeTurn(move, BPawns);
                A = captured(WPawns, WRooks, WKnights, WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings, "BPawn");
                WPawns = get<0>(A);
                WRooks = get<1>(A);
                WKnights = get<2>(A);
                WBishops = get<3>(A);
                WQueens = get<4>(A);
                WKings = get<5>(A);

                if (move[1] =='1'){
                    b = BMorph(BPawns, BRooks, BKnights, BBishops, BQueens);
                    BPawns = get<0>(b);
                    BRooks = get<1>(b);
                    BKnights = get<2>(b);
                    BBishops = get<3>(b);
                    BQueens = get<4>(b);
                }

            }
            else {
                if (move[0] == 'R') {
                    BRooks = makeTurn(move, BRooks);
                    A = captured(WPawns, WRooks, WKnights, WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings, "BRook");
                    WPawns = get<0>(A);
                    WRooks = get<1>(A);
                    WKnights = get<2>(A);
                    WBishops = get<3>(A);
                    WQueens = get<4>(A);
                    WKings = get<5>(A);

                }
                else if (move[0] == 'K' && move[1] == 'n') {
                    BKnights = makeTurn(move, BKnights);
                    A = captured(WPawns, WRooks, WKnights, WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings, "BKnight");
                    WPawns = get<0>(A);
                    WRooks = get<1>(A);
                    WKnights = get<2>(A);
                    WBishops = get<3>(A);
                    WQueens = get<4>(A);
                    WKings = get<5>(A);

                }
                else if (move[0] == 'B') {
                    BBishops = makeTurn(move, BBishops);
                    A = captured(WPawns, WRooks, WKnights, WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings, "BBishop");
                    BPawns = get<6>(A);
                    BRooks = get<7>(A);
                    BKnights = get<8>(A);
                    BBishops = get<9>(A);
                    BQueens = get<10>(A);
                    BKings = get<11>(A);

                }
                else if (move[0] == 'Q') {
                    BQueens = makeTurn(move, BQueens);
                    A = captured(WPawns, WRooks, WKnights, WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings, "BQueen");
                    BPawns = get<6>(A);
                    BRooks = get<7>(A);
                    BKnights = get<8>(A);
                    BBishops = get<9>(A);
                    BQueens = get<10>(A);
                    BKings = get<11>(A);

                }
                else if (move[0] == 'K') {
                    BKings = makeTurn(move, BKings);
                    A = captured(WPawns, WRooks, WKnights, WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings, "BKing");
                    BPawns = get<6>(A);
                    BRooks = get<7>(A);
                    BKnights = get<8>(A);
                    BBishops = get<9>(A);
                    BQueens = get<10>(A);
                    BKings = get<11>(A);

                }

            }
        }
        status = 1;
        board = update(WPawns, BPawns, WRooks, BRooks, WKnights, BKnights, WBishops, BBishops, WQueens, BQueens, WKings, BKings, board);
        render(board);
        BDead = {{'.', '.', '.', '.', '.', '.', '.', '.'},
                {'.', '.', '.', '.', '.', '.', '.', '.'},
                {'.', '.', '.', '.', '.', '.', '.', '.'},
                {'.', '.', '.', '.', '.', '.', '.', '.'},
                {'.', '.', '.', '.', '.', '.', '.', '.'},
                {'.', '.', '.', '.', '.', '.', '.', '.'},
                {'.', '.', '.', '.', '.', '.', '.', '.'},
                {'.', '.', '.', '.', '.', '.', '.', '.'}};
        WDead = BDead;
         for (int i =0; i < WPawns.size(); i++){
            func = WPawns[i].predicthion(WPawns[i].coordinates, board, BDead);
            WPawns[i].Predicthion = get<0>(func);
            BDead = get<1>(func);
        }
        for (int i =0; i < BPawns.size(); i++){
            func = BPawns[i].predicthion(BPawns[i].coordinates, board, WDead);
            BPawns[i].Predicthion = get<0>(func);
            WDead = get<1>(func);
        }
        for (int i =0; i <WRooks.size(); i++){
            func = WRooks[i].predicthion(WRooks[i].coordinates, board, BDead);
            WRooks[i].Predicthion = get<0>(func);
            BDead = get<1>(func);
        }
        for (int i =0; i <BRooks.size(); i++){
            func = BRooks[i].predicthion(BRooks[i].coordinates, board, WDead);
            BRooks[i].Predicthion = get<0>(func) ;
            WDead = get<1>(func);
        }
         for (int i =0; i <WKnights.size(); i++){
            func = WKnights[i].predicthion(WKnights[i].coordinates, board, BDead);
            WKnights[i].Predicthion = get<0>(func);
            BDead = get<1>(func);
        }
        for (int i =0; i <BKnights.size(); i++){
            func = BKnights[i].predicthion(BKnights[i].coordinates, board, WDead);
            BKnights[i].Predicthion = get<0>(func);
            WDead = get<1>(func);
        }
        for (int i =0; i <WBishops.size(); i++){
            func = WBishops[i].predicthion(WBishops[i].coordinates, board, BDead);
            WBishops[i].Predicthion = get<0>(func);
            BDead = get<1>(func);
        }
        for (int i =0; i <BBishops.size(); i++){
            func = BBishops[i].predicthion(BBishops[i].coordinates, board, WDead);
            BBishops[i].Predicthion = get<0>(func);
            WDead = get<1>(func);
        }
        for (int i =0; i <WQueens.size(); i++){
            func = WQueens[i].predicthion(WQueens[i].coordinates, board, BDead);
            WQueens[i].Predicthion = get<0>(func);
            BDead = get<1>(func);
        }
        for (int i =0; i <BQueens.size(); i++){
            func = BQueens[i].predicthion(BQueens[i].coordinates, board, WDead);
            BQueens[i].Predicthion = get<0>(func);
            WDead = get<1>(func);
        }
        WDead = WDeadSquares(WPawns, WRooks, WKnights, WBishops, WQueens, WKings, WDead);
        BDead = BDeadSquares(BPawns, BRooks, BKnights, BBishops, BQueens, BKings, BDead);
        WKings[0].Predicthion = WKings[0].predicthion(WKings[0].coordinates, board, WDead);
        BKings[0].Predicthion = BKings[0].predicthion(BKings[0].coordinates, board, BDead);
        Turn = (Turn + 1) % 2;
    }

    return 1;
}

