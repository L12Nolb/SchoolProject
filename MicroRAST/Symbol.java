// Symbol enumeration definition
// Symbol is an enumeration to represent lexical token classes in the MicroR.
//Author: Suzanne Nolba

public enum Symbol {
  EOF, 
  // punctuation
  COMMA, SEMICOLON, LBRACE, RBRACE, 
  // operators
  ASSIGN, AND, OR, NOT, LT, LE, GT, GE, EQ, NE, PLUS, MINUS, TIMES, SLASH, 
  LPAREN, RPAREN, RELOPE,
  // keywords
  ASINTEGER, CONS, ELSE, FUNCTION, HEAD, IF, MAIN, NULL, PRINT, READLINE, 
  RETURN, SOURCE, TAIL, WHILE,
  // "List.R" string
  LISTR,
  // ids and integers
  ID, INTEGER
}