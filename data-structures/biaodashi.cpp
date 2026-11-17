//输入操作数，直接输出PostfixExp
//输入开括号，将其入栈
//输入闭括号，判断栈是否为空，空则不匹配，错误；
//			  非空依次弹出栈中元素，输出到PostfixExp，直到遇到第一个开括号位置，开括号不进入PostfixExp
//输入运算符，循环，当（栈非空&&栈顶不是开括号&&栈顶运算符＞=输入运算符优先级），反复操作将栈顶元素弹出，输出到PostfixExp
//			  将输入的运算符压入栈中
//输入其他字符，错误
//中缀扫描后，若栈内仍有元素，将其全部依次弹出，输出到PostfixExp
//							  若遇到开括号，错误异常，清栈退出
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

template <class T>

class Link {
	public:
		T data;
		Link<T> *next;

		Link(const T info, Link<T> *nextValue = nullptr) {
			data = info;
			next = nextValue;
		}
};

template <class T>

class InkStack {
	private:
		Link<T> *top;
		int size;

	public:
		InkStack() : top(nullptr), size(0) {}
		~InkStack() {
			clear();
		}

		void clear() {
			while (top != nullptr) {
				Link<T> *tmp = top;
				top = top->next;
				delete tmp;
			}
		}

		bool pushH(const T item) {
			Link<T> *tmp = new Link<T>(item, top);
			top = tmp;
			size++;
			return true;
		}

		bool popH(T &item) {
			if (size == 0) {
				return false;
			}
			item = top->data;
			Link<T> *tmp = top->next;
			delete top;
			top = tmp;
			size--;
			return true;
		}

		bool topH(T &item) {
			if (size == 0) {
				return false;
			}
			item = top->data;
			return true;
		}

		bool isEmpty() const {
			return size == 0;
		}
};

class infix2postfix {
	private:
		bool isOperator(char ch) {
			return ch == '+' || ch == '-' || ch == '*' || ch == '/';
		}

		int getPriority(char op) {
			if (op == '*' || op == '/') {
				return 2;
			}
			if (op == '+' || op == '-') {
				return 1;
			}
			return 0;
		}

	public:
		string convert2Postfix(const string &infix) {
			InkStack<char> s;
			string postfix;
			string number; // 用于存储多位数

			for (size_t i = 0; i < infix.size(); ++i) {
				char ch = infix[i];

				if (ch == '=') {
					break; // 遇到等号结束处理
				}

				if (isdigit(ch)) {
					number += ch; // 累加数字字符
					if (i + 1 == infix.size() || !isdigit(infix[i + 1])) { // 如果是最后一个字符或下一个字符不是数字
						postfix += number + " "; // 将多位数添加到后缀表达式，并加空格分隔
						number.clear(); // 清空number，准备下一个数字
					}
				} else if (ch == '(') {
					s.pushH(ch);
				} else if (ch == ')') {
					if (s.isEmpty()) {
						cerr << "括号不匹配" << endl;
						return "";
					}
					char op;
					while (!s.isEmpty()) {
						s.topH(op);
						if (op == '(') {
							s.popH(op);
							break;
						} else {
							s.popH(op);
							postfix += op;
							postfix += ' ';
						}
					}
				} else if (isOperator(ch)) {
					char tp;
					while (!s.isEmpty() && s.topH(tp) && tp != '(' && getPriority(tp) >= getPriority(ch)) {
						char op;
						s.popH(op);
						postfix += op;
						postfix += ' ';
					}
					s.pushH(ch);
				} else if (ch == ' ') {
					continue; // 跳过空格
				} else {
					cerr << "非法字符: " << ch << endl;
					return "";
				}
			}


			while (!s.isEmpty()) {
				char tp;
				if (s.topH(tp) && tp == '(') {
					cerr << "括号不匹配" << endl;
					return "";
				}
				char op;
				s.popH(op);
				postfix += op;
				postfix += ' ';
			}

			// 去掉最后的空格
			if (!postfix.empty() && postfix.back() == ' ') {
				postfix.pop_back();
			}

			return postfix;
		}
};

int main() {
	infix2postfix converter;
	string infix;
	getline(cin, infix);

	string postfix = converter.convert2Postfix(infix);
	if (!postfix.empty()) {
		cout << postfix << endl;
	}
	return 0;
}