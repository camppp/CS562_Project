# Define the lazy_load_clean function
lazy_load_clean() {
  local func_name=$1
  local func_file=$2

  # Check if the function is already defined
  if [ -z "$(type -t $func_name)" ]; then
    # Load the function from the file
    source $func_file
  fi
}

# Define the load_func variable
load_func="lazy_load_clean"

# Now you can use the load_func variable to load functions lazily
$load_func my_function my_function.sh