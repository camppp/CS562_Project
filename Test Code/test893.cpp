python
def rearrange_and_extract_special_verse(input_str):
    verses = input_str.split('\n')
    rearranged_verses = []
    special_verse = None

    for verse in verses:
        if verse.startswith('<'):
            rearranged_verses.insert(0, verse[2:])
        elif verse.startswith('>'):
            rearranged_verses.append(verse[2:])
        elif verse.startswith('<Portal:'):
            special_verse = verse.split(': ')[1]

    return special_verse

input_str = "> Verse 5\nW: Anyway, this cake is great.\nE: When I look up there it makes me glad I'm not you.\nSW: there is research to be done on the people who are still alive.\n< Verse 5\n< Verse 4\n< Verse 3\n<Portal: Still Alive Verse 1\n>Last One Verse 6\n"
print(rearrange_and_extract_special_verse(input_str))
