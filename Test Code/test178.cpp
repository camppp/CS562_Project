python
def sortAgentVersions(versions):
    return sorted(versions, key=lambda x: (x['version'], x['agent']))
