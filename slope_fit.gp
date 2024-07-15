# Define the linear function
f(x) = m*x + c

# Fit the combined dataset
fit f(x) 'pressure_data.txt' using 1:2 via m,c

# Print the slope and constant
print "Slope: ", m, " Constant: ", c

# Plot the combined dataset and its best-fit line
plot 'pressure_data.txt' with points title 'pressure vs count', \
     f(x) title sprintf('Best Fit: m=%.2f, c=%.2f', m, c)
