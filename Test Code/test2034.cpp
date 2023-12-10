python
def processDictionary(dictionary):
    totalCount = 0
    sumKeyNumbers = 0
    sumValueNumbers = 0

    for key, value in dictionary.items():
        totalCount += 1

        # Extract keyNumber from a string of the form key<keyNumber>
        keyNumber = int(key[3:])

        # Extract valueNumber from a string of the form value<valueNumber>
        valueNumber = int(value[5:])

        sumKeyNumbers += keyNumber
        sumValueNumbers += valueNumber

    return totalCount, sumKeyNumbers, sumValueNumbers
