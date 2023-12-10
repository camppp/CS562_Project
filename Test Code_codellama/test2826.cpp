#include <iostream>
#include <vcflib/vcf.h>

int main() {
    // Open the VCF file
    VCFFile vcfFile("input.vcf");

    // Get the number of variants in the VCF file
    int numVariants = vcfFile.getNumVariants();

    // Print the number of variants to the console
    std::cout << "Number of variants: " << numVariants << std::endl;

    // Iterate over each variant in the VCF file
    for (int i = 0; i < numVariants; i++) {
        // Get the variant at the current index
        VCFVariant variant = vcfFile.getVariant(i);

        // Get the chromosome, position, reference allele, and alternate allele for the variant
        std::string chromosome = variant.getChromosome();
        int position = variant.getPosition();
        std::string referenceAllele = variant.getReferenceAllele();
        std::string alternateAllele = variant.getAlternateAllele();

        // Print the chromosome, position, reference allele, and alternate allele for the variant to the console
        std::cout << "Chromosome: " << chromosome << std::endl;
        std::cout << "Position: " << position << std::endl;
        std::cout << "Reference allele: " << referenceAllele << std::endl;
        std::cout << "Alternate allele: " << alternateAllele << std::endl;
    }

    return 0;
}
