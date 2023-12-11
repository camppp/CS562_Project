#!/bin/bash

while IFS= read -r line
do
    if [ "$line" = "exit" ]; then
        exit 1
    elif [ "$line" = "fi" ]; then
        continue
    else
        eval $line
    fi
done < "$1"