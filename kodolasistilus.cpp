// Google C++ Style Guide szerint átalakított kód
// Forrás: https://google.github.io/styleguide/cppguide.html
//
// Főbb változások:
// - #define makrók eltávolítva (Google: kerülendő)
// - Egybetűs változó- és függvénynevek kibővítve (olvashatóság)
// - Struktúra átnevezve és tagjai snake_case-re hozva
// - Minden változó deklaráció a használat helyére kerül (nem a blokk elejére)
// - using namespace std; eltávolítva (Google: tiltott fejléc fájlban, kerülendő)
// - Kapcsos zárójelek minden vezérlési szerkezetnél (Kernighan & Ritchie stílus)
// - Függvénynevek leíró nevekre cserélve
// - Konstans referencia paraméterek ahol lehetséges

#include <iostream>

// Struktúra: két egész szám tárolása
// Google: struktúra neve CamelCase, tagok snake_case
struct Pair {
  int first;
  int second;
};

// Buborékrendezés a 'first' mező szerint
// Google: függvény neve CamelCase, paraméterek snake_case
void BubbleSort(Pair* data, int length) {
  for (int i = 0; i < length; ++i) {
    for (int j = 0; j < length - 1; ++j) {
      if (data[j].first > data[j + 1].first) {
        // Csere: mindkét mező felcserélése
        int temp_first = data[j].first;
        data[j].first = data[j + 1].first;
        data[j + 1].first = temp_first;

        int temp_second = data[j].second;
        data[j].second = data[j + 1].second;
        data[j + 1].second = temp_second;
      }
    }
  }
}

// Elválasztó vonalak kiírása
// Google: rövid, egy feladatot végző függvények rendben vannak
void PrintSeparatorDouble() {
  std::cout << "===" << std::endl;
}

void PrintSeparatorSingle() {
  std::cout << "---" << std::endl;
}

void PrintOutputLabel() {
  std::cout << "Output:" << std::endl;
}

// Kiszámítja és kiírja az eredményeket a párok alapján:
// - ha mindkét mező páros: szorzat
// - ha first páros, second páratlan: összeg
// - ha first páratlan, second páros: különbség
// - ha mindkét mező páratlan: first értéke
void ComputeAndPrint(const Pair* pairs, int size) {
  for (int i = 0; i < size; ++i) {
    int first = pairs[i].first;
    int second = pairs[i].second;
    int result = 0;

    if (first % 2 == 0) {
      if (second % 2 == 0) {
        result = first * second;
      } else {
        result = first + second;
      }
    } else {
      if (second % 2 == 0) {
        result = first - second;
      } else {
        result = first;
      }
    }

    std::cout << result << std::endl;
  }
}

// Rendezés, majd eredmények megjelenítése
void SortAndDisplay(Pair* data, int length) {
  BubbleSort(data, length);
  PrintSeparatorDouble();
  PrintOutputLabel();
  PrintSeparatorSingle();
  ComputeAndPrint(data, length);
}

int main() {
  // Google: tömbök helyett std::array vagy std::vector ajánlott,
  // de a feladat struktúráját megtartjuk
  Pair pairs[5];
  pairs[0] = {5, 1};
  pairs[1] = {2, 4};
  pairs[2] = {3, 7};
  pairs[3] = {1, 6};
  pairs[4] = {4, 5};

  SortAndDisplay(pairs, 5);

  return 0;
}
