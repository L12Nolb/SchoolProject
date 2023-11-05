// this class represents a recursive descent parser for the
//MicroR programming language.
//Author: Suzanne Nolba
import java.io.*;
import java.beans.*;

public class SyntaxAnalyzer {
	protected MicroRLexer lexer; //lexical analyzer
	protected Token token; //current token
	
	public SyntaxAnalyzer () throws IOException{
		lexer = new MicroRLexer (new InputStreamReader (System . in));
		getToken();
	}
	private void getToken () throws IOException{
		token = lexer. nextToken();
	}
	public void FunctionDef () throws IOException{
		if(token.symbol()== Symbol.ASSIGN){
			getToken();
				if(token.symbol() == Symbol.FUNCTION){
					getToken();
					if(token.symbol() == Symbol.LPAREN){
						getToken();
						if(token.symbol() == Symbol.ID){
							getToken();
							while(token.symbol() == Symbol.COMMA){
								getToken();
								if(token.symbol() == Symbol.ID){
									getToken();
								}
								else{
									ErrorMessage.print(lexer.position(), "IDENTIFIER EXPECTED");	
								}
							}
						}
						if(token.symbol()== Symbol.RPAREN){
							getToken();
							if(token.symbol() == Symbol.LBRACE){
								getToken();
								while(token.symbol() == Symbol.IF || token.symbol()==Symbol.WHILE || token.symbol()==Symbol.ID || token.symbol()==Symbol.PRINT){
									Statement();
								}
								if(token.symbol()==Symbol.RETURN){
									getToken();
									if(token.symbol()==Symbol.LPAREN){
										getToken();
											Expr();
											if(token.symbol()==Symbol.RPAREN){
												getToken();
												if(token.symbol()== Symbol.SEMICOLON){
													getToken();
													if(token.symbol()== Symbol.RBRACE){
														getToken();
													}
													else{
														ErrorMessage.print(lexer.position(), "} EXPECTED");
													}
												}
												else {
													ErrorMessage.print(lexer.position(), "; EXPECTED");
												}
											}
											else{
												ErrorMessage.print(lexer.position(), ") EXPECTED");
											}
										}
									else{
										ErrorMessage.print(lexer.position(), "( EXPECTED");
									}
								}
								else{
									ErrorMessage.print(lexer.position(), "return EXPECTED");
								}
							}
							else{
								ErrorMessage.print(lexer.position(), "{EXPECTED");
							}
						}
						else{
							ErrorMessage.print(lexer.position(), ")EXPECTED");
						}
					}
					else{
						ErrorMessage.print(lexer.position(), "( EXPECTED");
					}
				}
				else{
					ErrorMessage.print(lexer.position(), "function EXPECTED");
				}
			}
			else{
				ErrorMessage.print(lexer.position(), " <- EXPECTED");
			}
	}
	
