void UYourAbilityClass::CancelAbility()
{
    Super::CancelAbility();

    // Custom logic to clean up tasks
    if (MoveCharacterToCursorAbilityTask && !MoveCharacterToCursorAbilityTask->IsFinished())
    {
        MoveCharacterToCursorAbilityTask->EndTask();
    }
    
    // Additional cleanup if needed
}

void UYourAbilityClass::EndAbility()
{
    if (MoveCharacterToCursorAbilityTask && !MoveCharacterToCursorAbilityTask->IsFinished())
    {
        UE_LOG(LogYourGame, Warning, TEXT("%s: Attempted to EndAbility when MoveCharacterToCursorAbilityTask was still active. Should have already been cleaned up in CancelAbility or regular execution."), *GetName());
    }

    Super::EndAbility();
}
