#!/bin/bash

# Get the variable name and CSV file path from the command-line arguments
VAR_NAME=$1
CSV_FILE=$2

# Create a new DataTable with the specified variable name
echo "var $VAR_NAME = new google.visualization.DataTable();"

# Add columns for the data in the CSV file
echo "$VAR_NAME.addColumn('string', 'Owner');"
echo "$VAR_NAME.addColumn('string', 'Name');"
echo "$VAR_NAME.addColumn('string', 'Type');"
echo "$VAR_NAME.addColumn('number', 'Container');"
echo "$VAR_NAME.addColumn('boolean', 'Result');"

# Read the CSV file and add rows to the DataTable
while IFS=, read -r OWNER NAME TYPE CONTAINER RESULT; do
  echo "$VAR_NAME.addRow([$OWNER, $NAME, $TYPE, $CONTAINER, $RESULT]);"
done < $CSV_FILE