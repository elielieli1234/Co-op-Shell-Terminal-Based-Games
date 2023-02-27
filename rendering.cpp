#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

void drawBlack(int x, int y) {
    char aChar[] = {'\033', '[', '1', ';', '3', '0', 'm', '#', '\033', '[', '0', 'm'};    
    string b(aChar, sizeof(aChar) / sizeof(aChar[0]));

    string a, a1;
    for (int i = 0; i < 7; i++) {
        (7 - i) >= 6 || (7 - i) <= 2 ? a += (char)219 : a += b;
        a1 += b;
    }

    bool  alt = true;
    for (int i = 0; i < 3; i++) {
        cout << "\x1b[" << 4 + (3 * (y - 1)) + i /*y*/ << ";" << 1 + (x-1) * 7 /*x*/ << "H";
        alt ? cout<<a : cout<<a1;
        alt = !alt;
    }

    cout << "\x1b[" << 30 /*y*/ << ";" << 1 /*x*/ << "H"; 
}

void drawRed(int x, int y) {
    char aChar[] = {'\033', '[', '1', ';', '3', '1', 'm', '#', '\033', '[', '0', 'm'};    
    string b(aChar, sizeof(aChar) / sizeof(aChar[0]));

    string a, a1;
    for (int i = 0; i < 7; i++) {
        (7 - i) >= 6 || (7 - i) <= 2 ? a += (char)219 : a += b;
        a1 += b;
    }

    bool  alt = true;
    for (int i = 0; i < 3; i++) {
        cout << "\x1b[" << 4 + (3 * (y - 1)) + i /*y*/ << ";" << 1 + (x-1) * 7 /*x*/ << "H";
        alt ? cout<<a : cout<<a1;
        alt = !alt;
    }

    cout << "\x1b[" << 30 /*y*/ << ";" << 1 /*x*/ << "H"; 

}

void drawAtXYCell(int x, int y) {
    string a(7, (char)219);

    for (int j = 4 + (3 * (y - 1)); j < 4 + (3 * (y - 1)) + 3; j++) {
        cout << "\x1b[" << j /*y*/ << ";" << 1 + (x-1) * 7 /*x*/ << "H";
        cout<<a;
    }
    
    cout << "\x1b[" << 30 /*y*/ << ";" << 1 /*x*/ << "H"; 
}

void drawBlankBoard() {
    bool odd = true;
    int y = 1;
    for (int i = 0; i < 8; i++) {
        int x = odd ? 1 : 2;
        for (int j = 0; j < 4; j++) {
            drawAtXYCell(x, y);
            x+=2;
        }

        y++;
        
        odd = !odd;
    }
}

void pendingAnimation(int x, int y) {
}

void gameLoop() {
    char ch;

    while (1) {
        drawBlankBoard(); //draw blank
        drawBlack(2,4); //draw at xy
        drawRed(3,1); 
        ch = getch(); //take input continually
        if (ch == 'w' || ch == 'a' || ch == 's' || ch == 'd') {
            cout << "\x1b[" << 15 /*y*/ << ";" << 100 /*x*/ << "H";
            printf("You pressed %c\n", ch);

        }
        else if (ch == 'q') {
            break;
        }

        cout << "\x1b[" << 2 /*y*/ << ";" << 1 /*x*/ << "H"; //move cursor back to top left

    }
}

int main() {

    //string a(7, (char)219);

    //gameLoop();

    char a[] = "testing test 1 2";

    //"changing" opacity

    std::cout << "\x1b[41m";

    //write semi-transparent text
    std::cout << "\x1b[30;40;5mHello, world!\x1b[0m\n";

    return 0;
}