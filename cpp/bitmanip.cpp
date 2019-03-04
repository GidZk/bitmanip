#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#include<vector>
using namespace std;
#define QUESTION_MARK 0x3F
#define MAX_ISTRUCTION_SEQ 100
#define REG_SIZE 32
#define PLACEHOLDER 2
#define MAX_ISTRUCTION_SEQ 100


/*
    My Java solution of this problem did not go as planned, so tried with
    a C++ project I started out with. 

    1. slighly modified AND / OR conditions.

    Let's see if this one passes all tests!
*/

void printAllRegisters(vector<string> reg);
void SET(string& regis, int index );
void CLEAR(string& regis, int index);
void AND(string& regis, int i,int j);
void OR(string& regis, int i,int j);

int main (){ 
    int arg1, arg2;
    string command;
    int nArgs;
    int topIndex = 0;
    vector<string> registers;
    

    while(1){
        std::cin >> nArgs;
        if(nArgs < 1){
            break;
        }
        registers.push_back("????????????????????????????????");
        
        
        for (int j = 0; j < nArgs; j++){
            cin >> command;

            if(!command.compare("SET")){
                 cin >> arg1;
                arg1 = REG_SIZE -arg1 -1;
                SET(registers[topIndex], arg1);             
            }
            if(!command.compare("CLEAR")){
                 cin >> arg1;
                 arg1 = REG_SIZE -arg1 -1;
                CLEAR(registers[topIndex],arg1);
            }
            if(!command.compare("AND")){
                 cin >> arg1;
                 cin >> arg2;

                 arg1 = REG_SIZE -arg1 -1;
                 arg2 = REG_SIZE -arg2 -1;
                AND(registers[topIndex],arg1,arg2);
            }
            if(!command.compare("OR")){
                 cin >> arg1;
                 cin >> arg2;

                 arg1 = REG_SIZE -arg1 -1;
                 arg2 = REG_SIZE -arg2 -1;
                OR(registers[topIndex],arg1,arg2);
            }
        }
        topIndex++;
    }    
    printAllRegisters(registers);
    exit(0);
}
void SET(string& regis, int index ){
    regis[index] = '1';
}
void CLEAR(string& regis, int index){
    regis[index] = '0';
}
void AND(string &regis, int i, int j)
{
    if(regis[i] == '0' || regis[j] =='0'){
        regis[i] = '0';
    }
    else if(regis[i] == '1' && regis[j] =='1'){
        regis[i] = '1';
    }else {
        regis[i] ='?';
    }
}

void OR(string& regis, int i, int j){
    if (regis[i] == '0' && regis[j] == '?'){
        regis[i] = '?';
    }else if(regis[i] == '1' || regis[j] == '1'){
        regis[i] = '1';
    }
}

void printAllRegisters(vector<string> reg){
     for (int i = 0; i < reg.size(); i++ ){
        cout << reg[i] << "\n";
    }
    cout <<"\n";

 
}

