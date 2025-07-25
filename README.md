# Infix to Postfix Converter (C)

## Overview
This program converts an infix expression (e.g., `A+B*C`) into its equivalent postfix expression (e.g., `ABC*+`). It uses a stack-based algorithm implemented manually using a fixed-size character array.

## Features
- Converts infix to postfix notation  
- Supports operators: `+`, `-`, `*`, `/`, `^`  
- Handles parentheses for grouping  
- Accepts alphanumeric operands  
- Simple custom stack implementation  

## File
All logic is contained in a single C file: `main.c`

## Compilation
Compile using any standard C compiler:

```bash
gcc main.c -o infix2postfix
```

## Execution
Run the program:

```bash
./infix2postfix
```

It will prompt for an infix expression.

## Example

**Input:**
```
Enter infix exp
A+B*C
```

**Output:**
```
Postfix Exp: ABC*+
```

## Limitations
- Only single-character operands supported  
- No error handling for invalid expressions  
- Stack size is fixed at 999 elements  

