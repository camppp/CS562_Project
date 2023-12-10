function rangeContainsTableCellBoundary(start, end) {
  // Get the table element that contains the range
  const table = document.getElementById('sample');

  // Get the table cell that contains the start position
  const startCell = table.querySelector('td[id="td2"]');

  // Get the table cell that contains the end position
  const endCell = table.querySelector('td[id="td2"]');

  // Check if the start and end positions are in the same table cell
  if (startCell === endCell) {
    return true;
  }

  // Check if the start position is in a table cell and the end position is not
  if (startCell && !endCell) {
    return true;
  }

  // Check if the start position is not in a table cell and the end position is in a table cell
  if (!startCell && endCell) {
    return true;
  }

  // Check if the start and end positions are in different table cells
  if (startCell && endCell && startCell !== endCell) {
    return true;
  }

  // If none of the above conditions are met, the range does not contain a table cell boundary
  return false;
}
