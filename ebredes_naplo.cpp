#include <iostream>
#include <string>
#include <vector>
#include <sstream>

struct Bejegyzes {
    std::string datum;
    std::string fekves;
    std::string ebreds;
    int alvasPerc;
    std::string megjegyzes;
};

int percKulonbseg(const std::string& tol, const std::string& ig) {
    int h1, m1, h2, m2;
    char c;
    std::istringstream(tol) >> h1 >> c >> m1;
    std::istringstream(ig)  >> h2 >> c >> m2;
    int percTol = h1 * 60 + m1;
    int percIg  = h2 * 60 + m2;
    if (percIg < percTol) percIg += 24 * 60;
    return percIg - percTol;
}

void bejegyzesKiir(const Bejegyzes& b) {
    std::cout << "  Dátum:      " << b.datum << "\n";
    std::cout << "  Lefekvés:   " << b.fekves << "\n";
    std::cout << "  Ébredés:    " << b.ebreds << "\n";
    std::cout << "  Alvás:      " << b.alvasPerc / 60 << " óra "
                                  << b.alvasPerc % 60 << " perc\n";
    std::cout << "  Megjegyzés: " << b.megjegyzes << "\n";
    std::cout << "  ---\n";
}

int main() {
    std::vector<Bejegyzes> lista;

    std::cout << "=== Ébredési Napló ===\n\n";

    int valasztas;
    while (true) {
        std::cout << "1 - Új bejegyzés\n";
        std::cout << "2 - Bejegyzések listázása\n";
        std::cout << "0 - Kilépés\n";
        std::cout << "Választás: ";
        std::cin >> valasztas;
        std::cin.ignore();

        if (valasztas == 0) {
            std::cout << "Viszlát!\n";
            break;
        }

        if (valasztas == 1) {
            Bejegyzes b;

            std::cout << "Dátum (pl. 2025-04-20): ";
            std::getline(std::cin, b.datum);

            std::cout << "Lefekvés (pl. 23:30): ";
            std::getline(std::cin, b.fekves);

            std::cout << "Ébredés (pl. 07:15): ";
            std::getline(std::cin, b.ebreds);

            b.alvasPerc = percKulonbseg(b.fekves, b.ebreds);

            std::cout << "Megjegyzés: ";
            std::getline(std::cin, b.megjegyzes);

            lista.push_back(b);
            std::cout << "Aludtál: " << b.alvasPerc / 60 << " óra "
                      << b.alvasPerc % 60 << " percet.\n\n";
        }

        if (valasztas == 2) {
            if (lista.empty()) {
                std::cout << "Még nincs bejegyzés.\n\n";
            } else {
                std::cout << "\n--- Bejegyzések ---\n";
                for (const auto& b : lista) bejegyzesKiir(b);
                std::cout << "\n";
            }
        }
    }

    return 0;
}
