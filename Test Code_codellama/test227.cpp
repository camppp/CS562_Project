void build_jmp(LtacNode* node) {
    switch (node->op) {
        case None:
            printf("jmp\n");
            break;
        case Equal:
            printf("je\n");
            break;
        case NotEqual:
            printf("jne\n");
            break;
        case Greater:
            printf("jg\n");
            break;
        case Less:
            printf("jl\n");
            break;
        case GreaterEq:
            printf("jge\n");
            break;
        case LessEq:
            printf("jle\n");
            break;
    }
}
