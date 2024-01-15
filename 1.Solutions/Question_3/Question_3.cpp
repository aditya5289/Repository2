// Question_3.cpp
#include <iostream>
#include <fstream>
#include <limits>

long long calculateFactorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n * calculateFactorial(n - 1);
}

int main()
{
    std::ofstream outputFile("factorials.csv");

    if (!outputFile.is_open())
    {
        std::cerr << "Error opening file for writing." << std::endl;
        return 1;
    }

    for (int i = 0; i < 10; ++i)
    {
        std::cout << "Enter a number: ";
        int num;
        std::cin >> num;

        // Perform input validation
        while (std::cin.fail() || num < 0)
        {
            std::cin.clear();                                                   // Clear input buffer to restore cin to a usable state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore last input
            std::cout << "Invalid input. Please enter a non-negative integer: ";
            std::cin >> num;
        }

        // Calculate factorial
        long long factorial = calculateFactorial(num);

        // Write to file
        outputFile << num << "," << factorial << std::endl;
    }

    outputFile.close();

    return 0;
}
