#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <string>

using namespace std;

class HashTable{

    private:

    //structure to hold table entries
    struct HashEntry {
        int key;
        string value;
        bool occupied;
        HashEntry() : key(0), value(""), occupied(false) {}
    };

public:

    //constructor initializes hash table with specified size
    HashTable(int size = 11);
    
    //inserts key & value pair into the table
    void processKey(int key, const string& value);
    
    //displays all entries in the hash table
    void displayTable() const;
    
    //shows probing sequence for a key search
    void traceKey(int key) const;

    vector<HashEntry> table; //storage for hash table entries
    int tableSize; //total slots in the table

    //hash function using division method
    int divisionHash(int key) const;
};

#endif