#include "LanguageMap.h"
#include <iostream>

template<class T>
Map<T>::Map(T name, T value)
{
    Entry<T> temp_entry;
    temp_entry.value = value;
    temp_entry.name = name;
    temp_entry.index = static_cast<int>(entryList.size());
    entryList.push_back(temp_entry);
}

template<class T>
void Map<T>::Insert(T name, T value) {
    Entry<T> temp_entry;
    temp_entry.value = value;
    temp_entry.name = name;
    temp_entry.index = static_cast<int>(entryList.size());
    entryList.push_back(temp_entry);
}

template<class T>
T Map<T>::LookUpName(T name)
{
    for(Entry<T> l : entryList)
    {
        if(l.name == name){
            return l.value;
        }
    }
    return "";
}

template<class T>
T Map<T>::LookUpIndex(int index)
{
    for(Entry<T> l : entryList)
    {
        if(l.index == index){
            return l.value;
        }
    }
    return "";
}


template<class T>
void Map<T>::RemoveByName(T name)
{
    for (unsigned long i = 0; i < entryList.size() - 1; ++i)
    {
        if(entryList[i].name == name)
        {
            entryList.erase(entryList.begin() + static_cast<long>(i));
        }
    }
}
template<class T>
int Map<T>::MapSize() {
    return static_cast<int>(entryList.size());
}

int main(){

    Map<std::string> map("Hello", "Hola");
    map.Insert("Stupid","Pendejo");
    map.Insert("Bitch","Puta");
    map.Insert("Mother","Madre");
    map.Insert("Father","Padre");
    map.Insert("Potato", "Papa")

    for (int i = 0; i < map.MapSize() - 1; ++i)
    {
        std::cout << map.LookUpIndex(i) << std::endl;
    }
    map.RemoveByName("Stupid");

    for (int i = 0; i < map.MapSize() - 1; ++i)
    {
        std::cout << map.LookUpIndex(i) << std::endl;
    }

    std::cout << map.MapSize() << std::endl;

    return 0;
}