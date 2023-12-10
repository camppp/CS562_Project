irods::resource* plugin_factory(void* resc) {
    // Use dynamic_cast to safely convert the void pointer to irods::resource pointer
    irods::resource* generic_resource_ptr = dynamic_cast<irods::resource*>(static_cast<irods::resource*>(resc));
    return generic_resource_ptr;
}