	public void MainDef () throws IOException{
		if(token.symbol() == Symbol.MAIN){
			getToken();
			if(token.symbol() == Symbol.ASSIGN){
				getToken();
					if(token.symbol() == Symbol.FUNCTION){
						getToken();
						if(token.symbol() == Symbol.LPAREN){
							getToken();
							if(token.symbol() == Symbol.RPAREN){
								getToken();
								if(token.symbol() == Symbol.LBRACE){
									getToken();
									StatementList();
									if(token.symbol() == Symbol.RBRACE){
										getToken();
									}
									else{
										ErrorMessage.print(lexer.position(), "} EXPECTED");
									}
								}
								else {
									ErrorMessage.print(lexer.position(), " {EXPECTED");
								}
							}
							else{
								ErrorMessage.print(lexer.position(), ") EXPECTED");}
						}
						else{
							ErrorMessage.print(lexer.position(), "( EXPECTED");}
					}
					else{
						ErrorMessage.print(lexer.position(), "function EXPECTED");}
				}
				else {ErrorMessage.print(lexer.position(), " <- EXPECTED");}
			}
		else{ ErrorMessage.print(lexer.position(), "\"MAIN\" EXPECTED");
		}
	}
	public void StatementList () throws IOException{
		if(token.symbol()== Symbol.IF|| token.symbol()==Symbol.WHILE || token.symbol()==Symbol.ID || token.symbol()==Symbol.PRINT){
			Statement();
		}
		else{
			ErrorMessage.print(lexer.position(), "conditional statement EXPECTED");
		}
		while(token.symbol()== Symbol.IF || token.symbol()==Symbol.WHILE || token.symbol()==Symbol.ID || token.symbol()==Symbol.PRINT){
			Statement();
		}
	}
	public void Statement () throws IOException{
		switch(token.symbol()){
			case IF:
			getToken();
			if(token.symbol()==Symbol.LPAREN){
				getToken();
				Cond();
				if( token.symbol()==Symbol.RPAREN){
					getToken();
					if(token.symbol()==Symbol.LBRACE){
						getToken();
						StatementList();
						if(token.symbol() == Symbol.RBRACE){
							getToken();
							if(token.symbol() == Symbol.ELSE){
								getToken();
								if(token.symbol()==Symbol.LBRACE){
									getToken();
									StatementList();
									if(token.symbol() == Symbol.RBRACE){
										getToken();
									}
									else {
										ErrorMessage.print(lexer.position(), "} EXPECTED");
									}
								}
								else {
									ErrorMessage.print(lexer.position(), "{ EXPECTED");
								}
							}
							
							}
						else{
							ErrorMessage.print(lexer.position(), "} EXPECTED");
						}
					}
					else {
						ErrorMessage.print(lexer.position(), "{ EXPECTED");
					}
				}
				else {
					ErrorMessage.print(lexer.position(), ") EXPECTED");
				}
			}
			else{
				ErrorMessage.print(lexer.position(), "( EXPECTED");
			}
				break;
			
			case WHILE:
			 getToken();
			 if(token.symbol()==Symbol.LPAREN){
				getToken();
				Cond();
				if(token.symbol()==Symbol.RPAREN){
					getToken();
					if(token.symbol()== Symbol.LBRACE){
						getToken();
						StatementList();
						if(token.symbol()== Symbol.RBRACE){
							getToken();
						}
						else {
							ErrorMessage.print(lexer.position(), "} EXPECTED");
						}
					}
					else{
						ErrorMessage.print(lexer.position(), "} EXPECTED");
					}
				}
				else {
					ErrorMessage.print(lexer.position(), ") EXPECTED");
				}
			}
			else{
				ErrorMessage.print(lexer.position(), "( EXPECTED");
			}
				break;
			
			case PRINT:
			 getToken();
			 if(token.symbol()==Symbol.LPAREN){
					getToken();
				Expr();
				if(token.symbol()==Symbol.RPAREN){
					getToken();
					if(token.symbol()==Symbol.SEMICOLON){
						getToken();
					}
					else{
						ErrorMessage.print(lexer.position(), "; EXPECTED");
					}
				}
				else{
					ErrorMessage.print(lexer.position(), ") EXPECTED");
				}
			}
			else {ErrorMessage.print(lexer.position(), "( EXPECTED");
		}
				break;
			
			
			case ID:
			getToken();
			if(token.symbol() == Symbol.ASSIGN){
				getToken();
				Expr();
				if(token.symbol() == Symbol.SEMICOLON){
					getToken();
				}
				else{
					ErrorMessage.print(lexer.position(), "; EXPECTED");
				}
			}
			else {
				ErrorMessage.print(lexer.position(), "<- EXPECTED");
			}
			break;
		}
	}
	public void Cond () throws IOException{
		AndExpr();
		while(token.symbol()==Symbol.OR){
			getToken();
			AndExpr();
		}
		
	}
	public void AndExpr () throws IOException{
		RelExpr();
		while(token.symbol()==Symbol.AND){
			getToken();
			RelExpr();
		}
	}
	
	public void RelExpr () throws IOException{
		if(token.symbol() == Symbol.RELOPE){
			getToken();
		}
		Expr();
		switch(token.symbol()){
			case LT:
			case LE:
			case GT:
			case GE:
			case EQ:
			case NE:
				getToken();
				Expr();
				break;
			default: 
			ErrorMessage.print(lexer.position(), "Relational operator EXPECTED");
		}
	}
	public void Expr () throws IOException{
		MulExpr();
		while(token.symbol()== Symbol.PLUS || token.symbol()== Symbol.MINUS){
			getToken();
			MulExpr();
		}
	}
	public void MulExpr () throws IOException{
		PrefixExpr();
		while(token.symbol() == Symbol.TIMES || token.symbol() == Symbol.SLASH){
			getToken();
			PrefixExpr();
		}
	}
	
