javascript
function validateJSON(jsonObject, schema) {
  if (typeof jsonObject !== "object" || Array.isArray(jsonObject)) {
    return false;
  }

  const schemaProperties = schema.properties || {};
  const schemaPatternProperties = schema.patternProperties || {};
  const requiredProperties = schema.required || [];

  // Check if all required properties are present
  for (const prop of requiredProperties) {
    if (!(prop in jsonObject)) {
      return false;
    }
  }

  // Check if additional properties are disallowed
  if (!schema.additionalProperties) {
    const schemaKeys = new Set([
      ...Object.keys(schemaProperties),
      ...Object.keys(schemaPatternProperties)
    ]);
    for (const key in jsonObject) {
      if (!schemaKeys.has(key)) {
        return false;
      }
    }
  }

  // Check property types
  for (const prop in schemaProperties) {
    if (typeof jsonObject[prop] !== schemaProperties[prop].type) {
      return false;
    }
  }

  // Check pattern properties
  for (const prop in jsonObject) {
    for (const pattern in schemaPatternProperties) {
      const regex = new RegExp(pattern);
      if (regex.test(prop) && typeof jsonObject[prop] !== schemaPatternProperties[pattern].type) {
        return false;
      }
    }
  }

  return true;
}
