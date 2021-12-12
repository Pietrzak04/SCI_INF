#include <iostream>
#include <string>
#include <time.h>

using namespace std;

struct Keys {
	pair<long int, long int> privateKey;
	pair<long int, long int> publicKey;
};

class Encryption {
public:
	virtual ~Encryption() = 0;

public:
	string substitution(string t, int k)
	{
		int l = t.length();

		if (!(k >= 1 && k <= 26))
		{
			cout << "niewłaściwy klucz" << endl;
			cout << "tekst nie został zmieniony" << endl;

			return t;
		}

		//iterate string array
		for (int i = 0; i < l; i++)
		{
			//check if the current char is in the uppercase range
			if (t[i] >= 'A' && t[i] <= 'Z')
			{
				//check if char doesn't need to be transferred 
				if (t[i] + k <= 'Z')
				{
					t[i] += k;
				}
				else {
					t[i] = t[i] + k - 26;
				}
			}
			//check if the current char is in the lowercase range
			else if (t[i] >= 'a' && t[i] <= 'z')
			{
				//check if char doesn't need to be transferred 
				if (t[i] + k <= 'z')
				{
					t[i] += k;
				}
				else {
					t[i] = t[i] + k - 26;
				}
			}
			//if the current char is out of range do nothing
		}

		return t;
	}

	string transposition(string t)
	{
		int l = t.length();

		//iterate string array
		for (int i = 0; i < l; i += 2)
		{
			//break if length is odd
			if (i + 1 == l)
			{
				break;
			}

			//swap two elements
			swap(t[i], t[i + 1]);
		}

		return t;
	}
};

Encryption::~Encryption() {}

class Encrypt : public Encryption {
public:
	string transpositionSubstitution(string t, int k)
	{
		return transposition(substitution(t, k));
	}
};

class Decrypt : public Encryption {
public:

	string decryptSubstitution(string t)
	{
		int n;
		int l = t.length();

		//iterate all posible keys
		for (int j = 1; j < 26; j++)
		{
			cout << endl << "klucz = " << j << endl;
			//iterate string array
			for (int i = 0; i < l; i++)
			{
				//check if the current char is in the uppercase range
				if (t[i] >= 'A' && t[i] <= 'Z')
				{
					//check if char doesn't need to be transferred 
					if (t[i] + j <= 'Z')
					{
						cout << char(t[i] + j);
					}
					else {
						cout << char(t[i] + j - 26);
					}
				}
				//check if the current char is in the lowercase range
				else if (t[i] >= 'a' && t[i] <= 'z')
				{
					//check if char doesn't need to be transferred 
					if (t[i] + j <= 'z')
					{
						cout << char(t[i] + j);
					}
					else {
						cout << char(t[i] + j - 26);
					}
				}
				else {
					//if the current char is out of range print the same char 
					cout << char(t[i]);
				}
			}
		}

		cout << endl << "podaj poprawny klucz" << endl;
		cin >> n;

		t = Encryption::substitution(t, n);

		return t;
	}

	string decryptTranspositionSubstitution(string t, int k)
	{
		return transposition(this->decryptSubstitution(t));
	}
};

class RSA {
private:
	int prime(int n)
	{

		// All prime numbers are odd except two
		if (n & 1)
			n -= 2;
		else
			n--;

		int i, j;
		for (i = n; i >= 2; i -= 2)
		{
			if (i % 2 == 0)
				continue;
			for (j = 3; j <= sqrt(i); j += 2)
			{
				if (i % j == 0)
					break;
			}
			if (j > sqrt(i)) return i;
		}

		// It will only be executed when n is 3
		return 2;
	}

	int randomNumber(int min, int max)
	{
		srand(time(NULL));

		return rand() % (max - min + 1) + min;
	}

	int gcd(int a, int b)
	{
		int t;
		while (1) {
			t = a % b;
			if (t == 0)
				return b;
			a = b;
			b = t;
		}
	}

public:

	Keys generateKey() 
	{
		long int pN1 = prime(randomNumber(10, 30));  // primary number 1
		long int pN2 = prime(randomNumber(10, 30));  // primary number 2

		// in case of the same primary number generate other
		while (pN1 == pN2)
		{
			pN2 = prime(randomNumber(10, 20));
		}

		//RSA module
		long int n = pN1 * pN2;

		//Euler function
		long int phi = (pN1 - 1) * (pN2 - 1);

		// get random e
		long int e = randomNumber(2, 5);

		//for checking that 1 < e < phi(n) and gcd(e, phi(n)) = 1; i.e., e and phi(n) are coprime.
		long int devidor;
		while (e < phi)
		{
			devidor = gcd(e, phi);
			if (devidor == 1)
				break;
			else
				e++;
		}

		long int d1 = 1 / e;
		long int d = fmod(d1, phi);

		Keys keys;
		keys.privateKey = pair<long int, long int>(d, n);
		keys.publicKey = pair<long int, long int>(e, n);

		return keys;
	}

};

int main()
{
	Encrypt cipher;
	Decrypt unCipher;
	RSA generator;
	Keys keys;

	char option;
	string text;
	int key;

	while (true)
	{
		cout << "co chcesz zrobić" << endl;
		cout << "[1] szyfr podstawieniowy" << endl;
		cout << "[2] szyfr przestawieniowy" << endl;
		cout << "[3] szyfr podstawieniowo-podstawieniowy" << endl;
		cout << "[4] odszyfruj podstawienie" << endl;
		cout << "[5] odszyfruj przestawienie" << endl;
		cout << "[6] odszyfruj podstawieniowo-podstawieniowy" << endl;
		cout << "[7] generuj klucze RSA" << endl;
		cin >> option;

		switch (option)
		{
		case '1':
			cout << "podaj klucz [1 ---- 26]" << endl;
			cin >> key;

			cout << "podaj tekst do kodowania" << endl;
			cin.ignore();
			getline(cin, text);

			text = cipher.substitution(text, key);

			cout << text << endl;
			break;
		case '2':
			cout << "podaj tekst do kodowania" << endl;
			cin.ignore();
			getline(cin, text);

			text = cipher.transposition(text);

			cout << text << endl;
			break;
		case '3':
			cout << "podaj klucz [1 ---- 26]" << endl;
			cin >> key;

			cout << "podaj tekst do kodowania" << endl;
			cin.ignore();
			getline(cin, text);

			text = cipher.substitution(cipher.transposition(text), key);

			cout << text << endl;
			break;
		case '4':
			cout << "podaj tekst do odkodowania" << endl;
			cin.ignore();
			getline(cin, text);

			text = unCipher.decryptSubstitution(text);

			cout << text << endl;
			break;
		case '5':
			cout << "podaj tekst do odkodowania" << endl;
			cin.ignore();
			getline(cin, text);

			text = unCipher.transposition(text);

			cout << text << endl;
			break;
		case '6':
			cout << "podaj tekst do odkodowania" << endl;
			cin.ignore();
			getline(cin, text);

			text = unCipher.decryptSubstitution(unCipher.transposition(text));

			cout << text << endl;
			break;
		case '7':
			keys = generator.generateKey();

			cout << "Private key: n=" << keys.privateKey.second << " d=" << keys.privateKey.first << "\nPublic key: n=" << keys.publicKey.second << " e=" << keys.publicKey.first << std::endl;
			break;
		default:
			cout << "wybrano nieistniejącą opcje" << endl;
			break;
		}
	}
}

