bool IsLaneRuleRequestComplete(const CreateLaneRuleRequest& request) {
    return request.m_ruleNameHasBeenSet && request.m_remarkHasBeenSet;
}