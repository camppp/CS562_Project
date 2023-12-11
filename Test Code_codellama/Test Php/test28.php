class Service {
  private $nom;

  public function setNom($nom) {
    $this->nom = $nom;
    return $this;
  }
}
$service = new Service();
$service->setNom('My Service');