//
// Created by Aaron Marklund on 2023-11-16.
//
#ifndef LEARNINGCPP_LANGUAGEMAP_H
#define LEARNINGCPP_LANGUAGEMAP_H

#include <vector>
template<class T>
struct Entry{
    int index;
    T name;
    T value;
};

template<class T>
        class Map{
        private:
            std::vector<Entry<T>> entryList;

public:
    Map(T name, T value);
    void Insert(T name,T value);
    T LookUpName(T name);
    T LookUpIndex(int index);
    void RemoveByName(T name);
    int MapSize();
};

#endif //LEARNINGCPP_LANGUAGEMAP_H
