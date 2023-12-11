# Plot the first 9 prime numbers in each subplot
for i in range(3):
    for j in range(3):
        axs[i, j].plot([2, 3, 5, 7, 11, 13, 17, 19, 23])
        axs[i, j].set_title(f"Prime Number {i * 3 + j + 2}")

# Ensure that each subplot displays a different prime number
for i in range(3):
    for j in range(3):
        axs[i, j].set_xlabel("Prime Number")
        axs[i, j].set_ylabel("Count")
        axs[i, j].set_xticks([2, 3, 5, 7, 11, 13, 17, 19, 23])
        axs[i, j].set_xticklabels([2, 3, 5, 7, 11, 13, 17, 19, 23])

# Show the plot
plt.show()