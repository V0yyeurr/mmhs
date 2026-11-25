#include<iostream>
#include<string>
#include<assert.h>


const std::string keywords[] = {"int", "double", "float", "char", "if", "for", "while"};

enum Type {
	ERR = -1,
	KEY,
	ID,
	NUM,
	STR,
	OP,
};

class Token{
private:

	Token* next;
	std::string content;
	Type type;

public:
	Token() {
		next = nullptr;
		type = ERR;
		content = content.empty();
	}

	Token(std::string content, Type type) {
		this->next = nullptr;
		this->content = content;
		this->type = type;
	}

	Type get_type() {
		return this->type;
	}

	std::string get_content() {
		return this->content;
	}
	
	Token* get_next() {
		return this->next;
	}
};

class Stack {
private:
	Token* head;
	Token* tail;
public:
	Stack() {
		head = nullptr;
		tail = head;
	}
	
	void push_token(Token* n) {
		assert(0 && "not implemented yet");
	}
	
	Token* pop_token(){
		assert(0 && "not implemented yet");
	}
	
	Token* get_head() {
		return this->head;
	}

	Token* get_tail() {
		return this->tail;
	}

};

class Tokenizer {
public:
	Stack* tokens;
	
	Tokenizer() {
		tokens = new Stack;
	}
	
	void push(Token* t) {
		tokens->push_token(t);
	}

	Token* create_token(std::string content, Type type) {
		Token* new_token = new Token(content, type);
		return new_token;
	}

private:
	bool is_keyword(std::string src) {
		for(int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++){
			if(src == keywords[i]) return true; 
		}
		return false;
	}

	
};

int main () {
	Tokenizer* s = new Tokenizer;
	return 0;
}
