#include "snl.h"
#include <queue>
#include <iostream>
#include <sstream>
#include<string>
#include<stack>


using namespace std; 

string slBoard::minMoves(int board[], int boardSize){
    string path = "";
    bool *visited = new bool[boardSize];
    
    for (int i = 0; i < boardSize; i++){
        visited[i] = false; 
    }

    queue<aMove> q; 
    queue<string> snlq;
    string hold;
    
    visited[0] = true; 
    aMove firstPosition;
    firstPosition.position = 0; 
    firstPosition.distance = 0;

    q.push(firstPosition);
    //snlq.push(to_string(1));

    aMove am; 
    aMove a;
   // aMove a; 
   // a.distance = 0;
   // a.position = 6;

    //cout << "HELLO " << firstPosition.position + 1 << endl;
    while (!q.empty()) 
    { 
        am = q.front(); 
        int vertex = am.position;  

        // If front vertex is the destination vertex, 
        // we are done 
        if (vertex == boardSize-1){
            break; 
        }

        // cout << "hello " << q.back().position << " bye" << endl;
        q.pop(); 

        
        if (!snlq.empty()){
            if (snlq.back() != hold){
                path += snlq.back() + " ";
            }
           
            snlq.pop();
            hold = snlq.back();
        }
        
        int k = vertex + 6;
        if (vertex + 6 >= boardSize) {
            k = boardSize - 1;
        }

        for (int j = k; j >= vertex; j--) 
        { 
            if (!visited[j]) 
            { 
                a.position = j;
                a.previous = vertex;

                 cout << "check: " << a.position + 1 << ", " << a.previous + 1<< endl;
                a.distance = (am.distance + 1); 
                visited[j] = true; 
                
                // snlq.push(to_string(a.position));
                if (a.position + 1 == boardSize){                    
                    //snlq.push(to_string(a.position));
                    path += to_string(a.previous + 1) + " " + to_string(a.position + 1) + "\n";
                    cout << a.distance << endl;
                    delete[] visited;
                    return path; 
                }
                if (board[j] != -1) {
                    cout << "j:" << j << " ";
                    if (a.position > board[j]+1){
                        // snake
                        // cout << "S|L: " << a.position + 1 << "-" << board[j] + 1 << endl;
                        snlq.push(to_string(a.previous + 1) + "-" + to_string(board[j] + 1));

                    }
                    else {
                        // ladder
                        // snlq.push(to_string(a.previous + 1) + "+" + to_string(board[j] + 1));
                        // cout << "S|L: " << a.position + 1 << "+" << board[j] + 1 << endl;
                    }
                    //cout << "SNL " << a.previous << endl;
                    //a.previous = a.position;
                    //cout << "SNL " << a.previous << endl;
                    a.position = board[j]; 
                    //snlq.push(to_string(a.previous));
                }
                else {
                     q.push(a);
                     snlq.push(to_string(a.previous + 1));

                }
                // q.push(a);
                 // cout << "SNL " << a.previous << endl;
                // snlq.push(to_string(a.previous + 1));
            } 
        } 
    } 

    cout << am.distance << endl;
    return path; 
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
            // cout << "ladder: " << a + 1 << ", " << b + 1 << endl;
        }

        int c, d;
        for (int snakes = 0; snakes < s; snakes++){
            iss >> t; 
            c = stoi(t) - 1; 
            iss >> t; 
            d = stoi(t) - 1; 
            moves[c] = d;
            // cout << "snake: " << c + 1 << ", " << d + 1 << endl;
        }

        string path = sl.minMoves(moves,boardSize);
        cout << path;

        // check board set up
        /*
        for (int i = 0; i < boardSize; i++){
            if (i%n == 0){
                cout << "\n";
            }
            cout << moves[i] << " ";
        }
        */

    }
    return 0;

}


