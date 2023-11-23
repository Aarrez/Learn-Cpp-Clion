#include "LanguageMap.h"
#include <iostream>

template<typename T, typename U>
Map<T,U>::Map(T name, U value)
{
    Entry<T, U> temp_entry;
    temp_entry.value = value;
    temp_entry.name = name;
    temp_entry.index = static_cast<int>(entryList.size());
    entryList.push_back(temp_entry);
}

template<typename T, typename U>
void Map<T,U>::Insert(T name, U value) {
    Entry<T, U> temp_entry;
    temp_entry.value = value;
    temp_entry.name = name;
    temp_entry.index = static_cast<int>(entryList.size());
    entryList.push_back(temp_entry);
}
template<typename T, typename U>
void Map<T, U>::RemoveByName(T name)
{

    for(Entry<T, U> l :entryList)
    {
        if(l.name == name)
            entryList.erase(entryList.begin() + l.index);
    }

}

template<typename T, typename U>
T Map<T, U>::LookUpName(T name)
{
    for(Entry<T, U> l : entryList)
    {
        if(l.name == name){
            return l.value;
        }
    }
    return "";
}

template<typename T, typename U>
T Map<T, U>::LookUpIndex(int index)
{
    for(Entry<T, U> l : entryList)
    {
        if(l.index == index){
            return l.value;
        }
    }
    return "";
}



template<typename T, typename U>
int Map<T,U>::MapSize() {
    return static_cast<int>(entryList.size());
}

int main(){

    Map<std::string, std::string> map("Hello", "Hola");
    map.Insert("Stupid","Pendejo");
    map.Insert("Bitch","Puta");
    map.Insert("Mother","Madre");
    map.Insert("Father","Padre");
    map.Insert("Potato", "Papa");

    std::cout << map.LookUpIndex(0) << std::endl;
    std::cout << map.LookUpIndex(1) << std::endl;
    std::cout << map.LookUpIndex(2) << std::endl;
    std::cout << map.LookUpIndex(3) << std::endl;
    std::cout << map.LookUpIndex(4) << std::endl;
    std::cout << map.LookUpIndex(5) << std::endl;
    map.RemoveByName("Hello");

    std::cout << map.LookUpIndex(0) << std::endl;
    std::cout << map.LookUpIndex(1) << std::endl;
    std::cout << map.LookUpIndex(2) << std::endl;
    std::cout << map.LookUpIndex(3) << std::endl;
    std::cout << map.LookUpIndex(4) << std::endl;
    std::cout << map.LookUpIndex(5) << std::endl;

    return 0;
}