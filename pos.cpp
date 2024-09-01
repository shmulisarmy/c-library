#define UsingAsLibrary__

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
using std::string, std::vector, std::map, std::set, std::queue, std::pair;
using std::cin, std::cout, std::endl, std::stringstream;
using std::max, std::min;
using std::make_pair, std::make_shared;
using std::priority_queue;
using std::shared_ptr;



struct Pos
{
    int x;
    int y;
    Pos(int x, int y): x(x), y(y) {}
    Pos(): x(0), y(0) {}
    Pos operator+(Pos other){
        return Pos(x+other.x, y+other.y);
    }
    Pos operator-(Pos other){
        return Pos(x-other.x, y-other.y);
    }
    Pos operator*(int i){
        return Pos(x*i, y*i);
    }
    Pos operator/(int i){
        return Pos(x/i, y/i);
    }
    bool operator==(Pos pos){
        return x == pos.x && y == pos.y;
    }
    bool operator!=(Pos pos){
        return x != pos.x || y != pos.y;
    }   
};


