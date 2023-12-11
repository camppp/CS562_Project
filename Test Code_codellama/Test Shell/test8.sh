#!/bin/bash

# Set the input and output files
input_file="books_input.txt"
output_file="organized_books.txt"

# Read the input file and write the organized information to the output file
awk -F "|" '{print $1 " " $2 " " $3}' $input_file > $output_file