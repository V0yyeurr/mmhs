#include<iostream>
#include<string>
#include<assert.h>

const std::string keywords[] = {"int", "double", "float", "char", "if", "for", "while", "nadia"};
const std::string operations[] = {"+", "-", "*", "/", "&", "&&", "||", "|", "%"};

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
public:
	
	Token* next;
	std::string content;
	Type type;
	
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

	Token(std::string content) {
		this->next = nullptr;
		this->content = content;
		this->type = ERR;
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
	
	void set_next(Token* token){
		this->next = token;
	}
	
	void set_type(Type type){
		this->type = type;
	}

	void set_content(std::string content){
		this->content = content;
	}
	
	void print_token() {
		std::cout << "content: " << content << "\ntype: " << type << "\nnext: " << next << "\n";
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
	
	void push_token(Token* t) {
		if(head == nullptr) {
			head = t;
			tail = head;
			return;
		}
		tail->set_next(t);
		tail = tail->get_next();
	}
	
	Token* pop_token(){
		if(!this->head) return nullptr;
		Token* aux = this->head;
		this->head = this->head->get_next();
		aux->set_next(nullptr);
		return aux;
	}
	
	Token* get_head() {
		return this->head;
	}

	Token* get_tail() {
		return this->tail;
	}
	
	void set_head(Token* head) {
		this->head = head;
	}

	void set_tail(Token* tail) {
		this->tail = tail;
	}

	//debug
	void print_stack() {
		Token* aux = head;
		while(aux != nullptr) {
			std::cout << "current: " << aux << "\n";
			aux->print_token();
			aux = aux->get_next();
		}
	}

};

class Tokenizer {
public:
	Stack* tokens;
	
	Tokenizer() {
		tokens = new Stack;
	}
	
	void push(Token* t) {
		if(!t) return;
		tokens->push_token(t);
	}
	
	Token* pop() {
		return tokens->pop_token();
		
	}

	Token* create_token(std::string content, Type type) {
		Token* new_token = new Token(content, type);
		return new_token;
	}
	
	//debug
	void print_tokens() {
		tokens->print_stack();
	}

	bool is_keyword(std::string src) {
		for(int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++){
			if(src == keywords[i]) return true; 
		}
		return false;
	}
	
	bool is_identifier(std::string src) {
		return false;
	}

	bool is_number(std::string src) {
		for(char c : src) {

			if(!isdigit(c)) return false;
		}
		return true;
	}

	bool is_string(std::string src) {
		return false;
	}

	bool is_operation(std::string src) {
		for(int i = 0; i < sizeof(operations)/sizeof(operations[0]); i++) {
			if(src == operations[i]) return true;
		}
		return false;
	}
	
	Token* tokenize_word(std::string src) {
		if(is_keyword(src)) {
			return create_token(src, ID);
		}else if(is_operation(src)) {
			return create_token(src, OP);
		}else if(is_string(src)) {
			return create_token(src, STR);
		}else if(is_number(src)) {
			return create_token(src, NUM);
		}else if(is_identifier(src)) {
			return create_token(src, ID);
		}
		return create_token(src, ERR);
	}
	
};

int main () {
	Tokenizer* s = new Tokenizer;
	Token* test = s->tokenize_word("nadia");
	test->print_token();
	return 0;
}
