handle_error() {
  local error_message="$1"
  echo "Error: $error_message" >&2
  cd ..
  exit 1
}