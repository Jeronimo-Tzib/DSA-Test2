#include "header.h"
#include <iostream>

using namespace std;

int main(){

    //create table with 11 slots
    HashTable ht(11);

    //test insertions
    ht.processKey(23, "Ignacio"); //normal insertion
    ht.processKey(45, "Flakk"); //normal insertion
    ht.processKey(12, "Sahur"); //may collide depending on hash
    ht.processKey(34, "Gurt"); //likely collision
    ht.processKey(56, "Plait"); //demonstrates quadratic probing
    ht.processKey(23, "Tralalelo"); //duplicate key test

    //show final table state
    ht.displayTable();

    //demonstrate key tracing
    ht.traceKey(45); //existing key
    ht.traceKey(12); //existing key with possible collision
    ht.traceKey(99); //non-existent key

    cout << "\nTesting complete.\n";

    return 0;
}