// SyntaxAnalyzer class
// SyntaxAnalyzer is a class to represent a recursive descent parser for the 
// MicroR programming language.

import java.io.*;import java.util.*;


public class ParserAST {

  protected MicroRLexer lexer;	// lexical analyzer
  protected Token token;	// current token

  public ParserAST () throws IOException {
    lexer = new MicroRLexer (new InputStreamReader (System . in));
    getToken ();
  }

  private void getToken () throws IOException { 
    token = lexer . nextToken (); 
  }

    // Program ::= source ( â€œList.Râ€ ) {FunctionDef} MainDef
    public Program program () throws IOException {
      Program stmt1;
      Statement st;
      
      Vector <Statement> func = new Vector();
      
      if (token . symbol () != Symbol . SOURCE) 	// source
        ErrorMessage . print (lexer . position (), "source EXPECTED");
      getToken ();
      if (token . symbol () != Symbol . LPAREN) 	// (
        ErrorMessage . print (lexer . position (), "( EXPECTED");
      getToken ();
      if (token . symbol () != Symbol . LISTR) 	// "List.R"
        ErrorMessage . print (lexer . position (), "\"List.R\" EXPECTED");
      getToken ();
      if (token . symbol () != Symbol . RPAREN ) 	// )
        ErrorMessage . print (lexer . position (), ") EXPECTED");
      getToken ();
      while (token . symbol () == Symbol . ID){ 	// {FunctionDef}
      func.add(functionDef ());}
      st = mainDef();
      stmt1 = new FuncMain(st, func);  // MainDef
      if(func.size() !=0){
        stmt1 = new FuncMain(st, func); 
      }
      if (token . symbol () != Symbol . EOF) 
        ErrorMessage . print (lexer . position (), "END OF PROGRAM EXPECTED");
        
        
        return stmt1;
    }
  
  
    // FunctionDef ::= 
    //     id <âˆ’ function ( [id {, id }] ) "{" {Statement} return ( Expr ) ; "}"
  
    public Statement functionDef () throws IOException {
      
      Statement stmt1 = null;
      Vector <Statement> stmt2= new Vector();
      Expression exp;
      String fName;
      
      if (token . symbol () != Symbol . ID)        	// id
        ErrorMessage . print (lexer . position (), "id EXPECTED");
        fName = token.lexeme();
      getToken ();
      if (token . symbol () != Symbol . ASSIGN)     	// <-
        ErrorMessage . print (lexer . position (), "<- EXPECTED");
      getToken ();
      if (token . symbol () != Symbol . FUNCTION)  	// function
        ErrorMessage . print (lexer . position (), "function EXPECTED");
      getToken ();
      if (token . symbol () != Symbol . LPAREN)     	// (
        ErrorMessage . print (lexer . position (), "( EXPECTED");
      getToken ();
      if (token . symbol () == Symbol . ID) {     	// [ id
        getToken ();
        while (token . symbol () == Symbol . COMMA) {	// { ,
          getToken ();
          if (token . symbol () != Symbol . ID)      	// id
            ErrorMessage . print (lexer . position (), "id EXPECTED");
          getToken ();
        }                                          	// }
      }                                             	// ]
      if (token . symbol () != Symbol . RPAREN)   	// )
          ErrorMessage . print (lexer . position (), ") EXPECTED");
      getToken ();
      if (token . symbol () != Symbol . LBRACE)      	// "{"
        ErrorMessage . print (lexer . position (), "{ EXPECTED");
      getToken ();
      while (token . symbol () == Symbol . IF        	// { 
          || token . symbol () == Symbol . WHILE
          || token . symbol () == Symbol . ID
          || token . symbol () == Symbol . PRINT) 
        stmt2.add(statement ());                             	// Statement }
      if (token . symbol () != Symbol . RETURN)    	// return
        ErrorMessage . print (lexer . position (), "return EXPECTED");
      getToken ();
      if (token . symbol () != Symbol . LPAREN)    	// (
        ErrorMessage . print (lexer . position (), "( EXPECTED");
      getToken ();
      exp= expr ();                                     	// Expr
      stmt1 = new Func (fName,stmt2, exp);
      
      if (token . symbol () != Symbol . RPAREN)    	// )
        ErrorMessage . print (lexer . position (), ") EXPECTED");
      getToken ();
      if (token . symbol () != Symbol . SEMICOLON)    	// ;
        ErrorMessage . print (lexer . position (), "; EXPECTED");
      getToken ();
      if (token . symbol () != Symbol . RBRACE)    	// "}"
        ErrorMessage . print (lexer . position (), "} EXPECTED");
      getToken ();
      
      return stmt1;
      
    }
  
