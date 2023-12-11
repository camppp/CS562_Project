import numpy as np

def get_netcdf_metadata_number_with_warning(var):
    """
    Compute the unpacked data type for a NetCDF variable.

    Parameters
    ----------
    var : NetCDF variable
        The NetCDF variable to compute the unpacked data type for.

    Returns
    -------
    unpacked_data_type : str
        The unpacked data type of the NetCDF variable.
    warning : str
        A warning message if the input variable is empty or contains numerical data.
    """
    if var.empty:
        warning = "Input variable is empty."
        return None, warning
    elif np.issubdtype(var.dtype, np.number):
        warning = "Input variable contains numerical data."
        return None, warning
    else:
        unpacked_data_type = var.dtype.name
        return unpacked_data_type, None