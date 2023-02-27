#include <iostream>
#include <unistd.h>
#include <conio.h>

//Goal: create a well formatted checkers game that can be played by clicking interactively, 
//then allow that game to be played by multiple people on a server in the terminal
//Goal: print cells at particular cells on the screen

using namespace std;

struct player {
    bool red;
    int numPieces = 12;
};

//Public to inherit data members
struct board {
    
    static const int dim = 4;
    int dimMod = dim;

    int checkerBoard[8][dim] = {{1,1,1,1}, {1,1,1,1}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {2,2,2,2}, {2,2,2,2}};

    int numRedChecks;
    int numBlueChecks;

    void printBoard(player red, player black) {
        bool alternate = false;
        bool print = true;

        dimMod*=2;

        string boxChar;
        for (int i = 0; i < 6; i++) {
            boxChar += (char) 219;
        }


        while (print) {
            if (!alternate) {
                for (int i = 0; i < 3; i++) {
                    cout<<boxChar<<"      "<<boxChar<<"      "<<
                          boxChar<<"      "<<boxChar<<"      ";
                    cout<<endl;
                }
                alternate = true;
            }
            else {
                for (int i = 0; i < 3; i++) {
                    cout<<"      "<<boxChar<<"      "<<boxChar<<
                          "      "<<boxChar<<"      "<<boxChar;
                    cout<<endl;
                }
                alternate = false;
            }

            if (dimMod <= 1) {
                print = false;
            }

            dimMod--;
        }
    }

};

class play {
  
};

int main() {
    board Start;
    player user1;
    player user2;

    Start.printBoard(user1, user2);
    
    // cout << "Hello, world!\r";
    // cout.flush();
    // sleep(1);
    // cout << "Goodbye, world!\r";
    // cout.flush();
    // sleep(1);


    return 0;
}