	public void PrefixExpr () throws IOException{
		if(token.symbol () == Symbol.PLUS|| token.symbol () == Symbol.MINUS){
			getToken();
		}
		SimpleExpr();
	}
	public void SimpleExpr () throws IOException{
		if(token.symbol () == Symbol.INTEGER){
			getToken();
		}
		else if (token.symbol () == Symbol.HEAD || token.symbol () == Symbol.TAIL){
			getToken();
			if(token.symbol () == Symbol.LPAREN){
				getToken();
				Expr();
				if(token.symbol () == Symbol.RPAREN){
					getToken();
				}
				else {
					ErrorMessage.print(lexer.position(), ") EXPECTED");
				}
			}
			else {
				ErrorMessage.print(lexer.position(), "( EXPECTED");
			}
		}
		else if (token.symbol () == Symbol.NULL){
			getToken();
			if(token.symbol () == Symbol.LPAREN){
				getToken();
				if(token.symbol () == Symbol.RPAREN){
					getToken();
				}
				else {
					ErrorMessage.print(lexer.position(), ") EXPECTED");
				}
			}
			else {
				ErrorMessage.print(lexer.position(), "( EXPECTED");
			}
		}
		else if (token.symbol () == Symbol.LPAREN){
			getToken();
			Expr();
			if(token.symbol () == Symbol.RPAREN){
				getToken();
			}
			else {
				ErrorMessage.print(lexer.position(), ") EXPECTED");
			}
		}
		else if (token.symbol () == Symbol.ASINTEGER){
			getToken();
			if(token.symbol () == Symbol.LPAREN){
				getToken();
				if(token.symbol () == Symbol.READLINE){
					getToken();
					if(token.symbol () == Symbol.LPAREN){
						getToken();
						if(token.symbol () == Symbol.RPAREN){
							getToken();
							if(token.symbol () == Symbol.RPAREN){
								getToken();
							}
							else {
								ErrorMessage.print(lexer.position(), ") EXPECTED");
							}
						}
						else {
							ErrorMessage.print(lexer.position(), ") EXPECTED");
						}
					}
					else {
						ErrorMessage.print(lexer.position(), "( EXPECTED");
					}
				}
				else{
					ErrorMessage.print(lexer.position(), "readline EXPECTED");
				}
			}
			else {
				ErrorMessage.print(lexer.position(), "( EXPECTED");
			}		
		}
		
		else if (token.symbol () == Symbol.ID){
			getToken();
			if(token.symbol () == Symbol.LPAREN){
				getToken();
				if(token.symbol () == Symbol.TIMES || token.symbol () == Symbol.SLASH ||token.symbol () == Symbol.INTEGER || token.symbol () == Symbol.LPAREN || token.symbol () == Symbol.ASINTEGER|| token.symbol () == Symbol.ID ||token.symbol () == Symbol.CONS||token.symbol () == Symbol.HEAD ||token.symbol () == Symbol.TAIL|| token.symbol () == Symbol.NULL){
					//getToken();
					Expr();
					while (token.symbol () == Symbol.COMMA){
						getToken();
						Expr();
					}
				}
				if(token.symbol () == Symbol.RPAREN){
					getToken();
				}
				else {
					ErrorMessage.print(lexer.position(), ") EXPECTED");
				}
		}
		}
		else if (token.symbol () == Symbol.CONS){
			getToken();
			if(token.symbol () == Symbol.LPAREN){
				getToken();
				Expr();
				if(token.symbol () == Symbol.COMMA){
					getToken();
					Expr();
					if(token.symbol () == Symbol.RPAREN){
						getToken();
					}
					else{
						ErrorMessage.print(lexer.position(), ") EXPECTED");
					}
				}
				else {
					ErrorMessage.print(lexer.position(), ", EXPECTED");
				}
			}
			else {
				ErrorMessage.print(lexer.position(), "( EXPECTED");
			}
		}
		
		else {
			ErrorMessage.print(lexer.position(), "Simple expression EXPECTED");
		}
	}
	
	public void program () throws IOException{
		if(token.symbol () != Symbol.SOURCE)
		ErrorMessage.print(lexer.position(), "source EXPECTED");
		getToken();
		if(token.symbol () != Symbol.LPAREN)
		ErrorMessage.print(lexer.position(), "( EXPECTED");
		getToken();
		if(token.symbol () != Symbol.LISTR)
		ErrorMessage.print(lexer.position(), "\"List.R\" EXPECTED");
		getToken();
		if(token.symbol () != Symbol.RPAREN)
		ErrorMessage.print(lexer.position(), ") EXPECTED");
		getToken();
		while (token.symbol()==Symbol.ID){//if next token is an identifier, check if it is a function definition
			getToken();
			FunctionDef();
		}
		MainDef();
		
	}
}