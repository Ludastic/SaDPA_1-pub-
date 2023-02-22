#include <string>
#include <iostream>
#include <ctime>
#include "Struct.h"
#pragma once
#define _STATIC_MAS_H
using namespace std;
struct Static_mas { //��������� ������� �� ����������� �������
	int curr_size = 0, curr_size_theme=0;
	static const int max_size = 100;
	Question mas[max_size];
	int themes[max_size];
	/*void print() {
		for (int i = 0; i < curr_size; i++) {
			cout <<"� "<<i+1<<endl<<
				"����� ����: "<< mas[i].num_theme<< endl <<
				"����� �������: "<< mas[i].text_q<<endl<<endl<<
				"���� �� ���������� �����: " << mas[i].points<<
				endl<<endl<< "�������� �������: "<<endl;
			for (int j = 0; j < mas[i].curr_vars; j++) {
				cout << j + 1 << ") " << mas[i].ans[j] << endl;
			}
			cout << "����� ����������� ������: " << mas[i].num_right << ")" << endl;
		}
	}*/
	void insert(Question& obj) { //������� ���������� ������� � ������� (��� ������������ �������)
		bool newth = true;
		for (int i = 0; i < curr_size_theme; i++) {
			if (obj.num_theme == mas[i].num_theme) {
				newth = false;
			}
		}
		if (newth == true) {
			themes[curr_size_theme] = obj.num_theme;
			curr_size_theme++;
		}
		int aim = 0; 
		for (int i = 0; i < curr_size; i++) {
			if (obj.num_theme < mas[i].num_theme) {
				aim = i; 
				break;
			}
		}
		if (aim == 0) {
			aim = curr_size;
		}
		for (int i = curr_size; i > aim; i--) {
			mas[i] = mas[i - 1];
		}
		mas[aim] = obj;
		curr_size++;
	}
	void delete_theme(int num_t) { //������� �������� ������� �� ����� ����
		for (int i = 0; i < curr_size; i++) {
			if (mas[i].num_theme == num_t) {
				for (int j = i; j < curr_size - 1; j++) {
					mas[j] = mas[j + 1];
				}
				curr_size--;
			}
		}
		for (int i = 0; i < curr_size_theme; i++) {
			if (themes[i] == num_t) {
				for (int j = i; j < curr_size_theme - 1; j++) {
					themes[j] = themes[j + 1];
				}
				curr_size_theme--;
				break;
			}
		}
	}
};
void print(Static_mas& obj) { //������� ������ ���� ������� (�� ���� �������� �������)
	cout << endl << endl << "///////////////���� �������///////////////" << endl << endl;
	for (int i = 0; i < obj.curr_size; i++) {
		cout << "� " << i + 1 << endl <<
			"����� ����: " << obj.mas[i].num_theme << endl <<
			"����� �������: " << obj.mas[i].text_q << endl << endl <<
			"���� �� ���������� �����: " << obj.mas[i].points <<
			endl << endl << "�������� �������: " << endl;
		for (int j = 0; j < obj.mas[i].curr_vars; j++) {
			cout << j + 1 << ") " << obj.mas[i].ans[j] << endl;
		}
		cout << "����� ����������� ������: " << obj.mas[i].num_right << ")" << endl<<endl;
	}
}

void form_test(Static_mas& obj) { //������� ������������ ����� (�� ���� �������� �������)
	srand(time(NULL));
	int *theme_state = new int[obj.curr_size_theme];
	for (int i = 0; i < obj.curr_size_theme; i++) {
		theme_state[i] = 0;
	}
	int num_prints = 0;
	cout << endl << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!TEST!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl << endl;
	while (num_prints<obj.curr_size_theme*2) {
		Question question = obj.mas[rand() % obj.curr_size_theme];
		int num_curr_theme_q;
		for (int i = 0; i < obj.curr_size_theme; i++) {
			if (question.num_theme == obj.themes[i]) {
				num_curr_theme_q = i;
				break;
			}
		}
		if (theme_state[num_curr_theme_q] != 2) {
			print(question);
			theme_state[num_curr_theme_q]++;
			num_prints++;
		}
	}
}