android::app::appsearch::SetSchemaResponse_Builder SetSchemaResponse_Builder::addMigratedTypes(std::vector<android::app::appsearch::MigratedType> migratedTypes) const
{
    for (const auto& migratedType : migratedTypes) {
        callObjectMethod(
            "addMigratedType",
            "(Landroid/app/appsearch/MigratedType;)Landroid/app/appsearch/SetSchemaResponse$Builder;",
            migratedType.getNativeObject());
    }
    return *this;
}
