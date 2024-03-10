    #include <stdio.h>
    #include <math.h>
    
    int main() {
        char op;
        double result = 0, num;
        int inputCount = 0;
    
        printf("Welcome to the Calculator Program!\n");
        printf("Enter values and operators to perform calculations (+,-,*,/,^).\n");
        printf("To end the program, enter 'q' and press Enter for Result.\n\n");
    
        while (1) {
            if (inputCount == 0) {
                printf("Enter value: ");
                if (scanf("%lf", &num) != 1) {
                    printf("Invalid input. Please enter a number.\n");
                    return 1;
                }
                result = num;
                inputCount++;
            } else {
                printf("Enter operator or quit (q to quit): ");
                if (scanf(" %c", &op) != 1) {
                    printf("Invalid input. Please enter an operator or a number.\n");
                    return 1;
                }
    
                if (op == 'q' || op == 'Q') {
                    printf("Program terminated. Result: %.2lf\n", result);
                    break;
                }
    
                if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^') {
                    printf("Enter value: ");
                    if (scanf("%lf", &num) != 1) {
                        printf("Invalid input. Please enter a number.\n");
                        return 1;
                    }
    
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
                            if (num != 0) {
                                result /= num;
                            } else {
                                printf("Error: Division by zero\n");
                                return 1;
                            }
                            break;
                        case '^':
                            result = pow(result, num);
                            break;
                    }
    
                    inputCount++;
                } else {
                    printf("Invalid operator. Please enter a valid operator (+, -, *, /, ^) or 'q' to quit.\n");
                    return 1;
                }
            }
        }
    
        return 0;
    }
