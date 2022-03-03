#include "SetLab_11_Kubanychbekova.h";

int main() {
	setlocale(LC_ALL, "Russian");
	//Elem* set = create_empty_set();
	//set=add_new_elem(set,5);
	//set= add_new_elem(set, 15);
	//set = add_new_elem(set, 35);
	//set = add_new_elem(set, 12);
	cout << "Множество А" << endl;
	cout << "==================================" << endl;
	Elem* set_a= create_set_for_3(10,10,99);
	cout << print_set(set_a, " , ") << endl;
	cout << get_size_of_set(set_a) << endl;
	set_a=delete_set(set_a);
	cout << print_set(set_a, " , ") << endl;
	cout << get_size_of_set(set_a) << endl;
	cout << "==================================" << endl;
	cout << "Множество В" << endl;
	Elem* set_b = create_set_for_6(10, 10, 99);
	cout << print_set(set_b, " , ") << endl;
	cout << get_size_of_set(set_b) << endl;
	set_b=delete_set(set_b);
	cout << print_set(set_b, " , ") << endl;
	cout << get_size_of_set(set_b) << endl;

	
	return 0;
}