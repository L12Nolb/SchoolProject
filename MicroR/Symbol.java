// Symbol enumeration definition
// Symbol is an enumeration to represent lexical token classes in the MicroR.
//Author: Suzanne Nolba

public enum Symbol {
  EOF, 
  // punctuation
  PERIOD, COMMA, SEMICOLON, 
  // operators
  ASSIGN, EQ, NE, LT, GT, LE, GE, PLUS, MINUS, TIMES, SLASH, LPAREN, RPAREN, LCPAREN, RCPAREN, ANDCOMP,
  // keywords
  BEGIN, CALL, CONST, DO, END, IF, ODD, PROC, THEN, VAR, WHILE, SOURCE, STRING, FUNC, MAIN, ELSE, PRINT,ASINT, READLINE, CONS, HEAD, TAIL, NULL,
  // ids and integers
  ID, INTEGER, IDE,
  // special character
COMMENTS, RELOPE,QUOTE
  
}
