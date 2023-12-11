#!/bin/bash

fileArray=("file1.txt" "file2.csv" "file3.xls" "file4.csv" "file5.txt")

for file in "${fileArray[@]}"
do
    if [[ $file == *.csv ]]
    then
        echo "Skipping"
    else
        echo "Processing $file"
        # Add your custom action here
    fi
done