    // MainDef ::= main < âˆ’ function ( ) "{" StatementList "}"
  
    public Statement mainDef () throws IOException {
      Statement stmt;
      
      if (token . symbol () != Symbol . MAIN)   	// main
        ErrorMessage . print (lexer . position (), "main EXPECTED");
      getToken ();
      if (token . symbol () != Symbol . ASSIGN)  	// <-
        ErrorMessage . print (lexer . position (), "<- EXPECTED");
      getToken ();
      if (token . symbol () != Symbol . FUNCTION) // function
        ErrorMessage . print (lexer . position (), "function EXPECTED");
      getToken ();
      if (token . symbol () != Symbol . LPAREN) 	// (
        ErrorMessage . print (lexer . position (), "( EXPECTED");
      getToken ();
      if (token . symbol () != Symbol . RPAREN) 	// )
        ErrorMessage . print (lexer . position (), ") EXPECTED");
      getToken ();
      if (token . symbol () != Symbol . LBRACE) 	// "{"
        ErrorMessage . print (lexer . position (), "{ EXPECTED");
      getToken ();
      stmt = statementList ();                      	// StatementList
      if (token . symbol () != Symbol . RBRACE) 	// "}"
        ErrorMessage . print (lexer . position (), "} EXPECTED");
      getToken ();
      
      return stmt;
    }
  
    // StatementList ::= Statement { Statement }
  
    public Statement statementList () throws IOException {
      
      
          Statement stmt1= null, stmt2;
          stmt1 = statement ();                          	// Statement
          while (token . symbol () == Symbol . IF  	// {
              || token . symbol () == Symbol . WHILE
              || token . symbol () == Symbol . ID
              || token . symbol () == Symbol . PRINT) {
            stmt2 = statement (); // Statement }
            if(stmt2 !=null)
            stmt1 = new Statement (stmt1, stmt2);
              }
            return stmt1;
    }
  
    // Statement ::= if ( Cond ) { StatementList } [else { StatementList }]
    //   | while ( Cond ) { StatementList }
    //   | id < âˆ’ Expr ;
    //   | print ( Expr ) ;
  
