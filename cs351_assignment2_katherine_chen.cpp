// ConsoleApplication1.cpp : Simple Command Line Interpreter.
// Copyright (c) Katherine Chen 9/23/2022
//had to use the command below in order to compile code just in case it doesnt work 
//use cmd to compile: g++ -std=c++11 cs351_assignment2_katherine_chen.cpp -o outputFile.out
//then: ./outputFile.out to execute!
#include <iostream>
#include <string> 
#include <stdlib.h> //system()
#include <cstring>  //strtok()
#include <thread> //thread

void sysCall(int size, std::string* arr) {
    char argg[100];
    std::string cmd = ""; 
    for (int k=0; k < size; k++) {
        cmd = cmd + arr[k] + " ";
    }
    strcpy(argg, cmd.c_str());
    system(argg); 
    return;
}

int main() { 
    char preStok[100];
    char arg[100];
    std::string argument[4]; 
    char* returnVal; 

    int i=0;
     
    std::cout << "Welcome to myShell!\n"; 

    while(1) {
        std::cout << "==> "; 
        std::cin.getline(preStok,100);  
        
        returnVal = strtok(preStok, " ");
       
        while (returnVal) {
            argument[i] = returnVal; 
            returnVal = strtok(NULL," ");
            i++;
        }
        if (i > 1) {
            std::thread first(sysCall, i, argument);
            first.join();
            i=0;
        }
        else {
            if (argument[0] == "exit") {
                    break;
            }
            strcpy(arg, argument[0].c_str());
            system(arg); 
            i=0;
        }
    }
    
    std::cout << "Thanks for using myShell!" << std::endl;
    return 0;
}
