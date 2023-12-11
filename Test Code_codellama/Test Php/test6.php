class ContractManager {
  public function adicionarContrato($dados = NULL) {
    if (!is_array($dados)) {
      return;
    }

    $clientName = $dados['clientName'];
    $startDate = $dados['startDate'];
    $endDate = $dados['endDate'];

    if (!$clientName || !$startDate || !$endDate) {
      return;
    }

    if (!is_string($clientName) || !is_string($startDate) || !is_string($endDate)) {
      return;
    }

    if (!preg_match('/^\d{4}-\d{2}-\d{2}$/', $startDate) || !preg_match('/^\d{4}-\d{2}-\d{2}$/', $endDate)) {
      return;
    }

    if (strtotime($endDate) < strtotime($startDate))
}
}