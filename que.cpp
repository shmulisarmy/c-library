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
#include "linkedList.cpp"
using std::string, std::vector, std::map, std::set, std::queue, std::pair;
using std::cin, std::cout, std::endl, std::stringstream;
using std::max, std::min;
using std::make_pair, std::make_shared;
using std::priority_queue;
using std::shared_ptr;

template <typename T>
class que
{
public:
    linkedList<T>* head = nullptr;
    linkedList<T>* tail = nullptr;
    int size = 0;
    inline void push(T d){
        linkedList<T>* temp = new linkedList<T>(d);
        if(head == nullptr){
            head = temp;
            tail = temp;
        }else{
            tail->next = temp;
            tail = tail->next;
        }
        size++;
    };
    inline T operator--(int ph){
        linkedList<T>* temp = head;
        head = head->next;
        temp->next = nullptr;
        T data = temp->data;
        delete temp;
        size--;
        return data;
    }

    inline void display(){
        linkedList<T>* temp = head;
        while(temp){
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
    inline linkedList<T>* operator [](int index){
        linkedList<T>* temp = head;
        for(int i = 0; i < index; i++){
            if(temp == nullptr) return nullptr;
            temp = temp->next;
        }
        return temp;
    }
    que(T initialValues[] = nullptr, size_t count = 0){
        for(size_t i = 0; i < count; i++){
            this->push(initialValues[i]);
        }
    };
    ~que(){
        while(head){
            linkedList<T>* temp = head;
            head = head->next;
            delete temp;
        }
    };
};


#define debug(X) cout << __LINE__ << ": " << #X << " = " << X << endl





#if 0

int main(){
    que<int> q;
    debug(sizeof(q));

    

    static_assert(sizeof(q) == 24, "que is not 8 bytes");
    // q.push(1);
    // q.push(2);
    // q.push(3);
    // q.push(4);
    // q.display();

    // cout << q-- << endl;
    // cout << q-- << endl;
    // cout << q-- << endl;


}
#endif