    public Statement statement () throws IOException {
      
      Expression exp;
      Identifier id = null;
      Statement stmt = null, stmt1, stmt2 = null;
      
      switch (token . symbol ()) {
        
        case IF :                                  	// if
          getToken ();
          if (token . symbol () != Symbol . LPAREN)   	// (
            ErrorMessage . print (lexer . position (), "( EXPECTED");
          getToken ();
          exp = cond ();                                 	// Cond
          if (token . symbol () != Symbol . RPAREN)  	// )
            ErrorMessage . print (lexer . position (), ") EXPECTED");
          getToken ();
          if (token . symbol () != Symbol . LBRACE) 	// "{"
            ErrorMessage . print (lexer . position (), "{ EXPECTED");
          getToken ();
          stmt1 = statementList (); // StatementList
          stmt = new IfStatement (exp, stmt1, null); 
          if (token . symbol () != Symbol . RBRACE) 	// "}"
            ErrorMessage . print (lexer . position (), "} EXPECTED");
          getToken ();
          if (token . symbol () == Symbol . ELSE) {  	// [ else
            getToken ();
            if (token . symbol () != Symbol . LBRACE) 	// "{"
              ErrorMessage . print (lexer . position (), "{ EXPECTED");
            getToken ();
            stmt2= statementList (); // StatementList
            stmt = new IfStatement (exp, stmt1, stmt2); 
            if (token . symbol () != Symbol . RBRACE) 	// "}"
              ErrorMessage . print (lexer . position (), "} EXPECTED");
            getToken ();
          }                                        	// ]
          break;
        
        case WHILE :                                  	// while
          getToken ();
          if (token . symbol () != Symbol . LPAREN)   	// (
            ErrorMessage . print (lexer . position (), "( EXPECTED");
          getToken ();
          exp = cond ();                                 	// Cond
          if (token . symbol () != Symbol . RPAREN)  	// )
            ErrorMessage . print (lexer . position (), ") EXPECTED");
          getToken ();
          if (token . symbol () != Symbol . LBRACE) 	// "{"
            ErrorMessage . print (lexer . position (), "{ EXPECTED");
          getToken ();
          stmt1 = statementList ();  
          stmt = new WhileStatement(exp, stmt1);// StatementList
          if (token . symbol () != Symbol . RBRACE) 	// "}"
            ErrorMessage . print (lexer . position (), "} EXPECTED");
          getToken ();
          break;
        
        case ID :                                  	// id
        id = new Identifier (token.lexeme());
          getToken ();
          if (token . symbol () != Symbol . ASSIGN)  	// <-
            ErrorMessage . print (lexer . position (), "<- EXPECTED");
          getToken ();
          //exp = expr ();                                 	// Expr
          stmt = new Assignment (id, expr());
          if (token . symbol () != Symbol . SEMICOLON)  	// ; 
            ErrorMessage . print (lexer . position (), "; EXPECTED");
          getToken ();
          break;
        
        case PRINT :                                  	// print
          getToken ();
          if (token . symbol () != Symbol . LPAREN)  	// (
            ErrorMessage . print (lexer . position (), "( EXPECTED");
          getToken ();
          //exp = expr (); // Expr
          stmt = new PrintStatement(expr());
          if (token . symbol () != Symbol . RPAREN) 	// )
            ErrorMessage . print (lexer . position (), ") EXPECTED");
          getToken ();
          if (token . symbol () != Symbol . SEMICOLON)  	// ;
            ErrorMessage . print (lexer . position (), "; EXPECTED");
          getToken ();
          break;
        
        default :
          ErrorMessage . print (lexer . position (), "UNRECOGNIZABLE SYMBOL");
        
      }
      return stmt;

    }
  
    // Cond ::= AndExpr {|| AndExpr}
  
    public Expression cond () throws IOException {
    Expression cond;
    cond = andExpr ();                                	// AndExpr
    while (token . symbol () == Symbol . OR) { 	// { ||
      getToken ();
      cond = new Binary ("||", cond , andExpr());                             	// AndExpr }
    }
    return cond;
    }
  
    // AndExpr ::= RelExpr {&& RelExpr}
  
    public Expression andExpr () throws IOException {
    Expression exp;
    exp = relExpr ();                                	// relExpr
    while (token . symbol () == Symbol . AND) { // { &&
      getToken ();
      exp = new Binary ("&&", exp, relExpr ());                              	// relExpr }
    }
    return exp;
    }
  
    // RelExpr ::= [!] Expr RelOper Expr
  
