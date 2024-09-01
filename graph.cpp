
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


#if __cplusplus < 201103L
#endif





class vertex
/**
 * this class is meant to be used by graph
*/
{
private:
    /* data */
public:
/**
 * there are multiple different ways to connect to other vertex
*/
using connectionType = string;
map<connectionType, vector<string>> connections;
string name;
    vertex(string name): name(name){};

    inline void display(){
        cout << "vertex: " << name << endl;
        for (auto it = connections.begin(); it != connections.end(); it++){
            cout << it->first << ": ";
            for (int i = 0; i < it->second.size(); i++){
                const string& connection = it->second[i];
                cout << "\t" << connection << " ";
            }
            cout << endl;
        }
    }
};



class graph
{
private:
    /* data */
public:
    map<string, vertex*> vertexes = {};
    set<string> supportedConnectionTypes;
    graph(set<string> supportedConnectionTypes): supportedConnectionTypes(supportedConnectionTypes){};
    ~graph(){

        for (auto it = vertexes.begin(); it != vertexes.end(); it++){
            delete it->second;
        }
    };


    bool createVertex(string name){
        if (vertexes.find(name) != vertexes.end()) return false;
        vertexes[name] = new vertex(name);
        return true;
    }


    bool addConnection(string from, string conectionType, string to){

        if (supportedConnectionTypes.find(conectionType) == supportedConnectionTypes.end()) return false;
        if (vertexes.find(from) == vertexes.end()) return false;
        if (vertexes.find(to) == vertexes.end()) return false;


        vertexes[from]->connections[conectionType].push_back(to);

        return true;
    }


    void display(){
        for (auto it = vertexes.begin(); it != vertexes.end(); it++){
            it->second->display();
        }

    }


    vector<string> getNeighbors(vector<string> startingVertexNames, string connectionType){
        if (this->supportedConnectionTypes.find(connectionType) == this->supportedConnectionTypes.end()) throw "connection type not supported";
        for (vector<string>::iterator vertexName = startingVertexNames.begin(); vertexName != startingVertexNames.end(); vertexName++){

            if (vertexes.find(*vertexName) == vertexes.end()) throw "vertex not found";
            const vertex* v = vertexes[*vertexName];

    
    
        }
    }


};






int main(){
    graph g = graph({"friend", "parent", "child"});
    g.createVertex("josh");
    g.createVertex("jan");

    g.createVertex("kelman");
    g.createVertex("albert");
    g.createVertex("bert");



    g.addConnection("josh", "friend", "jan");
    g.addConnection("josh", "friend", "kelman");


    g.addConnection("jan", "friend", "albert");
    g.addConnection("jan", "friend", "bert");

    g.addConnection("kelman", "child", "albert");
    g.addConnection("kelman", "child", "bert");


    g.display();




    return 0;
}