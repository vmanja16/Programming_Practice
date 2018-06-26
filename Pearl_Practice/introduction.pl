
use feature 'state';

# String value operators: eq ne gt lt ge le cmp

=This is a multi-line comment
more comments
=cut

# Single Line comment

$x = 4;
print("The value of x is $x\n");


# ARRAYS

@itemList = (1,2,3,4,5);
@fruitList = ("Apple", "Banana");

# Array Size
print("Size of itemList is: ",scalar(@itemList),".\n");

# Array access
print($itemList[0], " and $itemList[3]\n");

# Array push,  unshift (push_front),  pop , shift (pop_front) 
push(@fruitList, "Carrot", "TestPush");
print("The item popped was ", pop(@fruitList), "\n");

# HASH
%dictionary = ("Apple" => 1, "Banana" => 2);
# Hash access
$key = "Apple";
print("The key is $key and the value is $dictionary{$key}.");


# Adding a key,value to a hashMap
$key = "Carrot";
$dictionary{"Carrot"} = 3;
print("The key is $key and the value is $dictionary{$fruitList[2]}.\n");

# CONDITIONALS

$x = "Apple";
if ($x==5){print "It's True!\n";}
elsif($x eq  "Apple"){print("It's hit an elsif!\n");}
else {print ("It's over now!\n");}
# unless and until are just negative booleans lol
unless ($x==5) {print("This is just a negative boolean.\n");}

# LOOPS
# next = continue,   last = break
foreach $fruit (@fruitList){
	print("Fruit is $fruit and count is $dictionary{$fruit}\n");
}
# Use .. to get a range of numbers or letters
@range = (0..20); @range2 = ("a".."z");
print("@range\n@range2\n");


# REFERENCES (pointers)

$var = 10;
# assign pointer
$r_var = \$var;
# dereference the pointer with ($ or @ or %)!
print ("referenced is $r_var\n");
print("dereferenced is $$r_var\n");
# use the 'ref' function to determine type like type(x) in python
print("The variable $r_var is of type: ", ref($r_var), "\n"); 


# SUBROUTINES
# use '@_' to reference parameters.. might be good idea to pass pointers
# use my for local var declarations
# use 'state' for static var declarations


sub max{
=This function returns the max of a group of integers, will return -1 if nothing
is passed
=cut
	# return -1 if nothing was passed in
	if (scalar(@_) == 0){return -1;}
	
	my $maximum = @_[0];
	foreach $number (@_){
		if ($number > $maximum){
			$maximum = $number;
		}
	} 
	return $maximum;
}

print("Maximum of (10,20,30, 5) is:", max(10,20,30,5), "\n");


