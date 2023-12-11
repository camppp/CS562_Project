import numpy as np

def temperature_analysis(eq_lib3, eq_lib3T1, eq_lib3T2, eq_lib3_t, eq_lib3_tt, eq_lib3T1_t, eq_lib3T2_t, eq_lib2T, eq_lib2):
    # Check for NaN values in the temperature data
    nan_values = np.isnan(eq_lib3['temperature']) | np.isnan(eq_lib3T1['temperature']) | np.isnan(eq_lib3T2['temperature']) | np.isnan(eq_lib3_t['temperature']) | np.isnan(eq_lib3_tt['temperature']) | np.isnan(eq_lib3T1_t['temperature']) | np.isnan(eq_lib3T2_t['temperature']) | np.isnan(eq_lib2T['temperature']) | np.isnan(eq_lib2['temperature'])
    if nan_values.any():
        return (True, False)

    # Compare temperature data between dictionaries
    assert_allclose(eq_lib3['temperature'], eq_lib3T1['temperature'], rtol=1e-05, atol=1e-08)
    assert_allclose(eq_lib3['temperature'], eq_lib3T2['temperature'], rtol=1e-05, atol=1e-08)
    assert_allclose(eq_lib3['temperature'], eq_lib3_t['temperature'], rtol=1e-05, atol=1e-08)
    assert_allclose(eq_lib3['temperature'], eq_lib3_tt['temperature'], rtol=1e-05, atol=1e-08)
    assert_allclose(eq_lib3T1['temperature'], eq_lib3T1_t['temperature'], rtol=1e-05, atol=1e-08)
    assert_allclose(eq_lib3T2['temperature'], eq_lib3T2_t['temperature'], rtol=1e-05, atol=1e-08)
    assert_allclose(eq_lib2T['temperature'], eq_lib2['temperature'], rtol=1e-05, atol=1e-08)

    return (False, True)