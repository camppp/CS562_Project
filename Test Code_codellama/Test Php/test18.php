function generateAnnouncementHtml($annonce) {
  $content = $annonce->content;
  $createdAt = $annonce->created_at;
  $formattedCreatedAt = $createdAt->format('d/m/y à H:i:s');
  $html = <<<HTML
  <article>
    <div class="card-body">
      <div>$content</div>
    </div>
    <footer class="card-footer">$formattedCreatedAt</footer>
  </article>
HTML;
  return $html;
}