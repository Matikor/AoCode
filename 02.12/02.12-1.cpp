#include <iostream>
#include <fstream>

int main()
{
    std::ifstream inFile;
    inFile.open("input.txt");
    std::string table[2];
    int score = 0;

    for(std::string line; std::getline(inFile, line);)
    {
        table[0] = line.substr(0, 1);     
        table[1] = line.substr(2, 3);
        
        if (table[1] == "Y")
        {
            score += 2;
            if(table[0] == "A") {score += 6;}
            else if(table[0] == "B") {score += 3;}
            else if(table[0] == "C") {score += 0;}
        }
        if (table[1] == "X")
        {
            score += 1;
            if(table[0] == "A") {score += 3;}
            else if(table[0] == "B") {score += 0;}
            else if(table[0] == "C") {score += 6;}
        }
        if (table[1] == "Z")
        {
            score += 3;
            if(table[0] == "A") {score += 0;}
            else if(table[0] == "B") {score += 6;}
            else if(table[0] == "C") {score += 3;}
        }
    }
    std::cout << score;
}