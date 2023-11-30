# Binary Calculator README

## Program Description

This program is a binary calculator that performs bitwise operations on binary, decimal, and hexadecimal numbers. It supports operations such as AND, OR, XOR, NOR, left shift, and right shift. The user can choose the input and output number systems (binary, decimal, or hexadecimal) and perform bitwise operations accordingly.

### Parts of the Program

1. **Main Function:**
   - The main function initializes variables for the input and output bases, as well as the two values on which bitwise operations will be performed.
   - It contains a loop that allows the user to perform multiple operations until they choose to exit.
   - Within this loop, the program prompts the user for the input and output bases and the two numbers on which to perform bitwise operations.
   - It then displays the operations menu and performs the selected operation using the `bitwise_operation` function.

2. **Display Operations Menu Function (`display_operations_menu`):**
   - This function simply prints the menu of bitwise operations for the user to choose from.

3. **Bitwise Operation Function (`bitwise_operation`):**
   - This function takes the user's choice, the two values, and the input and output bases as parameters.
   - It performs the selected bitwise operation and displays the result in the chosen number system.

4. **Input Validation and Conversion Functions (`char_to_digit`, `hex_char_to_digit`, `convert_digit`, `validate_and_convert`, `input_num_validation`):**
   - These functions handle the conversion and validation of input numbers based on the chosen number system.
   - They ensure that the input is valid and convert it into the corresponding integer representation.

## Compilation and Execution Instructions

1. **Compilation:**
   - Open a terminal window.
   - Navigate to the directory containing the source code file (`binary_calculator.c`).
   - Compile the program using a C compiler (e.g., gcc):
     ```bash
     gcc -o binary_calculator binary_calculator.c
     ```

2. **Execution:**
   - Run the compiled program:
     ```bash
     ./binary_calculator
     ```

## User Manual

1. **Number System Selection:**
   - When prompted, enter the number system for input (2 for binary, 10 for decimal, 16 for hexadecimal).
   - Repeat the process for the output number system.

2. **Input of Numbers:**
   - Enter the first and second numbers according to the chosen input number system.
   - For binary, prefix the number with '0b' (e.g., 0b1101).
   - For hexadecimal, prefix the number with '0x' (e.g., 0xABCD).
   - For decimal, prefix the number with '0d' (e.g., 0d123).

3. **Bitwise Operations:**
   - Choose an operation from the displayed menu (1-6).
   - The program will perform the selected operation on the two input numbers.
   - The result will be displayed in the chosen output number system.

4. **Change Number System:**
   - Select option 7 to change the input and output number systems.
   - Repeat the number system selection and perform bitwise operations accordingly.

5. **Exit Program:**
   - Select option 8 to exit the program.


