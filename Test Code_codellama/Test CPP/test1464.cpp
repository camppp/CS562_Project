void APlayerPawnTest_Male_C::ExecuteUbergraph_PlayerPawnTest_Male(int EntryPoint)
{
    switch (EntryPoint)
    {
        case 0: // Jump
            Jump();
            break;
        case 1: // Run
            Run();
            break;
        case 2: // Attack
            Attack();
            break;
        default:
            break;
    }
}
