#include "slBoard.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int main(int arc, char* argv[]){
     string str = argv[1];
    
    istringstream iss(str);
    string t;
    string line;

    slBoard sl; 

    iss >> t;

    int games = stoi(t); 

    // N L S 

    int n, l ,s; 
    for (int i = 1; i <= games; i++){
        cout << "Board Game #" << i << ":\n";
        iss >> t; 
        n = stoi(t);
        iss >> t;
        l = stoi(t);
        iss >> t; 
        s = stoi(t);

        cout << n << " " << l << " " << s << " " << endl;
        
        // set up game 
        int boardSize = n*n;
        int moves[boardSize];
        for (int j = 0; j < boardSize; j++){
            moves[j] = -1;
        } 

        int a, b;
        for (int ladders = 0; ladders < l; ladders++){
            iss >> t; 
            a = stoi(t) - 1; 
            iss >> t; 
            b = stoi(t) - 1; 
            moves[a] = b;
            cout << "ladder: " << a << ", " << b << endl;
        }

        int c, d;
        for (int snakes = 0; snakes < s; snakes++){
            iss >> t; 
            c = stoi(t) - 1; 
            iss >> t; 
            d = stoi(t) - 1; 
            moves[c] = d;
            cout << "snake: " << c << ", " << d << endl;
        }

        sl.minMoves(moves,boardSize);

    }
    return 0;

}