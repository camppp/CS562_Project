void LuaEntity::UpdateEntity() const
{
    // Update entity's position based on velocity
    positionX += velocityX;
    positionY += velocityY;

    // Handle events using the event handler
    while (eventHandler.HasPendingEvents())
    {
        Event event = eventHandler.GetNextEvent();
        eventHandler.HandleEvent(event);
    }
}
