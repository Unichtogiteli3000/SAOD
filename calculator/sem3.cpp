#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

int main(int argc, char* argv[]) {
    try {
        if (argc != 4) {
            std::cerr << "Input must be: program_name operation1 operation2" << std::endl;
        }

        int num1 = std::stoi(argv[2]);
        int num2 = std::stoi(argv[3]);
        std::string operation = argv[1];

        if (operation == "add") {
            std::cout << "Result: " + std::to_string(num1 + num2) << std::endl;
        }
        else if (operation == "sub") {
            std::cout << "Result: " + std::to_string(num1 - num2) << std::endl;
        }
        else if (operation == "mul") {
            std::cout << "Result: " + std::to_string(num1 * num2) << std::endl;
        }
        else if (operation == "div") {
            if (num2 == 0) {
                std::cerr << "Divide by zero!" << std::endl;
            }
            std::cout << "Result: " + std::to_string(num1 / num2) << std::endl;
        }
        else {
            std::cerr << "Incorrect operation. Use add, sub, mul, div" << std::endl;
        }
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Argument is out of range:" << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Two last arguments must be integers" << std::endl;
    }
}