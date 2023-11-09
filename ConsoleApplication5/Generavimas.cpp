#include "mylib.h"
struct Studentas {
    std::string vardas;
    std::string pavarde;
    std::vector<int> nd;
    int egzaminas;
};

void GenerateStudents() {
    int studentuSkaicius;

    std::cout << "Iveskite norima studentu skaiciu: ";
    std::cin >> studentuSkaicius;

    std::vector<Studentas> studentai;
    studentai.reserve(studentuSkaicius);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> ndVerte(1, 10);
    std::uniform_int_distribution<> egzaminas(1, 10);

    for (int i = 0; i < studentuSkaicius; ++i) {
        Studentas naujasStudentas;
        naujasStudentas.vardas = "Vardas" + std::to_string(i + 1);
        naujasStudentas.pavarde = "Pavarde" + std::to_string(i + 1);

        naujasStudentas.nd.reserve(15);
        for (int j = 0; j < 15; ++j) {
            naujasStudentas.nd.push_back(ndVerte(gen));
        }

        naujasStudentas.egzaminas = egzaminas(gen);
        studentai.push_back(naujasStudentas);
    }

    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();

    std::ofstream failas("GeneruotiStudentai.txt");
    if (failas.is_open()) {
        failas << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde";
        for (int i = 1; i <= 15; ++i) {
            failas << std::setw(5) << "ND" + std::to_string(i);
        }
        failas << std::setw(7) << "Egz." << std::endl;

        for (const auto& studentas : studentai) {
            failas << std::left << std::setw(20) << studentas.vardas << std::setw(20) << studentas.pavarde;
            for (const auto& nd : studentas.nd) {
                failas << std::setw(5) << nd;
            }
            failas << std::setw(7) << studentas.egzaminas << std::endl;
        }
        failas.close();

        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        std::cout << "Failo kurimo laikas: " << diff.count() << " seconds\n";
        
    }
    else {
        std::cerr << "Nepavyko sukurti failo\n";
    }
}