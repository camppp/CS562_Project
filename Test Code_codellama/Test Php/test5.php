class Conference {
  // Constructor and other methods can be included here

  public function getAllConf() {
    $confres = [];
    $confs = $this->getConferences();
    foreach ($confs as $conf) {
      $confres[$conf->getName()] = $conf->getConfiguration();
    }
    return $confres;
  }
}