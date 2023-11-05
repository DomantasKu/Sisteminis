#include "mylib.h"
int minimum(int a, int b) { return a < b ? a : b; }
Student::Student() {
	mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
	int_distribution dist(0, 9);
	string vardai[10] = { "Irma","Alma","Irena","Egle","Jolanta","Petras","Jonas","Ignas","Darius","Simas" };
	string pavardes_m[10] = { "Pavardaite1", "Pavardaite2", "Pavardaite3", "Pavardaite4", "Pavardaite5", "Pavardaite6", "Pavardaite7", "Pavardaite8", "Pavardaite9", "Pavardaite10" };
	string pavardes_v[10] = { "Pavardenis1", "Pavardenis2", "Pavardenis3", "Pavardenis4", "Pavardenis5", "Pavardenis6", "Pavardenis7", "Pavardenis8", "Pavardenis9", "Pavardenis10" };
	Name = vardai[dist(mt)];
	switch (*Name.rbegin()) {
	case 's':
		Surname = pavardes_v[dist(mt)];
		break;
	default:
		Surname = pavardes_m[dist(mt)];
		break;
	};
	for (int i = 0; i < 5;i++) {
		HW.push_back(dist(mt) + 1);
	}
	Exam = dist(mt) + 1;
	Rezult('v');
}
Student::Student(string N, string S, vector <int> H, int E) {
	Name = N; Surname = S;
	HW = H;
	Exam = E;
	Rezult('v');
}
Student::Student(const Student& A) {
	Name = A.Name; Surname = A.Surname;
	HW = A.HW;
	Exam = A.Exam;
	Rez = A.Rez;
}
Student& Student::operator=(const Student& A) {
	if (this == &A) return *this;
	Name = A.Name; Surname = A.Surname;
	HW = A.HW;
	Exam = A.Exam;
	Rez = A.Rez;
	return *this;
}
Student::~Student() {
	Name.clear();
	Surname.clear();
	HW.clear();
	Exam = 0;
	Rez = 0;
}
float Student::Vid() {
	return std::accumulate(HW.begin(), HW.end(), 0.0) / HW.size() * 1.0;
}
float Student::Med() {
	std::sort(HW.begin(), HW.end());
	int n = HW.size() / 2;
	return
		(n % 2 == 1) ? HW[n] / 1.0 : (HW[n] + HW[n + 1]) / 2.0;
}
void Student::Rezult(char pas) {
	if (pas == 'v') { Rez = 0.4 * Vid() + 0.6 * Exam; }
	else { Rez = 0.4 * Med() + 0.6 * Exam; }
}
void Student::printas() {
	cout << Name << " ; " << Surname << " | ";
	for (auto& i : HW) cout << i << " | ";
	cout << Exam << " | ";
	cout << " Rezultatas = " << Rez << endl;
}
//bool Student::operator<(const Student& B)
//{
//	return this->Rez < B.GetRez();
//}
std::ostream& operator<<(std::ostream& out, const Student& A) {
	out << A.Name << " ; " << A.Surname << " | ";
	for (auto& i : A.HW) out << i << " | ";
	out << A.Exam << " | ";
	out << " Rezultatas = " << A.Rez << endl;
	return out;
}
std::istream& operator>>(std::istream& in, Student& a) {
	in >> a.Name;
	in >> a.Surname;
	a.HW.clear();
	for (int i = 0; i < 5; i++) {
		int k;
		in >> k; a.HW.push_back(k);
	}
	in >> a.Exam;
	a.Rezult('v');
	return in;
}

bool maziauVid(const Student& A, const Student& B)
{
	
	return A.GetRez()<B.GetRez();
}

bool maziauVard(const Student& A, const Student& B)
{
	return A.GetVard()<B.GetVard();
}
bool operator<(const Student &A, const Student& B)
{
	return A.GetRez() < B.GetRez();
}