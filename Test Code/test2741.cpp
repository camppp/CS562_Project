java
public List<Bullet> updateBullets(List<Bullet> bullets, float dt) {
    List<Bullet> updatedBullets = new ArrayList<>();

    for (Bullet b : bullets) {
        b.update(dt);
        if (b.getPosition().x > -1) {
            updatedBullets.add(b);
        }
    }

    return updatedBullets;
}
