#include <vector>

using namespace std;

class slBoard {
    public: 

    struct aMove { 
    int position;     
    int distance;  
    };

    int fastestSNL();
    int minMoves(int board[], int boardSize);

    private: 
    aMove entry;
};