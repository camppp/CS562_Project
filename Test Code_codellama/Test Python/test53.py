import os
import re

def bundle_assets(input_files, filters, output_files):
    # Create a dictionary to store the bundled assets
    bundled_assets = {}

    # Loop through each input file and apply the specified filters
    for asset_type, files in input_files.items():
        for file in files:
            # Read the contents of the input file
            with open(file, 'r') as f:
                content = f.read()

            # Apply the specified filters to the content
            for filter in filters[asset_type]:
                if filter == 'uglify':
                    # Uglify the content
                    content = re.sub(r'\s+', '', content)
                elif filter == 'autoprefixer':
                    # Add vendor prefixes to the content
                    content = re.sub(r'(-[a-z])', r'-\1-', content)
                elif filter == 'cssmin':
                    # Minify the content
                    content = re.sub(r'\s+', '', content)

            # Write the bundled content to the output file
            with open(output_files[asset_type], 'w') as f:
                f.write(content)

            # Add the bundled asset to the dictionary
            bundled_assets[asset_type] = content

    return bundled_assets