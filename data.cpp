#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <ranges>

void shuffleVector(std::vector<std::string> &vec)
{
    auto rng = std::default_random_engine{};
    std::shuffle(vec.begin(), vec.end(), rng);
}

std::string trim(const std::string &str)
{
    const std::string whiteSpace = " \t\n\r\f\v";
    const std::size_t strBegin = str.find_first_not_of(whiteSpace);
    if (strBegin == std::string::npos)
    {
        return "";
    }

    const std::size_t strEnd = str.find_last_not_of(whiteSpace);
    const std::size_t stringRange = strEnd - strBegin + 1;

    return str.substr(strBegin, stringRange);
}

int main()
{
    std::string line;
    std::vector<std::string> v;
    std::ifstream myFile("./input.txt");
    if (myFile.is_open())
    {
        while (std::getline(myFile, line))
        {
            const std::string strTrimmed = trim(line);
            if ("" != strTrimmed)
            {
                v.push_back(strTrimmed);
            }
        }
        myFile.close();
    }
    else
        std::cout << "Unable to open file";

    for (std::string element : v | std::views::take(10))
    {
        std::cout << element << std::endl;
    }

    shuffleVector(v);
    std::cout << "=================>AFTER SHUFFLING" << std::endl;

    for (std::string element : v | std::views::take(10))
    {
        std::cout << element << std::endl;
    }

    return 0;
}