    public Expression relExpr () throws IOException {
      
      Expression relE;
      String op;
      if (token . symbol () == Symbol . NOT) 	// [!]
        getToken ();
      relE = expr ();                             	// Expr
      switch (token . symbol ()) {
        case LT :                          	// <
          op = "<";
          getToken ();
          relE = new Binary (op, relE, expr ());   
          break;
          
        case LE :                          	// <=
        op = "<=";
        getToken ();
        relE = new Binary (op, relE, expr ());   
        break;
        case GT :                          	// >
        op = ">";
        getToken ();
        relE = new Binary (op, relE, expr ());   
        break;
        case GE :                         	// >=
        op = ">=";
        getToken ();
        relE = new Binary (op, relE, expr ());   
        break;
        case EQ :                         	// ==
        op = "=";
        getToken ();
        relE = new Binary (op, relE, expr ());   
        break;
        case NE :                         	// !=
        op = "!=";
        getToken ();
        relE = new Binary (op, relE, expr ());   
        break;
                                	// Expr

        default : 
          ErrorMessage . print (lexer . position (), "UNRECOGNIZABLE SYMBOL");
          break;
      }
      return relE;
    }
  
    // Expr ::= MulExpr {AddOper MulExpr}
    // AddOper ::= + | âˆ’
  
    public Expression expr () throws IOException {
      
      Expression exp;
      String addOp;
      exp = mulExpr ();                                 	// MulExpr
      while (token . symbol () == Symbol . PLUS   	// { +
    || token . symbol () == Symbol . MINUS) {      	//   -
      if (token . symbol () == Symbol . PLUS)
              addOp = "+";
            else
              addOp = "-";
        getToken ();
        exp = new Binary (addOp, exp, mulExpr ());                                 	// MulExpr }
      }
        return exp;
    }
  
    // MulExpr ::= PrefixExpr {MulOper PrefixExpr}
    // MulOper ::= * | /
  
    public Expression mulExpr () throws IOException {
      
      Expression mulE;
      String op;
      mulE = prefixExpr ();                               	// PrefixExpr
      while (token . symbol () == Symbol . TIMES  	// { *
          || token . symbol () == Symbol . SLASH) {  	//   /
            if (token . symbol () == Symbol . TIMES)
                    op = "*";
                  else
                    op = "/";  
        getToken ();
        mulE = new Binary (op, mulE, prefixExpr ());                                	// PrefixExpr }
      }
  return mulE;

    }
  
    // PrefixExpr ::= [AddOper] SimpleExpr
    // SimpleExpr ::= integer | ( Expr ) | as.integer ( readline ( ) ) 
    //   | id [ ( [Expr {, Expr}] ) ] | cons ( Expr , Expr ) | head ( Expr ) 
    //   | tail ( Expr ) | null ( )
  
