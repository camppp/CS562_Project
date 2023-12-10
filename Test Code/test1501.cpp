python
def modifyName(Name_mod):
    if "kAAF" in Name_mod:
        return Name_mod.replace("kAAF", "")
    else:
        return "kAAF" + Name_mod

# Example usage
original_name = "kAAFJohnDoe"
modified_name = modifyName(original_name)
print(modified_name)  # Output: "JohnDoe"
