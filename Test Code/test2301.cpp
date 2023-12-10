// Complete implementation of the xml_element class
class xml_element : public xml_node {
public:
    xml_element(mstring name, xml_items_t items)
        : xml_node(xml_type_t::element), xml_name(ang::move(name)) {
        if (!items.is_empty() && items->xml_is_type_of(xml_type_t::element_list))
            xml_children(ang::move(items));
    }

    void set_name(mstring name) {
        xml_name = ang::move(name);
    }

    mstring get_name() const {
        return xml_name;
    }

    void set_value(mstring value) {
        xml_value = ang::move(value);
    }

    mstring get_value() const {
        return xml_value;
    }

    void set_children(xml_items_t items) {
        if (!items.is_empty() && items->xml_is_type_of(xml_type_t::element_list))
            xml_children = ang::move(items);
    }

    xml_items_t get_children() const {
        return xml_children;
    }

private:
    mstring xml_name;
    mstring xml_value;
    xml_items_t xml_children;
};
