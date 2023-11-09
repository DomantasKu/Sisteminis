#include "Failai.h"

void Data_read(string FailoVardas, vector<Student>& Grupe)
{
	std::ifstream open_f(FailoVardas);
	string NuskEil;
	std::getline(open_f, NuskEil);
	while (open_f) {
		if (!open_f.eof()) {
			std::getline(open_f, NuskEil);
			std::stringstream my_buffer(NuskEil);
			Student Temp;
			string TEil;
			my_buffer >> TEil; Temp.SetName(TEil);
			my_buffer >> TEil; Temp.SetSurname(TEil);
			vector <int> LaikPaz;
			int t;
			while (my_buffer >> t) {
				if (t >= 0 && t < 11) LaikPaz.push_back(t);
				else std::cerr << "Pazymis sugadintas\n";
			}
			if (LaikPaz.empty()) std::cerr << "Studentas neturi iverciu\n";
			else {
				Temp.SetExam(LaikPaz.back());
				LaikPaz.pop_back();
				Temp.SetHW(LaikPaz);
				Temp.Rezult('v');
				Grupe.push_back(Temp);
			}
			LaikPaz.clear();
			Temp.SetHW(LaikPaz);
		}
		else break;
	}
	open_f.close();
}
