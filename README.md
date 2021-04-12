# LEXICAL-ANALYZER-PARSER
Lexical analysis is the first phase of converting a high level PL to a machine language. Lexical analyzer reads the given characters from our source code and tokenize them to check the tokens’ / lexemes’ types and validity. In this part of your homework you are asked to implement a simple lexical analyzer/parser of your own. Please note that YOU DO NOT HAVE TO CHECK THE WHOLE SYNTAX AND LOGIC VALIDITY. I.e. do not try to check the order corrections, e.g. a + b = c and so on. Keep the idea simple and check the tokens / lexemes only.

You should check:
- Delimeters: ‘ ‘, ‘{‘, ‘}’, ‘[‘, ‘]’, ‘(‘, ‘)’
- Operators: +, -, *, /, >,<,=
- Keywords: if, else, do, while, break, continue, switch, case, short, int, long, double, float, char, return, void, NULL, struct
- Integer numbers
- Real numbers
- Valid identifiers
- Rule: An identifier cannot start with a digit
![image](https://user-images.githubusercontent.com/64929089/114410222-de8a7800-9bb3-11eb-8251-c2ab4a1e3958.png)
