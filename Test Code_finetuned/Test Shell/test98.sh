def get_package_commands(image):
    if image.startswith("fedora:"):
        pkgcmd = "dnf"
        builddep = "dnf builddep"
    elif image.startswith("ubuntu:"):
        pkgcmd = "apt"
        builddep = "apt-get build-dep"
    elif image.startswith("centos:"):
        pkgcmd = "yum"
        builddep = "yum-builddep"
    else:
        raise ValueError("Unsupported image type")

    return pkgcmd, builddep