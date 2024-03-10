#include <stdio.h>
#include <math.h>

int main() {
    // Declare variables
    char op;
    double result = 0, num;
    int inputCount = 0;

    // Display welcome message and instructions
    printf("Welcome to the Calculator Program!\n");
    printf("Enter values and operators to perform calculations (+,-,*,/,^).\n");
    printf("To end the program, enter 'q' and press Enter for Result.\n\n");

    // Main program loop
    while (1) {
        // Check if it's the first input or not
        if (inputCount == 0) {
            printf("Enter value: ");
            // Read the first number
            if (scanf("%lf", &num) != 1) {
                printf("Invalid input. Please enter a number.\n");
                return 1; // Exit with an error code
            }
            result = num; // Initialize result with the first number
            inputCount++;
        } else {
            // Ask for operator or to quit
            printf("Enter operator or quit (q to quit): ");
            // Read the operator
            if (scanf(" %c", &op) != 1) {
                printf("Invalid input. Please enter an operator or a number.\n");
                return 1; // Exit with an error code
            }

            // Check if the user wants to quit
            if (op == 'q' || op == 'Q') {
                printf("Program terminated. Result: %.2lf\n", result);
                break; // Exit the loop
            }

            // Check for valid operators
            if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^') {
                printf("Enter value: ");
                // Read the next number
                if (scanf("%lf", &num) != 1) {
                    printf("Invalid input. Please enter a number.\n");
                    return 1; // Exit with an error code
                }

                // Perform calculations based on the operator
                switch (op) {
                    case '+':
                        result += num;
                        break;
                    case '-':
                        result -= num;
                        break;
                    case '*':
                        result *= num;
                        break;
                    case '/':
                        // Check for division by zero
                        if (num != 0) {
                            result /= num;
                        } else {
                            printf("Error: Division by zero\n");
                            return 1; // Exit with an error code
                        }
                        break;
                    case '^':
                        result = pow(result, num);
                        break;
                }

                inputCount++;
            } else {
                // Invalid operator entered
                printf("Invalid operator. Please enter a valid operator (+, -, *, /, ^) or 'q' to quit.\n");
                return 1; // Exit with an error code
            }
        }
    }

    // Exit the program with success code
    return 0;
}





