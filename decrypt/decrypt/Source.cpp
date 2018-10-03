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
void Row_transposition(std::string message, int key[]) {
	std::cout << std::left << std::setw(22) << "Row transposition " << " : ";
	std::cout << message << " ---> ";
	char temp = ' ';
	std::string output = "";
	//int Arr1[8] = { 3, 1, 5, 6, 2, 4, 8, 7 };
	cout << "array (on stack): ";
	cout << sizeof(key) / sizeof(key[0]) << endl;
	for (int i = 0,count = 0; i < message.size(); i+=8) {
		for (int j = 0; j < sizeof(key)/sizeof(key[0]); j++) {
			count++;
			if (count > message.size())
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
	for (int i = 0; i < message.size(); i++) {
		for (int j = 0; j < message.size() - i - 1; j++) {
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
string Upper(string t) {
	for (int i = 0; i < t.length(); i++) {
		t[i] = toupper(t[i]);
	}
	return t;
}
void Vernam_cipher(string text,string key) {
	for (int i = 0,k=0; i < text.size();i+=3) {
		for (int j = 0; j < key.size(); j++) {
			if (k >= text.size())
				break;
			char code = char(toint(Xor(todigit(text[k] - 'A'), todigit(key[j] - 'A'))) + 'A');
			key[j] = code;
			cout << code;
			k++;
		}	
	}
}


void row(string message, string key) {
	size_t newSize = key.size();
	int* newArr = new int[newSize];

}
int main()
{
	string plaintext = "keepgoingnevergiveup", upperplaintext, GGBIG = "IKJNIDKDLPKYG'LK\\JWB";
	upperplaintext = Upper(plaintext);
	//char ch = ' ';
	std::string message[6] = { "RLLWNVPUNULCLYNPCLBW", "ATTHUGOFUFTCTKUOCTXH", "MCCROUALFOCXMXDBXCPQ",
									"IKJFCKHLIFJTJVTMECCA", "IKJNIDKDLPKYG`LK\JWB", "GEUEIEIREPPVGOKGVENN" };

	//const std::string MonoaKey = "MNBVCXZLKJHGFDSAPOIUYTREWQ";
	//int ProductKey[20] = { 15,11,19,18,16,3,7,14,2,20,4,12,9,6,1,5,17,13,10,8 };
	int RowKey[8] = { 3, 1, 5, 6, 2, 4, 8, 7 };  //key = 31562487
	//const std::string ke = "CONCONCONCONCONCONCO";
	//string plainkey = "CONKEEPGOINGNEVERGIV";
	//const std::string k = "IKJNIDKDLPKYG`LK\JWB";
	const std::string newkey = "IKJFCKHLIFJTJVTMEC][";
	//Caesar_cipher(message[0]);
	//Monoalphabetic_cipher(message[1], MonoaKey);
	//Playfair_cipher(message[2], "HIT");
	//Vernam_cipher(message[4], "CON");
	Row_transposition(message[4], RowKey);
	//Product_cipher(message[5], ProductKey);
	//Vernam_cipher(newkey,"CON");
	
	return 0;
}