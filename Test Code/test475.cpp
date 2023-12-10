#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

class DynamicSliceManagerComponent : public AZ::Component
{
public:
    void Reflect(AZ::ReflectContext* context) override
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<DynamicSliceManagerComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<DynamicSliceManagerComponent>("DynamicSliceManagerComponent", "handles dynamic slices")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "");
            }
        }
    }
};
