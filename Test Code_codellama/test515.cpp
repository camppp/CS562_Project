template <typename T>
void trackPendingValue(TrackedValueType<T> value) {
  // Determine the appropriate member function to call based on the type of the tracked value
  auto memberFunction = PointerToMemberFunctionReturningSourceRange<T>::getMemberFunction(value);

  // Call the appropriate member function to add the tracked value to the appropriate set
  if (memberFunction == &PendingNonLocValueSet::insert) {
    PendingNonLocValueSet.insert(value);
  } else if (memberFunction == &PendingMemoryRegionSet::insert) {
    PendingMemoryRegionSet.insert(value);
  }
}

template <typename T>
void trackPendingMemoryRegion(TrackedValueType<T> region) {
  // Determine the appropriate member function to call based on the type of the tracked memory region
  auto memberFunction = PointerToMemberFunctionReturningSourceRange<T>::getMemberFunction(region);

  // Call the appropriate member function to add the tracked memory region to the appropriate set
  if (memberFunction == &PendingNonLocValueSet::insert) {
    PendingNonLocValueSet.insert(region);
  } else if (memberFunction == &PendingMemoryRegionSet::insert) {
    PendingMemoryRegionSet.insert(region);
  }
}
