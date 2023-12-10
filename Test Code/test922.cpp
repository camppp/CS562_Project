TMap<EntityId, VirtualWorkerId> GenerateACLAssignments(const SpatialVirtualWorkerTranslator& VirtualWorkerTranslator, const USpatialStaticComponentView& StaticComponentView) {
    TMap<EntityId, VirtualWorkerId> ACLAssignments;

    // Iterate through the entities in the static component view
    for (const auto& EntityPair : StaticComponentView.GetEntities()) {
        EntityId EntityId = EntityPair.Key;
        const FEntityStaticComponent& EntityComponent = EntityPair.Value;

        // Get the virtual worker ID based on the spatial mapping
        VirtualWorkerId AssignedWorker = VirtualWorkerTranslator.GetAssignedVirtualWorker(EntityComponent.SpatialCoordinates);

        // Add the ACL assignment request to the map
        ACLAssignments.Add(EntityId, AssignedWorker);
    }

    return ACLAssignments;
}
