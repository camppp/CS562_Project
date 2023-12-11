function generateAnnouncementHTML($annonce) {
    $content = $annonce->content;
    $created_at = $annonce->created_at->format('d/m/y à H:i:s');

    $html = '<article>';
    $html.= '<div class="card-body">';
    $html.= '<div>'. $content. '</div>';
    $html.= '</div>';
    $html.= '<footer class="card-footer">'. $created_at. '</footer>';
    $html.= '</article>';

    return $html;
}