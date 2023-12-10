#include <AzCore/Component/Component.h>
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

class DynamicSliceManagerComponent
    : public AZ::Component
{
public:
    AZ_COMPONENT(DynamicSliceManagerComponent, "{37858231-4092-4321-8765-432187654321}");

    DynamicSliceManagerComponent() = default;
    ~DynamicSliceManagerComponent() override = default;

    void Activate() override;
    void Deactivate() override;

    static void Reflect(AZ::ReflectContext* context);

private:
    AZStd::vector<AZ::Entity*> m_dynamicSlices;
};

void DynamicSliceManagerComponent::Activate()
{
    // Initialize the dynamic slice manager component
}

void DynamicSliceManagerComponent::Deactivate()
{
    // Clean up the dynamic slice manager component
}

void DynamicSliceManagerComponent::Reflect(AZ::ReflectContext* context)
{
    if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
    {
        serializeContext->Class<DynamicSliceManagerComponent, AZ::Component>()
            ->Version(0)
            ->Field("DynamicSlices", &DynamicSliceManagerComponent::m_dynamicSlices);

        if (auto editContext = serializeContext->GetEditContext())
        {
            editContext->Class<DynamicSliceManagerComponent>("Dynamic Slice Manager", "Manages dynamic slices")
                ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    ->Attribute(AZ::Edit::Attributes::Category, "Game")
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("Game"))
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true);
        }
    }
}
