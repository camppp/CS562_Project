javascript
class Rectangle {
    constructor(width, height) {
        this.width = width;
        this.height = height;
    }

    getArea() {
        return this.width * this.height;
    }
}

const rect = new Rectangle(5, 10);
console.log(rect.getArea()); // Output: 50
