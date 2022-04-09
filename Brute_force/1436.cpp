#include <iostream>
#include <string>
using namespace std;


int main(void) {
	int N = 0;
	int i = 0;
	while (N < 1 || N>10000) {
		cin >> N;
	}
	int* arr = new int[N];
	string comp;
	string six = to_string(6);


	for (int j = 666;; j++) {
		comp = to_string(j);

		for (int k = 0; k < comp.length()-2; k++) {
			if (comp[k] == six[0] && comp[k + 1] == six[0] && comp[k + 2] == six[0]) {
				arr[i++] = stoi(comp);
				break;
			}
		}
		if (i == N) {
			cout << arr[N - 1];
			break;
		}
	}

	return 0;
}