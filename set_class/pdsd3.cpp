#include "SetLab.h";
//using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	cout << "Множество А" << endl;
	cout << "==================================" << endl;
	Set set_a(6 + rand() % (10 - 6), 10, 99, 3);
	cout << set_a.print_set(" , ") << endl;
	cout << "Мощность множества А: " << set_a.get_size() << endl;

	cout << "==================================" << endl;
	cout << "Множество B" << endl;
	cout << "==================================" << endl;
	Set  set_b(6 + rand() % (10 - 6), 10, 99, 6);
	cout << set_b.print_set(" , ") << endl;
	cout << "Мощность множества B: " << set_b.get_size() << endl;

	cout << "Подмножество A и A: " << set_a.check_sub(set_a) << endl;
	cout << "Подмножество A и B: " << set_b.check_sub(set_a) << endl;
	cout << "Равенство двух множеств А В: " << set_a.equals(set_b) << endl;
	cout << "Равенство двух множеств А A: " << set_a.equals(set_a) << endl;
	Set MergeSet = set_a.merge(set_b);
	cout << "Объединение двух множеств: " << MergeSet.print_set(",") << endl;
	Set IdenticalSet = set_a.identical_elemsAB(set_b);
	cout << "Пересечение двух множеств: " << IdenticalSet.print_set( ",") << endl;
	Set DifferentSetAB = set_a.different_elemsAB(set_b);
	cout << "Разность множеств A и B: " << DifferentSetAB.print_set( ",") << endl;
	Set DifferentSetBA=set_b.different_elemsAB(set_a);
	cout << "Разность множеств B и A: " << DifferentSetBA.print_set(",") << endl;
	Set SymmDiffSet = set_a.symmetric_difference(set_b);
	cout << "Симметричная разность: " << SymmDiffSet.print_set(",") << endl;


	cout << "Удаление А: " << endl;
	set_a.deleteSet();
	cout << "Мощность множества А: " << set_a.get_size() << endl;
	cout << "Удаление B: " << endl;
	set_b.deleteSet();
	cout << "Мощность множества B: " << set_b.get_size() << endl;

}
