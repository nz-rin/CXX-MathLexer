
#include "MathLexer.hxx"
#include <optional>

int main(){

	std::vector<std::string> strings = {
		"Hello + Lexer",
		"(-7)",
		"7++",
		"5++6",
		"6--7",
		"5++(6--7)",
		"5+-(6--7)",
		"(-6--7)"
	};
	for(std::string &s : strings){
		std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n" ;
		std::cout << "  Lexing string \"" << s << "\"\n";

		std::optional<std::vector<std::string>> token = MathLexer::lex_string(s);

		std::cout << "\n";

		if(token.has_value()){
			if(	!MathLexer::validate_expressions(*token)){
				std::cout << "  ERROR Invalid Expression" <<std::endl;
				std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n" ;
				continue;
			}
			MathLexer::fold_tokens(*token);
			for(std::string &_s : (*token)){
				std::cout << "    Token: \'" << _s << "\'\n";
			}

			std::cout << "\n  Valid Tokens"<< std::endl;
		}else{
			std::cout << "  ERROR Invalid Tokens" <<std::endl;
		}
		std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n" ;
	}

	return 0;
}
