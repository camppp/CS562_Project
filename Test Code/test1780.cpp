javascript
function rangeContainsTableCellBoundary(start, end) {
  // Get the common ancestor container of the start and end positions
  const commonAncestor = start.commonAncestorContainer;

  // Check if the common ancestor is a table cell or contains a table cell
  if (commonAncestor.tagName === 'TD' || commonAncestor.closest('td')) {
    return true; // Range contains a table cell boundary
  }

  return false; // Range does not contain a table cell boundary
}
