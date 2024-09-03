#include<vector>
#include<iostream>
#include <tuple>
using namespace std;


std::tuple <int, int> a = {55, 55};
bool InRange(int a, int b, int c) {
    if (a >= b && a <= c) {
        return true;
    }
    else {
        return false;
    }
}
class WPawn; class WRook; class WKnight; class WBishop; class WQueen; class WKing;
class BPawn; class BRook; class BKnight; class BBishop; class BQueen; class BKing;
class WPawn
{
public:
    tuple<int, int> coordinates = { 0,6 };
    vector<vector<int>> Predicthion = { {0,5, 1}, {0,4, 1} };
    vector<vector<int>> predicthion(tuple<int, int> coordinates, vector<vector<char>> Board) {
        vector<vector<int>> Predicthion;
        if (get<1>(coordinates) == 6 && Board[get<1>(coordinates) - 2][get<0>(coordinates)] == '.') {
            Predicthion.push_back({ get<0>(coordinates), get<1>(coordinates) - 2 });
        }
        if (get<1>(coordinates) - 1 >= 0 && Board[get<1>(coordinates) - 1][get<0>(coordinates)] == '.') {
            Predicthion.push_back({ get<0>(coordinates), get<1>(coordinates) - 1 });
        }
        if ((get<1>(coordinates) - 1 >= 0 && get<0>(coordinates) - 1 >= 0) && InRange((int)Board[get<1>(coordinates) - 1][get<0>(coordinates) - 1], (int)'a', (int)'z')) {
            Predicthion.push_back({ {get<0>(coordinates) - 1, get<1>(coordinates) - 1} });
        }
        if ((get<1>(coordinates) - 1 >= 0 && get<0>(coordinates) + 1 <= 7) && InRange((int)Board[get<1>(coordinates) - 1][get<0>(coordinates) + 1], (int)'a', (int)'z')) {
            Predicthion.push_back({ {get<0>(coordinates) + 1, get<1>(coordinates) - 1} });
        }
        return Predicthion;
    }


};

class BPawn {
private:

public:
    tuple<int, int> coordinates = { 0,1 };
    vector<vector<int>> Predicthion = { {0,2}, {0,3} };
    vector<vector<int>> predicthion(tuple<int, int> coordinates, vector<vector<char>> Board) {
        vector<vector<int>> Predicthion;
        if (get<1>(coordinates) == 1 && Board[get<1>(coordinates) + 2][get<0>(coordinates)] == '.') {
            Predicthion.push_back({ get<0>(coordinates), get<1>(coordinates) + 2 });
        }
        if (get<1>(coordinates) + 1 <= 7 && Board[get<1>(coordinates) + 1][get<0>(coordinates)] == '.') {
            Predicthion.push_back({ get<0>(coordinates), get<1>(coordinates) + 1 });
        }
        if ((get<1>(coordinates) + 1 <= 7 && get<0>(coordinates) - 1 >= 0) && InRange((int)Board[get<1>(coordinates) + 1][get<0>(coordinates) - 1], (int)'A', (int)'Z')) {
            Predicthion.push_back({ {get<0>(coordinates) - 1, get<1>(coordinates) + 1} });
        }
        if ((get<0>(coordinates) + 1 <= 7 && get<1>(coordinates) + 1 <= 7) && InRange((int)Board[get<1>(coordinates) + 1][get<0>(coordinates) + 1], (int)'A', (int)'Z')) {
            Predicthion.push_back({ {get<0>(coordinates) + 1, get<1>(coordinates) + 1} });
        }
        return Predicthion;
    }
};

class WRook {
public:
    tuple<int, int> coordinates = { 0,0 };
    vector<vector<int>> Predicthion;
    vector<vector<int>> predicthion(tuple<int, int> coordinates, vector<vector<char>> Board) {
        vector<vector<int>> Predicthion;
        for (int i = 1; i < 8; i++) {
            if (get<0>(coordinates) - i < 0) {
                break;
            }
            if (InRange(Board[get<1>(coordinates)][get<0>(coordinates) - i], (int)'a', (int)'z')) {
                Predicthion.push_back({ get<0>(coordinates) - i, get<1>(coordinates) });
                break;
            }
            if (InRange(Board[get<1>(coordinates)][get<0>(coordinates) - i], (int)'A', (int)'Z') || Board[get<1>(coordinates)][get<0>(coordinates) - i] == '@' || Board[get<1>(coordinates)][get<0>(coordinates) - i] == '#') {
                break;
            }
            if (Board[get<1>(coordinates)][get<0>(coordinates) - i] == '.') {
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
                break;
            }
            if (Board[get<1>(coordinates)][get<0>(coordinates) + i] == '.') {
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
                break;
            }
            if (Board[get<1>(coordinates) - i][get<0>(coordinates)] == '.') {
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
                break;
            }
            if (Board[get<1>(coordinates) + i][get<0>(coordinates)] == '.') {
                Predicthion.push_back({ get<0>(coordinates), get<1>(coordinates) + i });
            }

        }
        return Predicthion;
    }
};

