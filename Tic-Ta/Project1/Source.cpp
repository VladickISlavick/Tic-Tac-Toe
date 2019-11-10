#include <iostream>
#include <string>
#include <exception>
#include <limits>
using namespace std;

float a;

int main() {
	while (true) {
		cin >> a;

		if (cin.good()) {
			cout << "GOoD";
		}
		else {
			cout << "NO";
		}
		
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		//_flushall();
	}
}