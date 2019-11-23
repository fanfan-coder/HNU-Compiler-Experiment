#include <bits/stdc++.h>
#include "scan.h"
#define MAXTOKENLEN 40
#define BUFLEN 256
#define MAXRESERVED 1024
#define reservedTableSize 8
using namespace std;
struct TableUnit
{
    string str;
    TokenType tok;
};/* lookup table of reserved words */
TableUnit reservedWords[MAXRESERVED] =
{
    {"else", ELSE}, {"end", END},
    {"if", IF}, {"read", READ},
    {"repeat", REPEAT}, {"then", THEN},
    {"until", UNTIL}, {"write", WRITE}
};
enum StateType {START, INASSIGN, INCOMMENT, INNUM, INID, DONE}; /* DFA states */
int lineno;
string tokenString;
string lineBuf; /* holds the current line */
int linePos = 0; /* current position in lineBuf */
int bufSize = 0; /* current size of buffer string */
bool EOFFlag = 0; /* corrects retract behavior on EOF */
void printToken(TokenType token, string s);

inline bool isAlpha(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

inline bool isDigit(char c)
{
    return (c >= '0' && c <= '9');
}

inline bool isWhiteSpace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

bool getLine(string& s)
{
    char c;
    while((c = cin.get()) != '\n' && c != EOF) s += c;
    if(c == EOF) return 0;
    if(c == '\n') s += c;
    return 1;
}

char getNextChar()
{
    if(linePos < bufSize)
        return lineBuf[linePos++];
    else
    {
        ++lineno;
        lineBuf.clear();
        if(getLine(lineBuf))
        {
            bufSize = lineBuf.length();
            linePos = 0;
            //cout << setiosflags(ios::left) << setw(2) << lineno << ':';
            //cout << lineBuf;
            return lineBuf[linePos++];
        }
        else
        {
            EOFFlag = 1;
            return EOF;
        }
    }
}

inline void retract()
{
    if(!EOFFlag)
        --linePos;
}

TokenType reservedLookUp(string s)
{
    int l = 0, r = reservedTableSize;
    while(l < r)
    {
        int m = l + ((r - l) >> 1);
        if(s < reservedWords[m].str)
            r = m;
        else if(s > reservedWords[m].str)
            l = m+1;
        else
            return reservedWords[m].tok;
    }
    return ID;
}

TokenType getToken()
{
    TokenType token; /* holds current token to be returned */
    StateType state = START; /* current state - always begins at START */
    bool saveFlag; /* flag to indicate save to tokenString */
    char c; /* temporary to save a char */
    tokenString.clear();

    while(state != DONE)
    {
        c = getNextChar();
        saveFlag = 1;
        switch(state)
        {
            case START:
                if(isDigit(c))
                    state = INNUM;
                else if(isAlpha(c))
                    state = INID;
                else if(c == ':')
                    state = INASSIGN;
                else if(isWhiteSpace(c))
                    saveFlag = 0;
                else if(c == '{')
                    saveFlag = 0, state = INCOMMENT;
                else
                {
                    state = DONE;
                    switch(c)
                    {
                        case EOF:
                            saveFlag = 0;
                            token = ENDFILE;
                            break;
                        case '+':
                            token = PLUS;
                            break;
                        case '-':
                            token = MINUS;
                            break;
                        case '*':
                            token = TIMES;
                            break;
                        case '/':
                            token = OVER;
                            break;
                        case '=':
                            token = EQ;
                            break;
                        case '<':
                            token = LT;
                            break;
                        case '(':
                            token = LPAREN;
                            break;
                        case ')':
                            token = RPAREN;
                            break;
                        case ';':
                            token = SEMI;
                            break;
                        default:
                            token = ERROR;
                            break;
                    }
                }
                break;
            case INNUM:
                if(!isDigit(c))
                {
                    retract();
                    saveFlag = 0;
                    state = DONE;
                    token = NUM;
                }
                break;
            case INID:
                if(!isAlpha(c))
                {
                    retract();
                    saveFlag = 0;
                    state = DONE;
                    token = ID;
                }
                break;
            case INASSIGN:
                state = DONE;
                if(c == '=')
                    token = ASSIGN;
                else
                {
                    retract();
                    saveFlag = 0;
                    token = ERROR;
                }
                break;
            case INCOMMENT:
                saveFlag = 0;
                if(c == EOF)
                {
                    state = DONE;
                    token = ENDFILE;
                }
                else if(c == '}')
                    state = START;
                break;
            case DONE:
            default:
                cout << "Scanner Error @StateType: " << state << endl;
                state = DONE;
                token = ERROR;
                break;
        }
        if(saveFlag)
            tokenString += c;
    }

    if(state == DONE && token == ID)
        token = reservedLookUp(tokenString);
    //cout << "    " << lineno << ": ";
    //printToken(token, tokenString);
    return token;
}

string getTokenString(TokenType token)
{
    switch (token)
    {
        case IF: return "IF";
        case THEN: return "THEN";
        case ELSE: return "ELSE";
        case END: return "END";
        case REPEAT: return "REPEAT";
        case UNTIL: return "UNTIL";
        case READ: return "READ";
        case WRITE: return "WRITE";
        case ENDFILE: return "ENDFILE";
        case PLUS: return "PLUS";
        case MINUS: return "MINUS";
        case TIMES: return "TIMES";
        case OVER: return "OVER";
        case ASSIGN: return "ASSIGN";
        case LT: return "LT";
        case EQ: return "EQ";
        case LPAREN: return "LPAREN";
        case RPAREN: return "RPAREN";
        case SEMI: return "SEMI";
        case NUM: return "NUM";
        case ID: return "ID";
        case ERROR: return "ERROR";
        default: return "UNKNOWN TOKEN";
    }
}
