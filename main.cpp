#include "mylib.h"
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
  std::vector<Studentas> studentai;
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
    studentas.IvestiBalus();

    studentai.push_back(studentas);
  }

  std::cout << std::left << std::setw(15) << "Pavardė" << std::setw(15)
            << "Vardas" << std::setw(20) << "Galutinis (Vid.)" << std::setw(20)
            << "Galutinis (Med.)" << std::endl;
  std::cout << "----------------------------------------------------------"
            << std::endl;

  for (const Studentas &studentas : studentai) {
    std::cout << std::left << std::setw(15) << studentas.Pavarde()
              << std::setw(15) << studentas.Vardas() << std::setw(20)
              << studentas.Vidurkis() << std::setw(20) << studentas.Mediana()
              << std::endl;
  }

  return 0;
}
