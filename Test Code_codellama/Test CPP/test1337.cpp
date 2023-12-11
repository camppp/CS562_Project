#include <gtest/gtest.h>

void testModuleProperties(const ib_module_t* module) {
  EXPECT_EQ(module->name, s_module_name);
  EXPECT_EQ(module->filename, __FILE__);
  EXPECT_EQ(module->ib, m_engine.ib());
  EXPECT_EQ(s_delegate_initialized, false);
}
