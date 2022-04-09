#include <iostream>
using namespace std;

typedef class _order {
private:
	int weight;
	int height;
	int rank;
public:
	_order() : weight(0), height(0), rank(1) {}
	_order(const int (&w), const int (&h)) : weight(w), height(h), rank(1) {}

	void inputdata(const int& w, const int& h) {
		weight = w;
		height = h;
	}
	void Showrank() {
		cout << rank << " ";
	}
	void rankup() {
		rank ++;
	}
	void comp(_order s) {
		if (weight < s.weight) {
			if (height < s.height) {
				rank++;
			}
		}
	}
}order;



int main(void) {

	
	int num = 0;
	int x = 0, y = 0;
	while (num < 2 || num>50) {
		cin >> num;
	}
	order* arr = new order[num];

	for (int i = 0; i < num; i++) {
		while ((x, y) < 10 || (x, y)>200) {
			cin >> x; cin >> y;
		}
		arr[i].inputdata(x, y);
		x = 0; y = 0;
	}

	for (int j = 0; j < num; j++) {
		for (int k = j+1; k < num; k++) {
			arr[j].comp(arr[k]);
			arr[k].comp(arr[j]);
			}
	}
	for (int i = 0; i < num; i++) {
		arr[i].Showrank();
	}
	
	delete[] arr;

	return 0;
}