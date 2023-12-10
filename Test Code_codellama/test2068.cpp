String interactWithMaterial(int ix, int iy) {
    if (ix < 0 || iy < 0 || ix >= game.level.N || iy >= game.level.M) {
        return "Out of bounds";
    }
    Material m = game.level.mat(ix, iy);
    return m.toString();
}
