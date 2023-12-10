python
def calculateBatteryPercentage(currentBatteryLevel):
    basePower = 150
    remainingPercentage = (currentBatteryLevel / basePower) * 100
    return int(remainingPercentage)
