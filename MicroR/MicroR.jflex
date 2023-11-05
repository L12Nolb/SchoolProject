/*Author: Suzanne Nolba*/

%%
%{
	private void echo () { System . out . print (yytext ()); }
	
	public int position () { return yycolumn; }
%}

%class    MICRORLexer
%function nextToken
%type	  Token
%unicode
%line
%column
%eofval{
	{ return new Token (Symbol . EOF); }
%eofval}

WhiteSpace = [ \t\n]
Ident      = [:letter:] ([:letter:] | [:digit:])*
Integer    = [:digit:] [:digit:]*
Comments   = [#]([^\n])*
Id		   = [:letter:] ([:letter:] | [:digit:]| [_]([:letter:] | [:digit:])){1,30}([:letter:] | [:digit:])*




%%
"."  	    	{ echo (); return new Token (Symbol . PERIOD); }
","		{ echo (); return new Token (Symbol . COMMA); }
";"		{ echo (); return new Token (Symbol . SEMICOLON); }
":="     	{ echo (); return new Token (Symbol . ASSIGN); }
"="     	{ echo (); return new Token (Symbol . EQ); }
"<>"    	{ echo (); return new Token (Symbol . NE); }
"<"     	{ echo (); return new Token (Symbol . LT); }
">"     	{ echo (); return new Token (Symbol . GT); }
"<="    	{ echo (); return new Token (Symbol . LE); }
">="    	{ echo (); return new Token (Symbol . GE); }
"+"		{ echo (); return new Token (Symbol . PLUS); }
"-"		{ echo (); return new Token (Symbol . MINUS); }
"*"     	{ echo (); return new Token (Symbol . TIMES); }
"/"  	 	{ echo (); return new Token (Symbol . SLASH); }
"("		{ echo (); return new Token (Symbol . LPAREN); }
")"		{ echo (); return new Token (Symbol . RPAREN); }
"{"		{ echo (); return new Token (Symbol . LCPAREN); }
"}"		{ echo (); return new Token (Symbol . RCPAREN); }
"!"		{ echo (); return new Token( Symbol . RELOPE);}
"&&"		{ echo (); return new Token( Symbol . ANDCOMP);}
source 		{ echo (); return new Token (Symbol . SOURCE); }
\"List.R\" 		{ echo (); return new Token (Symbol . STRING); }
function 		{ echo (); return new Token (Symbol . FUNC); }
main		{ echo (); return new Token( Symbol . MAIN);}
else		{ echo (); return new Token( Symbol . ELSE);}
print		{ echo (); return new Token( Symbol . PRINT);}
readline	{ echo (); return new Token( Symbol . READLINE);}
as.integer	{ echo (); return new Token( Symbol . ASINT);}
cons		{ echo (); return new Token( Symbol . CONS);}
head		{ echo (); return new Token( Symbol . HEAD);}
tail		{ echo (); return new Token( Symbol . TAIL);}
null		{ echo (); return new Token( Symbol . NULL);}
begin 		{ echo (); return new Token (Symbol . BEGIN); }
call    	{ echo (); return new Token (Symbol . CALL); }
const   	{ echo (); return new Token (Symbol . CONST); }
do      	{ echo (); return new Token (Symbol . DO); }
end     	{ echo (); return new Token (Symbol . END); }
if		{ echo (); return new Token (Symbol . IF); }
odd     	{ echo (); return new Token (Symbol . ODD); }
procedure  	{ echo (); return new Token (Symbol . PROC); }
then    	{ echo (); return new Token (Symbol . THEN); }
var  	 	{ echo (); return new Token (Symbol . VAR); }
while		{ echo (); return new Token (Symbol . WHILE); }
{Ident}   	{ echo (); return new Token (Symbol . ID, yytext ()); }
{Id}   	{ echo (); return new Token (Symbol . IDE, yytext ()); }
{Integer}	{ echo (); return new Token (Symbol . INTEGER, yytext ()); }
{Comments}		{ echo (); }
{WhiteSpace}	{ echo (); }

.		{ echo (); ErrorMessage . print (yycolumn, "Illegal character"); }