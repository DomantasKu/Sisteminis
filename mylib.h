#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <chrono>
#include <random>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::mt19937;
using std::sort;

using hrClock = std::chrono::high_resolution_clock;
typedef std::uniform_int_distribution<int> int_distribution;
int minimum(int a, int b);

class Student {
	string Name, Surname;
	vector <int> HW;
	int Exam;
	float Rez;
public:
	Student();
	Student(string N, string S, vector <int> H, int E);
	Student(const Student& A);
	Student& operator=(const Student& A);
	~Student();
	float Vid();
	float Med();
	void Rezult(char pas);
	//setters
	inline void SetName(string N) { Name = N; }
	inline void SetSurname(string S) { Surname = S; };
	inline void SetHW(vector <int> Vec) { HW = Vec; };
	inline void SetExam(int n) { Exam = n; };
	//getters
	float GetRez() const { return Rez; };
	string GetVard() const { return Name; };
	//kitos
	void printas();
	friend std::ostream& operator<<(std::ostream& out, const Student& A);
	friend std::istream& operator>>(std::istream& in,  Student& A);
	//bool operator<(const Student& B);

};

bool maziauVid(const Student& A, const Student& B);
bool maziauVard(const Student& A, const Student& B);
bool operator<(const Student& A, const Student& B);