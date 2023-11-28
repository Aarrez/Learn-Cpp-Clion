#include "HashMap.h"
#include <limits>

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
    if(entries[hash])
        return nullptr;
    LinkedListEntry<T, U>* toCheck =  entries[hash];
    while (!toCheck)
    {
        if(toCheck->value == hash)
            return toCheck->value;
        toCheck = toCheck->next;
    }
    return nullptr;
}

template<class T, class U>
int MyHasMap<T, U>::HashFunciton(T key)
{
    unsigned long hashDigest = 0;
    for(char c : key)
        hashDigest += static_cast<unsigned long>(c);
    return hashDigest % size;
}

int main()
{
    int max = std::numeric_limits<int>::max();
    MyHasMap<std::string, int> has_map(max);


    std::cout << has_map.HashFunciton("Hel") << std::endl;
    std::cout << has_map.HashFunciton("Cau") << std::endl;
    return 0;
}


