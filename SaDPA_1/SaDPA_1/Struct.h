#include <string>
#include <iostream>
#pragma once
#define _STRUCT_H
using namespace std;
struct Question //структура записи 
{
	int num_theme{}, points{}, num_right{}, curr_vars{};
	string text_q, ans[10];
};

void inp_for_q(Question& obj) { //заполнение вопроса
	cout << "Введите номер темы: ";
	cin >> obj.num_theme;
	cout << "Введите текст вопроса: ";
	cin >> obj.text_q;
	cout << "Введите количество баллов за правильный ответ: ";
	cin >> obj.points;
	cout << "Введите количество вариантов ответа (максимум 10): ";
	cin >> obj.curr_vars;
	for (int i = 0; i < obj.curr_vars; i++) {
		cout << "Введите вариант ответа №" << i + 1 << ": ";
		string current_ans;
		cin >> current_ans;
		obj.ans[i] = current_ans;
	}
	cout << "Введите номер правильного ответа: ";
	cin >> obj.num_right;
}

void print(Question obj) { //вывод одного вопроса
		cout <<"Номер темы: " << obj.num_theme << endl <<
			"Текст вопроса: " << obj.text_q << endl << endl <<
			"Балл за правильный ответ: " << obj.points <<
			endl << endl << "Варианты ответов: " << endl;
		for (int j = 0; j < obj.curr_vars; j++) {
			cout << j + 1 << ") " << obj.ans[j] << endl;
		}
		cout << "Номер правильного ответа: " << obj.num_right << ")" << endl;
}
