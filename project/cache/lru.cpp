#include <iostream>
#include <cmath>
#include <iterator> 
#include <map>
#include <list> 
using namespace std;

class LRUCache {
    public:
        // stores elements in the cache
        list<char> dq;
        // stores references of key in the cache
        map<char, list<char>::iterator> ma;
        char csize;
    
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
    return last;
}

int main() {
    // ######## PARAMETERS #######
    char associativity = 8;
    char sets = 64;
    // ##########################
    map<char, LRUCache *> cache_sets;
    char i;
    for(i = 0; i < sets; i++) {
        cache_sets[i] = new LRUCache(associativity); 
    }
    
    cache_sets[3]->refer(2);
    cout << int(cache_sets[3]->dq.front()) << endl;
    return 0;
}
