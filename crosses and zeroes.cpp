using namespace std;
#include <iostream>
void output(char** arr, int n) {
	
	for (int i = 0; i < n; i++) {
		cout << "|";
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << "|";
		}
		cout << endl;
	
	}
}
void nichuia(char** arr, int n, int& p) {
	int a = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != ' ') {
				a++;
			}
		}
	}
	if (a == 9) {
		cout << "nichuya\n";
		p = 1;
	}

}
void call(char** arr, int n, int& p) {
	if (arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2] && arr[0][1]!=' ') {				//1 1 1 (переша лінія)
		cout << arr[0][0] << " WON \n";	
		p = 1;
	}																			
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1] != ' ') {					//(навхрест зліва вправо)
		cout << arr[0][0] << " WON \n";
		p = 1;
	}
	if (arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0] && arr[1][0] != ' ') {				//(перший стовпичк
		cout << arr[0][0] << " WON \n";
		p = 1;
	}
	if (arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2] && arr[1][0] != ' ') {				//друга лінія
		cout << arr[2][1] << " WON \n";
		p = 1;
	}
	if (arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2] && arr[2][0] != ' ') {				//третя лінія
		cout << arr[2][1] << " WON \n";
		p = 1;
	}
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] != ' ') {				// навхрест
		cout << arr[1][1] << " WON \n";
		p = 1;
	}
	if (arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1] && arr[0][1] != ' ') {				// другий стопвчик
		cout << arr[1][1] << " WON \n";
		p = 1;
	}
	if (arr[0][2] == arr[1][2] && arr[1][2] == arr[2][2] && arr[0][2] != ' ') {
		cout << arr[1][2] << " WON \n";
		p = 1;
	}
}

int main()
{
	int n = 3;
	start:
	char** arr = new char* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new char[n];
		for (int j = 0; j < n; j++) {
			arr[i][j] = ' ';
		}
	}
	output(arr, n);
	int p = 0;
	do {
		int w, w1;
		bool h = true;
		do {
			cout << "Input \"x\"" << endl;
			cin >> w >> w1;
			h = true;
			if ((w > 3 || w1 > 3) || (arr[w-1][w1-1] != ' ') ) {
				cout << "Input again\n";
				h = false;
			}
			else {
				arr[w-1][w1-1] = 'x';
			}
		} while (h == false);
		output(arr, n);
		call(arr, n, p);
		nichuia(arr, n, p);

		if (p == 1) {
			cout << "Want paly again? 1 - yes, 0 - no\n";
			int p;
			cin >> p;
			if (p == 1) {
				goto start;
			}
			else {
				return 0;
			}
		}
	
		do {
			cout << "Input \"0\"" << endl;
			cin >> w >> w1;
			h = true;
			if ((w > 3 || w1 > 3) || (arr[w-1][w1-1] != ' ')  ) {
				cout << "Input again\n";
				h = false;
			}
			else {
				arr[w-1][w1-1] = '0';
			}
		} while (h == false);
		output(arr, n);
		call(arr, n, p);
		nichuia(arr, n, p);
		if (p == 1) {
			cout << "Want paly again? 1 - yes, 0 - no\n";
			int p;
			cin >> p;
			if (p == 1) {
				goto start;
			}
			else {
				return 0;
			}
		}

	} while (p!=1);
}
