#include <stdio.h>
#include <string.h>

void display_operations_menu();
int char_to_digit(char c);
int hex_char_to_digit(char c);
int convert_digit(int base, char c);
int validate_and_convert(int numSystem, char *inputNumber, int *num);
int input_num_validation(int numSystem, int *num);
void bitwise_operation(int choice, int val1, int val2, int outputBase);

int main()
{
    int inputBase, outputBase, val1, val2;
    int exit = 1;

    while (exit)
    { // validiating input system
        printf("Enter number system for input (2 for binary, 10 for decimal, 16 for hexadecimal): ");
        while (scanf(" %d", &inputBase) != 1)
        {
            printf("Invalid input. Please enter a valid number: ");
            while (getchar() != '\n'); // Clearing input buffer
        }

        while (inputBase != 2 && inputBase != 10 && inputBase != 16)
        {
            printf("Invalid number system. Please try again: ");
            while (scanf(" %d", &inputBase) != 1)
            {
                printf("Invalid input. Please enter a valid number: ");
                while (getchar() != '\n');
            }
            while (getchar() != '\n');
        }

        printf("Enter number system for output (2 for binary, 10 for decimal, 16 for hexadecimal): ");
        while (scanf("%d", &outputBase) != 1)
        { // validiating output system
            printf("Invalid input. Please enter a valid number: ");
            while (getchar() != '\n');
        }

        while (outputBase != 2 && outputBase != 10 && outputBase != 16)
        {
            printf("Invalid number system. Please try again: ");
            while (scanf(" %d", &outputBase) != 1)
            {
                printf("Invalid input. Please enter a valid number: ");
                while (getchar() != '\n');
            }
            while (getchar() != '\n');
        }

        while (1)
        { // getting input numbers
            do
            {
                printf("Enter the first number ");
            } while (!input_num_validation(inputBase, &val1));
            do
            {
                printf("Enter the second number ");
            } while (!input_num_validation(inputBase, &val2));

            display_operations_menu();

            int op;
            while (scanf("%d", &op) != 1)
            {
                printf("Invalid input. Please enter a valid number: ");
                while (getchar() != '\n');
            }

            if (op >= 1 && op <= 6)
            {
                bitwise_operation(op, val1, val2, outputBase);
            }
            else if (op == 7)
            {
                break; // Change number system
            }
            else if (op == 8)
            { // Exit
                printf("Exiting the program.\n");
                exit = 0;
                break;
            }
            else
            {
                printf("Invalid choice. Please try again.\n");
            }
        }
    }
    return 0;
}

void display_operations_menu()
{
    printf("\nOperations Menu:\n");
    printf("1. AND\n");
    printf("2. OR\n");
    printf("3. XOR\n");
    printf("4. NOR\n");
    printf("5. Left Shift\n");
    printf("6. Right Shift\n");
    printf("7. Change Number System\n");
    printf("8. Exit\n");
    printf("Choose operation: ");
}

int char_to_digit(char c)
{
    return c - '0'; // converting chars with 10 and 2 base
}

int hex_char_to_digit(char c) // converting chars with 16 base
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    else if (c >= 'a' && c <= 'f')
    {
        return c - 'a' + 10;
    }
    else if (c >= 'A' && c <= 'F')
    {
        return c - 'A' + 10;
    }
    else
    {
        return -1;
    }
}

int convert_digit(int base, char c) // for converting 10, 2, 16 base chars
{
    if (base == 2 || base == 10)
    {
        return char_to_digit(c);
    }
    else if (base == 16)
    {
        return hex_char_to_digit(c);
    }
    else
    {
        return -1;
    }
}

int validate_and_convert(int inputBase, char *inputNumber, int *num) // Validate input based on the number system
{
    *num = 0;
    for (int i = 2; i < strlen(inputNumber); i++)
    {
        int digit = convert_digit(inputBase, inputNumber[i]);
        if (digit == -1)
        {
            printf("Invalid input. Try again.\n");
            return 0;
        }
        *num = (*num * inputBase) + digit;
    }
    return 1;
}

int input_num_validation(int inputBase, int *num)
{
    char inputNumber[20];
    scanf("%s", inputNumber);

    if (!validate_and_convert(inputBase, inputNumber, num)) // Validate and convert input
    {
        return 0;
    }

    if (inputBase == 2)
    {
        if (inputNumber[0] != '0' || inputNumber[1] != 'b')
        { //  for skipping first two characters before validating the binary digits.
            printf("Invalid binary input, input should start with 0b . Try again.\n");
            return 0;
        }
        for (int i = 2; i < strlen(inputNumber); i++)
        { // aditional validiation for base 2, since char_to_digit funcion only makes converts
            if (inputNumber[i] != '0' && inputNumber[i] != '1')
            {
                printf("Invalid binary input. Try again.\n");
                return 0;
            }
        }
    }

    if (inputBase == 16)
    { // for skipping first two characters before validating the hexadecimal digits.
        if (inputNumber[0] != '0' || inputNumber[1] != 'x')
        {
            printf("Invalid hexadecimal input, input should start with 0x . Try again.\n");
            return 0;
        }
    }

    if (inputBase == 10)
    { // for skipping first two characters before validating the decimal digits.
        if (inputNumber[0] != '0' || inputNumber[1] != 'd')
        {
            printf("Invalid decimal input, input should start with 0d . Try again.\n");
            return 0;
        }
        for (int i = 2; i < strlen(inputNumber); i++)
        { // Additional validation for decimal base, since char_to_digit funcion only makes converts
            if (inputNumber[i] < '0' || inputNumber[i] > '9')
            {
                printf("Invalid decimal input. Try again.\n");
                return 0;
            }
        }
    }
    return 1;
}

void bitwise_operation(int op, int val1, int val2, int outputBase)
{ // getting result 
    int res;

    if (op == 1)
    {
        res = val1 & val2;
    }
    else if (op == 2)
    {
        res = val1 | val2;
    }
    else if (op == 3)
    {
        res = val1 ^ val2;
    }
    else if (op == 4)
    {
        res = ~(val1 | val2);
    }
    else if (op == 5)
    {
        res = val1 << val2;
    }
    else if (op == 6)
    {
        res = val1 >> val2;
    }
    else
    {
        printf("Invalid choice.\n");
        return;
    }

    printf("\n");
    if (outputBase == 2)
    {
        for (int i = 31; i >= 0; i--)
        {
            printf("%d", (res >> i) & 1);
        }
        printf("\n");
    }
    else if (outputBase == 10)
    {
        printf("%d\n", res);
    }
    else
    {
        printf("%X\n", res);
    }
}

//