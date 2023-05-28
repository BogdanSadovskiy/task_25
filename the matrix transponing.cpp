using namespace std;
#include <iostream>
void output(int** arr, int size) {
	cout << "______________________\n";
	for (int i = 0; i < size; i++) {
		
		for (int j = 0; j < size; j++) {
		
			cout << arr[i][j] << " ";
			
		}
		cout << endl;
	}
	cout << "----------------------\n";
}
void change(int**& arr, int size) {
	int c;
	int** arr2 = new int* [size];

	for (int i = 0; i < size; i++) {
		arr2[i] = new int[size];
		for (int j = 0; j < size; j++) {
			arr2[i][j] = arr[j][i];
		}
	}
	delete[] arr;
	arr = arr2;
}

int main()
{
	int size;
	cout << "Input size of matrix\n";
	cin >> size;
	int** arr = new int*[size];
	for (int i = 0; i < size; i++) {
		arr[i] = new int[size];
		for (int j = 0; j < size; j++) {
			arr[i][j] = rand()% 20+1 ;
		}
	}
	output(arr, size);
	change(arr, size);
	output(arr, size);
}
