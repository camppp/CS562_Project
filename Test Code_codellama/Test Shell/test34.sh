# Generate a sequence of 1000 random numbers between 1 and 6, inclusive
for i in {1..1000}; do
  dice_roll=$(($RANDOM % 6 + 1))
  echo $dice_roll
done

# Count the frequency of each outcome (1 to 6) in the generated sequence
declare -A outcomes
for i in {1..6}; do
  outcomes[$i]=0
done

for i in {1..1000}; do
  dice_roll=$(($RANDOM % 6 + 1))
  outcomes[$dice_roll]=$(($outcomes[$dice_roll] + 1))
done

# Display the frequency of each outcome in a user-friendly format
echo "Outcome Frequency:"
for i in {1..6}; do
  echo "$i: ${outcomes[$i]}"
done