#terminology

## Definition
A **stack** is the name given to a data structure that stores values, and supports these basic operation:

- **push(stack, x)**: adds element x to the *top* of the stack
- **pop(stack)**: removes the *top* element of the stack
- **peek(stack, x)**: returns a copy of the *top* element of the stack without removing it
- **is_empty(stack)**: returns true if the stack is empty, and false otherwise

The only way to add an item to a stack is to call **push(stack, x)**, and the only way to remove an item is to call **pop(stack)**. With a stack, items can only be added and removed from one end of the stack.

## Example

For example, here is an empty stack:
```
|   |
|   |
|   |  empty stack
|   |
|___|  bottom of the stack
```

If you call **is_empty(stack)** returns true.

After calling **push(stack, 5)**, it looks like this:
```
|   |
|   |
|   |  
| 5 | <-- 5 is on the top of the stack
|___|  bottom of the stack
```

Calling **is_empty(stack)** returns false.

After calling **push(stack, 2)**, it looks like this:
```
|   |
|   |
| 2 | <-- 5 is on the top of the stack 
| 5 | 
|___|  bottom of the stack
```

Now 2 is on the top of the stack. The 5 is still there underneath the 2.

Lets push one more value with **push(stack, 8)**:
```
|   |
| 8 | <-- 8 is on the top of the stack
| 2 | 
| 5 | 
|___|  bottom of the stack
```

Visually, we know have a stack of numbers, with 8 on the top and 5 on the bottom.

If we called **peek(stack)** on this stack, it would return 8. **peek(stack)** always returns a copy of the top item on the stack without changing the stack in any way.

Popping a stack removes one element from the top. For example, after calling **pop(stack)**, the stack looks like this:
```
|   |   8 has been popped, i.e. removed from the stack
|   | 
| 2 | <-- 2 is on the top of the stack
| 5 | 
|___|  bottom of the stack
```

After **pop(stack)** again it looks like this:
```
|   |   2 has been popped, i.e. removed from the stack
|   | 
|   | 
| 5 | <-- 5 is on the top of the stack
|___|  bottom of the stack
```

After one more call to **pop(stack)**, it looks like this:
```
|   |   5 has been popped, i.e. removed from the stack
|   | 
|   |  stack is empty
|   | 
|___|  bottom of the stack
```

Calling **pop(stack)** on an empty stack typically results in an error since there is nothing to remove.
