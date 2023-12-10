#include <string>
#include <vector>

class xml_element : public xml_node {
public:
    xml_element(mstring name, xml_items_t items) : xml_node(xml_type_t::element), xml_name(name), xml_children(items) {}

    mstring get_name() const { return xml_name; }
    void set_name(mstring name) { xml_name = name; }

    mstring get_value() const { return xml_value; }
    void set_value(mstring value) { xml_value = value; }

    xml_items_t get_children() const { return xml_children; }
    void set_children(xml_items_t children) { xml_children = children; }

private:
    mstring xml_name;
    mstring xml_value;
    xml_items_t xml_children;
};
