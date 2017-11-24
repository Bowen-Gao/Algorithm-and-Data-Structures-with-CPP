#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
	int position;
    for (position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
			Bracket b1(next, (position+1));
			opening_brackets_stack.push(b1);
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
			Bracket b2 = opening_brackets_stack.top();
			if (b2.Matchc(next)) {
				opening_brackets_stack.pop();
			} else {
				break;
			}
        }
    }

    // Printing answer, write your code here
	if (opening_brackets_stack.empty()) {
		std::cout<<"Success"<<std::endl;
	} else {
		if (position < text.length()){
			std::cout<<(position + 1)<<std::endl;
		} else {
			std::cout<<opening_brackets_stack.top().position<<std::endl;
		}
	}
	system("pause");
    return 0;
}
