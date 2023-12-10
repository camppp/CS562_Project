android::app::appsearch::SetSchemaResponse_Builder SetSchemaResponse_Builder::addMigratedTypes(std::vector<android::app::appsearch::MigratedType> migratedTypes) const
{
    // Assuming callObjectMethod adds the migrated types to the schema response builder
    return callObjectMethod(
        "addMigratedTypes",
        "(Ljava/util/Collection;)Landroid/app/appsearch/SetSchemaResponse$Builder;",
        migratedTypes
    );
}
