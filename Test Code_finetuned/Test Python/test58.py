import geopandas as gpd
import numpy as np

def process_geodata(file_path: str) -> float:
    try:
        # Read the GeoPackage file
        gdf = gpd.read_file(file_path, driver='GPKG')

        # Extract the geometries and convert them into a NumPy array
        geometries = np.array(gdf.geometry.to_list())

        # Calculate the total area covered by the geometries
        total_area = sum(geom.area for geom in geometries)

        return total_area

    except Exception as e:
        print(f"An error occurred: {e}")
        return None