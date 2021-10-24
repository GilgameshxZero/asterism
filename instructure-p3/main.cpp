/*
(aaaa[aaa)aaa]

see (: then ) must come later, but before everything else
see [: then ] must come later, but before everything else
see {: then } must come later, but before everything else

aaaa(aaaaaa[aaaa{aaaaaa}aaaaa]aaaaaa)aaaaa
    )
           ])
					      }])
								       ])
											       )


([)]      
*/

#include <iostream>
#include <string>
#include <vector>

bool verify(std::string const &S) {
	std::vector<char> later;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == '(') {
			later.push_back(')');
		} else if (S[i] == '[') {
			later.push_back(']');
		} else if (S[i] == '{') {
			later.push_back('}');
		} else if (!later.empty() && S[i] == later.back()) {
			later.pop_back();
		} else if (S[i] == ')' || S[i] == ']' || S[i] == '}') {
			return false;
		}
	}
	return true;
}

int main() {
	std::cout << verify("process(elements)") << '\n';
	std::cout << verify("aaaa(aaaaaa[aaaa{aaaaaa}aaaaa]aaaaaa)aaaaa") << '\n';
	std::cout << verify("(aaaa[aaa)aaa]") << '\n';
	return 0;
}
