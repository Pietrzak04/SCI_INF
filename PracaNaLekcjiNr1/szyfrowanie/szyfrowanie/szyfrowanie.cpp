// program szyfrujący

#include <iostream>
#include <string>

using namespace std;

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

string unSubstitution(string t)
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

	t = substitution(t, n);

	return t;
}

int main()
{
	char option;
	string text;
	int key;

	while (true)
	{
		cout << "co chcesz zrobić" << endl;
		cout << "[1] szyfr podstawieniowy" << endl;
		cout << "[2] szyfr przestawieniowy" << endl;
		cout << "[3] szyfr podstawieniowo-podstawieniowy" << endl;
		cout << "[4] odszyfruj" << endl;
		cin >> option;

		switch (option)
		{
		case '1':
			cout << "podaj klucz [1 ---- 26]" << endl;
			cin >> key;

			cout << "podaj tekst do kodowania" << endl;
			cin.ignore();
			getline(cin, text);

			text = substitution(text, key);

			cout << text << endl;
			break;
		case '2':
			cout << "podaj tekst do kodowania" << endl;
			cin.ignore();
			getline(cin, text);

			text = transposition(text);

			cout << text << endl;
			break;
		case '3':
			cout << "podaj klucz [1 ---- 26]" << endl;
			cin >> key;

			cout << "podaj tekst do kodowania" << endl;
			cin.ignore();
			getline(cin, text);

			text = substitution(transposition(text), key);

			cout << text << endl;
			break;
		case '4':
			cout << "podaj tekst do odkodowania" << endl;
			cin.ignore();
			getline(cin, text);

			text = unSubstitution(text);

			cout << text << endl;
			break;
		default:
			cout << "wybrano nieistniejącą opcje" << endl;
			break;
		}
	}

	return 0;
}
