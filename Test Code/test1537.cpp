#include <type_safe/optional.hpp>

// Custom entity structure
struct Entity {
    type_safe::optional<std::string> comment() const {
        // Return the comment of the entity
    }

    void set_comment(type_safe::optional<std::string> comment) {
        // Set the comment of the entity
    }
};

// Function to parse and process entities
void process_entity(Context& context, Entity* child, Entity& cur) {
    // Call the parse_entity function to parse the entity
    Entity* entity = parse_entity(context, nullptr, child, cur);

    if (entity) {
        // Extract the comment from the entity using type_safe::copy
        type_safe::optional<std::string> comment = type_safe::copy(entity->comment()).value_or("");

        // Remove the comment from the entity
        entity->set_comment(type_safe::nullopt);
    }
}
