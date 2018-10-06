#include<iostream>
#include<string>
#include<vector>
using namespace std;
//function prototype
std::string lower(std::string t);
string todigit(int num);
int toint(string digit);
string Xor(string a, string b);
void Caesar_cipher(std::string message, int keynum);
void Monoalphabetic_cipher(std::string message, const std::string key);
void Playfair_cipher(std::string message, std::string key);   //有問題
void Vernam_cipher(string message, string key);               //有問題
void Row_transposition(std::string message, vector<int> key);
void Product_cipher(std::string message, vector<int> key);
//main
int main()
{
	bool isContinue = true;
	while (isContinue) {
		vector<int> inputlist;
		std::string inputString = "", inputkeyString = "";
		int i = 0, inputnum = 0, num = 0, typeOfdecrypt = 0;
		std::cout << "(1:Caesar cipher, 2:Monoalphabetic cipher, 3:Playfair cipher, 4:Vernam cipher, 5:Row transposition, 6:Product cipher)" << endl;
		std::cout << "Please input your encrypt type : ";
		std::cin >> typeOfdecrypt;
		switch (typeOfdecrypt)
		{
		case 1:
			std::cout << "Please input cipher :";
			std::cin >> inputString;
			std::cout << "Please input key num :";
			std::cin >> inputnum;
			std::cout << endl;
			std::cout << "You choose Caesar cipher" << endl;
			Caesar_cipher(inputString, inputnum);
			break;
		case 2:
		case 3:
		case 4:
			std::cout << "Please input cipher :";
			std::cin >> inputString;
			std::cout << "Please input key string :";
			std::cin >> inputkeyString;
			std::cout << endl;
			if (typeOfdecrypt == 2) {
				std::cout << "You choose Monoalphabetic cipher" << endl;
				Monoalphabetic_cipher(inputString, inputkeyString);
			}
			else if (typeOfdecrypt == 3) {
				std::cout << "You choose Playfair cipher" << endl;
				Playfair_cipher(inputString, inputkeyString);
			}
			else if (typeOfdecrypt == 4) {
				std::cout << "You choose Vernam cipher" << endl;
				Vernam_cipher(inputString, inputkeyString);
			}
			break;
		case 5:
		case 6:
			std::cout << "Please input cipher :";
			std::cin >> inputString;
			std::cout << "Please input length of key :";
			std::cin >> inputnum;
			std::cout << endl;
			while (i < inputnum) {
				std::cout << "still need to input " << inputnum - i << " number" << endl;
				std::cout << "num = ";
				std::cin >> num;
				inputlist.push_back(num);
				i++;
			}
			if (typeOfdecrypt == 5) {
				std::cout << "You choose Row transposition" << endl;
				Row_transposition(inputString, inputlist);
			}
			else {
				std::cout << "You choose Product cipher" << endl;
				Product_cipher(inputString, inputlist);
			}
			inputlist.clear();
			break;
		default:
			break;
		}
		std::cout << endl << "Continue press 1, exit press 0" << endl;
		std::cin >> isContinue;
	}
	return 0;
}
//function implement
void Caesar_cipher(std::string message, int keynum) {
	char output = ' ';
	std::cout << "Caesar cipher " << " : ";
	std::cout << message << " ---> ";
	for (int i = 0; message[i] != '\0'; i++) {
		output = message[i];
		std::cout << char(tolower(((output - 'Z') - keynum) % 26 + 'Z'));
	}
	std::cout << std::endl;
	std::cout << std::endl;
}
void Monoalphabetic_cipher(std::string message, const std::string key) {
	char output = ' ';
	const std::string alpha = "zyxwvutsrqponmlkjihgfedcba";
	std::cout << "Monoalphabetic cipher " << " : ";
	std::cout << message << " ---> ";
	for (int i = 0; i < message.size(); i++) {
		for (int j = 0; j < key.size(); j++) {
			if (message[i] == key[j])
				output = alpha[j];
		}
		std::cout << output;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}
void Playfair_cipher(std::string message, std::string key) {
	int index1[2], index2[2];
	std::string keyString = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < key.size(); i++) {
		for (int j = 0; j < keyString.size(); j++) {
			if (key[i] == keyString[j])
				keyString.erase(j, 1);
		}
	}
	keyString = key + keyString;
	std::cout << "Playfair cipher " << " : ";
	std::cout << message << " ---> ";
	for (int i = 0; i < message.length(); i += 2) {
		for (int j = 0; j < keyString.length(); j++) {
			if (message[i] == keyString[j]) {
				index1[0] = (j) / 5;
				index1[1] = (j) % 5;
			}
			if (message[i + 1] == keyString[j]) {
				index2[0] = (j) / 5;
				index2[1] = (j) % 5;
			}
		}
		if (index1[0] == index2[0] && index1[1] == index2[1]) {
			index1[0] = (index1[0] + 4) % 5;
			index2[0] = (index2[0] + 4) % 5;
		}
		if (index1[0] != index2[0] && index1[1] != index2[1]) {
			std::swap(index1[1], index2[1]);
		}
		if (index1[0] == index2[0] && index1[1] != index2[1]) {
			index1[1] = ((index1[1] - 1) >= 0) ? (index1[1] - 1) % 5 : (index1[1] + 4) % 5;
			index2[1] = ((index2[1] - 1) >= 0) ? (index2[1] - 1) % 5 : (index2[1] + 4) % 5;
		}
		if (index1[0] != index2[0] && index1[1] == index2[1]) {
			index1[0] = ((index2[0] - 1) >= 0) ? (index1[0] - 1) % 5 : (index1[0] + 4) % 5;
			index2[0] = ((index2[0] - 1) >= 0) ? (index2[0] - 1) % 5 : (index2[0] + 4) % 5;
		}
		std::cout << char(tolower(keyString[(index1[0] * 5 + index1[1])])) << char(tolower(keyString[(index2[0] * 5 + index2[1])]));
	}
	std::cout << std::endl;
}
void Vernam_cipher(string message, string key) {
	std::cout << endl << "Vernam cipher " << " : ";
	std::cout << message << " ---> ";
	for (int i = 0, k = 0; i < message.size(); i += key.size()) {
		for (int j = 0; j < key.size(); j++) {
			if (k >= message.size())
				break;
			char code = char(toint(Xor(todigit(message[k] - 'A'), todigit(key[j] - 'A'))) + 'A');
			key[j] = code;
			std::cout << char(tolower(code));
			k++;
		}
	}
	std::cout << endl;
}
void Row_transposition(std::string message, vector<int> key) {
	std::cout << "Row transposition " << " : ";
	std::cout << message << " ---> ";
	int div = message.size() / key.size();
	int mod = message.size() % key.size();
	vector<int> listCount;
	for (int i = 0; i < mod; i++) {
		listCount.push_back(key[i]);
	}
	for (int i = 0, count = 0; i < message.size(); i += 8) {
		for (int j = 0; j < key.size(); j++) {
			count++;
			if (count > message.size())
				break;
			int index = 0;
			for (int k = 1; k < key[j]; k++) {
				bool countExtra = 0;
				for (int m = 0; m < listCount.size(); m++) {
					if (k == listCount[m]) {
						index += (div + 1);
						countExtra = true;
					}
				}
				if (!countExtra)
					index += div;
			}
			std::cout << (char)(tolower(message[index + (i / key.size())]));
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
}
void Product_cipher(std::string message, vector<int> key) {
	std::cout << "Product cipher " << " : ";
	std::cout << message << " ---> ";
	int temp = 0;
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
std::string lower(std::string t) {
	for (int i = 0; i < t.length(); i++) {
		t[i] = tolower(t[i]);
	}
	return t;
}
string todigit(int num) {
	char digit[5] = { '0','0','0','0','0' };
	for (int i = 4; num > 0; i--) {
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