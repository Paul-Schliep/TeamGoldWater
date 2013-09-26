Palindrome Memory Leaks

Our Fixes:

* Our first freed memory was from rev, because it wasn't used past the while loop.  Leak was in palindrome file.
* The second was a bit more complicated.  There was a leak in palindrome_test from calling palindrome because it was calling memory and not freeing it in the palindrome_test file, so we freed 'result' in the test file.
