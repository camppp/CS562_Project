public List<Bullet> updateBullets(List<Bullet> bullets, float dt) {
    List<Bullet> updatedBullets = new ArrayList<>();
    for (Bullet bullet : bullets) {
        bullet.update(dt);
        if (bullet.getPosition().x >= -1) {
            updatedBullets.add(bullet);
        }
    }
    return updatedBullets;
}
