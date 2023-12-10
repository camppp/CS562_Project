float LinuxParser::CpuUtilization(int pid) {
  long activeJiffies = LinuxParser::ActiveJiffies(pid);
  long uptime = LinuxParser::UpTime();
  return 100.0 * (activeJiffies / uptime);
}
