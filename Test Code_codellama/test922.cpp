TMap<EntityId, VirtualWorkerId> GenerateACLAssignments(const SpatialVirtualWorkerTranslator& VirtualWorkerTranslator, const USpatialStaticComponentView& StaticComponentView)
{
    // Get the spatial mapping from the SpatialVirtualWorkerTranslator
    const TMap<EntityId, VirtualWorkerId>& SpatialMapping = VirtualWorkerTranslator.GetSpatialMapping();

    // Get the current state of entities from the USpatialStaticComponentView
    const TArray<USpatialStaticComponentView::EntityState>& EntityStates = StaticComponentView.GetEntityStates();

    // Create a map to store the ACL assignment requests
    TMap<EntityId, VirtualWorkerId> ACLAssignments;

    // Iterate over the entity states and determine the ACL assignment requests for each entity
    for (const USpatialStaticComponentView::EntityState& EntityState : EntityStates)
    {
        // Get the entity ID and virtual worker ID from the spatial mapping
        const EntityId EntityId = EntityState.GetEntityId();
        const VirtualWorkerId VirtualWorkerId = SpatialMapping.FindRef(EntityId);

        // If the entity is not assigned to a virtual worker, skip it
        if (VirtualWorkerId == INDEX_NONE)
        {
            continue;
        }

        // Determine the ACL assignment request for the entity
        const ACLAssignmentRequest& ACLAssignmentRequest = DetermineACLAssignmentRequest(EntityState);

        // Add the ACL assignment request to the map
        ACLAssignments.Add(EntityId, VirtualWorkerId);
    }

    return ACLAssignments;
}
