#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string line;
    std::ifstream myFile("./input.txt");
    if (myFile.is_open())
    {
        while (std::getline(myFile, line))
        {
            std::cout << line << '\n';
        }
        myFile.close();
    }
    else
        std::cout << "Unable to open file";
    return 0;
}
