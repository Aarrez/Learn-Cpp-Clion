#ifndef LEARNINGCPP_HASHMAP_H
#define LEARNINGCPP_HASHMAP_H
#include <iostream>

class LinkedListEntry{
public:
    LinkedListEntry(std::string key, std::string value);
    std::string key;
    std::string value;
    LinkedListEntry* next = nullptr;
    LinkedListEntry* Last(){
        if(next) return this;
        LinkedListEntry* last = next;
        while(last->next)
            last = last->next;
        return last;
    }
};

class MyHasMap{
public:
    void Initialize(int size);
    void Insert(std::string key, std::string value);
    std::string LookUp(std::string key);
    void Remove(std::string key);
private:
    int HashFunciton(std::string key);
    int size;
    LinkedListEntry** entries;
};


#endif //LEARNINGCPP_HASHMAP_H
