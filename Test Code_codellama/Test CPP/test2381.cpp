def processTransactions(refs: List[str], code: str) -> Any:
    # Initialize the final result
    result = None

    # Iterate over the references
    for ref in refs:
        # Get the transaction data
        transaction = getTransaction(ref)

        # Process the transaction
        result = processTransaction(transaction, code)

        # Update the code
        code = result

    # Return the final result
    return result
