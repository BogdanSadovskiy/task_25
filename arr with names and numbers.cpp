
using namespace std;
#include <iostream>
struct anketa {
	string name;
	int num;
};
void addacc(anketa*& arr, int& size) {			//adding func
	anketa* arr2 = new anketa[size+1];
	for (int i = 0; i < size; i++) {
		arr2[i].name = arr[i].name;
		arr2[i].num = arr[i].num;
	}
	size++;
	cout << "Input name  ";
	cin >> arr2[size -1].name;
	cout << "Input tel number  ";
	cin >> arr2[size - 1].num;
		
	delete[] arr;
	arr = arr2;
	cout << "Great\nYou added a new account\n";

}
void viewacc(anketa* arr, int size) {
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << "-----------------------\n";
		cout << "Account # " << i+1 << endl;
		cout << arr[i].name << endl;
		cout << arr[i].num << endl;
		cout << "-----------------------\n";
		cout << endl;
	}
}
void search(anketa* arr, int size) {					//searching func
	cout << "Want to search by number? - input 1\n";
	cout << "Want to search by name? - input 2\n";
	int q;
	int num;
	string name;
	do {
		cin >> q;
		if (q < 1 || q>2) {
			cout << "Input correctly\n";
		}
	} while (q < 1 || q>2);
	for (int i = 0; i< size; i++){
		if (i == 0) {
			if (q == 1) {
				cout << "Input number\n";
				cin >> num;
			}
			else if (q == 2) {
				cout << "Input name\n";
				cin >> name;
			}
		}
		if (q == 1) {
			if (arr[i].num == num) {
				cout << "Found by " << i+1 << " account\n";
				cout << arr[i].name << endl;
				cout << arr[i].num << endl;
			}
			else {
				cout << "Not found\n";
			}
		}
		if (q == 2) {
			if (arr[i].name == name) {
				cout << "Found by " << i+1 << " account\n";
				cout << arr[i].name << endl;
				cout << arr[i].num << endl;
			}
			else {
				cout << "Not found\n";
			}
		}
	}
	}
void change(anketa* arr, int size) {
	int q;
	int acc;
	start:
	cout << "What account do you want to change? (you have " << size << " acc)\n";
	cout << "View accounts before changing date (input 0)\n";
	do {
		cin >> q;
		if (q < 0 || q> size) {
			cout << "Input correctly\n";
		}
	} while (q < 0 || q> size);
	if (q == 0) {
		viewacc(arr, size);
		goto start;
	}
	else {
		acc = q;
		cout << "-----------------------\n";
		cout << "Chosen acc is :\n";
		cout << arr[acc - 1].name << endl;
		cout << arr[acc - 1].num << endl;
		cout << "-----------------------\n\n";
		cout << "What do you want to change\n";
		cout << "Name - press 1; Number - press 2\n";
		do {
			cin >> q;
			if (q < 1 || q> 2) {
				cout << "Input correctly\n";
			}
		} while (q < 1 || q> 2);
		if (q == 1) {
			cout << "Input new name  ";
			cin >> arr[acc - 1].name;
		}
		if (q == 2) {
			cout << "Input new number  ";
			cin >> arr[acc - 1].num;
		}
		cout << "-----------------------\n";
		cout << "Chosen acc is now :\n";
		cout << arr[acc - 1].name << endl;
		cout << arr[acc - 1].num << endl;
		cout << "-----------------------\n\n";
	}
}
	
int main()
{
	int size = 0;
	anketa* arr = new anketa[size];
start:
	cout << "-----------------------\n";
	cout << "Add account (input 1)\n";
	cout << "Search account (input 2)\n";
	cout << "Change account (input 3)\n";
	cout << "View accounts (input 4)\n";
	cout << "       (input 0 to exit)\n";
	cout << "-----------------------\n";
	int q;
	do {
		cin >> q;
		if ((q == 2 || q == 3 || q == 4) && size == 0) {
			cout << "You have not any accounts. Try to input one at least\n";
		}
		if (q < 0 || q>4) {
			cout << "Input correctly\n";
		}
	} while (((q == 2 || q == 3 || q == 4) && size == 0) || (q < 0 || q>4));

	if (q == 0) {
		cout << "Goodbye\n";
		return 0;
	}

	if (q == 1) {
		add:
		addacc(arr, size);
		cout << "Want to add another one? (1 - yes; 0 - back)\n";
		do {
			cin >> q;
			if (q < 0 || q>1) {
				cout << "Input correctly\n";
			}
		} while (q < 0 || q>1);
		if (q == 1) {
			goto add;
		}
		if (q == 0) {
			goto start;
		}
	}

	if (q == 2) {
		search:
		search(arr, size);
		cout << "Want to search again? (1 - yes; 0 - back)\n";
		do {
			cin >> q;
			if (q < 0 || q>1) {
				cout << "Input correctly\n";
			}
		} while (q < 0 || q>1);
		if (q == 1) {
			goto search;
		}
		if (q == 0) {
			goto start;
		}
	}

	if (q == 3) {
	change:
		change(arr, size);
		cout << "Want to change again? (1 - yes; 0 - back)\n";
		do {
			cin >> q;
			if (q < 0 || q>1) {
				cout << "Input correctly\n";
			}
		} while (q < 0 || q>1);
		if (q == 1) {
			goto change;
		}
		if (q == 0) {
			goto start;
		}
	}
	if (q == 4) {
		viewacc(arr, size);
		char f;
		cout << "Input anything to back in main menu  ";
		cin >> f;
		goto start;
	}
}

