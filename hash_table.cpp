#include "header.h"
#include <iostream>
#include <iomanip>

using namespace std;

//constructor to set up table size and initializes empty slots
HashTable::HashTable(int size) : tableSize(size){

    if (tableSize <= 0){
        cout << "Warning: Invalid size. Using default 11.\n";
        tableSize = 11;
    }
    table.resize(tableSize); //create empty table with specified size
}

//division hashing: key mod tableSize for basic distribution
int HashTable::divisionHash(int key) const{

    int positiveKey = abs(key);
    int hashValue = positiveKey % tableSize;

    cout << "Hash calculation: " << positiveKey 
              << " % " << tableSize << " = " << hashValue << "\n";
              
    return hashValue;
}

//inserts key using quadratic probing collision resolution
void HashTable::processKey(int key, const string& value){

    cout << "\nInserting key: " << key << " (" << value << ")\n";
    
    int index = divisionHash(key);
    int attempts = 0;
    
    while (attempts < tableSize){
        int currentIndex = (index + attempts * attempts) % tableSize;
        
        cout << " Attempt " << (attempts + 1) 
                  << ": Checking index " << currentIndex << "\n";
        
        if (!table[currentIndex].occupied){

            //modified assignment
            table[currentIndex].key = key;
            table[currentIndex].value = value;
            table[currentIndex].occupied = true;
            cout << "  Inserted at index " << currentIndex << "\n";
            return;
        }

        //existing key found
        else if (table[currentIndex].key == key){

            cout << "  Key already exists at index " << currentIndex << "\n";
            return;
        }
        //collision occurred
        else{
            cout << "  Collision with key " << table[currentIndex].key << "\n";
        }
        attempts++;
    }
    cout << "Failed to insert key " << key << " - Table full\n";
}

//displays table contents with formatting

void HashTable::displayTable() const{
    cout << "\nCurrent Hash Table State:\n";
    cout << setw(10) << "Index" << setw(10) << "Key" 
              << setw(15) << "Value" << "\n";
    
    //iterate through all table entries
    for (int i = 0; i < tableSize; ++i) {
        if (table[i].occupied) {
            cout << setw(10) << i << setw(10) << table[i].key 
                      << setw(15) << table[i].value << "\n";
        } else {
            cout << setw(10) << i << setw(10) << "---" 
                      << setw(15) << "---" << "\n";
        }
    }
}

//traces probing sequence for key searches
void HashTable::traceKey(int key) const{

    cout << "\nTracing key: " << key << "\n";
    int hash = divisionHash(key); //get initial hash position
    int attempts = 0;

    //follow quadratic probing sequence
    while (attempts < tableSize){

        int currentIndex = (hash + attempts * attempts) % tableSize;
        
        cout << " Check " << (attempts + 1) 
                  << ": Index " << currentIndex << " - ";
        
        if (table[currentIndex].occupied) {
            if (table[currentIndex].key == key){
                cout << "Found! Value: " << table[currentIndex].value << "\n";
                return;
            }
            cout << "Occupied by different key: " 
                      << table[currentIndex].key << "\n";
        } else{
            cout << "Empty slot - key not present\n";
            return;
        }
        attempts++;
    }
    cout << "Key not found after full table scan\n";
}