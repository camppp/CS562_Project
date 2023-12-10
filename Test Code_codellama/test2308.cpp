#include <smtk/attribute/Definition.h>
#include <smtk/attribute/StringItemDefinition.h>

void validateAndManipulateDefinitions(smtk::attribute::DefinitionPtr expDef, smtk::attribute::DefinitionPtr baseDef)
{
  // Validate that the expDef and baseDef are not null
  if (!expDef || !baseDef)
  {
    std::cerr << "Error: expDef and baseDef must not be null" << std::endl;
    return;
  }

  // Check if the expDef contains a string item definition with the name "Expression String"
  auto expStringItemDef = expDef->findStringItemDefinition("Expression String");
  if (!expStringItemDef)
  {
    // Add a new string item definition with the name "Expression String" to the expDef
    expStringItemDef = smtk::attribute::StringItemDefinition::New("Expression String");
    expDef->addItemDefinition(expStringItemDef);
  }

  // Check if the baseDef already contains a string item definition with the name "Base String"
  auto baseStringItemDef = baseDef->findStringItemDefinition("Base String");
  if (baseStringItemDef)
  {
    // Remove the string item definition with the name "Base String" from the baseDef
    baseDef->removeItemDefinition(baseStringItemDef);
  }
}
