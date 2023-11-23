#ifndef LEARNINGCPP_HASHMAP_H
#define LEARNINGCPP_HASHMAP_H
#include <iostream>
 struct some
{
     some* date;
     int id;
};

template<class T, class U>
class LinkedListEntry{
public:
    LinkedListEntry(T key, U value);
    T key;
    U value;
    LinkedListEntry* next = nullptr;
    LinkedListEntry* Last(){
        if(next) return this;
        LinkedListEntry* last = next;
        while(last->next)
            last = last->next;
        return last;
    }
};
template<class T, class U>
class MyHasMap{
public:
    MyHasMap(int size)
    {
        this->size = size;
        entries = new LinkedListEntry*[size];
    }
    void Insert(T key, U value);
    U LookUp(T key);
    void Remove(T key);
private:
    int HashFunciton(T key);
    int size;
    LinkedListEntry<T, U>** entries;

    ~MyHasMap()
    {
        delete entries;
    }
};


#endif //LEARNINGCPP_HASHMAP_H
