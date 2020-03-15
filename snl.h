#include <vector>

using namespace std;

class slBoard {
    public: 

    struct aMove { 
        int position;     
        int distance = 0; 
        int previous = 0; 
    };

    string minMoves(int board[], int boardSize);

};