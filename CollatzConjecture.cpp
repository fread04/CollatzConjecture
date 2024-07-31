#include <iostream>
#include <string>
#include <vector>

void collatz(std::string& n, std::string& max, int& steps, std::vector<std::string>& sequence);
std::string collatz_step_up(std::string& n);
std::string collatz_step_down(std::string& n);
bool isEven(std::string& n);
bool isValidInteger(const std::string& n);

int main()
{
    std::string n;
    while (true) 
    {
        std::cout << "Enter your number: ";
        std::getline(std::cin >> std::ws, n);

        if (!isValidInteger(n)) {
            std::cout << "Invalid input. Please enter an integer.\n";
            continue;
        }

        n.erase(0, n.find_first_not_of('0')); // remove leading zeros
        break;
    }

    std::string max{ n };
    int steps{ 0 };
    std::vector<std::string> sequence;

    collatz(n, max, steps, sequence);

    std::cout << "Sequence: ";
    for (const auto& num : sequence) {
        std::cout << num << " ";
    }

    std::cout << "\nMax: " << max;
    std::cout << "\nSteps: " << steps;
}

// main function, that calculates Collatz Conjecture
void collatz(std::string& n, std::string& max, int& steps, std::vector<std::string>& sequence)
{
    sequence.push_back(n);  // Store the initial number
    
    while (n.compare("1"))
    {
        n = isEven(n) ? collatz_step_down(n) : collatz_step_up(n); // increase or decrease number
        if (n.length() > max.length() || (n.length() == max.length() && n > max)) // compare n with max
        {
            max = n;
        }
        steps++;
        
        sequence.push_back(n);  // Store each number in the sequence
    }
}

// calculates increased number n = 3 * n + 1
std::string collatz_step_up(std::string& n)
{
    if (n.empty())
    {
        return "1";
    }

    int carry = 1; // instead of adding 1 separately after multiplying by 3, we can start with carry = 1
    for (auto it = n.rbegin(); it != n.rend(); ++it) // we iterate using reverse iterators 
    {
        int digit = *it - '0'; // create temp value, dereferencing current number
        int new_digit = digit * 3 + carry;
        *it = (new_digit % 10) + '0'; // write number back
        carry = new_digit / 10;
    }

    if (carry > 0) // add final carried number if needed
    {
        n.insert(n.begin(), carry + '0');
    }

    return n;
}

// calculates decreased number n = n / 2
std::string collatz_step_down(std::string& n)
{
    if (n.empty())
    {
        return "1";
    }

    int remainder = 0;
    for (auto it = n.begin(); it != n.end(); ++it) // we iterate using reverse iterators 
    {
        int digit = *it - '0'; // create temp value, dereferencing current number
        int new_digit = (digit + remainder * 10);
        *it = (new_digit / 2) + '0'; // write number back
        remainder = new_digit % 2;
    }
    
    n.erase(0, n.find_first_not_of('0')); // remove leading zeros

    return n;
}

// returns true if last symbol of a string is even
bool isEven(std::string& n)
{
    if (n.empty())
    {
        return 0;
    }

    return (n.back() - '0') % 2 == 0;
}

// checks if string contains valid number
bool isValidInteger(const std::string& n) {
    if (n.empty()) 
    {
        return false;
    } 

    return n.find_first_not_of("0123456789", 0) == std::string::npos;
}
