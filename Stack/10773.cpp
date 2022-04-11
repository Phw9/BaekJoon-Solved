#include <iostream>
#include <string>
using namespace std;
typedef int LData;
#define TRUE 1;
#define FALSE 0;

typedef struct _Node {
	LData data;
	_Node* next;
}Node;

typedef class _LinkedList {
private:
	Node* head;
	Node* cur;
	Node* before;
	int numOfData;
public:
	_LinkedList() : numOfData(0) {
		head = new Node;
		head->next = NULL;
		head->data = -1;
		cur = head;
		before = head;
	}
	~_LinkedList() {
		if (LFirst()) {
			while (1) {
				LRemove();
				if (numOfData == 0)
					break;
			}
		}
		delete head;

	}

	void LInsert(LData data) {
		Node* newnode = new Node;
		newnode->next = head->next;
		head->next = newnode;
		before = head;
		cur = head->next;
		newnode->data = data;
		numOfData++;
	}
	int LFirst() {
		if (head->next == NULL) {
			return FALSE;
		}
		cur = head->next;
		before = head;
		return TRUE;
	}
	int LNext() {
		if (cur->next == NULL) {
			return FALSE;
		}
		before = cur;
		cur = cur->next;
		return TRUE;
	}
	LData LRemove() {
		if (numOfData == 0) {
			return 0;
		}
		Node* rnode = new Node;
		LData rdata;
		rnode = cur;
		rdata = rnode->data;
		cur = cur->next;
		before->next = cur;
		delete rnode;
		numOfData--;
		return rdata;
	}
	int LCount() {
		return numOfData;
	}
	void Showdata() {
		LFirst();
		for (int i = 0; i < numOfData; i++) {
			cout << cur->data << " ";
			LNext();
		}
	}
	LData Showtop() {
		if (LFirst()) {
			return cur->data;
		}
		return -1;
	}
}List;

typedef enum _command { push, pop, size, empty, top }command;

std::istream& operator>>(std::istream& is, _command& cmd)
{
	std::string name;
	is >> name;

	if (name == "push")
		cmd = _command::push;
	else if (name == "pop")
		cmd = _command::pop;
	else if (name == "size")
		cmd = _command::size;
	else if (name == "empty")
		cmd = _command::empty;
	else if (name == "top")
		cmd = _command::top;

	return is;
}




int main(void) {
	int cmd_num = 0;
	int num;
	List plist;
	LData input;
	while (cmd_num < 1 || cmd_num>100000) {
		cin >> cmd_num;
	}
	int i = 0;
	int j = 0;
	int sum = 0;
	int* output = new int[cmd_num];

	while (i < cmd_num) {
		num = -1;
		while(num<0||num>1000000)
			cin >> num;

		if (num == 0) {
			output[j] = plist.LRemove();
			j++;
		}
		else {
			plist.LInsert(num);
		}
		i++;
	}
	int times = plist.LCount();
	for (int k = 0; k < times; k++) {
		sum += plist.LRemove();
	}
	cout << sum << endl;
	return 0;
}