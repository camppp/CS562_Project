def fix_application_names(apps):
    # Create a dictionary to map incorrect names to their correct spellings
    name_corrections = {
        "google-chorme": "google-chrome",
        "slack-desktop": "slack",
        "spotfiy": "spotify",
        "whatsapp-web-desktop": "whatsapp-web"
    }

    # Iterate over the input list and correct the names
    corrected_apps = []
    for app in apps:
        # Check if the name is in the dictionary of corrections
        if app in name_corrections:
            corrected_apps.append(name_corrections[app])
        else:
            corrected_apps.append(app)

    return corrected_apps