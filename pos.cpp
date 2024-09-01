#include "testStarter.cpp"

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
using std::priority_queue;




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


namespace posistion{
    void equalityTest(){
        Pos position1(0, 0);
        Pos position2(0, 0);


        ASSERT_EQUAL(position1, position2);
    }


    void plusTest(){
        Pos position1(0, 0);
        Pos position2(1, 1);
        Pos position3 = position1 + position2;
        ASSERT_EQUAL(position3.x, 1);
        ASSERT_EQUAL(position3.y, 1);
    }


    void minusTest(){
        Pos position1(0, 0);
        Pos position2(1, 1);
        Pos position3 = position1 - position2;
        ASSERT_EQUAL(position3.x, -1);
        ASSERT_EQUAL(position3.y, -1);
    }


    void notEqualTest(){
        Pos position1(0, 0);
        Pos position2(1, 1);
        ASSERT_TRUE(position1 != position2);
    }


    void test(){
        equalityTest();
        plusTest();
        minusTest();
        notEqualTest();
    }

    
}