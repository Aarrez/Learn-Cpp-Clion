#include <fstream>
#include <iostream>


int main()
{
    std::ofstream myfile ("example.txt");
    if (myfile.is_open()) {
        myfile << "This is a line.\n";
        myfile << "This is another line.\n";
        myfile.close();
    }
    else std::cout << "Unable to write on file";

    std::fstream stream;
    stream.open("example.txt");

    if(stream.is_open())
    {
        int myInt = 15;
        stream.write((char*)&myInt, sizeof(int));
        stream.close();
    }

    std::string line;
    std::ifstream yourfile ("example.txt");
    if (yourfile.is_open()) {
        while ( getline (yourfile, line) ) {
            std::cout << line << '\n';
        }
        yourfile.close();
    }
    else std::cout << "Unable to read file";
}
