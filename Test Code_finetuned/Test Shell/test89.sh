import re

def parse_slurm_script(script):
    # Define regular expressions for each type of information
    ntasks_re = re.compile(r'#SBATCH --ntasks=(\d+)')
    mem_re = re.compile(r'#\s*\!\s*How much real memory is required per node \(in MB\)\?\s*(\d+)')
    output_re = re.compile(r'#SBATCH --output\s+(\S+)')
    time_re = re.compile(r'#SBATCH --time=(\d+:\d+:\d+)')
    symlink_re = re.compile(r'#ln -s\s+(\S+)')

    # Initialize results
    results = {
        'ntasks': None,
       'mem': None,
        'output': None,
        'time': None,
       'symlink': None
    }

    # Search for each type of information in the script
    for line in script.split('\n'):
        ntasks_match = ntasks_re.match(line)
        if ntasks_match:
            results['ntasks'] = int(ntasks_match.group(1))

        mem_match = mem_re.match(line)
        if mem_match:
            results['mem'] = int(mem_match.group(1))

        output_match = output_re.match(line)
        if output_match:
            results['output'] = output_match.group(1)

        time_match = time_re.match(line)
        if time_match:
            results['time'] = time_match.group(1)

        symlink_match = symlink_re.match(line)
        if symlink_match:
            results['symlink'] = symlink_match.group(1)

    return results

# Test the function
script = """
#SBATCH --ntasks=20
#! How much real memory is required per node (in MB)? 1000
#SBATCH --output slurm.%u.%j.%N.stdout.txt
#SBATCH --time=00:10:20
#ln -s /home/adev01/gPROMSAgent_5154434330700/SRT_10.25.188.122_446653966157500/liblapack.so.3
"""
print(parse_slurm_script(script))