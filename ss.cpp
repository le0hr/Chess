#include<iostream>
#include <vector>

using namespace std;


tuple <vector <WPawn>, vector <WRook>, vector <WKnight>, vector <WBishop>, vector <WQueen>, vector <WKing>, vector <BPawn>, vector <BRook>, vector <BKnight>, vector <BBishop>, vector <BQueen>, vector <BKing>>  captured (vector <WPawn> WPawns, vector <WRook> WRooks, vector <WKnight> WKnights, vector <WBishop> WBishops, vector <WQueen> WQueens, vector <WKing> WKings,  vector <BPawn> BPawns, vector <BRook> BRooks, vector <BKnight> BKnights, vector <BBishop> BBishops, vector <BQueen> BQueens, vector <BKing> BKings, string piece ){
    tuple <vector <WPawn>, vector <WRook>, vector <WKnight> , vector <WBishop>, vector <WQueen>, vector <WKing>,vector <BPawn>, vector <BRook>, vector <BKnight>, vector <BBishop>, vector <BQueen>, vector <BKing>> a;
    a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};
    if (piece == "WPawn"){
        for (size_t i = 0; i < WPawns.size(); i++){
            for (size_t j = 0; j < WPawns[i].Predicthion.size(); j++){
                if (WPawns[i].Predicthion[j][2] == 0){
                     for (size_t q = 0; q < BPawns.size(); q++){
                        if (WPawns[i].Predicthion[j][0] == get<0>(BPawns[q].coordinates) && WPawns[i].Predicthion[j][1] == get<1>(BPawns[q].coordinates)){
                            BPawns.erase(BPawns.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};
                            return a;
                        }
                     }
                     for (size_t q = 0; q < BRooks.size(); q++){
                        if (WPawns[i].Predicthion[j][0] == get<0>(BRooks[q].coordinates) && WPawns[i].Predicthion[j][1] == get<1>(BRooks[q].coordinates)){
                            BRooks.erase(BRooks.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};
                            return a;
                        }
                     }
                     for (size_t q = 0; q < BKnights.size(); q++){
                        if (WPawns[i].Predicthion[j][0] == get<0>(BKnights[q].coordinates) && WPawns[i].Predicthion[j][1] == get<1>(BKnights[q].coordinates)){
                            BKnights.erase(BKnights.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};
                            return a;
                        }
                     }
                     for (size_t q = 0; q < BBishops.size(); q++){
                        if (WPawns[i].Predicthion[j][0] == get<0>(BBishops[q].coordinates) && WPawns[i].Predicthion[j][1] == get<1>(BBishops[q].coordinates)){
                            BBishops.erase(BBishops.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};
                            return a;
                        }
                     }
                    for (size_t q = 0; q < BQueens.size(); q++){
                        if (WPawns[i].Predicthion[j][0] == get<0>(BQueens[q].coordinates) && WPawns[i].Predicthion[j][1] == get<1>(BQueens[q].coordinates)){
                            BQueens.erase(BQueens.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};
                            return a;
                        }
                    }
                     
                     //дописати для інших фігур + по шаблону зробити для інших відгалуженнь
                }
            }
        }
    }
    else if (piece == "WRook"){
        for (size_t i = 0; i < WRooks.size(); i++){
            for (size_t j = 0; j < WRooks[i].Predicthion.size(); j++){
                if (WRooks[i].Predicthion[j][2] == 0){
                     for (size_t q = 0; q < BPawns.size(); q++){
                        if (WRooks[i].Predicthion[j][0] == get<0>(BPawns[q].coordinates) && WRooks[i].Predicthion[j][1] == get<1>(BPawns[q].coordinates)){
                            BPawns.erase(BPawns.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};
                            return a;
                        }
                     }
                     for (size_t q = 0; q < BRooks.size(); q++){
                        if (WRooks[i].Predicthion[j][0] == get<0>(BRooks[q].coordinates) && WRooks[i].Predicthion[j][1] == get<1>(BRooks[q].coordinates)){
                            BRooks.erase(BRooks.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};
                            return a;
                        }
                     }
                     for (size_t q = 0; q < BKnights.size(); q++){
                        if (WRooks[i].Predicthion[j][0] == get<0>(BKnights[q].coordinates) && WRooks[i].Predicthion[j][1] == get<1>(BKnights[q].coordinates)){
                            BKnights.erase(BKnights.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};
                            return a;
                        }
                     }
                     for (size_t q = 0; q < BBishops.size(); q++){
                        if (WRooks[i].Predicthion[j][0] == get<0>(BBishops[q].coordinates) && WRooks[i].Predicthion[j][1] == get<1>(BBishops[q].coordinates)){
                            BBishops.erase(BBishops.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};
                            return a;
                        }
                     }
                    for (size_t q = 0; q < BQueens.size(); q++){
                        if (WRooks[i].Predicthion[j][0] == get<0>(BQueens[q].coordinates) && WRooks[i].Predicthion[j][1] == get<1>(BQueens[q].coordinates)){
                            BQueens.erase(BQueens.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};
                            return a;
                        }
                    }
                }
            }
        }

    }
    else if (piece == "WKnight"){
        for (size_t i = 0; i < WKnights.size(); i++){
            for (size_t j = 0; j < WKnights[i].Predicthion.size(); j++){
                if (WKnights[i].Predicthion[j][2] == 0){
                     for (size_t q = 0; q < BPawns.size(); q++){
                        if (WKnights[i].Predicthion[j][0] == get<0>(BPawns[q].coordinates) && WKnights[i].Predicthion[j][1] == get<1>(BPawns[q].coordinates)){
                            BPawns.erase(BPawns.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};
                            return a;
                        }
                     }
                     for (size_t q = 0; q < BRooks.size(); q++){
                        if (WKnights[i].Predicthion[j][0] == get<0>(BRooks[q].coordinates) && WKnights[i].Predicthion[j][1] == get<1>(BRooks[q].coordinates)){
                            BRooks.erase(BRooks.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};                            
                            return a;
                        }
                     }
                     for (size_t q = 0; q < BKnights.size(); q++){
                        if (WKnights[i].Predicthion[j][0] == get<0>(BKnights[q].coordinates) && WKnights[i].Predicthion[j][1] == get<1>(BKnights[q].coordinates)){
                            BKnights.erase(BKnights.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};                            
                            return a;
                        }
                     }
                     for (size_t q = 0; q < BBishops.size(); q++){
                        if (WKnights[i].Predicthion[j][0] == get<0>(BBishops[q].coordinates) && WKnights[i].Predicthion[j][1] == get<1>(BBishops[q].coordinates)){
                            BBishops.erase(BBishops.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};                            
                            return a;
                        }
                     }
                     for (size_t q = 0; q < BQueens.size(); q++){
                        if (WKnights[i].Predicthion[j][0] == get<0>(BQueens[q].coordinates) && WKnights[i].Predicthion[j][1] == get<1>(BQueens[q].coordinates)){
                            BQueens.erase(BQueens.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};                        
                            return a;
                        }
                    }
                }
            }
        }
    }
    else if (piece == "WBishop"){
        for (size_t i = 0; i < WBishops.size(); i++){
            for (size_t j = 0; j < WBishops[i].Predicthion.size(); j++){
                if (WBishops[i].Predicthion[j][2] == 0){
                     for (size_t q = 0; q < BPawns.size(); q++){
                        if (WBishops[i].Predicthion[j][0] == get<0>(BPawns[q].coordinates) && WBishops[i].Predicthion[j][1] == get<1>(BPawns[q].coordinates)){
                            BPawns.erase(BPawns.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};                        
                            return a;
                        }
                     }
                     for (size_t q = 0; q < BRooks.size(); q++){
                        if (WBishops[i].Predicthion[j][0] == get<0>(BRooks[q].coordinates) && WBishops[i].Predicthion[j][1] == get<1>(BRooks[q].coordinates)){
                            BRooks.erase(BRooks.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};                        
                            return a;
                        }
                     }
                     for (size_t q = 0; q < BKnights.size(); q++){
                        if (WBishops[i].Predicthion[j][0] == get<0>(BKnights[q].coordinates) && WBishops[i].Predicthion[j][1] == get<1>(BKnights[q].coordinates)){
                            BKnights.erase(BKnights.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};                        
                            return a;
                        }
                     }
                     for (size_t q = 0; q < BBishops.size(); q++){
                        if (WBishops[i].Predicthion[j][0] == get<0>(BBishops[q].coordinates) && WBishops[i].Predicthion[j][1] == get<1>(BBishops[q].coordinates)){
                            BBishops.erase(BBishops.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};                        
                            return a;
                        }
                     }
                     for (size_t q = 0; q < BQueens.size(); q++){
                        if (WBishops[i].Predicthion[j][0] == get<0>(BQueens[q].coordinates) && WBishops[i].Predicthion[j][1] == get<1>(BQueens[q].coordinates)){
                            BQueens.erase(BQueens.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};                        
                            return a;
                        }
                     }
                }
            }
        }
        
    }
    else if (piece == "WQueen"){
        for (size_t i = 0; i < WQueens.size(); i++){
            for (size_t j = 0; j < WQueens[i].Predicthion.size(); j++){
                if (WQueens[i].Predicthion[j][2] == 0){
                    for (size_t q = 0; q < BPawns.size(); q++){
                        if (WQueens[i].Predicthion[j][0] == get<0>(BPawns[q].coordinates) && WQueens[i].Predicthion[j][1] == get<1>(BPawns[q].coordinates)){
                            BPawns.erase(BPawns.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};                        
                            return a;
                        }
                    }
                    for (size_t q = 0; q < BRooks.size(); q++){
                        if (WQueens[i].Predicthion[j][0] == get<0>(BRooks[q].coordinates) && WQueens[i].Predicthion[j][1] == get<1>(BRooks[q].coordinates)){
                            BRooks.erase(BRooks.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};                        
                            return a;
                        }
                    }
                    for (size_t q = 0; q < BKnights.size(); q++){
                        if (WQueens[i].Predicthion[j][0] == get<0>(BKnights[q].coordinates) && WQueens[i].Predicthion[j][1] == get<1>(BKnights[q].coordinates)){
                            BKnights.erase(BKnights.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};                        
                            return a;
                        }
                    }
                    for (size_t q = 0; q < BBishops.size(); q++){
                        if (WQueens[i].Predicthion[j][0] == get<0>(BBishops[q].coordinates) && WQueens[i].Predicthion[j][1] == get<1>(BBishops[q].coordinates)){
                            BBishops.erase(BBishops.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};                        
                            return a;
                        }
                    }
                    for (size_t q = 0; q <BQueens.size(); q++){
                        if (WQueens[i].Predicthion[j][0] == get<0>(BQueens[q].coordinates) && WQueens[i].Predicthion[j][1] == get<1>(BQueens[q].coordinates)){
                            BQueens.erase(BQueens.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};                        
                            return a;
                        }
                    }
                }
            }
        }
    }
    else if (piece == "WKing"){
        for (size_t i = 0; i < WKings.size(); i++){
            for (size_t j = 0; j < WKings[i].Predicthion.size(); j++){
                if (WKings[i].Predicthion[j][2] == 0){
                    for (size_t q = 0; q < BPawns.size(); q++){
                        if (WKings[i].Predicthion[j][0] == get<0>(BPawns[q].coordinates) && WKings[i].Predicthion[j][1] == get<1>(BPawns[q].coordinates)){
                            BPawns.erase(BPawns.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};                        
                            return a;
                        }
                    }
                    for (size_t q = 0; q < BRooks.size(); q++){
                        if (WKings[i].Predicthion[j][0] == get<0>(BRooks[q].coordinates) && WKings[i].Predicthion[j][1] == get<1>(BRooks[q].coordinates)){
                            BRooks.erase(BRooks.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};                        
                            return a;
                        }
                    }
                    for (size_t q = 0; q < BKnights.size(); q++){
                        if (WKings[i].Predicthion[j][0] == get<0>(BKnights[q].coordinates) && WKings[i].Predicthion[j][1] == get<1>(BKnights[q].coordinates)){
                            BKnights.erase(BKnights.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};                        
                            return a;
                        }
                    }
                    for (size_t q = 0; q < BBishops.size(); q++){
                        if (WKings[i].Predicthion[j][0] == get<0>(BBishops[q].coordinates) && WKings[i].Predicthion[j][1] == get<1>(BBishops[q].coordinates)){
                            BBishops.erase(BBishops.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};                        
                            return a;
                        }
                    }
                    for (size_t q = 0; q < BQueens.size(); q++){
                        if (WKings[i].Predicthion[j][0] == get<0>(BQueens[q].coordinates) && WKings[i].Predicthion[j][1] == get<1>(BQueens[q].coordinates)){
                            BQueens.erase(BQueens.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};                        
                            return a;
                        }
                    }
                }
            }
        }
    }
    else if (piece == "BPawn"){
        for (size_t i = 0; i < BPawns.size(); i++){
            for (size_t j = 0; j < BPawns[i].Predicthion.size(); j++){
                if (BPawns[i].Predicthion[j][2] == 0){
                     for (size_t q = 0; q < WPawns.size(); q++){
                        if (BPawns[i].Predicthion[j][0] == get<0>(WPawns[q].coordinates) && BPawns[i].Predicthion[j][1] == get<1>(WPawns[q].coordinates)){
                            WPawns.erase(WPawns.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};
                            return a;
                        }
                     }
                     for (size_t q = 0; q < WRooks.size(); q++){
                        if (BPawns[i].Predicthion[j][0] == get<0>(WRooks[q].coordinates) && BPawns[i].Predicthion[j][1] == get<1>(WRooks[q].coordinates)){
                            WRooks.erase(WRooks.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};
                            return a;
                        }
                     }
                     for (size_t q = 0; q < WKnights.size(); q++){
                        if (BPawns[i].Predicthion[j][0] == get<0>(WKnights[q].coordinates) && BPawns[i].Predicthion[j][1] == get<1>(WKnights[q].coordinates)){
                            WKnights.erase(WKnights.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};
                            return a;
                        }
                     }
                     for (size_t q = 0; q < WBishops.size(); q++){
                        if (BPawns[i].Predicthion[j][0] == get<0>(WBishops[q].coordinates) && BPawns[i].Predicthion[j][1] == get<1>(WBishops[q].coordinates)){
                            WBishops.erase(WBishops.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};
                            return a;
                        }
                     }
                    for (size_t q = 0; q < WQueens.size(); q++){
                        if (BPawns[i].Predicthion[j][0] == get<0>(WQueens[q].coordinates) && BPawns[i].Predicthion[j][1] == get<1>(WQueens[q].coordinates)){
                            WQueens.erase(WQueens.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};
                            return a;
                        }
                    }
                }
            }
        }

    }
    else if (piece == "BRooks"){
        for (size_t i = 0; i < BRooks.size(); i++){
            for (size_t j = 0; j < BRooks[i].Predicthion.size(); j++){
                if (BRooks[i].Predicthion[j][2] == 0){
                     for (size_t q = 0; q < WPawns.size(); q++){
                        if (BRooks[i].Predicthion[j][0] == get<0>(WPawns[q].coordinates) && BRooks[i].Predicthion[j][1] == get<1>(WPawns[q].coordinates)){
                            WPawns.erase(WPawns.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};
                            return a;
                        }
                     }
                     for (size_t q = 0; q < WRooks.size(); q++){
                        if (BRooks[i].Predicthion[j][0] == get<0>(WRooks[q].coordinates) && BRooks[i].Predicthion[j][1] == get<1>(WRooks[q].coordinates)){
                            WRooks.erase(WRooks.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};
                            return a;
                        }
                     }
                     for (size_t q = 0; q < WKnights.size(); q++){
                        if (BRooks[i].Predicthion[j][0] == get<0>(WKnights[q].coordinates) && BRooks[i].Predicthion[j][1] == get<1>(WKnights[q].coordinates)){
                            WKnights.erase(WKnights.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};
                            return a;
                        }
                     }
                     for (size_t q = 0; q < WBishops.size(); q++){
                        if (BRooks[i].Predicthion[j][0] == get<0>(WBishops[q].coordinates) && BRooks[i].Predicthion[j][1] == get<1>(WBishops[q].coordinates)){
                            WBishops.erase(WBishops.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};
                            return a;
                        }
                     }
                    for (size_t q = 0; q < WQueens.size(); q++){
                        if (BRooks[i].Predicthion[j][0] == get<0>(WQueens[q].coordinates) && BRooks[i].Predicthion[j][1] == get<1>(WQueens[q].coordinates)){
                            WQueens.erase(WQueens.begin()+q);
                            a = {WPawns, WRooks, WKnights,WBishops, WQueens, WKings, BPawns, BRooks, BKnights, BBishops, BQueens, BKings};
                            return a;
                        }
                    }
                }
            }
        }

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

int main(){

    BKing dd;
    vector <BKing> a[1];
    
    cout << sizeof(dd)<< '\n';
    cout << sizeof(a);
}