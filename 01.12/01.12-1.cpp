#include <iostream>
#include <fstream>

int main()
{
    int calories, maxCalories = 0;
    int top3[3];
    std::string data = "1";
    std::ifstream inFile;
    inFile.open("input1.txt");  
         

    for(std::string line; std::getline(inFile, line);)
    {  
        if(line == "") 
        {
            if(calories > maxCalories)
            {
                maxCalories = calories;
            }
            calories = 0;
            continue;
        }
        calories += std::stoi(line);
    }
    std::cout << maxCalories;

}