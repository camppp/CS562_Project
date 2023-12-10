template<class T>
void decomposeProperty(const WeightedSample<T>& weightedSample, PropertyBag& targetbag)
{
    // Set the type of the target PropertyBag to "WeightedSample"
    targetbag.setType("WeightedSample");

    // Get the type of the elements in the weighted sample
    auto elementType = detail::DataSourceTypeInfo<T>::getType();

    // Iterate over the elements in the weighted sample
    for (const auto& element : weightedSample.getData())
    {
        // Create a new property for the element
        Property property(elementType);

        // Set the value of the property to the element
        property.setValue(element);

        // Set the weight of the property to the weight of the element
        property.setWeight(weightedSample.getWeight(element));

        // Add the property to the target PropertyBag
        targetbag.addProperty(property);
    }
}
