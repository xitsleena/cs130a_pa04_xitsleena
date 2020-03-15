#include <vector>
#include <map>

using namespace std;

class slBoard {
    public: 

    struct aMove { 
        int position;     
        int distance; 
        int previous = 0; 
    };

    map<string,string> minMoves(int board[], int boardSize);
    void minPath(map<string,string> order, int boardSize);

};