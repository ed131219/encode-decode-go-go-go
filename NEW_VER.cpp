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
		else if (x[0] == y[0] && x[1] != y[1]) {
			x[1] = (x[1] + 1) % 5;
			y[1] = (y[1] + 1) % 5;
		}
		else if (x[0] != y[0] && x[1] == y[1]) {
			x[0] = (x[0] + 1) % 5;
			y[0] = (y[0] + 1) % 5;
		}
		else if (x[0] == y[0] && x[1] == y[1]) {
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
string todigit(int num) {
	char digit[5] = {'0','0','0','0','0'};
	for (int i = 4; num > 0 ; --i) {
		digit[i] = (num % 2) + '0';
		num = num / 2;
	}
	return digit;
}
int toint(string digit) {
	int num;
	num = (digit[0]- '0') * 16 + (digit[1] - '0') * 8 + (digit[2] - '0') * 4 + (digit[3] - '0') * 2 + (digit[4] - '0') * 1;
	return num;
}
string Xor(string a, string b) {
	char code[5];
	for (int i = 0;i < 5; i++) {
		code[i] = ((a[i] - '0') ^ (b[i] - '0')) + '0';
	}
	return code;
}
void Vernam_cipher(string text, string key) {
	cout << left << setw(ww) << "Vernam cipher" << ": ";
		for (int i = 0, j = 0, flag = 0; i < text.length(); ++i) {
			//cout << (char)((((text[i] - 'A') ^ (key[j] - 'A')) % 26 ) + 'A');
			char code = char(toint(Xor(todigit(text[i] - 'A'), todigit(key[j] - 'A'))) % 26 + 'A');
			cout << code;

			if (flag == 0 && (j + 1 >= key.length())) {
				flag = 1;
				j = 0;
				key = text;
			}
			else 
				j = (j + 1) % key.length();
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
	string plaintext = "keepgoingnevergiveup",upperplaintext,GGBIG = "IKJNIDKDLPKYG'LK\\JWB",pt, key;
	int mode = -1, intkey;
	cout << "Choose cipher : " << endl;
	cout << "1.Caesar_cipher" << endl << "2.Monoalphabetic_cipher" << endl << "3.Playfair_cipher" << endl;
	cout << "4.Vernam_cipher" << endl << "5.Row_transposition" << endl << "6.Product_cipher" << endl << "0.Exit" << endl;
	while (1) {
		cin >> mode;
		if (mode == 0)
			break;
		cout << left << setw(ww) << "Please enter the plaintext " << ": ";
		cin >> pt;
		pt = Upper(pt);
		switch (mode) 
		{
		case 1:
			cout << left << setw(ww) << "Enter the key " << ": ";
			cin >> intkey;

			cout << "---------------------------------------------------------------" << endl;
			Caesar_cipher(pt, intkey);
			cout << "---------------------------------------------------------------" << endl;

			break;
		case 2:
			cout << "Enter the key : ";
			cin >> key;

			cout << "---------------------------------------------------------------" << endl;
			Monoalphabetic_cipher(pt, Upper(key));
			cout << "---------------------------------------------------------------" << endl;

			break;
		case 3:
			cout << "Enter the key : ";
			cin >> key;

			cout << "---------------------------------------------------------------" << endl;
			Playfair_cipher(pt, Upper(key));
			cout << "---------------------------------------------------------------" << endl;

			break;
		case 4:
			cout << "Enter the key : ";
			cin >> key;

			cout << "---------------------------------------------------------------" << endl;
			Vernam_cipher(pt, Upper(key));
			cout << "---------------------------------------------------------------" << endl;

			break;
		case 5:
			cout << "Enter the key : ";
			cin >> key;

			cout << "---------------------------------------------------------------" << endl;
			Row_transposition(pt, Upper(key));
			cout << "---------------------------------------------------------------" << endl;

			break;
		case 6:
			cout << "Enter the key : ";
			cin >> key;

			cout << "---------------------------------------------------------------" << endl;
			Product_cipher(pt, Upper(key));
			cout << "---------------------------------------------------------------" << endl;

			break;
		default:
			cout << "Wrong input, try again." << endl;	
		}

		//upperplaintext = Upper(plaintext);
		//cout << left << setw(ww) << "Plaintext " << ": " << plaintext << endl;
		//Caesar_cipher(upperplaintext, 7);
		//Monoalphabetic_cipher(upperplaintext,"MNBVCXZLKJHGFDSAPOIUYTREWQ");
		//Playfair_cipher(upperplaintext, "HIT");
		//Vernam_cipher(upperplaintext, "CON");
		//Vernam_cipher(GGBIG, "CON");
		//Row_transposition(upperplaintext, "31562487");
		//Product_cipher(upperplaintext, "15 11 19 18 16 03 07 14 02 20 04 12 09 06 01 05 17 13 10 08");
	}
	system("pause");
	return 0;
}