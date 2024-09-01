#pragma once

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

template<typename T>
struct linkedList {
    linkedList<T>* next;
    T data;

    // Constructor
    linkedList(T d) : data(d), next(nullptr) {}

    // Insert method
    void operator+=(T d) {
        if (!next) {
            next = new linkedList(d);
        } else {
            next->operator+=(d);
        }
    }

    // Print method
    void print() const {
        cout << "data" << data << endl;
    }

    const void inline display() noexcept{
    
        cout << "data" << data << endl;

        if (next) next->display();
    }

    // Search method
    linkedList<T>* search(T d) {
        if (data == d) return this;
        if (next) return next->search(d);
        return nullptr;
    }

    linkedList* operator[](int index) {
        linkedList* current = this;
        for (size_t i = 0; i < index; i++)
        {
            if (!current->next) return nullptr;
            current = current->next;
        
        }
        return current;
    }

    void operator--(int ph) {
        linkedList* temp = next;
        next = next->next;
        temp->next = nullptr;
        delete temp;
    }
        

    // Destructor
    ~linkedList() {
        delete next; // No need to check if next is nullptr
    }
};


#if 0
int main() {
    linkedList<int> list(1);

    list += 2;
    list += 3;
    list += 4;

    list[1]->print();
    list--;

    list[1]->print();
    return 0;
}
#endif