def _base_transaction(transaction: dict) -> dict:
    event_id = transaction.get("event_id")
    contexts = transaction.get("contexts")
    trace = contexts.get("trace") if contexts else None

    if event_id and trace:
        return {
            "event_id": event_id,
            "contexts": {
                "trace": trace
            }
        }
    else:
        return {}