/* ICS 51 Lab 2 */
char * yourName = "Falmata Mohamed";
char * studentID = "31827036";

/*******************************************************************************
	Part A - Bit Operation

Bit operation tends to always come up during interfiews for software engineering
jobs. So I'll give you one to practice with.

Implement the countOnes function that counts the number of "1"s in the binary
representation of an integer, and returns the result.

Hint 1. Don't try to convert an integer to binary. All the integers inside your
CPU are in binary already. You should try to think about the "value" of the
integer regardless of its representation. For example, if x = 5, and you move it
into AL, then AL is 00000101 automatically.

Hint 2. Can you try to move each bit into some flag, and then make a conditional
jump based on that bit?
*******************************************************************************/
__declspec(naked) unsigned int countOnes(unsigned int x) {
	__asm{

	mov ebx, x 
	mov ecx, 0    //incrementor 
	mov eax, 0    //actual values, being incremented 
START_WHILE:
	cmp ecx, 32
	je END_WHILE
	shr ebx, 1   
	jb COUNTER_LOOP  //jumps when values in cf are/is "1"
	inc ecx 
	jmp START_WHILE 
COUNTER_LOOP:
	inc ecx 
	inc eax 
	jmp START_WHILE 
 
END_WHILE:

		ret
	}
}

/*******************************************************************************
    Part B - Recursive Function Call

Implement 2 functions that calculates the factorial of an integer no larger than
10. (You may assume that the input never gets larger than 10. You don't have to
check.)

The 1st function, factWrapper(int i), is the non recursive wrapper function
which take the input, sets up the stack, and calls the recursive function.

The 2nd function, factRec(int x), is the recursive function that actually
calculates the factorial.

Hint: write your functions in c++/python/java first, then rewrite the code in
assembly.
*******************************************************************************/

__declspec(naked) int factRec(int x) {
__asm{
	cmp ebx, 1
	jle END_LOOP

	push ebx
	dec ebx
	call factRec
	pop ebx
	mul ebx
END_LOOP:
	ret
	}
}

__declspec(naked) int factWrapper(int i) {
__asm{


	mov ebx, [esp+4]
	mov eax, 1
	call factRec
	ret
	} 
}



/*******************************************************************************
    Part C - Linked List Operation

It is very important to understand how data objects are laid out in memory. 

Recall the positiveSum function in lab 1. We will implement the same function
here again, except that the integers will be stored in a linked list.
*******************************************************************************/
__declspec(naked) int positiveSum(struct Node *head) {
__asm{


	mov edx, [head]
	mov eax, 0

ITERATE:
       cmp [edx], -858993460
       je END
      
	   cmp [edx], 0
	   jle NEXT

	   add eax, [edx]
	   add edx, 4
	   jmp ITERATE

NEXT:
	   add edx, 4
	   jmp ITERATE 
END:
	ret



}
}

/*******************************************************************************
    Part D - Optional Bit Operation

This is an interview question I encountered at one of the major software 
companies.

Implement isPalindrome(unsigned int x).

This function checks the binary representation of an unsigned integer and tests
if it is a palindrome. If it is, return 1. otherwise, return 0.
*******************************************************************************/
__declspec(naked) int isPalindrome(unsigned int x) {
	__asm{


		ret
	}
}