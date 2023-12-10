javascript
function drawShape(canvas, shapeType, x1, y1, x2, y2) {
  if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0 || x1 >= canvas.length || y1 >= canvas[0].length || x2 >= canvas.length || y2 >= canvas[0].length) {
    return canvas; // Invalid coordinates, return original canvas
  }

  switch (shapeType) {
    case "rectangle":
      for (let i = x1; i <= x2; i++) {
        for (let j = y1; j <= y2; j++) {
          canvas[i][j] = "R";
        }
      }
      break;
    case "circle":
      const centerX = x1;
      const centerY = y1;
      const radius = Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
      for (let i = 0; i < canvas.length; i++) {
        for (let j = 0; j < canvas[0].length; j++) {
          if (Math.pow(i - centerX, 2) + Math.pow(j - centerY, 2) <= Math.pow(radius, 2)) {
            canvas[i][j] = "C";
          }
        }
      }
      break;
    case "line":
      const dx = Math.abs(x2 - x1);
      const dy = Math.abs(y2 - y1);
      const sx = (x1 < x2) ? 1 : -1;
      const sy = (y1 < y2) ? 1 : -1;
      let err = dx - dy;
      let x = x1;
      let y = y1;
      while (true) {
        canvas[x][y] = "L";
        if (x === x2 && y === y2) {
          break;
        }
        const e2 = 2 * err;
        if (e2 > -dy) {
          err -= dy;
          x += sx;
        }
        if (e2 < dx) {
          err += dx;
          y += sy;
        }
      }
      break;
    default:
      return canvas; // Invalid shape type, return original canvas
  }

  return canvas;
}
