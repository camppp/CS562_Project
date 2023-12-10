// Solution for CpuUtilization function
float LinuxParser::CpuUtilization(int pid) {
  long activeJiffies = LinuxParser::ActiveJiffies(pid);
  long uptime = LinuxParser::UpTime();
  
  long total_time = activeJiffies / sysconf(_SC_CLK_TCK);  // Convert jiffies to seconds
  float seconds = uptime - (LinuxParser::UpTime(pid) / sysconf(_SC_CLK_TCK));  // Time the process has been running
  
  float cpu_utilization = 100.0 * ((total_time / seconds) / sysconf(_SC_NPROCESSORS_ONLN));  // Calculate CPU utilization percentage
  
  return cpu_utilization;
}
