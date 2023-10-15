// mylib.h
#include <string>
#include <vector>

class Studentas {
public:
    Studentas(const std::string &vardas, const std::string &pavarde);
    void PridetiNamuDarba(int pazymys);
    void PridetiEgzamina(int pazymys);
    double Vidurkis() const;
    double Mediana() const;
    const std::string &Vardas() const;
    const std::string &Pavarde() const;

private:
    std::string vardas_;
    std::string pavarde_;
    std::vector<int> namu_darbai_;
    int egzaminas_;
};
