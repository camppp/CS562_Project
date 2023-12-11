import os
import glob

def list_non_private_modules(package_name):
    # Get the path of the package
    package_path = os.path.dirname(__import__(package_name).__file__)

    # Get all.py files in the package directory
    module_files = glob.glob(os.path.join(package_path, '*.py'))

    # Extract module names from file names
    module_names = [os.path.splitext(os.path.basename(f))[0] for f in module_files]

    # Filter out private modules (those starting with '_')
    non_private_modules = [m for m in module_names if not m.startswith('_')]

    return non_private_modules