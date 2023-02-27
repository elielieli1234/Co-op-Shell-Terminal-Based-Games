#include <iostream>
#include <unistd.h>

using namespace std;

void drawAtXYCell(int x, int y) {
    string a(7, (char)219);

    for (int j = 4 + (3 * (y - 1)); j < 4 + (3 * (y - 1)) + 3; j++) {
        cout << "\x1b[" << j /*y*/ << ";" << 1 + (x-1) * 7 /*x*/ << "H";
        cout<<a;
    }
    
    cout << "\x1b[" << 30 /*y*/ << ";" << 1 /*x*/ << "H"; 
}

void pendingAnimation(int x, int y) {
    string a(7, (char)219);

    for (int j = 4 + (3 * (y - 1)); j < 4 + (3 * (y - 1)) + 3; j++) {
        cout << "\x1b[" << j /*y*/ << ";" << 1 + (x-1) * 7 /*x*/ << "H";
        cout<<a;
    }
    
    cout << "\x1b[" << 30 /*y*/ << ";" << 1 /*x*/ << "H"; 
}

int main() {
    while (1) {
        for (int i = 0; i <= 255; i++) {
            std::cout << "\033[38;2;" << i << ";0;0mFading in...\033[0m" << std::endl;
            usleep((100000/23));
        }
        for (int i = 255; i >= 0; i--) {
            std::cout << "\033[38;2;" << i << ";0;0mFading out...\033[0m" << std::endl;
            usleep((100000/23));
        }
    }

    return 0;
}