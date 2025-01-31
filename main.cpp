#include <iostream>
using namespace std;

void input_marks(int marks[], int value) {
	for (int i = 0; i < value; i++) {
		cout << "Enter mark " << i + 1 << " ";
		cin >> marks[i];
		system("cls");
	}
}

void output_marks(int marks[], int value, int choice) {
	if (choice == 0) {
		for (int i = 0; i < value; i++) {
			cout << "Mark " << i + 1 << " is " << marks[i] << endl;
		}
	}
	else if (choice == 1) {
		for (int i = 0; i < value - 1; i++) {
			for (int j = i + 1; j < value; j++) {
				if (marks[i] > marks[j]) {
					swap(marks[i], marks[j]);
				}
			}
		}
		for (int i = 0; i < value; i++) {
			cout << "Mark " << i + 1 << " is " << marks[i] << endl;
		}
	}
	else {
		cout << "Invalid choice" << endl;
	}

}

void new_mark(int marks[], int num_of_mark, int _new_mark) {
	if (num_of_mark < 1 || num_of_mark > 10) {
		cout << "Invalid number of mark" << endl;
		return;
	}
	marks[num_of_mark] = _new_mark;
}

int scholarship(int marks[], int value) {
	float sum = 0;
	for (int i = 0; i < value; i++) {
		sum += marks[i];
	}
	if (sum / value < 10.7) {
		return 0;
	}
	else {
		return 1;
	}
}

int main() {
	const int value = 10;
	int* marks = new int[value];
	input_marks(marks, value);
	int choice;
	do {
		cout << endl;
		cout << "Menu:\n";
		cout << "1. Output marks\n";
		cout << "2. Output sorted marks\n";
		cout << "3. Change a mark\n";
		cout << "4. Check scholarship\n";
		cout << "5. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			system("cls");
			output_marks(marks, value, 0);

			break;
		case 2:
			system("cls");
			output_marks(marks, value, 1);
			break;
		case 3:
			system("cls");
			int num_of_mark;
			cout << "Enter the number of mark you want to change: ";
			cin >> num_of_mark;
			int _new_mark;
			cout << "Enter the new mark: ";
			cin >> _new_mark;
			new_mark(marks, num_of_mark - 1, _new_mark);
			break;
		case 4:
			system("cls");
			if (scholarship(marks, value) == 0) {
				cout << "You don't have scholarship" << endl;
			}
			else {
				cout << "You have scholarship" << endl;
			}
			break;
		case 5:
			system("cls");
			cout << "Leaving" << endl;
			break;
		default:
			cout << "Invalid choice, please try again." << endl;
			break;
		}
	} while (choice != 5);

	delete[] marks;

	return 0;
}