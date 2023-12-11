class MediaProcessor
{
    protected $view;

    public function __construct($view)
    {
        $this->view = $view;
    }

    public function makeSolrDocument($mediaItem, $solrDocument)
    {
        // Process the media item and update the Solr document
        // This is a placeholder and should be replaced with actual processing logic
        $solrDocument->addField('id', $mediaItem->getId());
        $solrDocument->addField('title', $mediaItem->getTitle());
        $solrDocument->addField('description', $mediaItem->getDescription());

        return $solrDocument;
    }

    public function mediaTestAction()
    {
        $this->view->setNoRender();
    }
}