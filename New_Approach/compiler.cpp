#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <bits/stdc++.h>
#include <windows.h>
#include <algorithm>
#include "library.h"
#pragma execution_character_set( "utf-8" )
#define colWidth 15
using namespace std;
//* OOP aproach for easy debugging
class element {
	vector <string> value;
	string name;
	public :
	element(string name) : name(name) {
		cout << name <<" element created" << endl;
	}
	void push(const string& str) {
		value.push_back(str);
		cout << str << " pushed to " << name << endl;
	}
	string operator [](int i) const {
		return value[i];
	}
	int size() const {
		return value.size();
	}
	~element() {
		value.clear();
	}
};
int main()
{
    std::stringstream ss;
	string line, word, Dict_word, File_pack, Pack_word, temp, ID_temp;
	vector <string> Dict_words, Pack_words, File_packs;
    vector <char> File_pack_chars;
	element	errors("errors"), keys("keys"), others("others"), numbers("numbers"), 
			operators("operators"), strings("strings"), IDs("IDs");
	ifstream File("File.txt"); //* step 1 : reading file
	ifstream Dictionary("Dictionnaire.txt"); //* step 2 : linking Dictionary
	bool pushed_key = false, record = false;
    int pushed_chars = 0;
	while(getline(Dictionary, Dict_word, '\n')) {
		Dict_words.push_back(Dict_word);
	}
	while(getline(File, File_pack, ';')) {
		File_packs.push_back(File_pack);
        //cout << File_pack << endl;
	}
	File.close();
	//* For loop to treat every pack in file.txt
	for(int i = 0; i < File_packs.size(); i++) { //* all File lines till their ; (pack)
        //cout << File_packs[i] << ':' << endl;
        for(int j = 0; j < File_packs[i].size() ;j++) { //* every pack in packs
            //cout << File_packs[i][j] << endl;
			if(File_packs[i][j] == '='){
				record = false;
				if(isID(ID_temp)) {
					IDs.push(ID_temp);
				}
				temp.clear();
			}
			File_pack_chars.push_back(File_packs[i][j]);
			temp.push_back(File_packs[i][j]);
			if(record) {
				ID_temp.push_back(File_packs[i][j]);
			}
			for (int z = 0; z < Dict_words.size(); z++) {
				if (temp.compare(Dict_words[z]) == 0) {
					keys.push(temp);
					pushed_key = true;
					record = true;
					temp.clear();
					break;
				}
			}
			if(is_a_space(File_packs[i][j])) {
				temp.clear();
				cout << "cleared temp" << endl;
				if(pushed_key)
					record = true;
			}
        }
    }
	//* Console Output
	cout << setfill('*') << setw(3*colWidth) << "*" << endl;
	cout << setfill(' ') << fixed;
	cout << setw(colWidth) << "mots" << setw(colWidth) << "valeur" << endl;
	cout << setfill('*') << setw(3*colWidth) << "*" << endl;
	cout << setfill(' ') << fixed;
	//* List 1 : IDs
	for(int i = 0; i < IDs.size(); i++) {
		cout << setprecision(0) << setw(colWidth) << IDs[i] << setprecision(4) << 
		setw(colWidth)<< "ID" << endl;
	}
	//* List 2 : key words
	for(int i = 0; i < keys.size(); i++) {
		cout << setprecision(0) << setw(colWidth) << keys[i] << setprecision(4) << 
		setw(colWidth)<< "mot cle" << endl;
	}
	//* List 3 : numbers
	for(int i = 0; i < numbers.size(); i++) {
		cout << setprecision(0) << setw(colWidth) << numbers[i] << setprecision(4) << 
		setw(colWidth)<< "nombre" << endl;
	}
	//* List 4 : operators
	for(int i = 0; i < operators.size(); i++) {
		cout << setprecision(0) << setw(colWidth) << operators[i] << setprecision(4) << 
		setw(colWidth)<< "operateur" << endl;
	}
	//* List 5 : strings
	for(int i = 0; i < strings.size(); i++) {
		cout << setprecision(0) << setw(colWidth) << strings[i] << setprecision(4) << 
		setw(colWidth)<< "chaine" << endl;
	}
	//* List 6 : unidentified
	for(int i = 0; i < others.size(); i++) {
		cout << setprecision(0) << setw(colWidth) << others[i] << setprecision(4) << 
		setw(colWidth)<< "autres" << endl;
	}
  	return 0;
}