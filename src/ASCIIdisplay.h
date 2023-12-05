#ifndef TEXTDISP
#define TEXTDISP

#include <string>
#include <iostream>
#include <sstream>
#include <vector>

class Model;

class ASCII_Disp {
    Model *m;
    public:
        ASCII_Disp(Model *m);
        ~ASCII_Disp();

        void printBoard();
        void printFieldCard(int player, int fieldpos);
        void printField(int player);
        void printHand(int player);
        void printGraveyard(int player);

        void unlink();
};



#endif