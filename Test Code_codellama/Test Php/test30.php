function createNewCollect($collectSite, $collectSource, $objectType, $objectSubType, $objectWeight, $bdd) {
  // Prepare the SQL statement
  $stmt = $bdd->prepare("INSERT INTO collects (collect_site, collect_source, object_type, object_sub_type, object_weight, collect_date) VALUES (:collect_site, :collect_source, :object_type, :object_sub_type, :object_weight, NOW())");

  // Bind the input parameters to the SQL statement
  $stmt->bindParam(':collect_site', $collectSite);
  $stmt->bindParam(':collect_source', $collectSource);
  $stmt->bindParam(':object_type', $objectType);
  $stmt->bindParam(':object_sub_type', $objectSubType);