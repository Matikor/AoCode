#include <iostream>
#include <fstream>

int main()
{
    int calories, top3[3] = {0, 0, 0}, temp;
    std::ifstream inFile;
    inFile.open("input1.txt");  
         
    for(std::string line; std::getline(inFile, line);)
    {  
        if(line == "") 
        {
            for (int i = 0; i < 3; i++)
            {
                if(top3[i] < calories)
                {
                    temp = top3[i];
                    top3[i] = calories;
                    calories = temp;
                }
            }
            calories = 0;
            continue;
        }
        calories += std::stoi(line);
    }
    std::cout << top3[0] + top3[1] + top3[2];;
}