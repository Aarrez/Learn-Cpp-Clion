#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

struct trinket
        {
    string name {"Item"};
    int value {0};
    float weight {0};
        };

queue<trinket> PopulateQueue(int amount, int maxValue, int baseValue)
{
    queue<trinket> tempQueue {};
    for (int i = 0; i < amount; ++i)
    {
        trinket tempTrinket{};
        tempTrinket.name += to_string(i);
        tempTrinket.value = rand() % maxValue + baseValue;
        float r = static_cast<float> (rand()) / static_cast<float> (RAND_MAX);
        tempTrinket.weight = r;
        tempQueue.push(tempTrinket);
    }
    return tempQueue;
}

int main()
{
    int amount {10};
    queue<trinket> trinketQueue = PopulateQueue(amount, 100, 0);
    do
    {
        cout << trinketQueue.front().name << " ";
        cout << "Value: " << trinketQueue.front().value << " ";
        cout << "Weight: " << trinketQueue.front().weight << endl;
        trinketQueue.pop();
    }
    while(!trinketQueue.empty());
}