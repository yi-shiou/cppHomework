#include <iostream>
//call by pointer
void set1(int *a) {
	*a = 1;
}
//call by referance
void set2(int& a) {
	a = 2;
}
void set3(int *a) {
	*a = 2;
}
int main() {
	int a = 5;
	//call by pointer
	set1(&a);
	std::cout << a << "\n";
	//call by referance ***only for c++
	set2(a);
	std::cout << a << "\n";

	//------//
	int *b;
	int c = 10;
	b = &c;

	set3(b);
	std::cout << *b;
	return 0;
}
