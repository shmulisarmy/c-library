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
using std::priority_queue;



template <typename T>
class Json: public map<string, T>{

public:
    string toString(){
        string outPut;
        outPut += "{";
        for (auto it = this->begin(); it != this->end(); it++){
            outPut += "\"" + it->first + "\": " + it->second + ",";
        }
        outPut.pop_back();
        outPut += "}";
        return outPut;
    };


    void forEach(std::function<void(string, T)> func){
        for (auto it = this->begin(); it != this->end(); it++){
            func(it->first, it->second);
        }
    }

    Json<T> map(std::function<pair<string, T>(string, T)> func){
        Json<T> j = *this;
        pair<string, T> p;
        for (auto it = this->begin(); it != this->end(); it++){
            p = func(it->first, it->second);
            j[p.first] = p.second;
        }

        return j;
    }

    Json<T> filter(std::function<bool(string, T)> func){
        Json<T> j = Json<T>();
        for (auto it = this->begin(); it != this->end(); it++){
            if (func(it->first, it->second)) j[it->first] = it->second;
        }

        return j;
    }

    T reduce(std::function<T(T, T)> func){
        T t;
        for (auto it = this->begin(); it != this->end(); it++){
            t = func(it->second, t);
        }
    }
};



namespace json{



void test(){

    Json<int> j;

    j["a"] = 1;
    j["b"] = 2;
    j["c"] = 3;
    j["d"] = 4;
    j["e"] = 5;
    j["f"] = 6;
    j["g"] = 7;




}



   


}
