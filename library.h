#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

//* returns length of a string
int len(const string& str)
{
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++) {  
        length++;
    }
    return length;
}
//* returns true if strings in parametres are the same
bool compare(const string &s1, const string &s2) {
	int count = 0;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] == s2[i])
			count++;
	}
	if (count == s1.size())
		return true;
	else
		return false;
}
//* returns if the charactere in param exists in string
bool exists(const string& string, char c) {
	bool exists;
	for (int i = 0; i < string.size(); i++) {
		if (string[i] == c)
			exists = true;
	}
	if (exists) 
		return true;
	else
		return false;
}

//* NOT USED : splits a string into words
string split(const string &chaine) {
	char str[100], *ptr;
	string result;
	for(int i = 0; i <= len(chaine); i++) {
		str[i] = chaine[i];
	}
	ptr = strtok(str, " ");
	cout << str << endl;
	for(int i = 0; i <= len(ptr); i++) {
		result[i] = ptr[i];
		cout << ptr[1];
		break;
	}
	return result;
}
//* checks if a string is an operator
bool isoperator(const string& s) {
	vector <string> operators = {"*", "=", "==", "+", "-", "/", "%", "!", "#", "<", ">", "!="};
    for( int i = 0; i < operators.size(); i++) {
        if (s == operators[i])
            return true;
    }
    return false;
}
bool isstring(const string& str) {
	int count = 0;
	for (char const &c : str) {
		if(c == '"')
			count++;
	}
	if(count == 2)
		return true;
    else 
        return false;
}
bool isnumber(const string& str) {
    int count = 0;
	for (char const &c : str) {
        if (!isdigit(c) and c != '.') {
			return false;
        }
        if (c == '.')
                count++;
    }
    if(count > 1)
        return false;
    return true;
}
bool not_a_space(const string& str)
{
    char* token = strtok(const_cast<char*>(str.c_str()), " ");

    while (token != NULL)
    {   
        if (*token != ' ')
        {   
            return true;
        }   
    }   
    return false;
}

bool isID(const string& str) {
    for(auto c : str) {
        if (static_cast<unsigned char>(c) < 64 or static_cast<unsigned char>(c) > 90 ) {
            if (static_cast<unsigned char>(c) < 97 or static_cast<unsigned char>(c) > 122) {
                if (static_cast<unsigned char>(c) != 95)
                    return false;
            }
        }
    }
    if(isdigit(str[0]) == true)
        return false;
    return true;
}