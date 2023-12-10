python
import re

def parsePeripheralConstants(code_snippet):
    peripheral_constants = {}
    pattern = r'#if defined\((.*?)\)\s+([\w]+)\s+=\s+(.*?),'
    matches = re.findall(pattern, code_snippet)
    for match in matches:
        peripheral_constants[match[1]] = match[2]
    return peripheral_constants

# Test the function with the given code snippet
code_snippet = """
    #if defined(STM32F405xx) || defined(STM32F415xx) || defined(STM32F407xx) || defined(STM32F417xx) || defined(STM32F401xC) || defined(STM32F401xE) || defined(STM32F411xE)
        PLLI2S     = 0x04,
    #endif
    #if defined(STM32F401xC) || defined(STM32F401xE) || defined(STM32F411xE)
        RTC        = 0x08,
    #endif
"""
print(parsePeripheralConstants(code_snippet))
