bool load_schedule(serialization::input_archive & ar, ...) {
    // Implement the logic to process the schedule and determine if the parcel was migrated or scheduled locally
    // Extract necessary information from the input archive and perform the required checks

    // Example pseudo-code logic:
    // Read parcel details from the input archive
    // Check if the parcel has a migration flag or any indication of being scheduled locally
    // Based on the extracted information, return true if the parcel was migrated, and false if it was scheduled locally

    // Replace ... with any additional parameters or types required for processing the schedule

    // Example implementation:
    // Assuming the input archive provides a flag indicating migration
    bool isMigrated = ar.readParcelMigrationFlag();  // Example function to read migration flag from the input archive
    return isMigrated;
}
