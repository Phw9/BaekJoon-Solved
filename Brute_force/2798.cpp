#include <iostream>
using namespace std;

int blackjack_sum(int arr[], int num, int max) {
	int sum = 0, temp;
	for (int i = 0; i < num; i++) {
		for (int j = i + 1; j < num; j++) {
			for (int k = j + 1; k < num; k++) {
				temp = arr[i] + arr[j] + arr[k];
				if (temp <= max && temp > sum)
					sum = temp;
			}
		}
	}
	return sum;
}

int main(void) {
	int num = 0, sum = 0, temp = 0, max = 0;

	while (3 > num || num > 100, 10 > max || max > 300000) {
		cin >> num; cin >> max;
	}

	int* arr = new int[num];

	for (int i = 0; i < num; i++) {
		cin >> arr[i];
		if (arr[i] < 1 || arr[i]>100000)
			continue;
	}
	cout << blackjack_sum(arr, num, max);

	delete[]arr;
	return 0;
}