import os

def create_symbolic_link(target_file_path):
    # Check if the ~/.config/nvim directory exists
    nvim_config_dir = os.path.expanduser('~/.config/nvim')
    if not os.path.exists(nvim_config_dir):
        # Create the ~/.config/nvim directory if it doesn't exist
        os.makedirs(nvim_config_dir)

    # Create the symbolic link
    link_name = os.path.join(nvim_config_dir, os.path.basename(target_file_path))
    os.symlink(target_file_path, link_name)