#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector<int> vec;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}

	for (int j = 0; j < m; j++) {
		int num;
		cin >> num;
		cout << vec[num - 1] << endl;
	}

	return 0;
}


