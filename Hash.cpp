#include "Hash.h"
Hash::Hash() {
	arr = new List<string>[401];
	size = 401;
	for (int i = 0; i < 401; i++) {
		arr[i].addAtFirstLocation(to_string(i));
	}
	/*count = 0;
	val = 0;
	key = 0;*/
}
Hash::Hash(int s) {
	arr = new List<string>[s];
	size = s;
	for (int i = 0; i < size; i++) {
		arr[i].addAtFirstLocation(to_string(i));
	}	//count = 0;
	//val = 0;
	//key = 0;
}
void Hash::add(int x, string name) {
	int sum = x;
	int val = sum % size;
	for (int k = 0; k < size; k++) {
		if (val == k) {
			arr[k].add(name);
		}
		//for (int i = 0; i < size; i++) {
		//	while (count != 100) {
		//		//for (int j = 0; j < 500; j++) {
		//		int x = rand() % 1000;
		//		int n = 7 % x;
		//		for (int k = 0; k < 7; k++) {
		//			if (n == k) {
		//				//cout << arr + k << endl;
		//				Node* node;
		//				node->setData(x);

		//				count++;
		//			}
		//		}
		//	}
		//}
		//int count = 0;

	}
}
void Hash::print(){
	for (int k = 0; k < size; k++) {
		cout << k << endl;
		arr[k].displayList();
		cout << endl;
	}
	}

int Hash::search(string) {
	return 0;
	}