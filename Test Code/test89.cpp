python
def processIdentifiers(identifiers, labels):
    processed_identifiers = {}
    for i in range(len(identifiers)):
        if identifiers[i] != "":
            if i < len(labels):
                processed_identifiers[identifiers[i]] = labels[i]
            else:
                processed_identifiers[identifiers[i]] = "MISSING_LABEL"
        else:
            processed_identifiers["POS_ID"] = labels[i] if i < len(labels) else "MISSING_LABEL"
    return processed_identifiers
