handle_error() {
    echo "$1" >&2
    cd..
    exit 1
}

#!/bin/bash

# Some code here...

if [ $? -ne 0 ]; then
    handle_error "An error occurred!"
fi