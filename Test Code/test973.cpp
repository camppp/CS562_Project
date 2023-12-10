auto window::handle_events() -> void
{
    SDL_Event ev;

    while(static_cast<bool>(SDL_PollEvent(&ev))) {
        switch(ev.type) {
        case SDL_QUIT: {
            m_should_close = true;
            break;
        }
        case SDL_KEYDOWN: {
            m_last_key_pressed = ev.key.keysym.sym;
            break;
        }
        }
    }
}
