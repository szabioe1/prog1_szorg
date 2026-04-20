#include <iostream>
#include <vector>
#include <cstdlib>

int main() {
    const size_t chunk = 64 * 1024 * 1024;
    std::vector<char*> blocks;

    std::cout << "Memória foglalás kezdődik..." << std::endl;

    while (true) {
        char* p = (char*)malloc(chunk);
        if (!p) break;

        for (size_t i = 0; i < chunk; i += 4096) {
            p[i] = 1;
        }

        blocks.push_back(p);
        std::cout << blocks.size() * 64 << " MB foglalva" << std::endl;
    }

    std::cout << "Memória tele. Összesen: " << blocks.size() * 64 << " MB" << std::endl;

    std::cin.get();

    for (char* b : blocks) free(b);
    return 0;
}
