void Asm_x64::build_jmp(LtacNode *node) {
    auto jmp = static_cast<LtacJmp *>(node);
    
    switch (jmp->op) {
        case Operator::None: writer << "\tjmp "; break;
        case Operator::Equal: writer << "\tje "; break;
        case Operator::NotEqual: writer << "\tjne "; break;
        case Operator::Greater: writer << "\tjg "; break;
        case Operator::Less: writer << "\tjl "; break;
        case Operator::GreaterEq: writer << "\tjge "; break;
        case Operator::LessEq: writer << "\tjle "; break;
    }
}
