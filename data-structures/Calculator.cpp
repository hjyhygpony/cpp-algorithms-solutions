#include <iostream>
#include <string>
#include <sstream>

template <class T>

class Link {
	public:
		T data;
		Link<T> *next;

		Link(const T info, Link<T> *nextValue = nullptr) {
			data = info;
			next = nextValue;
		}

		Link(Link<T> *nextValue = nullptr) {
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
			size = 0;
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
			Link<T> *tmp = top;
			top = top->next;
			delete tmp;
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

		bool isFull() const {
			return false;
		}
};

class Calculator {
	private:
		InkStack<int> s;

		bool GetTwoOperands(int &opd1, int &opd2) {
			if (!s.popH(opd1)) {
				std::cout << "Missing operand!" << std::endl;
				return false;
			}
			if (!s.popH(opd2)) {
				std::cout << "Missing operand!" << std::endl;
				return false;
			}
			return true;
		}

		void Compute(char op) {
			int operand1, operand2;
			if (GetTwoOperands(operand1, operand2)) {
				switch (op) {
					case '+':
						s.pushH(operand2 + operand1);
						break;
					case '-':
						s.pushH(operand2 - operand1);
						break;
					case '*':
						s.pushH(operand2 * operand1);
						break;
					case '/':
						if (operand1 == 0) {
							std::cout << "Divide by 0!" << std::endl;
							s.clear();
						} else {
							s.pushH(operand2 / operand1);
						}
						break;
				}
			}
		}

	public:
		void Run() {
			std::string token;
			while (std::cin >> token && token != "@") {
				if (token == "+" || token == "-" || token == "*" || token == "/") {
					Compute(token[0]);
				} else {
					// 处理数字（可能是多位数）这种方法更加简单运用到了标准库，但没有biaodashi中的方法灵活，建议还是用那个
					int num;
					std::istringstream iss(token);
					if (iss >> num) {
						s.pushH(num);
					} else {
						std::cout << "Invalid input: " << token << std::endl;
						s.clear();
						return;
					}
				}
			}

			int result;
			if (s.popH(result)) {
				if (s.isEmpty()) {
					std::cout << result << std::endl;
				} else {
					std::cout << "Invalid expression: extra operands left!" << std::endl;
				}
			} else {
				std::cout << "No result!" << std::endl;
			}
		}
};

int main() {
	Calculator calc;
	calc.Run();
	return 0;
}