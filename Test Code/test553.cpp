assembly
# Define stack pointer and stack size
stack_ptr .req sp
stack_size = 64

# Define constants for single-precision floating-point numbers
single_precision_size = 4

# Define constants for stack operations
push_offset = -single_precision_size
pop_offset = single_precision_size

# Push operation
push:
    cmp stack_ptr, sp - stack_size
    bge stack_overflow  # Branch if stack overflow
    str v0.s[2], [stack_ptr, push_offset]!  # Store the value and update stack pointer
    bx lr  # Return

# Pop operation
pop:
    cmp stack_ptr, sp
    ble stack_underflow  # Branch if stack underflow
    ldr v0.s[2], [stack_ptr], pop_offset  # Load the value and update stack pointer
    bx lr  # Return

# Peek operation
peek:
    ldr v0.s[2], [stack_ptr, pop_offset]  # Load the value without updating stack pointer
    bx lr  # Return

# Stack overflow handler
stack_overflow:
    # Handle stack overflow (e.g., raise an error, log a message, etc.)
    bx lr  # Return

# Stack underflow handler
stack_underflow:
    # Handle stack underflow (e.g., raise an error, log a message, etc.)
    bx lr  # Return
