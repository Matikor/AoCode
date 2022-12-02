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
            score += 3;
            if(table[0] == "A") {score += 1;}
            else if(table[0] == "B") {score += 2;}
            else if(table[0] == "C") {score += 3;}
        }
        if (table[1] == "X")
        {
            score += 0;
            if(table[0] == "A") {score += 3;}
            else if(table[0] == "B") {score += 1;}
            else if(table[0] == "C") {score += 2;}
        }
        if (table[1] == "Z")
        {
            score += 6;
            if(table[0] == "A") {score += 2;}
            else if(table[0] == "B") {score += 3;}
            else if(table[0] == "C") {score += 1;}
        }
    }
    std::cout << score;
}