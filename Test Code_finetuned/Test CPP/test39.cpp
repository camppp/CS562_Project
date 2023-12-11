class NotifierId:
    def __init__(self, notifier_type, id):
        self.notifier_type = notifier_type
        self.id = id

    def __eq__(self, other):
        return self.notifier_type == other.notifier_type and self.id == other.id


class SettingsProvider:
    def __init__(self):
        self.button_press_count = 0
        self.last_pressed_button_id = None

    def SendLearnMorePressedForTest(self, id):
        self.button_press_count += 1
        self.last_pressed_button_id = NotifierId("APPLICATION", id)

    def request_count(self):
        return self.button_press_count

    def last_requested_notifier_id(self):
        return self.last_pressed_button_id


def test_settings_provider():
    settings_provider = SettingsProvider()

    # Simulate a settings button being pressed
    settings_provider.SendLearnMorePressedForTest("id")

    # Test the number of settings buttons pressed
    assert settings_provider.request_count() == 1

    # Test the ID of the last settings button pressed
    assert settings_provider.last_requested_notifier_id() == NotifierId("APPLICATION", "id")

test_settings_provider()