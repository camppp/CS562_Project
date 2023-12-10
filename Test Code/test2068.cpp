java
String interactWithMaterial(int ix, int iy) {
    if (ix < 0 || ix >= game.level.width() || iy < 0 || iy >= game.level.height()) {
        return "Out of bounds";
    } else {
        Material m = game.level.mat(ix, iy);
        return m.getType();
    }
}
