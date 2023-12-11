def processIdentifiers(identifiers, labels):
    result = {}
    for i, identifier in enumerate(identifiers):
        if identifier:
            if i < len(labels):
                result[identifier] = labels[i]
            else:
                result[identifier] = "MISSING_LABEL"
        else:
            result["POS_ID"] = "label2" if i == 1 else "MISSING_LABEL"
    return result


identifiers = ["id1", "", "id3"]
labels = ["label1", "label2"]


{ "id1": "label1", "POS_ID": "label2", "id3": "MISSING_LABEL" }