class MediaProcessor {
  private $solrClient;

  public function __construct(SolrClient $solrClient) {
    $this->solrClient = $solrClient;
  }

  public function makeSolrDocument(Apache_Solr_Document $document) {
    // Process the media item and update the Solr document
    $document->setField('title', $this->getTitle($document));
    $document->setField('description', $this->getDescription($document));
    $document->setField('tags', $this->getTags($document));
    $document->setField('url', $this->getUrl($document));
    $document->setField('date', $this->getDate($document));
    $document->setField('author', $this->getAuthor($document));
    $document->setField('content', $this->getContent($document));
    return $document;
  }

  public function mediaTestAction() {
    // Set the view renderer to not