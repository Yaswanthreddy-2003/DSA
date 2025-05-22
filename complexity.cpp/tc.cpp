//time complexity
//time complexity means the total number of operations required as the input size increases.

//for recursive functions
//time complexity is calculated by the number of recursive calls made and number of operations done in each recursive call

//binary exponentiation
//what is binary exponentiation?
//The number of times the loop runs in binary exponentiation is equal to the number of bits in the exponent.
//Why?
//Because each iteration of the loop handles one bit of the exponent.
//The exponent is halved in each iteration, so the number of iterations is logarithmic in the size of the exponent.
//The number of bits in the exponent is log2(n), where n is the exponent.

//Here’s What Happens:
// Let’s say you want to compute base^exp, and exp = 13.
// Binary of 13 = 1101 → 4 bits
// In each iteration, you:
// Look at the current least significant bit (LSB) of exp
// If it’s 1, multiply the result
// Then square the base
// Then right-shift exp (i.e., divide by 2)

/*
exp = 13 → binary: 1101
iterations:
  1101 (bit 0 is 1)
  0110 (bit 1 is 0)
  0011 (bit 1 is 1)
  0001 (bit 1 is 1)
→ total 4 iterations

For any number n:
Number of bits = floor(log₂(n)) + 1
That’s the maximum number of iterations the loop will run.
*/

