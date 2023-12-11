void draw(uint16_t anim) {
    switch (state) {
        case MAN_ST_STAND:
            if (count >= 20) state = MAN_ST_STAND;
            break;
        case MAN_ST_WALK:
            if (count >= 40) state = MAN_ST_STAND;
            break;
        case MAN_ST_DAMAGED:
            count++;
            if (count >= 40) state = MAN_ST_STAND;
            break;
        default:
            break;
    }
}
