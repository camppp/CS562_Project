go
func findMaxKey(m map[string]int) string {
    maxKey := ""
    maxValue := 0
    for key, value := range m {
        if value > maxValue {
            maxKey = key
            maxValue = value
        }
    }
    return maxKey
}
