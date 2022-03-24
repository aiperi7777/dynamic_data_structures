#include "SetLab_11_Kubanychbekova.h";

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	//Elem* set = create_empty_set();
	//set=add_new_elem(set,5);
	//set= add_new_elem(set, 15);
	//set = add_new_elem(set, 35);
	//set = add_new_elem(set, 12);
	cout << "Множество А" << endl;
	cout << "==================================" << endl;
	Elem* set_a = create_set(6 + rand() % (10 - 6), 10, 99, 3);
	cout << print_set(set_a, " , ") << endl;
//	cout << get_size_of_set(set_a) << endl;
//	set_a=delete_set(set_a);
//	cout << print_set(set_a, " , ") << endl;
//	cout << get_size_of_set(set_a) << endl;
	cout << "==================================" << endl;
	cout << "Множество В" << endl;
	Elem* set_b = create_set(6 + rand() % (10 - 6), 10, 99, 6);
	cout << print_set(set_b, " , ") << endl;
///	cout << get_size_of_set(set_b) << endl;
///	set_b=delete_set(set_b);
//	cout << print_set(set_b, " , ") << endl;
//	cout << get_size_of_set(set_b) << endl;
	
	//===================================================================
	
	cout << "лабораторная работа №2" << endl;
	cout << "Подмножество A и A=" << checkSub(set_a, set_a) << endl;
	cout << "Подмножество A и B="<< checkSub(set_a, set_b) << endl;
	cout << "Равенство двух множеств А-В="<< checkEquals(set_a, set_b) << endl;
	cout << "Объединение двух множеств="<< print_set(mergerOfSets(set_a, set_b), ",") << endl;
	cout << "Пересечение двух множеств="<< print_set(create_with_identical_elemsAB(set_a, set_b), ",") << endl;
	cout << "Разность множеств A и B="<< print_set(create_with_different_elemsAB(set_a, set_b), ",") << endl;
	cout << "Разность множеств B и A=" << print_set(create_with_different_elemsAB(set_b, set_a), ",") << endl;
	cout << "Симметричная разность="<< print_set(create_with_symmetric_difference(set_a, set_b), ",") << endl;
	
	
	return 0;
}