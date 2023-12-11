class ContractManager {
    public function adicionarContrato($dados = NULL) {
        if (is_array($dados)) {
            if (isset($dados['clientName']) && isset($dados['startDate']) && isset($dados['endDate'])) {
                $startDate = DateTime::createFromFormat('Y-m-d', $dados['startDate']);
                $endDate = DateTime::createFromFormat('Y-m-d', $dados['endDate']);

                if ($startDate!== false && $endDate!== false && $endDate > $startDate) {
                    // Add contract logic here
                    return true;
                }
            }
        }
        return false;
    }
}