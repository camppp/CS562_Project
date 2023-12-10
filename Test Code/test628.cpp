javascript
function checkAndCreateProperty(obj, prop) {
  if (typeof obj[prop] !== 'undefined') {
    return typeof obj[prop];
  } else {
    obj[prop] = undefined;
    return 'undefined';
  }
}
