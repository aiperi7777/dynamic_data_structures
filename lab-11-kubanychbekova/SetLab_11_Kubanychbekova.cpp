#include "SetLab_11_Kubanychbekova.h";

int rand_val(int a, int b) {
	if (a > 0) return a + rand() % (b - a);
	else return a + rand() % (abs(a) + b);
}

Elem* create_empty_set() {
	return nullptr;
};
bool is_empty_set(Elem* ptr) {
	return ptr == nullptr;
};
bool is_belongs(Elem* ptr, int value) {
	Elem* tmp = ptr;
	bool res = false;
	if (is_empty_set(tmp)) {
		return false;
	}
	while (tmp->next) {
		if (tmp->value == value) {
			res = true;
			break;
		}
		else
			tmp = tmp->next;
	}
	return res;
};

Elem* add_new_elem(Elem* ptr, int new_elem) {
	if (!is_belongs(ptr, new_elem)) {
		Elem* tmp = new Elem;
		tmp->value = new_elem;
		tmp->next = ptr;
		ptr = tmp;
	}
	return ptr;
};

Elem* create_set(int size, int min, int max, int k) {
	Elem* set = create_empty_set();
	while (size > 0) {
		int value = rand_val(min, max);
		if (value % k == 0 && !is_belongs(set, value)) {
			set = add_new_elem(set, value);
			size--;
		}
	};
	return set;
}

int get_size_of_set(Elem* ptr) {
	int size = 0;
	Elem* tmp = ptr;
	if (is_empty_set(ptr)) {
		return 0;
	}
	while (tmp->next) {
		tmp = tmp->next;
		size++;
	}
	size++;
	return size;
};


Elem* delete_set(Elem* ptr) {
	Elem* tmp = ptr;
		while (ptr->next) {
			tmp = ptr;
			ptr = ptr->next;
			delete tmp;
		}
	ptr = nullptr;
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
//2 лабораторная работа 
bool checkSub(Elem* main, Elem* sub) {
	Elem* tmp1 = main;
	if (get_size_of_set(main) < get_size_of_set(sub)) return false;
	while (tmp1 != nullptr) {
		if (!is_belongs( sub, tmp1->value)) {
			return false;
		}
		else {
			tmp1 = tmp1->next;
		}
	}
	return true;
}
bool checkEquals(Elem* main, Elem* sub) {
	return checkSub(main, sub) && (get_size_of_set(main) == get_size_of_set(sub));
}
Elem* mergerOfSets(Elem* A, Elem* B) {
	Elem* tmp = B;
	Elem* newSet = A;
	if (!is_empty_set(A) && !is_empty_set(B)) {
		while (tmp != nullptr) {
			if (!is_belongs(newSet, tmp->value)) {
				newSet = add_new_elem(newSet, tmp->value);
			}
			tmp = tmp->next;
		}
	}
	return newSet;
}
Elem* create_with_identical_elemsAB(Elem* A, Elem* B) {
	if (is_empty_set(A) || is_empty_set(B)) return create_empty_set();
	Elem* tmp1 = A;
	Elem* newSet = create_empty_set();
	while (tmp1->next) {
		if (is_belongs(B, tmp1->value)) {
			newSet = add_new_elem(newSet, tmp1->value);
		}
		tmp1 = tmp1->next;
	}
	if (is_belongs(B, tmp1->value)) {
		newSet = add_new_elem(newSet, tmp1->value);
	}
	return newSet;
}
Elem* create_with_different_elemsAB(Elem* A, Elem* B) {
	Elem* newSet = create_empty_set();
	if (is_empty_set(A)) {
		return newSet;
	}
	if (is_empty_set(B)) {
		return A;
	}
	Elem* tmp1 = A;
	while (tmp1->next) {
		if (!is_belongs(B, tmp1->value)) {
			newSet = add_new_elem(newSet, tmp1->value);
		}
		tmp1 = tmp1->next;
	}
	if (!is_belongs(B, tmp1->value)) {
		newSet = add_new_elem(newSet, tmp1->value);
	}
	return newSet;
}
Elem* create_with_symmetric_difference(Elem* A, Elem* B) {
	return create_with_different_elemsAB(mergerOfSets(A, B), create_with_identical_elemsAB(A, B));
}




/*
Elem* mergerOfSets(Elem* A, Elem* B) {
	Elem* tmp1 = A;
	Elem* tmp2 = B;
	Elem* newSet = create_empty_set();
	if (!is_empty_set(A) && !is_empty_set(B)) {
		while (tmp1->next && tmp2->next) {
			if (!is_belongs(newSet, tmp1->value)) {
				newSet = add_new_elem(newSet, tmp1->value);
			}
			if (!is_belongs(newSet, tmp2->value)) {
				newSet = add_new_elem(newSet, tmp2->value);
			}
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
		if (!is_belongs(newSet, tmp1->value)) {
			newSet = add_new_elem(newSet, tmp1->value);
		}
		if (!is_belongs(newSet, tmp2->value)) {
			newSet = add_new_elem(newSet, tmp2->value);
		}
	}
	return newSet;
}
*/