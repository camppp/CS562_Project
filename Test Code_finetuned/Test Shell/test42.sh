#!/bin/bash

# Use jq to slurp and sort the keys of the JSON data from person.json
json_keys=$(jq -S. person.json)

# Use Y2J to convert the YAML data from person.yaml to JSON format
yaml_keys=$(Y2J person.yaml | jq -S.)

# Compare the JSON data from person.json with the JSON data from person.yaml
if [ "$json_keys" = "$yaml_keys" ]; then
    echo "The files contain identical data"
    exit 0
else
    echo "The files do not contain identical data"
    exit 1
fi