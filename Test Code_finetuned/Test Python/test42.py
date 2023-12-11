import netCDF4

def get_netcdf_metadata_number_with_warning(variable):
    if not variable:
        return "Variable is empty"
    else:
        try:
            return str(variable.dtype)
        except Exception as e:
            return str(e)