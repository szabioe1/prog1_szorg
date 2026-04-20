#include <iostream>
#include <string>

std::string xorTitkosit(const std::string& szoveg, const std::string& kulcs) {
    std::string eredmeny = szoveg;
    for (size_t i = 0; i < szoveg.size(); i++) {
        eredmeny[i] = szoveg[i] ^ kulcs[i % kulcs.size()];
    }
    return eredmeny;
}

int main() {
    std::cout << "=== EXOR Titkosító ===\n\n";
    std::cout << "1 - Szöveg titkosítása\n";
    std::cout << "2 - Titkosított szöveg visszafejtése\n";
    std::cout << "0 - Kilépés\n\n";

    std::string titkositott = "";

    int valasztas;
    while (true) {
        std::cout << "Választás: ";
        std::cin >> valasztas;
        std::cin.ignore();

        if (valasztas == 0) break;

        if (valasztas == 1) {
            std::string szoveg, kulcs;

            std::cout << "Titkosítandó szöveg: ";
            std::getline(std::cin, szoveg);

            std::cout << "Kulcs: ";
            std::getline(std::cin, kulcs);

            if (kulcs.empty()) {
                std::cout << "A kulcs nem lehet üres!\n\n";
                continue;
            }

            titkositott = xorTitkosit(szoveg, kulcs);

            std::cout << "Titkosított (bájtonként): ";
            for (unsigned char ch : titkositott)
                std::cout << (int)ch << " ";
            std::cout << "\n\n";
        }

        if (valasztas == 2) {
            if (titkositott.empty()) {
                std::cout << "Még nincs titkosított szöveg!\n\n";
                continue;
            }

            std::string kulcs;
            std::cout << "Kulcs a visszafejtéshez: ";
            std::getline(std::cin, kulcs);

            std::string vissza = xorTitkosit(titkositott, kulcs);
            std::cout << "Visszafejtett szöveg: " << vissza << "\n\n";
        }
    }

    return 0;
}
