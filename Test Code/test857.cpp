python
def update_menu_display(menu_show: bool, toggle_ai_show: bool, resume_show: bool) -> dict:
    display_status = {}
    if menu_show:
        display_status['menu'] = True
        if toggle_ai_show:
            display_status['toggle_ai'] = True
            if resume_show:
                display_status['resume'] = True
            else:
                display_status['resume'] = False
        else:
            display_status['toggle_ai'] = False
            display_status['resume'] = False
    else:
        display_status['menu'] = False
        display_status['toggle_ai'] = False
        display_status['resume'] = False
    return display_status
