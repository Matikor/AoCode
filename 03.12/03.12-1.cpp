#include <iostream>
#include <fstream>
#include <cstring>
#include <typeinfo>

int main()
{
    std::ifstream inFile;
    inFile.open("input.txt");
    char prio[52];
    int i = 1, n, prioSum = 0, counter = 0;

    for(char lwalpCh = 'a'; lwalpCh <= 'z'; lwalpCh++)
	{prio[i] = lwalpCh; i++;}
    for(char lwalpCh = 'A'; lwalpCh <= 'Z'; lwalpCh++)
	{prio[i] = lwalpCh; i++;}
    
    START:for(std::string line; std::getline(inFile, line);)
    {
        n = line.length();
        char array[n], compartment1[n/2], compartment2[n/2];
        strcpy(array, line.c_str());
        
        for (int x = 0; x < n/2; x++)
        {
        compartment1[x] = array[x];
        compartment2[x] = array[x+n/2];
        }
        
        for(int x = 0; x < n/2; x++)
        {
            for(int y = 0; y < n/2; y++)
            {
                if(compartment1[x] == compartment2[y])
                {
                    for(int z=1; z<53; z++)
                    {
                        if(prio[z] == compartment1[x])
                        {
                            prioSum += z;
                            counter++;
                            goto START;
                        }
                    }
                } 
            }
        }
    }
    std::cout << counter << std::endl;
    std::cout << prioSum;
}