void MDeferredRenderWork::DrawNormalMesh(MRenderInfo& info)
{
    for (MMaterialGroup& group : info.vMaterialRenderGroup)
    {
        // Perform rendering operations for each material group
        // Example: Set shader parameters, draw meshes, etc.
        info.pRenderer->SetShaderParamSet(info.pPrimaryCommand, &group.m_FrameParamSet);
        info.pRenderer->DrawMesh(info.pPrimaryCommand, group.m_pScreenDrawMesh);
    }
    info.pRenderer->EndRenderPass(info.pPrimaryCommand);
}
