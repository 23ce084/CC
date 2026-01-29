#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

int index_pos;
string input;
int valid = 1;
void S();
void L();
void L_prime();
void match(char c);
void match(char c) {
    if (index_pos < input.length() && input[index_pos] == c) {
        index_pos++; 
    } else {
        valid = 0;
    }
}
void S() {
    if (index_pos < input.length()) {
        if (input[index_pos] == '(') {
            match('(');
            L();
            match(')');
        } else if (input[index_pos] == 'a') {
            match('a');
        } else {
            valid = 0;
        }
    } else {
        valid = 0;
    }
}
void L() {
    S();
    L_prime();
}
void L_prime() {
    if (index_pos < input.length() && input[index_pos] == ',') {
        match(',');
        S();
        L_prime();
    }
}

int main() {
    cout << "Enter string: ";
    getline(cin, input);
    
    index_pos = 0;
    valid = 1;
    S();
    
    if (valid && index_pos == input.length()) {
        cout << "Valid string" << endl;
    } else {
        cout << "Invalid string" << endl;
    }
    return 0;
}