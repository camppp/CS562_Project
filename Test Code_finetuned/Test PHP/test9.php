def generateSectionTag(sectionTitle, pageTitle):
    id = pageTitle.lower().replace(' ', '-')
    return f"<section class='section' id='{id}'>{sectionTitle}</section>"