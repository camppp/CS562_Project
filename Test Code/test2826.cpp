#include <iostream>
#include "Variant.h"
#include "split.h"
#include "var.hpp"

int main() {
    // Create a VCF object to parse the input VCF file
    VariantCallFile variantFile;
    variantFile.open("input.vcf");

    // Check if the VCF file is successfully opened
    if (!variantFile.is_open()) {
        std::cerr << "Error: Unable to open input.vcf" << std::endl;
        return 1;
    }

    // Initialize a counter for the number of variants
    int variantCount = 0;

    // Iterate through each variant in the VCF file
    Variant var(variantFile);
    while (variantFile.is_open() && variantFile.getNextVariant(var)) {
        // Increment the variant count
        variantCount++;

        // Extract and print the chromosome, position, reference allele, and alternate allele for each variant
        std::cout << "Variant " << variantCount << " - Chromosome: " << var.sequenceName
                  << ", Position: " << var.position << ", Ref Allele: " << var.ref
                  << ", Alt Allele: " << var.alt << std::endl;
    }

    // Print the total number of variants in the VCF file
    std::cout << "Total number of variants: " << variantCount << std::endl;

    // Close the VCF file
    variantFile.close();

    return 0;
}
