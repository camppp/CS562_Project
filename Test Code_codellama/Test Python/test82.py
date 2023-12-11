def judge(self, inputs, default):
    results = {input: self.trial(input) for input in inputs}
    eligible = {input: result for input, result in results.items() if result is not None}
    if eligible:
        champion = max(eligible, key=eligible.get, default=default)
    else:
        champion = default
    return champion