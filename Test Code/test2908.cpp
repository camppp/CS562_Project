void circusc_state::draw_sprites(bitmap_ind16 &bitmap, const rectangle &cliprect)
{
    int offs;
    uint8_t *sr = m_spritebank ? m_spriteram : m_spriteram_2;

    for (offs = 0; offs < m_spriteram.bytes(); offs += 4)
    {
        int code = sr[offs + 0] + 8 * (sr[offs + 1] & 0x20);
        int color = sr[offs + 1] & 0x0f;
        int sx = sr[offs + 2];
        int sy = sr[offs + 3];

        // Render the sprite on the bitmap within the clipping rectangle
        // Assuming the sprite rendering function is available, use it to render the sprite
        // Example: render_sprite(bitmap, cliprect, code, color, sx, sy);
    }
}
