# c-polite
A more polite language, relying on saying please and thank you to the computer.

Use ./please_run -h for more info.

Write C Polite commands in a .cpol file

cpol commands:
please - Asks the computer nicely to do a command (required)
usage: please <command>

println - Prints a message with a line break
usage: println <message> donethankyoucomputer

print - Prints a message
usage: print <message> donethankyoucomputer

printvar: Prints the value of a variable (no line break)
usage: printvar <1-10>

input - Allows user specified input fed into one of the ten variables
usage: input <1-10>

add - Adds two numbers (use "$ " before variable indexes)
example: add $ 1 4 ... adds variable 1 and 4
usage: add <destination> <num1> <num2>

thankyou - Ends the program nicely (required)
usage: thankyou
