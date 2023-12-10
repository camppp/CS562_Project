EventResult CheckEffectType(const char* graph_name)
{
    // Look up the actor graph object using the data handler
    auto this_AGObj = OHAF_datahandler.GetActorGraph(graph_name);
    if (!this_AGObj)
    {
        // Log a debug message if the actor graph object is not found
        OHAF_datahandler.LogDebug("Actor graph object not found: %s", graph_name);
        return EventResult::kContinue;
    }

    // Check the effect type based on the actor graph object
    if (this_AGObj->GetEffectType() == EffectType::kNone)
    {
        // Log a debug message if the effect type is none
        OHAF_datahandler.LogDebug("Effect type is none: %s", graph_name);
        return EventResult::kContinue;
    }
    else if (this_AGObj->GetEffectType() == EffectType::kFade)
    {
        // Log a debug message if the effect type is fade
        OHAF_datahandler.LogDebug("Effect type is fade: %s", graph_name);
        return EventResult::kContinue;
    }
    else if (this_AGObj->GetEffectType() == EffectType::kSlide)
    {
        // Log a debug message if the effect type is slide
        OHAF_datahandler.LogDebug("Effect type is slide: %s", graph_name);
        return EventResult::kContinue;
    }
    else if (this_AGObj->GetEffectType() == EffectType::kFlip)
    {
        // Log a debug message if the effect type is flip
        OHAF_datahandler.LogDebug("Effect type is flip: %s", graph_name);
        return EventResult::kContinue;
    }
    else
    {
        // Log a debug message if the effect type is unknown
        OHAF_datahandler.LogDebug("Unknown effect type: %s", graph_name);
        return EventResult::kContinue;
    }
}
