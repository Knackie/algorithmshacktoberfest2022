def lscsa(datas):
	size = len(datas)
	saved_max = datas[0] #Save the first value as the max 
	end_max = 0 #variable to calculate the max 

	for i in range(0, size):
		end_max += datas[i] #add the actual value in the array to the calculation of the max
		if (end_max < 0):
			end_max = 0 #if the value of the of the max is inferior to 0, then we go back to the calculation at 0
		elif (saved_max < end_max):
			saved_max = end_max #if the calculation of the max is superior to the saved value of the max sum, then we save it at the new one
	
	return saved_max
