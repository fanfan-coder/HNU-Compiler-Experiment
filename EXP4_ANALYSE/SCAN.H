#ifndef SCAN_H_INCLUDED
#define SCAN_H_INCLUDED
#include <bits/stdc++.h>
#define MAXRESERVED 1024
#define MAXTOKENLEN 40 /* MAXTOKENLEN is the maximum size of a token */
using namespace std;

extern bool EOFFlag; /* corrects retract behavior on EOF */
extern string tokenString; /* tokenString array stores the lexeme of each token */
extern int lineno; /* source line number for listing */
enum TokenType /* book-keeping tokens */
{
    ENDFILE, ERROR,
    IF, THEN, ELSE, END, REPEAT, UNTIL, READ, WRITE, /* reserved words */
    ID, NUM, /* multicharacter tokens */
    ASSIGN, EQ, LT, PLUS, MINUS, TIMES, OVER, LPAREN, RPAREN, SEMI /* special symbols */
};
TokenType getToken(void); /* function getToken returns the next token in source file */
bool isAlpha(char);
bool isDigit(char);
bool isWhiteSpace(char);
bool getLine(string&);
char getNextChar();
void retract();
TokenType reservedLookUp(string);
string getTokenString(TokenType);


#endif
