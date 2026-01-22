#include <iostream>
        #include <cctype>
        #include <string>
        using namespace std;

        
        bool isPunctuation(char ch) {
            return ch == '(' || ch == ')' || ch == '{' || ch == '}' ||
                ch == ';' || ch == ',';
        }

        
        bool isOperator(char ch) {
            return ch == '+' || ch == '-' || ch == '*' ||
                ch == '/' || ch == '=';
        }

        bool isKeyword(const string& str) {
            string keywords[] = {"int", "char", "return", "float", "double"};
            for (string k : keywords)
                if (str == k)
                    return true;
            return false;
        }

        bool isIdentifier(const string& str) {
            if (!isalpha(str[0]) && str[0] != '_')
                return false;

            for (char ch : str)
                if (!isalnum(ch) && ch != '_')
                    return false;

            return true;
        }

        void lexicalAnalyzer(const string& input) {
            int i = 0;
            int n = input.length();

            cout << "TOKENS\n";

            while (i < n) {

                if (isspace(input[i])) {
                    i++;
                    continue;
                }

                if (isalpha(input[i])) {
                    string word = "";
                    while (i < n && isalnum(input[i])) {
                        word += input[i++];
                    }

                    if (isKeyword(word))
                        cout << "Keyword: " << word << endl;
                    else
                        cout << "Identifier: " << word << endl;
                }

                else if (isdigit(input[i])) {
                    string num = "";
                    while (i < n && isdigit(input[i])) {
                        num += input[i++];
                    }
                    cout << "Constant: " << num << endl;
                }

                else if (input[i] == '\'') {
                    cout << "Constant: '" << input[i + 1] << "'" << endl;
                    i += 3;
                }

                else if (isOperator(input[i])) {
                    cout << "Operator: " << input[i] << endl;
                    i++;
                }

                else if (isPunctuation(input[i])) {
                    cout << "Punctuation: " << input[i] << endl;
                    i++;
                }

                else {
                    i++;
                }
            }
        }
            int main() {
            string input;
            getline(cin, input);   
            lexicalAnalyzer(input);
            return 0;
        }