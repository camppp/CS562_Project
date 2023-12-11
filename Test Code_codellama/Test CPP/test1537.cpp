#include <type_safe>

void extract_comments(const Context& context, const Child& child, const Cur& cur) {
    // Parse the entity from the given context
    auto entity = parse_entity(context, child, nullptr);

    // If the entity was successfully parsed
    if (entity) {
        // Extract the comment from the entity
        auto comment = type_safe::copy(entity.comment());

        // Remove the comment from the entity
        entity.set_comment(type_safe::nullopt);

        // Store the comment in a separate variable
        // ...
    }
}
