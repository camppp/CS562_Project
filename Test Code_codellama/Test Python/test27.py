def main():
   return [1, 2, 3, 4, 5]

def find_max_min(my_list):
   max_value = my_list[0]
   min_value = my_list[0]
   for i in range(1, len(my_list)):
       if my_list[i] > max_value:
           max_value = my_list[i]
       if my_list[i] < min_value:
           min_value = my_list[i]
   return max_value, min_value

def calculate_diff(max_value, min_value):
   return max_value - min_value

if __name__ == "__main__":
   my_list = main()
   max_value, min_value = find_max_min(my_list)
   diff = calculate_diff(max_value, min_value)
   print(max_value)
   print(min_value)
   print(diff)