void drawShape(char canvas[][4], string shapeType, int x1, int y1, int x2, int y2) {
  if (shapeType == "rectangle") {
    for (int i = x1; i <= x2; i++) {
      for (int j = y1; j <= y2; j++) {
        canvas[i][j] = 'R';
      }
    }
  } else if (shapeType == "circle") {
    int radius = abs(x2 - x1);
    for (int i = x1 - radius; i <= x1 + radius; i++) {
      for (int j = y1 - radius; j <= y1 + radius; j++) {
        if (i * i + j * j <= radius * radius) {
          canvas[i][j] = 'C';
        }
      }
    }
  } else if (shapeType == "line") {
    for (int i = x1; i <= x2; i++) {
      canvas[i][y1] = 'L';
    }
  } else {
    return;
  }
}
