#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define ww 22

string Upper(string t) {
	for (int i = 0; i < t.length(); i++) {
		t[i] = toupper(t[i]);
	}
	return t;
}
void Caesar_cipher(string text,int key ) {

	cout << left << setw(ww) << "Caesar cipher" << ": ";
	for (int i = 0; i < text.length(); i++) {
		cout << char(((text[i] - 'A') + 7) % 26 + 'A');
	}
	cout << endl;
}
void Monoalphabetic_cipher(string text, string key) {
	cout << left << setw(ww) << "Monoalphabetic cipher" << ": ";
	for (int i = 0; i < text.length(); i++) {
		cout << key[25 - (text[i] - 'A')];
	}
	cout << endl;
}
void Playfair_cipher(string text, string key) {
	int x[2], y[2];
	string az = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < key.length(); i++) {
		for (string::iterator j = az.begin(); j != az.end(); ++j) {
			if (*j == key[i]) {
				az.erase(j);
			}
		}
	}
	key = key + az;
	cout << left << setw(ww) << "Playfair cipher" << ": ";
	if (text.length() % 2 == 1) {
		text += 'X';
	}
	for (int i = 0; i < text.length(); i+=2) {
		for (int j = 0;j < key.length(); j++) {
			if (text[i] == text[i + 1]) {
				text[i + 1] = 'X';
			}
			if (text[i] == key[j]) {
				x[0] = (j) / 5;
				x[1] = (j) % 5;
			}
			if (text[i + 1] == key[j]) {
				y[0] = (j) / 5;
				y[1] = (j) % 5;
			}
		}
		if (x[0] != y[0] && x[1] != y[1]) {
			swap(x[1], y[1]);
		}
		if (x[0] == y[0] && x[1] != y[1]) {
			x[1] = (x[1] + 1) % 5;
			y[1] = (y[1] + 1) % 5;
		}
		if (x[0] != y[0] && x[1] == y[1]) {
			x[0] = (x[0] + 1) % 5;
			y[0] = (y[0] + 1) % 5;
		}
		cout << key[(x[0] * 5 + x[1])] << key[(y[0] * 5 + y[1])];
	}
	cout << endl;
	for (int i = 0;i < key.length(); i++) {
			cout << key[i] << ' ';
			if ((i + 1) % 5 == 0)
				cout << endl;

	}
}
void Vernam_cipher(string text, string key) {
	cout << left << setw(ww) << "Vernam cipher" << ": ";
		for (int i = 0, j = 0, flag = 0; i < text.length(); ++i) {
			cout << (char)((((text[i] - 'A') ^ (key[j] - 'A')) % 26) + 'A');
			if (flag == 0 && (j + 1 >= key.length())) {
				flag = 1;
				j = 0;
				key = text;
			}
			else {
				j = (j + 1) % key.length();
				}
		}
	cout << endl;
}
void Row_transposition(string text, string key) {
	cout << left << setw(ww) << "Row transposition" << ": ";
	text = key + text;
	for (int i = 1,flag = 0; i <= key.length(); i++) {
		for (int j = 0; (j + key.length()) < text.length();) {
			if (flag == 1) {
				cout << text[j + key.length()];
				j += key.length();
			}
			else if ((text[j] - '0') == i && flag == 0) {
				cout << text[j + key.length()];
				j += key.length();
				flag = 1;
			}
			else
				j++;
		}
		flag = 0;
	}
	cout << endl;
	for (int i = 0; i < text.length(); i++) {
		cout << text[i] << ' ';
		if ((i + 1) % key.length() == 0)
			cout << endl;
	}
	cout << endl;
}
void Product_cipher(string text, string key) {
	cout << left << setw(ww) << "Product cipher" << ": ";
	int a[20] = { 15,11,19,18,16,3,7,14,2,20,4,12,9,6,1,5,17,13,10,8 };
	for (int i = 0; i < 20; i++) {
		cout << text[a[i] - 1];
	}
	cout << endl;
}
int main() {
	string plaintext = "keepgoingnevergiveup",upperplaintext;
	upperplaintext = Upper(plaintext);
	cout << left << setw(ww) << "Plaintext " << ": " << plaintext << endl;
	Caesar_cipher(upperplaintext, 7);
	Monoalphabetic_cipher(upperplaintext,"MNBVCXZLKJHGFDSAPOIUYTREWQ");
	Playfair_cipher(upperplaintext, "HIT");
	Vernam_cipher(upperplaintext, "CON");
	Row_transposition(upperplaintext, "31562487");
	Product_cipher(upperplaintext, "15 11 19 18 16 03 07 14 02 20 04 12 09 06 01 05 17 13 10 08");
	return 0;
}