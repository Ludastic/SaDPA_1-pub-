#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Struct.h"
#pragma once
#define _VEC_H
using namespace std;
bool comp(vector<Question> fst, vector<Question> scnd) { //����������
	return fst[0].num_theme < scnd[0].num_theme;
}
struct Vec { //��������� ������� �� �������
	vector<vector<Question>> vec;
	/*void print() {
		cout << endl << endl << "///////////////���� �������///////////////" << endl << endl;
		for (int i = 0; i < vec.size(); i++) {
			cout << "����� ����: " << vec[i][0].num_theme << endl;
			for (int j = 0; j < vec[i].size(); j++) {
				cout << "������ � " << j + 1 << endl <<
					"����� �������: " << vec[i][j].text_q << endl <<
					"���� �� ���������� �����: " << vec[i][j].points << endl <<
					"�������� �������: " << endl;
				for (int k = 0; k < vec[i][j].curr_vars; k++) {
					cout << k + 1 << ") " << vec[i][j].ans[k] << endl;
				}
				cout << "����� ����������� ������: " << vec[i][j].num_right << endl<<endl;
			}
		}
	}*/
	void insert(Question& obj) { //������� ���������� ������� � ������� (��� ������������ �������)
		int flag = 0;
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i][0].num_theme == obj.num_theme) {
				vec[i].push_back(obj);
				flag = 1;
			}
		}
		if (flag == 0) {
			vector<Question> buff;
			buff.push_back(obj);
			vec.push_back(buff);
		}
		/*bool comp(vector<Question> fst, vector<Question> scnd) {
			return fst[0].num_theme < scnd[0].num_theme;
		}*/
		sort(vec.begin(), vec.end(), comp);
	}
	void delete_theme(int num_t) { //������� �������� ������� �� ����� ����
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i][0].num_theme == num_t) {
				vec.erase(vec.begin() + i);
			}
		}
	}
};

void print(Vec& obj) { //������� ������ ���� ������� (�� ���� �������� �������)
	cout << endl << endl << "///////////////���� �������///////////////" << endl << endl;
	for (int i = 0; i < obj.vec.size(); i++) {
		cout << "����� ����: " << obj.vec[i][0].num_theme << endl;
		for (int j = 0; j < obj.vec[i].size(); j++) {
			cout << "������ � " << j + 1 << endl <<
				"����� �������: " << obj.vec[i][j].text_q << endl <<
				"���� �� ���������� �����: " << obj.vec[i][j].points << endl <<
				"�������� �������: " << endl;
			for (int k = 0; k < obj.vec[i][j].curr_vars; k++) {
				cout << k + 1 << ") " << obj.vec[i][j].ans[k] << endl;
			}
			cout << "����� ����������� ������: " << obj.vec[i][j].num_right << endl << endl;
		}
	}
}

void form_test(Vec& obj) { //������� ������������ ����� (�� ���� �������� �������)
	srand(time(NULL));
	cout << endl << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!TEST!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl << endl;
	for (int i = 0; i < obj.vec.size(); i++) {
		print(obj.vec[i][rand() % obj.vec[i].size()]);
		print(obj.vec[i][rand() % obj.vec[i].size()]);
	}
}

