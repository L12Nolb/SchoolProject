// This program is a recursive descent parser for MicroR. The abstract syntax 
// tree representation for the program is constructed.

public class MicroRAST {

  public static void main (String args []) throws java.io.IOException {
    System . out . println ("Source Program");
    System . out . println ("--------------");
    System . out . println ();

    ParserAST micror = new ParserAST ();
    
    Program program = micror . program ();
    System . out . println ();
    System . out . println ();
    System . out . println ("Abstract Syntax Tree");
    System . out . println ("--------------------");
    System . out . println ();
    System . out . println (program);
  }

}