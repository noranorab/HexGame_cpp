/*
* Hex Game
* by Nora
* on 14/09/2023
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>

using namespace std;

enum class Player: short { B, R };

enum class HexNode : short {Empty = 0, B=1, R=2};

class HexBoard{
    private :
        int size;
        vector<vector<HexNode>> hex;

    public:
        HexBoard(){};
        HexBoard(int size, vector<vector<HexNode>> hex) : size(size), hex(size, vector<HexNode>(size, HexNode::Empty)){};

        HexNode getHexNode(int x, int y) const{
            return hex[x][y];
        }

        void setHexNode(int x, int y, HexNode node){
            hex[x][y] = node;
        }

        int getSize(){
            return size;
        }

        void setSize(int& size){
            this->size = size;
        }

        bool isWithinHex(int x, int y) const{};

        vector<tuple<int, int>> getAdjacents(int x, int y) const{
            tuple<int, int> positions[] = {
                make_tuple(x+1, y),
                make_tuple(x+1,y+1),
                make_tuple(x,y+1),
                make_tuple(x-1,y+1),
                make_tuple(x-1, y),
                make_tuple(x-1,y-1)
            };

            vector<tuple<int, int>> adjacents;
            for (auto pos: positions){
                auto [x, y] = pos;
                if (isWithinHex(x,y)){
                    adjacents.push_back(pos);
                }
            }

            return adjacents;
        }

};


int main(){

}
