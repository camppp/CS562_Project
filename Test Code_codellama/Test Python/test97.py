def process_fasta_files(files: List[str]) -> Dict[str, str]:
    sequences = {}
    for file in files:
        with open(file, 'r') as f:
            for line in f:
                if line.startswith('>'):
                    sequence_id = line[1:].strip()
                else:
                    sequence = line.strip()
                    sequences[sequence_id] = sequence
    return sequences

files = ['sequences.fasta', 'sequences2.fasta']
sequences = process_fasta_files(files)
print(sequences)