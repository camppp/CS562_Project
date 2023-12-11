#!/bin/bash

# Input file
input_file="books_input.txt"

# Output file
output_file="organized_books.txt"

# Empty the output file
echo -n > $output_file

# Read the input file line by line
while IFS= read -r line
do
    # If the line is not the end of the book list
    if [ "$line"!= "END_OF_BOOKS" ]
    then
        # Split the line into book, author, and category
        IFS='|' read -r -a array <<< "$line"
        book=${array[0]}
        author=${array[1]}
        category=${array[2]}

        # Write the book, author, and category to the output file
        echo "$book $author $category" >> $output_file
    fi
done < "$input_file"