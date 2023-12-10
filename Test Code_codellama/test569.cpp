void updateGraphicsPipeline(std::unordered_map<uint64_t, uint64_t>& mMaterialPipelineVariants, GraphicsPipelineDescription& mDesc) {
    for (const auto& [materialID, pipelineVariantID] : mMaterialPipelineVariants) {
        if (materialID == 1) {
            mDesc.material1PipelineVariant = pipelineVariantID;
        } else if (materialID == 2) {
            mDesc.material2PipelineVariant = pipelineVariantID;
        }
        // Add similar conditions for other material IDs if needed
    }
}
