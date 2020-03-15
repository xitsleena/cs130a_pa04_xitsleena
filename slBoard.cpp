#include "slBoard.h"
#include <queue>
#include <iostream>
#include <sstream>
#include<string>


using namespace std; 

int slBoard::minMoves(int board[], int boardSize){
    bool *visited = new bool[boardSize];
    
    for (int i = 0; i < boardSize; i++){
        visited[i] = false; 
    }

    queue<aMove> q; 
    queue<string> snlq;
    string test = "bam";

    visited[0] = true; 
    aMove firstPosition;
    firstPosition.position = 0; 
    firstPosition.distance = 0;

    q.push(firstPosition);
    snlq.push(test + to_string(firstPosition.position + 1));

    aMove am; 
   // aMove a; 
   // a.distance = 0;
   // a.position = 6;

    //cout << "HELLO " << firstPosition.position + 1 << endl;
    while (!q.empty()) 
    { 
        if (q.front().distance > am.distance){
            cout << "HELLO " << q.front().position + 1 << ", " << q.front().distance << endl;
        }
        am = q.front(); 
        // cout << "p" << am.position << " ";
        int vertex = am.position;  
        // cout << vertex << endl;

        // If front vertex is the destination vertex, 
        // we are done 
        if (vertex == boardSize-1){
            //cout << "BYEBYE" << endl;
            break; 
        }

        q.pop(); 
        // cout << snlq.front() << " ";
        // snlq.pop();
        
        int k = vertex + 6;
        if (vertex + 6 >= boardSize) {
            k = boardSize - 1;
        }

        for (int j = k; j >= vertex; j--) 
        { 
            if (!visited[j]) 
            { 
                //cout << "j:" << j << endl;
                aMove a;
                a.position = j;
                a.distance = (am.distance + 1); 
                visited[j] = true; 
                if (a.position + 1 == 100){
                    //cout << "BYE" << endl;
                    //break;
                    //cout << "FINISHED 100" << endl;
                    cout << a.distance << endl;
                    return a.distance; 
                }
                if (board[j] != -1) {
                    if (a.position > board[j] +1){
                        // snake
                        cout << "S|L: " << a.position + 1 << "-" << board[j] + 1 << endl;
                    }
                    else {
                        // ladder
                        //cout << "S|L: " << a.position + 1 << "+" << board[j] + 1 << endl;
                    }
                    a.position = board[j]; 
                }
                else {
                    // cout << a.position + 1 << ", " << a.distance << endl;
                    // a.position = j; 
                    // cout << a.position << endl;
                }
                q.push(a); 
                // snlq.push(to_string(a.position + 1));
                //cout << "p" << a.position << " ";

            } 
        } 
    } 
    //cout << "FINISHED 100" << endl;

    cout << am.distance << endl;
    return am.distance; 
} 

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

        //cout << n << " " << l << " " << s << " " << endl;
        
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
            cout << "ladder: " << a + 1 << ", " << b + 1 << endl;
        }

        int c, d;
        for (int snakes = 0; snakes < s; snakes++){
            iss >> t; 
            c = stoi(t) - 1; 
            iss >> t; 
            d = stoi(t) - 1; 
            moves[c] = d;
            cout << "snake: " << c + 1 << ", " << d + 1 << endl;
        }

        sl.minMoves(moves,boardSize);

    }
    return 0;

}


