#include <iostream>
#include <cmath>
#include <iterator> 
#include <map>
#include <list> 
using namespace std;

class LRUCache {
    // stores elements in the cache
    list<char> dq;
    // stores references of key in the cache
    map<char, list<char>::iterator> ma;
    char csize;
    
    public:
        LRUCache(char);
        char refer(char);
};

LRUCache::LRUCache(char n) {
    csize = n;
}

char LRUCache::refer(char x) {
    char last = -1;
    if(ma.find(x) == ma.end()) {
        if (dq.size() == csize) {
            last = dq.back();
            dq.pop_back();
            ma.erase(last);
        }
    }
    else {
        dq.erase(ma[x]);
    }
    dq.push_front(x);
    ma[x] = dq.begin();
    cout << last << endl;
    return last;
}

int main() {
    cout << 'c' << endl;
    // ######## PARAMETERS #######
    unsigned int associativity = 8;
    unsigned int sets = 64;
    // ##########################
    LRUCache cache(2);
    cout << (int) cache.refer(1); 
    cout << (int) cache.refer(2); 
    cout << (int) cache.refer(3); 
    cout << (int) cache.refer(1); 
    cout << (int) cache.refer(4); 
    cout << (int) cache.refer(5); 
    return 0;
}
