#include <iostream>
#include "Pmx.h"
using namespace std;

int main() {
	char path[] = "kizunaai.pmx";
	cout << "hello, world!" << endl;
	pmx::PMX_MODEL model;
	if (model.readModel(path)) {
		wcout << "success" << endl;
	}
	else {
		cout << "fail" << endl;
	}
	cin.get();
	return 0;
}