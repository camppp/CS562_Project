void circusc_state::draw_sprites(bitmap_ind16 &bitmap, const rectangle &cliprect)
{
	// Iterate through the sprite data
	for (offs = 0; offs < 0x1000; offs += 4)
	{
		// Extract the sprite code, color, and position
		code = m_spriteram[offs];
		color = m_spriteram[offs + 1];
		sx = m_spriteram[offs + 2];
		sy = m_spriteram[offs + 3];

		// Check if the sprite is on the screen
		if (sx >= 0 && sx < 256 && sy >= 0 && sy < 256)
		{
			// Render the sprite on the bitmap
			bitmap.pix(sy, sx) = color;
		}
	}
}
