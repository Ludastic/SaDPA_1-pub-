#include <string>
#include <iostream>
#pragma once
#define _STRUCT_H
using namespace std;
struct Question //��������� ������ 
{
	int num_theme{}, points{}, num_right{}, curr_vars{};
	string text_q, ans[10];
};

void inp_for_q(Question& obj) { //���������� �������
	cout << "������� ����� ����: ";
	cin >> obj.num_theme;
	cout << "������� ����� �������: ";
	cin >> obj.text_q;
	cout << "������� ���������� ������ �� ���������� �����: ";
	cin >> obj.points;
	cout << "������� ���������� ��������� ������ (�������� 10): ";
	cin >> obj.curr_vars;
	for (int i = 0; i < obj.curr_vars; i++) {
		cout << "������� ������� ������ �" << i + 1 << ": ";
		string current_ans;
		cin >> current_ans;
		obj.ans[i] = current_ans;
	}
	cout << "������� ����� ����������� ������: ";
	cin >> obj.num_right;
}

void print(Question obj) { //����� ������ �������
		cout <<"����� ����: " << obj.num_theme << endl <<
			"����� �������: " << obj.text_q << endl << endl <<
			"���� �� ���������� �����: " << obj.points <<
			endl << endl << "�������� �������: " << endl;
		for (int j = 0; j < obj.curr_vars; j++) {
			cout << j + 1 << ") " << obj.ans[j] << endl;
		}
		cout << "����� ����������� ������: " << obj.num_right << ")" << endl;
}
