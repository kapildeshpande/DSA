#include<iostream>
#include<stack>
using namespace std;

bool is_operand(char c) {
	int k = (int) c;
	if ( k >= 'A' && k <= 'Z'
	|| k>= 'a' && k<= 'z') return 1;
	return 0;
}

int is_operator (char c ) {
	if (c==')'||c=='(') return 4;
	else if (c == '^') return 3;
	else if (c=='*'||c=='/') return 2;
	else if (c=='+'||c=='-') return 1;
	return 0;
}

string infix_to_postfix(string s) {
	stack <char> st;
	string s2;
	for (int i=0;i<s.size();i++) {
		if ( is_operand(s[i])) {
			s2 += s[i];
		}
		else {
			if (st.empty()) st.push(s[i]);
			else  {
			int a = is_operator(s[i]);
			if (s[i]==')') {
				while (st.top()!='(') {
					s2 += st.top();
					st.pop();
				}
				st.pop();
			}
			else if (is_operator(st.top()) < a ||st.top()=='(')st.push(s[i]);
			else {
				s2 += st.top();
				st.pop();
				st.push(s[i]);
			}
	        }
		}
	}
	while (!st.empty()) {
		s2 += st.top();
		st.pop(); 
	}
	return s2;
}

int main () {
	string s;
	cout<<"Enter Infix expression\n";
	getline (cin,s);
	cout<<"Postfix expression \n"<<infix_to_postfix(s);
	
}
