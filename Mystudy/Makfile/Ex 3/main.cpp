#include <iostream>
#include "tool.h"

using namespace std;


int main() {

	int a = 10;
	int b = 20;
	swap1(a, b); // 值传递不会改变实参
    cout << a <<endl;
    cout << b <<endl;
	swap2(&a, &b); //地址传递会改变实参
    cout << a <<endl;
    cout << b <<endl;

	return 0;
}