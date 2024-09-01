#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <utility>
#include <climits>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <cassert>
#include "pos.cpp"
using std::string, std::vector, std::map, std::set, std::queue, std::pair;
using std::cin, std::cout, std::endl, std::stringstream;
using std::max, std::min;
using std::make_pair, std::make_shared;
using std::priority_queue;
using std::shared_ptr;



template <typename T>
class matrix{
    private:
        vector<T> data;
    public:
        int maxWidth;
        int maxHeight;

    matrix(int w, int h): maxWidth(w), maxHeight(h), data(vector<T>(w*h)){
        
    };
    matrix(int w, int h, T initValiue): maxWidth(w), maxHeight(h){
        for (int i = 0; i < w*h; i++) data.push_back(initValiue);
    };

    inline bool asign(const Pos& pos, T value){
        if (pos.y >= maxHeight || pos.x >= maxWidth) return false;
        int y = pos.y%maxHeight;
        int x = pos.x%maxWidth;
        data[y*maxWidth + x] = value;
        return true;
    };
    inline T operator[](const Pos& pos) const {
        if (pos.y >= maxHeight || pos.x >= maxWidth) {
            throw "out of bounds";
            return T();
        }
        int y = pos.y%maxHeight;
        int x = pos.x%maxWidth;
        return data[y*maxWidth + x];
    };
    inline void display() const noexcept{
        for (int i = 0; i < maxHeight; i++){
            cout << endl;
            for (int j = 0; j < maxWidth; j++){
                cout << data[i*maxWidth + j] << " ";
            }
            cout << endl;
        }
    }


    inline int areaSum(pos rangeStart, pos rangeEnd){
        rangeStart.y = max(rangeStart.y, 0);
        rangeStart.x = max(rangeStart.x, 0);
        rangeEnd.y = min(rangeEnd.y, maxHeight-1);
        rangeEnd.x = min(rangeEnd.x, maxWidth-1);


        int totalSum = 0;

        for (int i = rangeStart.y; i <= rangeEnd.y; i++){
            for (int j = rangeStart.x; j <= rangeEnd.x; j++){
                totalSum += data[i*maxWidth + j];
            }
        }
        return totalSum;
    }

    inline int areaProduct(pos rangeStart, pos rangeEnd){
        rangeStart.y = max(rangeStart.y, 0);
        rangeStart.x = max(rangeStart.x, 0);
        rangeEnd.y = min(rangeEnd.y, maxHeight-1);
        rangeEnd.x = min(rangeEnd.x, maxWidth-1);


        int totalproduct = 1;

        for (int i = rangeStart.y; i <= rangeEnd.y; i++){
            for (int j = rangeStart.x; j <= rangeEnd.x; j++){
                totalproduct *= data[i*maxWidth + j];
            }
        }
        return totalproduct;
    }

    inline void displayArea(pos rangeStart, pos rangeEnd){
        rangeStart.y = max(rangeStart.y, 0);
        rangeStart.x = max(rangeStart.x, 0);
        rangeEnd.y = min(rangeEnd.y, maxHeight-1);
        rangeEnd.x = min(rangeEnd.x, maxWidth-1);



        for (int i = rangeStart.y; i <= rangeEnd.y; i++){
            for (int j = rangeStart.x; j <= rangeEnd.x; j++){
                cout << data[i*maxWidth + j] << " ";
            }
            cout << endl;
        }
    }

};


int main(){
    matrix<int> mat(10,10);
    cout << mat.asign({5,5},1) << endl;
    cout << mat[{5,5}] << endl;

    mat.display();
}



