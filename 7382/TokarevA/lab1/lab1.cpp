#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

bool round(string str);

int deep = 0, iter = 0, round_in=0;

bool brackets(string str) { //beginning of recursion
	deep++;
	cout << "In function brackets. Deep = " << deep << endl;
	while (str[iter]) {
		if (str[iter] == '(') {
			iter++;
			return round(str); //enter to the second recursion
		}
		else if ((str[iter] == 'A') || (str[iter] == 'B')) {
			iter++;
			return brackets(str);
		}
		else if (str[iter] == ')' && round_in>0) {
			iter++;
			return brackets(str);
		}
		else
			return false; //exit when wrong symbol is encountered
	}
	return true; //exit when all symbols are checked
}

bool round(string str) { //second recursion
	deep++;
	cout << "In function round. Deep = " << deep << endl;
	round_in++; //this var marked how many ')' should we meet at the exit of the second recursion 
	if (str[iter] == '(') {
		iter++;
		return round(str);
	}
	else if (str[iter] == 'A' || str[iter] == 'B') {
		if ((str[iter + 1] == 'A' || str[iter + 1] == 'B') && str[iter + 2] == ')') {
			iter += 3;
			round_in--;
			return brackets(str); //exit from the second recursion when nested brackets are ended
		}
		if (str[iter + 1] == '(') {
			iter+=2;
			return round(str);
		}
		return false; //exit when the wrong symbol is encountered after 'A'||'B'
	}
	else
		return false; //exit when the wrong symbol is encountered after '('
}

int main() {
	string str;
	cout << "Input your string: " << endl;
    getline(cin, str);
	if (!brackets(str)) {
		cout << "These aren't brackets" << endl; //brackets = false
		return 0;
	}
	cout << "These are brackets" << endl; //brackets = true
	return 0;
}



