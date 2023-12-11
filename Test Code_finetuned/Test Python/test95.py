def organize_packages(packages: list) -> dict:
    organized_packages = {}
    for package in packages:
        if package["name"] not in organized_packages:
            organized_packages[package["name"]] = []
        organized_packages[package["name"]].append(package["version"])
    return organized_packages

def calculate_total_size(organized_packages: dict, package_name: str) -> int:
    total_size = 0
    for name, versions in organized_packages.items():
        if name == package_name:
            for version in versions:
                for package in packages:
                    if package["name"] == name and package["version"] == version:
                        total_size += package["size"]
                        for dependency in package["dependencies"]:
                            for dep_package in packages:
                                if dep_package["name"] == dependency:
                                    total_size += dep_package["size"]
    return total_size

packages = [ {"name": "numpy", "version": "1.18.1", "dependencies": ["mkl", "python"], "size": 150}, {"name": "mkl", "version": "2019.0", "dependencies": ["python"], "size": 100}, {"name": "python", "version": "3.7.4", "dependencies": [], "size": 200} ]

organized_packages = organize_packages(packages)
print(organized_packages)
print(calculate_total_size(organized_packages, "numpy"))