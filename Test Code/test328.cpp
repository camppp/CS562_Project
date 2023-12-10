// Function to check the effect type for a given target actor graph
EventResult CheckEffectType(const std::string& graph_name) {
    logger::debug(FMT_STRING("Target Actor Graph Name is {}."), graph_name);

    // Look up the actor graph object by name
    auto this_AGObj = OHAF_datahandler->LookUpAGObjByName(graph_name);

    if (!this_AGObj) {
        logger::debug("Not Matching AnimGraph Type Found For Effect Target!");
        return EventResult::kContinue;
    }

    // Perform the effect type check logic here
    // Example: Assuming effect type is stored in this_AGObj, perform the necessary checks
    if (this_AGObj->HasEffectType()) {
        logger::debug("Effect Type Found: {}", this_AGObj->GetEffectType());
    } else {
        logger::debug("No Effect Type Found for the Target Actor Graph");
    }

    // Return appropriate EventResult based on the effect type check
    return EventResult::kSuccess;  // Or any other suitable result
}
