# Collatz Conjecture Calculator

This program implements the Collatz sequence calculation (also known as the 3n+1 problem) for large numbers using string representation.

## Description

The Collatz conjecture states that for any positive integer n, if we apply the following operations:
- if n is even, divide it by 2
- if n is odd, multiply it by 3 and add 1

we will always eventually reach the number 1, regardless of which number we start with.

## Functionality

The program performs the following actions:
1. Prompts the user to input a number.
2. Checks the validity of the entered number.
3. Calculates the Collatz sequence for the entered number.
4. Finds the maximum number in the sequence.
5. Counts the number of steps to reach 1.
6. Outputs the full sequence, maximum number, and step count.

## Usage

1. Run the program.
2. Enter a positive integer when prompted.
3. The program will output the Collatz sequence, the maximum number reached, and the number of steps.

## Implementation Details

- The program uses string representation of numbers to work with very large numbers exceeding standard data types.
- Separate functions are implemented for increasing the number (3n+1) and decreasing (n/2).
- Input validation ensures that only valid integers are processed.

## Limitations

- The program works only with positive integers.
- Very large numbers may result in long execution times.

## Future Improvements

- Add the ability to save results to a file.
- Implement multithreading to speed up calculations.
- Add visualization of the sequence.
