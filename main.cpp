#include "mylib.h"
#include "Failai.h"
#include <chrono>

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    int pasir;
    std::cout << "Generuoti studentus: 1 \n";
    std::cout << "Skaityti is failo: 2\n";
    std::cin >> pasir;

    switch (pasir) {
    case 1: {
        auto fileCreationStart = std::chrono::high_resolution_clock::now();

        vector<Student> Grupe;
        std::cout << "Iveskite studentu skaiciu: ";
        int nr;
        std::cin >> nr;
        Grupe.reserve(nr);
        for (int i = 0; i < nr; i++) {
            Student Laikinas;
            std::string laik5;
            Grupe.push_back(Laikinas);
            Laikinas.~Student(); // Consider removing this line
        }
        std::sort(Grupe.begin(), Grupe.end(), std::less<Student>());
        for (auto& duom : Grupe) std::cout << duom;

        auto fileCreationEnd = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> fileCreationTime = fileCreationEnd - fileCreationStart;
        std::cout << "Failo kurimo laikas: " << fileCreationTime.count() << " seconds" << std::endl;

        // Sorting students into two categories
        auto sortingStart = std::chrono::high_resolution_clock::now();
        std::vector<Student> vargsiukai;
        std::vector<Student> kietiakiai;

        for (auto& duom : Grupe) {
            if (duom.GetRez() < 5.0) {
                vargsiukai.push_back(duom);
            }
            else {
                kietiakiai.push_back(duom);
            }
        }

        std::ofstream vargsiukaiFile("vargsiukai.txt");
        for (const auto& student : vargsiukai) {
            vargsiukaiFile << student;
        }
        vargsiukaiFile.close();

        std::ofstream kietiakiaiFile("kietiakiai.txt");
        for (const auto& student : kietiakiai) {
            kietiakiaiFile << student;
        }
        kietiakiaiFile.close();

        std::ofstream out_f("rezultatai.txt");
        for (auto& duom : Grupe) {
            out_f << duom;
        }
        out_f.close();

        auto sortingEnd = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> sortingTime = sortingEnd - sortingStart;
        std::cout << "Rusiavimo laikas: " << sortingTime.count() << " seconds" << std::endl;

        break;
    }
    case 2: {
        auto dataReadingStart = std::chrono::high_resolution_clock::now();

        vector<Student> Grupe;
        system("dir *.txt");
        std::cout << "Iveskite failo pavadinima: ";
        std::string vardas;
        std::cin >> vardas;
        Data_read(vardas, Grupe);
        std::sort(Grupe.begin(), Grupe.end());

        auto dataReadingEnd = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> dataReadingTime = dataReadingEnd - dataReadingStart;
        std::cout << "Duomenu nuskaitymo laikas: " << dataReadingTime.count() << " seconds" << std::endl;

        std::ofstream out_f("rezultatai.txt");
        for (auto& duom : Grupe) out_f << duom;
        out_f.close();
        break;
    }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> totalTime = end - start;
    std::cout << "Visas programos veikimo laikas: " << totalTime.count() << " seconds" << std::endl;

    return 0;
}
