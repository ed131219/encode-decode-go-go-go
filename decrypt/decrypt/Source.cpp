#include<stdio.h>
#include<iostream>
#include<string>
#include <iomanip>
#include<vector>
using namespace std;
std::string lower(std::string t) {
	for (int i = 0; i < t.length(); i++) {
		t[i] = tolower(t[i]);
	}
	return t;
}

void Caesar_cipher(std::string message) {
	char output = ' ';
	std::cout << std::left << std::setw(22) << "Caesar cipher "<<" : ";
	std::cout << message << " ---> ";
	for (int i = 0; message[i] != '\0'; i++) {
		output = message[i];
		std::cout << char(tolower(((output - 'Z') - 7) % 26 + 'Z'));
	}
	std::cout << std::endl;
	std::cout << std::endl;
}
void Monoalphabetic_cipher(std::string message,const std::string key) {
	char output = ' ';
	const std::string alpha = "zyxwvutsrqponmlkjihgfedcba";
	std::cout << std::left << std::setw(22) << "Monoalphabetic cipher "<<" : ";
	std::cout << message << " ---> ";
	for (int i = 0; i < message.size(); i++) {
		for (int j = 0; j < key.size(); j++) {
			if (message[i] == key[j])
				output = alpha[j];
		}
		std::cout << output;
	}
	std::cout<<std::endl;
	std::cout << std::endl;
}
void Playfair_cipher(std::string message, std::string key) {
	int index1[2], index2[2];
	std::string keyString = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < key.size(); i++) {
		for (int j = 0; j < keyString.size(); j++) {
			if (key[i] == keyString[j])
				keyString.erase(j,1);
		}
	}
	keyString = key + keyString;
	std::cout << std::left << std::setw(22) << "Playfair cipher " << " : ";
	std::cout << message << " ---> ";
	for (int i = 0; i < message.length(); i += 2) {
		for (int j = 0; j < keyString.length(); j++) {
			if (message[i] == message[i + 1]) {
				message[i + 1] = 'X';
			}
			if (message[i] == keyString[j]) {
				index1[0] = (j) / 5;
				index1[1] = (j) % 5;
			}
			if (message[i + 1] == keyString[j]) {
				index2[0] = (j) / 5;
				index2[1] = (j) % 5;
			}
		}
		if (index1[0] != index2[0] && index1[1] != index2[1]) {
			std::swap(index1[1], index2[1]);
		}
		if (index1[0] == index2[0] && index1[1] != index2[1]) {
			index1[1] = ((index1[1] - 1) >= 0) ?  (index1[1] - 1) % 5 : (index1[1] + 4) % 5;
			index2[1] = ((index2[1] - 1) >= 0) ? (index2[1] - 1) % 5 : (index2[1] + 4) % 5;
		}
		if (index1[0] != index2[0] && index1[1] == index2[1]) {
			index1[0] = ((index2[0] - 1) >= 0) ? (index1[0] - 1) % 5 : (index1[0] + 4) % 5;
			index2[0] = ((index2[0] - 1) >= 0) ? (index2[0] - 1) % 5 : (index2[0] + 4) % 5;
		}
		std::cout << char(tolower(keyString[(index1[0] * 5 + index1[1])])) << char(tolower(keyString[(index2[0] * 5 + index2[1])]));
	}
	std::cout << std::endl;
	for (int i = 0; i < keyString.size(); i++) {
		std::cout << keyString[i] << ' ';
		if ((i + 1) % 5 == 0)
			std::cout << std::endl;
	}
}
void Vernam_cipher(std::string message, std::string key) {
	
}
void Row_transposition(std::string message, int *key) {
	std::cout << std::left << std::setw(22) << "Row transposition " << " : ";
	std::cout << message << " ---> ";
	char temp = ' ';
	std::string output = "";
	/*int a[8][2] = {};
	for (int i = 0; i < 8; i++) {
		for (int j = 1; j < 2; j++) {
			if (i >= 4)
				a[i][j] = 2;
			else
				a[i][j] = 3;
		}
		a[i][0] = key[i];
	}*/
	for (int i = 0,count = 0; i < message.size(); i+=8) {
		for (int j = 0; j < 8; j++) {
			count++;
			if (count > 20)
				break;
			int index = 0;
			for (int k = 1; k < key[j]; k++) {
				if (k == 3 || k == 1 || k == 5 || k == 6) {
					index += 3;
				}
				else
					index += 2;
			}
			std::cout << (char)(tolower(message[index + (i / 8)]));	
		}	
	}
	std::cout << std::endl;
	std::cout << std::endl;
}
void Product_cipher(std::string message, int* key) {
	std::cout << std::left << std::setw(22) << "Product cipher " << " : ";
	std::cout << message << " ---> ";
	int temp =0;
	char tmp = ' ';
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20 - i - 1; j++) {
			if (key[j] > key[j + 1])
			{
				std::swap(key[j], key[j + 1]);
				tmp = message[j];
				message[j] = message[j + 1];
				message[j + 1] = tmp;				
			}
		}
	}
	std::cout << lower(message);
	std::cout << std::endl;
	std::cout << std::endl;
}
string todigit(int num) {
	char digit[5] = { '0','0','0','0','0' };
	for (int i = 4; num > 0; --i) {
		digit[i] = (num % 2) + '0';
		num = num / 2;
	}
	return digit;
}
int toint(string digit) {
	int num;
	num = (digit[0] - '0') * 16 + (digit[1] - '0') * 8 + (digit[2] - '0') * 4 + (digit[3] - '0') * 2 + (digit[4] - '0') * 1;
	return num;
}
string Xor(string a, string b) {
	char code[5];
	for (int i = 0; i < 5; i++) {
		code[i] = ((a[i] - '0') ^ (b[i] - '0')) + '0';
	}
	return code;
}
void Vernam_ciphers(string text, string key) {
	cout << left << setw(22) << "Vernam cipher" << ": ";
	for (int i = 0, j = 0, flag = 0; i < text.length(); ++i) {
		//cout << (char)((((text[i] - 'A') ^ (key[j] - 'A')) % 26 ) + 'A');
		char code = char(toint(Xor(todigit(text[i] - 'A'), todigit(key[j] - 'A'))) + 'A');
		cout << code;

		/*if (flag == 0 && (j + 1 >= key.length())) {
			flag = 1;
			j = 0;
			key = text;
		}
		else */
		j = (j + 1) % key.length();
	}
	cout << endl;
}
string Upper(string t) {
	for (int i = 0; i < t.length(); i++) {
		t[i] = toupper(t[i]);
	}
	return t;
}
int main()
{
	string plaintext = "keepgoingnevergiveup", upperplaintext, GGBIG = "IKJNIDKDLPKYG'LK\\JWB";
	upperplaintext = Upper(plaintext);
	char ch = ' ';
	std::string message[6] = { "RLLWNVPUNULCLYNPCLBW", "ATTHUGOFUFTCTKUOCTXH", "MCCROUALFOCXMXDBXCPQ",
										"IKJFCKHLIFJTJVTMECCA", "IKJNIDKDLPKYG`LK\JWB", "GEUEIEIREPPVGOKGVENN" };

	const std::string MonoaKey = "MNBVCXZLKJHGFDSAPOIUYTREWQ";
	int ProductKey[20] = { 15,11,19,18,16,3,7,14,2,20,4,12,9,6,1,5,17,13,10,8 };
	int RowKey[8] = { 3, 1, 5, 6, 2, 4, 8, 7 };  //key = 31562487
	const std::string ke = "CONCONCONCONCONCONCO";
	const std::string k = "IKJNIDKDLPKYG`LK\JWB";
	/*Caesar_cipher(message[0]);
	Monoalphabetic_cipher(message[1], MonoaKey);
	Playfair_cipher(message[2], "HIT");
	Vernam_cipher(message[4], "CON");
	Row_transposition(message[4], RowKey);
	Product_cipher(message[5], ProductKey);*/
	Vernam_ciphers(upperplaintext, "CON");
	std::cout << (char)(('H' ^ 'X'))<<std::endl;
	ch = (char)('H' ^ 'X');
	for (int i = 0; i < 20; i++) {
		std::cout << ((k[i] ^ ke[i])) << std::endl;
	}
	cout << int('K') << endl;
	return 0;
}