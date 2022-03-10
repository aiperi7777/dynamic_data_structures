#include <string>
#include <cstdlib>
#include <iostream>
#include <ctime>
#pragma once
using namespace std;

struct Elem {
	int value;
	Elem* next;
};

Elem* create_empty_set();
bool is_empty_set(Elem*);
bool is_belongs(Elem*, int value);
Elem* add_new_elem(Elem*, int new_elem);
//Elem* create_set(int size, int min, int max);
Elem* create_set(int size, int min, int max,int k);
int get_size_of_set(Elem*A) ;
Elem* delete_set(Elem*A);
string print_set(Elem*A,string delim)  ;
int rand_val(int a, int b) ;