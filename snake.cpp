#include "snake.h"
#include <queue>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <stack>
#include <iterator>



using namespace std; 

map<string,string> slBoard::minMoves(int board[], int boardSize){
    string path = "";
    bool *visited = new bool[boardSize];
    
    for (int i = 0; i < boardSize; i++){
        visited[i] = false; 
    }

    queue<aMove> q; 
    queue<string> snlq;
    string hold;
    map<string,string> order;
    map<string,string>::iterator itr;

    
    // visited[0] = true; 
    aMove firstPosition;
    firstPosition.position = 0; 
    firstPosition.distance = 0;

    q.push(firstPosition);

    aMove am; 
    aMove a;
 
    int initial = 0;
    while (board[initial] != -1){
        a.position = board[initial]; 
        a.distance = am.distance + 1;
        a.previous = initial;
        // cout << "check: " << a.position + 1 << ", " << a.previous + 1<< endl;
        order[to_string(a.position + 1)] = to_string(a.previous + 1);
        q.push(a);
        initial = a.position;
    }

    while (!q.empty()) 
    { 
        am = q.front(); 
        int vertex = am.position;  

        // If front vertex is the destination vertex, 
        // we are done 
        if (vertex == boardSize-1){
            break; 
        }

        q.pop(); 

        
        int k = vertex + 6;
        if (vertex + 6 >= boardSize) {
            k = boardSize - 1;
        }

        for (int j = k; j > vertex; j--) 
        { 
            if (!visited[j]) 
            { 
                //cout << "j: " << j << ", " << am.distance << endl;
                a.position = j;
                a.previous = vertex;
                a.distance = (am.distance + 1); 

                //cout << "check: " << a.position + 1 << ", " << a.previous + 1 << ", " << a.distance << endl;
                itr = order.find(to_string(a.position + 1));
                if (itr == order.end()){
                    order[to_string(a.position + 1)] = to_string(a.previous + 1);
                }
                visited[j] = true; 
                
                if (a.position + 1 == boardSize){                    
                    cout << a.distance << endl;
                    delete[] visited;
                    return order; 
                }
                while (board[a.position] != -1) {
                    if (a.position > board[a.position]){
                        // snake
                        //cout << "check: " << a.position + 1 << ", " << a.previous + 1<< endl;
                    }
                    else {
                        // ladder
                        //cout << "check: " << a.position + 1 << ", " << a.previous + 1<< endl;
                    }
                    a.previous = a.position;
                    a.position = board[a.position]; 
                    a.distance = (a.distance + 1); 
                    // cout << "check: " << a.position + 1 << ", " << a.previous + 1 << ", " <<a.distance << endl;
                    itr = order.find(to_string(a.position + 1));
                    if (itr == order.end()){
                        order[to_string(a.position + 1)] = to_string(a.previous + 1);
                        q.push(a);
                    }
                    if (a.position + 1 == boardSize){                    
                        cout << a.distance - 1 << endl;
                        delete[] visited;
                        return order; 
                    }
                }
                     q.push(a);
            } 
        } 
    } 

    cout << a.distance << endl;
    delete[] visited;
    return order; 
} 

void slBoard::minPath(map<string,string> order, int boardSize){
    /*
    map<string,string>::iterator itr; 
    cout << "\n order : \n"; 
    cout << "\tKEY\tELEMENT\n"; 
    for (itr = order.begin(); itr != order.end(); ++itr) { 
        cout << '\t' << itr->first 
             << '\t' << itr->second << '\n'; 
    }   
    */
    
    stack<string> path; 
    string position = to_string(boardSize); 
    string last;
    path.push(position);
    bool sol = false;
    while (position != "1"){
        if (stoi(position) > stoi(order[position]) + 6){
            if (sol){
                path.push(position + " ");
            }
            path.push(order[position] + "+");
            sol = true;
        }
        else if (stoi(position) < stoi(order[position]) - 6){
            if (sol){
                path.push(position + " ");
            }
            path.push(order[position] + "-");
            sol = true;
        }
        else {
            path.push(order[position] + " ");
            sol = false;
        }
        position = order[position];
    }
    if (path.top() != "1 "){
        cout << "1" << " ";
    }
    while (!path.empty()){
        cout << path.top();
        path.pop();
    }
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

        map<string,string> path = sl.minMoves(moves,boardSize);
        sl.minPath(path,boardSize);

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


