void rsm_t::_read() {
    // Initialize member variables
    m_scale_key_frames = 0;
    m_volume_boxes = 0;

    // Read magic value from input stream
    uint32_t magic = m_io->read_u4le();

    // Validate magic value
    if (magic != 0x4752534D) { // GRSM
        throw kaitai::validation_not_equal_error("Invalid magic value", magic, 0x4752534D);
    }

    // Read scale key frames and volume boxes
    m_scale_key_frames = m_io->read_u4le();
    m_volume_boxes = m_io->read_u4le();

    // Update member variables
    m_scale_key_frames = m_io->read_u4le();
    m_volume_boxes = m_io->read_u4le();
}