class BRook {
public:
    tuple<int, int> coordinates = { 0,0 };
    vector<vector<int>> Predicthion;
    vector<vector<int>> predicthion(tuple<int, int> coordinates, vector<vector<char>> Board) {
        vector<vector<int>> Predicthion;
        for (int i = 1; i < 8; i++) {
            if (get<0>(coordinates) - i < 0) {
                break;
            }
            if (InRange(Board[get<1>(coordinates)][get<0>(coordinates) - i], (int)'A', (int)'Z')) {
                Predicthion.push_back({ get<0>(coordinates) - i, get<1>(coordinates) });
                break;
            }
            if (InRange(Board[get<1>(coordinates)][get<0>(coordinates) - i], (int)'a', (int)'z') || Board[get<1>(coordinates)][get<0>(coordinates) - i] == '@' || Board[get<1>(coordinates)][get<0>(coordinates) - i] == '#') {
                break;
            }
            if (Board[get<1>(coordinates)][get<0>(coordinates) - i] == '.') {
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
                break;
            }
            if (Board[get<1>(coordinates)][get<0>(coordinates) + i] == '.') {
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
                break;
            }
            if (Board[get<1>(coordinates) - i][get<0>(coordinates)] == '.') {
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
                break;
            }
            if (Board[get<1>(coordinates) + i][get<0>(coordinates)] == '.') {
                Predicthion.push_back({ get<0>(coordinates), get<1>(coordinates) + i });
            }

        }
        return Predicthion;
    }
};

class WKnight {
public:
    tuple<int, int> coordinates = { 0,0 };
    vector<vector<int>> Predicthion;
    vector<vector<int>> predicthion(tuple<int, int> coordinates, vector<vector<char>> Board) {
        vector<vector<int>> Predicthion;
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
        return Predicthion;
    }

};

class BKnight {
public:
    tuple<int, int> coordinates = { 0,0 };
    vector<vector<int>> Predicthion;
    vector<vector<int>> predicthion(tuple<int, int> coordinates, vector<vector<char>> Board) {
        vector<vector<int>> Predicthion;
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
        return Predicthion;
    }

};

class WBishop {
public:
    tuple<int, int> coordinates = { 0,0 };
    vector<vector<int>> Predicthion;
    vector<vector<int>> predicthion(tuple<int, int> coordinates, vector<vector<char>> Board) {
        vector<vector<int>> Predicthion;
        for (int i = 1; i < 8; i++) {
            if (get<0>(coordinates) - i < 0 || get<1>(coordinates) - i < 0) {
                break;
            }
            if (InRange(Board[get<1>(coordinates) - i][get<0>(coordinates) - i], (int)'a', (int)'z')) {
                Predicthion.push_back({ get<0>(coordinates) - i, get<1>(coordinates) - i });
                break;
            }
            if (InRange(Board[get<1>(coordinates) - i][get<0>(coordinates) - i], (int)'A', (int)'Z') || Board[get<1>(coordinates) - i][get<0>(coordinates) - i] == '@' || Board[get<1>(coordinates) - i][get<0>(coordinates) - i] == '#') {
                break;
            }
            if (Board[get<1>(coordinates) - i][get<0>(coordinates) - i] == '.') {
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
                break;
            }
            if (Board[get<1>(coordinates) - i][get<0>(coordinates) + i] == '.') {
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
                break;
            }
            if (Board[get<1>(coordinates) + i][get<0>(coordinates) + i] == '.') {
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
                break;
            }
            if (Board[get<1>(coordinates) + i][get<0>(coordinates) - i] == '.') {
                Predicthion.push_back({ get<0>(coordinates) - i, get<1>(coordinates) + i });
            }

        }

        return Predicthion;
    }
};

