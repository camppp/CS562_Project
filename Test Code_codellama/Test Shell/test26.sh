create_library() {
  local target_dir="$1"
  local link_flag="$2"

  if [ -z "$target_dir" ]; then
    usage
    exit 1
  fi

  if [ "$link_flag" = "--link" ]; then
    # Create symbolic links for easy testing
    for file in *; do
      ln -s "$file" "$target_dir"
    done
  else
    # Overwrite existing files in the target directory
    for file in *; do
      cp "$file" "$target_dir"
    done
  fi
}