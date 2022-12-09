#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>

int main()
{
    std::ifstream inFile;
    inFile.open("input.txt");
    int i = 1, prioSum = 0, counter, n1, n2, n3;
    char prio[52];

    for(char lwalpCh = 'a'; lwalpCh <= 'z'; lwalpCh++)
	{prio[i] = lwalpCh; i++;}
    for(char lwalpCh = 'A'; lwalpCh <= 'Z'; lwalpCh++)
	{prio[i] = lwalpCh; i++;}
    std::vector<char> compartment1, compartment2, compartment3;
    
    START:for(std::string line; std::getline(inFile, line);)
    {
        counter++;
        if (counter%3 == 1){std::copy(line.begin(), line.end(), std::back_inserter(compartment1)); n1 = line.length();}
        if (counter%3 == 2){std::copy(line.begin(), line.end(), std::back_inserter(compartment2)); n2 = line.length();}
        if (counter%3 == 0)
        {
            std::copy(line.begin(), line.end(), std::back_inserter(compartment3)); 
            n3 = line.length();

            for(int x = 0; x<n1 ; x++)
            {
                for(int y = 0; y<n2; y++)
                {
                    for(int z = 0; z<n3; z++)
                    {
                        if(compartment1[x] == compartment2[y] && compartment2[y] == compartment3[z])
                        {
                            for(int in=1; in<53; in++)
                            {
                                if(prio[in] == compartment1[x])
                                {
                                    prioSum += in;
                                    compartment1.clear();
                                    compartment2.clear();
                                    compartment3.clear();
                                    goto START;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    std::cout << prioSum;
}