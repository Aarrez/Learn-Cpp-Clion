#include "HashMap.h"

template<typename T, typename U>
void MyHasMap<T, U>::Insert(T key, U value)
{
    int hash = HashFunciton(key);
    if(entries[hash])
        entries[hash] = new LinkedListEntry(key, value);
    else
        entries[hash]->Last()->next = new LinkedListEntry(key, value);
}

template<class T, class U>
U MyHasMap<T, U>::LookUp(T key)
{
    int hash = HashFunciton(key);
    if(entries[key])
        return nullptr;
    LinkedListEntry<T, U>* toCheck =  entries[key];
    while (!toCheck)
    {
        if(toCheck->value == key)
            return toCheck->value;
        toCheck = toCheck->next;
    }
    return nullptr;
}

template<class T, class U>
int MyHasMap<T, U>::HashFunciton(T key)
{
    int hashDigest = 0;
    for(char c : key)
        hashDigest += static_cast<int>(c);
    return hashDigest % size;
}

int main()
{

    return 0;
}


