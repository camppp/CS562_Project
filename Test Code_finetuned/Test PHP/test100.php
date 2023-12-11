class Message {
    protected $content;

    public function __construct($content) {
        $this->content = $content;
    }

    public function getContent() {
        return $this->content;
    }
}

class Email extends Message {
    protected $recipient;

    public function __construct($content, $recipient) {
        parent::__construct($content);
        $this->recipient = $recipient;
    }

    public function getRecipient() {
        return $this->recipient;
    }
}