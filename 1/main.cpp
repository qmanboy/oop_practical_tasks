#include <iostream>
#include <cmath>
#include <cstdint>

class Power {
    private:
        double m_num1 = 2.7;
        double m_num2 = 3.2;
    public:
        void set(double num1, double num2) {
            m_num1 = num1;
            m_num2 = num2;
        }    
        void calculate() {
            std::cout << m_num1 << " ^ " << m_num2 << "\n";
            std::cout << "calculate: " << pow(m_num1, m_num2) << "\n";
        }
};

class RGBA {
    private:
        std::uint8_t m_red = 0;
        std::uint8_t m_green = 0;
        std::uint8_t m_blue = 0;
        std::uint8_t m_alpha = 255;
    public:
        RGBA() {
        }
        RGBA(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha)
        : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha) {
        }
        void print() {
            std::cout << "red: " << m_red
            << "\ngreen: " << m_green
            << "\nblue: " << m_blue
            << "\nalpha: " << m_alpha << "\n";
        }
};

class Stack {
    private:
        int m_arr[10]{0};
        int m_stacklen = 0;
    public:
        void reset(){
            for (int i = 0; i < m_stacklen; i++)
                m_arr[i] = 0;
            m_stacklen = 0;
        }
        bool push(int num){
            if (m_stacklen == 10)
                return false;
            m_arr[m_stacklen] = num;
            m_stacklen++;
            return true;
        }
        int pop() {
            if (m_stacklen == 0) {
                std::cout << "Stack is empty\n";
                return -1;
            }
            else {
                int temp = m_arr[m_stacklen];
                m_arr[m_stacklen] = 0;
                m_stacklen--;
                return temp;
            }

        }
        void print() {
            std::cout << "(";
            for (int i = 0; i < m_stacklen; i++)
                std::cout << " " << m_arr[i];
            std::cout << " )\n";
        }
};

int main() {

    Power pwr;    
    pwr.calculate();
    pwr.set(3.4, 4.5);
    pwr.calculate();

    RGBA rgba_one;
    rgba_one.print();
    RGBA rgba_two(65, 97, 90, 122);
    rgba_two.print();

    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

    return 0;
}