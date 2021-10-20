#include <iostream>
#include <tuple>
using namespace std;

int check(int h, int b, int w, int t) {
	if (h < 1 || b < 2 || w < 1 || t < 2 || ((2*h+3)-(2*t-1))<0)
		return 0;
	else
		return 1;
}

tuple<int, int, int, int> input() {
	int bol = 0;
	int h, b, w, t;
	while (bol == 0)
	{
		cout << "Enter h, b, w, t: ";
		cin >> h >> b >> w >> t;
		bol = check(h, b, w, t);
	}
	return make_tuple(h, b, w, t);
}

void Space_p(int x) {
	for (int i = 0; i < x; i++)
		cout << " ";
}

void Dot_p(int x) {
	for (int i = 0; i < x; i++)
		cout << ".";
}

void Star_p(int x) {
	for (int i = 0; i < x; i++)
		cout << "*";
}

void Left_p(int x) {
	for (int i = 0; i < x; i++)
		cout << "/";
}

void Right_p(int x) {
	for (int i = 0; i < x; i++)
		cout << "\\";
}

void Box_cell_Tail(int h, int w) {
	Space_p(w);
	cout << "+";
	for (int j = 0; j < 2 * h + 1; j++)
		cout << "-";
	cout << "+\n";
}

void Head_p(int h, int w) {
	Space_p(w + h + 1);
	cout << "|\n";
	int i = 1;
	for (int x = 0; x < h; x++, i+=2) {
		Space_p(w+h-x);
		cout << "/";
		Star_p(i);
		cout << "\\\n";
	}
}

void BodyWing_p(int h, int b, int w) {
	int wing_height;
	if (b % 2 != 0)
		wing_height = b / 2 + 1;
	else
		wing_height = b / 2;
	Box_cell_Tail(h, w);
	for (int x = 0; x < b; x++) {
		if (x >= wing_height)
		{
			Left_p(w);
			cout << "|";
			Dot_p(2 * h + 1);
			cout << "|";
			Right_p(w);
			cout << "\n";
		}
		else {
			Space_p(w);
			cout << "|";
			Dot_p(2 * h + 1);
			cout << "|\n";
		}
	}
	Box_cell_Tail(h, w);
}

void Tail_p(int h, int w, int t) {
	int upper_h = 0;
	if (t % 2 != 0)
		upper_h = t / 2 + 1;
	else
		upper_h = t / 2;
	int upper_v = 2 * (t / 2) + 1;
	int x = 0;
	for (x = 0; x < upper_h; x++) {
		Space_p(w + ((2 * h + 1)/2) - (upper_v/2) - x + 1);
		Star_p(upper_v + 2*x);
		cout << "\n";
	}
	x -= 1;
	for (int z = 0; z < upper_v + 2 * x; z += 2) {
		Space_p(w + ((2 * h + 1) / 2) - (upper_v / 2) - x + 1 + z/2);
		Star_p(upper_v + 2 * x - z);
		cout << "\n";
	}
}

void Main_p(int h, int b, int w, int t) {
	Head_p(h, w);
	BodyWing_p(h, b, w);
	Tail_p(h, w, t);
}

int main() {
	int h, b, w, t;
	tie(h, b, w, t) = input();
	Main_p(h, b, w, t);
}
