#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>

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

void getValueInArray(int numberArr[], int value, int size)
{
    int max = size;
    int min = 0;
    int middle;
    middle = (max - min) / 2;
    if(numberArr[middle] > value){
        max--;
    }
    else{
        max++;
    }
    while(true)
    {

        if (numberArr[middle] > value)
        {
            max = middle - 1;
            middle = (max - min) / 2;
        }
        else if(numberArr[middle] < value)
        {
            min = middle + 1;
            middle = (max + min) / 2;
        }
        else
        {
            cout << "Value: " << value <<" was found: " << "index: " << middle << endl;
            return;
        }
    }
}
int main()
{
    std::chrono::duration<double> startTimes[10];
    std::chrono::duration<double> endTimes[10];
    for (int a = 0; a < 10; ++a)
    {
    auto mainStart = std::chrono::system_clock::now();
    int amount{20};
    int numberArray[amount];
    queue<trinket> trinketQueue = PopulateQueue(amount, 100, 0);

    for (int i = 0; i < amount; ++i)
    {
        numberArray[i] = trinketQueue.front().value;
        trinketQueue.pop();
    }
    cout << "SORTED" << endl;
    for (int i = 0; i < amount; ++i)
    {
        int lowestIndex = i;
        for (int j = i + 1; j < amount; ++j)
        {
            if (numberArray[j] < numberArray[lowestIndex])
                lowestIndex = j;
        }
        if (numberArray[i] != numberArray[lowestIndex])
        {
            int some = numberArray[i];
            numberArray[i] = numberArray[lowestIndex];
            numberArray[lowestIndex] = some;
        }

        cout << "index: " << i;
        cout << " Value: " << numberArray[i] << endl;
    }
    srand((unsigned) time(NULL));
    int randomValue = rand() % amount;
    cout << "Search value: " << randomValue;
    getValueInArray(numberArray, numberArray[randomValue], amount);
    auto mainEnd = std::chrono::system_clock::now();
    startTimes[a] = mainStart.time_since_epoch();
    endTimes[a] = mainEnd.time_since_epoch();
    }
    for (int i = 0; i < 10; ++i)
    {
        std::chrono::duration<double> elapsed_time = (endTimes[i] - startTimes[i]);
        cout << "Time: " << elapsed_time.count() << endl;
    }
    }