    public Expression prefixExpr () throws IOException {
      
      Expression exp = null, exp1=null, exp2, exp3;
      //Expression[] exp4 = new Expression[4];
      Vector<Expression> exp4 = new Vector();
      String stmt1;
      String id, addOp = null;
      
      if (token . symbol () == Symbol . PLUS     	// [ +
          || token . symbol () == Symbol . MINUS){ //   - ]
        addOp = token. lexeme ();
        getToken ();}
      
      switch (token . symbol ()) {
        
        case INTEGER :                             	// integer

        exp = new IntValue(Integer.parseInt(token.lexeme()));
          getToken ();
          break;
        
        case LPAREN :                                  	// (
        
        getToken ();
        exp = expr ();                                	// Expr
        if (token . symbol () != Symbol . RPAREN)  	// )
          ErrorMessage . print (lexer . position (), ") EXPECTED");
        getToken ();
        break;
        
//          getToken ();
//          expr ();                                	// Expr
//          if (token . symbol () != Symbol . RPAREN)  	// )
//            ErrorMessage . print (lexer . position (), ") EXPECTED");
//          getToken ();
//          break;
        
        case ASINTEGER :                            	// as.integer
          getToken ();
          if (token . symbol () != Symbol . LPAREN)  	// (
            ErrorMessage . print (lexer . position (), "( EXPECTED");
          getToken ();
          if (token . symbol () != Symbol . READLINE) 	// readline
            ErrorMessage . print (lexer . position (), "readline EXPECTED");
          getToken ();
          if (token . symbol () != Symbol . LPAREN)  	// (
            ErrorMessage . print (lexer . position (), "( EXPECTED");
          getToken ();
          if (token . symbol () != Symbol . RPAREN)  	// )
            ErrorMessage . print (lexer . position (), ") EXPECTED");
          getToken ();
          if (token . symbol () != Symbol . RPAREN)  	// )
            ErrorMessage . print (lexer . position (), ") EXPECTED");
            exp = new AsInteger("readline");
          getToken ();
          break;
        
        case ID :                                 	// id
        id = token . lexeme();
        exp = new Identifier(id);
        getToken ();
        
        if (token . symbol () == Symbol . LPAREN) { 	// [ (
          getToken ();
          if (token . symbol () != Symbol . RPAREN) { 	// [
            exp1 = expr();
           // Expr
            int i=0;
            while (token . symbol () == Symbol . COMMA) { // { ,
              getToken ();
              exp4.add(expr ());                           	// Expr }
              i++;
            }
            exp = new Apply (id, exp1, exp4);
        
            if (token . symbol () != Symbol . RPAREN) 	// )
              ErrorMessage . print (lexer . position (), ") EXPECTED");
          }                                      	// ]
          getToken ();
        }
        
        break;

        
        case CONS :                               	// cons
                  
          getToken ();
          if (token . symbol () != Symbol . LPAREN)  	// (
            ErrorMessage . print (lexer . position (), "( EXPECTED");
          getToken ();
          exp2 = expr ();                                 	// Expr
          if (token . symbol () != Symbol . COMMA)   	// ,
            ErrorMessage . print (lexer . position (), ", EXPECTED");
          getToken ();
          exp3 = expr ();                                 	// Expr
          exp = new cons (exp2, exp3);
          if (token . symbol () != Symbol . RPAREN)  	// )
            ErrorMessage . print (lexer . position (), ") EXPECTED");
          getToken ();
          break;

        case HEAD :                               	// head
        
        getToken ();
        if (token . symbol () != Symbol . LPAREN) 	// (
          ErrorMessage . print (lexer . position (), "( EXPECTED");
        getToken ();
        exp1 = expr ();   // Expr
        exp = new Head (exp1); 
        if (token . symbol () != Symbol . RPAREN)  	// )
          ErrorMessage . print (lexer . position (), ") EXPECTED");
        getToken ();
        break;

        
        case TAIL :                                	// tail
        
        getToken ();
        if (token . symbol () != Symbol . LPAREN) 	// (
          ErrorMessage . print (lexer . position (), "( EXPECTED");
        getToken ();
        exp1 =expr ();                                	// Expr
        exp = new Tail (exp1);
        if (token . symbol () != Symbol . RPAREN)  	// )
          ErrorMessage . print (lexer . position (), ") EXPECTED");
        getToken ();
        break;      

        
        case NULL :                               	// null
        
        exp = new Null(token.lexeme());
        
          getToken ();
          if (token . symbol () != Symbol . LPAREN) 	// (
            ErrorMessage . print (lexer . position (), "( EXPECTED");
          getToken ();
          if (token . symbol () != Symbol . RPAREN) 	// )
            ErrorMessage . print (lexer . position (), ") EXPECTED");
          getToken ();
          break;
        
//          getToken ();
//          if (token . symbol () != Symbol . LPAREN) 	// (
//            ErrorMessage . print (lexer . position (), "( EXPECTED");
//          getToken ();
//          if (token . symbol () != Symbol . RPAREN) 	// )
//            ErrorMessage . print (lexer . position (), ") EXPECTED");
//          getToken ();
//          break;
        
        default :
          ErrorMessage . print (lexer . position (), "UNRECOGNIZABLE SYMBOL");
      }
      return exp;
    }
  
  }

        