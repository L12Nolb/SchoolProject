//MicroRSyn.java
//Author: Suzanne Nolba

public class MicroRSyn{
	public static void main (String args[]) throws java.io.IOException{
		
		System.out.println ("Source Program");
		System.out.println ("--------------");
		System.out.println ();
		
		SyntaxAnalyzer micror = new SyntaxAnalyzer();
		micror. program();
		
		System.out.println ();
		System.out.println ();
		System.out.println ("PARSE SUCCESSFUL");
	}
}