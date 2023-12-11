import hashlib

def getDigest(input):
    algorithms = ['MD5', 'SHA-256', 'SHA-512']
    digests = {}
    for algorithm in algorithms:
        digests[algorithm] = hashlib.new(algorithm, input.encode()).hexdigest()
    return digests