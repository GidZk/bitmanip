
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;
#define EARTH_DAYS 365
#define MARS_DAYS 687

void printAll(vector<int> list);

int main()
{
    int earth, mars, nOfDays, testCase;

    vector<int> output;

    while (cin >> earth && cin >> mars)
    {
        nOfDays = 0;
        nOfDays = EARTH_DAYS - earth;

        if (earth == 0 && mars == 0)
        {
            output.push_back(0);
        }
        else
        {
            
            mars = mars + nOfDays;
            mars %= MARS_DAYS;

            while (1)
            {
                if (mars == 0)
                {
                    output.push_back(nOfDays);
                    break;
                }
                mars += EARTH_DAYS;
                mars %= MARS_DAYS;
                nOfDays += EARTH_DAYS;
            }
        }
    }

    printAll(output);
}

void printAll(vector<int> list)
{
    std::stringstream output;

    for (int i = 1; i <= list.size(); i++)
    {
        output << "Case " << i << ": " << list.at(i-1) << endl;
       
    }
     cout << output.str();
}
