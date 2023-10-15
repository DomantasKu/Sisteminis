#include "mylib.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

int main() {
    std::vector<Studentas> studentai;

    std::cout << "Pasirinkite: " << std::endl;
    std::cout << "1. Skaityti studentus iš failo" << std::endl;
    std:: cout << "2. Įvesti studentus ranka" << std::endl;
    int pasirinkimas;
    std::cin >> pasirinkimas;

    if (pasirinkimas == 1) {
        std::string failo_pavadinimas;
        std::cout << "Įveskite failo pavadinimą: ";
        std::cin >> failo_pavadinimas;

        std::ifstream inputFile(failo_pavadinimas);

        if (!inputFile.is_open()) {
            std::cerr << "Klaida atidarant failą!" << std::endl;
            return 1;
        }

        std::string line;
        std::getline(inputFile, line); // Praleidžiame antraštę

        while (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            std::string vardas, pavarde;
            int nd1, nd2, nd3, nd4, nd5, egzaminas;

            iss >> vardas >> pavarde >> nd1 >> nd2 >> nd3 >> nd4 >> nd5 >> egzaminas;

            Studentas studentas(vardas, pavarde);
            studentas.PridetiNamuDarba(nd1);
            studentas.PridetiNamuDarba(nd2);
            studentas.PridetiNamuDarba(nd3);
            studentas.PridetiNamuDarba(nd4);
            studentas.PridetiNamuDarba(nd5);
            studentas.PridetiEgzamina(egzaminas);
            studentai.push_back(studentas);
        }

        inputFile.close();
    } else if (pasirinkimas == 2) {
        int studentu_skaicius;
        std::cout << "Įveskite studentų skaičių: ";
        std::cin >> studentu_skaicius;
        for (int i = 0; i < studentu_skaicius; ++i) {
            std::string vardas, pavarde;
            std::cout << "Įveskite studento vardą: ";
            std::cin >> vardas;
            std::cout << "Įveskite studento pavardę: ";
            std::cin >> pavarde;
            Studentas studentas(vardas, pavarde);
            int pazymys;
            while (true) {
                std::cout << "Įveskite namų darbo rezultatą (įveskite -1, kad baigtumėte): ";
                std::cin >> pazymys;
                if (pazymys == -1) {
                    break;
                }
                studentas.PridetiNamuDarba(pazymys);
            }
            std::cout << "Įveskite egzamino rezultatą: ";
            int egzaminas;
            std::cin >> egzaminas;
            studentas.PridetiEgzamina(egzaminas);
            studentai.push_back(studentas);
        }
    } else {
        std::cerr << "Neteisingas pasirinkimas!" << std::endl;
        return 1;
    }

    std::cout << std::left << std::setw(15) << "Pavardė" << std::setw(15)
              << "Vardas" << std::setw(20) << "Galutinis (Vid.)"
              << std::setw(20) << "Galutinis (Med.)" << std::endl;
    std::cout << "----------------------------------------------------------"
              << std::endl;

    for (const Studentas &studentas : studentai) {
        std::cout << std::left << std::setw(15) << studentas.Pavarde()
                  << std::setw(15) << studentas.Vardas() << std::fixed
                  << std::setprecision(2) << std::setw(20)
                  << studentas.Vidurkis() << std::setw(20) << studentas.Mediana()
                  << std::endl;
    }

    return 0;
}
