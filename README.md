# CXX-MathLexer
Header Only C++ file that can Lex math strings from strings or files, validate and fold tokens into properly signed tokens.

## Usage
The namespace has multiple functions that can be used to tokenize a string or file into Tokens, such as the MathLexer::c_str function which will lex a \0 terminated string.
The namespace also 2 additional helper functions:
- validate_expressions which will analyse a list of tokens and ensure it meets the grammer.
```
  Expression Operator Expression

  Expression    = [+|-] NUMBER | [+|-] (Expression)
  Operator      = +|-|*|/
```
- fold_tokens
The lexer will cut an expression with signed number such as 1* -2 into '1', '*', '-' & '2', which may unwanted.
this function will 'fold' tokens into signed tokens according to this grammer:
```
  Expression Operator Operator Expression
```
into
```
  Expression Operator [-|+]Expression
```
as long as it a + or -, / * are not signs for numbers and will be ignored. this function does not valid the grammer only fold based on the rule

## Exampled
Build the main.cxx file using the build.sh or your own prefered compiler and run it to see an example of how valid and invalid tokens are handled.
