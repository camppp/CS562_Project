class Hyperlink {
    private $options;
    private $attributes;
    private $url;

    public function __construct($options, $attr) {
        unset($options['url']);
        $this->options = $options;
        $this->attributes = $attr;
    }

    /**
     * Set the URL of the link
     *
     * @param string $url
     * @return Hyperlink $this
     */
    public function setUrl($url) {
        $this->url = $url;
        return $this;
    }
}