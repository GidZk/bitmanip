
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include<vector>
using namespace std;
#define EARTH_DAYS 365
#define MARS_DAYS 687

int main (){
int earth, mars;
int nCase = 1;
int nOfDays;
string tmp;
vector<int> output;

    while (cin >> earth && cin >> mars){

        // TODO : how many earth days has passed ? earth is now 0
        mars = abs(mars - earth);
        earth = earth - earth;

        while (1){
            
            mars = mars + EARTH_DAYS;
            mars = mars % MARS_DAYS; 
            if (mars == 0){
           
                output.push_back(nOfDays);
   
                
            }


        }
                


            
        }
    
            cout << "finish \n";
        //cout << input + "\n";

   




    

}


void printAll(vector<string> list){
     for (int i = 0; i < list.size(); i++ ){
        cout << list[i] << "\n";
    }


 
}
