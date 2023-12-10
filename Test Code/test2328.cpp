template<class T>
void decomposeProperty(const WeightedSample<T>& weightedSample, PropertyBag& targetbag)
{
    std::string tname = detail::DataSourceTypeInfo<T>::getType();
    targetbag.setType("WeightedSample");

    // Iterate through the elements of the weighted sample
    for (size_t i = 0; i < weightedSample.size(); ++i) {
        // Create a property for each element and its weight
        Property<T> prop;
        prop.setValue(weightedSample[i]);
        prop.setWeight(weightedSample.getWeight(i));

        // Set the type of the property
        prop.setType(tname);

        // Add the property to the target PropertyBag
        targetbag.addProperty(prop);
    }
}
