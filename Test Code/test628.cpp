#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

string checkAndCreateProperty(object obj, string prop) {
  // Check if the property exists
  if (obj.hasProperty(prop)) {
    // Return the type of the property
    return typeid(obj.getProperty(prop)).name();
  } else {
    // Create the property with a value of undefined
    obj.setProperty(prop, undefined);
    // Return the type of the property
    return "undefined";
  }
}

int main() {
  // Create an example object
  object exampleObj = {
    "name": "John",
    "age": 25
  };

  // Call the function with the object and property name
  string result = checkAndCreateProperty(exampleObj, "name");
  cout << "The type of the property 'name' is: " << result << endl;

  result = checkAndCreateProperty(exampleObj, "occupation");
  cout << "The type of the property 'occupation' is: " << result << endl;

  return 0;
}
