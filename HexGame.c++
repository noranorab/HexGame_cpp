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

enum class HexNode : short {Empty = 0, B=1, R=2};

class Node{
    private:
        int i;
        int j;
        int n;
        deque<int> edgeList;
    
    public:
        Node(int i, int j):i(i), j(j){};
        Node (int n): n(n){};

        int getNode(int i, int j){ return i*11+j; }
        int getXFromN(int n){ return n/11; }
        int getYFromN(int n){ return n%j; }
        int getX(){ return i; }
        int getY(){ return j; }
        void setX(int i){ i = i; }
        void setY(int j){ j = j; }
        deque<int> getEdgeList(int n){ return edgeList; }

        bool isCornerTypeOne(int n){
            int i = getXFromN(n);
            int j = getYFromN(n);
            return (i==0 && j==0) || (i==n-1 && j==n-1);
        }

        bool isCornerTypeTwo(int n){
            int i = getXFromN(n);
            int j = getYFromN(n);
            return (i==0 && j==n-1) || (i==n-1 && j==0);
        }

        bool isEdge(int n){
            int i = getXFromN(n);
            int j = getYFromN(n);
            return i==0 || j==0 || i==10 || j==10;
        }

        bool isInternal(int n){
            return !isCornerTypeOne(n) && !isCornerTypeTwo(n) && !isEdge(n);
        }

        void setAdjacentsList(int n){
            int i = getXFromN(n);
            int j = getYFromN(n);

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

    public:
        HexGraph(){
            int count=0;
            edgeList.resize(121);
            for(int i=0; i<11; ++i){
                for (int j=0; j<11; ++j){
                    makeNode(i, j, edgeList[count++]);
                }
            }
        }

        void makeNode(int i, int j, deque<int> edgeList){}

       

};
void initGame(){
            for (int j=0; j<11; ++j)
                    {
                        for (int k=0; k<11-j; ++k){
                            cout << " ";
                        }
                        for (int i=0; i<11; ++i){
                            cout << ".  ";
                            
                        }
                        cout <<endl;
                        
                    }
}



class randomPlay{

};


int main(){
    initGame();
}
