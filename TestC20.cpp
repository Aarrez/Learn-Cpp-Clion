#include <iostream>

int width { 2 };
int x { 5 };
int halfWidth {width/2};
std::string userText {};

int main()
{
    x = width;
    std::cout << x << "\n";
    return 0;
}
