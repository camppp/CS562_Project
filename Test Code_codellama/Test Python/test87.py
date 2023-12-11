class RiskAssessment:
    def assert_risk_values(self, risk):
        # Check that all risk categories are valid
        valid_categories = ['credit', 'market', 'operational']
        for category in risk.keys():
            if category not in valid_categories:
                raise ValueError(f"Invalid risk category: {category}")

        # Check that risk levels are within the acceptable range
        acceptable_range = range(1, 6)
        for level in risk.values():
            if level not in acceptable_range:
                raise ValueError(f"Invalid risk level: {level}")

        return True