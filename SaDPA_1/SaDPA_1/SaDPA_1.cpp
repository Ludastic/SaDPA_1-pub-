#include <iostream>
#include "Dynamic_mas.h"
#include "Static_mas.h"
#include "Vec.h"
#include "Struct.h"
#include <string>
using namespace std;
int input_static(Static_mas& obj) {
	while (1 == 1) {
		Question newq;
		inp_for_q(newq);
		cout << "Что вы хотите сделать с данным вопросом:\n" << endl << "СОЗДАННЫЙ ВОПРОС: "<<endl;
		print(newq);
		cout << endl << "1. Записать в таблицу.\n2. Перезаписать вопрос по новой.\n"<<"Выберите опцию: ";
		int inp;
		cin >> inp;
		if (inp == 1) {
			obj.insert(newq);
			print(obj);
			return 0;
		}
	}
}
int menu_static(Static_mas& obj) {
	while (1 == 1) {
		cout << "1. Создать новый вопрос и добавить его в таблицу.\n" <<
			"2. Сформировать тест, состоящий из двух вопросов по каждой теме.\n" <<
			"3. Удалить вопросы по одной теме.\n" <<
			"4. Вывести всю таблицу.\n" <<
			"5. Выйти из режима взаимодействия с таблицей.\n";
		cout << "Что вы хотите сделать с таблицей: ";
		int input;
		cin >> input;
		switch (input)
		{
		case 1:
			input_static(obj);
			break;
		case 2:
			form_test(obj);
			break;
		case 3:
			cout << "Введите номер темы для удаления(при вводе несуществующей темы - ничего не изменится): ";
			int num_del;
			cin >> num_del;
			obj.delete_q(num_del);
			print(obj);
			break;
		case 4:
			print(obj);
			break;
		case 5: 
			cout << endl << "ЗАВЕРШЕНИЕ РАБОТЫ С ТАБЛИЦЕЙ"<<endl;
			return 0;
		default:
			break;
		}
	}
}
///////////
int input_dynamic(Dynamic_mas& obj) {
	while (1 == 1) {
		Question newq;
		inp_for_q(newq);
		cout << "Что вы хотите сделать с данным вопросом:\n" << endl << "СОЗДАННЫЙ ВОПРОС: " << endl;
		print(newq);
		cout << endl << "1. Записать в таблицу.\n2. Перезаписать вопрос по новой.\n" << "Выберите опцию: ";
		int inp;
		cin >> inp;
		if (inp == 1) {
			obj.insert(newq);
			obj.print();
			return 0;
		}
	}
}

int menu_dynamic(Dynamic_mas& obj) {
	while (1 == 1) {
		cout << "1. Создать новый вопрос и добавить его в таблицу.\n" <<
			"2. Сформировать тест, состоящий из двух вопросов по каждой теме.\n" <<
			"3. Удалить вопросы по одной теме.\n" <<
			"4. Вывести всю таблицу.\n" <<
			"5. Выйти из режима взаимодействия с таблицей.\n";
		cout << "Что вы хотите сделать с таблицей: ";
		int input;
		cin >> input;
		switch (input)
		{
		case 1:
			input_dynamic(obj);
			break;
		case 2:
			form_test(obj);
			break;
		case 3:
			cout << "Введите номер темы для удаления(при вводе несуществующей темы - ничего не изменится): ";
			int num_del;
			cin >> num_del;
			obj.delete_q(num_del);
			obj.print();
			break;
		case 4:
			obj.print();
			break;
		case 5:
			cout << endl << "ЗАВЕРШЕНИЕ РАБОТЫ С ТАБЛИЦЕЙ"<<endl;
			return 0;
		default:
			break;
		}
	}
}
///////////

int input_vec(Vec& obj) {
	while (1 == 1) {
		Question newq;
		inp_for_q(newq);
		cout << "Что вы хотите сделать с данным вопросом:\n" << endl << "СОЗДАННЫЙ ВОПРОС: " << endl;
		print(newq);
		cout << endl << "1. Записать в таблицу.\n2. Перезаписать вопрос по новой.\n" << "Выберите опцию: ";
		int inp;
		cin >> inp;
		if (inp == 1) {
			obj.insert(newq);
			obj.print();
			return 0;
		}
	}
}

int menu_vec(Vec& obj) {
	while (1 == 1) {
		cout << "1. Создать новый вопрос и добавить его в таблицу.\n" <<
			"2. Сформировать тест, состоящий из двух вопросов по каждой теме.\n" <<
			"3. Удалить вопросы по одной теме.\n" <<
			"4. Вывести всю таблицу.\n" <<
			"5. Выйти из режима взаимодействия с таблицей.\n";
		cout << "Что вы хотите сделать с таблицей: ";
		int input;
		cin >> input;
		switch (input)
		{
		case 1:
			input_vec(obj);
			break;
		case 2:
			form_test(obj);
			break;
		case 3:
			cout << "Введите номер темы для удаления(при вводе несуществующей темы - ничего не изменится): ";
			int num_del;
			cin >> num_del;
			obj.delete_q(num_del);
			obj.print();
			break;
		case 4:
			obj.print();
			break;
		case 5:
			cout << endl << "ЗАВЕРШЕНИЕ РАБОТЫ С ТАБЛИЦЕЙ"<<endl;
			return 0;
		default:
			break;
		}
	}
}

int menu() {
	while (1 == 1) {
		cout << "1. Работа с таблицей на основе статического массива.\n" <<
			"2. Работа с таблицей на основе динамического массива.\n" <<
			"3. Работа с таблицей на основе вектора. \n" <<
			"4. Завершение работы\n" <<
			"Какой способ работы с таблицей выбираете? (введите соотв. цифру): ";
		int input;
		cin >> input;
		if (input == 1) {
			Static_mas obj;
			menu_static(obj);
		}
		else if (input == 2) {
			Dynamic_mas obj;
			menu_dynamic(obj);
		}
		else if (input == 3) {
			Vec obj;
			menu_vec(obj);
		}
		else if (input == 4) {
			cout << endl << "КОНЕЦ РАБОТЫ!";
			return 0;
		}
		else {
			cout << endl << "НЕКОРРЕКТНЫЙ ВВОД!" << endl;
		}
	}
}
int main() {
	setlocale(LC_ALL, "Russian");
	menu();
}