class BBishop {
public:
    tuple<int, int> coordinates = { 0,0 };
    vector<vector<int>> Predicthion;
    vector<vector<int>> predicthion(tuple<int, int> coordinates, vector<vector<char>> Board) {
        vector<vector<int>> Predicthion;
        for (int i = 1; i < 8; i++) {
            if (get<1>(coordinates) - i < 0 || get<0>(coordinates) - i < 0) {
                break;
            }
            if (InRange(Board[get<1>(coordinates) - i][get<0>(coordinates) - i], (int)'A', (int)'Z')) {
                Predicthion.push_back({ get<0>(coordinates) - i, get<1>(coordinates) - i });
                break;
            }
            if (InRange(Board[get<1>(coordinates) - i][get<0>(coordinates) - i], (int)'a', (int)'z') || Board[get<1>(coordinates) - i][get<0>(coordinates) - i] == '@' || Board[get<1>(coordinates) - i][get<0>(coordinates) - i] == '#') {
                break;
            }
            if (Board[get<1>(coordinates) - i][get<0>(coordinates) - i] == '.') {
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
                break;
            }
            if (Board[get<1>(coordinates) - i][get<0>(coordinates) + i] == '.') {
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
                break;
            }
            if (Board[get<1>(coordinates) + i][get<0>(coordinates) - i] == '.') {
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
                break;
            }
            if (Board[get<1>(coordinates) + i][get<0>(coordinates) + i] == '.') {
                Predicthion.push_back({ get<0>(coordinates) + i, get<1>(coordinates) + i });
            }

        }
        return Predicthion;
    }
};

class WQueen {
public:
    tuple<int, int> coordinates = { 0,0 };
    vector<vector<int>> Predicthion;
    vector<vector<int>> predicthion(tuple<int, int> coordinates, vector<vector<char>> Board) {
        vector<vector<int>> Predicthion;
        for (int i = 1; i < 8; i++) {
            if (get<0>(coordinates) - i < 0 || get<1>(coordinates) - i < 0) {
                break;
            }
            if (InRange(Board[get<1>(coordinates) - i][get<0>(coordinates) - i], (int)'a', (int)'z')) {
                Predicthion.push_back({ get<0>(coordinates) - i, get<1>(coordinates) - i });
                break;
            }
            if (InRange(Board[get<1>(coordinates) - i][get<0>(coordinates) - i], (int)'A', (int)'Z') || Board[get<1>(coordinates) - i][get<0>(coordinates) - i] == '@' || Board[get<1>(coordinates) - i][get<0>(coordinates) - i] == '#') {
                break;
            }
            if (Board[get<1>(coordinates) - i][get<0>(coordinates) - i] == '.') {
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
                break;
            }
            if (Board[get<1>(coordinates) - i][get<0>(coordinates) + i] == '.') {
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
                break;
            }
            if (Board[get<1>(coordinates) + i][get<0>(coordinates) + i] == '.') {
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
                break;
            }
            if (Board[get<1>(coordinates) + i][get<0>(coordinates) - i] == '.') {
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
                break;
            }
            if (Board[get<1>(coordinates)][get<0>(coordinates) - i] == '.') {
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
                break;
            }
            if (Board[get<1>(coordinates)][get<0>(coordinates) + i] == '.') {
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
                break;
            }
            if (Board[get<1>(coordinates) - i][get<0>(coordinates)] == '.') {
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
                break;
            }
            if (Board[get<1>(coordinates) + i][get<0>(coordinates)] == '.') {
                Predicthion.push_back({ get<0>(coordinates), get<1>(coordinates) + i });
            }

        }
        return Predicthion;
    }

};

