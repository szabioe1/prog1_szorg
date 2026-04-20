#include <iostream>
#include <thread>
#include <vector>

void burn() {
    while (true) {}
}

int main() {
    unsigned int n = std::thread::hardware_concurrency();
    std::cout << "CPU magok: " << n << std::endl;

    std::vector<std::thread> threads;
    for (unsigned int i = 0; i < n; i++) {
        threads.emplace_back(burn);
    }

    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
