void calculate16BitResources(SResource* fFirst, int32_t& totalResources, int32_t& resultingValue) {
    int32_t totalResourcesWritten = 0;
    int32_t resultingValue = 0;

    // Iterate through the linked list of resources
    for (SResource* current = fFirst; current != nullptr; current = current->next) {
        // Check if the current resource is a 16-bit resource
        if (current->type == RESOURCE_TYPE_16BIT) {
            // Increment the total number of 16-bit resources written
            totalResourcesWritten++;

            // Update the resulting value with the current resource value
            resultingValue += current->res16;
        }
    }

    // Check if all resources have been written
    if (totalResourcesWritten == 0) {
        // If not, call the writeAllRes16 method to write all 16-bit resources to the bundle
        writeAllRes16(fFirst);
    }

    // Update the totalResources and resultingValue parameters with the calculated values
    totalResources = totalResourcesWritten;
    resultingValue = resultingValue;
}
