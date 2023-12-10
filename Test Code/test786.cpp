javascript
function validateJSON(jsonObject, schema) {
  for (let key in schema) {
    if (typeof schema[key] === 'object') {
      if (!jsonObject.hasOwnProperty(key) || !validateJSON(jsonObject[key], schema[key])) {
        return false;
      }
    } else if (schema[key] === 'array') {
      if (!Array.isArray(jsonObject[key])) {
        return false;
      }
    } else if (typeof jsonObject[key] !== schema[key]) {
      return false;
    }
  }
  return true;
}
