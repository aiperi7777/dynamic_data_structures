#include "SetLab_11_Kubanychbekova.h";

int rand_val(int a, int b) {
	if (a > 0) return a + rand() % (b - a);
	else return a + rand() % (abs(a) + b);
}

Elem* create_empty_set() {
	//cout << "created empty set" << endl;
	Elem* set = nullptr;
	return set;
};
bool is_empty_set(Elem* ptr) {
	//cout << "is empty set=" << (ptr == nullptr) << endl;
	return ptr == nullptr;
};
bool is_belongs(Elem* ptr, int value) {
	Elem* tmp = ptr;
	bool res = false;
	if (is_empty_set(tmp)) {
		//cout << "is belongs? - set is empty" << endl;
		return false;
	}
	while (tmp->next) {
		if (tmp->value == value) {
			res = true;
			//cout << "is belongs" << endl;
			break;
		}
		else
			tmp = tmp->next;
	}
	return res;
};

Elem* add_new_elem(Elem* ptr, int new_elem) {
	if (is_belongs(ptr, new_elem)) {
		//cout << "cant add bcs is belongs" << endl;
		return ptr;
	}
	else {
		Elem* tmp = new Elem;
		tmp->value = new_elem;
		tmp->next = ptr;
		ptr = tmp; 
		///cout << "new elem was added= " << new_elem << endl;
	}
	return ptr;
};

Elem* create_set(int size, int min, int max,int k) {
	Elem* set = create_empty_set();
	while (size >0) {
		int value = rand_val(min, max);
		//cout << "rand value=" << value << endl;
		if (value % k == 0&& !is_belongs(set,value)) {
			set =add_new_elem(set, value);
			size--;
			//cout << "creating and add elem now=" << value << endl;
		}
	};
	return set;
}

int get_size_of_set(Elem* ptr) {
	int size = 0;
	Elem* tmp = ptr;
	if (is_empty_set(ptr)) {
		cout << "size=";
		return 0;
	}
	while (tmp->next) {
		tmp = tmp->next;
		size++;
	}
	size++;
	cout << "size=";
	return size;
};


Elem* delete_set(Elem* ptr) {
	Elem* tmp = ptr;
	if (is_empty_set(ptr)) {
		//cout << "can't delete bcs is empty" << endl;;
		return ptr;
	}
	else {
		while (ptr->next) {
			tmp = ptr;
			ptr = ptr->next;
			delete tmp;
		}
	}
	ptr = nullptr;
	cout << "deleted" << endl;;
	return ptr;
};

string print_set(Elem* ptr, string delim) {
	if (is_empty_set(ptr)) return "EMPTY";
	Elem* tmp = ptr;
	string res;
	while (tmp->next) {
		res += to_string(tmp->value) + delim;
		tmp = tmp->next;
	}
	res += to_string(tmp->value);
	return res;

}