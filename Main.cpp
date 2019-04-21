#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int firstByte(string s) {
	string str2 = "";
	int n;
	if (s.length() == 3)
		str2 += s[0];
	else {
		str2 += s[0];
		str2 += s[1];
	}
	n = stoi(str2, nullptr, 16);
	return n;
}

int secondByte(string s) {
	string str = "";
	int n;
	if (s.length() == 3) {
		str += s[1];
		str += s[2];
	}
	else {
		str += s[2];
		str += s[3];
	}
	n = stoi(str, nullptr, 16);
	return n;
}

int main() {
	int input;
	string word = "";
	bool flag = true;
	bool flag1 = true;
	bool flag2 = true;
	bool flag3 = true;
	bool flagLast = true;
	int choice;
	int choice1;
	int choice2;
	int choice3;
	int choice4;
	char charChoice;
	streampos begin, end;
	ifstream myfile("SAVED.GAM", ios::binary);
	begin = myfile.tellg();
	myfile.seekg(0, ios::end);
	end = myfile.tellg();
	myfile.close();
	cout << "size is: " << (end - begin) << " bytes.\n";

	streampos size;
	char * memblock;

	ifstream rfile("SAVED.GAM", ios::in | ios::binary | ios::ate);
	if (rfile.is_open())
	{
		size = rfile.tellg();
		memblock = new char[size];
		rfile.seekg(0, ios::beg);
		rfile.read(memblock, size);
		rfile.close();

		cout << "the entire file content is in memory" << endl;
		for (int i = 0; i < size; i++) {
			cout << hex << int(memblock[i]);
		}
		cout << endl << endl;

		/*input = 99;
		memblock[0x000E] = input;*/


		//-------------------------------------------------------------------------------------
		cout << "What would you like to change?" << endl;
		cout << "1: Character" << endl;
		cout << "2: Allies" << endl;
		cout << "3: Items" << endl;

		cin >> choice;
		while (flag) {
			if (choice == 1) {
				cout << "What stat would you like to change?" << endl;
				cout << "1. Strength" << endl;
				cout << "2. Dexterity" << endl;
				cout << "3. Intelligance" << endl;
				cout << "4. Health Points" << endl;
				cout << "5. Maximum Health" << endl;
				cout << "6. Experience" << endl;
				cin >> choice1;
				while (flag1) {
					if (choice1 == 1) {
						cout << "Please enter new stat for Strength (1-99)" << endl;
						cin >> input;
						memblock[0x000E] = input;
						flag1 = false;
						flag = false;
					}
					else if (choice1 == 2) {
						cout << "Please enter new stat for Dexterity (1-99)" << endl;
						cin >> input;
						memblock[0x000F] = input;
						flag1 = false;
						flag = false;
					}
					else if (choice1 == 3) {
						cout << "Please enter new stat for Intelligence (1-99)" << endl;
						cin >> input;
						memblock[0x0010] = input;
						flag1 = false;
						flag = false;
					}
					else if (choice1 == 4) {
						cout << "Please enter new stat for HP (1-999)" << endl;
						cin >> input;
						word += memblock[0x0013 + (0x20 * 0)];
						word += memblock[0x0012 + (0x20 * 0)];
						cout << "word: " << word << endl;
						cout << "test: " << memblock[0x0013] << memblock[0x0012] << endl;
						if (input > 0 && input <= 255) {
							memblock[0x0012] = input;
							memblock[0x0013] = 0;
						}
						else {
							//memblock[0x0012] = firstByte(word);
							//memblock[0x0013] = secondByte(word);
						}
						flag1 = false;
						flag = false;
					}
					else if (choice1 == 5) {
						cout << "Do something with max HP" << endl;
						flag1 = false;
					}
					else if (choice1 == 6) {
						cout << "Do something with exp" << endl;
						flag1 = false;
						flag = false;
					}
					else {
						cout << "That is not an availible choice, try again." << endl;
						cout << "1. Strength" << endl;
						cout << "2. Dexterity" << endl;
						cout << "3. Intelligance" << endl;
						cout << "4. Health Points" << endl;
						cout << "5. Maximum Health" << endl;
						cout << "6. Experience" << endl;
						cin >> choice1;
					}
				}
			}
			else if (choice == 2) {
				cout << "Which ally do you want to change?" << endl;
				cout << " 1. Shamino" << endl;
				cout << " 2. Iolo" << endl;
				cout << " 3. Mariah" << endl;
				cout << " 4. Geoffrey" << endl;
				cout << " 5. Jaana" << endl;
				cout << " 6. Julia" << endl;
				cout << " 7. Dupre" << endl;
				cout << " 8. Katrina" << endl;
				cout << " 9. Sentri" << endl;
				cout << "10. Gwenno" << endl;
				cout << "11. Johne" << endl;
				cout << "12. Gorn" << endl;
				cout << "13. Maxwell" << endl;
				cout << "14. Toshi" << endl;
				cout << "15. Saduj" << endl;
				cin >> choice2;

				while (flag2) {
					if (choice2 == 1) {
						cout << "Shanimo:" << endl;
						cout << "1. Str" << endl;
						cout << "2. Dex" << endl;
						cout << "3. Int" << endl;
						cout << "4. HP" << endl;
						cout << "5. Max HP" << endl;
						cout << "6. Exp" << endl;
						cin >> choice4;

						while (flagLast) {
							if (choice4 == 1) {
								cout << "Please enter new stat for Strength (1-99)" << endl;
								cin >> input;
								memblock[0x000E + 0x20] = input;
								flagLast = false;
							}
							else if (choice4 == 2) {
								cout << "Please enter new stat for Dexterity (1-99)" << endl;
								cin >> input;
								memblock[0x000F + 0x20] = input;
								flagLast = false;
							}
							else if (choice4 == 3) {
								cout << "Please enter new stat for Intelligence (1-99)" << endl;
								cin >> input;
								memblock[0x0010 + 0x20] = input;
								flagLast = false;
							}
							else if (choice4 == 4) {
								cout << "Do something with HP" << endl;
								flagLast = false;
							}
							else if (choice4 == 5) {
								cout << "Do something with Max HP" << endl;
								flagLast = false;
							}
							else if (choice4 == 6) {
								cout << "Do something with Exp" << endl;
								flagLast = false;
							}
							else {
								cout << "Incorrect input, please try again" << endl;
								cout << "1. Str" << endl;
								cout << "2. Dex" << endl;
								cout << "3. Int" << endl;
								cout << "4. HP" << endl;
								cout << "5. Max HP" << endl;
								cout << "6. Exp" << endl;
								cin >> choice4;
							}
						}
						flagLast = true;
						flag2 = false;
						flag = false;
					}
					else if (choice2 == 2) {
						cout << "Iolo:" << endl;
						cout << "1. Str" << endl;
						cout << "2. Dex" << endl;
						cout << "3. Int" << endl;
						cout << "4. HP" << endl;
						cout << "5. Max HP" << endl;
						cout << "6. Exp" << endl;
						cin >> choice4;

						while (flagLast) {
							if (choice4 == 1) {
								cout << "Please enter new stat for Strength (1-99)" << endl;
								cin >> input;
								memblock[0x000E + 0x40] = input;
								flagLast = false;
							}
							else if (choice4 == 2) {
								cout << "Please enter new stat for Dexterity (1-99)" << endl;
								cin >> input;
								memblock[0x000F + 0x40] = input;
								flagLast = false;
							}
							else if (choice4 == 3) {
								cout << "Please enter new stat for Intelligence (1-99)" << endl;
								cin >> input;
								memblock[0x0010 + 0x40] = input;
								flagLast = false;
							}
							else if (choice4 == 4) {
								cout << "Do something with HP" << endl;
								flagLast = false;
							}
							else if (choice4 == 5) {
								cout << "Do something with Max HP" << endl;
								flagLast = false;
							}
							else if (choice4 == 6) {
								cout << "Do something with Exp" << endl;
								flagLast = false;
							}
							else {
								cout << "Incorrect input, please try again" << endl;
								cout << "1. Str" << endl;
								cout << "2. Dex" << endl;
								cout << "3. Int" << endl;
								cout << "4. HP" << endl;
								cout << "5. Max HP" << endl;
								cout << "6. Exp" << endl;
								cin >> choice4;
							}
						}
						flagLast = true;
						flag2 = false;
						flag = false;
					}
					else if (choice2 == 3) {
						cout << "Mariah:" << endl;
						cout << "1. Str" << endl;
						cout << "2. Dex" << endl;
						cout << "3. Int" << endl;
						cout << "4. HP" << endl;
						cout << "5. Max HP" << endl;
						cout << "6. Exp" << endl;
						cin >> choice4;

						while (flagLast) {
							if (choice4 == 1) {
								cout << "Please enter new stat for Strength (1-99)" << endl;
								cin >> input;
								memblock[0x000E + 0x60] = input;
								flagLast = false;
							}
							else if (choice4 == 2) {
								cout << "Please enter new stat for Dexterity (1-99)" << endl;
								cin >> input;
								memblock[0x000F + 0x60] = input;
								flagLast = false;
							}
							else if (choice4 == 3) {
								cout << "Please enter new stat for Intelligence (1-99)" << endl;
								cin >> input;
								memblock[0x0010 + 0x60] = input;
								flagLast = false;
							}
							else if (choice4 == 4) {
								cout << "Do something with HP" << endl;
								flagLast = false;
							}
							else if (choice4 == 5) {
								cout << "Do something with Max HP" << endl;
								flagLast = false;
							}
							else if (choice4 == 6) {
								cout << "Do something with Exp" << endl;
								flagLast = false;
							}
							else {
								cout << "Incorrect input, please try again" << endl;
								cout << "1. Str" << endl;
								cout << "2. Dex" << endl;
								cout << "3. Int" << endl;
								cout << "4. HP" << endl;
								cout << "5. Max HP" << endl;
								cout << "6. Exp" << endl;
								cin >> choice4;
							}
						}
						flagLast = true;
						flag2 = false;
						flag = false;
					}
					else if (choice2 == 4) {
						cout << "Geoffrey:" << endl;
						cout << "1. Str" << endl;
						cout << "2. Dex" << endl;
						cout << "3. Int" << endl;
						cout << "4. HP" << endl;
						cout << "5. Max HP" << endl;
						cout << "6. Exp" << endl;
						cin >> choice4;

						while (flagLast) {
							if (choice4 == 1) {
								cout << "Please enter new stat for Strength (1-99)" << endl;
								cin >> input;
								memblock[0x000E + 0x80] = input;
								flagLast = false;
							}
							else if (choice4 == 2) {
								cout << "Please enter new stat for Dexterity (1-99)" << endl;
								cin >> input;
								memblock[0x000F + 0x80] = input;
								flagLast = false;
							}
							else if (choice4 == 3) {
								cout << "Please enter new stat for Intelligence (1-99)" << endl;
								cin >> input;
								memblock[0x0010 + 0x80] = input;
								flagLast = false;
							}
							else if (choice4 == 4) {
								cout << "Do something with HP" << endl;
								flagLast = false;
							}
							else if (choice4 == 5) {
								cout << "Do something with Max HP" << endl;
								flagLast = false;
							}
							else if (choice4 == 6) {
								cout << "Do something with Exp" << endl;
								flagLast = false;
							}
							else {
								cout << "Incorrect input, please try again" << endl;
								cout << "1. Str" << endl;
								cout << "2. Dex" << endl;
								cout << "3. Int" << endl;
								cout << "4. HP" << endl;
								cout << "5. Max HP" << endl;
								cout << "6. Exp" << endl;
								cin >> choice4;
							}
						}
						flagLast = true;
						flag2 = false;
						flag = false;
					}
					else if (choice2 == 5) {
						cout << "Jaana:" << endl;
						cout << "1. Str" << endl;
						cout << "2. Dex" << endl;
						cout << "3. Int" << endl;
						cout << "4. HP" << endl;
						cout << "5. Max HP" << endl;
						cout << "6. Exp" << endl;
						cin >> choice4;

						while (flagLast) {
							if (choice4 == 1) {
								cout << "Please enter new stat for Strength (1-99)" << endl;
								cin >> input;
								memblock[0x000E + 0xA0] = input;
								flagLast = false;
							}
							else if (choice4 == 2) {
								cout << "Please enter new stat for Dexterity (1-99)" << endl;
								cin >> input;
								memblock[0x000F + 0xA0] = input;
								flagLast = false;
							}
							else if (choice4 == 3) {
								cout << "Please enter new stat for Intelligence (1-99)" << endl;
								cin >> input;
								memblock[0x0010 + 0xA0] = input;
								flagLast = false;
							}
							else if (choice4 == 4) {
								cout << "Do something with HP" << endl;
								flagLast = false;
							}
							else if (choice4 == 5) {
								cout << "Do something with Max HP" << endl;
								flagLast = false;
							}
							else if (choice4 == 6) {
								cout << "Do something with Exp" << endl;
								flagLast = false;
							}
							else {
								cout << "Incorrect input, please try again" << endl;
								cout << "1. Str" << endl;
								cout << "2. Dex" << endl;
								cout << "3. Int" << endl;
								cout << "4. HP" << endl;
								cout << "5. Max HP" << endl;
								cout << "6. Exp" << endl;
								cin >> choice4;
							}
						}
						flagLast = true;
						flag2 = false;
						flag = false;
					}
					else if (choice2 == 6) {
						cout << "Julia:" << endl;
						cout << "1. Str" << endl;
						cout << "2. Dex" << endl;
						cout << "3. Int" << endl;
						cout << "4. HP" << endl;
						cout << "5. Max HP" << endl;
						cout << "6. Exp" << endl;
						cin >> choice4;

						while (flagLast) {
							if (choice4 == 1) {
								cout << "Please enter new stat for Strength (1-99)" << endl;
								cin >> input;
								memblock[0x000E + 0xC0] = input;
								flagLast = false;
							}
							else if (choice4 == 2) {
								cout << "Please enter new stat for Dexterity (1-99)" << endl;
								cin >> input;
								memblock[0x000F + 0xC0] = input;
								flagLast = false;
							}
							else if (choice4 == 3) {
								cout << "Please enter new stat for Intelligence (1-99)" << endl;
								cin >> input;
								memblock[0x0010 + 0xC0] = input;
								flagLast = false;
							}
							else if (choice4 == 4) {
								cout << "Do something with HP" << endl;
								flagLast = false;
							}
							else if (choice4 == 5) {
								cout << "Do something with Max HP" << endl;
								flagLast = false;
							}
							else if (choice4 == 6) {
								cout << "Do something with Exp" << endl;
								flagLast = false;
							}
							else {
								cout << "Incorrect input, please try again" << endl;
								cout << "1. Str" << endl;
								cout << "2. Dex" << endl;
								cout << "3. Int" << endl;
								cout << "4. HP" << endl;
								cout << "5. Max HP" << endl;
								cout << "6. Exp" << endl;
								cin >> choice4;
							}
						}
						flagLast = true;
						flag2 = false;
						flag = false;
					}
					else if (choice2 == 7) {
						cout << "Dupre:" << endl;
						cout << "1. Str" << endl;
						cout << "2. Dex" << endl;
						cout << "3. Int" << endl;
						cout << "4. HP" << endl;
						cout << "5. Max HP" << endl;
						cout << "6. Exp" << endl;
						cin >> choice4;

						while (flagLast) {
							if (choice4 == 1) {
								cout << "Please enter new stat for Strength (1-99)" << endl;
								cin >> input;
								memblock[0x000E + 0xE0] = input;
								flagLast = false;
							}
							else if (choice4 == 2) {
								cout << "Please enter new stat for Dexterity (1-99)" << endl;
								cin >> input;
								memblock[0x000F + 0xE0] = input;
								flagLast = false;
							}
							else if (choice4 == 3) {
								cout << "Please enter new stat for Intelligence (1-99)" << endl;
								cin >> input;
								memblock[0x0010 + 0xE0] = input;
								flagLast = false;
							}
							else if (choice4 == 4) {
								cout << "Do something with HP" << endl;
								flagLast = false;
							}
							else if (choice4 == 5) {
								cout << "Do something with Max HP" << endl;
								flagLast = false;
							}
							else if (choice4 == 6) {
								cout << "Do something with Exp" << endl;
								flagLast = false;
							}
							else {
								cout << "Incorrect input, please try again" << endl;
								cout << "1. Str" << endl;
								cout << "2. Dex" << endl;
								cout << "3. Int" << endl;
								cout << "4. HP" << endl;
								cout << "5. Max HP" << endl;
								cout << "6. Exp" << endl;
								cin >> choice4;
							}
						}
						flagLast = true;
						flag2 = false;
						flag = false;
					}
					else if (choice2 == 8) {
						cout << "Katrina:" << endl;
						cout << "1. Str" << endl;
						cout << "2. Dex" << endl;
						cout << "3. Int" << endl;
						cout << "4. HP" << endl;
						cout << "5. Max HP" << endl;
						cout << "6. Exp" << endl;
						cin >> choice4;

						while (flagLast) {
							if (choice4 == 1) {
								cout << "Please enter new stat for Strength (1-99)" << endl;
								cin >> input;
								memblock[0x000E + 0x100] = input;
								flagLast = false;
							}
							else if (choice4 == 2) {
								cout << "Please enter new stat for Dexterity (1-99)" << endl;
								cin >> input;
								memblock[0x000F + 0x100] = input;
								flagLast = false;
							}
							else if (choice4 == 3) {
								cout << "Please enter new stat for Intelligence (1-99)" << endl;
								cin >> input;
								memblock[0x0010 + 0x100] = input;
								flagLast = false;
							}
							else if (choice4 == 4) {
								cout << "Do something with HP" << endl;
								flagLast = false;
							}
							else if (choice4 == 5) {
								cout << "Do something with Max HP" << endl;
								flagLast = false;
							}
							else if (choice4 == 6) {
								cout << "Do something with Exp" << endl;
								flagLast = false;
							}
							else {
								cout << "Incorrect input, please try again" << endl;
								cout << "1. Str" << endl;
								cout << "2. Dex" << endl;
								cout << "3. Int" << endl;
								cout << "4. HP" << endl;
								cout << "5. Max HP" << endl;
								cout << "6. Exp" << endl;
								cin >> choice4;
							}
						}
						flagLast = true;
						flag2 = false;
						flag = false;
					}
					else if (choice2 == 9) {
						cout << "Sentri:" << endl;
						cout << "1. Str" << endl;
						cout << "2. Dex" << endl;
						cout << "3. Int" << endl;
						cout << "4. HP" << endl;
						cout << "5. Max HP" << endl;
						cout << "6. Exp" << endl;
						cin >> choice4;

						while (flagLast) {
							if (choice4 == 1) {
								cout << "Please enter new stat for Strength (1-99)" << endl;
								cin >> input;
								memblock[0x000E + 0x120] = input;
								flagLast = false;
							}
							else if (choice4 == 2) {
								cout << "Please enter new stat for Dexterity (1-99)" << endl;
								cin >> input;
								memblock[0x000F + 0x120] = input;
								flagLast = false;
							}
							else if (choice4 == 3) {
								cout << "Please enter new stat for Intelligence (1-99)" << endl;
								cin >> input;
								memblock[0x0010 + 0x120] = input;
								flagLast = false;
							}
							else if (choice4 == 4) {
								cout << "Do something with HP" << endl;
								flagLast = false;
							}
							else if (choice4 == 5) {
								cout << "Do something with Max HP" << endl;
								flagLast = false;
							}
							else if (choice4 == 6) {
								cout << "Do something with Exp" << endl;
								flagLast = false;
							}
							else {
								cout << "Incorrect input, please try again" << endl;
								cout << "1. Str" << endl;
								cout << "2. Dex" << endl;
								cout << "3. Int" << endl;
								cout << "4. HP" << endl;
								cout << "5. Max HP" << endl;
								cout << "6. Exp" << endl;
								cin >> choice4;
							}
						}
						flagLast = true;
						flag2 = false;
						flag = false;
					}
					else if (choice2 == 10) {
						cout << "Gwenno:" << endl;
						cout << "1. Str" << endl;
						cout << "2. Dex" << endl;
						cout << "3. Int" << endl;
						cout << "4. HP" << endl;
						cout << "5. Max HP" << endl;
						cout << "6. Exp" << endl;
						cin >> choice4;

						while (flagLast) {
							if (choice4 == 1) {
								cout << "Please enter new stat for Strength (1-99)" << endl;
								cin >> input;
								memblock[0x000E + 0x140] = input;
								flagLast = false;
							}
							else if (choice4 == 2) {
								cout << "Please enter new stat for Dexterity (1-99)" << endl;
								cin >> input;
								memblock[0x000F + 0x140] = input;
								flagLast = false;
							}
							else if (choice4 == 3) {
								cout << "Please enter new stat for Intelligence (1-99)" << endl;
								cin >> input;
								memblock[0x0010 + 0x140] = input;
								flagLast = false;
							}
							else if (choice4 == 4) {
								cout << "Do something with HP" << endl;
								flagLast = false;
							}
							else if (choice4 == 5) {
								cout << "Do something with Max HP" << endl;
								flagLast = false;
							}
							else if (choice4 == 6) {
								cout << "Do something with Exp" << endl;
								flagLast = false;
							}
							else {
								cout << "Incorrect input, please try again" << endl;
								cout << "1. Str" << endl;
								cout << "2. Dex" << endl;
								cout << "3. Int" << endl;
								cout << "4. HP" << endl;
								cout << "5. Max HP" << endl;
								cout << "6. Exp" << endl;
								cin >> choice4;
							}
						}
						flagLast = true;
						flag2 = false;
						flag = false;
					}
					else if (choice2 == 11) {
						cout << "Johne:" << endl;
						cout << "1. Str" << endl;
						cout << "2. Dex" << endl;
						cout << "3. Int" << endl;
						cout << "4. HP" << endl;
						cout << "5. Max HP" << endl;
						cout << "6. Exp" << endl;
						cin >> choice4;

						while (flagLast) {
							if (choice4 == 1) {
								cout << "Please enter new stat for Strength (1-99)" << endl;
								cin >> input;
								memblock[0x000E + 0x160] = input;
								flagLast = false;
							}
							else if (choice4 == 2) {
								cout << "Please enter new stat for Dexterity (1-99)" << endl;
								cin >> input;
								memblock[0x000F + 0x160] = input;
								flagLast = false;
							}
							else if (choice4 == 3) {
								cout << "Please enter new stat for Intelligence (1-99)" << endl;
								cin >> input;
								memblock[0x0010 + 0x160] = input;
								flagLast = false;
							}
							else if (choice4 == 4) {
								cout << "Do something with HP" << endl;
								flagLast = false;
							}
							else if (choice4 == 5) {
								cout << "Do something with Max HP" << endl;
								flagLast = false;
							}
							else if (choice4 == 6) {
								cout << "Do something with Exp" << endl;
								flagLast = false;
							}
							else {
								cout << "Incorrect input, please try again" << endl;
								cout << "1. Str" << endl;
								cout << "2. Dex" << endl;
								cout << "3. Int" << endl;
								cout << "4. HP" << endl;
								cout << "5. Max HP" << endl;
								cout << "6. Exp" << endl;
								cin >> choice4;
							}
						}
						flagLast = true;
						flag2 = false;
						flag = false;
					}
					else if (choice2 == 12) {
						cout << "Gorn:" << endl;
						cout << "1. Str" << endl;
						cout << "2. Dex" << endl;
						cout << "3. Int" << endl;
						cout << "4. HP" << endl;
						cout << "5. Max HP" << endl;
						cout << "6. Exp" << endl;
						cin >> choice4;

						while (flagLast) {
							if (choice4 == 1) {
								cout << "Please enter new stat for Strength (1-99)" << endl;
								cin >> input;
								memblock[0x000E + 0x180] = input;
								flagLast = false;
							}
							else if (choice4 == 2) {
								cout << "Please enter new stat for Dexterity (1-99)" << endl;
								cin >> input;
								memblock[0x000F + 0x180] = input;
								flagLast = false;
							}
							else if (choice4 == 3) {
								cout << "Please enter new stat for Intelligence (1-99)" << endl;
								cin >> input;
								memblock[0x0010 + 0x180] = input;
								flagLast = false;
							}
							else if (choice4 == 4) {
								cout << "Do something with HP" << endl;
								flagLast = false;
							}
							else if (choice4 == 5) {
								cout << "Do something with Max HP" << endl;
								flagLast = false;
							}
							else if (choice4 == 6) {
								cout << "Do something with Exp" << endl;
								flagLast = false;
							}
							else {
								cout << "Incorrect input, please try again" << endl;
								cout << "1. Str" << endl;
								cout << "2. Dex" << endl;
								cout << "3. Int" << endl;
								cout << "4. HP" << endl;
								cout << "5. Max HP" << endl;
								cout << "6. Exp" << endl;
								cin >> choice4;
							}
						}
						flagLast = true;
						flag2 = false;
						flag = false;
					}
					else if (choice2 == 13) {
						cout << "Maxwell:" << endl;
						cout << "1. Str" << endl;
						cout << "2. Dex" << endl;
						cout << "3. Int" << endl;
						cout << "4. HP" << endl;
						cout << "5. Max HP" << endl;
						cout << "6. Exp" << endl;
						cin >> choice4;

						while (flagLast) {
							if (choice4 == 1) {
								cout << "Please enter new stat for Strength (1-99)" << endl;
								cin >> input;
								memblock[0x000E + 0x1A0] = input;
								flagLast = false;
							}
							else if (choice4 == 2) {
								cout << "Please enter new stat for Dexterity (1-99)" << endl;
								cin >> input;
								memblock[0x000F + 0x1A0] = input;
								flagLast = false;
							}
							else if (choice4 == 3) {
								cout << "Please enter new stat for Intelligence (1-99)" << endl;
								cin >> input;
								memblock[0x0010 + 0x1A0] = input;
								flagLast = false;
							}
							else if (choice4 == 4) {
								cout << "Do something with HP" << endl;
								flagLast = false;
							}
							else if (choice4 == 5) {
								cout << "Do something with Max HP" << endl;
								flagLast = false;
							}
							else if (choice4 == 6) {
								cout << "Do something with Exp" << endl;
								flagLast = false;
							}
							else {
								cout << "Incorrect input, please try again" << endl;
								cout << "1. Str" << endl;
								cout << "2. Dex" << endl;
								cout << "3. Int" << endl;
								cout << "4. HP" << endl;
								cout << "5. Max HP" << endl;
								cout << "6. Exp" << endl;
								cin >> choice4;
							}
						}
						flagLast = true;
						flag2 = false;
						flag = false;
					}
					else if (choice2 == 14) {
						cout << "Toshi:" << endl;
						cout << "1. Str" << endl;
						cout << "2. Dex" << endl;
						cout << "3. Int" << endl;
						cout << "4. HP" << endl;
						cout << "5. Max HP" << endl;
						cout << "6. Exp" << endl;
						cin >> choice4;

						while (flagLast) {
							if (choice4 == 1) {
								cout << "Please enter new stat for Strength (1-99)" << endl;
								cin >> input;
								memblock[0x000E + 0x1C0] = input;
								flagLast = false;
							}
							else if (choice4 == 2) {
								cout << "Please enter new stat for Dexterity (1-99)" << endl;
								cin >> input;
								memblock[0x000F + 0x1C0] = input;
								flagLast = false;
							}
							else if (choice4 == 3) {
								cout << "Please enter new stat for Intelligence (1-99)" << endl;
								cin >> input;
								memblock[0x0010 + 0x1C0] = input;
								flagLast = false;
							}
							else if (choice4 == 4) {
								cout << "Do something with HP" << endl;
								flagLast = false;
							}
							else if (choice4 == 5) {
								cout << "Do something with Max HP" << endl;
								flagLast = false;
							}
							else if (choice4 == 6) {
								cout << "Do something with Exp" << endl;
								flagLast = false;
							}
							else {
								cout << "Incorrect input, please try again" << endl;
								cout << "1. Str" << endl;
								cout << "2. Dex" << endl;
								cout << "3. Int" << endl;
								cout << "4. HP" << endl;
								cout << "5. Max HP" << endl;
								cout << "6. Exp" << endl;
								cin >> choice4;
							}
						}
						flagLast = true;
						flag2 = false;
						flag = false;
					}
					else if (choice2 == 15) {
						cout << "Saduj:" << endl;
						cout << "1. Str" << endl;
						cout << "2. Dex" << endl;
						cout << "3. Int" << endl;
						cout << "4. HP" << endl;
						cout << "5. Max HP" << endl;
						cout << "6. Exp" << endl;
						cin >> choice4;

						while (flagLast) {
							if (choice4 == 1) {
								cout << "Please enter new stat for Strength (1-99)" << endl;
								cin >> input;
								memblock[0x000E + 0x1E0] = input;
								flagLast = false;
							}
							else if (choice4 == 2) {
								cout << "Please enter new stat for Dexterity (1-99)" << endl;
								cin >> input;
								memblock[0x000F + 0x1E0] = input;
								flagLast = false;
							}
							else if (choice4 == 3) {
								cout << "Please enter new stat for Intelligence (1-99)" << endl;
								cin >> input;
								memblock[0x0010 + 0x1E0] = input;
								flagLast = false;
							}
							else if (choice4 == 4) {
								cout << "Do something with HP" << endl;
								flagLast = false;
							}
							else if (choice4 == 5) {
								cout << "Do something with Max HP" << endl;
								flagLast = false;
							}
							else if (choice4 == 6) {
								cout << "Do something with Exp" << endl;
								flagLast = false;
							}
							else {
								cout << "Incorrect input, please try again" << endl;
								cout << "1. Str" << endl;
								cout << "2. Dex" << endl;
								cout << "3. Int" << endl;
								cout << "4. HP" << endl;
								cout << "5. Max HP" << endl;
								cout << "6. Exp" << endl;
								cin >> choice4;
							}
						}
						flagLast = true;
						flag2 = false;
						flag = false;
					}
					else {
						cout << "That is not an availible choice, try again." << endl;
						cout << " 1. Shamino" << endl;
						cout << " 2. Iolo" << endl;
						cout << " 3. Mariah" << endl;
						cout << " 4. Geoffrey" << endl;
						cout << " 5. Jaana" << endl;
						cout << " 6. Julia" << endl;
						cout << " 7. Dupre" << endl;
						cout << " 8. Katrina" << endl;
						cout << " 9. Sentri" << endl;
						cout << "10. Gwenno" << endl;
						cout << "11. Johne" << endl;
						cout << "12. Gorn" << endl;
						cout << "13. Maxwell" << endl;
						cout << "14. Toshi" << endl;
						cout << "15. Saduj" << endl;
						cin >> choice2;
					}
				}
			}
			else if (choice == 3) {
				cout << "Which item do you want to change?" << endl;
				cout << "1. Gold" << endl;
				cout << "2. Keys" << endl;
				cout << "3. Skull Keys" << endl;
				cout << "4. Gems" << endl;
				cout << "5. Black Badge" << endl;
				cout << "6. Magic Carpets" << endl;
				cout << "7. Magic Axes" << endl;
				cin >> choice3;

				while (flag3) {
					if (choice3 == 1) {
						cout << "Do something with gold" << endl;
						flag3 = false;
						flag = false;
					}
					else if (choice3 == 2) {
						cout << "How many keys do you want? (0-99)" << endl;
						cin >> input;
						memblock[0x0206] = input;
						flag3 = false;
						flag = false;
					}
					else if (choice3 == 3) {
						cout << "How many skull keys do you want? (0-99)" << endl;
						cin >> input;
						memblock[0x020B] = input;
						flag3 = false;
						flag = false;
					}
					else if (choice3 == 4) {
						cout << "How many gems do you want? (0-99)" << endl;
						cin >> input;
						memblock[0x0207] = input;
						flag3 = false;
						flag = false;
					}
					else if (choice3 == 5) {
						cout << "Do you want to have the black badge? ('y' or 'no')" << endl;
						cin >> charChoice;
						while (flagLast) {
							if (charChoice == 'y') {
								memblock[0x0218] = 0xFF;
								flagLast = false;
							}
							else if (charChoice == 'n') {
								memblock[0x0218] = 0x0;
								flagLast = false;
							}
							else {
								cout << "incorrect input, please select 'y' or 'n'" << endl;
								cin >> charChoice;
							}
						}
						flagLast = true;
						flag3 = false;
						flag = false;
					}
					else if (choice3 == 6) {
						cout << "How many magic carpets do you want? (0-99)" << endl;
						cin >> input;
						memblock[0x020A] = input;
						flag3 = false;
						flag = false;
					}
					else if (choice3 == 7) {
						cout << "How many magic axes do you want? (0-99)" << endl;
						cin >> input;
						memblock[0x0240] = input;
						flag3 = false;
						flag = false;
					}
					else {
						cout << "That is not an availible choice, try again." << endl;
						cout << "1. Gold" << endl;
						cout << "2. Keys" << endl;
						cout << "3. Skull Keys" << endl;
						cout << "4. Gems" << endl;
						cout << "5. Black Badge" << endl;
						cout << "6. Magic Carpets" << endl;
						cout << "7. Magic Axes" << endl;
						cin >> choice3;
					}
				}
			}
			else {
				cout << "Please select 1, 2, or 3.  Try Again." << endl;
				cout << "1: Character" << endl;
				cout << "2: Allies" << endl;
				cout << "3: Items" << endl;
				cin >> choice;
			}
		}
		//-------------------------------------------------------------------------------------


		ofstream wfile("SAVED.GAM", ios::binary);
		if (wfile.is_open()) {

			wfile.write(memblock, size);
			wfile.close();
		}

		delete[] memblock;
	}
	else cout << "Unable to open file" << endl << endl;



	/*ofstream wfile("SAVED.GAM", ios::in | ios::binary | ios::ate);
	if (wfile.is_open()) {
		size = wfile.tellp();
		memblock = new char[size];
		wfile.seekp(0, ios::beg);

		cout << memblock[0x000E] << endl;
		memblock[0x000E] = 0x62;
		cout << memblock[0x000E] << endl;

		wfile.write(memblock, size);
		wfile.close();
		
		delete[] memblock;
	}
	else {
		cout << "Unable to open file" << endl;
	}*/


	getchar();
	getchar();
	return 0;
}