#include <stdio.h>
#include <iostream>

#define REG_SIZE 32

void printRegisters(char** reg, int limit, int regSize);
void setup(char** reg, int nOfRegs, int regSize);

int main () { 
    
    int nOfTests;
    int nOfArgs;
    std::cin >> nOfTests;
    char** registers = new char* [nOfTests]; 

    setup(registers, nOfTests,REG_SIZE);


    
    printRegisters(registers,nOfTests,REG_SIZE);
    exit(0);

    
}

void setup(char** reg, int nOfRegs, int regSize){

    for (int i = 0; i < nOfRegs; i++){
        reg[i] = new char[regSize];

        for (int j = 0; j < regSize; j++){
            reg[i][j] = -1;
        }
    }
}



void printRegisters(char** reg, int limit, int regSize){

printf ("--------Registers---------- \n ");
    for (int i = 0; i < limit; i++ ){
        printf("register %d : ", i+1 );
        for (int j = 0; j < regSize; j ++){
            printf("%d",reg[i][j]);
        }

        printf("\n");

    }
    printf("derefered : %d \n", **reg);
    printf("reg[0][0] %d: \n", reg[0][0]);
    printf("adress: %x \n", reg[0]);
}