class BQueen {
public:
    tuple<int, int> coordinates = { 0,0 };
    vector<vector<int>> Predicthion;
    vector<vector<int>> predicthion(tuple<int, int> coordinates, vector<vector<char>> Board) {
        vector<vector<int>> Predicthion;
        for (int i = 1; i < 8; i++) {
            if (get<1>(coordinates) - i < 0 || get<0>(coordinates) - i < 0) {
                break;
            }
            if (InRange(Board[get<1>(coordinates) - i][get<0>(coordinates) - i], (int)'A', (int)'Z')) {
                Predicthion.push_back({ get<0>(coordinates) - i, get<1>(coordinates) - i });
                break;
            }
            if (InRange(Board[get<1>(coordinates) - i][get<0>(coordinates) - i], (int)'a', (int)'z') || Board[get<1>(coordinates) - i][get<0>(coordinates) - i] == '@' || Board[get<1>(coordinates) - i][get<0>(coordinates) - i] == '#') {
                break;
            }
            if (Board[get<1>(coordinates) - i][get<0>(coordinates) - i] == '.') {
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
                break;
            }
            if (Board[get<1>(coordinates) - i][get<0>(coordinates) + i] == '.') {
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
                break;
            }
            if (Board[get<1>(coordinates) + i][get<0>(coordinates) - i] == '.') {
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
                break;
            }
            if (Board[get<1>(coordinates) + i][get<0>(coordinates) + i] == '.') {
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
                break;
            }
            if (Board[get<1>(coordinates)][get<0>(coordinates) - i] == '.') {
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
                break;
            }
            if (Board[get<1>(coordinates)][get<0>(coordinates) + i] == '.') {
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
                break;
            }
            if (Board[get<1>(coordinates) - i][get<0>(coordinates)] == '.') {
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
                break;
            }
            if (Board[get<1>(coordinates) + i][get<0>(coordinates)] == '.') {
                Predicthion.push_back({ get<0>(coordinates), get<1>(coordinates) + i });
            }

        }
        return Predicthion;
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


vector<vector<char>> BDeadSquares(vector <BPawn> BPawns, vector <BRook> BRooks, vector <BKnight> BKnights, vector <BBishop> BBishops, vector<BQueen> BQueens, vector <BKing> BKings, vector <WPawn> WPawns, vector <WRook> WRooks, vector <WKnight> WKnights, vector <WBishop> WBishops, vector<WQueen> WQueens, vector <WKing> WKings) {
    vector < vector <char> > DeadBoard = { {'.','.','.','.','.','.','.','.'},
                                        {'.','.','.','.','.','.','.','.'},
                                        {'.','.','.','.','.','.','.','.'},
                                        {'.','.','.','.','.','.','.','.'},
                                        {'.','.','.','.','.','.','.','.'},
                                        {'.','.','.','.','.','.','.','.'},
                                        {'.','.','.','.','.','.','.','.'},
                                        {'.','.','.','.','.','.','.', '.'} };
    for (size_t i = 0; i < WPawns.size(); i++)
    {
        if (get<1>(WPawns[i].coordinates) - 1 < 8 && get<0>(WPawns[i].coordinates) + 1 < 8) {
            DeadBoard[get<1>(WPawns[i].coordinates) - 1][get<0>(WPawns[i].coordinates) + 1] = 'X';
        }
        if (get<1>(BPawns[i].coordinates) - 1 < 8 && get<0>(BPawns[i].coordinates) - 1 >= 0) {
            DeadBoard[get<1>(WPawns[i].coordinates) - 1][get<0>(WPawns[i].coordinates) - 1] = 'X';
        }
    }
    for (size_t i = 0; i < BPawns.size(); i++)
    {
        DeadBoard[get<1>(BPawns[i].coordinates)][get<0>(BPawns[i].coordinates)] = 'X';
    }

    for (size_t i = 0; i < WRooks.size(); i++)
    {
        for (size_t j = 0; j < WRooks[i].Predicthion.size(); j++)
        {
            DeadBoard[WRooks[i].Predicthion[j][1]][WRooks[i].Predicthion[j][0]] = 'X';
        }
    }
    for (size_t i = 0; i < BRooks.size(); i++)
    {
        DeadBoard[get<1>(BRooks[i].coordinates)][get<0>(BRooks[i].coordinates)] = 'X';
    }

    for (size_t i = 0; i < WKnights.size(); i++)
    {
        for (size_t j = 0; j < WKnights[i].Predicthion.size(); j++)
        {
            DeadBoard[WKnights[i].Predicthion[j][1]][WKnights[i].Predicthion[j][0]] = 'X';
        }
    }
    for (size_t i = 0; i < BKnights.size(); i++)
    {
        DeadBoard[get<1>(BKnights[i].coordinates)][get<0>(BKnights[i].coordinates)] = 'X';
    }

    for (size_t i = 0; i < WBishops.size(); i++)
    {
        for (size_t j = 0; j < WBishops[i].Predicthion.size(); j++)
        {
            DeadBoard[WBishops[i].Predicthion[j][1]][WBishops[i].Predicthion[j][0]] = 'X';
        }
    }
    for (size_t i = 0; i < BBishops.size(); i++)
    {
        DeadBoard[get<1>(BBishops[i].coordinates)][get<0>(BBishops[i].coordinates)] = 'X';
    }

    for (size_t i = 0; i < WQueens.size(); i++)
    {
        for (size_t j = 0; j < WQueens[i].Predicthion.size(); j++) {
            DeadBoard[WQueens[i].Predicthion[j][1]][WQueens[i].Predicthion[j][0]] = 'X';
        }
    }
    for (size_t i = 0; i < BQueens.size(); i++)
    {
        DeadBoard[get<1>(BQueens[i].coordinates)][get<0>(BQueens[i].coordinates)] = 'X';
    }

    for (size_t i = 0; i < WKings.size(); i++)
    {
        for (size_t j = 0; j < WKings[i].Predicthion.size(); j++) {
            DeadBoard[WKings[i].Predicthion[j][1]][WKings[i].Predicthion[j][0]] = 'X';
        }
    }
    for (size_t i = 0; i < BKings.size(); i++)
    {
        DeadBoard[get<1>(BKings[i].coordinates)][get<0>(BKings[i].coordinates)] = 'X';
    }
    return DeadBoard;
}

vector<vector<char>> WDeadSquares(vector <BPawn> BPawns, vector <BRook> BRooks, vector <BKnight> BKnights, vector <BBishop> BBishops, vector<BQueen> BQueens, vector <BKing> BKings, vector <WPawn> WPawns, vector <WRook> WRooks, vector <WKnight> WKnights, vector <WBishop> WBishops, vector<WQueen> WQueens, vector <WKing> WKings) {
    vector < vector <char> > DeadBoard = { {'.','.','.','.','.','.','.','.'},
                                        {'.','.','.','.','.','.','.','.'},
                                        {'.','.','.','.','.','.','.','.'},
                                        {'.','.','.','.','.','.','.','.'},
                                        {'.','.','.','.','.','.','.','.'},
                                        {'.','.','.','.','.','.','.','.'},
                                        {'.','.','.','.','.','.','.','.'},
                                        {'.','.','.','.','.','.','.', '.'} };
    for (size_t i = 0; i < BPawns.size(); i++)
    {
        if (get<1>(BPawns[i].coordinates) + 1 < 8 && get<0>(BPawns[i].coordinates) + 1 < 8) {
            DeadBoard[get<1>(BPawns[i].coordinates) + 1][get<0>(BPawns[i].coordinates) + 1] = 'X';
        }
        if (get<1>(BPawns[i].coordinates) + 1 < 8 && get<0>(BPawns[i].coordinates) -1 >= 0) {
            DeadBoard[get<1>(BPawns[i].coordinates) + 1][get<0>(BPawns[i].coordinates) - 1] = 'X';
        }
    }
    for (size_t i = 0; i < WPawns.size(); i++) {
        DeadBoard[get<1>(WPawns[i].coordinates)][get<0>(WPawns[i].coordinates)] = 'X';
    }

    for (size_t i = 0; i < BRooks.size(); i++)
    {
        for (size_t j = 0; j < BRooks[i].Predicthion.size(); j++)
        {
            DeadBoard[BRooks[i].Predicthion[j][1]][BRooks[i].Predicthion[j][0]] = 'X';
        }
    }
    for (size_t i = 0; i < WRooks.size(); i++)
    {
        DeadBoard[get<1>(WRooks[i].coordinates)][get<0>(WRooks[i].coordinates)] = 'X';
    }

    for (size_t i = 0; i < BKnights.size(); i++)
    {
        for (size_t j = 0; j < BKnights[i].Predicthion.size(); j++)
        {
            DeadBoard[BKnights[i].Predicthion[j][1]][BKnights[i].Predicthion[j][0]] = 'X';
        }
    }
    for (size_t i = 0; i < WKnights.size(); i++)
    {
        DeadBoard[get<1>(WKnights[i].coordinates)][get<0>(WKnights[i].coordinates)] = 'X';
    }

    for (size_t i = 0; i < BBishops.size(); i++)
    {
        for (size_t j = 0; j < BBishops[i].Predicthion.size(); j++)
        {
            DeadBoard[BBishops[i].Predicthion[j][1]][BBishops[i].Predicthion[j][0]] = 'X';
        }
    }
    for (size_t i = 0; i < WBishops.size(); i++)
    {
        DeadBoard[get<1>(WBishops[i].coordinates)][get<0>(WBishops[i].coordinates)] = 'X';
    }

    for (size_t i = 0; i < BQueens.size(); i++)
    {
        for (size_t j = 0; j < BQueens[i].Predicthion.size(); j++)
        {
            DeadBoard[BQueens[i].Predicthion[j][1]][BQueens[i].Predicthion[j][0]] = 'X';
        }
    }
    for (size_t i = 0; i < WQueens.size(); i++)
    {
        DeadBoard[get<1>(WQueens[i].coordinates)][get<0>(WQueens[i].coordinates)] = 'X';
    }

    for (size_t i = 0; i < BKings.size(); i++)
    {
        for (size_t j = 0; j < BKings[i].Predicthion.size(); j++)
        {
            DeadBoard[BKings[i].Predicthion[j][1]][BKings[i].Predicthion[j][0]] = 'X';
        }
    }
    for (size_t i = 0; i < WKings.size(); i++)
    {
        DeadBoard[get<1>(WKings[i].coordinates)][get<0>(WKings[i].coordinates)] = 'X';
    }
    return DeadBoard;
}



// дописати класи для слона, короля й королеви
vector<char> enter() {
    string move;
    char piece;

    tuple<char, char, int> t = {};
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
    for (size_t j = 0; j < piece[0].Predicthion.size(); j++) {
        if (piece[0].Predicthion[j][0] == move[1] && piece[0].Predicthion[j][1] == move[2]) {
            get<0>(piece[0].coordinates) = move[1];
            get<1>(piece[0].coordinates) = move[2];
            return piece;
        }
    }
}

vector<WQueen> makeTurn(vector<char> move, vector <WQueen> piece) {
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

vector < vector <char> > render(vector <WPawn> WPawns, vector <BPawn> BPawns, vector <WRook> WRooks, vector <BRook> BRooks, vector<WKnight> WKnights, vector<BKnight> BKnights, vector <WBishop> WBishops, vector <BBishop> BBishops, vector <WQueen> WQueens, vector <BQueen> BQueens, vector <WKing> WKings, vector <BKing> BKings, vector <vector<char>> board) {
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

    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            cout << board[i][j];

        }
        cout << endl;

    }
    return board;
}

int main() {
    int Turn = 0;
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
    vector < vector <char> > board = { {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.', '.'} };
    tuple <vector<WPawn>, vector<WRook>, vector<WKnight>, vector<WBishop>, vector<WQueen>, vector <WKing>, vector<BPawn>, vector<BRook>, vector<BKnight>, vector<BBishop>, vector<BQueen>, vector<BKing>> A;
    for (int i = 0; i < WKnights.size(); i++) {
        WKnights[i].Predicthion = WKnights[i].predicthion(WKnights[i].coordinates, board);
    }
    for (int i = 0; i < BKnights.size(); i++) {
        BKnights[i].Predicthion = BKnights[i].predicthion(BKnights[i].coordinates, board);
    }
    for (int i = 0; i < 8; i++) {
        WPawns[i].coordinates = { i, 6 };
        WPawns[i].Predicthion = { {i, 5}, {i, 4} };
    }
    for (int i = 0; i < 8; i++) {
        BPawns[i].coordinates = { i, 1 };
        BPawns[i].Predicthion = { {i, 2}, {i, 3} };
    }
    board = render(WPawns, BPawns, WRooks, BRooks, WKnights, BKnights, WBishops, BBishops, WQueens, BQueens, WKings, BKings, board);
    while (true) {
        move = enter();
        if (Turn == 0) {
            if (move.size() == 2) {
                WPawns = makeTurn(move, WPawns);
                A = captured(WPawns, WRooks, WKnights, WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings, "WPawn");
                BPawns = get<6>(A);
                BRooks = get<7>(A);
                BKnights = get<8>(A);
                BBishops = get<9>(A);
                BQueens = get<10>(A);
                BKings = get<11>(A);
                // функцыя маэ виконуватись першою, пысля чого потрыбно виконувати функцыю  captured, яку потрыбно выдредагувати
            }
            else {
                if (move[0] == 'R') {
                    WRooks = makeTurn(move, WRooks);
                    A = captured(WPawns, WRooks, WKnights, WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings, "WRook");
                    BPawns = get<6>(A);
                    BRooks = get<7>(A);
                    BKnights = get<8>(A);
                    BBishops = get<9>(A);
                    BQueens = get<10>(A);
                    BKings = get<11>(A);

                }
                else if (move[0] == 'K' && move[1] == 'n') {
                    WKnights = makeTurn(move, WKnights);
                    A = captured(WPawns, WRooks, WKnights, WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings, "WKnight");
                    BPawns = get<6>(A);
                    BRooks = get<7>(A);
                    BKnights = get<8>(A);
                    BBishops = get<9>(A);
                    BQueens = get<10>(A);
                    BKings = get<11>(A);

                }
                else if (move[0] == 'B') {
                    WBishops = makeTurn(move, WBishops);
                    A = captured(WPawns, WRooks, WKnights, WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings, "WBishop");
                    BPawns = get<6>(A);
                    BRooks = get<7>(A);
                    BKnights = get<8>(A);
                    BBishops = get<9>(A);
                    BQueens = get<10>(A);
                    BKings = get<11>(A);

                }
                else if (move[0] == 'Q') {
                    WQueens = makeTurn(move, WQueens);
                    A = captured(WPawns, WRooks, WKnights, WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings, "WQueen");
                    BPawns = get<6>(A);
                    BRooks = get<7>(A);
                    BKnights = get<8>(A);
                    BBishops = get<9>(A);
                    BQueens = get<10>(A);
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
        }
        else {
            if (move.size() == 2) {
                BPawns = makeTurn(move, BPawns);
                A = captured(WPawns, WRooks, WKnights, WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings, "BPawn");
                WPawns = get<0>(A);
                WRooks = get<1>(A);
                WKnights = get<2>(A);
                WBishops = get<3>(A);
                WQueens = get<4>(A);
                WKings = get<5>(A);

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

        board = render(WPawns, BPawns, WRooks, BRooks, WKnights, BKnights, WBishops, BBishops, WQueens, BQueens, WKings, BKings, board);
        for (int i = 0; i < WPawns.size(); i++) {
            WPawns[i].Predicthion = WPawns[i].predicthion(WPawns[i].coordinates, board);
        }
        for (int i = 0; i < BPawns.size(); i++) {
            BPawns[i].Predicthion = BPawns[i].predicthion(BPawns[i].coordinates, board);
        }
        for (int i = 0; i < WRooks.size(); i++) {
            WRooks[i].Predicthion = WRooks[i].predicthion(WRooks[i].coordinates, board);
        }
        for (int i = 0; i < BRooks.size(); i++) {
            BRooks[i].Predicthion = BRooks[i].predicthion(BRooks[i].coordinates, board);
        }
        for (int i = 0; i < WKnights.size(); i++) {
            WKnights[i].Predicthion = WKnights[i].predicthion(WKnights[i].coordinates, board);
        }
        for (int i = 0; i < BKnights.size(); i++) {
            BKnights[i].Predicthion = BKnights[i].predicthion(BKnights[i].coordinates, board);
        }
        for (int i = 0; i < WBishops.size(); i++) {
            WBishops[i].Predicthion = WBishops[i].predicthion(WBishops[i].coordinates, board);
        }
        for (int i = 0; i < BBishops.size(); i++) {
            BBishops[i].Predicthion = BBishops[i].predicthion(BBishops[i].coordinates, board);
        }
        for (int i = 0; i < WQueens.size(); i++) {
            WQueens[i].Predicthion = WQueens[i].predicthion(WQueens[i].coordinates, board);
        }
        for (int i = 0; i < BQueens.size(); i++) {
            BQueens[i].Predicthion = BQueens[i].predicthion(BQueens[i].coordinates, board);
        }
        WKings[0].Predicthion = WKings[0].predicthion(WKings[0].coordinates, board, WDeadSquares(BPawns, BRooks, BKnights, BBishops, BQueens, BKings, WPawns, WRooks, WKnights, WBishops, WQueens, WKings));
        BKings[0].Predicthion = BKings[0].predicthion(BKings[0].coordinates, board, BDeadSquares(BPawns, BRooks, BKnights, BBishops, BQueens, BKings, WPawns, WRooks, WKnights, WBishops, WQueens, WKings));

        Turn = (Turn + 1) % 2;
    }

    return 1;
}

