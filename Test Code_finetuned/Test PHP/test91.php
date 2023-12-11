function generateJoinStatement(string $table, string $on_condition,?string $as = null): string {
    $joinStatement = "JOIN $table";
    if ($as!== null) {
        $joinStatement.= " AS $as";
    }
    $joinStatement.= " ON $on_condition";
    return $joinStatement;
}