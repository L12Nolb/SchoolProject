import java.util.*;

abstract class Program { }

class Statement extends Program {

   protected Statement stmt1, stmt2;

   public Statement () { }

   public Statement (Statement stmt1, Statement stmt2) {
     this . stmt1 = stmt1;
     this . stmt2 = stmt2;
   }

   public String toString () {
     if (stmt1 == null)
       return "()";
     else if (stmt2 == null)
       return "(" + stmt2 + ")";
     else
       return "(: " + stmt1 + " " + stmt2 + ")";
   }

}
class FuncMain extends Program{
  
   protected Statement stmt1;
    Vector <Statement>func = new Vector();
  
   public FuncMain () { }
  
   public FuncMain (Statement stmt1, Vector <Statement> args) {
     this . stmt1 = stmt1;
     
      for (int i =0; i < args.size(); i++){
        func.add(args.get(i));
      }
      
   }
  
   public String toString () {
     if (stmt1 == null)
       return "()";
        
     else if (func.size() == 0)
       return "Parse Tree of Main\n\n\n (" + stmt1 + ")";
        
      else{
        String dummy = "";
        for (int i =0; i < func.size(); i++){
          dummy = dummy +func.get(i) + ")\n\n\n";
      }
        
        return  dummy + " \n\n Parse Tree of main\n\n (: " + stmt1 + ")";
        
      }
   }
  
}
class Func extends Statement{
  
   Vector <Statement> stmt1 = new Vector();
  protected Expression stmt2;
  String fName;
   public Func () { }
  
   public Func (String fName, Vector <Statement> stmt, Expression stmt2) {
     //this . stmt1 = stmt;
      for (int i =0; i < stmt.size(); i++){
        stmt1.add(stmt.get(i));
      }
     this . stmt2 = stmt2;
      this . fName = fName;
   }
  
   public String toString () {
      
        String dummy = "";
        for (int i =0; i < stmt1.size(); i++){
          dummy = dummy +stmt1.get(i) + " ";
      }
      
       return fName + " PARSE TREE \n\n\n(: " + dummy + ") (return " + stmt2 + ")";
   }
  
}


class Assignment extends Statement {

   protected Identifier lhs;
   protected Expression rhs;

   public Assignment () { }

   public Assignment (Identifier lhs, Expression rhs) {
     this . lhs = lhs;
     this . rhs = rhs;
   }

   public String toString () {
     return "(<- " + lhs + " " + rhs + ")";
   }

}

class PrintStatement extends Statement {

   protected Expression procId;

   public PrintStatement () { }

   public PrintStatement (Expression procId) {
     this . procId = procId;
   }

   public String toString () {
     return "(print " + procId + ")";
   }

}

class returnStatement extends Statement {
  
   protected Expression procId;
  
   public returnStatement () { }
  
   public returnStatement (Expression procId) {
     this . procId = procId;
   }
  
   public String toString () {
     return "(return " + procId + ")";
   }
  
}

class IfStatement extends Statement {

  protected Expression test;
  protected Statement thenStmt, elseStmt;

  public IfStatement () { }

  public IfStatement (Expression test, Statement thenStmt, Statement elseStmt) {
    this . test = test;
    this . thenStmt = thenStmt;
    this . elseStmt = elseStmt;
  }

  public String toString () {
    if (elseStmt == null){
      return "(if " + test + " " + thenStmt +")";
    }
    else{
      return "(if " + test + " " + thenStmt + " "+ elseStmt +")";}
   }

}

class WhileStatement extends Statement {

  protected Expression test;
  protected Statement body;

  public WhileStatement () { }

  public WhileStatement (Expression test, Statement body) {
    this . test = test;
    this . body = body;
  }

  public String toString () {
     return "(while " + test + " " + body + ")";
   }

}

abstract class Expression { }

class Identifier extends Expression {

  protected String id;

  public Identifier () { }

  public Identifier (String id) {
    this . id = id;
  }
  public String toString () {
    return "(id " + id + ")";
  }
    
  }
  
class IntValue extends Expression {

  protected int intValue;

  public IntValue () { }

  public IntValue (int intValue) {
    this . intValue = intValue;
  }

  public String toString () {
    return "(integer " + intValue + ")";
  }

}
  
class Apply extends Expression {
  
  //protected Expression term1;
  String fName;
  Expression term1;
  Vector<Expression> arf = new Vector();
  public Apply () { }

  public Apply (String fName, Expression term1, Vector<Expression> arg) {
    this . fName = fName;
    this . term1 = term1;
    
    for (int i =0; i < arg.size(); i++){
      arf.add(arg.get(i));
      
    }
  }
  
  public String toString () {
    if (arf.size() == 1)
      return "(apply " + fName + " (" +term1 +"))";
    else{
      String dummy = "(apply " + fName + " " +term1, dummy2;
      for(int i =0; i < arf.size(); i++){
        dummy2 = " " +arf.get(i);
        dummy = dummy + dummy2;
      }
      dummy = dummy +")";
      return dummy;}
 }
}
class Binary extends Expression {

  protected String op;
  protected Expression term1, term2;

  public Binary () { }

  public Binary (String op, Expression term1, Expression term2) {
    this . op = op;
    this . term1 = term1;
    this . term2 = term2;
  }

  public String toString () {
    return "(" + op + " " + term1 + " " + term2 + ")";
  }

}

class Unary extends Expression {

  protected String op;
  protected Expression term;

  public Unary () { }

  public Unary (String op, Expression term) {
    this . op = op;
    this . term = term;
  }

  public String toString () {
    return "(" + op + " " + term + ")";
  }

}

class cons extends Expression {
  
   protected Expression stmt1, stmt2;
  
   public cons () { }
  
   public cons (Expression stmt1, Expression stmt2) {
     this . stmt1 = stmt1;
     this . stmt2 = stmt2;
   }
  
   public String toString () {

       return "(cons " + stmt1 + " " + stmt2 + ")";
   }
  
}

class Head extends Expression {
  
   protected Expression stmt1;
  
   public Head () { }
  
   public Head (Expression stmt1) {
     this . stmt1 = stmt1;
   }
  
   public String toString () {
      
       return "(Head (id " + stmt1 + ")";
   }
  
}

class Tail extends Expression{
  
   protected Expression stmt1;
  
   public Tail () { }
  
   public Tail (Expression stmt1) {
     this . stmt1 = stmt1;
   }
  
   public String toString () {
      
       return "(Tail (id " + stmt1 + ")";
   }
  
}

class Null extends Expression {
  
   protected String stmt1;
  
   public Null () { }
  
   public Null (String stmt1) {
     this . stmt1 = stmt1;
   }
  
   public String toString () {
      
       return "(null)";
   }
  
}

class AsInteger extends Expression {
  
   protected String stmt1;
  
   public AsInteger () { }
  
   public AsInteger (String stmt1) {
     this . stmt1 = stmt1;
   }
  
   public String toString () {
      
       return "( " + stmt1 +")";
   }
  
}




  