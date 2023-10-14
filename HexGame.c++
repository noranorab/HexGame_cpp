/*
* Hex Game
* by Nora
* on 14/09/2023
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>
#include <deque>

using namespace std;

enum class Player: short { B, R };

enum class HexNode : char {Empty = '.', B='X', R='O'};

class Node{
    private:
        int i;
        int j;
        int n;
        deque<int> edgeList;
        HexNode state = HexNode::Empty;
    
    public:
        Node(int i, int j):i(i), j(j){};
        Node (int n): n(n){};

        enum HexNode getState(){
            return this->state;
        }
        void setState(HexNode state){
            this->state = state;
        }
        static int getNode(int i, int j){ return i*11+j; }
        int getXFromN(){ return n/11; }
        int getYFromN(){ return n%11; }
        int getX(){ return i; }
        int getY(){ return j; }
        void setX(int i){ i = i; }
        void setY(int j){ j = j; }
        deque<int> getEdgeList(int n){ return edgeList; }

        bool isCornerTypeOne(int n){
            int i = getXFromN();
            int j = getYFromN();
            return (i==0 && j==0) || (i==n-1 && j==n-1);
        }

        bool isCornerTypeTwo(int n){
            int i = getXFromN();
            int j = getYFromN();
            return (i==0 && j==n-1) || (i==n-1 && j==0);
        }

        bool isEdge(int n){
            int i = getXFromN();
            int j = getYFromN();
            return i==0 || j==0 || i==10 || j==10;
        }

        bool isInternal(int n){
            return !isCornerTypeOne(n) && !isCornerTypeTwo(n) && !isEdge(n);
        }

        void setAdjacentsList(int n){
            int i = getXFromN();
            int j = getYFromN();

            if(isInternal(n)){
                edgeList.push_front(i*11+j+1);
                edgeList.push_front(i*11+j-1);
                edgeList.push_front((i+1)*11+j);
                edgeList.push_front((i+1)*11+j+1);
                edgeList.push_back((i-1)*11+j);
                edgeList.push_back((i-1)*11+j-1);
            }else if (isCornerTypeOne(n)){
                if (i==0 && j ==0){
                    edgeList.push_front((i+1)*11+j);
                    edgeList.push_front((i*11+(j+1)));
                }else{
                    edgeList.push_front(i*11+(j-1));
                    edgeList.push_front((i-1)*11+j);
                }
            }else if(isCornerTypeTwo(n)){
                if (i==n && j==0){
                    edgeList.push_front((i-1)*11+j);
                    edgeList.push_front(i*11+j+1);
                    edgeList.push_front((i-1)*11+j+1);
                }else{
                    edgeList.push_front(i*11+j-1);
                    edgeList.push_front((i+1)*11+j);
                    edgeList.push_front((i+1)*11+j-1);
                }
            }else{                // edges
                if (j==0){
                    edgeList.push_front(((i-1)*11+j));
                    edgeList.push_front(((i+1)*11+j));
                    edgeList.push_front(((i-1)*11+j+1));
                    edgeList.push_front(((i+1)*11+j+1));
                }else{
                    edgeList.push_front(((i-1)*11+j));
                    edgeList.push_front(((i+1)*11+j));
                    edgeList.push_front(((i-1)*11+j-1));
                    edgeList.push_front(((i+1)*11+j-1));
                }
            }

        }

};


class HexGraph{
    private :
        vector<deque<int>> edgeList;
        vector<bool> visited;

    public:
        HexGraph(){
            int count=0;
            edgeList.resize(121);
            visited.resize(121, false);
            for(int i=0; i<11; ++i){
                for (int j=0; j<11; ++j){
             
                    makeNode(i, j, edgeList[count++]);
                }
            }
        }

        void makeNode(int i, int j, deque<int> edgeList){
            Node node(i,j);
            int n = node.getNode(i, j);
            node.setAdjacentsList(n);
        }

        bool hasConnectedPath(char player, const char *board){

            for (int i=0; i<11; ++i){
                int startNode = Node::getNode(i,0);
                if (player == 'X' && board[startNode] == 'X' && dfs(player, startNode)){
                    return true;
                }else if(player == 'O' && board[startNode] == 'O' && dfs(player, startNode)){
                    return true;
                }
            }
            return false;
        }

       

};

class HexGame{
    public :
        HexGame() : currentPlayer(players[0]), graph(){
            for (int i=0; i<121; ++i){
                board[i] = '.';
                available[i] = true;
            }
        }
        void initGame(){
            for (int j=0; j<11; ++j)
                    {
                        for (int k=0; k<11-j; ++k){
                            cout << " ";
                        }
                        for (int i=0; i<11; ++i){
                            cout << ". ";
                            
                        }
                        cout <<endl;
                        
                    }
        }
        
        bool isAvailable(int n){ return available[n]; }

        

        void markPosition(int n){
            Node node(n);
            int l = node.getXFromN();
            int m = node.getYFromN();

            if (!isAvailable(n)) {
                    return;
            }

            board[n] = currentPlayer;
            available[n] = false;


            drawBoard();

            //switch players;
            currentPlayer = (currentPlayer == players[0]) ? players[1] : players[0];

        }
        char getCurrentPlayer(){
            return currentPlayer;
        }

        void drawBoard(){
            for (int j=0; j<11; ++j)
                    {
                        for (int k=0; k<11-j; ++k){
                            cout << " ";
                        }
                        for (int i=0; i<11; ++i){
                            int n = Node::getNode(i, j);
                            cout << board[n] << " ";
 
                        }
                        cout <<endl;
                        
                    }
        }

        vector<int> availablePositions(){
            vector<int> availablePos;
            for (int i = 0; i<121; ++i){
                if (available[i] == true){
                    availablePos.push_back(i);
                }
            }
            return availablePos;
        }
        void printAvailablePositions(){
            vector<int> availablePos  = availablePositions();
            for (int i=0; i<availablePos.size(); ++i){
                cout << availablePos[i] << " ";
            }
            cout <<endl;
        }
        

    private : 
        char board[121];
        bool available[121];
        char players[2] = {'X', 'O'};
        char currentPlayer;
        HexGraph graph;
};







int main(){
    HexGame hex;
    int pos = 0;
    int total = 121;
    char curr = 'X';
    while (true){
        
        vector<int> allowedPos = hex.availablePositions();
        hex.printAvailablePositions();

        if (curr == 'X'){
            cin >> pos;
            hex.markPosition(allowedPos[pos]);

        }

      

            srand(time(0));
            pos = rand() % total;
            hex.markPosition(allowedPos[pos]);
            total--;
        }
       
    

    return 0;
}
