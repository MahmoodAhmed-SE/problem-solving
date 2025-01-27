Char
isalnum()   is alphanumeric?



String:
std::transform(s.begin(), s.end(), s.begin(), ::tolower);
std::transform(s.begin(), s.end(), s.begin(), ::toupper);
at() 	Returns an indexed character from a string
length() 	Returns the length of a string
size() 	Alias of length(). Returns the length of a string
max_size() 	Returns the maximum length of a string
empty() 	Checks wheter a string is empty or not
append() 	Appends a string (or a part of a string) to another string
substr() 	Returns a part of a string from a start index (position) and length
find() 	Returns the index (position) of the first occurrence of a string or character
rfind() 	Returns the index (position) of the last occurrence of a string or character
replace() 	Replaces a part of a string with another string
insert() 	Inserts a string at a specified index (position)
erase() 	Removes characters from a string
compare() 	Compares two strings


Algorthim lib:
adjacent_find() 	Finds a pair of consecutive elements with the same value in a data range
all_of() 	Checks if all of the elements in a data range match a condition
any_of() 	Checks if at least one element in a data range matches a condition
binary_search() 	An efficient algorithm for finding if a value exists in a sorted data range
copy() 	Copies the values from a data range into a different data range
count() 	Counts the number of times that a value occurs in a data range
count_if() 	Counts the number of elements in a data range that match a condition
fill() 	Writes a value into every element of a data range
find() 	Finds the first element of a data range with a specified value
find_first_of() 	Finds the first element of a data range which matches one of several specified values
find_if() 	Finds the first element of a data range which matches a condition
find_if_not() 	Finds the first element of a data range which does not match a condition
for_each() 	Runs a function on every element in a data range
includes() 	Checks if all of the values in a sorted data range exist in another sorted data range
is_permutation() 	Checks if a data range is a permutation of another
is_sorted() 	Checks if a data range is sorted
is_sorted_until() 	Finds the position in a data range at which elements are no longer sorted
lower_bound() 	Finds the first element at or above a specified lower bound in a sorted data range
max_element() 	Finds the element with the highest value in a data range
merge() 	Merges the values of two data ranges into a new data range
min_element() 	Finds the element with the lowest value in a data range
none_of() 	Checks if none of the elements in a data range match a condition
random_shuffle() 	Randomly rearranges the elements in a data range
replace() 	Replaces all occurrences of a value in a data range with a different value
replace_copy() 	Creates a copy of a data range with all occurrences of a specified value replaced with a different value
replace_copy_if() 	Creates a copy of a data rage where all values that match a condition are replaced with a different value
replace_if() 	Replaces all values in a data range that match a condition with a different value
reverse() 	Reverses the order of elements in a data range
reverse_copy() 	Creates a copy of a data range with the elements in reverse order
search() 	Finds a specified sequence of values in a data range
sort() 	Sorts the values of a data range in ascending order
swap() 	Swaps the values of two variables
swap_ranges() 	Swaps the values of two data ranges of the same size
upper_bound() 	Finds the first element above a specified upper bound in a sorted data range


vector:
assign() 	Fills a vector with multiple values
at() 	Returns an indexed element from a vector
back() 	Returns the last element of a vector
begin() 	Returns an iterator pointing to the beginning of a vector
capacity() 	Returns the number of elements that a vector's reserved memory is able to store
clear() 	Removes all of the contents of a vector
data() 	Returns a pointer to the block of memory where a vector's elements are stored
empty() 	Checks whether a vector is empty or not
end() 	Returns an iterator pointing to the end of a vector
erase() 	Removes a number of elements from a vector
front() 	Returns the first element of a vector
insert() 	Inserts a number of elements into a vector
max_size() 	Returns the maximum number of elements that a vector can have
pop_back() 	Removes the last element of a vector
push_back() 	Adds an element to the end of a vector
rbegin() 	Returns a reverse iterator pointing to the last element of a vector
rend() 	Returns a reverse iterator pointing to a position right before the first element of a vector
reserve() 	Reserves memory for a vector
resize() 	Changes the size of a vector, adding or removing elements if necessary
shrink_to_fit() 	Reduces the reseved memory of a vector if necessary to exactly fit the number of elements
size() 	Returns the number of elements in a vector
swap() 	Swaps the contents of one vector with another
