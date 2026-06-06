#include "../../../../Rdk/GUI/Qt/UComponentFormRegistry.h"
#include "../../../../Rdk/GUI/Qt/UGenericComponentControllerWidget.h"

namespace
{
UComponentFormDescriptor MakeBasicDescriptor(const QString& id, const QString& title)
{
    UComponentFormDescriptor descriptor;
    descriptor.formId = id;
    descriptor.title = title;
    descriptor.singleInstance = true;
    descriptor.factory = [id, title](RDK::UApplication* app) -> UVisualControllerWidget*
    {
        return new UGenericComponentControllerWidget(id, title, nullptr, app);
    };
    return descriptor;
}
}

void RegisterBasicLibComponentGuiForms()
{
    UComponentFormRegistry& registry = UComponentFormRegistry::instance();
    registry.registerFormFactory("NModel", MakeBasicDescriptor("basic.model.panel", "BasicLib: Model Panel"));
}
