
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


template <typename T>
inline void extend(set<T> &a, set<T> b);


template <typename T>
inline void extend(set<T>&a, vector<T>b);


class Graph
{
private:
public:
    map<string, map<string, vector<string>>> vertexes;
    set<string> connectionTypes;


    void inline addVertex(string name) noexcept{
        vertexes[name];
        return ;
    }

    void inline addConnectionType(const string connectionType) noexcept{
        connectionTypes.insert(connectionType);
        return ;
    }

    bool inline addConnection(string fromVertex, string toVertex, string connectionType){
        if(vertexes.find(fromVertex) == vertexes.end()){
            return false;
        }

        if(vertexes.find(toVertex) == vertexes.end()){
            return false;
        }

        if(connectionTypes.find(connectionType) == connectionTypes.end()){
            return false;
        }
        vertexes[fromVertex][connectionType].push_back(toVertex);
    
        return true;
    }


    const void inline display() const noexcept{
        cout << "displaying graph" << endl;
        for(auto it = vertexes.begin(); it != vertexes.end(); it++){
            cout << it->first << " : ";
            for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++){
                cout << it2->first << " : ";
                for(auto it3 = it2->second.begin(); it3 != it2->second.end(); it3++){
                    cout << *it3 << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
        cout << "end of display" << endl;
        return ;
    }

    const vector<string> inline expand(string vertexName, vector<string> connectionTypes)const{
        set<string> outVertexes;
        set<string> usingVertexes({vertexName});
        set<string> nextUsingVertexes;
        for (auto connectionType : connectionTypes){
            if (this->connectionTypes.find(connectionType) == this->connectionTypes.end()){
                throw "connection type not found";
            }
            for (string vertexName : usingVertexes){
                if (this->vertexes.at(vertexName).find(connectionType) == this->vertexes.at(vertexName).end()){
                    continue;
                }
                extend(nextUsingVertexes, this->vertexes.at(vertexName).at(connectionType));
            }

            usingVertexes = nextUsingVertexes;
            nextUsingVertexes.clear();
        }

        extend(outVertexes, usingVertexes);
        return vector<string>(outVertexes.begin(), outVertexes.end());
    }
    
};



template <typename T>
inline void extend(set<T> &a, set<T> b){
    for (auto it = b.begin(); it != b.end(); it++){
        a.insert(*it);
    }
    return ;
}


template <typename T>
inline void extend(set<T> &a, vector<T> b){
    for (auto it = b.begin(); it != b.end(); it++){
        a.insert(*it);
    }
    return ;
}




int main(){
    Graph personGraph = Graph();

    personGraph.addConnectionType("friends");
    personGraph.addConnectionType("family");
    personGraph.addConnectionType("acquaintance");
    personGraph.addConnectionType("colleague");



    personGraph.addVertex("John");
    personGraph.addVertex("Jane");
    personGraph.addVertex("Jack");
    personGraph.addVertex("Jill");
    personGraph.addVertex("Jenny");
    personGraph.addVertex("Jenny");



    personGraph.addConnection("John", "Jane", "friends");
    personGraph.addConnection("John", "Jill", "friends");
    personGraph.addConnection("Jane", "Jack", "friends");
    personGraph.addConnection("Jack", "Jill", "friends");
    personGraph.addConnection("Jill", "Jenny", "family");
    personGraph.addConnection("Jenny", "John", "friends");
    personGraph.addConnection("Jenny", "Jane", "friends");


    personGraph.display();



    auto friends = personGraph.expand("John", {"friends", "family"});

    for (auto it = friends.begin(); it != friends.end(); it++){
        cout << *it << " ";
    }
    return 0;
}