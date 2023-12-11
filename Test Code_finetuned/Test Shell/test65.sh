testSyncCatalogClusterRole() {
  local chart_dir="$1"
  local expected_result="$2"

  # Change directory to the chart directory
  cd "$chart_dir" || exit 1

  # Use Helm to template the chart and extract the content of a specific YAML file
  local sync_catalog_clusterrole_content
  sync_catalog_clusterrole_content=$(helm template../charts/sync-catalog-clusterrole.yaml | yq 'length > 0')

  # Store the result of the filter in a variable
  local result
  result=$(echo "$sync_catalog_clusterrole_content" | tee /dev/stderr)

  # Assert that the result is equal to the expected result
  if [ "$result"!= "$expected_result" ]; then
    echo "Test failed: Expected $expected_result, but got $result"
    exit 1
  fi
}