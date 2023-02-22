#include <string>
#include <iostream>
#include <ctime>
#include "Struct.h"
#pragma once
#define _DYNAMIC_MAS_H
using namespace std;
struct Dynamic_mas {
	int curr_size = 0, curr_size_theme = 0;
	Question** mas = new Question*[0];
	int* size_themes = new int[0];
	void print() {
		cout << endl << endl << "///////////////ВАША ТАБЛИЦА///////////////" << endl << endl;
		for (int i = 0; i < curr_size; i++) {
			cout << "Номер темы: " << mas[i][0].num_theme << endl;
			for (int j = 0; j < size_themes[i]; j++) {
				cout << "Вопрос № " << j + 1 << endl <<
					"Текст вопроса: " << mas[i][j].text_q << endl <<
					"Балл за правильный ответ: " << mas[i][j].points << endl <<
					"Варианты ответов: " << endl;
				for (int k = 0; k < mas[i][j].curr_vars; k++) {
					cout << k + 1 << ") " << mas[i][j].ans[k] << endl;
				}
				cout << "Номер правильного ответа: " << mas[i][j].num_right << endl<<endl;
			}
		}
	}
	void insert(Question& obj) {
		int aim = 0;
		bool IsNew = true;
		for (int i = 0; i < curr_size; i++) {
			if (obj.num_theme <= mas[i][0].num_theme) {
				aim = i;
				if (obj.num_theme == mas[i][0].num_theme) {
					IsNew = false;
				}
				break;
			}
		}
		if (IsNew) {
			Question** new_mas = new Question * [curr_size + 1];
			for (int i = 0; i < aim; i++) {
				memcpy(new_mas[i], mas[i], size_themes[i] * sizeof(Question));
			}
			new_mas[aim] = new Question[1];
			new_mas[aim][0] = obj;
			for (int i = aim; i < curr_size; i++) {
				memcpy(new_mas[i + 1], mas[i], size_themes[i] * sizeof(Question));
			}
			for (int i = 0; i < curr_size; i++) {
				delete[] mas[i];
			}
			delete[] mas;
			mas = new_mas;
			curr_size++;
			int* new_size_themes = new int[curr_size_theme++];
			for (int i = 0; i < aim; i++) {
				new_size_themes[i] = size_themes[i];
			}
			new_size_themes[aim] = 1;
			for (int i = aim; i < curr_size_theme; i++) {
				new_size_themes[i + 1] = size_themes[i];
			}
			delete[] size_themes;
			size_themes = new_size_themes;
			curr_size_theme++;
		}
		else {
			Question* sub_mas = new Question[size_themes[aim]+1];
			for (int i = 0; i < size_themes[aim]; i++) {
				sub_mas[i] = mas[aim][i];
			}
			sub_mas[size_themes[aim]] = obj;
			delete[] mas[aim];
			mas[aim] = sub_mas;
			curr_size_theme++;
		}
	}
	void delete_q(int num_t) {
		for (int i = 0; i < curr_size; i++) {
			if (mas[i][0].num_theme == num_t) {
				Question** new_mas = new Question * [curr_size - 1];
				for (int j = 0; j < i; j++) {
					new_mas[j] = mas[j];
				}
				for (int j = i + 1; j < curr_size; j++) {
					new_mas[j - 1] = mas[j];
				}
				for (int j = 0; j < curr_size; j++) {
					delete[] mas[i];
				}
				mas = new_mas;
				curr_size--;
				break;
			}
		}
	}
};

void form_test(Dynamic_mas& obj) {
	srand(time(NULL));
	cout << endl << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!TEST!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl << endl;
	for (int i = 0; i < obj.curr_size; i++) {
		print(obj.mas[i][rand() % obj.size_themes[i]]);
		print(obj.mas[i][rand() % obj.size_themes[i]]);
	}
}
