#include <fstream>
#include <iostream>
#include <string>


int main()
{
    // std::ofstream myfile ("example.txt");
    // if (myfile.is_open()) {
    //     myfile << "This is a line.\n";
    //     myfile << "This is another line.\n";
    //     myfile.close();
    // }
    // else std::cout << "Unable to write on file";

    std::fstream iofile{ "AssignmentNodes.txt", std::ios::in | std::ios::out};

    if(!iofile)
    {
        std::cerr << "Uh oh, AssignmentNodes.txt could not be opend! \n";
        return 1;
    }

    char chChar{};

    while (iofile.get(chChar))
    {
        switch (chChar)
        {
            case 'o':
                case 'X':

            iofile.seekg(-1, std::ios::cur);

            iofile << '#';

            iofile.seekg(iofile.tellg(), std::ios::beg);

            break;
        }
    }

    return 0;
    // std::ifstream stream {"AssignmentNodes.txt"};
    // if(stream.is_open())
    // {
    //     int myInt = 2;
    //     stream.read((char*)&myInt, sizeof(int));
    //
    //     // for(std::string line; std::getline(stream, line, 'o');)
    //     // {
    //     //     std::cout << line << std::endl;
    //     // }
    //     stream.close();
    // }
    // else
    // {
    //     std::cout << "Unable to read from file" << std::endl;
    // }

}
