class Service {
    private $nom;

    public function setNom($nom) {
        $this->nom = $nom;
        return $this;
    }

    public function getNom() {
        return $this->nom;
    }
}