#include <iostream>
#include <chrono>
#include <thread>

const int SZELES = 40;
const int MAGAS  = 20;

void kurzorRejtve()  { std::cout << "\033[?25l"; }
void kurzorLathato() { std::cout << "\033[?25h"; }
void kepernyoTorol() { std::cout << "\033[2J";   }
void kurzorMozgat(int x, int y) {
    std::cout << "\033[" << y << ";" << x << "H";
}

void keretRajzol() {
    kurzorMozgat(1, 1);
    std::cout << "+";
    for (int i = 0; i < SZELES; i++) std::cout << "-";
    std::cout << "+";

    kurzorMozgat(1, MAGAS + 2);
    std::cout << "+";
    for (int i = 0; i < SZELES; i++) std::cout << "-";
    std::cout << "+";

    for (int y = 2; y <= MAGAS + 1; y++) {
        kurzorMozgat(1, y);
        std::cout << "|";
        kurzorMozgat(SZELES + 2, y);
        std::cout << "|";
    }
}

int main() {
    kurzorRejtve();
    kepernyoTorol();
    keretRajzol();

    double x  = SZELES / 2.0;
    double y  = MAGAS  / 2.0;
    double dx = 1.0;
    double dy = 0.5;

    while (true) {
        kurzorMozgat((int)x + 2, (int)y + 2);
        std::cout << " ";

        x += dx;
        y += dy;

        if (x <= 0)      { x = 0;      dx = -dx; }
        if (x >= SZELES) { x = SZELES; dx = -dx; }
        if (y <= 0)      { y = 0;      dy = -dy; }
        if (y >= MAGAS)  { y = MAGAS;  dy = -dy; }

        kurzorMozgat((int)x + 2, (int)y + 2);
        std::cout << "\033[1;32mO\033[0m" << std::flush;

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    kurzorLathato();
    return 0;
}
