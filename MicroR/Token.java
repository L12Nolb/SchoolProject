// Token class definition
// Token is a class to represent lexical tokens in the in the MicroR programming 
// Author: Suzanne Nolba

public class Token{
	
	private Symbol symbol;  //current token
	private String lexeme;	//lexeme
	
	public Token(){ }
	
	public Token (Symbol symbol){
		this (symbol, null);
	}
	
	public Token (Symbol symbol, String lexeme){
		this.symbol = symbol;
		this.lexeme = lexeme;
	}
	
	public Symbol symbol () { return symbol; }
	
	public String lexeme () { return lexeme; }
	
	public String toString () {
		switch (symbol) {
			case PERIOD :    return "(punctuation, .) ";
			case COMMA :     return "(punctuation, ,) ";
			case SEMICOLON : return "(punctuation, ;) ";
			case ASSIGN :    return "(operator, :=) ";
			case EQ :        return "(operator, =) ";
			case NE :        return "(operator, !=) ";
			case LT :        return "(operator, <) ";
			case GT :        return "(operator, >) ";
			case LE :        return "(operator, <=) ";
			case GE :        return "(operator, >=) ";
			case PLUS :      return "(operator, +) ";
			case MINUS :     return "(operator, -) ";
			case TIMES :     return "(operator, *) ";
			case SLASH :     return "(operator, /) ";
			case LPAREN :    return "(operator, () ";
			case RPAREN :    return "(operator, )) ";
			case ANDCOMP :    return "(operator, &&) ";
			case LCPAREN :    return "(punctuation, {) ";
			case RCPAREN :    return "(punctuation, }) ";
			case RELOPE :    return "(operator, !) ";
			case BEGIN :     return "(keyword, begin) ";
			case SOURCE :    return "(keyword, source) ";
			case FUNC :    return "(keyword, function) ";
			case MAIN :    return "(keyword, main) ";
			case ELSE :    return "(keyword, else) ";
			case PRINT :    return "(keyword, print) ";
			case TAIL:      return "(keyword, tail) ";
			case NULL :    return "(keyword, null) ";
			case HEAD :    return "(keyword, head) ";
			case CONS :    return "(keyword, cons) ";
			case READLINE :    return "(keyword, readline) ";
			case ASINT :    return "(keyword, as.integer) ";
			case STRING :   return "(string, \"List.R\") ";
			case CALL :      return "(keyword, call) ";
			case CONST :     return "(keyword, const) ";
			case DO :        return "(keyword, do) ";
			case END :       return "(keyword, end) ";
			case IF :        return "(keyword, if) ";
			case ODD :       return "(keyword, odd) ";
			case PROC :      return "(keyword, proc) ";
			case THEN :      return "(keyword, then) ";
			case VAR :       return "(keyword, var) ";
			case WHILE :     return "(keyword, while) ";
			case ID :        return "(identifier, " + lexeme + ") ";
			case IDE :        return "(identifier, " + lexeme + ") ";
			case INTEGER :   return "(integer, " + lexeme + ") ";
			default : 
		
	ErrorMessage . print (0, "Unrecognized token");
				return null;
		}
	}
}