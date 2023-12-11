#include "virtual_machine/CPUInfo.h"

void InitializeCLexerDefs(CPUInfo& cpuInfo) {
    // Initialize the lexer definitions for the CPU
    cpuInfo.lexerDefs.push_back(LexerDefinition("keyword", "\\b(if|else|while|for|return)\\b"));
    cpuInfo.lexerDefs.push_back(LexerDefinition("identifier", "\\b[a-zA-Z_][a-zA-Z0-9_]*\\b"));
    cpuInfo.lexerDefs.push_back(LexerDefinition("number", "\\b[0-9]+\\b"));
    cpuInfo.lexerDefs.push_back(LexerDefinition("string", "\"[^\"]*\""));
    cpuInfo.lexerDefs.push_back(LexerDefinition("comment", "//[^\n]*"));
}
