class Podcast {
    private $title;
    private $genre;
    private $id;
    private $playing;

    public function __construct($title, $genre, $id) {
        $this->title = $title;
        $this->genre = $genre;
        $this->id = $id;
        $this->playing = false;
    }

    public function getTitle() {
        return $this->title;
    }

    public function getGenre() {
        return $this->genre;
    }

    public function togglePlayState() {
        $this->playing =!$this->playing;
        if ($this->playing) {
            echo "Podcast is playing.\n";
        } else {
            echo "Podcast is paused.\n";
        }
    }
}