//
// Created by Aaron Marklund on 2023-11-16.
//
#ifndef LEARNINGCPP_LANGUAGEMAP_H
#define LEARNINGCPP_LANGUAGEMAP_H

#include <vector>
template<typename T, typename U>
struct Entry{
    int index;
    T name;
    U value;
};

template<class T, class U>
        class Map{
        private:
            std::vector<Entry<T, U>> entryList;

public:
    Map(T name, U value);
    void Insert(T name,U value);
    void RemoveByName(T name);
    T LookUpName(T name);
    T LookUpIndex(int index);
    int MapSize();
};

#endif //LEARNINGCPP_LANGUAGEMAP_H
