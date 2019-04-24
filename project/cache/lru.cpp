#include <iostream>
#include <cmath>
#include <iterator> 
#include <map>
#include <list> 
#include <fstream>
#include <stdlib.h>

using namespace std;

class LRUCache {
    public:
        // stores elements in the cache
        list<long> dq;
        // stores references of key in the cache
        map<long, list<long>::iterator> ma;
        char csize;
    
        LRUCache(char);
        long refer(long);
};

LRUCache::LRUCache(char n) {
    csize = n;
}

long LRUCache::refer(long x) {
    long last = -1;
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
    char block_size = 128;
    
    // ##########################
    map<char, LRUCache *> cache_sets;
    char i;
    for(i = 0; i < sets; i++) {
        cache_sets[i] = new LRUCache(associativity); 
    }
    
    ifstream trace;
    const string trace_file = "dummy.txt";
    trace.open(trace_file.c_str());

    unsigned long cycles_later, unk, address;
    unsigned char operation;
    string word;
    
    unsigned long tag;
    unsigned char set;

    while(trace >> cycles_later >> operation >> word) {
	// cout << cycles_later << " " << operation << " " << word << endl;
	address = strtol(word.c_str(), NULL, 16);
        switch(operation) {
	    case 'W':
		break;
	    case 'R':
		trace >> unk;
		break;
	}
	set = (address >> 6) & (63);
	tag = (address >> 11);
    }   
 
    return 0;
}
