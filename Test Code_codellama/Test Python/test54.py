import argparse

parser = argparse.ArgumentParser(description='Image processing tool')

# Add hue argument
parser.add_argument('--hue', type=float, default=100, help='Hue adjustment for the image')

# Add blur argument
parser.add_argument('--blur', action='store_true', help='Apply a blur effect to the image')

# Add blur radius argument
parser.add_argument('--blur_radius', type=float, default=10, help='Radius of the blur effect')

# Add blur sigma argument
parser.add_argument('--blur_sigma', type=float, default=1, help='Sigma value for the blur effect')

# Add Gaussian blur argument
parser.add_argument('--gaussianBlur', action='store_true', help='Apply a Gaussian blur effect to the image')

# Add Gaussian blur width argument
parser.add_argument('--gaussianBlur_width', type=float, default=5, help='Width of the Gaussian blur effect')

# Parse the arguments
args = parser.parse_args()

# Print the arguments
print(args)