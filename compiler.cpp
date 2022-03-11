#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <bits/stdc++.h>
#include <windows.h>
#include "library.h"
#pragma execution_character_set( "utf-8" )
#define colWidth 15
using namespace std;

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
	string show(int i) const {
		return value[i];
	}
	~element() {
		value.clear();
	}
	int size() const {
		return value.size();
	}
};
int main()
{
	string line, word, Dict_word, File_word;
	vector <string> Dict_words, File_words;
	element keys("keys"), others("others"), numbers("numbers"), operators("operators"), strings("strings"), IDs("IDs");
	ifstream File("File.txt"); //* step 1 : reading file
	ifstream Dictionary("Dictionnaire.txt"); //* step 2 : linking Dictionary
	bool pushed = false;
	while(getline(Dictionary, Dict_word, '\n')) {
		Dict_words.push_back(Dict_word);
	}
	while(getline(File, File_word, ' ')) {
		File_words.push_back(File_word);
	}
	File.close();
	//* For loop to treat every word in file.txt ----------------------------------------->>
	for (int i = 0; i < File_words.size(); i++) {
		//* Keys Detection --------------------------------------------------------------->>
		for (int z = 0; z < Dict_words.size(); z++) {
			if (File_words[i].compare(Dict_words[z]) == 0) {
				keys.push(File_words[i]);
				pushed = true;
				break;
			}
		}
		//* Numbers Detection ------------------------------------------------------------>>
		if (isnumber(File_words[i]) and (not_a_space(File_words[i]) == true)) {
				numbers.push(File_words[i]);
				pushed = true;
		}
		if (!pushed and (not_a_space(File_words[i]) == true) and !exists(File_words[i], '\n')) {
			if(isID(File_words[i])) {
				IDs.push(File_words[i]);
				pushed = true;
			}
			else if(isstring(File_words[i])) {
				strings.push(File_words[i]);
				pushed = true;
			}
			else if(isoperator(File_words[i])) {
				operators.push(File_words[i]);
				pushed = true;
			}
			else if(!pushed){
				others.push(File_words[i]);
				pushed = true;
			}
		}
		pushed = false;
	}
	//* Console Output 
	cout << setfill('*') << setw(3*colWidth) << "*" << endl;
	cout << setfill(' ') << fixed;
	cout << setw(colWidth) << "mots" << setw(colWidth) << "valeur" << endl;
	cout << setfill('*') << setw(3*colWidth) << "*" << endl;
	cout << setfill(' ') << fixed;
	//* List 1 : IDs 
	for(int i = 0; i < IDs.size(); i++) {
		cout << setprecision(0) << setw(colWidth) << IDs.show(i) << setprecision(4) << 
		setw(colWidth)<< "ID" << endl;
	}
	//* List 2 : key words 
	for(int i = 0; i < keys.size(); i++) {
		cout << setprecision(0) << setw(colWidth) << keys.show(i) << setprecision(4) << 
		setw(colWidth)<< "mot cle" << endl;
	}
	//* List 3 : numbers 
	for(int i = 0; i < numbers.size(); i++) {
		cout << setprecision(0) << setw(colWidth) << numbers.show(i) << setprecision(4) << 
		setw(colWidth)<< "nombre" << endl;
	}
	//* List 4 : operators 
	for(int i = 0; i < operators.size(); i++) {
		cout << setprecision(0) << setw(colWidth) << operators.show(i) << setprecision(4) << 
		setw(colWidth)<< "operateur" << endl;
	}
	//* List 5 : strings 
	for(int i = 0; i < strings.size(); i++) {
		cout << setprecision(0) << setw(colWidth) << strings.show(i) << setprecision(4) << 
		setw(colWidth)<< "chaine" << endl;
	}
	//* List 6 : unidentified 
	for(int i = 0; i < others.size(); i++) {
		cout << setprecision(0) << setw(colWidth) << others.show(i) << setprecision(4) << 
		setw(colWidth)<< "autres" << endl;
	}
  	return 0;
}