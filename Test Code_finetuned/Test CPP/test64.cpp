function drawShape(canvas, shapeType, x1, y1, x2, y2) {
    // Check if the canvas is a 2D array
    if (!Array.isArray(canvas) ||!canvas.every(row => Array.isArray(row))) {
        return canvas;
    }

    // Check if the shapeType is valid
    if (shapeType!== "rectangle" && shapeType!== "circle" && shapeType!== "line") {
        return canvas;
    }

    // Check if the coordinates are within the canvas boundaries
    if (x1 < 0 || x1 >= canvas[0].length || y1 < 0 || y1 >= canvas.length || x2 < 0 || x2 >= canvas[0].length || y2 < 0 || y2 >= canvas.length) {
        return canvas;
    }

    // Draw the shape
    for (let y = y1; y <= y2; y++) {
        for (let x = x1; x <= x2; x++) {
            if (shapeType === "rectangle") {
                canvas[y][x] = "R";
            } else if (shapeType === "circle") {
                let dx = x - x1;
                let dy = y - y1;
                if (dx * dx + dy * dy <= (x2 - x1) * (x2 - x1)) {
                    canvas[y][x] = "C";
                }
            } else if (shapeType === "line") {
                let dx = x2 - x1;
                let dy = y2 - y1;
                let d = Math.abs(dx * y - dy * x);
                let d2 = Math.abs(dx * y1 - dy * x1);
                if (d <= d2) {
                    canvas[y][x] = "L";
                }
            }
        }
    }

    return canvas;
}