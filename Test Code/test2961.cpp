python
import re

def analyze_code_snippet(code_snippet):
    variables = re.findall(r'(\w+)\s+(\w+);', code_snippet)
    data_types = set(var[0] for var in variables)
    arrays = re.findall(r'j2c_array<\s*(\w+)\s*>\s+(\w+);', code_snippet)
    array_sizes = [arr[1] for arr in arrays]

    total_variables = len(variables)
    total_arrays = len(arrays)

    print("Total number of variables:", total_variables)
    print("Data types of variables:", ", ".join(data_types))
    print("Total number of arrays:", total_arrays)
    print("Sizes of arrays:", ", ".join(array_sizes) if array_sizes else "Not specified")

# Example usage
code_snippet = """
int64_t ptempp;
j2c_array< double >  _pa_rand_gen_arr;
j2c_array< double >  pp_pa_rand_gen_arr_14p276;
double SSAValue40pp2;
j2c_array< double >  SSAValue0;
j2c_array< double >  SSAValue1;
int64_t SSAValue2;
j2c_array< double >  SSAValue4;
double SSAValue5;
bool SSAValue6;
"""
analyze_code_snippet(code_snippet)
