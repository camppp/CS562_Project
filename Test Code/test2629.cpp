python
import random
import string

def generateLicenseKey(productCode, numLicenses, licenseLength):
    license_keys = set()
    while len(license_keys) < numLicenses:
        random_string = ''.join(random.choices(string.ascii_uppercase + string.digits, k=licenseLength))
        license_key = f"{productCode}-{random_string}"
        license_keys.add(license_key)
    return list(license_keys)
