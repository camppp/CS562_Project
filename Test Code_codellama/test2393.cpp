void __calc__(vector<llint>& answer) {
  llint sum = 0;
  for (llint num : answer) {
    sum += num;
  }
  answer.push_back(sum);
}
