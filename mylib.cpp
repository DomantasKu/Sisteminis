#include "mylib.h"
#include <algorithm>
#include <iostream>
#include <numeric>

Studentas::Studentas(const std::string &vardas, const std::string &pavarde)
    : vardas_(vardas), pavarde_(pavarde) {}

void Studentas::IvestiBalus() {
    int pazymys;
    int namu_darbu_sk = 0;

    std::cout << "Įveskite kiek pažymių norite įvesti: ";
    std::cin >> namu_darbu_sk;

    std::cout << "Įveskite " << namu_darbu_sk << " pažymius: ";

    for (int i = 0; i < namu_darbu_sk; ++i) {
        std::cin >> pazymys;
        namu_darbai_.push_back(pazymys);
    }

    std::cout << "Įveskite egzamino rezultatą: ";
    std::cin >> egzaminas_;
}

double Studentas::Vidurkis() const {
    if (namu_darbai_.empty())
        return 0.6 * egzaminas_;
    double vidurkis =
        std::accumulate(namu_darbai_.begin(), namu_darbai_.end(), 0.0) /
        namu_darbai_.size();
    return 0.4 * vidurkis + 0.6 * egzaminas_;
}

double Studentas::Mediana() const {
    if (namu_darbai_.empty())
        return 0.6 * egzaminas_;
    std::vector<int> pazymiai = namu_darbai_;
    std::sort(pazymiai.begin(), pazymiai.end());
    int n = pazymiai.size();
    return n % 2 == 0 ? 0.4 * (0.5 * (pazymiai[n / 2 - 1] + pazymiai[n / 2])) +
                            0.6 * egzaminas_
                      : 0.4 * pazymiai[n / 2] + 0.6 * egzaminas_;
}

const std::string &Studentas::Vardas() const { return vardas_; }

const std::string &Studentas::Pavarde() const { return pavarde_; }
