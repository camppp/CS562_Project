class EnergyTypeManager {
  protected $table = 'energy_type';

  public function getTableName() {
    return $this->table;
  }
}

$energyTypeManager = new EnergyTypeManager();
echo $energyTypeManager->getTableName(); // Output: energy_type

$energyTypeManager = new EnergyTypeManager();
$energyTypeManager->setTableName('new_energy_type');
echo $energyTypeManager->getTableName(); // Output: new_energy_type