#include "mylib.h"
#include "Failai.h"
int main()
{
	int pasir;
	cout << "Generuoti studentus: 1 \n";
		cout << "Skaityti is failo: 2\n";
		cin >> pasir;
		switch (pasir) {
		case 1: {
			vector<Student> Grupe;
			cout << "Iveskite studentu skaiciu: ";
			int nr;
			cin >> nr;
			Grupe.reserve(nr);
			for (int i = 0; i < nr; i++) {
				Student Laikinas;
				string laik5;
				//cin >> Laikinas;
				Grupe.push_back(Laikinas);
				Laikinas.~Student();
			}
			//sort(Grupe.begin(), Grupe.end(),maziauVid);
			sort(Grupe.begin(), Grupe.end(), std::less<Student>());
			for (auto& duom : Grupe) cout << duom;
			break;
		}
		case 2: {
			vector<Student> Grupe;
			system("dir *.txt");
			cout << "Iveskite failo pavadinima: ";
			string vardas;
			cin >> vardas;
			Data_read(vardas, Grupe);
			sort(Grupe.begin(), Grupe.end());
			std::ofstream out_f("rezultatai.txt");
			for (auto& duom : Grupe) out_f << duom;
			out_f.close();
			break;
		}
		}

	system("pause");
}