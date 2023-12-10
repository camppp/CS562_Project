// Write to an existing value with overwrite flag. The value should be
// overwritten.
TEST_F(SetRegValueWorkItemTest, WriteExistingOverwrite) {
  RegKey key;

  // Set up the parent key for the test
  std::wstring parent_key(test_root);
  file_util::AppendToPath(&parent_key, L"WriteExistingOverwrite");
  ASSERT_TRUE(key.Create(HKEY_CURRENT_USER, parent_key.c_str(),
                         KEY_READ | KEY_SET_VALUE));

  // Define the value to be written and the expected overwritten value
  DWORD original_value = 123;  // Original value in the registry
  DWORD new_value = 456;        // New value to overwrite the original

  // Write the original value to the registry
  ASSERT_TRUE(key.WriteValueDW(L"TestValue", original_value));

  // Call the function to overwrite the existing value
  // Replace the function call with the actual function being tested
  // e.g., key.WriteValueDW(L"TestValue", new_value, true);
  // Ensure that the overwrite flag is set to true

  // Read the value from the registry to verify the overwrite
  DWORD read_value;
  ASSERT_TRUE(key.ReadValueDW(L"TestValue", &read_value));

  // Assert that the value has been overwritten
  EXPECT_EQ(read_value, new_value);
}
